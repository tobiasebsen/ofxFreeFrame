/*
 *  ofxFFPluginInstance.cpp
 *  freeframeExample
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxFFPluginInstance.h"

ofxFFPluginInstance::ofxFFPluginInstance(FFPlugin* plugin, int instanceID) {
	this->plugin = plugin;
	this->instanceID = instanceID;
}

ofxFFPluginInstance::~ofxFFPluginInstance() {
	plugin->deInstantiate(instanceID);
}

void ofxFFPluginInstance::processFrame(ofPixels& pixels) {
	plugin->processFrame(pixels.getPixels(), instanceID);
}

void ofxFFPluginInstance::processFrameCopy(ofPixelsRef input, ofPixelsRef output) {
	void* in = input.getPixels();
	plugin->processFrameCopy(1, &in, output.getPixels(), instanceID);
}

float ofxFFPluginInstance::getParameter(int index) {
	return plugin->getParameter(index, instanceID);
}

string ofxFFPluginInstance::getParameterString(int index) {
	return plugin->getParameterDisplay(index, instanceID);
}

void ofxFFPluginInstance::setParameter(int index, float value) {
	plugin->setParameter(index, value, instanceID);
}

void ofxFFPluginInstance::destroy() {
	plugin->deInstantiate(instanceID);
}
