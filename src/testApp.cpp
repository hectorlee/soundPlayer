#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    my_sound.loadSound("song.mp3");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    ofDrawBitmapString("Player Controls", 10, 20);
    ofDrawBitmapString("Play/Stop = Spacebar", 10, 40);
    ofDrawBitmapString("Pause = p", 10, 60);
    ofDrawBitmapString("Unpause = o", 10, 80);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key == 'p') {
        my_sound.setPaused(true);
    }
    
    if (key == 'o') {
        my_sound.setPaused(false);
    }
    
    if (key == ' ') {
        if (my_sound.getIsPlaying() == true) {
            my_sound.stop();
        } else {
            my_sound.play();
        }

    }

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
    cout << mouseX << endl;
    float panPos = ofMap(ofClamp(mouseX, 0, 1024), 0, ofGetWindowWidth(), -1, 1);
    cout << "panPos" << panPos << endl;
    my_sound.setPan(panPos);

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