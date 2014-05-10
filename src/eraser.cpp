#include "eraser.h"

eraser::eraser(){
    
    centx = ofRandom(2144);
    centy = ofRandom(936);
    
    radius = ofRandom(10,50);
    radiusNoise = ofRandom(10);
    rotate = ofRandom(-2,2);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    bX = ofRandom(100)-50;
    bY = ofRandom(100)-50;
    
    waitCnt = ofRandom(0, 300);
    step = 0;

    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);
    
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
    radius += ofRandom(-1.0, 1.0);
    radiusNoise += ofRandom(-0.05, 0.05);
    
    centx += speedX;
    centy += speedY;
    if (centx >= 2144 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 936 || centy <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void eraser::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a --; }else{ a = 255;}
    }
    
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + (ofNoise(radiusNoise) * 10) -5;
        
        x = centx + (thisRadius * cos(ang*3.141592/180));
        y = centy + (thisRadius * sin(ang*3.141592/180));
        oppx = centx - (thisRadius * cos(ang*3.141592/180));
        oppy = centy - (thisRadius * sin(ang*3.141592/180));
        
        ofSetColor(30,0,30,200);
        ofSetLineWidth(ofRandom(1,5));
        ofNoFill();
        //        ofPoint(x,y);
        ofLine(x, y, oppx, oppy);
        ofBezier(x, y,
                 x + bX, y + bY,
                 oppx, oppy,
                 oppx + bX, oppy + bY);
        
        //        ofBeginShape();
        //        ofCurve(x, y,
        //                x + bX, y + bY,
        //                oppx, oppy,
        //                oppx + bX, oppy + bY);
        //        ofEndShape();
        
        
        if ((ang > 360) || (ang < -360) ) {
            ang = 0;
        }
        if ((radius > 150) || (radius < 0) ) {
            radius = 3;
        }
    }
    
    
}






