package com.comp301.a01sushi;

import java.lang.Math;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;

public class Roll implements Sushi {
  private static final String SEAWEED = "seaweed";
  private String name;
  private IngredientPortion[] roll_ingredients;
  private IngredientPortion seaweedPortion = new ShrimpPortion(0.1);

  public Roll(String name, IngredientPortion[] roll_ingredients) {
    this.name = name;

    if (roll_ingredients == null) {
      throw new IllegalArgumentException();
    } else {
      for (IngredientPortion roll_ingredient : roll_ingredients) {
        if (roll_ingredient == null) {
          throw new IllegalArgumentException();
        }
      }
      this.roll_ingredients = roll_ingredients.clone();
    }
    this.roll_ingredients = this.processRoll(this.roll_ingredients);
  }

  @Override
  public String getName() {
    return name;
  }

  @Override
  public IngredientPortion[] getIngredients() {
    IngredientPortion[] temp = new IngredientPortion[this.roll_ingredients.length];
    System.arraycopy(roll_ingredients, 0, temp, 0, this.roll_ingredients.length);
    return temp;
  }

  @Override
  public int getCalories() {
    double calories = 0;
    for (int i = 0; i < this.roll_ingredients.length; i++) {
      calories += this.roll_ingredients[i].getCalories();
    }
    return (int) Math.round(calories);
  }

  @Override
  public double getCost() {
    double price = 0.0;
    for (int i = 0; i < this.roll_ingredients.length; i++) {
      price += this.roll_ingredients[i].getCost();
    }
    return (Math.round(price * 100.0)) / 100.0;
  }

  @Override
  public boolean getHasRice() {
    for (int i = 0; i < this.roll_ingredients.length; i++) {
      if (this.roll_ingredients[i].getIsRice()) {
        return true;
      }
    }
    return false;
  }

  @Override
  public boolean getHasShellfish() {
    for (int i = 0; i < this.roll_ingredients.length; i++) {
      if (this.roll_ingredients[i].getIsShellfish()) {
        return true;
      }
    }
    return false;
  }

  @Override
  public boolean getIsVegetarian() {
    for (int i = 0; i < this.roll_ingredients.length; i++) {
      if (this.roll_ingredients[i].getIsVegetarian()) {
        return true;
      }
    }
    return false;
  }

  public IngredientPortion[] processRoll(IngredientPortion[] roll) {

    HashMap<String, IngredientPortion> rollMap = new HashMap<String, IngredientPortion>();

    for (IngredientPortion ingredient : roll) {
      if (!rollMap.containsKey(ingredient.getName())) {
        rollMap.put(ingredient.getName(), ingredient);
      } else {
        rollMap.put(ingredient.getName(), rollMap.get(ingredient.getName()).combine(ingredient));
      }
    }

    if (!rollMap.containsKey(SEAWEED) || rollMap.get(SEAWEED).getAmount() < 0.1) {
      rollMap.put(SEAWEED, new SeaweedPortion(0.1));
    }

    IngredientPortion[] temp = rollMap.values().toArray(new IngredientPortion[0]);

    return temp;
  }
}
