//Rectangle class
//Stores a rectangle as two points
//Upper left corner and lower right corner

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle {
public:
	//Storage
	Point upper, lower;
	
	//Reference ID, which calibration rectangle
	int id;

	//Creates a rectangle of size 0
	Rectangle() {
		upper.x = 0;
		upper.y = 0;
		lower.x = 0;
		lower.y = 0;
	}

	//Creates a rectangle from 2 points
	Rectangle(Point a, Point b) {
		upper = a;
		lower = b;
	}

	//Get size of rectangle
	int size() {
		return (lower.x - upper.x) * (lower.y - upper.y);
	}
};

#endif