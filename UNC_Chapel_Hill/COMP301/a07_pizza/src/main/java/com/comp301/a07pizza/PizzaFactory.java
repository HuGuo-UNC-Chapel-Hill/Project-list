package com.comp301.a07pizza;

public class PizzaFactory {

  public static Pizza makeCheesePizza(Pizza.Size size) {
    Topping[] toppings = new Topping[0];
    return new PizzaImpl(size, Crust.HAND_TOSSED, Sauce.TOMATO, Cheese.BLEND, toppings);
  }

  public static Pizza makeHawaiianPizza(Pizza.Size size) {
    Topping[] toppings = new Topping[2];
    toppings[0] = Topping.HAM;
    toppings[1] = Topping.PINEAPPLE;
    return new PizzaImpl(size, Crust.HAND_TOSSED, Sauce.TOMATO, Cheese.BLEND, toppings);
  }

  public static Pizza makeMeatLoversPizza(Pizza.Size size) {
    Topping[] toppings = new Topping[4];
    toppings[0] = Topping.PEPPERONI;
    toppings[1] = Topping.SAUSAGE;
    toppings[2] = Topping.BACON;
    toppings[3] = Topping.GROUND_BEEF;
    return new PizzaImpl(size, Crust.DEEP_DISH, Sauce.TOMATO, Cheese.BLEND, toppings);
  }

  public static Pizza makeVeggieSupremePizza(Pizza.Size size) {
    Topping[] toppings = new Topping[4];
    toppings[0] = Topping.SUN_DRIED_TOMATO;
    toppings[1] = Topping.GREEN_PEPPER;
    toppings[2] = Topping.MUSHROOMS;
    toppings[3] = Topping.OLIVES;
    return new PizzaImpl(size, Crust.THIN, Sauce.TOMATO, Cheese.BLEND, toppings);
  }

  public static Pizza makeDailySpecialPizza() {
    Topping[] toppings = new Topping[4];
    toppings[0] = Topping.SUN_DRIED_TOMATO;
    toppings[1] = Topping.GREEN_PEPPER;
    toppings[2] = Topping.MUSHROOMS;
    toppings[3] = Topping.OLIVES;
    return new PizzaImpl(Pizza.Size.MEDIUM, Crust.THIN, Sauce.TOMATO, Cheese.BLEND, toppings);
  }
}
