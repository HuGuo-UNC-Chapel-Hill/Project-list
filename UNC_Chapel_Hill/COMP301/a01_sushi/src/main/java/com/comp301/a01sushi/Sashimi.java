package com.comp301.a01sushi;

import java.lang.Math;

public class Sashimi implements Sushi {
  public enum SashimiType {
    TUNA,
    YELLOWTAIL,
    EEL,
    CRAB,
    SHRIMP
  }

  private static final double AMOUNT = 0.75;
  private IngredientPortion sashimiPlate;

  public Sashimi(SashimiType type) {
    switch (type) {
      case TUNA:
        sashimiPlate = new TunaPortion(AMOUNT);

        break;
      case EEL:
        sashimiPlate = new EelPortion(AMOUNT);

        break;
      case CRAB:
        sashimiPlate = new CrabPortion(AMOUNT);

        break;
      case SHRIMP:
        sashimiPlate = new ShrimpPortion(AMOUNT);

        break;
      case YELLOWTAIL:
        sashimiPlate = new YellowtailPortion(AMOUNT);

        break;
    }
  }

  @Override
  public String getName() {
    return sashimiPlate.getName() + " sashimi";
  }

  @Override
  public IngredientPortion[] getIngredients() {
    return new IngredientPortion[] {sashimiPlate};
  }

  @Override
  public int getCalories() {
    return (int) Math.round(sashimiPlate.getCalories());
  }

  @Override
  public double getCost() {
    return Math.round((sashimiPlate.getCost()) * 100) / 100.0;
  }

  @Override
  public boolean getHasRice() {
    return false;
  }

  @Override
  public boolean getHasShellfish() {
    return sashimiPlate.getIsShellfish();
  }

  @Override
  public boolean getIsVegetarian() {
    return false;
  }
}
