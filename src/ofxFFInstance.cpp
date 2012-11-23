/*
 *  ofxFFInstance.cpp
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *
 */

#include "ofxFFInstance.h"

/*ofxFFInstance::ofxFFInstance(FFGLPlugin* plugin, int instanceID) {
	this->plugin = plugin;
	this->instanceID = instanceID;
}*/

void ofxFFInstance::processFrame(ofPixels& pixels) {
	plugin->processFrame(pixels.getPixels(), instanceID);
}

void ofxFFInstance::processFrameCopy(ofPixelsRef input, ofPixelsRef output) {
	void* in = input.getPixels();
	plugin->processFrameCopy(1, &in, output.getPixels(), instanceID);
}
