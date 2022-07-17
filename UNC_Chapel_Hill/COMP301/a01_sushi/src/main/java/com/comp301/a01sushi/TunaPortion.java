package com.comp301.a01sushi;

public class TunaPortion extends IngredientPortions {
  public TunaPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Tuna();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new TunaPortion(amount);
  }
}
