#ifndef _OF_PEN
#define _OF_PEN

#include "ofMain.h"

class pen{
    
public:

    int centx, centy;
    int radius;
    int ang;
    int rotate;
    float x, y;
    float oppx, oppy;
    
    float radiusNoise;
    int waitCnt;
    int step;

    int r;
    int g;
    int b;
    int ID;
    float col;
    bool flag;
    int a;
    int waiting;
    int sw;
    
    int speedX;
    int speedY;
//    int num;
//    int blue;
//    bool drawing;
//    float t_1;
//    float t_2;
//    float t_3;
//    float t_4;
    
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
