#include "ofApp.h"

ofSerial mySerial;
int value = 963;
bool isValid = false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    mySerial.setup("/dev/cu.usbmodem1421",9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    isValid = false;
    int head = 128;
    int high = (value >> 7) & 127;
    int low  = value & 127;
    bool byteWasWritten1 = mySerial.writeByte(head);
    bool byteWasWritten2 = mySerial.writeByte(high);
    bool byteWasWritten3 = mySerial.writeByte(low);
    if ( byteWasWritten1 && byteWasWritten2 && byteWasWritten3 ) {
        isValid = true;
        printf("write value %d \n", value);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if ( !isValid ) {
        printf("an error occurred \n");
    }
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
