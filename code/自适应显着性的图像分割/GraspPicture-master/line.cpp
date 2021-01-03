#include "line.h"
using namespace std;
using namespace cv;

Line::Line()
{
  corner = true;
}

Line::Line(Point2d pos1, Point2d pos2)
{
  //find starting point of line
  startPoint.x = pos1.x;
  startPoint.y = pos1.y;

  //calculate magnitude of line
  mag = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));

  //find unit vector for direction
  uVec.x = (pos2.x - pos1.x) / mag;
  uVec.y = (pos2.y - pos1.y) / mag;

  corner = false;

}

//following returns the perpendicular unit vector of the line
Point2d Line::getPerpendicular()
{
  //!!!Need to consider direction of new vector
  Point2d perpUVect;
  perpUVect.x = uVec.y;
  perpUVect.y = uVec.x * (-1);

  return perpUVect;
}

// Following finds the angle between two unit vectors
double Line::getAngleWith(double l1[2])
{
  return cos(l1[0] * uVec.x + l1[1] * uVec.y);
}
