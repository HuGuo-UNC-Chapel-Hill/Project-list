package com.comp301.a08shopping;

import com.comp301.a08shopping.events.*;

import java.util.ArrayList;
import java.util.List;

public class CustomerImpl implements Customer {
  private String name;
  private double budget;
  private List<ReceiptItem> receiptItems;

  public CustomerImpl(String name, double budget) {
    if (budget < 0 || name == null) {
      throw new IllegalArgumentException();
    }
    this.name = name;
    this.budget = budget;
    this.receiptItems = new ArrayList<ReceiptItem>();
  }

  @Override
  public String getName() {
    return this.name;
  }

  @Override
  public double getBudget() {
    return this.budget;
  }

  @Override
  public void purchaseProduct(Product product, Store store) {
    if (product == null || store == null) {
      throw new IllegalArgumentException();
    }
    if (store.getSalePrice(product) > this.budget) {
      throw new IllegalStateException();
    } else {
      this.budget -= store.getSalePrice(product);
      ReceiptItem receiptItem = store.purchaseProduct(product);
      this.receiptItems.add(receiptItem);
    }
  }

  @Override
  public List<ReceiptItem> getPurchaseHistory() {
    List<ReceiptItem> temp = this.receiptItems;
    return temp;
  }

  @Override
  public void update(StoreEvent event) {
    String e = ((StoreEventImpl) event).getEventType();

    switch (e) {
      case "BackInStockEvent":
        System.out.println(
            event.getProduct().getName() + " is back in stock at " + event.getStore().getName());
        break;
      case "OutOfStockEvent":
        System.out.println(
            event.getProduct().getName() + " is now out of stock at " + event.getStore().getName());
        break;
      case "PurchaseEvent":
        System.out.println(
            "Someone purchased "
                + event.getProduct().getName()
                + " at "
                + event.getStore().getName());
        break;
      case "SaleEndEvent":
        System.out.println(
            "The sale for "
                + event.getProduct().getName()
                + " at "
                + event.getStore().getName()
                + " has ended");
        break;
      case "SaleStartEvent":
        System.out.println(
            "New sale for "
                + event.getProduct().getName()
                + " at "
                + event.getStore().getName()
                + "!");
        break;
      default:
        throw new IllegalArgumentException();
    }
  }
}
