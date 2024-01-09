#pragma once

#include "Components.h"
#include <string>



class SCI : public Component
{
public:
    // the movenemt componet
    TransformComponent* transform;

    int baudRate;
    int parity;
    int stopBits;
    int byteSize;
    int flowControl;
    std::string portName;
    std::string data;


    void init() override{
        baudRate = 9600;
        parity = 0;
        stopBits = 1;
        byteSize = 8;
        flowControl = 0;
        portName = "COM1";
        data = "";
    }


    void update() override{
    }

    void writeData(std::string data);
    std::string readData();

};
