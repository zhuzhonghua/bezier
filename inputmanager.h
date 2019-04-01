#pragma once

#include <unordered_map>
#include "util.h"

class InputManager{
public:
  InputManager();

  void update();

  void pressKey(unsigned int key);
  void releaseKey(unsigned int key);

  bool isKeyDown(unsigned int key);
  bool isKeyPressed(unsigned int key);

  void setMouseCoords(float x, float y);

  Point getMouseCoords() const { return _mouseCoords; }
private:
  bool wasKeyDown(unsigned int key);

  std::unordered_map<unsigned int, bool> _keys;
  std::unordered_map<unsigned int, bool> _previousKeys;

  Point _mouseCoords;
};
