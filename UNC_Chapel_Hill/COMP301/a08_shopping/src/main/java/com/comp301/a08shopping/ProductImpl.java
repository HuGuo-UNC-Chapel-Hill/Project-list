package com.comp301.a08shopping;

public class ProductImpl implements Product {
  private String name;
  private double basePrice; // two decimal place
  private int inventory;
  private double percentOff;

  public ProductImpl(String name, double basePrise) {
    if (basePrise < 0.00 || name == null) {
      throw new IllegalArgumentException();
    } else {
      this.name = name;
      this.basePrice = basePrise;
      this.inventory = 0;
      this.percentOff = 0.00;
    }
  }

  @Override
  public String getName() {
    return this.name;
  }

  @Override
  public double getBasePrice() {
    return this.basePrice;
  }

  public void setInventory(int inventory) {
    this.inventory = inventory;
  }

  public int getInventory() {
    return this.inventory;
  }

  public void setPercentOff(double percentOff) {
    this.percentOff = percentOff;
  }

  public double getPercentOff() {
    return this.percentOff;
  }
}
