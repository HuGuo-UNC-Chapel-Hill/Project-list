package com.comp301.a06image;

import java.awt.Color;
import java.io.IOException;
import javafx.application.Application;

public class Main {
  /**
   * Creates and returns an image object for testing. The image that this method produces will be
   * automatically displayed on the screen when main() is run below. Use this method to test
   * different decorators.
   */
  public static Image makeImage() throws IOException {
    // TODO use this method for testing your decorators
    PictureImage pi = new PictureImage("img/kmp.jpg");
    BorderDecorator rbi = new BorderDecorator(pi, 5, new Color(255, 0, 0));
    BorderDecorator bbi = new BorderDecorator(rbi, 50, new Color(0, 0, 255));
    CircleDecorator yci = new CircleDecorator(bbi, 50, 50, 40, new Color(255, 255, 0));
    SquareDecorator osi = new SquareDecorator(yci, 100, 100, 40, new Color(200, 80, 10));
    ZoomDecorator zi = new ZoomDecorator(osi);
    return zi;
  }

  /**
   * Use this method for testing your code. When main() runs, the image you created and decorated in
   * the makeImage() method above will be generated and displayed on the screen. You don't need to
   * make any changes to this main() method.
   */
  public static void main(String[] args) {
    Application.launch(ImageDisplay.class, args);
  }
}
