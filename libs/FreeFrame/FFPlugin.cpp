/*
 *  FFPlugin.cpp
 *  FreeFrame
 *
 *  Created by Tobias Ebsen on 11/20/12.
 *  Copyright 2012 Tobias Ebsen. All rights reserved.
 *
 */

#include "FFPlugin.h"

FFPlugin::FFPlugin(FF_Main_FuncPtr plugMain) {
	this->plugMain = plugMain;
}

PluginInfoStruct* FFPlugin::getInfo() {
	return plugMain(FF_GETINFO, 0, 0).PISvalue;
}

bool FFPlugin::initialize() {
	return plugMain(FF_INITIALISE, 0, 0).ivalue == FF_SUCCESS;
}

bool FFPlugin::deInitialize() {
	return plugMain(FF_DEINITIALISE, 0, 0).ivalue == FF_SUCCESS;
}

bool FFPlugin::processFrame(void* pFrame, DWORD instanceID) {
	return plugMain(FF_PROCESSFRAME, (DWORD)pFrame, instanceID).ivalue == FF_SUCCESS;
}

DWORD FFPlugin::getNumParameters() {
	return plugMain(FF_GETNUMPARAMETERS, 0, 0).ivalue;
}

char* FFPlugin::getParameterName(DWORD index) {
	return plugMain(FF_GETPARAMETERNAME, index, 0).svalue;
}

DWORD FFPlugin::getPluginCaps(DWORD capsIndex) {
	return plugMain(FF_GETPLUGINCAPS, capsIndex, 0).ivalue;
}

PluginExtendedInfoStruct* FFPlugin::getExtendedInfo() {
	return (PluginExtendedInfoStruct*)plugMain(FF_GETEXTENDEDINFO, 0, 0).PISvalue;
}

char* FFPlugin::getParameterDisplay(DWORD index, DWORD instanceID) {
	return plugMain(FF_GETPARAMETERDISPLAY, index, instanceID).svalue;
}

bool FFPlugin::setParameter(DWORD index, float value, DWORD instanceID) {
	SetParameterStruct setParam;
	setParam.ParameterNumber = index;
	memcpy(&setParam.NewParameterValue, &value, 4);
	return plugMain(FF_SETPARAMETER, (DWORD)&setParam, instanceID).ivalue == FF_SUCCESS;
}

float FFPlugin::getParameter(DWORD index, DWORD instanceID) {
	return plugMain(FF_GETPARAMETER, index, instanceID).fvalue;
}

DWORD FFPlugin::instantiate(VideoInfoStruct* videoInfo) {
	return plugMain(FF_INSTANTIATE, (DWORD)videoInfo, 0).ivalue;
}

bool FFPlugin::deInstantiate(DWORD instanceID) {
	return plugMain(FF_DEINSTANTIATE, 0, instanceID).ivalue == FF_SUCCESS;
}

bool FFPlugin::processFrameCopy(DWORD numInputFrames, void** ppInputFrames, void* pOutputFrame, DWORD instanceID) {
	ProcessFrameCopyStruct copyStruct;
	copyStruct.numInputFrames = numInputFrames;
	copyStruct.ppInputFrames = ppInputFrames;
	copyStruct.pOutputFrame = pOutputFrame;
	return plugMain(FF_PROCESSFRAMECOPY, (DWORD)&copyStruct, instanceID).ivalue == FF_SUCCESS;
}