package com.comp301.a01sushi;

import java.lang.Math;

public class Nigiri implements Sushi {

  public enum NigiriType {
    TUNA,
    YELLOWTAIL,
    EEL,
    CRAB,
    SHRIMP
  }

  private static final double AMOUNT = 0.75;
  private IngredientPortion nigiriPlate;
  private IngredientPortion ricePortion;

  public Nigiri(NigiriType type) {

    ricePortion = new RicePortion(AMOUNT - 0.25);

    switch (type) {
      case TUNA:
        nigiriPlate = new TunaPortion(AMOUNT);

        break;
      case EEL:
        nigiriPlate = new EelPortion(AMOUNT);

        break;
      case CRAB:
        nigiriPlate = new CrabPortion(AMOUNT);

        break;
      case SHRIMP:
        nigiriPlate = new ShrimpPortion(AMOUNT);

        break;
      case YELLOWTAIL:
        nigiriPlate = new YellowtailPortion(AMOUNT);

        break;
    }
  }

  @Override
  public String getName() {
    return nigiriPlate.getName() + " nigiri";
  }

  @Override
  public IngredientPortion[] getIngredients() {
    return new IngredientPortion[] {nigiriPlate, ricePortion};
  }

  @Override
  public int getCalories() {
    return (int) Math.round(nigiriPlate.getCalories() + ricePortion.getCalories());
  }

  @Override
  public double getCost() {
    return Math.round((nigiriPlate.getCost() + ricePortion.getCost()) * 100) / 100.0;
  }

  @Override
  public boolean getHasRice() {
    return true;
  }

  @Override
  public boolean getHasShellfish() {
    return nigiriPlate.getIsShellfish();
  }

  @Override
  public boolean getIsVegetarian() {
    return false;
  }
}
