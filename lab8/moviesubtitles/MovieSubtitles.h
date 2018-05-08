//
// Created by Piotr Walat on 07.05.2018.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <regex>
#include <string>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <sstream>

using std::invalid_argument;
using std::cout;
using std::string;
using std::smatch;
using std::to_string;
using std::endl;
using std::unique_ptr;
using std::stringstream;
using std::regex;

namespace moviesubs {

    class MovieSubtitles {

    public:

        virtual void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out) = 0 ;

    };


    class SubRipSubtitles : public MovieSubtitles {

    public:

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out);

    };

    class MicroDvdSubtitles : public MovieSubtitles {

    public:

        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out);

    };

    class NegativeFrameAfterShift{

    };

    class SubtitleEndBeforeStart{

    public:

        SubtitleEndBeforeStart(int line_nr, string line_);
        int LineAt()const;
        string what() const;

    private:

        int line_number;
        string line;

    };

    class InvalidSubtitleLineFormat{
    };

    class MissingTimeSpecification {
    };

    class OutOfOrderFrames {
    };

}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
