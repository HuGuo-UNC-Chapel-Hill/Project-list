package com.comp301.a01sushi;

public class AvocadoPortion extends IngredientPortions {
  public AvocadoPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Avocado();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new AvocadoPortion(amount);
  }
}
