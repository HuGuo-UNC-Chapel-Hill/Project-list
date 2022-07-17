package com.comp301.a06image;

import java.awt.*;

public class SquareDecorator implements Image {
  private Image image;
  private int width;
  private int height;
  private int squareX;
  private int squareY;
  private int squareSize;
  private Color squareColor;

  public SquareDecorator(Image image, int squareX, int squareY, int squareSize, Color color) {
    // Constructor code goes here
    if (squareSize < 0 || image == null) {
      throw new IllegalArgumentException();
    }
    this.image = image;
    this.width = image.getWidth();
    this.height = image.getHeight();
    this.squareX = squareX;
    this.squareY = squareY;
    this.squareSize = squareSize;
    this.squareColor = color;
  }

  @Override
  public Color getPixelColor(int x, int y) {
    if (x < 0 || x >= this.width || y < 0 || y >= this.height) {
      throw new IllegalArgumentException();
    } else {
      if ((x >= squareX && x < squareX + squareSize) && (y >= squareY & y < squareY + squareSize)) {
        return squareColor;
      } else {
        return this.image.getPixelColor(x, y);
      }
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
  public int getNumLayers() {
    return 1 + this.image.getNumLayers();
  }
}
