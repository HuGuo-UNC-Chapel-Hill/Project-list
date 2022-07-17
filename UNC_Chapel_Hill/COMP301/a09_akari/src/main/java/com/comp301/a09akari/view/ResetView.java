package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import javafx.event.ActionEvent;
import javafx.scene.Parent;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.control.Button;
// import javafx.scene.media.AudioClip;

import java.io.File;

public class ResetView implements FXComponent {
  private final AlternateMvcController controller;

  public ResetView(AlternateMvcController controller) {
    this.controller = controller;
  }

  @Override
  public Parent render() {
    HBox layout = new HBox();
    layout.getStyleClass().add("testColor");

    HBox spacel = new HBox();
    spacel.setMinWidth(30);
    layout.getChildren().add(spacel);

    Label reset = new Label("Reset Current Puzzle");
    reset.getStyleClass().add("lablePuzzle");
    reset.setMaxWidth(420);
    reset.setMinWidth(120);
    reset.setMaxHeight(30);
    HBox.setHgrow(reset, Priority.SOMETIMES);
    layout.getChildren().add(reset);

    Button resetPuzzle = new Button("Reset Puzzle");
    resetPuzzle.setMinHeight(30);
    resetPuzzle.setOnAction(
        (ActionEvent event) -> {
          controller.clickResetPuzzle();
          //          if (clip() != null) {
          //            clip().play();
          //          }
        });

    layout.getChildren().add(resetPuzzle);
    layout.setSpacing(8);
    return layout;
  }

  //  private AudioClip clip() {
  //    File src = new File("src/main/resources/Button_Click.mp3");
  //    AudioClip clip = new AudioClip(src.toURI().toString());
  //    return clip;
  //  }
}
