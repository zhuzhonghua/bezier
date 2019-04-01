#include "stdafx.h"
#include "imageutil.h"

int ImageUtil::quadraticBezier(int p0, int p1, int p2, float t)
{
  float k = 1-t;
  // 二次贝塞尔曲线方程
  return k*k*p0+2*(1-t)*t*p1+t*t*p2;
}

void ImageUtil::drawBezier(SDL_Renderer* render, const Point& start, const Point& end, const Point& cp)
{
  std::vector<Point> points;
  
  for (float t=0;t<1;t+=0.01)
  {
    int x = quadraticBezier(start.x, cp.x, end.x, t);
    int y = quadraticBezier(start.y, cp.y, end.y, t);
    points.push_back(Point(x,y));
  }

  for (int i=0;i<points.size()-1;i++)
  {
    Point p1 = points[i];
    Point p2 = points[i+1];
    //thickLineRGBA(render, p1.x, p1.y, p2.x, p2.y, 1, 0, 0, 0, 255);
    aalineRGBA(render, p1.x, p1.y, p2.x, p2.y, 0, 0, 0, 255);
  }

  aalineRGBA(render, start.x, start.y, end.x, end.y, 0, 0, 0, 255);
}
