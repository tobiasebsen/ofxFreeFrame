/*
 *  ofxFFInstance.h
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *
 */

#pragma once

#include "ofxFFBaseInstance.h"

class ofxFFInstance : public ofxFFBaseInstance {
public:
	ofxFFInstance(FFPlugin* plugin, DWORD instanceID);
	
	void processFrame(ofPixelsRef pixels);
	void processFrameCopy(ofPixelsRef input, ofPixelsRef output);
};