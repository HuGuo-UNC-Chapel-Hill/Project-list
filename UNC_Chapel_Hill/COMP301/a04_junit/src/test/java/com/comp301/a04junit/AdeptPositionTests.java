package com.comp301.a04junit;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import com.comp301.a04junit.adventure.Direction;
import com.comp301.a04junit.adventure.Position;
import com.comp301.a04junit.adventure.PositionImpl;

import org.junit.Test;

/** Write unit tests for the PositionImpl class here */
public class AdeptPositionTests {
  @Test
  public void unitTest1() {
    Position test1 = new PositionImpl(1, 2);
    assertEquals(1,test1.getX());
    assertEquals(2,test1.getY());
    Position test2 = new PositionImpl(11, 12);
    assertEquals(11,test2.getX());
    assertEquals(11,test2.getX());
    assertEquals(12,test2.getY());
    assertEquals(12,test2.getY());
  }

  @Test
  public void unitTest2() {
    try {
      Position test = new PositionImpl(-2, 2);
    } catch (IllegalArgumentException e) {

    }
  }

  @Test
  public void unitTest3() {
    Position test = new PositionImpl(10, 20);
    assertEquals(21,test.getNeighbor(Direction.NORTH).getY());
    assertEquals(19,test.getNeighbor(Direction.SOUTH).getY());
    assertEquals(9,test.getNeighbor(Direction.WEST).getX());
    assertEquals(11,test.getNeighbor(Direction.EAST).getX());
  }
}
