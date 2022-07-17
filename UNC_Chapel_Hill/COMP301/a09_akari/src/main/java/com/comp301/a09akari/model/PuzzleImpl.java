package com.comp301.a09akari.model;

public class PuzzleImpl implements Puzzle {
  private int[][] board;

  public PuzzleImpl(int[][] board) {
    if (board != null) {
      this.board = board;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public int getWidth() {
    return this.board[0].length;
  }

  @Override
  public int getHeight() {
    return this.board.length;
  }

  @Override
  public CellType getCellType(int r, int c) {
    if (r >= this.getHeight() || c >= this.getWidth()) {
      throw new IndexOutOfBoundsException();
    }
    if (this.board[r][c] < 5) {
      return CellType.CLUE;
    } else if (this.board[r][c] == 5) {
      return CellType.WALL;
    }
    return CellType.CORRIDOR;
  }

  @Override
  public int getClue(int r, int c) {
    if (r >= this.getHeight() || c >= this.getWidth()) {
      throw new IndexOutOfBoundsException();
    }
    if (this.getCellType(r, c) != CellType.CLUE) {
      throw new IllegalArgumentException();
    }
    return this.board[r][c];
  }
}
