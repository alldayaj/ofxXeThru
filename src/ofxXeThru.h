//
//  ofxXeThru.h
//  Usage XeThru X4M200 model
//
//  Created by MICHAEL ROMEO on 6/21/18.
//
//

#include "XEP.hpp"
#include "Data.hpp"
#include "xtid.h"
#include "X4M300.hpp"
#include "ModuleConnector.hpp"

using namespace XeThru;

class ofxXeThru {
    
public:
    
    void setup(string _serialID){
        
        const std::string device_name = _serialID;
        return read_frame(device_name);
        
    }

    

private:
    
    //config values/
    int dac_min = 949;
    int dac_max = 1100;
    int iteration = 32;
    int pps = 150;
    int fps = 17;
    float offset = 0.18;
    float fa1 = 0.4;
    float fa2 = 5.0;
    int dc = 0;
    
    
    
    int read_frame(const std::string & device_name)
    {
        const unsigned int log_level = 0;
        ModuleConnector mc(device_name, log_level);
        XEP & xep = mc.get_xep();
        
        std::string FWID;
        //If the module is a X4M200 or X4M300 it needs to be put in manual mode
        xep.get_system_info(0x02, &FWID);
        if (FWID != "XEP") {
            //Module X4M300 or X4M200
            std::string Module;
            X4M300 & x4m300 = mc.get_x4m300();
            x4m300.set_sensor_mode(XTID_SM_STOP,0);
            x4m300.set_sensor_mode(XTID_SM_MANUAL,0);
            xep.get_system_info(0x01, &Module);
            std::cout << "Module " << Module << " set to XEP mode"<< std::endl;
        }
        
        // Configure XEP
        
        xep.x4driver_init();
        xep.x4driver_set_dac_min(dac_min);
        xep.x4driver_set_dac_max(dac_max);
        xep.x4driver_set_iterations(iteration);
        xep.x4driver_set_pulses_per_step(pps);
        xep.x4driver_set_fps(fps);
        xep.x4driver_set_frame_area_offset(offset);
        xep.x4driver_set_frame_area(fa1, fa2);
        xep.x4driver_set_downconversion(dc);

        
        // DataFloat
        XeThru::DataFloat test;
        // Check packets queue
        int packets = xep.peek_message_data_float();
        std::cout << "Packets in queue: " << packets<<'\n';
        
        // Printing output until KeyboardInterrupt
        // This data is not readable.
        std::cout << "Printing out data: " << '\n';
        while (true) {
            if (xep.read_message_data_float(&test)) {
                
                //stopped working
            }
            std::vector<float> outData = test.data;
            int sz = outData.size();
            for (int x = 0; x < sz; ++x) {
                //printing out unreadable RF-data
                std::cout << test.data[x] << " ";
            }
            std::cout << '\n';
        }
        return 0;
    }
};

