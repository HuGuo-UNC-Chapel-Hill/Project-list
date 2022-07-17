package com.comp301.a02adventure;

import java.util.ArrayList;

public class InventoryImpl implements Inventory {
  private ArrayList<Item> inventory;

  public InventoryImpl() {
    inventory = new ArrayList<Item>();
  }

  @Override
  public boolean isEmpty() {
    if (this.inventory.isEmpty()) {
      return true;
    }
    return false;
  }

  @Override
  public int getNumItems() {
    return this.inventory.size();
  }

  @Override
  public ArrayList<Item> getItems() {
    ArrayList<Item> temp;
    temp = (ArrayList<Item>) this.inventory.clone();
    return temp;
  }

  @Override
  public void addItem(Item item) {
    this.inventory.add(item);
  }

  @Override
  public void removeItem(Item item) {
    this.inventory.remove(item);
  }

  @Override
  public void clear() {
    this.inventory.clear();
  }

  @Override
  public void transferFrom(Inventory other) {
    this.inventory.addAll(other.getItems());
    other.clear();
  }
}
