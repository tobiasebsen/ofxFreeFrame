/*
 *  ofxFFPlugin.cpp
 *  freeframeExample
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#include "ofxFFPlugin.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <dlfcn.h>

ofxFFPlugin* ofxFFPlugin::load(string filename) {
	
	struct stat st;
	if(stat(filename.c_str(), &st) != 0)
		return NULL;
	
	if (st.st_mode & S_IFDIR) {
		// Not a file, but a directory
	}

	void* handle = dlopen(filename.c_str(), RTLD_LAZY);
	if (!handle)
		return NULL;
	
	void* symbol = dlsym(handle, "plugMain");
	if (!symbol)
		return NULL;
	
	FF_Main_FuncPtr plugMain = (FF_Main_FuncPtr)symbol;
	
	FFPlugin* ffplug = new FFPlugin(plugMain);
	ofxFFPlugin* plugin = new ofxFFPlugin();
	plugin->handle = handle;
	plugin->plugin = ffplug;
	
	return plugin;
}

string ofxFFPlugin::getName() {
	PluginInfoStruct *info = plugin->getInfo();
	return (char*)info->PluginName;
}

string ofxFFPlugin::getDescription() {
	PluginExtendedInfoStruct *exinfo = plugin->getExtendedInfo();
	return (char*)exinfo->Description;
}

string ofxFFPlugin::getAbout() {
	PluginExtendedInfoStruct *exinfo = plugin->getExtendedInfo();
	return (char*)exinfo->About;
}

void ofxFFPlugin::init() {
	plugin->initialize();
}

int ofxFFPlugin::getParameterCount() {
	return plugin->getNumParameters();
}

string ofxFFPlugin::getParameterName(int index) {
	return plugin->getParameterName(index);
}

int ofxFFPlugin::getCaps(int capsIndex) {
	return plugin->getPluginCaps(capsIndex);
}

ofxFFPluginInstance* ofxFFPlugin::createInstance(int width, int height, ffBitDepth bitDepth, ffOrientation orientation) {
	VideoInfoStruct videoInfo;
	videoInfo.FrameWidth = width;
	videoInfo.FrameHeight = height;
	videoInfo.BitDepth = bitDepth;
	videoInfo.Orientation = orientation;
	int instanceID = plugin->instantiate(&videoInfo);
	if (instanceID == FF_FAIL)
		return NULL;
	return new ofxFFPluginInstance(plugin, instanceID);
}