package com.comp301.a08shopping;

import com.comp301.a08shopping.events.*;
import com.comp301.a08shopping.exceptions.OutOfStockException;
import com.comp301.a08shopping.exceptions.ProductNotFoundException;

import java.util.ArrayList;
import java.util.List;

public class StoreImpl implements Store {
  private String name;
  private List<StoreObserver> storeObservers;
  private List<Product> products;

  public StoreImpl(String name) {
    if (name == null) {
      throw new IllegalArgumentException();
    } else {
      this.name = name;
      storeObservers = new ArrayList<StoreObserver>();
      products = new ArrayList<Product>();
    }
  }

  @Override
  public String getName() {
    return name;
  }

  @Override
  public void addObserver(StoreObserver observer) {
    if (observer == null) {
      throw new IllegalArgumentException();
    }
    storeObservers.add(observer);
  }

  @Override
  public void removeObserver(StoreObserver observer) {
    if (observer == null) {
      throw new IllegalArgumentException();
    }
    storeObservers.remove(observer);
  }

  @Override
  public List<Product> getProducts() {
    List<Product> temp = new ArrayList<Product>();
    for (Product p : products) {
      temp.add(p);
    }
    return temp;
  }

  @Override
  public Product createProduct(String name, double basePrice, int inventory) {
    if (name == null || basePrice <= 0.00 || inventory < 0) {
      throw new IllegalArgumentException();
    } else {
      Product product = new ProductImpl(name, basePrice);
      ((ProductImpl) product).setInventory(inventory);
      products.add(product);
      return product;
    }
  }

  private void notify(StoreEvent event) {
    for (StoreObserver o : storeObservers) {
      o.update(event);
    }
  }

  @Override
  public ReceiptItem purchaseProduct(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else if (((ProductImpl) product).getInventory() == 0) {
      throw new OutOfStockException();
    } else {
      int inventory = ((ProductImpl) product).getInventory();
      ((ProductImpl) product).setInventory(inventory - 1);
      StoreEventImpl event1 = new PurchaseEvent(product, this);
      this.notify(event1);
      if (inventory - 1 == 0) {
        StoreEventImpl event2 = new OutOfStockEvent(product, this);
        this.notify(event2);
      }
    }
    ReceiptItem receiptItem =
        new ReceiptItemImpl(product.getName(), this.getSalePrice(product), this.name);
    return receiptItem;
  }

  @Override
  public void restockProduct(Product product, int numItems) {
    if (product == null || numItems < 0) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      int productNum = ((ProductImpl) product).getInventory();
      ((ProductImpl) product).setInventory(productNum + numItems);
      if (productNum == 0 && numItems > 0) {
        StoreEventImpl event = new BackInStockEvent(product, this);
        notify(event);
      }
    }
  }

  @Override
  public void startSale(Product product, double percentOff) {
    if (product == null || percentOff <= 0.0 || percentOff >= 1.0) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      ((ProductImpl) product).setPercentOff(percentOff);
      StoreEventImpl event = new SaleStartEvent(product, this);
      notify(event);
    }
  }

  @Override
  public void endSale(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      ((ProductImpl) product).setPercentOff(0.00);
      StoreEventImpl event = new SaleEndEvent(product, this);
      notify(event);
    }
  }

  @Override
  public int getProductInventory(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      return ((ProductImpl) product).getInventory();
    }
  }

  @Override
  public boolean getIsInStock(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      return this.getProductInventory(product) != 0;
    }
  }

  @Override
  public double getSalePrice(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      double price = product.getBasePrice();
      price *= (1 - ((ProductImpl) product).getPercentOff());
      price = Math.round(price * 100.0) / 100.0;
      return price;
    }
  }

  @Override
  public boolean getIsOnSale(Product product) {
    if (product == null) {
      throw new IllegalArgumentException();
    } else if (!products.contains(product)) {
      throw new ProductNotFoundException();
    } else {
      return this.getSalePrice(product) < product.getBasePrice();
    }
  }
}
