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
    
    alpha = 60;
    end_0 = true;
    end_1 = true;
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::update(){
    
    for (int i=0; i<NUM; i++) {
        pens[i].update();
    }
    
}
//--------------------------------------------------------------------------------------------------------------
void TestLayer2::draw(){
    
    ofTranslate(0, 900);
    ofRotateX(180);
    
    // setting
    if (end_0 == true) {
        waiting_1++;
        if (alpha < 60) {
            alpha+=0.1;
        }
    }
    
    // phase 1
    if (end_1 == true) {
        if (waiting_2 < 80) {
            waiting_2++;
        }else{
            end_0 = false;
            end_2 = true;
            if (alpha > 0) {
                alpha-=5;
            }
        }
    }
    
    // elase all
    if (end_2 == true) {
        if (waiting_3 < 700) {
            waiting_3++;
        }else{
            end_1 = false;
            end_3 = true;
            if (alpha < 60) {
                alpha+=0.1;
            }
        }
    }
    
    // phase 2
    if (end_3 == true) {
        if (waiting_4 < 80) {
            waiting_4++;
        }else{
            end_2 = false;
            end_4 = true;
            if (alpha > 0) {
                alpha-=5;
            }
        }
    }
    
    // reset
    if (end_4 == true) {
        if (waiting_5 < 700) {
            waiting_5++;
        }else{
            waiting_1 = waiting_2 = waiting_3 = waiting_4 = waiting_5 = 0;
            end_2 = end_3 = end_4 = false;
            end_0 = end_1 = true;
        }
    }
    
    
    fbo.begin();
    ofEnableAlphaBlending();
    ofBackground(0,0,0,0);
    processFbo.draw(0, 0);
    fbo.end();
    
    
    
    processFbo.begin();
    for (int i=0; i<NUM; i++) {
        pens[i].draw();
    }
    
    for (int n=0; n<NUM; n++) {
        for (int m = pens[n].ID + 1; m<NUM; m++) {
            
            float dx = pens[m].centx-pens[n].centx;
            float dy = pens[m].centy-pens[n].centy;
            float d = sqrt(dx*dx + dy*dy);
            
            if (d < pens[m].radius + pens[n].radius) {
                if (d > abs(pens[m].radius - pens[n].radius)) {
                    //                    pens[n].drawing = true;
                    //                    cout << "ok" << endl;
                    //                    pens[n].t_1 = pens[n].centx;
                    //                    pens[n].t_2 = pens[n].centy;
                    //                    pens[n].t_3 = pens[m].centy;
                    //                    pens[n].t_4 = pens[m].centy;
                    ofSetColor(pens[m].r + pens[m].col,
                               pens[m].g + pens[m].col,
                               pens[m].b + pens[m].col,
                               pens[m].a);
                    ofSetLineWidth(5);
                    ofLine(pens[m].centx, pens[m].centy, pens[n].centx, pens[n].centy);
                    //            float a = (pens[n].radius * pens[n].radius
                    //                       - pens[n+1].radius * pens[n+1].radius
                    //                       + d * d
                    //                       )/(2*d);
                    //            float p2x = pens[n].centx + a*(pens[n+1].centx - pens[n].centx);
                    //            float p2y = pens[n].centy + a*(pens[n+1].centy - pens[n].centy);
                    //            ofSetColor(0,0,255);
                    //            ofSetLineWidth(5);
                    //            ofLine(pens[n].centx, pens[n].centy, p2x, p2y);
                }
            }
            
        }
        
    }
    
    ofSetColor(200, 180, 100, alpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    processFbo.end();
    
    
    
    ofSetHexColor(0xffffff);
    fbo.draw(0,0);
    
    
    
}
