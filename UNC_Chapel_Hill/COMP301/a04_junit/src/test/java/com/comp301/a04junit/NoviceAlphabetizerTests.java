package com.comp301.a04junit;

import org.junit.Test;

import com.comp301.a04junit.alphabetizer.Alphabetizer;

import org.junit.Test;

import java.util.NoSuchElementException;

import static org.junit.Assert.*;

/** Write tests for the Alphabetizer class here */
public class NoviceAlphabetizerTests {

  @Test
  public void unitTest1() {
      String[] str = new String[] {"c", "b", "a"};
      Alphabetizer test = new Alphabetizer(str);
      assertEquals("a", test.next());
      assertTrue(test.hasNext());
      assertEquals("b", test.next());
      assertTrue(test.hasNext());
      assertEquals("c", test.next());
      assertFalse(test.hasNext());
  }

  @Test
  public void unitTest2() {
    try {
      String[] str = new String[] {"c", "b", "a"};
      Alphabetizer test = new Alphabetizer(str);
      assertEquals("a", test.next());
      assertTrue(test.hasNext());
      assertEquals("b", test.next());
      assertTrue(test.hasNext());
      assertEquals("c", test.next());
      test.next();
      fail();
    } catch (NoSuchElementException e) {

    }
  }

  @Test
  public void unitTest3() {
    Alphabetizer test = new Alphabetizer(null);
  }

  @Test
  public void unitTest4() {
    try {
      String[] str = new String[] {"A"};
      Alphabetizer test = new Alphabetizer(str);
      assertEquals("A", test.next());
    } catch (IllegalArgumentException e) {
      fail("Exception" + e);
    }
  }

  @Test
  public void unitTest5() {
    try {
      Alphabetizer test = new Alphabetizer(new String[] {"3", "2", "1"});
      assertEquals("1", test.next());
      assertEquals("2", test.next());
      assertEquals("3", test.next());
    } catch (IllegalArgumentException e) {

    }
  }

  @Test
  public void unitTest6() {
    try {
      Alphabetizer test = new Alphabetizer(new String[] {"A", "a"});
      assertEquals("A", test.next());
      assertEquals("a", test.next());
    } catch (IllegalArgumentException e) {

    }
  }

  @Test
  public void unitTest7() {
    String[] str = new String[] {"a", "b", "c"};
    Alphabetizer test = new Alphabetizer(str);
    str[0] = "d";
    assertEquals("a", test.next());
    assertEquals("b", test.next());
    assertEquals("c", test.next());
  }
}
