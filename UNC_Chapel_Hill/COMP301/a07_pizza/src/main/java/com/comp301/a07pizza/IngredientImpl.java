package com.comp301.a07pizza;

public class IngredientImpl implements Ingredient {
  private String name;
  private boolean isVegetarian;
  private boolean isVegan;

  public IngredientImpl(String name, boolean isVegetarian, boolean isVegan) {
    if (name == "") {
      throw new IllegalArgumentException();
    }
    this.name = name;
    this.isVegetarian = isVegetarian;
    this.isVegan = isVegan;
  }

  @Override
  public String getName() {
    return this.name;
  }

  @Override
  public boolean isVegetarian() {
    return this.isVegetarian;
  }

  @Override
  public boolean isVegan() {
    return this.isVegan;
  }
}
