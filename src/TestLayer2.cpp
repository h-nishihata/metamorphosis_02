#include "TestLayer2.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer2::setup(){
    
    fbo.allocate(1440, 900);
    processFbo.allocate(1440, 900);
    
    image.loadImage("ohkyo.jpg");
    pixels = image.getPixels();
    
    for (int i=0; i<NUM; i++) {
        
        pos = pens[i].centy * 2144 + pens[i].centx;
        red = pixels[pos *3];
        green = pixels[pos *3 +1];
        blue =  pixels[pos *3 +2];
        identify = i;
        
        pens[i].setR(red);
        pens[i].setG(green);
        pens[i].setB(blue);
        pens[i].setID(identify);
        
    }
    
    a = 200;
    end_0 = true;
    end_1 = true;
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
    for (int i=0; i<NUM_E; i++) {
        erasers[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::draw(){
    
    ofTranslate(0, 900);
    ofRotateX(180);
    
    
    
    fbo.begin();
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    for (int i=0; i<NUM_E; i++) {
        erasers[i].draw();
    }
        
    
    // setting
    if (end_0 == true) {
        waiting_1++;
        fading(30, 0, 30, 200);
    }
    
    
    // phase 1
    if (end_1 == true) {
        if (waiting_2 < 300) {
            waiting_2++;
        }else{
            end_0 = false;
            end_2 = true;
            fading(30, 30, 0, 200);
        }
    }
    
    
    // phase 3
    if (end_2 == true) {
        if (waiting_3 < 300) {
            waiting_3++;
        }else{
            end_1 = false;
            end_3 = true;
            fading(40, 0, 0, 200);
        }
    }
    
    
    // phase 2
    if (end_3 == true) {
        if (waiting_4 < 300) {
            waiting_4++;
        }else{
            end_2 = false;
            end_4 = true;
            fading(0, 40, 0, 200);
        }
    }
    
    
    // reset
    if (end_4 == true) {
        if (waiting_5 < 300) {
            waiting_5++;
        }else{
            waiting_1 = waiting_2 = waiting_3 = waiting_4 = waiting_5 = 0;
            end_2 = end_3 = end_4 = false;
            end_0 = end_1 = true;
        }
    }
    
    //    ofSetColor(0, 0, 0, alpha);
    //    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);
    
}

//--------------------------------------------------------------------------------------------------------------
void TestLayer2::fading(int r, int g, int b, float alpha){
    
    ofSetColor(r, g, b, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i=0; i<NUM_E; i++) {
        erasers[i].setR(r);
        erasers[i].setG(g);
        erasers[i].setB(b);
    }
    
}

