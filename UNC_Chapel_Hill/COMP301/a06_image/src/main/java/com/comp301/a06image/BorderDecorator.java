package com.comp301.a06image;

import java.awt.*;

public class BorderDecorator implements Image {
  private Image image;
  private int width;
  private int height;
  private int thiccness;
  private Color borderColor;

  public BorderDecorator(Image image, int thiccness, Color borderColor) {
    // Constructor code goes here
    if (thiccness < 0 || image == null) {
      throw new IllegalArgumentException();
    } else {
      this.image = image;
      this.width = image.getWidth() + 2 * thiccness;
      this.height = image.getHeight() + 2 * thiccness;
      this.thiccness = thiccness;
      this.borderColor = borderColor;
    }
  }

  @Override
  public Color getPixelColor(int x, int y) {
    if (x < 0 || x >= this.width || y < 0 || y >= this.height) {
      throw new IllegalArgumentException();
    } else {
      if ((x >= this.thiccness && x < this.width - this.thiccness)
          && (y >= this.thiccness && y < this.height - this.thiccness)) {
        return this.image.getPixelColor(x - this.thiccness, y - this.thiccness);
      } else {
        return borderColor;
      }
    }
  }

  @Override
  public int getWidth() {
    return this.width;
  }

  @Override
  public int getHeight() {
    return height;
  }

  @Override
  public int getNumLayers() {
    return 1 + this.image.getNumLayers();
  }
}
