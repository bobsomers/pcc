#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <pcc/pcc.h>
#include <nanogui/nanogui.h>

namespace ng = nanogui;

class CurvizApp : public ng::Screen {
public:
  CurvizApp()
    : ng::Screen(ng::Vector2i(1280, 720), "Piecewise Clothoid Curve Visualizer") {
    ng::Window* window = new ng::Window(this, "My Window");
    window->setPosition(ng::Vector2i(15, 15));
    window->setLayout(new ng::GroupLayout());

    new ng::Label(window, "My Button", "sans-bold");

    ng::Button* button = new ng::Button(window, "The Button");
    button->setCallback([] { pcc::sayHello(); });
    button->setTooltip("Push me!");

    performLayout();
  }

  virtual bool keyboardEvent(int key, int scancode, int action, int modifiers) override {
    if (ng::Screen::keyboardEvent(key, scancode, action, modifiers)) {
      return true;
    }
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
      setVisible(false);
      return true;
    }
    return false;
  }
};

int main(int argc, char* argv[]) {
  try {
    nanogui::init();

    {
      ng::ref<CurvizApp> app = new CurvizApp();
      app->drawAll();
      app->setVisible(true);
      ng::mainloop();
    }

    nanogui::shutdown();
  } catch (const std::runtime_error& e) {
    std::cerr << "Runtime Error: " << e.what() << "\n";
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
