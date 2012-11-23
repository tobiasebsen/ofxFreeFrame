/*
 *  ofxFFBaseInstance.h
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#pragma once

#include "ofMain.h"
#include "FFPlugin.h"

class ofxFFBaseInstance {
public:
	
	float  getParameter(int index);
	string getParameterString(int index);
	void   setParameter(int index, float value);

protected:
	ofxFFBaseInstance(FFPlugin* plugin, DWORD instanceID);
	
	FFPlugin* plugin;
	DWORD instanceID;
};