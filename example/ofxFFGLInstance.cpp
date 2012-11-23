/*
 *  ofxFFGLInstance.cpp
 *
 *  Created by Tobias Ebsen on 11/23/12.
 *
 */

#include "ofxFFGLInstance.h"

ofxFFGLInstance::ofxFFGLInstance(FFGLPlugin* plugin, DWORD instanceID) : ofxFFBaseInstance(plugin, instanceID) {
}

void ofxFFGLInstance::processFrame(ofTexture& texture) {
	
	ofTextureData texdata = texture.getTextureData();
	
	FFGLTextureStruct tex;
	tex.Width = texdata.width;
	tex.Height = texdata.height;
	tex.HardwareWidth = texdata.tex_w;
	tex.HardwareHeight = texdata.tex_h;
	tex.Handle = texture.getTextureData().textureID;
	
	FFGLTextureStruct* textures[] = {&tex};

	ProcessOpenGLStruct pogl;
	pogl.numInputTextures = 1;
	pogl.inputTextures = textures;
	pogl.HostFBO = 0;
	
	ofPushMatrix();

	ofScale(tex.Width / 2, tex.Height / 2);
	ofTranslate(1, 1);
		 
	((FFGLPlugin*)plugin)->processOpengl(&pogl, instanceID);
	
	ofPopMatrix();
}

void ofxFFGLInstance::processFrame(ofTexture& texture, ofFbo& fbo) {
	fbo.begin();
	processFrame(texture);
	fbo.end();
}