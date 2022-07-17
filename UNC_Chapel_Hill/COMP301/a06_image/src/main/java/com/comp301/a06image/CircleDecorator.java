package com.comp301.a06image;

import java.awt.*;

public class CircleDecorator implements Image {
  private Image image;
  private int width;
  private int height;
  private int cx;
  private int cy;
  private int radius;
  private Color cycleColor;

  public CircleDecorator(Image image, int cx, int cy, int radius, Color color) {
    if (radius < 0 || image == null) {
      throw new IllegalArgumentException();
    }
    this.image = image;
    this.width = this.image.getWidth();
    this.height = this.image.getHeight();
    this.cx = cx;
    this.cy = cy;
    this.radius = radius;
    this.cycleColor = color;
  }

  @Override
  public Color getPixelColor(int x, int y) {
    if (x < 0 || x >= this.width || y < 0 || y >= this.height) {
      throw new IllegalArgumentException();
    } else {
      double distance = Math.sqrt(Math.pow((cx - x), 2) + Math.pow((cy - y), 2));
      if (distance < radius) {
        return cycleColor;
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
