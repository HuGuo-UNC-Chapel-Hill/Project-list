package com.comp301.a09akari.model;

import java.util.ArrayList;

public class ModelImpl implements Model {
  private PuzzleLibrary puzzleLibrary;
  private int currentPuzzleIndex;
  private ArrayList<ModelObserver> modelObserves = new ArrayList<ModelObserver>();
  private boolean[][] lampsList;
  private boolean emptyClue;

  public ModelImpl(PuzzleLibrary library) {
    if (library == null) {
      throw new IllegalArgumentException();
    }
    this.puzzleLibrary = library;
    this.currentPuzzleIndex = 0;
    initialLampsList();
    emptyClue = false;
  }

  // create the empty lampsList 2d array with false value for all element
  private void initialLampsList() {
    boolean[][] temp =
        new boolean[this.getActivePuzzle().getHeight()][this.getActivePuzzle().getWidth()];
    for (int i = 0; i < temp.length; i++) {
      for (int j = 0; j < temp[0].length; j++) {
        temp[i][j] = false;
      }
    }
    this.lampsList = temp;
  }

  private void initialLampsList(int r, int c) {
    boolean[][] temp = new boolean[r][c];
    for (int i = 0; i < temp.length; i++) {
      for (int j = 0; j < temp[0].length; j++) {
        temp[i][j] = false;
      }
    }
    this.lampsList = temp;
  }

  private void inRange(int r, int c) {
    if (r >= this.getActivePuzzle().getHeight()
        || c >= this.getActivePuzzle().getWidth()
        || r < 0
        || c < 0) {
      throw new IndexOutOfBoundsException();
    }
  }

  private void isCorridor(int r, int c) {
    if (this.getActivePuzzle().getCellType(r, c) != CellType.CORRIDOR) {
      throw new IllegalArgumentException();
    }
  }

  private void isClue(int r, int c) {
    if (this.getActivePuzzle().getCellType(r, c) != CellType.CLUE) {
      throw new IllegalArgumentException();
    }
  }

  private void isWall(int r, int c) {
    if (this.getActivePuzzle().getCellType(r, c) != CellType.WALL) {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public void addLamp(int r, int c) {
    inRange(r, c);
    isCorridor(r, c);
    this.lampsList[r][c] = true;
    notifyObserves();
  }

  @Override
  public void removeLamp(int r, int c) {
    inRange(r, c);
    isCorridor(r, c);
    this.lampsList[r][c] = false;
    notifyObserves();
  }

  @Override
  public boolean isLit(int r, int c) {
    inRange(r, c);
    isCorridor(r, c);
    if (this.getActivePuzzle().getCellType(r, c) == CellType.CORRIDOR
        && this.lampsList[r][c] == true) {
      return true;
    } else {
      for (int upr = r + 1; upr < this.getActivePuzzle().getHeight(); upr++) {
        if (this.getActivePuzzle().getCellType(upr, c) == CellType.CORRIDOR
            && this.lampsList[upr][c] == true) {
          return true;
        } else if (this.getActivePuzzle().getCellType(upr, c) != CellType.CORRIDOR) {
          break;
        }
      }
      for (int downr = r - 1; downr >= 0; downr--) {
        if (this.getActivePuzzle().getCellType(downr, c) == CellType.CORRIDOR
            && this.lampsList[downr][c] == true) {
          return true;
        } else if (this.getActivePuzzle().getCellType(downr, c) != CellType.CORRIDOR) {
          break;
        }
      }
      for (int leftc = c + 1; leftc < this.getActivePuzzle().getWidth(); leftc++) {
        if (this.getActivePuzzle().getCellType(r, leftc) == CellType.CORRIDOR
            && this.lampsList[r][leftc] == true) {
          return true;
        } else if (this.getActivePuzzle().getCellType(r, leftc) != CellType.CORRIDOR) {
          break;
        }
      }
      for (int rightc = c - 1; rightc >= 0; rightc--) {
        if (this.getActivePuzzle().getCellType(r, rightc) == CellType.CORRIDOR
            && this.lampsList[r][rightc] == true) {
          return true;
        } else if (this.getActivePuzzle().getCellType(r, rightc) != CellType.CORRIDOR) {
          break;
        }
      }
    }
    return false;
  }

  @Override
  public boolean isLamp(int r, int c) {
    inRange(r, c);
    isCorridor(r, c);
    return this.lampsList[r][c];
  }

  @Override
  public boolean isLampIllegal(int r, int c) {
    inRange(r, c);
    isCorridor(r, c);
    for (int upr = r + 1; upr < this.getActivePuzzle().getHeight(); upr++) {
      if (this.getActivePuzzle().getCellType(upr, c) == CellType.CORRIDOR
          && this.lampsList[upr][c] == true) {
        return true;
      } else if (this.getActivePuzzle().getCellType(upr, c) != CellType.CORRIDOR) {
        break;
      }
    }
    for (int downr = r - 1; downr >= 0; downr--) {
      if (this.getActivePuzzle().getCellType(downr, c) == CellType.CORRIDOR
          && this.lampsList[downr][c] == true) {
        return true;
      } else if (this.getActivePuzzle().getCellType(downr, c) != CellType.CORRIDOR) {
        break;
      }
    }
    for (int leftc = c + 1; leftc < this.getActivePuzzle().getWidth(); leftc++) {
      if (this.getActivePuzzle().getCellType(r, leftc) == CellType.CORRIDOR
          && this.lampsList[r][leftc] == true) {
        return true;
      } else if (this.getActivePuzzle().getCellType(r, leftc) != CellType.CORRIDOR) {
        break;
      }
    }
    for (int rightc = c - 1; rightc >= 0; rightc--) {
      if (this.getActivePuzzle().getCellType(r, rightc) == CellType.CORRIDOR
          && this.lampsList[r][rightc] == true) {
        return true;
      } else if (this.getActivePuzzle().getCellType(r, rightc) != CellType.CORRIDOR) {
        break;
      }
    }
    return false;
  }

  @Override
  public Puzzle getActivePuzzle() {
    return this.puzzleLibrary.getPuzzle(this.getActivePuzzleIndex());
  }

  @Override
  public int getActivePuzzleIndex() {
    return this.currentPuzzleIndex;
  }

  @Override
  public void setActivePuzzleIndex(int index) {
    if (index >= this.getPuzzleLibrarySize() || index < 0) {
      throw new IndexOutOfBoundsException();
    }
    this.currentPuzzleIndex = index;
    int height = this.getActivePuzzle().getHeight();
    int width = this.getActivePuzzle().getWidth();
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        initialLampsList(height, width);
      }
    }
    notifyObserves();
  }

  @Override
  public int getPuzzleLibrarySize() {
    return this.puzzleLibrary.size();
  }

  @Override
  public void resetPuzzle() {
    for (int i = 0; i < this.getActivePuzzle().getHeight(); i++) {
      for (int j = 0; j < this.getActivePuzzle().getWidth(); j++) {
        this.lampsList[i][j] = false;
      }
    }
    notifyObserves();
  }

  @Override
  public boolean isSolved() {
    for (int i = 0; i < this.getActivePuzzle().getHeight(); i++) {
      for (int j = 0; j < this.getActivePuzzle().getWidth(); j++) {
        if (lampsList[i][j] == true && isLampIllegal(i, j)) {
          return false;
        }
        if (this.getActivePuzzle().getCellType(i, j) == CellType.CORRIDOR && !isLit(i, j)) {
          return false;
        }
        if (this.getActivePuzzle().getCellType(i, j) == CellType.CLUE && !isClueSatisfied(i, j))
          return false;
      }
    }
    return true;
  }

  @Override
  public boolean isClueSatisfied(int r, int c) {
    inRange(r, c);
    isClue(r, c);
    int l = 0;
    int upr = (r + 1) % this.getActivePuzzle().getHeight();
    if (lampsList[upr][c] == true) {
      l++;
    }
    int downr = (r - 1 + this.getActivePuzzle().getHeight()) % this.getActivePuzzle().getHeight();
    if (lampsList[downr][c] == true) {
      l++;
    }
    int rightc = (c + 1) % this.getActivePuzzle().getWidth();
    if (lampsList[r][rightc] == true) {
      l++;
    }
    int leftc = (c - 1 + this.getActivePuzzle().getWidth()) % this.getActivePuzzle().getWidth();
    if (lampsList[r][leftc] == true) {
      l++;
    }
    return l == this.getActivePuzzle().getClue(r, c);
  }

  @Override
  public void addObserver(ModelObserver observer) {
    this.modelObserves.add(observer);
  }

  @Override
  public void removeObserver(ModelObserver observer) {
    this.modelObserves.remove(observer);
  }

  public void notifyObserves() {
    for (ModelObserver o : modelObserves) {
      o.update(this);
    }
  }
}
