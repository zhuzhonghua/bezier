#pragma once

#include "timing.h"
#include "inputmanager.h"

class Game{
public:
  Game();
  void init();
  void run();

protected:
  void update();
  void draw();
  void processInput();

protected:
  bool _gameExit;
  FPSLimiter _fpsLimiter;

  float _fps;
protected:
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  InputManager _inputMgr;

protected:
  int _width;
  int _height;

  Point _pStart;
  Point _pEnd;
  Point _pCp;
};
