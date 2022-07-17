package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import com.comp301.a09akari.controller.ControllerImpl;
import com.comp301.a09akari.model.*;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.ArrayList;

public class AppLauncher extends Application {
  @Override
  public void start(Stage stage) {
    // TODO: Create your Model, View, and Controller instances and launch your GUI

    PuzzleLibrary library = InitialPuzzleLibrary.create();
    Model model = new ModelImpl(library);

    AlternateMvcController controller = new ControllerImpl(model);

    View view = new View(controller);

    Scene scene = new Scene(view.render(), 500, 500);
    scene.getStylesheets().add("main.css");
    stage.setScene(scene);

    model.addObserver(
        (Model m) -> {
          scene.setRoot(view.render());
          stage.sizeToScene();
          ;
        });

    stage.setTitle("Akari, COMP 301,  Hu Guo, PID: 730507803");
    stage.show();
  }
}
