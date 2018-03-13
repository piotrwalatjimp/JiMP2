//
// Created by walapiot on 13.03.18.
//


#include "MinimalTimeDifference.h"

unsigned int ToMinutes(std::string time_HH_MM){
    string time_HH_string, time_MM_string;
    int time_HH, time_MM;
    unsigned int result_minutes;

    if( time_HH_MM[2]==':'){
        time_HH_string = time_HH_MM.substr(0,2);
        time_MM_string = time_HH_MM.substr(3,5);
    }
    if(time_HH_MM[1]==':'){
        time_HH_string = time_HH_MM.substr(0,1);
        time_MM_string = time_HH_MM.substr(2,4);
    }
    else{
        std::cout<< "Podaj godzine w formacie HH:MM lub H:MM" <<std::endl<<std::endl;

    }
    istringstream string_to_int_HH(time_HH_string);
    string_to_int_HH >> time_HH;

    istringstream string_to_int_MM(time_MM_string);
    string_to_int_MM >> time_MM;

    result_minutes=time_HH*60+time_MM;
    if(result_minutes == 0) {
        result_minutes = 666;
    }
}

unsigned int MinimalTimeDifference(std::vector<std::string> times){
    unsigned int first_time, second_time;

}