package com.comp301.a02adventure;

import java.util.Objects;

public final class ItemImpl implements Item {
  private String name;

  public ItemImpl(String name) {
    if (name == null) {
      throw new IllegalArgumentException();
    }
    this.name = name;
  }

  @Override
  public String getName() {
    return this.name;
  }

  @Override
  public boolean equals(Object other) {
    if (other != null && other.getClass() == this.getClass()) {
      if (!(this.name.equals(((Item) other).getName()))) {
        return false;
      } else {
        return true;
      }
    } else {
      return false;
    }
  }

  @Override
  public String toString() {
    return this.name;
  }
}
