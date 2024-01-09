//////////////////////////////////////////////////////////////////////////////////////
// Project: Input.h
//       
// Author: Brandon Carpenter 
//
//
// Description: This is a class that handles the input for the game
//              the enum Keystates is used to keep track of the state of the key
//              if you need to check if the state of the key is pressed, held, or released 
//              it will give you a number other than 0;
//       
// updates: 
//       created: 12/19/2023
//       
//       
//////////////////////////////////////////////////////////////////////////////////////
#ifndef  Input_hpp
#define  Input_hpp


#include "SDL_keycode.h"
#include "Vector2D.h"

enum Keystates {
    Idle,
    Pressed,
    Held
};
enum DIRS{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
};

class Input {
    public:
        Input();
        ~Input();
        //*************************************************************************
        //  @Method: Keystates GetState(DIRS dir);
        //  @Purpose: gets the state of the key
        //  @Args: DIRS dir -- the direction of the key
        //  @returns: Keystates -- the state of the key
        //*************************************************************************
        Keystates GetState(DIRS dir);
        //*************************************************************************
        //  @method: void setstate(dirs dir, char state);
        //  @purpose: sets the state of the key
        //  @args: dirs dir -- the direction of the key
        //       @ char state -- the state of the key
        //  @returns: keystates -- the state of the key
        //*************************************************************************
        Keystates SetState(DIRS dir, Keystates state);
        //*************************************************************************
        //  @Method: char UpadateState(DIRS dir, char onOff);
        //  @Purpose: updates the state of the key
        //  @Args: DIRS dir -- the direction of the key
        //       @ char onOff -- the state of the key
        //  @returns: char -- the state of the key
        //*************************************************************************
        char UpadateState(DIRS dir, char onOff);


        //*************************************************************************
        //  @Method: Vector2D GetDirection();
        //  @Purpose: gets the direction of the key
        //  @Args:  -- 
        //  @returns: Vector2D -- the direction of the key
        //*************************************************************************
        Vector2D GetDirection();

    private:
        Keystates Left, Right, Up, Down;
};
















#endif /* Input_hpp */

