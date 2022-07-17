package com.comp301.a09akari.view;

import com.comp301.a09akari.controller.AlternateMvcController;
import javafx.scene.Parent;
import javafx.scene.layout.VBox;

public class View implements FXComponent {
  private final AlternateMvcController controller;

  public View(AlternateMvcController controller) {
    this.controller = controller;
  }

  @Override
  public Parent render() {
    VBox layout = new VBox();
    layout.getStyleClass().add("layout");

    ControlsView controlsView = new ControlsView(controller);
    layout.getChildren().add(controlsView.render());

    BoardView boardView = new BoardView(controller);
    layout.getChildren().add(boardView.render());

    ResetView resetView = new ResetView(controller);
    layout.getChildren().add(resetView.render());

    return layout;
  }
}
