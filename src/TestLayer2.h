#include "ofMain.h"

#include "ofxLayer.h"
#include "pen.h"
#include "eraser.h"

#define OFX_LAYER_DEFINE_LAYER_CLASS(Klass) public: const char* getClassName() const { return #Klass; } \
unsigned int getClassID() const { return ofx::Layer::Type2Int<Klass>::value(); }

#define NUM 50
#define NUM_E 10

class TestLayer2 : public ofxLayer::Layer{
public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(TestLayer2)
    
    void setup();
    void update();
    void draw();
    void fading(int r, int g, int b, float alpha);
    
    void drawFboTest();
    
    unsigned char* pixels;
    int pos;
    int red;
    int green;
    int blue;
    int a;
    int identify;

    int waiting_1;
    int waiting_2;
    int waiting_3;
    int waiting_4;
    int waiting_5;
    bool end_0;
    bool end_1;
    bool end_2;
    bool end_3;
    bool end_4;
    
    int fadeAmnt;
    
    ofFbo fbo;
    ofFbo processFbo;
    ofImage image;
    
    pen pens[NUM];
    eraser erasers[NUM_E];

};