#include "stdafx.h"
#include "util.h"

SimpleRand::SimpleRand(int min, int max)
  :_rndInt(min, max)
{
}

int SimpleRand::getIntRnd()
{
  return _rndInt(_randEngine);
}

Point::Point(int x, int y)
{
  this->x = x;
  this->y = y;
}
