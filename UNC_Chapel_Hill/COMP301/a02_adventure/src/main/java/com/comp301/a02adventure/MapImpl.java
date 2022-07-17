package com.comp301.a02adventure;

public class MapImpl implements Map {
  private int width;
  private int height;
  private final int numItems;
  private CellImpl[][] mapCells;

  public MapImpl(int width, int height, int numItems) {
    if (width <= 0 || height <= 0) {
      throw new IllegalArgumentException();
    } else {
      this.width = width;
      this.height = height;
      this.numItems = numItems;
      this.mapCells = new CellImpl[width][height];
    }
  }

  @Override
  public int getWidth() {
    return this.width;
  }

  @Override
  public int getHeight() {
    return this.height;
  }

  @Override
  public Cell getCell(int x, int y) {
    if (x > this.width - 1 || y > this.height - 1 || x < 0 || y < 0) {
      throw new IndexOutOfBoundsException();
    } else {
      return this.mapCells[x][y];
    }
  }

  @Override
  public Cell getCell(Position position) {
    if (position.getX() > this.width - 1
        || position.getY() > this.height - 1
        || position.getX() < 0
        || position.getY() < 0) {
      throw new IndexOutOfBoundsException();
    } else {
      return this.getCell(position.getX(), position.getY());
    }
  }

  @Override
  public void initCell(int x, int y) {
    if (x > this.width - 1 || y > this.height - 1 || x < 0 || y < 0) {
      throw new IndexOutOfBoundsException();
    } else {
      this.mapCells[x][y] = new CellImpl(x, y);
    }
  }

  @Override
  public int getNumItems() {
    return this.numItems;
  }
}
