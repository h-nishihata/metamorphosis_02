#pragma once

#include "ofMain.h"
#include "pen.h"
#include "eraser.h"

#define NUM 20
#define NUM_E 10

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void drawFboTest();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
   
    unsigned char* pixels;
    int pos;
    int red;
    int green;
    int blue;
    
    int startDraw;
    float fadeAmnt;
    
    float x;
    float y;
    float speedX;
    float speedY;

    
    ofFbo rgbaFbo;
    
    ofImage img;
    
    pen pens[NUM];
    eraser erasers[NUM_E];    
};
