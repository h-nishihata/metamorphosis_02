#include "pen.h"

pen::pen(){
    
    centx = ofNoise(ofRandom(10)) * 1500 + 100;
    centy = ofNoise(ofRandom(10)) * 500;
    
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
    
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    
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
    
    
    
    ang += rotate;
    radius += ofRandom(-0.5, 0.5);
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
void pen::draw(){
    
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
        
        x = centx + (thisRadius * cos(ang*3.1415926/180));
        y = centy + (thisRadius * sin(ang*3.1415926/180));
        oppx = centx - (thisRadius * cos(ang*3.1415926/180));
        oppy = centy - (thisRadius * sin(ang*3.1415926/180));
        
        ofSetColor(r, g, b, a);
        ofSetLineWidth(ofRandom(1,3));
        ofNoFill();
        
/*
        for (int n=0; n<50; n++) {
            for (int m = this[n].ID + 1; m<50; m++) {
                
                float dx = this[m].centx-this[n].centx;
                float dy = this[m].centy-this[n].centy;
                float d = sqrt(dx*dx + dy*dy);
                
                if (d < this[m].radius + this[n].radius) {
                    if (d > abs(this[m].radius - this[n].radius)) {
                        ofSetLineWidth(2);
                        ofSetColor(this[m].r, this[m].g, this[m].b, this[m].a);
                        ofSetLineWidth(ofRandom(1,5));
                        ofLine(this[m].centx, this[m].centy, this[n].centx, this[n].centy);
                        
                    }
                }
                
            }
        }
*/
        
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






