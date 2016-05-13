#include "Point.h"

Point::Point() {


}

Point::Point(double width, double height) : width(width), height(height){}

double Point::getWidth() const
{
	return width;
}
double Point::getHeight() const
{
	return height;
}
double Point::distance(const Point & p) const
{
	return sqrt((width - p.width)*(width - p.width) + (height - p.height)*(height - p.height));

}
