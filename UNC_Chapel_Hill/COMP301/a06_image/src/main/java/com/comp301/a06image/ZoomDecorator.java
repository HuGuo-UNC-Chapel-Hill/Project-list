package com.comp301.a06image;

import java.awt.*;

public class ZoomDecorator implements Image {
  private Image image;
  private int multiplier;
  private int width;
  private int height;

  public ZoomDecorator(Image image, int multiplier) {
    // Constructor code goes here
    if (multiplier <= 0 || image == null) {
      throw new IllegalArgumentException();
    } else {
      this.image = image;
      this.multiplier = multiplier;
      this.width = image.getWidth() * this.multiplier;
      this.height = image.getHeight() * this.multiplier;
    }
  }

  public ZoomDecorator(Image image) {
    this(image, 2);
  }

  @Override
  public Color getPixelColor(int x, int y) {
    if (x < 0 || x >= this.width || y < 0 || y >= this.height) {
      throw new IllegalArgumentException();
    } else {
      return this.image.getPixelColor(x / this.multiplier, y / this.multiplier);
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
