#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int cameraToUse;
    cameraToUse = 0;
    
    int vendorId, productId, interfaceNum;

    
    vendorId = 0x046d;
    productId = 0x82d;
    interfaceNum = 0x03;
    cameraName = "HD Pro Webcam C920";
    camWidth = 1280;
    camHeight = 720;
    
    int deviceId = 0;
    vector<ofVideoDevice> availableCams = vidGrabber.listDevices();

    for(int i = 0; i < availableCams.size(); i++){
        if(availableCams[i].deviceName == cameraName){
            deviceId = i;
        }
    }
    
    vidGrabber.setDeviceID(deviceId);
    vidGrabber.initGrabber(camWidth, camHeight);
    tex.allocate(vidGrabber.getPixels());
    
    focus = 0.5;
    exposure = 0.5;
    
    uvcControl.useCamera(vendorId, productId, interfaceNum); 
    uvcControl.setAutoExposure(false);
    uvcControl.setAutoFocus(false);
    uvcControl.setAbsoluteFocus(focus);
    uvcControl.setExposure(exposure);
    controls = uvcControl.getCameraControls();
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew())
    {
        tex.loadData(vidGrabber.getPixels());
    }
    controls = uvcControl.getCameraControls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    tex.draw(0,0, camWidth, camHeight);

    ofSetColor(255, 0, 100);
    stringstream s;
    s << "Camera name: " << cameraName << "\nAuto-exposure: " << uvcControl.getAutoExposure() << "\nAuto-focus: " << uvcControl.getAutoFocus() <<
    "\nAbsolute focus: " << uvcControl.getAbsoluteFocus() << "\nAbsolute exposure: " << uvcControl.getExposure() <<
    "\nPress 'e' to toggle auto-exposure.\nPress 'f' to toggle auto-focus.\nPress +/- to set absolute focus.\n\nResult of GET_STATUS for each feature\non this camera:\n";
        
    
    for(int i = 0; i < controls.size(); i++){
    
        s << controls.at(i).name << ": " << controls.at(i).status << "\n";

    }
    
    
    ofDrawBitmapString(s.str(), ofGetWidth()-350, 10);
    
    ofSetColor(255);

}

void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'e'){
        uvcControl.setAutoExposure(!uvcControl.getAutoExposure());
    }
    
    if(key == 'f'){
        uvcControl.setAutoFocus(!uvcControl.getAutoFocus());
    }
    
    if(key == '+'){
        focus += 0.01;
        if(focus>1){focus=1;}
        uvcControl.setAbsoluteFocus(focus);
    }
    
    if(key == '-'){
        focus -= 0.01;
        if(focus<0){focus=0;}
        uvcControl.setAbsoluteFocus(focus);

    }
    
    if(key == 'p'){
        exposure += 0.01;
        if(exposure>1){exposure=1;}
        uvcControl.setExposure(exposure);
    }
    
    if(key == 'm'){
        exposure -= 0.01;
        if(exposure<0){exposure=0;}
        uvcControl.setExposure(exposure);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
