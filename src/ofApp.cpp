#include "ofApp.h"

//bool rotateAng;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0,0,0);
    ofSetFrameRate(12);
    
    img.loadImage("hamamatsuzu_01.TIF");
    
    rgbaFbo.allocate(1920, 1200, GL_RGBA);
    
    rgbaFbo.begin();
    ofClear(255,255,255,0);
    rgbaFbo.end();
    
    pixels = img.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 4577 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        pens[i].setID(i);
        
    }
    
    fadeAmnt = 255;
    
    x = -100;
    y = -100;
    speedX = 0.13;
    speedY = 0.2;
    
    //    sender.setup(HOST, PORT);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (startDraw < 20) {
        startDraw++;
    }
    
    ofEnableAlphaBlending();
    
    rgbaFbo.begin();
    drawFboTest();
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    for (int i=0; i<NUM_E; i++) {
        erasers[i].update();
    }
    rgbaFbo.end();
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -368.5) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -313.5) {
        speedY = speedY*-1;
    }
    
}

//--------------------------------------------------------------
void ofApp::drawFboTest(){
    
    if(startDraw > 10){
        fadeAmnt = 1;
    }
    
    ofFill();
    ofSetColor(30, 0, 30, fadeAmnt);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    for (int i=0; i<NUM_E; i++) {
        erasers[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofHideCursor();
    
    ofSetColor(255,255,255);
    img.draw(x, y, img.width/2, img.height/2);
    rgbaFbo.draw(0,0);
    
    /*
     if (rotateAng == true) {
     ofxOscMessage m;
     m.setAddress("/test");
     m.addIntArg(pens[10].centx);
     m.addFloatArg(pens[10].centy);
     m.addStringArg("hello");
     m.addFloatArg(ofGetElapsedTimef());
     sender.sendMessage(m);
     }
     */
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
