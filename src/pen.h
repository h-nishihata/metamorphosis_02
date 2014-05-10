#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:

    float centx;
    float centy;
    float radius;
    int ang;
    int rotate;
    float x, y;
    float oppx, oppy;
    float bX;
    float bY;
    
    float radiusNoise;
    int waitCnt;
    int step;

    float r;
    float g;
    float b;
    int ID;
    float col;
    bool flag;
    int a;
    int waiting;
    int sw;
    
    int speedX;
    int speedY;
    
    pen();
    void setup();
    void update();
    void draw();
    
    void setR(int red);
    void setG(int green);
    void setB(int blue);
    void setID(int indentify);
    
};

#endif