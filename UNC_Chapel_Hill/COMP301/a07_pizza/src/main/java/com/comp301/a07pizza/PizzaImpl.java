package com.comp301.a07pizza;

public class PizzaImpl implements Pizza {
  private Size size;
  private Crust crust;
  private Sauce sauce;
  private Cheese cheese;
  private Topping[] toppings;

  public PizzaImpl(Size size, Crust crust, Sauce sauce, Cheese cheese, Topping[] toppings) {
    this.size = size;
    this.crust = crust;
    this.sauce = sauce;
    this.cheese = cheese;
    this.toppings = toppings;
  }

  @Override
  public boolean isVegetarian() {

    for (Topping topping : this.toppings) {
      if (topping.isVegetarian() == false) {
        return false;
      }
    }
    if (crust.isVegetarian() == false) {
      return false;
    }
    if (sauce.isVegetarian() == false) {
      return false;
    }
    if (cheese.isVegetarian() == false) {
      return false;
    }

    return true;
  }

  @Override
  public boolean isVegan() {
    for (Topping topping : this.toppings) {
      if (topping.isVegetarian() == false) {
        return false;
      }
    }
    if (crust.isVegan() == false) {
      return false;
    }
    if (sauce.isVegan() == false) {
      return false;
    }
    if (cheese.isVegan() == false) {
      return false;
    }
    return true;
  }

  @Override
  public double getPrice() {
    double price = 0;

    if (this.getSize() == Size.SMALL) {
      price += 7.00;
      for (Topping topping : this.toppings) {
        price += 0.25;
      }
    } else if (this.getSize() == Size.MEDIUM) {
      price += 9.00;
      for (Topping topping : this.toppings) {
        price += 0.50;
      }
    } else if (this.getSize() == Size.LARGE) {
      price += 11.00;
      for (Topping topping : this.toppings) {
        price += 0.75;
      }
    }
    return price;
  }

  @Override
  public Size getSize() {
    return this.size;
  }

  @Override
  public Ingredient getSauce() {
    return this.sauce;
  }

  @Override
  public Ingredient getCheese() {
    return this.cheese;
  }

  @Override
  public Ingredient getCrust() {
    return crust;
  }

  @Override
  public Ingredient[] getToppings() {
    Ingredient[] temp;
    if (toppings.length == 0) {
      temp = new IngredientImpl[0];
    } else {
      temp = new IngredientImpl[toppings.length];
      for (int i = 0; i < toppings.length; i++) {
        temp[i] = toppings[i];
      }
    }
    return temp;
  }

  @Override
  public Ingredient[] getIngredients() {
    Ingredient[] temp;
    if (toppings.length == 0) {
      temp = new IngredientImpl[3];
      temp[0] = this.crust;
      temp[1] = this.sauce;
      temp[2] = this.cheese;
    } else {
      temp = new IngredientImpl[toppings.length + 3];
      for (int i = 0; i < toppings.length; i++) {
        temp[i] = toppings[i];
      }
      temp[toppings.length] = this.crust;
      temp[toppings.length + 1] = this.sauce;
      temp[toppings.length + 2] = this.cheese;
    }
    return temp;
  }
}
