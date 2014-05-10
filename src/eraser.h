#ifndef _OF_ERASER
#define _OF_ERASER

#include "ofMain.h"

class eraser{
    
public:
    
    int centx, centy;
    float radius;
    int ang;
    int rotate;
    int x, y;
    int oppx, oppy;
    int bX;
    int bY;
    
    float radiusNoise;
    int waitCnt;
    int step;
    
    float r;
    float g;
    float b;
//    int ID;
    float col;
    bool flag;
    int a;
    int waiting;
    int sw;
    
    int speedX;
    int speedY;
    
    eraser();
    void setup();
    void update();
    void draw();
    
    void setR(int red);
    void setG(int green);
    void setB(int blue);
//    void setID(int indentify);
    
};

#endif
