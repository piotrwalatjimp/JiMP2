//
// Created by Piotrek on 25.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#include <string>
#include <unordered_map>
namespace nets{

    class View {
    public:
        View();
        View(std::string tekst);
        ~View();

        std::string Render(const std::unordered_map <std::string, std::string> &model) const;

        std::string GetText() const;

        void SetText(std::string text);
    private:
        std::string temp;
    };
}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H