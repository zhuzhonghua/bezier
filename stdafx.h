#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_gfxPrimitives.h>

#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <boost/random.hpp>

static inline void fatalError(std::string info)
{
  std::cout << info << std::endl;
  std::cout << "Enter Any Key To Exit" << std::endl;
  int tmp;
  std::cin >> tmp;
  SDL_Quit();
  exit(1);
}
