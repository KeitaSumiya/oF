#include "ofApp.h"

ofSerial mySerial;
unsigned char myByte = 0;
int a = +1;
float theta;
int x;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(false);
    ofSetFrameRate(0);

    mySerial.setup("/dev/cu.usbmodem1421",9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    myByte += 1;
    if (myByte > 255){
        myByte = 0;
    }
    theta = 2*PI*(float)myByte/255;
    //printf("%f \n", theta);
    x = 90*(cos(theta)+1);
    printf("%d \n", x);
//    sin(theta);
}

//--------------------------------------------------------------
void ofApp::draw(){
    bool byteWasWritten = mySerial.writeByte(x);
    if ( !byteWasWritten )
        printf("byte was not written to serial port");
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
