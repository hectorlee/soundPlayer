#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    
    my_sound.loadSound("song.mp3");
    
    gui = new ofxUICanvas(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    gui->addWidgetDown(new ofxUILabel("SOUND PLAYER", OFX_UI_FONT_LARGE));
    gui->addWidgetDown(new ofxUISlider(304, 16, 0.0, 255.0, 100.0, "BACKGROUND VALUE"));
    ofAddListener(gui->newGUIEvent, this, &testApp::guiEvent);
    
    gui->addWidgetDown(new ofxUIToggle(32, 32, false, "FULLSCREEN"));
    gui->addWidgetEastOf(new ofxUIToggle(32, 32, false, "PLAY/STOP"), "FULLSCREEN");
    gui->addWidgetEastOf(new ofxUIToggle(32, 32, false, "PAUSE"), "PLAY/STOP");
    
    gui->loadSettings("GUI/guisettings.xml");

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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

//--------------------------------------------------------------
void testApp::exit(){
    
    gui->saveSettings("GUI/guisettings.xml");
    delete gui;
    
}

//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e){
    
    if(e.widget->getName() == "BACKGROUND VALUE") {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        //panPos = slider->getScaledValue();
        ofBackground(slider->getScaledValue());
    }
    else if(e.widget->getName() == "FULLSCREEN") {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }
    else if(e.widget->getName() == "PLAY/STOP") {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        if (toggle->getValue() == true) {
            my_sound.play();
        } else if (toggle->getValue() == false) {
            my_sound.stop();
        }
    }
    else if(e.widget->getName() == "PAUSE") {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        my_sound.setPaused(toggle->getValue());
    }
    
}
