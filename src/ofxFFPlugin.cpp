/*
 *  ofxFFPlugin.cpp
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *
 */

#include "ofxFFPlugin.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <dlfcn.h>

ofxFFPlugin* ofxFFPlugin::load(ofFile file) {
	
	if (file.isDirectory()) {
		file = ofFile(file.getAbsolutePath() + "/Contents/MacOS/" + file.getBaseName());
	}
	
	string filename = file.getAbsolutePath();

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
	
	FFGLPlugin* ffplug = new FFGLPlugin(plugMain);
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

ofxFFInstance* ofxFFPlugin::createInstance(int width, int height, ffBitDepth bitDepth, ffOrientation orientation) {
	VideoInfoStruct videoInfo;
	videoInfo.FrameWidth = width;
	videoInfo.FrameHeight = height;
	videoInfo.BitDepth = bitDepth;
	videoInfo.Orientation = orientation;
	int instanceID = plugin->instantiate(&videoInfo);
	if (instanceID == FF_FAIL)
		return NULL;
	return new ofxFFInstance(plugin, instanceID);
}

ofxFFGLInstance* ofxFFPlugin::createGLInstance(int width, int height, int x, int y) {
	FFGLViewportStruct viewport;
	viewport.x = x;
	viewport.y = y;
	viewport.width = width;
	viewport.height = height;
	DWORD instanceID = plugin->instantiateGL(&viewport);
	return new ofxFFGLInstance(plugin, instanceID);
}