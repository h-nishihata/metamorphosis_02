#ifndef _OF_ERASER
#define _OF_ERASER

#include "ofMain.h"

class eraser{
    
public:
    
    //  functions
    eraser();
    void setup();
    void update();
    void draw();
    
    
    //  stroke
    int centx, centy;
    float radius;
    float ang;
    float rotate;
    int x, y;
    int oppx, oppy;
    int bX;
    int bY;
    
    float radiusNoise;
    int waitCnt;
    int step;
    
    int speedX;
    int speedY;
    
    
    //  colors
    float r;
    float g;
    float b;
    int a;
    int waiting;
    bool flag_r;
    bool flag_g;
    bool flag_b;
    
};

#endif
