package com.comp301.a01sushi;

public class YellowtailPortion extends IngredientPortions {
  public YellowtailPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Yellowtail();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new YellowtailPortion(amount);
  }
}
