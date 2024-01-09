#include "Input.h"

Input::Input() {
    Left = Idle;
    Right = Idle;
    Up = Idle;
    Down = Idle;
}

Input::~Input() { 
    
}

Keystates Input::GetState(DIRS dir) {
    switch (dir) {
        case DIR_UP:
            return Up;
            break;
        case DIR_DOWN:
            return Down;
            break;
        case DIR_LEFT:
            return Left;
            break;
        case DIR_RIGHT:
            return Right;
            break;
        default:
            return Idle;
            break;
    }
}

Keystates Input::SetState(DIRS dir, Keystates state) {
    switch (dir) {
        case DIR_UP:
            Up = state;
            break;
        case DIR_DOWN:
            Down = state;
            break;
        case DIR_LEFT:
            Left = state;
            break;
        case DIR_RIGHT:
            Right = state;
            break;
        default:
            break;
    }
    return state;
}

char Input::UpadateState(DIRS dir, char onOff) {
    Keystates lastOn = GetState(dir);
    if (onOff == 1) {
        if (!lastOn) {
            SetState(dir, Pressed);

        } else if (lastOn) {
            SetState(dir, Held);
        }
    } else {
        SetState(dir, Idle);
    }
    return GetState(dir);
}

Vector2D Input::GetDirection() {
    Vector2D direction;
    if (Up) {
        direction.y = -1;
    } else if (Down) {
        direction.y = 1;
    } else {
        direction.y = 0;
    }
    if (Left) {
        direction.x = -1;
    } else if (Right) {
        direction.x = 1;
    } else {
        direction.x = 0;
    }
    return direction;
}



