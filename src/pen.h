#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:

    //  stroke
    float centx;
    float centy;
    float radius;
    float ang;
    float rotate;
    float x, y;
    float oppx, oppy;
    float bX;
    float bY;
    
    float radiusNoise;
    int waitCnt;
    int step;
    int ID;

    int speedX;
    int speedY;
    
    //  colors
    float r;
    float g;
    float b;
    bool flag;
    int a;
    int waiting;
    
    
    //  functions
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
