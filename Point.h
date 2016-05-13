#include <cmath>
#include <iostream>
#ifndef POINT_H
#define POINT_H
using namespace std;

class Point {
private: 
	double width; 
	double height;
public:
	Point();
	Point(double width = 0.0, double height = 0.0);

	double getWidth() const;
	double getHeight() const;
	double distance(const Point & p) const;
};

#endif POINT_H

