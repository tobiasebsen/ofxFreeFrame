#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	host.listPluginFiles();
	host.loadAllPlugins();
		
	ofDisableArbTex();
	
	grabber.initGrabber(640, 480);
	//texture.allocate(320, 240, GL_RGB, false);
	fbo.allocate(grabber.getWidth(), grabber.getHeight());

	plugin = host.getPlugin("FFGLHeat");
	plugin->init();

	if (plugin->getCaps(FF_CAP_PROCESSOPENGL)) {
		instance = plugin->createGLInstance(grabber.getWidth(), grabber.getHeight());
	}
}

//--------------------------------------------------------------
void testApp::update(){

	grabber.update();

	if (grabber.isFrameNew()) {

		ofTexture tex = grabber.getTextureReference();
		instance->processFrame(tex, fbo);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	grabber.draw(0, 0, 320, 240);
	fbo.draw(320, 0, 320, 240);

	int nparam = plugin->getParameterCount();
	for (int p=0; p<nparam; p++) {
		ofDrawBitmapString(plugin->getParameterName(p), 10, 260 + p*20);
		ofDrawBitmapString(ofToString(instance->getParameter(p), 2), 220, 260 + p*20);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	instance->setParameter(0, x / 500.);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}