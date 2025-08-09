#include <iostream>
#include <string>
#include <unordered_map>
#include "Person.h"
#include <queue>
#include <vector>
#include<algorithm>
#include <fstream>
#include "Admin.h"
using namespace std;

int main()
{
    extern unordered_map<string, Person> people;
    extern queue<Person> waitingL1, waitingL2, dose1, dose2;
    queue<Person> wL1, wL2, d1, d2;
    unordered_map<string, Person> ::iterator its;


    ifstream loadall("D:\\source\\repos\\ds\\ds\\people.txt");
    int Age;
    string ID;
    string Name;
    string Password;
    string Gender;
    string Governorate;
    bool V1;
    bool V2;
    while (loadall >> ID >> Age >> Name >> Gender >> Governorate >> Password >> V1 >> V2)
    {
        Person p = Person(ID, Age, Name, Gender, Governorate, Password, V1, V2);
        people[p.getId()] = p;
    }
    loadall.close();


    ifstream lw1("D:\\source\\repos\\ds\\ds\\Waitinglist1.txt");
    while (lw1 >> ID >> Age >> Name >> Gender >> Governorate >> Password >> V1 >> V2)
    {
        Person p = Person(ID, Age, Name, Gender, Governorate, Password, V1, V2);
        waitingL1.push(p);
    }
    lw1.close();

    ifstream lw2("D:\\source\\repos\\ds\\ds\\Waitinglist2.txt");
    while (lw2 >> ID >> Age >> Name >> Gender >> Governorate >> Password >> V1 >> V2)
    {
        Person p = Person(ID, Age, Name, Gender, Governorate, Password, V1, V2);
        waitingL2.push(p);
    }
    lw2.close();

    ifstream ld1("D:\\source\\repos\\ds\\ds\\dose1.txt");
    if (ld1) {
        while (ld1 >> ID >> Age >> Name >> Gender >> Governorate >> Password >> V1 >> V2)
        {
            Person p = Person(ID, Age, Name, Gender, Governorate, Password, V1, V2);
            dose1.push(p);
        }
    }
    ld1.close();

    ifstream ld2("D:\\source\\repos\\ds\\ds\\dose2.txt");
    if (ld2) {
        while (ld2 >> ID >> Age >> Name >> Gender >> Governorate >> Password >> V1 >> V2)
        {
            Person p = Person(ID, Age, Name, Gender, Governorate, Password, V1, V2);
            dose2.push(p);
        }
    }
    ld2.close();

    ifstream lstat("D:\\source\\repos\\ds\\ds\\stat.txt");
    int m, f, cnt1, cnt2;
    if (lstat) {
        while (lstat >> m >> f >> cnt1 >> cnt2)
        {
            mcnt = m;
            fcnt = f;
            cntv1 = cnt1;
            cntv2 = cnt2;
        }
    }
    lstat.close();

    string pass;
    int choice;
    bool isValidChoice_menu = 1;

    do {
        system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        system("cls");
        cout << "                            -----------------------------------------------------\n";
        cout << "                                            Vaccine Tracking System                           ";
        cout << "\n                            -----------------------------------------------------\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter choice: ";
        if (!isValidChoice_menu)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\n\n INVALID CHOICE!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "\n\n ENTER ANOTHER CHOICE: ";

            isValidChoice_menu = 1;
        }
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            Person::registerp();
            break;
        case 2:
            system("cls");
            Person::login();
            break;
        case 3:
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\n\n";
            cout.width(80);
            cout << "Thank you for using our system!\n\n";
            break;
        default:
            isValidChoice_menu = 0;

        }
    } while (choice != 3);



    ofstream saveall("D:\\source\\repos\\ds\\ds\\people.txt");
    for (its = people.begin(); its != people.end(); its++)
    {
        saveall << its->second.getId() << "  " << its->second.getAge() << "  " << its->second.getName() << " " << its->second.getGender()
            << " " << its->second.getGov() << "  " << its->second.getPassword() << " " << its->second.getv1() << " " << its->second.getv2() << endl;
    }
    saveall.close();

    ofstream sw1("D:\\source\\repos\\ds\\ds\\Waitinglist1.txt");
    while (!waitingL1.empty())
    {
        sw1 << waitingL1.front().getId() << "\t" << waitingL1.front().getAge() << "\t" << waitingL1.front().getName()
            << "\t" << waitingL1.front().getGender() << "\t" << waitingL1.front().getGov()
            << "\t" << waitingL1.front().getPassword()
            << "\t" << waitingL1.front().getv1() << "\t" << waitingL1.front().getv2() << endl;
        waitingL1.pop();
    }
    sw1.close();

    ofstream sw2("D:\\source\\repos\\ds\\ds\\Waitinglist2.txt");
    while (!waitingL2.empty())
    {
        sw2 << waitingL2.front().getId() << "\t" << waitingL2.front().getAge() << "\t" << waitingL2.front().getName()
            << "\t" << waitingL2.front().getGender() << "\t" << waitingL2.front().getGov()
            << "\t" << waitingL2.front().getPassword()
            << "\t" << waitingL2.front().getv1() << "\t" << waitingL2.front().getv2() << endl;
        waitingL2.pop();
    }
    sw2.close();

    ofstream sd1("D:\\source\\repos\\ds\\ds\\dose1.txt");
    while (!dose1.empty())
    {
        sd1 << dose1.front().getId() << "\t" << dose1.front().getAge() << "\t" << dose1.front().getName()
            << "\t" << dose1.front().getGender() << "\t" << dose1.front().getGov()
            << "\t" << dose1.front().getPassword()
            << "\t" << dose1.front().getv1() << "\t" << dose1.front().getv2() << endl;
        dose1.pop();
    }
    sd1.close();
    
    ofstream sd2("D:\\source\\repos\\ds\\ds\\dose2.txt");
    while (!dose2.empty())
    {
        sd2 << dose2.front().getId() << "\t" << dose2.front().getAge() << "\t" << dose2.front().getName()
            << "\t" << dose2.front().getGender() << "\t" << dose2.front().getGov()
            << "\t" << dose2.front().getPassword()
            << "\t" << dose2.front().getv1() << "\t" << dose2.front().getv2() << endl;
        dose2.pop();
    }
    sd2.close();

    ofstream savestat("D:\\source\\repos\\ds\\ds\\stat.txt");
    savestat << mcnt << "\t" << fcnt << "\t" << cntv1 << "\t" << cntv2 << endl;
    savestat.close();

    return 0;
}