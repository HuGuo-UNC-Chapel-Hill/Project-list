package com.comp301.a01sushi;

public class SeaweedPortion extends IngredientPortions {
  public SeaweedPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Seaweed();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new SeaweedPortion(amount);
  }
}
