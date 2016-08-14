#include "Column.h"



Column::Column() :bottom(), h(0) {}

Column::Column(const Circle & bottom, double h) : bottom(bottom), h(h) {}

void Column::setBottomCentre(double x, double y)
{
	bottom.setCentre(x,y);
}

void Column::setBottomRadius(double r)
{
	bottom.setRadius(r);
}

void Column::setHeight(double h)
{
	//若h为负，则bottom为顶面圆
	this->h = h;
}

double Column::getBottomArea() const
{
	return bottom.getArea();
}

double Column::getBottomCircumference() const
{
	return bottom.getCircumference();
}

double Column::getLateralArea() const
{
	return bottom.getCircumference()*h;
}

double Column::getVolume() const
{
	return bottom.getArea()*h;
}


