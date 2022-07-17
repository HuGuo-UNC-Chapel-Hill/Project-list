package com.comp301.a02adventure;

import java.util.ArrayList;
import java.util.List;

public class GameImpl implements Game {
  private Player player;
  private Map map;

  public GameImpl(Map map, Player player) {
    if (player != null && map != null) {
      this.map = map;
      this.player = player;
    } else {
      throw new IllegalArgumentException();
    }
  }

  @Override
  public Position getPlayerPosition() {
    return this.player.getPosition();
  }

  @Override
  public String getPlayerName() {
    return this.player.getName();
  }

  @Override
  public List<Item> getPlayerItems() {
    return this.player.getInventory().getItems();
  }

  @Override
  public boolean getIsWinner() {
    if (this.player.getInventory().getNumItems() == this.map.getNumItems()) {
      return true;
    } else {
      return false;
    }
  }

  @Override
  public void printCellInfo() {
    Cell temp = this.map.getCell(this.player.getPosition());
    System.out.println("Location: " + temp.getName());
    System.out.println(temp.getDescription());
    if (temp.getIsVisited()) {
      System.out.println("You have already visited this location.");
    }
    if (temp.hasChest()) {
      System.out.println("You found a chest! Type 'open' to see what's inside, or keep moving.");
    }
    temp.visit();
  }

  @Override
  public void openChest() {
    Cell temp = this.map.getCell(this.player.getPosition());
    if (!temp.hasChest()) {
      System.out.println("No chest to open, sorry!");
    } else if (temp.getChest().isEmpty()) {
      System.out.println("The chest is empty.");
    } else {
      System.out.println("You collected these items: " + temp.getChest().getItems());
      this.player.getInventory().transferFrom(temp.getChest());
    }
  }

  @Override
  public boolean canMove(Direction direction) {
    Position temp = this.player.getPosition().getNeighbor(direction);
    if (temp.getX() >= this.map.getWidth()
        || temp.getX() < 0
        || temp.getY() >= this.map.getHeight()
        || temp.getY() < 0) {
      return false;
    } else {
      if (this.map.getCell(temp) != null) {
        return true;
      }
    }
    return false;
  }

  @Override
  public void move(Direction direction) {
    if (this.canMove(direction)) {
      this.player.move(direction);
      this.printCellInfo();
    } else {
      System.out.println("You can't go that way! Try another direction.");
    }
  }
}
