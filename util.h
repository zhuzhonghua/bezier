#pragma once

class SimpleRand{
public:
  SimpleRand(int min, int max);

  int getIntRnd();
protected:
  boost::random::mt19937 _randEngine;
  boost::random::uniform_int_distribution<> _rndInt;
};

class Point{
public:
  Point(){}
  Point(int x, int y);
  Point(const Point& p) { x = p.x, y=p.y; }
  
  int x;
  int y;
};
