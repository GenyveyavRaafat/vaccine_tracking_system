#include <string>
#include <stack>
#include "Person.h"

using namespace std;
class Admin
{
public:


    float mperc, fperc, firstperc, secperc;
    const int population = 1000;

    Admin();
    void percantages(int ch);
    static void findPerson();
    static void displayPerson();
    static void displayWaiting1();
    static void displayWaiting2();
    static void displayDose1();
    static void displayDose2();
    static void del();
    static void display_people_ordered_by_age();
    static void DeleteAll();
    static void admin_menu();
};