#include "stdafx.h"
#include "game.h"
#include "util.h"
#include "imageutil.h"

Game::Game()
{
  _width = 960;
  _height = 640;

  _pStart = Point(100, 100);
  _pEnd = Point(200, 200);
  _pCp = Point(125, 150);
  
  _gameExit = false;
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  _window = SDL_CreateWindow( "Game Of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  _renderer = SDL_CreateRenderer(_window, -1, 0);


  _fpsLimiter.setMaxFPS(60.0f);  
}

void Game::run()
{
  SDL_StartTextInput();	
  while(_gameExit == false){
    _fpsLimiter.begin();

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
    
    _inputMgr.update();
    
    processInput();
    update();
    draw();
    
    SDL_RenderPresent(_renderer);
    
    _fps = _fpsLimiter.end();
  }
  SDL_StopTextInput();

  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void Game::draw()
{
  ImageUtil::drawBezier(_renderer, _pStart, _pEnd, _pCp);
  //  SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
  //thickLineRGBA(_renderer, _bStart.x, _bStart.y, _bEnd.x, _bEnd.y, 2, 0, 0, 0, 255);
}

void Game::update()
{
}

void Game::processInput()
{
  SDL_Event e;
  while(SDL_PollEvent(&e) != 0){
    switch(e.type){
    case SDL_QUIT:
      _gameExit = true;
      break;
    case SDL_MOUSEMOTION:
      _inputMgr.setMouseCoords(e.motion.x, e.motion.y);
      break;
    case SDL_KEYDOWN:
      _inputMgr.pressKey(e.key.keysym.sym);
      break;
    case SDL_KEYUP:
      _inputMgr.releaseKey(e.key.keysym.sym);
      break;
    case SDL_MOUSEBUTTONDOWN:
      _inputMgr.pressKey(e.button.button);
      break;
    case SDL_MOUSEBUTTONUP:
      _inputMgr.releaseKey(e.button.button);
      break;
    }
  }
}
