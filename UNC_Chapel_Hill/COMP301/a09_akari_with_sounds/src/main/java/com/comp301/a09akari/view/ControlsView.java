package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import javafx.event.ActionEvent;
import javafx.scene.Parent;
import javafx.scene.layout.HBox;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.layout.Priority;
import javafx.scene.layout.VBox;
import javafx.scene.media.AudioClip;

import java.io.File;

public class ControlsView implements FXComponent {
  private final AlternateMvcController controller;

  public ControlsView(AlternateMvcController controller1) {
    this.controller = controller1;
  }

  @Override
  public Parent render() {
    VBox show = new VBox();

    HBox layout = new HBox();
    layout.getStyleClass().add("testColor");

    HBox spacel = new HBox();
    spacel.setMinWidth(10);
    layout.getChildren().add(spacel);

    Label switchPuzzle = new Label("Switch Puzzle");
    switchPuzzle.getStyleClass().add("lablePuzzle");
    switchPuzzle.setMaxWidth(220);
    switchPuzzle.setMinWidth(120);
    switchPuzzle.setMaxHeight(30);
    HBox.setHgrow(switchPuzzle, Priority.SOMETIMES);
    layout.getChildren().add(switchPuzzle);

    Button prePuzzle = new Button("\u23EA");
    prePuzzle.setOnAction(
        (ActionEvent event) -> {
          controller.clickPrevPuzzle();
          if (clip() != null) {
            clip().play();
          }
        });
    prePuzzle.setMinWidth(35);
    prePuzzle.setMinHeight(30);
    layout.getChildren().add(prePuzzle);

    Button nextPuzzle = new Button("\u23E9");
    nextPuzzle.setOnAction(
        (ActionEvent event) -> {
          controller.clickNextPuzzle();
          if (clip() != null) {
            clip().play();
          }
        });
    nextPuzzle.setMinWidth(35);
    nextPuzzle.setMinHeight(30);
    layout.getChildren().add(nextPuzzle);

    HBox spacec = new HBox();
    spacec.setMinWidth(5);
    layout.getChildren().add(spacec);

    Label randPuzzle = new Label("Get a Random Puzzle");
    randPuzzle.getStyleClass().add("lablePuzzle");
    randPuzzle.setMaxWidth(320);
    randPuzzle.setMaxHeight(30);
    HBox.setHgrow(randPuzzle, Priority.ALWAYS);
    layout.getChildren().add(randPuzzle);

    Button randButton = new Button("Random");
    randButton.setOnAction(
        (ActionEvent event) -> {
          controller.clickRandPuzzle();
          if (clip() != null) {
            clip().play();
          }
        });
    randButton.setMinHeight(30);
    layout.getChildren().add(randButton);

    HBox spacer = new HBox();
    spacer.setMinWidth(10);
    layout.getChildren().add(spacer);
    layout.setSpacing(5);

    HBox message = new HBox();
    message.getStyleClass().add("testColor");

    Label totalPuzzle = new Label("Total Puzzles: " + this.controller.returnSize());
    totalPuzzle.getStyleClass().add("message");
    totalPuzzle.setMaxWidth(320);
    HBox.setHgrow(totalPuzzle, Priority.ALWAYS);
    message.getChildren().add(totalPuzzle);

    Label index = new Label("Current Puzzle: No." + this.controller.returnIndex());
    index.setMaxWidth(320);
    HBox.setHgrow(index, Priority.ALWAYS);
    index.getStyleClass().add("message");
    message.getChildren().add(index);

    VBox textArea = new VBox();
    textArea.setMinHeight(35);
    message.getChildren().add(textArea);

    if (this.controller.isSolved()) {
      Label solved = new Label("Solved!!!");
      solved.getStyleClass().add("tile-solved");
      textArea.getChildren().add(solved);
      if (solved() != null) {
        solved().play();
      }
    }
    if (!this.controller.isSolved()) {
      Label solved = new Label("Unsolved!!!");
      solved.getStyleClass().add("message");
      textArea.getChildren().add(solved);
    }
    message.setSpacing(25);

    HBox spaceu = new HBox();
    spaceu.getStyleClass().add("space");
    spaceu.setMinHeight(5);
    layout.getChildren().add(spaceu);

    HBox space = new HBox();
    space.getStyleClass().add("layout");
    space.setMinHeight(10);
    layout.getChildren().add(space);

    show.getChildren().add(layout);
    show.getChildren().add(spaceu);
    show.getChildren().add(message);
    show.getChildren().add(space);
    return show;
  }

  private AudioClip clip() {
    File src = new File("src/main/resources/Button_Click.mp3");
    AudioClip clip = new AudioClip(src.toURI().toString());
    return clip;
  }

  private AudioClip solved() {
    File src = new File("src/main/resources/complete_success.mp3");
    AudioClip solved = new AudioClip(src.toURI().toString());
    return solved;
  }
}
