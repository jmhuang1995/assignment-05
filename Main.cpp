
#include <iostream>
#include <vector>
#include<chrono>
#include <thread>

#include "Point.h"
#include "Shape.h"

using std::endl;
using std::cout;
using std::vector;
using std::cin;

const double xSize = 80;
const double ySize = 25;

const double xScale = 1; 
const double yScale = 1.9;

void draw(const vector<Shape*> & v)
{
	for (double ypoint = 0; ypoint < ySize; ypoint++)
	{
		double y = ypoint * yScale;

		for (double xpoint = 0; xpoint < xSize; xpoint++)
		{
			double x = xpoint * xScale;

			if (ypoint == 0 || ypoint == ySize - 1)
			{
				cout << "-";
				continue;
			}

			if (xpoint == 0 || xpoint == xSize - 1)
			{
				cout << "|";
				continue;
			}

			bool includePoint = false;

			for (int c = 0; c < v.size(); c++)
			{
				if (v[c]->contains(Point(x, y))) {
					includePoint = true;
				}
			}
			if (includePoint)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}

int main()
{
	int frames = 50;
	int frameLength = 50;

	for (int i = 0; i < frames; i++)
	{
		Rectangle r(Point(5 + i, 5), 2, 8);
		Square    s(Point(50 - (i / 2), 5 + (i / 2)), 7);
		Ellipse   e(Point(10 - (i / 3), 35 + (i / 3)), Point(25 - (i / 3), 35 + (i / 3)), 22 + i);
		Circle    c(Point(50 + (i / 5), 35), 15);
		vector<Shape*> shapes = { &r, &s, &e, &c };

		draw(shapes);

		std::this_thread::sleep_for(std::chrono::milliseconds(frameLength));
	}

	cin.get();
	return 0;
}
