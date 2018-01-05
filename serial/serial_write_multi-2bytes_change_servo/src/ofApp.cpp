#include "ofApp.h"

ofSerial mySerial;
const int val_size = 2;
int values[val_size] = {0, 0};
bool isValids[val_size] = {false, false};
int t = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(120);
    mySerial.setup("/dev/cu.usbmodem1421",115200);
}

//--------------------------------------------------------------
void ofApp::update(){
    t += 4;
    if (t > 1023){
        t = 0;
    }
    float theta = 2*PI*(float)t/1023;
    float x = 60*(cos(theta)+1)/2 + 60;
    float y = 60*(sin(theta)+1)/2 + 60;
    values[0] = round(x);
    values[1] = round(y);
    
    bool isValids[val_size] = {false, false};
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
