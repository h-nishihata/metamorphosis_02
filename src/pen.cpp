#include "pen.h"

pen::pen(){
    
    centx = ofNoise(ofRandom(10)) * 1500 + 100;
    centy = ofNoise(ofRandom(10)) * 500;
    
    radius = ofRandom(3,30);
    radiusNoise = ofRandom(10);
    rotate = ofRandom(-2,2);
    
    if (rotate == 0) {
        rotate = 1;
    }
    
    bX = ofRandom(50)-25;
    bY = ofRandom(50)-25;
    
    waitCnt = ofRandom(0, 300);
    step = 0;
    
//    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
//    sw = ofRandom(1,8);
    
    speedX = ofRandom(-2, 2);
    speedY = ofRandom(-2, 2);

//    num = 100;
//    drawing = false;
    
}
//--------------------------------------------------------------
void pen::setup(){

}
//--------------------------------------------------------------
void pen::setR(int red){
    r = red;
}

//--------------------------------------------------------------
void pen::setG(int green){
    g = green;
}

//--------------------------------------------------------------
void pen::setB(int blue){
    b = blue;
}

//--------------------------------------------------------------
void pen::setID(int identify){
    ID = identify;
}

//--------------------------------------------------------------
void pen::update(){
    
    ang += rotate;
    radius += ofRandom(-0.5, 0.5);
    radiusNoise += ofRandom(-0.05, 0.05);
    
    if (flag == false) {
        r+=0.1;
        g+=0.1;
        b+=0.1;
        if(r>=255 || g>=255 || b>=25){
            flag = true;
        }
    }else if (flag == true){
        r-=0.1;
        g-=0.1;
        b-=0.1;
        if(r<=0 || g<=0 || b<=0){
            flag = false;
        }
    }
    
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
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
//        ofSetColor(0, 0, 255);
//        ofCircle(centx,centy,radius);

    
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
        
        ofSetColor(r, g, b, a);
        ofSetLineWidth(ofRandom(1,3));
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






