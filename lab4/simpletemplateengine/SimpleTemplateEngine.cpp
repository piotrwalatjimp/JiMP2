//
// Created by Piotrek on 25.03.2018.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <regex>

namespace nets{

    View::View():temp(""){
        std::cout << "Konstruktor bezparametrowy" << std::endl;
    }

    View::View(std::string text){
        View::SetText(text);
    }

    View::~View(){

    }

    std::string View::Render(const std::unordered_map <std::string, std::string> &model) const{
        std::regex pattern ("(\\{\\{[A-Za-z0-9_]+\\}\\})");
        std::string line = this -> temp;
        std::smatch match;
        std::string search = line;


        return line;
    }

    std::string View::GetText() const{
        return this->temp;
    }

    void View::SetText(std::string text){
        this->temp = text;
    }

}