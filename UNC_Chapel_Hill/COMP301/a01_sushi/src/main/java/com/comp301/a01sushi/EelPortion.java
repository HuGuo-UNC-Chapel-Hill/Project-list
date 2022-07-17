package com.comp301.a01sushi;

public class EelPortion extends IngredientPortions {
  public EelPortion(double ounceAmount) {
    super(ounceAmount);
    this.ingredientInstance = new Eel();
  }

  public IngredientPortion combine(IngredientPortion other) {
    super.combine(other);
    double amount = this.getAmount() + other.getAmount();
    return new EelPortion(amount);
  }
}
