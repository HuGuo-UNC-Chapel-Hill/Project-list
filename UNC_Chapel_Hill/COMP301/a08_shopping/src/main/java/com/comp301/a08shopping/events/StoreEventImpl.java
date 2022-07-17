package com.comp301.a08shopping.events;

import com.comp301.a08shopping.Product;
import com.comp301.a08shopping.Store;

public class StoreEventImpl implements StoreEvent {
  private final Product product;
  private final Store store;

  public StoreEventImpl(Product product, Store store) {
    if (product == null || store == null) {
      throw new IllegalArgumentException();
    } else {
      this.product = product;
      this.store = store;
    }
  }

  @Override
  public Product getProduct() {
    return this.product;
  }

  @Override
  public Store getStore() {
    return this.store;
  }

  public String getEventType() {
    return "";
  }
}
