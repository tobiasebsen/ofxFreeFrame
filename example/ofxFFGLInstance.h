/*
 *  ofxFFGLInstance.h
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#pragma once

#include "ofxFFPlugin.h"
#include "ofxFFBaseInstance.h"

class ofxFFGLInstance : public ofxFFBaseInstance {
public:
	ofxFFGLInstance(FFGLPlugin* plugin, DWORD instanceID);
	
	void processFrame(ofTexture& texture);
	void processFrame(ofTexture& texture, ofFbo& fbo);
};