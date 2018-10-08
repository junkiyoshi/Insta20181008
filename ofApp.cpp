#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofNoFill();
	ofSetLineWidth(2);

	for (int i = 0; i < 10; i++) {

		ofColor color;
		color.setHsb(i * 25, 200, 255);

		Hexagon hexagon = Hexagon(ofPoint(ofGetWidth() * 0.5, ofGetHeight() * 0.5), 28, color);
		this->hexagons.push_back(hexagon);
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (Hexagon& hexagon : this->hexagons) {
	
		hexagon.Update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (Hexagon& hexagon : this->hexagons) {

		hexagon.Draw();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}