/*
 *  ofxFFPlugin.h
 *  freeframeExample
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"
#include "FFPlugin.h"
#include "ofxFFPluginInstance.h"

typedef enum ffBitDepth {
	FF_16BIT, FF_24BIT, FF_32BIT
};

typedef enum ffOrientation {
	FF_TOP_LEFT = 1,
	FF_BOTTOM_LEFT = 2
};

class ofxFFPluginInstance;

class ofxFFPlugin {
public:
	static ofxFFPlugin* load(string file);
	
	int    getType();
	string getName();
	string getDescription();
	string getAbout();
	
	void init();
	void destroy();
	
	int    getParameterCount();
	string getParameterName(int index);
	int    getParameterType(int index);
	
	int getCaps(int capsIndex);
	
	ofxFFPluginInstance* createInstance(int width, int height, ffBitDepth bitDepth = FF_24BIT, ffOrientation orientation = FF_TOP_LEFT);

protected:
	void* handle;
	FFPlugin* plugin;
};
