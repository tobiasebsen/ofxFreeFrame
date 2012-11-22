/*
 *  ofxFFPluginInstance.h
 *  freeframeExample
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofxFFPlugin.h"

class ofxFFPlugin;

class ofxFFPluginInstance {
public:
	ofxFFPluginInstance(FFPlugin* plugin, int instanceID);
	~ofxFFPluginInstance();

	void processFrame(ofPixelsRef pixels);
	void processFrameCopy(ofPixelsRef input, ofPixelsRef output);
	
	float  getParameter(int index);
	string getParameterString(int index);
	void   setParameter(int index, float value);
	
	void destroy();

private:
	FFPlugin* plugin;
	DWORD instanceID;
};