//
// Created by Piotr Walat on 07.05.2018.
//

#include "MovieSubtitles.h"

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out) {
    regex pattern1 {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
    regex pattern2 {R"((^\d\n))"};
    regex pattern3 {R"(^\d$)"};
    regex pattern4 {R"((\n\d\n))"};
    smatch equality;
    smatch st_fr_eq;
    smatch frame;
    smatch order;
    int line_number=0;
    bool check = false;
    if(frame_per_second < 0 ){
        throw std::invalid_argument("Błąd: Liczba klatek nie może być mniejsza od zera");
    }
    string start_string = (*in).str();
    std::regex_search(start_string, st_fr_eq, pattern2);
    int first_frame_number = stoi(st_fr_eq[1]);
    int previous = first_frame_number;
    std::regex_search(start_string, order, pattern4);
    for(int i = 1; i < order.size() ; i++, previous++) {
        if (stoi(order[i]) != previous+1) {
            throw OutOfOrderFrames();
        }
    }
    string string_entr= "";
    while(getline(*in, string_entr, '\n')) {
        if (std::regex_search(string_entr, equality, pattern1)) {
            line_number++;
            check = false;
            *out << equality[1] << ":" << equality[2] << ":";
            int delay_in_4 = stoi(equality[4].str()) + offset_in_micro_seconds;
            int delay_in_3 = stoi(equality[3])+delay_in_4/1000;
            string strpattern3 = to_string(delay_in_3);
            string strpattern4 = equality[4].str();
            if(delay_in_4 < 1000) {
                while(strpattern4.size() < 3) {
                    strpattern4 = '0' + strpattern4;
                }
                while(strpattern3.size()<2){
                    strpattern3='0'+strpattern3;
                }
                (*out)<< strpattern3 << "," << delay_in_4 << " --> ";
            }
            else {
                strpattern4 = to_string(delay_in_4%1000);
                while(strpattern4.size()<3) {
                    strpattern4 = '0' + strpattern4;
                }
                while(strpattern3.size()<2){
                    strpattern3='0'+strpattern3;
                }
                (*out)<< strpattern3 << "," << strpattern4 << " --> ";
            }
            *out << equality[5] << ":" << equality[6] << ":";
            string strpattern8 = equality[8].str();
            int delay_in_8 = stoi(equality[8].str()) + offset_in_micro_seconds;
            int delay_in_7 = stoi(equality[7])+delay_in_8/1000;
            string strpattern7 = to_string(delay_in_7);

            if(delay_in_8 < 1000) {
                while(strpattern8.size() < 3) {
                    strpattern8 = '0' + strpattern8;
                }
                while(strpattern7.size() < 2) {
                    strpattern7 = '0' + strpattern7;
                }
                (*out)<< strpattern7 << "," << strpattern8 << " --> ";
            }
            else{
                strpattern8 = to_string(delay_in_8%1000);
                while(strpattern8.size() < 3){
                    strpattern8 = '0' + strpattern8;
                }
                while(strpattern7.size() < 2) {
                    strpattern7 = '0' + strpattern7;
                }
                (*out)<< strpattern7 << "," << strpattern8 << '\n';
            }
            if(delay_in_3 < 0 || delay_in_4 < 0 || delay_in_7 < 0 || delay_in_8 < 0) {
                throw NegativeFrameAfterShift();
            }
            if (stoi(equality[1]) * 3600 + stoi(equality[2]) * 60 + stoi(equality[3]) + stoi(equality[4]) * 0.001 >= stoi(equality[5]) * 3600 + stoi(equality[6]) * 60 + stoi(equality[7]) + stoi(equality[8]) * 0.001) {
                throw moviesubs::SubtitleEndBeforeStart(line_number, string_entr);
            }
        }
        else {
            if(check) {
                throw InvalidSubtitleLineFormat();
            }
            if (std::regex_search(string_entr, frame, pattern3)) {
                check = true;
            }
            *out << string_entr << '\n';
        }
    }
}
void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out) {

    string entr_str = (*in).str();
    regex wzor {R"(\{(\d+)\}\{(\d+)\}(.*))"};
    smatch eq;
    int line_nr=0;

    if (frame_per_second < 0 ) {
        throw invalid_argument("Błąd: Liczba klatek nie może być mniejsza od zera");
    }

    while(getline(*in, entr_str, '\n')) {
        line_nr++;
        if (std::regex_search(entr_str, eq, wzor)) {
            int start = stoi(eq[1]) + (offset_in_micro_seconds * frame_per_second / 1000);
            int finish = stoi(eq[2]) + (offset_in_micro_seconds * frame_per_second / 1000);
            if (start < 0 || finish < 0 ){
                throw moviesubs::NegativeFrameAfterShift();
            }
            if (finish < start){
                throw moviesubs::SubtitleEndBeforeStart(line_nr, entr_str);
            }
            *out << "{" << start << "}";
            *out << "{" << finish << "}";
            *out << eq[3] << "\n";
        }
        else {
            throw moviesubs::InvalidSubtitleLineFormat();
        }
    }
}
int moviesubs::SubtitleEndBeforeStart::LineAt() const {
    return line_number;
}
string moviesubs::SubtitleEndBeforeStart::what() const {
    return "At line " + to_string(line_number) + ": " + line;
}
moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(int line_nr, string line_) {
    line_number = line_nr;
    line = line_;
}