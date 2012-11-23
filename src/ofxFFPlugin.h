/*
 *  ofxFFPlugin.h
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *
 */

#pragma once

#include "ofMain.h"
#include "FFGLPlugin.h"
#include "ofxFFInstance.h"
#include "ofxFFGLInstance.h"

typedef enum ffBitDepth {
	FF_16BIT, FF_24BIT, FF_32BIT
};

typedef enum ffOrientation {
	FF_TOP_LEFT = 1,
	FF_BOTTOM_LEFT = 2
};

class ofxFFInstance;
class ofxFFGLInstance;

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
	
	ofxFFInstance* createInstance(int width, int height, ffBitDepth bitDepth = FF_24BIT, ffOrientation orientation = FF_TOP_LEFT);
	ofxFFGLInstance* createGLInstance(int width, int height, int x = 0, int y = 0);

protected:
	void* handle;
	FFGLPlugin* plugin;
};
