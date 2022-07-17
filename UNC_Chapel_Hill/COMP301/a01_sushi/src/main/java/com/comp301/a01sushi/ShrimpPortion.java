package com.comp301.a01sushi;

public class ShrimpPortion extends IngredientPortions {
  public ShrimpPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Shrimp();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new ShrimpPortion(amount);
  }
}
