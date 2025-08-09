#include "Admin.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include<fstream>

using namespace std;

unordered_map<string, Person> people;
queue<Person> waitingL1, waitingL2, dose1, dose2;
queue<Person> t1, t2, t3, t4;
int mcnt = 0, fcnt = 0, cntv1 = 0, cntv2 = 0;

Person::Person() {
}

Person::Person(string id, int age, string name, string gen, string gov, string pass, bool v1, bool v2) : ID(id), Age(age), Name(name), Gender(gen), Governorate(gov), Password(pass), V1(v1), V2(v2)
{
}
void Person::setId(string id)
{
    ID = id;
}
void Person::setName(string name)
{
    Name = name;
}
void Person::setAge(int age)
{
    Age = age;
}
void Person::setGender(string gender)
{
    Gender = gender;
}
void Person::setGov(string gov)
{
    Governorate = gov;
}
void Person::setPassword(string pas)
{
    Password = pas;
}
void Person::setv1(bool v1)
{
    V1 = v1;
}
void Person::setv2(bool v2)
{
    V2 = v2;
}
string Person::getId()
{
    return ID;
}
string Person::getName()
{
    return Name;
}
int Person::getAge()
{
    return Age;
}
string Person::getGender()
{
    return Gender;
}
string Person::getGov()
{
    return Governorate;
}
string Person::getPassword()
{
    return Password;
}
bool Person::getv1()
{
    return V1;
}
bool Person::getv2()
{
    return V2;
}

void Person::display()
{
    cout << ID << "\t" << Age << "\t" << Name << "\t" << Gender << "\t" << Governorate << "\t\t" <<
        Password << "\t\t" << V1 << "\t" << V2 << endl;
}

void Person::registerp()
{
    int  age;
    bool v1, v2;
    string id, name, gend, govr, pass;

    cout << "Enter ID: ";
    bool found = true;
    while (found) {
        cin >> id;
        auto it = people.find(id);
        if (it != people.end()) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nThis ID Already Exist Please Enter Another ID\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            continue;
        }
        else
            found = false;
    }
    cout << "\nEnter your Password: ";
    cin >> pass;

    cout << "\nEnter Your Name: ";
    cin >> name;

    cout << "\nEnter Your Age: ";
    cin >> age;

    cout << "\nEnter your Gender: (->Press 1 For Male OR ->Press 2 For Female)" << endl;
    int cnum;
    bool check = true;
    while (check) {
        check = false;
        cin >> cnum;
        if (cnum == 1) {
            gend = "male";
            mcnt++;
        }
        else if (cnum == 2) {

            gend = "female";
            fcnt++;
        }
        else {
            cout << "Please Enter 1 or 2" << endl;
            cout << "Enter 1 For male and 2 For female" << endl;
            check = true;
            continue;
        }
    }

    cout << "Enter your Governorate: ";
    cin >> govr;

    int vnum;
    bool vac = true;
    while (vac) {
        cout << "\nAlready Vaccinated Or Applying For Vaccination ?\n1- Applying\n2- Already Vaccinated" << endl;
        vac = false;
        cin >> vnum;
        if (vnum == 1) {
            v1 = false;
            v2 = false;
        }
        else if (vnum == 2) {
            cout << "Received One Dose Or The Two Doses?\n->Press 1 For 1 Dose\n->Press 2 For Both" << endl;
            bool d1 = true;
            int dnum;
            while (d1) {
                d1 = false;
                cin >> dnum;
                if (dnum == 1) {
                    v1 = true;
                    v2 = false;
                }
                else if (dnum == 2) {
                    v1 = true;
                    v2 = true;
                }
                else {
                    cout << "Please Enter 1 or 2" << endl;
                    cout << "Received One Dose Or The Two Doses? \n->Press  1 For 1 Dose \n->Press  2 For Both" << endl;
                    d1 = true;
                    continue;
                }
            }
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\n\n INVALID CHOICE!!\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "Please Enter 1 or 2" << endl;
            vac = true;
            continue;
        }
    }

    Person p(id, age, name, gend, govr, pass, v1, v2);
    people[id] = p;
    if (v1 == false && v2 == false) {
        waitingL1.push(p);
    }
    else if (v1 == true && v2 == false) {
        cntv1++;
        dose1.push(p);
        waitingL2.push(p);
    }
    else if (v1 == true && v2 == true) {
        cntv1++;
        cntv2++;
        dose1.push(p);
        dose2.push(p);
    }
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\n    You Have been Added to The System" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    system("pause");
}
void Person::login()
{
    string id, pass;
    char c;
    cout << "ENTER YOUR ID : " << endl;
    cin >> id;
    cout << "Enter your password: ";
    while ((c = _getch()) != '\r') {

        if (c == '\b') {
            if (!pass.empty()) {
                pass.pop_back();
                std::cout << "\b \b";
            }
        }
        else {
            pass.push_back(c);
            cout << "*";
        }
    }
    if (id == "admin" && pass == "admin")
    {
        Admin::admin_menu();
    }
    else
    {
        int x;
        auto it = people.find(id);
        if (it != people.end() && pass == it->second.getPassword()) {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nLogin Successful\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            system("pause");

            bool check = true;
            while (check) {
                system("cls");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                cout << "That's Your info " << it->second.getName() << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

                it->second.display();

                cout << "\n-> If YOU WANT TO EDIT YOUR INFO ENTER 1 " << endl;
                cout << "\n-> IF YOU WANT TO DELETE YOUR PROFILE ENTER 2 " << endl;
                cout << "\n->LOG OUT ENTER 3 " << endl;

                check = false;
                cin >> x;
                if (x == 1) {
                    int y;
                    bool checkk = true;
                    while (checkk) {
                        system("cls");
                        cout << "TO EDIT YOUR NAME ENTER 1 \n\n";
                        cout << "TO EDIT YOUR AGE ENTER 2 \n\n";
                        cout << "TO EDIT YOUR Governorate ENTER 3 \n\n";
                        cout << "TO EDIT YOUR GENDER ENTER 4  \n\n";
                        cout << "TO EDIT YOUR ID ENTER 5 \n\n";
                        cout << "TO EDIT YOUR PASSWORD ENTER 6 \n\n";

                        checkk = false;
                        cin >> y;
                        if (y == 1) {
                            system("cls");
                            cout << "ENTER YOUR NEW NAME : " << endl;
                            string namee;
                            cin >> namee;
                            if (namee == it->second.Name)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                cout << "This is Your Current Name" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            else
                            {
                                it->second.setName(namee);
                                Person p(it->second.ID, it->second.Age, namee, it->second.Gender, it->second.Governorate, it->second.Password,
                                    it->second.V1, it->second.V2);
                                Person::edit(id, p);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                cout << "\n    Your Name Have been Updated" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            system("pause");
                            check = true;
                        }
                        else if (y == 2) {
                            system("cls");
                            cout << "ENTER YOUR NEW AGE : " << endl;
                            int agee;
                            cin >> agee;
                            if (agee == it->second.Age)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                cout << "This is Your Current Age" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            else
                            {
                                it->second.setAge(agee);
                                Person p(it->second.ID, agee, it->second.Name, it->second.Gender, it->second.Governorate, it->second.Password,
                                    it->second.V1, it->second.V2);
                                Person::edit(id, p);

                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                cout << "\n    Your AGE Have been Updated" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            system("pause");
                            check = true;
                        }
                        else if (y == 3)
                        {
                            system("cls");
                            cout << "ENTER YOUR NEW Governorate : " << endl;
                            string gove;
                            cin >> gove;
                            if (gove == it->second.Governorate)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                cout << "This Is Your Current Governorate" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            else
                            {
                                it->second.setGov(gove);
                                Person p(it->second.ID, it->second.Age, it->second.Name, it->second.Gender, gove, it->second.Password,
                                    it->second.V1, it->second.V2);
                                Person::edit(id, p);

                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                cout << "\n    Your Governorate Have been Updated" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            system("pause");
                            check = true;

                        }
                        else if (y == 4)
                        {
                            system("cls");
                            cout << "ENTER YOUR NEW GENDER : " << endl;
                            string g;
                            cout << "Enter male or female" << endl;
                            bool checkk = true;
                            while (checkk) {
                                checkk = false;
                                cin >> g;
                                if (g == it->second.Gender)
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    cout << "\n    This Is Your Current Gender" << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                }
                                else if (g == "female") {
                                    it->second.setGender(g);
                                    fcnt++;
                                    mcnt--;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                    cout << "\n    Your Gender Have Been Updated" << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                }
                                else if (g == "male") {
                                    it->second.setGender(g);
                                    mcnt++;
                                    fcnt--;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                    cout << "\n    Your Gender Have Been Updated" << endl;
                                }
                                else {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    cout << "\n\n INVALID CHOICE!!\n";
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

                                    cout << "Enter male or female" << endl;
                                    checkk = true;
                                    continue;
                                }
                            }
                            Person p(it->second.ID, it->second.Age, it->second.Name, g, it->second.Governorate, it->second.Password,
                                it->second.V1, it->second.V2);
                            Person::edit(id, p);
                            system("pause");
                            check = true;
                        }
                        else if (y == 5)
                        {
                            system("cls");
                            cout << "ENTER YOUR NEW ID : " << endl;
                            string idd, gen, namee, gov, pass;
                            int agee;
                            bool v11, v22, found = true;
                            while (found) {
                                cin >> idd;
                                auto it = people.find(idd);
                                if (it != people.end()) {

                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                    cout << "This ID Already Exist Please Enter Another ID" << endl;
                                    continue;
                                }
                                else
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                    cout << "\n    Your ID Have been Updated" << endl;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                                    found = false;
                                }
                            }
                            agee = it->second.Age;
                            namee = it->second.Name;
                            gen = it->second.Gender;
                            gov = it->second.Governorate;
                            pass = it->second.Password;
                            v11 = it->second.V1;
                            v22 = it->second.V2;
                            Person p(idd, agee, namee, gen, gov, pass, v11, v22);
                            edit(id, p);
                            people.erase(it);
                            people[idd] = p;
                        }
                        else if (y == 6)
                        {
                            system("cls");
                            cout << "ENTER YOUR NEW PASSWORD : " << endl;
                            string pass;
                            cin >> pass;
                            if (pass == it->second.Password)
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                                cout << "This is Your Current Password" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                            else
                            {
                                it->second.setPassword(pass);
                                Person p(it->second.ID, it->second.Age, it->second.Name, it->second.Gender, it->second.Governorate, pass,
                                    it->second.V1, it->second.V2);
                                Person::edit(id, p);

                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                                cout << "\n    Your Password Have been Updated" << endl;
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                            }
                        }
                        else {
                            checkk = true;
                            continue;
                        }
                    }
                }
                else if (x == 2)
                {
                    Person::deletep(id);
                    people.erase(it);

                }
                else if (x == 3) {
                    system("cls");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
                    cout << "\n    logged out!! \n";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    break;
                }
                else {
                    check = true;
                    continue;
                }
            }
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "\n\nInvalid ID or password. Please try again.\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        system("pause");
    }
}
void Person::deletep(string id)
{
    auto it = people.find(id);
    while (!waitingL1.empty())
    {
        Person p = waitingL1.front();

        if (it->second.ID == p.ID)
        {
            waitingL1.pop();
            continue;
        }
        else
        {
            t1.push(p);
            waitingL1.pop();
        }
    }
    while (!t1.empty())
    {
        Person p = t1.front();
        waitingL1.push(p);
        t1.pop();

    }


    while (!waitingL2.empty())
    {
        Person p = waitingL2.front();

        if (it->second.ID == p.ID)
        {
            waitingL2.pop();
            continue;
        }
        else
        {
            t2.push(p);
            waitingL2.pop();
        }
    }
    while (!t2.empty())
    {
        Person p = t2.front();
        waitingL2.push(p);
        t2.pop();

    }

    while (!dose1.empty())
    {
        Person p = dose1.front();

        if (it->second.ID == p.ID)
        {
            dose1.pop();
            continue;
        }
        else
        {
            t3.push(p);
            dose1.pop();
        }
    }
    while (!t3.empty())
    {
        Person p = t3.front();
        dose1.push(p);
        t3.pop();

    }

    while (!dose2.empty())
    {
        Person p = dose2.front();

        if (it->second.ID == p.ID)
        {
            dose2.pop();
            continue;
        }
        else
        {
            t4.push(p);
            dose2.pop();
        }
    }
    while (!t4.empty())
    {
        Person p = t4.front();
        dose2.push(p);
        t4.pop();

    }
    if (it->second.Gender == "female")
    {
        fcnt--;
    }
    else if (it->second.Gender == "male")
    {
        mcnt--;
    }
    if (it->second.V1 == 1 && it->second.V2 == 0)
    {
        cntv1--;
    }
    else if (it->second.V2 == 1 && it->second.V1 == 1)
    {
        cntv2--;
        cntv1--;
    }
}
void Person::edit(string id, Person p)
{

    auto it = people.find(id);
    Person p2;
    while (!waitingL1.empty())
    {
        p2 = waitingL1.front();

        if (it->second.ID == p2.ID)
        {
            break;
        }
        else
        {
            t1.push(p2);
            waitingL1.pop();
        }
    }
    if (!waitingL1.empty()) {
        Person& temp = waitingL1.front();
        temp = p;
    }
    while (!waitingL1.empty())
    {
        t1.push(waitingL1.front());
        waitingL1.pop();
    }
    while (!t1.empty())
    {
        waitingL1.push(t1.front());
        t1.pop();
    }

    //
    while (!waitingL2.empty())
    {
        p2 = waitingL2.front();

        if (it->second.ID == p2.ID)
        {
            break;
        }
        else
        {
            t2.push(p2);
            waitingL2.pop();
        }

    }
    if (!waitingL2.empty()) {
        Person& temp2 = waitingL2.front();
        temp2 = p;
    }
    while (!waitingL2.empty())
    {
        t2.push(waitingL2.front());
        waitingL2.pop();

    }
    while (!t2.empty())
    {
        waitingL2.push(t2.front());
        t2.pop();
    }
    ///

    while (!dose1.empty())
    {
        p2 = dose1.front();

        if (it->second.ID == p2.ID)
        {
            break;
        }
        else
        {
            t3.push(p2);
            dose1.pop();
        }

    }
    if (!dose1.empty()) {
        Person& temp3 = dose1.front();
        temp3 = p;
    }
    while (!dose1.empty())
    {
        t3.push(dose1.front());
        dose1.pop();

    }
    while (!t3.empty())
    {
        dose1.push(t3.front());
        t3.pop();
    }

    ///

    while (!dose2.empty())
    {
        p2 = dose2.front();

        if (it->second.ID == p2.ID)
        {
            break;
        }
        else
        {
            t4.push(p2);
            dose2.pop();
        }

    }
    if (!dose2.empty()) {
        Person& temp4 = dose2.front();
        temp4 = p;
    }
    while (!dose2.empty())
    {
        t4.push(dose2.front());
        dose2.pop();

    }
    while (!t4.empty())
    {
        dose2.push(t4.front());
        t4.pop();
    }

}