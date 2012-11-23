/*
 *  ofxFFBaseInstance.cpp
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#include "ofxFFBaseInstance.h"

ofxFFBaseInstance::ofxFFBaseInstance(FFPlugin* plugin, DWORD instanceID) {
	this->plugin = plugin;
	this->instanceID = instanceID;
}

float ofxFFBaseInstance::getParameter(int index) {
	return plugin->getParameter(index, instanceID);
}

string ofxFFBaseInstance::getParameterString(int index) {
	return plugin->getParameterDisplay(index, instanceID);
}

void ofxFFBaseInstance::setParameter(int index, float value) {
	plugin->setParameter(index, value, instanceID);
}