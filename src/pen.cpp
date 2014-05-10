#include "pen.h"

pen::pen(){
    
    centx = ofRandom(2144);
    centy = ofNoise(ofRandom(10)) * 300;
    radius = ofRandom(5,20);
    radiusNoise = ofRandom(10);
    rotate = ofRandom(-2,2);
    
    if (rotate == 0) {
        rotate = 1;
    }
    

    waitCnt = ofRandom(0, 300);
    step = 0;
    
    col = 0;
    flag = false;
    a = ofRandom(0, 255);
    waiting = ofRandom(0,80);
    sw = (int)ofRandom(1,8);
    
    speedX = ofRandom(-2,2);
    speedY = ofRandom(-2,2);
    
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
    radius += ofRandom(-1,2);
    radiusNoise += ofRandom(-0.05, 0.1);
    
    if (flag == false) {
        col+=0.1;
        if(col > 200){
            flag = true;
        }
    }else if (flag == true){
        col-=0.1;
        if(col < 0){
            flag = false;
        }
    }
    
    centx += speedX;
    centy += speedY;
    if (centx >= 1440 || centx <= 0) {
        speedX = speedX*-1;
    }
    if (centy >= 900 || speedY <= 0) {
        speedY = speedY*-1;
    }
    
}
//--------------------------------------------------------------
void pen::draw(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
//    if (drawing) {
//        
//        ofSetColor(0, 0, 255);
//        ofSetLineWidth(5);
//        ofLine(t_1, t_2, t_3, t_4);
//        
//    }
    
    if(waiting < 80){
        waiting++;
    }else{
        if(a > 0){ a --; }else{ a = 255;}
    }
    
    
    if (step < waitCnt) {
        step++;
    }
    else {
        
        float thisRadius = radius + (ofNoise(radiusNoise) * 200) -100;
        
        x = centx + (thisRadius * cos(ang*3.141592/180));
        y = centy + (thisRadius * sin(ang*3.141592/180));
        oppx = centx - (thisRadius * cos(ang*3.141592/180));
        oppy = centy - (thisRadius * sin(ang*3.141592/180));
        
        ofSetColor(r+col, g+col, b, a);
        ofSetLineWidth(sw);
        ofLine(x, y, oppx, oppy);
        
        if ((ang > 360) || (ang < -360) ) {
            ang = 0;
        }

    }


}






