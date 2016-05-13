#include "Point.h"

#ifndef SHAPES_H
#define SHAPES_H

class Shape
{
public:
	virtual bool contains(const Point & p) const = 0;
	virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
	Point middle;
	double recWidth;
	double recHeight;
public:
	Rectangle(Point middle, double recWidth = 0, double recHeight = 0);

	bool contains(const Point & p) const;
};

class Square : public Rectangle
{
public: 
	Square(Point middle, double side);

};

class Ellipse : public Shape
{
	private:
		Point focal1;
		Point focal2;
		double radius;
	public:
		Ellipse(Point focal1, Point focal2, double radius);
			
		bool contains(const Point & p) const;
			
};


class Circle : public Ellipse
{
	public:
		double radius;
		Point center;
		
		Circle(Point center, double radius);
		
		bool contains(const Point & p) const;
		
};

#endif SHAPES _H
