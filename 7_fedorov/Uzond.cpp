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

void Uzond::addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames, vector<string> arrOfNameKindergarten, vector<string> arrOfWork, bool flag) {
    string sex = rand_data(_sex);
    string name = arrOfNames[rand_data(sex)];
    string surname = arrOfSurnames[rand_data(sex)];
    string year = rand_data(_year);
    string piesel = rand_data(_piesel);
    if (flag) {

        string Kindergarten = arrOfNameKindergarten[rand() % arrOfNameKindergarten.size()];
        people.push_back(new Children(name, surname, to_string(2023 - (rand() % 18)), piesel, sex, Kindergarten));
    }
    else {
        string year = rand_data(_year);
        string Work = arrOfWork[rand() % arrOfWork.size()];
        people.push_back(new People(name, surname, year, piesel, sex, Work, to_string(rand() % 20)));
    }
    
}

void Uzond::sort(short flag)
{

    switch (flag)
    {
    case 1:
        for (short i = 0; i < people.size(); i++) {
            for (short j = i + 1; j < people.size(); j++) {
                if (people[i]->FullName->Name_property.compare(people[j]->FullName->Name_property) > 0) {
                    swap(people[i]->FullName, people[j]->FullName);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 2:
        for (short i = 0; i < people.size(); i++) {
            for (short j = i + 1; j < people.size(); j++) {
                if (people[i]->FullName->Surname_property.compare(people[j]->FullName->Surname_property) > 0) {
                    swap(people[i]->FullName, people[j]->FullName);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }

        break;
    case 3:
        for (short i = 0; i < people.size(); i++) {
            for (short j = i + 1; j < people.size(); j++) {
                if (people[i]->sex.compare(people[j]->sex) > 0) {
                    swap(people[i]->FullName, people[j]->FullName);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 4:
        for (short i = 0; i < people.size(); i++)
        {
            for (short j = i + 1; j < people.size(); j++)
            {
                if (people[i]->piesel.compare(people[j]->piesel) > 0)
                {
                    swap(people[i]->FullName, people[j]->FullName);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;
    case 5:

        for (short i = 0; i < people.size(); i++) {
            for (short j = i + 1; j < people.size(); j++) {
                if (people[i]->Year.compare(people[j]->Year) > 0) {
                    swap(people[i]->FullName, people[j]->FullName);
                    swap(people[i]->sex, people[j]->sex);
                    swap(people[i]->piesel, people[j]->piesel);
                    swap(people[i]->Year, people[j]->Year);
                }
            }
        }
        break;

    }
}
void Uzond::removePerson(int index) {
    if (index < 0 || index >= people.size()) {
        return;
    }
    people.erase(people.begin() + (index - 1));
}