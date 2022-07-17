package com.comp301.a04junit;

import static org.junit.Assert.assertTrue;

import com.comp301.a04junit.adventure.*;

import static org.junit.Assert.*;
import org.junit.Test;

/** Write unit tests for the PlayerImpl class here */
public class JediPlayerTests {
  @Test
  public void unitTest1() {
    try {
      Player test = new PlayerImpl(null, 0, 0);
      fail();
    } catch (IllegalArgumentException e) {

    }
  }

  @Test
  public void unitTest2() {
    Player test = new PlayerImpl("abc", 12, 27);
    assertEquals("abc", test.getName());
    assertEquals(12, test.getPosition().getX());
    assertEquals(27, test.getPosition().getY());
  }

  @Test
  public void unitTest3() {
    Player test = new PlayerImpl("abc", 1, 1);
    assertEquals(0, test.getInventory().getNumItems());
    Item item = new ItemImpl("a");
    test.getInventory().addItem(item);
    assertEquals(1, test.getInventory().getNumItems());
  }

  @Test
  public void unitTest4() {
    Player test = new PlayerImpl("abc", 10,10);
    test.move(Direction.SOUTH);
    assertEquals(9, test.getPosition().getY());
    test.move(Direction.NORTH);
    assertEquals(10, test.getPosition().getY());
    test.move(Direction.EAST);
    assertEquals(11, test.getPosition().getX());
    test.move(Direction.WEST);
    assertEquals(10, test.getPosition().getX());
  }
}
