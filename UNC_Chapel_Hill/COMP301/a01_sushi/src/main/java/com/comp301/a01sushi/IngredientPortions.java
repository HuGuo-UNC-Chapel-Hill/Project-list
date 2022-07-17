package com.comp301.a01sushi;

public class IngredientPortions implements IngredientPortion {
  private double ounceAmount;
  protected Ingredients ingredientInstance;

  protected IngredientPortions(double ounceAmount) throws IllegalArgumentException {
    if (ounceAmount < 0.0) {
      throw new IllegalArgumentException();
    }
    this.ounceAmount = ounceAmount;
  }

  public Ingredients getIngredient() {
    return this.ingredientInstance;
  }

  public double getAmount() {
    return this.ounceAmount;
  }

  public String getName() {
    return this.ingredientInstance.getName();
  }

  public boolean getIsVegetarian() {
    return this.ingredientInstance.getIsVegetarian();
  }

  public boolean getIsRice() {
    return this.ingredientInstance.getIsRice();
  }

  public boolean getIsShellfish() {
    return this.ingredientInstance.getIsShellfish();
  }

  public double getCalories() {
    return (this.ingredientInstance.getCaloriesPerOunce() * this.ounceAmount);
  }

  public double getCost() {
    return (this.ingredientInstance.getPricePerOunce() * this.ounceAmount);
  }

  public IngredientPortion combine(IngredientPortion other) throws IllegalArgumentException {
    if (other == null) {
      throw new IllegalArgumentException("The other ingredientPortion is null.");
    } else if (!this.ingredientInstance.equals(other.getIngredient())) {
      throw new IllegalArgumentException("The ingredient portion is not same with this one.");
    }
    return null;
  }
}
