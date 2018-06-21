//
//  ofxXeThru.h
//  This code is specifcally for the XeThru X4M200
//
//  Created by MICHAEL ROMEO on 6/21/18.
//
//

#include "ModuleConnector.hpp"
#include "X4M200.hpp"
#include <iostream>

using namespace XeThru;

class ofxXeThru {
    
public:
    void setup(string _serialID){
        
        const std::string device_name = _serialID; // e.g. "/dev/cu.usbmodem1411"
        ping(device_name);
    }
    void update();
    void draw();

private:
    
    void usage()
    {
        std::cout << "ping <com port or device file>" << std::endl;
    }
    
    
    int ping(const std::string & device_name)
    {
        const unsigned int log_level = 5;
        ModuleConnector mc(device_name, log_level);
        X4M200 & x4m200 = mc.get_x4m200();
        unsigned int pong = 0;
        const int status = x4m200.ping(&pong);
        
        if(status != 0) {
            std::cout << "Something went wrong - error code: " << status << std::endl;
            return status;
        }
        
        std::cout << "pong: " << pong << std::endl;
        return 0;
    }

    
};
