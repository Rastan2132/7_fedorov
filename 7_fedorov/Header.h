#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>
#include <vector>
#include <sstream>

using namespace std;

#define MAXLINE 15
#define _num 3
#define _sex 2
#define _year 4
#define _piesel 12

#define MENU "| q-Zamkac |  a-ADD uzytkownika  |  d-Usuwanie uzytkownika |  e-Redaktor |  s-Sortowac |  y-Szukaj |" 
#define stru "#      Name            Surname	       Year     Piesel 	        Sex      Work/Kinder.    work exp."

#define MANIP setw(MAXLINE) <<  left 

int rand_data(string sex);
string rand_data(int max);


enum Keys { Enter = 13, Backspace = 8 };
enum SpecialKeys { Left = 75, Right = 77, End = 79, Home = 71, Esc = 27, Del = 83 };

struct COLOR
{
    short text;
    short back;
};
enum ConsoleColor
{
    Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

class Full_name
{
    string Name = " ";
    string Surname = " ";
public:
    Full_name(string Name_ = "lol", string Surname_ = "lol") :Name(Name_), Surname(Surname_) {}

    string get_name() const { return Name; }
    string get_surname() const { return Surname; }
    void set_name(string Name_) { Name = Name_; }
    void set_surname(string Surname_) { Surname = Surname_; }
    __declspec(property(get = get_name, put = set_name)) string Name_property;
    __declspec(property(get = get_surname, put = set_surname)) string Surname_property;

    Full_name& operator=(const Full_name& other) {
        if (this != &other) {
            Name = other.Name;
            Surname = other.Surname;
        }
        return *this;
    }
};

class Uzond {

    class Users {
    protected:
        std::string Year;
        std::string piesel;
        std::string sex;
        Full_name* FullName{ nullptr };
    public:
        Users(const std::string& Name_ = "lol", const std::string& Surname_ = "lol", const std::string& Year_ = "lol", const std::string& piesel_ = "lol", const std::string& sex_ = "lol") : Year(Year_), piesel(piesel_), sex(sex_), FullName(new Full_name(Name_, Surname_)) {}
        Users(const Users& other) : Year(other.Year), piesel(other.piesel), sex(other.sex), FullName(new Full_name(*other.FullName)) {}


        Users& operator=(const Users& other) {
            if (this != &other) {
                Year = other.Year;
                piesel = other.piesel;
                sex = other.sex;
                delete FullName;
                FullName = new Full_name(*other.FullName);
            }
            return *this;
        }

        std::string get_year() const { return Year; }
        void set_year(const std::string& Year_) { Year = Year_; }

        std::string get_piesel() const { return piesel; }
        void set_piesel(const std::string& piesel_) { piesel = piesel_; }

        std::string get_sex() const { return sex; }
        void set_sex(const std::string& sex_) { sex = sex_; }

        Full_name* get_fullname() const { return FullName; }
        void set_fullname(Full_name* FullName_) { FullName = FullName_; }
        
        virtual ~Users() {}
      //  virtual void edit();
        virtual void print() const;
      //  virtual void save(std::ostream& out) const;
      //  virtual void find(const char* keyword) const;

        __declspec(property(get = get_year, put = set_year)) std::string year_property;
        __declspec(property(get = get_piesel, put = set_piesel)) std::string piesel_property;
        __declspec(property(get = get_sex, put = set_sex)) std::string sex_property;
        __declspec(property(get = get_fullname, put = set_fullname)) Full_name* fullname_property;

    };

    class People : public Users {
    private:
        std::string work;
        std::string work_experience;
    public:
        People(const std::string& Name_ = "lol", const std::string& Surname_ = "lol", const std::string& Year_ = "lol", const std::string& piesel_ = "lol", const std::string& sex_ = "lol", const std::string& work_ = "lol", const std::string& work_experience_ = "lol") : Users(Name_, Surname_, Year_, piesel_, sex_), work(work_), work_experience(work_experience_) {}

        std::string get_work() const { return work; }
        void set_work(const std::string& work_) { work = work_; }
        std::string get_work_experience() const { return work_experience; }
        void set_work_experience(const std::string& work_experience_) { work_experience = work_experience_; }

     //   void edit() override;
        void print() const override;
     //   void save(std::ostream& out) const override;
     //   void find(const char* keyword) const override;

        People& operator=(const People& other) {
            if (this != &other) {
                Users::operator=(other);
                work = other.work;
                work_experience = other.work_experience;
            }
            return *this;
        }
        __declspec(property(get = get_work, put = set_work)) std::string work_property;
        __declspec(property(get = get_work_experience, put = set_work_experience)) std::string work_experience_property;

    };

    class Children : public Users {
    private:
        std::string kindergarten;
    public:
        Children(const std::string& Name_ = "lol", const std::string& Surname_ = "lol", const std::string& Year_ = "lol", const std::string& piesel_ = "lol", const std::string& sex_ = "lol", const std::string& kindergarten_ = "lol") : Users(Name_, Surname_, Year_, piesel_, sex_), kindergarten(kindergarten_) {}

        std::string get_kindergarten() const { return kindergarten; }
        void set_kindergarten(const std::string& kindergarten_) { kindergarten = kindergarten_; }

      //  void edit() override;
        void print() const override;
      //  void save(std::ostream& out) const override;
      //  void find(const char* keyword) const override;

        Children& operator=(const Children& other) {
            if (this != &other) {
                Users::operator=(other);
                kindergarten = other.kindergarten;
            }
            return *this;
        }
        __declspec(property(get = get_kindergarten, put = set_kindergarten)) std::string kindergarten_property;

    };

    std::vector<Users*> people;
    std::string Name;
    std::string Numer;
public:
    Uzond(){
        Name = "lol";
        Numer = "lol";
    }
    Uzond(const Uzond& other)
        : Name(other.Name), Numer(other.Numer)
    {
        for (const Users* user : other.people) {
            if (const People* peopleUser = dynamic_cast<const People*>(user)) {
                People* clonedPeople = new People(*peopleUser);
                people.push_back(clonedPeople);
            }
            else if (const Children* childrenUser = dynamic_cast<const Children*>(user)) {
                Children* clonedChildren = new Children(*childrenUser);
                people.push_back(clonedChildren);
            }
            else {
                Users* clonedUser = new Users(*user);
                people.push_back(clonedUser);
            }
        }
    }

    ~Uzond()
    {
        for (Users* user : people) {
            delete user;
        }
        people.clear();
    }

    vector<Users*> get_people() const { return people; }


    Users* get_user(short i) const { return people[i]; }

    void set_people(const std::vector<Users*>& people_) { people = people_; }

    void setName(const std::string& Name_) { Name = Name_; }
    std::string getName() const { return Name; }

    void setNumer(const std::string& Numer_) { Numer = Numer_; }
    std::string getNumer() const { return Numer; }


    static Uzond create(short size_of_people, const std::vector<std::string>& arrOfNameUrzant, const std::vector<std::string>& arrOfNames, const std::vector<std::string>& arrOfSurnames, const std::vector<std::string>& arrOfNameKindergarten, const std::vector<std::string>& arrOfWork);
    void edit();    
    void print() const;
    void save(std::ostream& out) const;
    void find(const char* keyword) const;
    __declspec(property(get = getName, put = setName)) std::string Name_property;
    __declspec(property(get = getNumer, put = setNumer)) std::string Numer_property;
    __declspec(property(get = get_people, put = set_people)) std::vector<Users*> people_property;

};

void error();

bool isalpha_r(unsigned char a);
bool isdigit_r(unsigned char a);


void show(vector<Uzond> program);
COORD getCursorPosition(void);
void Clear(int x, int y, long cnt = 100);
bool stredit(char* str, int buffer_size, int x, int y, int cursor = 0, bool clear_after = true);
void showcursor(bool flag);
void setCursorPosition(int x, int y);
COORD getConsoleSize();
COLOR GetColor();
WORD GetColorWord();
void SetColor(COLOR Color);
void print_find(char* str, short str_size, char* keyword, short key_size, int text = -1, int back = -1);

char* strstr_lower(char* str_a, char* str_b);
vector<char> stringToArrChar(const string& str);
void DeleteCh(char* str, int& cursor, int& term);
void InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);


std::istream& operator>>(Uzond*& program, std::istream& in);
std::ostream& operator<<(std::ostream& out, const Uzond& program);