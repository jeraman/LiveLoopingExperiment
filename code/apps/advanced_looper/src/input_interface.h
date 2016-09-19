#ifndef INPUT_INTERFACE_H
#define INPUT_INTERFACE_H

#include "ofMain.h"
#include "ofxMultiTouchPad.h"
#include <vector>


//state machine for the interface
typedef enum {
    NONE,
    ONE_FINGER,
    TWO_FINGERS,
    THREE_FINGERS,
    FOUR_FINGERS
} State;


//a simple data structure for storing touch events
class Touch {
public:
    float x;
    float y;
    float angle;
    float size;
    
    Touch(float x, float y, float angle=0, float size=0) {
        this->x = x;
        this->y = y;
        this->angle = angle;
        this->size  = size;
    }
};

/********************************
 Hides from the system what input interface is currently being used (e.g. ipad, mouse pad, etc).
 ********************************/

class Input_Interface
{
    
public:
     Input_Interface ();   //constructor
     Input_Interface (bool);   //constructor
    ~Input_Interface ();   //desctructor
    
    void draw ();                 //drawclass for visual feedback
    State get_state ();           //update the input interface update machine
    vector<Touch> get_fingers (); //returns a vector with the current finger positions
    void set_debug (bool);        //debug control

private:
    bool debug;
    ofxMultiTouchPad pad;
    State state;
};

#endif // INPUT_INTERFACE_H
