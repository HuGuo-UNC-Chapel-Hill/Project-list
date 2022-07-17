package com.comp301.a02adventure;

public class PositionImpl implements Position {
  private final int x;
  private final int y;

  public PositionImpl(int x, int y) {
    if (x == (int) x && y == (int) y) {
      this.x = x;
      this.y = y;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public int getX() {
    return this.x;
  }

  @Override
  public int getY() {
    return this.y;
  }

  @Override
  public Position getNeighbor(Direction direction) {
    if (direction == direction.NORTH) {
      return new PositionImpl(this.x, this.y + 1);
    } else if (direction == direction.SOUTH) {
      return new PositionImpl(this.x, this.y - 1);
    } else if (direction == direction.EAST) {
      return new PositionImpl(this.x + 1, this.y);
    } else if (direction == direction.WEST) {
      return new PositionImpl(this.x - 1, this.y);
    }
    return null;
  }
}
