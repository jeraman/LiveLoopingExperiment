#pragma once

#include "ofMain.h"
#include "loop.h"
#include "input_interface.h"
#include "state_machine.h"
#include "gui.h"


class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
    
        void setup_sound();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
		void audioIn(float * input, int bufferSize, int nChannels);
        void audioOut(float * input, int bufferSize, int nChannels);

        void set_debug(bool);
    
    private:
        State_Machine sm;
        ofSoundStream soundStream;
        bool          debug;
    
};
