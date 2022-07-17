package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import javafx.scene.Parent;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.media.AudioClip;
import java.io.File;

public class Test implements FXComponent {
  private final AlternateMvcController controller;

  public Test(AlternateMvcController controller1) {
    this.controller = controller1;
  }

  private AudioClip clip() {
    File src = new File("src/main/resources/Button_Click.mp3");
    AudioClip clip = new AudioClip(src.toURI().toString());
    return clip;
  }

  @Override
  public Parent render() {

    HBox layout = new HBox();
    HBox hbox = new HBox();
    Button button1 = new Button("Add");
    button1.setOnAction(
        (event) -> {
          if (clip() != null) {
            clip().play();
          }
        });
    Button button2 = new Button("Remove");
    HBox.setHgrow(button1, Priority.ALWAYS);
    HBox.setHgrow(button2, Priority.ALWAYS);
    button1.setMaxWidth(200);
    button2.setMaxWidth(Double.MAX_VALUE);
    hbox.getChildren().addAll(button1, button2);
    return hbox;
  }
}
