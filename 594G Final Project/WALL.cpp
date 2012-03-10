#include "WALL.h"

#define thickness 0.02

///////////////////////////////////////////////////////////////////////////////
// Constructor
///////////////////////////////////////////////////////////////////////////////
WALL::WALL(const VEC3F& normal, const VEC3F& point) :
  _normal(normal), _point(point)
{
  // just in case, normalize the normal vector
  _normal.normalize();
}

///////////////////////////////////////////////////////////////////////////////
// OGL drawing
///////////////////////////////////////////////////////////////////////////////
void WALL::draw() 
{
  glPushMatrix();
    // translate to the point
    glTranslatef(_point[0], _point[1], _point[2]);
    
    // apply a rotation
    float angle1 = asin(_normal[0]) / (2 * M_PI) * 360.0;
  float angle2 = asin(_normal[1]) / (2 * M_PI) * 360.0;
  float angle3 = asin(_normal[2]) / (2 * M_PI) * 360.0;

  
    glRotatef(-angle1, 0, 1, 0);
  //cout << "1: " << angle1 << " 2: " << angle2 << " 3: " << angle3 << endl;
  glRotatef(-angle2, 1, 0, 0);

    // make it a plane at 0,0
    glTranslatef(0, 0, thickness/2.0);
    glScalef(20,20,1);
    glutSolidCube(thickness);
  
    
  glPopMatrix();
}
