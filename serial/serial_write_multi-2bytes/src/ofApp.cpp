#include "ofApp.h"

ofSerial mySerial;
const int val_size = 3;
int values[val_size] = {123, 456, 789};
bool isValids[val_size] = {false, false, false};

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(120);
    mySerial.setup("/dev/cu.usbmodem1421",9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    bool isValids[val_size] = {false, false, false};
    for (int i=0; i<val_size; i++){
        int high = (values[i] >> 7) & 127;
        int low  = values[i] & 127;
        bool byteWasWritten1 = mySerial.writeByte(128+i);
        bool byteWasWritten2 = mySerial.writeByte(high);
        bool byteWasWritten3 = mySerial.writeByte(low);
        if ( byteWasWritten1 && byteWasWritten2 && byteWasWritten3 ) {
            printf("value is %d \n", values[i]);
            isValids[i] = true;
        } else {
            printf("an error occurred \n");
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
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
