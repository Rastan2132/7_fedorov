#include "Header.h"

Uzond Uzond::create(short size_of_people, const std::vector<std::string>& arrOfNameUrzant, const std::vector<std::string>& arrOfNames, const std::vector<std::string>& arrOfSurnames, const std::vector<std::string>& arrOfNameKindergarten, const std::vector<std::string>& arrOfWork) {
    Uzond uand;
    uand.Name_property = arrOfNameUrzant[rand() % arrOfNameUrzant.size()];
    uand.Numer_property = rand_data(_num);

    for (int i = 0; i < size_of_people; i++) {
        bool is_child = rand() % 2;
        std::string sex = rand_data(_sex);
        std::string name = arrOfNames[rand_data(sex)];
        std::string surname = arrOfSurnames[rand_data(sex)];
        std::string piesel = rand_data(_piesel);

        if (is_child) {
            std::string kindergarten = arrOfNameKindergarten[rand() % arrOfNameKindergarten.size()];
            uand.people.push_back(new Children(name, surname, std::to_string(2023 - (rand() % 18)), piesel, sex, kindergarten));
        } else {
            std::string year = rand_data(_year);
            std::string work = arrOfWork[rand() % arrOfWork.size()];
            uand.people.push_back(new People(name, surname, year, piesel, sex, work, std::to_string(rand() % 20)));
        }
    }

    return uand;
}

