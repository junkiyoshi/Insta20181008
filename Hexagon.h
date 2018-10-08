#pragma once
#include "ofMain.h"

class Hexagon {
public:
	Hexagon();
	Hexagon(ofPoint location, float radius, ofColor color);

	void Update();
	void Draw();

private:

	ofPoint location;
	std::deque<ofPoint> logs;
	float radius;
	float height;
	ofColor color;
};