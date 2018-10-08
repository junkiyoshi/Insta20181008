#include "Hexagon.h"

Hexagon::Hexagon() : Hexagon(ofPoint(), 0, ofColor()) {}

Hexagon::Hexagon(ofPoint location, float radius, ofColor color) {

	this->location = location;
	this->radius = radius;
	this->height = radius * sqrt(3);
	this->color = color;
}

void Hexagon::Update() {

	if (ofGetFrameNum() % 5 == 0) {
		
		int r = ofRandom(6);
		int deg = r * 60 + 30;

		int try_count = 0;
		ofPoint tmp_location;
		while (true) {

			tmp_location = this->location + ofPoint(this->height * cos(deg * DEG_TO_RAD), this->height * sin(deg * DEG_TO_RAD));
			if (tmp_location.x > 0 && tmp_location.x < ofGetWidth() && tmp_location.y > 0 && tmp_location.y < ofGetHeight()) { break; }

			deg += 60;
			if (++try_count > 6) { 
				
				tmp_location = this->location; 
				break;
			}
		}
		this->location = tmp_location;
		this->logs.push_front(this->location);
	}

	while (this->logs.size() > 6) { this->logs.pop_back(); }
}

void Hexagon::Draw() {

	float tmp_radius = this->radius;
	ofSetColor(this->color);

	for (ofPoint& log : this->logs) {

		ofPushMatrix();
		ofTranslate(log);

		ofBeginShape();
		for (int deg = 0; deg < 360; deg += 60) {

			ofVertex(tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD));
		}
		ofEndShape(true);

		ofPopMatrix();

		tmp_radius *= 0.9;
	}
}