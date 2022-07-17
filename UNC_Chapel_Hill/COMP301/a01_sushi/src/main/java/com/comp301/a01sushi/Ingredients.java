package com.comp301.a01sushi;

public class Ingredients implements Ingredient {

  private String name;
  private double caloriesPerDollar;
  private int caloriesPerOunce;
  private double pricePerOunce;
  boolean isVegetarian;
  boolean hasRice;
  boolean hasShellfish;

  //  public static DecimalFormat formatter = new DecimalFormat("0.0#");

  protected Ingredients(
      String name,
      int calories,
      double price,
      boolean boolVegetarian,
      boolean boolRice,
      boolean boolShell) {
    this.name = name;
    this.caloriesPerDollar = calories / price;
    this.caloriesPerOunce = calories;
    this.pricePerOunce = price;
    isVegetarian = boolVegetarian;
    hasRice = boolRice;
    hasShellfish = boolShell;
  }

  public String getName() {
    return this.name;
  }

  public double getCaloriesPerDollar() {
    return this.caloriesPerDollar;
  }

  public int getCaloriesPerOunce() {
    return this.caloriesPerOunce;
  }

  public double getPricePerOunce() {
    return this.pricePerOunce;
  }

  public boolean getIsVegetarian() {
    return this.isVegetarian;
  }

  public boolean getIsRice() {
    return this.hasRice;
  }

  public boolean getIsShellfish() {
    return this.hasShellfish;
  }

  public boolean equals(Ingredient other) {
    if (other == null) {
      return false;
    } else if (!this.name.equals(other.getName())) {
      return false;
    } else if (this.caloriesPerOunce - other.getCaloriesPerOunce() != 0) {
      return false;
    } else if (this.pricePerOunce - other.getPricePerOunce() > 0.01) {
      return false;
    } else if (this.isVegetarian != other.getIsVegetarian()) {
      return false;
    } else if (this.hasRice != other.getIsRice()) {
      return false;
    } else if (this.hasShellfish != other.getIsShellfish()) {
      return false;
    }
    return true;
  }
}
