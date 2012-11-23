/*
 *  ofxFFHost.cpp
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#include "ofxFFHost.h"

ofxFFHost::ofxFFHost() {
	pluginDirectories.push_back(ofDirectory("/Library/Graphics/FreeFrame"));
	pluginDirectories.push_back(ofDirectory("/Library/Application Support/FreeFrame"));
}

vector<ofFile> ofxFFHost::listPluginFiles() {
	
	for (int d=0; d<pluginDirectories.size(); d++) {
	
		pluginDirectories[d].listDir();
		vector<ofFile> files = pluginDirectories[d].getFiles();
		for (int n=0; n<files.size(); n++) {
			bool exists = false;
			for (int f=0; f<pluginFiles.size(); f++) {
				if(pluginFiles[f].getFileName() == files[n].getFileName())
				   exists = true;
			}
			if (!exists) {
				pluginFiles.push_back(files[n]);
			}
		}
	}
	
	return pluginFiles;
}

ofxFFPlugin* ofxFFHost::loadPlugin(ofFile file) {
		
	ofxFFPlugin* plugin = ofxFFPlugin::load(file);
	
	if (plugin != NULL)
		loadedPlugins.push_back(plugin);
	
	return plugin;
}

void ofxFFHost::loadAllPlugins() {

	for (int i=0; i<pluginFiles.size(); i++) {
		loadPlugin(pluginFiles[i]);
	}
}

ofxFFPlugin* ofxFFHost::getPlugin(string name) {
	
	for (int i=0; i<loadedPlugins.size(); i++) {
		if (loadedPlugins[i]->getName() == name) {
			return loadedPlugins[i];
		}
	}
	return NULL;
}