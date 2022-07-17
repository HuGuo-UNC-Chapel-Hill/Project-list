package com.comp301.a02adventure;

public class CellImpl implements Cell {
  private Position position;
  private String name;
  private String description;
  private Inventory chest;
  private boolean visit;

  public CellImpl(int x, int y) {
    this.position = new PositionImpl(x, y);
    this.name = "";
    this.description = "";
  }

  public CellImpl(int x, int y, String name, String description) {
    this(x, y);
    if (name == null || description == null) {
      throw new IllegalArgumentException();
    } else {
      this.name = name;
      this.description = description;
    }
    this.visit = false;
  }

  @Override
  public String getName() {
    return this.name;
  }

  @Override
  public String getDescription() {
    return this.description;
  }

  @Override
  public Position getPosition() {
    return this.position;
  }

  @Override
  public Inventory getChest() {
    return this.chest;
  }

  @Override
  public boolean getIsVisited() {
    return this.visit;
  }

  @Override
  public boolean hasChest() {
    if (this.chest != null) {
      return true;
    } else {
      return false;
    }
  }

  @Override
  public void setName(String name) {
    if (name != null) {
      this.name = name;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public void setDescription(String description) {
    if (description != null) {
      this.description = description;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public void setChest(Inventory chest) {
    if (chest != null) {
      this.chest = chest;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public void visit() {
    this.visit = true;
  }
}
