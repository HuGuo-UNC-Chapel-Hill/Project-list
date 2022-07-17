package com.comp301.a04junit;

import static org.junit.Assert.assertTrue;

import com.comp301.a04junit.adventure.Item;
import com.comp301.a04junit.adventure.ItemImpl;
import com.comp301.a04junit.adventure.Inventory;
import com.comp301.a04junit.adventure.InventoryImpl;
import java.util.ArrayList;
import java.util.List;

import org.junit.Test;
import static org.junit.Assert.*;

/** Write unit tests for the InventoryImpl class here */
public class JediInventoryTests {

  @Test
  public void unitTest1() {
    Inventory test = new InventoryImpl();
    assertTrue(test.isEmpty());
  }

  @Test
  public void unitTest2() {
    Inventory test = new InventoryImpl();
    Item item1 = new ItemImpl("abc");
    Item item2 = new ItemImpl("def");
    test.addItem(item1);
    test.addItem(item2);
    assertEquals(2, test.getNumItems());
    test.removeItem(test.getItems().get(0));
    assertEquals(1, test.getNumItems());
    test.clear();
    assertEquals(0, test.getNumItems());
  }

  @Test
  public void unitTest3() {
    Inventory test1 = new InventoryImpl();
    Item item1 = new ItemImpl("a");
    Item item2 = new ItemImpl("b");
    test1.addItem(item1);
    test1.addItem(item2);
    Inventory test2 = new InventoryImpl();
    test2.transferFrom(test1);
    assertEquals(2, test2.getNumItems());
    assertEquals(item1, test2.getItems().get(0));
  }

  @Test
  public void unitTest4() {
    Item item = new ItemImpl("a");
    Inventory test = new InventoryImpl();
    test.transferFrom(null);
    assertEquals(0, test.getNumItems());
    test.addItem(item);
    assertEquals(1, test.getNumItems());
  }
}
