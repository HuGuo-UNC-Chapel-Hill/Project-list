package com.comp301.a09akari.controller;

import com.comp301.a09akari.model.Puzzle;
import com.comp301.a09akari.model.Model;
import java.util.Random;

public class ControllerImpl implements AlternateMvcController {
  private Model model;

  public ControllerImpl(Model model) {
    if (model == null) {
      throw new IllegalArgumentException();
    }
    this.model = model;
  }

  @Override
  public void clickNextPuzzle() {
    int index = this.model.getActivePuzzleIndex();
    if (index < this.model.getPuzzleLibrarySize() - 1) {
      this.model.setActivePuzzleIndex(index + 1);
    }
  }

  @Override
  public void clickPrevPuzzle() {
    int index = this.model.getActivePuzzleIndex();
    if (index > 0) {
      this.model.setActivePuzzleIndex(index - 1);
    }
  }

  @Override
  public void clickRandPuzzle() {
    Random rand = new Random();
    int index = rand.nextInt(this.model.getPuzzleLibrarySize());
    if (index == this.model.getActivePuzzleIndex()) {
      this.clickRandPuzzle();
    } else {
      this.model.setActivePuzzleIndex(index);
    }
  }

  public int returnIndex() {
    return this.model.getActivePuzzleIndex() + 1;
  }

  public int returnSize() {
    return this.model.getPuzzleLibrarySize();
  }

  @Override
  public void clickResetPuzzle() {
    this.model.resetPuzzle();
  }

  @Override
  public void clickCell(int r, int c) {
    if (this.model.isLamp(r, c)) {
      this.model.removeLamp(r, c);
    } else {
      this.model.addLamp(r, c);
    }
  }

  @Override
  public boolean isLit(int r, int c) {
    return this.model.isLit(r, c);
  }

  @Override
  public boolean isLamp(int r, int c) {
    return this.model.isLamp(r, c);
  }

  public boolean isLampIllegal(int r, int c) {
    return this.model.isLampIllegal(r, c);
  }

  @Override
  public boolean isClueSatisfied(int r, int c) {
    return this.model.isClueSatisfied(r, c);
  }

  @Override
  public boolean isSolved() {
    return this.model.isSolved();
  }

  @Override
  public Puzzle getActivePuzzle() {
    return this.model.getActivePuzzle();
  }
}
