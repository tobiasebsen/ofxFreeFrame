/*
 *  ofxFFHost.h
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#pragma once

#include "ofxFFPlugin.h"

class ofxFFHost {
public:
	
	ofxFFHost();
	
	vector<ofFile> listPluginFiles();
	ofxFFPlugin* loadPlugin(ofFile file);
	void loadAllPlugins();
	
	ofxFFPlugin* getPlugin(string name);
	
	vector<ofDirectory> pluginDirectories;
	vector<ofFile> pluginFiles;
	vector<ofxFFPlugin*> loadedPlugins;

private:
	
};