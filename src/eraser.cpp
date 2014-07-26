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
    
    r = ofRandom(30);
    g = ofRandom(30);
    b = ofRandom(30);
    
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
    
    
    
    if (flag_r == false) {
        r+=0.1;
        if(r>=30){
            flag_r = true;
        }
    }else if (flag_r == true){
        r-=0.1;
        if(r<=0){
            flag_r = false;
        }
    }
    
    if (flag_g == false) {
        g+=0.1;
        if(g>=30){
            flag_g = true;
        }
    }else if (flag_g == true){
        g-=0.1;
        if(g<=0){
            flag_g = false;
        }
    }
    
    if (flag_b == false) {
        b+=0.1;
        if(b>=30){
            flag_b = true;
        }
    }else if (flag_b == true){
        b-=0.1;
        if(b<=0){
            flag_b = false;
        }
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






