#include "ofApp.h"

ofSerial mySerial;
bool isValid = false;
int value;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    mySerial.setup("/dev/cu.usbmodem1421",9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    isValid = false;
    if (mySerial.available() >= 3) {
        int head = mySerial.readByte();
        if (head == 128){
            int high = mySerial.readByte();
            int low = mySerial.readByte();
            value = (high<<7) + low;
            if (0 <= value && value <= 1023){
                printf("value is %d \n", value);
                isValid = true;
            }
        }
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
