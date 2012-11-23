/*
 *  FFGLPlugin.cpp
 *
 *  Created by Tobias Ebsen on 11/22/12.
 *
 */

#include "FFGLPlugin.h"

FFGLPlugin::FFGLPlugin(FF_Main_FuncPtr plugMain) : FFPlugin(plugMain) {
}

DWORD FFGLPlugin::processOpengl(ProcessOpenGLStruct* pProcessOpenGLStruct, DWORD instanceID) {
	return plugMain(FF_PROCESSOPENGL, (DWORD)pProcessOpenGLStruct, instanceID).ivalue;
}

DWORD FFGLPlugin::instantiateGL(FFGLViewportStruct* pFFGLViewportStruct) {
	return plugMain(FF_INSTANTIATEGL, (DWORD)pFFGLViewportStruct, 0).ivalue;
}

DWORD FFGLPlugin::deInstantiateGL(DWORD instanceID) {
	return plugMain(FF_DEINSTANTIATEGL, 0, instanceID).ivalue;
}

DWORD FFGLPlugin::setTime(double* Time, DWORD instanceID) {
	return plugMain(FF_SETTIME, (DWORD)Time, instanceID).ivalue;
}
