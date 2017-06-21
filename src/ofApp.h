#pragma once

#include "ofMain.h"
#include "ofxRemoteUIServer.h"
#include "ofxTimeMeasurements.h"
#include "ofxGui.h"

#include "Explosion.h"

#define CONFIGS_DIRECTORY	"configs"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key){}
    void mouseMoved(int x, int y ){}
    void mouseDragged(int x, int y, int button){}
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button){}
    void windowResized(int w, int h){}
    
    
    // APP SETUP ////////////////////////////////////////////
    
    Explosion e;
    
    ofTexture * smokeTex;
    ofTexture * fireTex;
    ofTexture * explosionTex;
    
    ofxFloatSlider strength;
    ofxIntSlider numP;
    ofxFloatSlider friction;
    ofxFloatSlider life;
    ofxFloatSlider offset;
    ofxFloatSlider spawnOffset;
    ofxFloatSlider smokeLife;
    ofxFloatSlider gravity;
    ofxIntSlider pixelScale;
    ofxPanel gui;
    
    ofTexture bg;
    
    
    
    
    
};
