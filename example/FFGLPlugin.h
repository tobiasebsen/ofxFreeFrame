/*
 *  FFGLPlugin.h
 *
 *  Created by Tobias Ebsen on 11/22/12.
 *
 */

#include "FFPlugin.h"
#include "FFGL.h"

class FFGLPlugin : public FFPlugin {
public:
	FFGLPlugin(FF_Main_FuncPtr plugMain);
	
	DWORD processOpengl(ProcessOpenGLStruct* pProcessOpenGLStruct, DWORD instanceID);
	DWORD instantiateGL(FFGLViewportStruct* pFFGLViewportStruct);
	DWORD deInstantiateGL(DWORD instanceID);
	DWORD setTime(double* Time, DWORD instanceID);
};