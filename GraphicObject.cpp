#include "GraphicObject.h"
GraphicObject::GraphicObject()
{
	position = vec3(0, 0, 0);
	angle = 0;
	color = vec3(0, 0, 0);
}
void GraphicObject::setPosition(vec3 position)
{
	this->position = position;

}
vec3 GraphicObject::getPosition()
{
	return position;
}
void GraphicObject::setAngle(float grad)
{
	this->angle = grad;
}
float GraphicObject::getAngle()
{
	return angle;
}
void GraphicObject::setСolor(vec3 color)
{
	this->color = color;
}
vec3 GraphicObject::getColor()
{
	return color;
}
// расчет матрицы modelMatrix на основе position и angle
void GraphicObject::recalculateModelMatrix()
{
	float angRad = radians(angle);
	modelMatrix[0] = cos(angRad)*4;
	modelMatrix[5] = 2;
	modelMatrix[2] = -sin(angRad)*4;
	modelMatrix[8] = sin(angRad)*4;
	modelMatrix[10] = cos(angRad)*4;

	modelMatrix[12] = position.x;
	modelMatrix[13] = position.y;
	modelMatrix[14] = position.z;
}
// вывести объект
void GraphicObject::draw()
{
	glColor3f(color.r, color.g, color.b);
	glPushMatrix();
	recalculateModelMatrix();
	glMultMatrixf(modelMatrix);
	glutWireTeapot(1.0);
	glPopMatrix();

}