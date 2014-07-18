#include "eraser.h"

eraser::eraser(){
    
    centx = ofRandom(1920);
    centy = ofRandom(1200);
    
    radius = (r+g+b)/3/ofRandom(100);
    radiusNoise = ofRandom(10);
    rotate = ofRandom(-2, 2);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    bX = ofRandom(50)-25;
    bY = ofRandom(50)-25;
    
    speedX = ofRandom(-2, 2);
    speedY = ofRandom(-2, 2);
    
    waitCnt = ofRandom(0, 300);
    step = 0;

    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
}

//--------------------------------------------------------------
void eraser::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void eraser::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void eraser::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void eraser::update(){
    
    ang += rotate;
    radius += ofRandom(-0.5, 0.5);
    radiusNoise += ofRandom(-0.05, 0.05);
    
    centx += speedX;
    centy += speedY;
    
    if (centx >= 1920 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 1200 || centy <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void eraser::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
//    if(waiting < 80){
//        waiting++;
//    }else{
//        if(a > 0){ a --; }else{ a = 255;}
//    }    
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + (ofNoise(radiusNoise) * 10) -5;
        
        x = centx + (thisRadius * cos(ang*3.141592/180));
        y = centy + (thisRadius * sin(ang*3.141592/180));
        oppx = centx - (thisRadius * cos(ang*3.141592/180));
        oppy = centy - (thisRadius * sin(ang*3.141592/180));
        
        ofSetColor(r, g, b);
        ofSetLineWidth(ofRandom(1,5));
        ofNoFill();
        
        ofLine(x, y, oppx, oppy);
        ofBezier(x, y,
                 x + bX, y + bY,
                 oppx, oppy,
                 oppx + bX, oppy + bY);
        
        
        if ((ang > 360) || (ang < -360) ) {
            ang = 0;
        }
        if ((radius > 150) || (radius < 0) ) {
            radius = 3;
        }
    }
    
    
}






