package com.comp301.a01sushi;

public class CrabPortion extends IngredientPortions {

  public CrabPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Crab();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new CrabPortion(amount);
  }
}
