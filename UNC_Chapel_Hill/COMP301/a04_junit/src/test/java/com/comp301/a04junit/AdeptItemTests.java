package com.comp301.a04junit;

import com.comp301.a04junit.adventure.Item;
import com.comp301.a04junit.adventure.ItemImpl;

import org.junit.Test;

import static org.junit.Assert.*;

/** Write unit tests for the ItemImpl class here */
public class  AdeptItemTests {
  @Test
  public void unitTest1() {
    String str = "Abc";
    Item test = new ItemImpl(str);
    assertEquals(str, test.getName());
  }

  @Test
  public void unitTest2() {
    String str = "Abc";
    Item test = new ItemImpl(str);
    assertEquals(str, test.toString());
  }

  @Test
  public void unitTest3() {
    String str1 = "ABC";
    Item test1 = new ItemImpl(str1);
    Item test2 = new ItemImpl(str1);
    assertEquals(test2, test1);
  }

  @Test
  public void unitTest4() {
    String str1 = "abc";
    Item test1 = new ItemImpl(str1);
    assertNotEquals(null, test1);
  }

  @Test
  public void nullNameTest() {
    try {
      new ItemImpl(null);
      fail();
    } catch (IllegalArgumentException e) {

    }
  }

}
