#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO		// uncomment this to use a live camera
								// otherwise, we'll use a movie file

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

        #ifdef _USE_LIVE_VIDEO
		  ofVideoGrabber 		vidGrabber;	//live camera will be used
		#else
		  ofVideoPlayer 		vidPlayer;
		#endif

        ofxCvColorImage		colorImg;			//hold orignal new frame

        ofxCvGrayscaleImage 	grayImage;			//convert to grayimage
	ofxCvGrayscaleImage 	grayBg;				//gray background image for abs
	ofxCvGrayscaleImage 	grayDiff;			//hold grayimage aft abs

//virtual int findContours( ofxCvGrayscaleImage& input, int minArea,
//int maxArea, int nConsidered, bool bFindHoles, bool bUseApproximation = true);
        ofxCvContourFinder 	contourFinder;

		int 				threshold;
		bool				bLearnBakground;


};

