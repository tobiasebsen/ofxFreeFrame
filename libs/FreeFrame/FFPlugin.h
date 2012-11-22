/*
 *  FFPlugin.h
 *  FreeFrame
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#ifndef FFPLUGIN_H
#define FFPLUGIN_H

#include "FreeFrame.h"

class FFPlugin {
public:
	FFPlugin(FF_Main_FuncPtr plugMain);
	~FFPlugin();
	
	PluginInfoStruct* getInfo();
	bool initialize();
	bool deInitialize();
	bool processFrame(void* pFrame, DWORD instanceID);
	DWORD getNumParameters();
	char* getParameterName(DWORD index);
	DWORD getPluginCaps(DWORD capsIndex);
	PluginExtendedInfoStruct* getExtendedInfo();
	
	char* getParameterDisplay(DWORD index, DWORD instanceID);
	bool setParameter(DWORD index, float value, DWORD instanceID);
	float getParameter(DWORD index, DWORD instanceID);
	DWORD instantiate(VideoInfoStruct* videoInfo);
	bool deInstantiate(DWORD instanceID);
	bool processFrameCopy(DWORD numInputFrames, void** ppInputFrames, void* pOutputFrame, DWORD instanceID);
	
private:
	FF_Main_FuncPtr plugMain;
};

#endif