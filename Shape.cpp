
#include "Point.h"
#include "Shape.h"
 using std::abs;

Rectangle::Rectangle(Point middle, double recWidth, double recHeight)
 : middle(middle), recWidth(recWidth), recHeight(recHeight) {}


bool Rectangle::contains(const Point & p) const {
	return abs(p.getWidth() - middle.getWidth()) <= recWidth &&
		abs(p.getHeight() - middle.getHeight()) <= recHeight;
	
}


Square::Square(Point middle, double side) : Rectangle(middle, side / 2, side / 2) {}


Ellipse::Ellipse(Point focal1, Point focal2, double radius)
: focal1(focal1), focal2(focal2), radius(radius) {}

bool Ellipse::contains(const Point & p) const {
	if (focal1.distance(p) + focal2.distance(p) <= radius)
	{ return true;
	}
	else
	{ return true;
	}
	
}


Circle::Circle(Point center, double) : center(center), radius(radius) {}

bool Circle::contains(const Point & p) const 
{
	if (radius <= center.distance(p))
	{ return true;
	}
	else
	{ return false;
	}
	
}
