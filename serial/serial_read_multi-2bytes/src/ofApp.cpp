#include "ofApp.h"

ofSerial mySerial;
const int val_size = 3;
int values[val_size] = {0, 0, 0};
bool isValids[val_size] = {false, false, false};

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    mySerial.setup("/dev/cu.usbmodem1421",9600);
}

//--------------------------------------------------------------
void ofApp::update(){
    bool isValids[val_size] = {false, false, false};
    if (mySerial.available() >= 3*val_size) {
        int head = mySerial.readByte();
        for (int i=0; i<val_size; i++){
            if (head == 128+i){
                int high = mySerial.readByte();
                int low  = mySerial.readByte();
                values[i] = (high<<7) + low;
                if (0 <= values[i] && values[i] <= 1023){
                    isValids[i] = true;
                    printf("value is %d \n", values[i]);
                }
            }
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
