#include "ofApp.h"


void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(22);
    
    ofDisableArbTex();
    
 //   ofLoadImage(bg, "images/unsquadron.png");
  //  bg.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    smokeTex = new ofTexture();
   // ofLoadImage(*smokeTex, "images/smoke2.png");
    smokeTex->setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    fireTex = new ofTexture();
   // ofLoadImage(*fireTex, "images/fire.png");
    fireTex->setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    explosionTex = new ofTexture();
   // ofLoadImage(*explosionTex, "images/explosion.png");
    explosionTex->setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    e.setup( smokeTex, fireTex, explosionTex );
    
    ofEnableArbTex(); //ofEnableArbText enables the use of ARB textures.
    
    /*
    strength = 950;
    numP = 16;
    friction = 0.93;
    life = 0.99;
    offset = 0;
    spawnOffset = 4;
    smokeLife = 1.6;
    gravity = 100;
    pixelScale = 3;
     */
     
    
    //GUI
    gui.setup();
    gui.add(strength.setup("strength",250,10,2900));
    gui.add(numP.setup("numP",16,5,50));
    gui.add(friction.setup("friction",0.93,0.8,1));
    gui.add(life.setup("life",0.99,0.2,1.7));
    gui.add(offset.setup("offset",0,0,50));
    gui.add(spawnOffset.setup("spawnOffset",4,0,10));
    gui.add(smokeLife.setup("smokeLife",1.6,0.2,4));
    gui.add(gravity.setup("gravity",100,-1000,1000));
    gui.add(pixelScale.setup("pixelScale",3,1,10));
    
    
  
    /*
    OFX_REMOTEUI_SERVER_SET_CONFIGS_DIR(CONFIGS_DIRECTORY);
    OFX_REMOTEUI_SERVER_SETUP();
    
    OFX_REMOTEUI_SERVER_SET_UPCOMING_PARAM_GROUP("EXPLOSION PARAMS");
    
    OFX_REMOTEUI_SERVER_SHARE_PARAM(strength, 10, 2900);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(numP, 5, 50);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(friction, 0.8, 1);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(life, 0.2, 1.7);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(offset, 0, 50);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(spawnOffset, 0, 10);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(smokeLife, 0.2, 4);
    OFX_REMOTEUI_SERVER_SHARE_PARAM(gravity, -1000, 1000);
    OFX_REMOTEUI_SERVER_SET_NEW_COLOR();
    OFX_REMOTEUI_SERVER_SHARE_PARAM(pixelScale, 1, 10);
    
    OFX_REMOTEUI_SERVER_LOAD_FROM_XML();
     */
    
    TIME_SAMPLE_SET_FRAMERATE(60);
}


void ofApp::update(){
    
    cout <<  "pixelScale = " << pixelScale << endl;
   
    float dt = 1.f/60.f;

    //以下は初期値の代入のみ
    e.setPixelScale(pixelScale); //ofAppで指定したピクセルの大きさをセット
    e.setSmokeProperties(
                         spawnOffset,		//random spawn pos offset from debris 破片からランダムに飛び散る(?)
                         ofVec2f(0,-50),	//smoke particles speed in pix / sec 速度
                         ofVec2f(50,0),		//smoke particles acc in pix / sec 加速度
                         smokeLife			//life in seconds ライフタイム
                         );
    e.update(dt);
    
}


void ofApp::draw(){
    
    ofSetColor(255);
   // bg.draw(0,0,ofGetWidth(), ofGetHeight());
    
    e.drawMesh();
    gui.draw();
    ofSetColor(250,0,0);
    ofDrawBitmapString("left mouse button to start explosion, right mouse button to stop post-smoke", 20,20);
    
    gui.draw();
    
}


void ofApp::keyPressed(int key){
    
    e.stopPostExplosionSmoke();
}


void ofApp::mousePressed(int x, int y, int button){
    
    if (button == 0){
        e.explode(ofVec2f(x,y), //where
                  ofVec2f(0, 2 * M_PI), //explosion angle range x:min y:max [0..¬π]
                  strength,	//explosion strength
                  numP,		//num debris particles
                  friction,	//air friction
                  ofVec2f(0, gravity), // gravity vector
                  life,		//particles life duration
                  offset		//initial position randomness, should be exploded object radius +-
                  );
        
    }else{
        e.reset();
    }
    
}
