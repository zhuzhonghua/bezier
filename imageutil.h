#pragma once
#include "util.h"

class ImageUtil{
private:
  static int quadraticBezier(int p0, int p1, int p2, float t);
public:
  static void drawBezier(SDL_Renderer* render, const Point& start, const Point& end, const Point& cp);
};
