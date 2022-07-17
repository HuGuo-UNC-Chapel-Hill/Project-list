package com.comp301.a06image;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class PictureImage implements Image {
  private BufferedImage image;
  private int width;
  private int height;

  public PictureImage(String pathname) throws IOException {

    this.image = ImageIO.read(new File(pathname));
    this.width = this.image.getWidth();
    this.height = this.image.getHeight();
  }

  @Override
  public Color getPixelColor(int x, int y) {
    if (x < 0 || x >= this.width || y < 0 || y >= this.height) {
      throw new IllegalArgumentException();
    }
    return new Color(this.image.getRGB(x, y));
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
    return 1;
  }
}
