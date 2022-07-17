package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import com.comp301.a09akari.model.CellType;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.layout.*;
import javafx.scene.control.Label;
// import javafx.scene.media.AudioClip;
import java.io.File;

public class BoardView implements FXComponent {
  private final AlternateMvcController controller;
  //  private static boolean position = false;

  public BoardView(AlternateMvcController controller) {
    this.controller = controller;
  }

  @Override
  public Parent render() {
    StackPane stack = new StackPane();

    BorderPane layout = new BorderPane();
    HBox leftSpace = new HBox();
    leftSpace.setMinWidth(70);
    leftSpace.setMaxWidth(300);
    HBox.setHgrow(leftSpace, Priority.ALWAYS);
    leftSpace.setOnMouseClicked((event) -> {});
    layout.setLeft(leftSpace);
    GridPane board = new GridPane();
    board.setHgap(1);
    board.setVgap(1);
    board.setGridLinesVisible(true);
    GridPane.setHgrow(board, Priority.ALWAYS);
    board.setMinHeight(350);
    board.setMinWidth(500);
    int r = this.controller.getActivePuzzle().getHeight();
    int c = this.controller.getActivePuzzle().getWidth();
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        board.add(this.makeTile(i, j), j, i);
      }
    }

    board.setOnMouseClicked(
        (event) -> {
          Node source = (Node) event.getTarget();
          if (board.getRowIndex(source) != null && board.getColumnIndex(source) != null) {
            int cnum = board.getColumnIndex(source);
            int rnum = board.getRowIndex(source);
            if (this.controller.getActivePuzzle().getCellType(rnum, cnum) == CellType.CORRIDOR) {
              this.controller.clickCell(rnum, cnum);
              //              if (this.controller.isLamp(rnum, cnum)
              //                  && this.lamp() != null
              //                  && !this.controller.isLampIllegal(rnum, cnum)) {
              //                lamp().play();
              //              }
              //              if (position == false) {
              //                if (this.controller.isLampIllegal(rnum, cnum) && this.illegal() !=
              // null) {
              //                  illegal().play();
              //                  position = true;
              //                }
              //              } else if (position = true && this.lamp() != null) {
              //                lamp().play();
              //                position = false;
              //              }
            }
            //            System.out.println("click test");
          }
        });
    layout.setCenter(board);
    stack.getChildren().add(layout);

    if (this.controller.isSolved()) {
      Image img = new Image("c.png");
      ImageView view = new ImageView(img);
      view.setFitHeight(180);
      view.setPreserveRatio(true);
      stack.getChildren().add(view);
    }

    return stack;
  }

  private Label makeTile(int r, int c) {
    Label tile;
    Image img = new Image("light-bulb.png");
    ImageView view = new ImageView(img);
    view.setFitHeight(32);
    view.setPreserveRatio(true);
    CellType currentCell = this.controller.getActivePuzzle().getCellType(r, c);
    if (currentCell == CellType.CORRIDOR) {
      tile = new Label();
      tile.getStyleClass().add("tile");
      tile.getStyleClass().add("tile-6");
      if (this.controller.isLamp(r, c)) {
        tile.getStyleClass().add("tile-lamp");
        tile.setGraphic(view);
      }
      if (this.controller.isLit(r, c)) {
        tile.getStyleClass().add("tile-lit");
      }
      if (this.controller.isLamp(r, c) && this.controller.isLampIllegal(r, c)) {
        tile.getStyleClass().add("tile-illegal");
      }
    } else if (currentCell == CellType.WALL) {
      tile = new Label();
      tile.getStyleClass().add("tile");
      tile.getStyleClass().add("tile-5");
    } else {
      tile = new Label(String.valueOf(this.controller.getActivePuzzle().getClue(r, c)));
      tile.getStyleClass().add("tile");
      //      tile.getStyleClass().add("tile-c");
      if (this.controller.isClueSatisfied(r, c)) {
        tile.getStyleClass().add("tile-c-s");
      } else {
        tile.getStyleClass().add("tile-c");
      }
    }
    return tile;
  }

  //  private AudioClip lamp() {
  //    File src = new File("src/main/resources/lamp.mp3");
  //    AudioClip lamp = new AudioClip(src.toURI().toString());
  //    return lamp;
  //  }
  //
  //  private AudioClip illegal() {
  //    File src = new File("src/main/resources/illegal_lamp.mp3");
  //    AudioClip illegal = new AudioClip(src.toURI().toString());
  //    return illegal;
  //  }
}
