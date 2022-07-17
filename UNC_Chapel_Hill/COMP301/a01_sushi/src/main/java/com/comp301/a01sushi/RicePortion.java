package com.comp301.a01sushi;

public class RicePortion extends IngredientPortions {
  public RicePortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Rice();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new RicePortion(amount);
  }
}
