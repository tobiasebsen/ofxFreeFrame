#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	grabber.initGrabber(320, 240);
	texture.allocate(320, 240, GL_RGB);

	plugin = ofxFFPlugin::load("/Library/Graphics/FreeFrame/FishEye.frf/Contents/MacOS/FishEye");
	
	plugin->init();

	if (plugin->getCaps(FF_CAP_24BITVIDEO)) {
		instance = plugin->createInstance(320, 240, FF_24BIT);
	}
}

//--------------------------------------------------------------
void testApp::update(){

	grabber.update();

	if (grabber.isFrameNew()) {

		ofPixelsRef pixels = grabber.getPixelsRef();
		instance->processFrame(pixels);
		texture.loadData(pixels.getPixels(), 320, 240, GL_RGB);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	grabber.draw(0, 0);
	texture.draw(320, 0);

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
	instance->setParameter(0, x / 1000.);
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