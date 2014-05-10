#include "TestLayer3.h"

//--------------------------------------------------------------------------------------------------------------
void TestLayer3::setup(){
    
    x = -100;
    y = -10;
    speedX = 0.13;
    speedY = 0.2;
    img.loadImage("ohkyo.jpg");
//    pixels = img.getPixels();
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::update(){
    
    x += speedX;
    y += speedY;
    
    if (x >= 0 || x <= -674) {
        speedX = speedX*-1;
    }
    if (y >= 0 || y <= -36) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer3::draw(){
    
    ofEnableAlphaBlending();
    ofBackground(255,255,255,0);
        
//    ofSetColor(200, 200, 80, 255);
    img.draw(x, y, img.width, img.height);
    
}
