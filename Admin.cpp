#include "Admin.h"
#include "Person.h"
#include <queue>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>


using namespace std;
extern unordered_map<string, Person> people;
extern queue<Person> waitingL1, waitingL2, dose1, dose2;
queue<Person> wL1, wL2, d1, d2;

Admin::Admin() {
    cout << "\nWELCOME TO ADMIN DASHBOARD" << endl;
}
void Admin::Admin::percantages(int ch) {
    if (ch == 1) {
        mperc = (float(mcnt) / population) * 100;
        cout << "Male percentage: " << mperc << "%" << endl;
    }
    else if (ch == 2) {
        fperc = (float(fcnt) / population) * 100;
        cout << "Female percentage: " << fperc << "%" << endl;
    }
    else if (ch == 3) {
        firstperc = (float(cntv1) / population) * 100;
        cout << "First dose percentage: " << firstperc << "%" << endl;
    }
    else if (ch == 4) {
        secperc = (float(cntv2) / population) * 100;
        cout << "Second dose percentage: " << secperc << "%" << endl;
    }
}
void Admin::findPerson() {
    string id, t = "1";
    while (t == "1")
    {
        cout << "Enter ID to search for: ";
        cin >> id;

        auto it = people.find(id);
        if (it != people.end()) {
            cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
            it->second.display();
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            cout << "\nPerson Not Found." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        }
        cout << "\n\n\n  -> Press 1 If You Want to Try Another ID." << endl;
        cout << "\n  -> Press Anything else If You Don't." << endl;
        cin >> t;

    }
}
void Admin::displayPerson() {
    if (people.empty())
    {
        cout << "No Users Found" << endl;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << "DATA OF USERS : " << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

        cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------- \n";

        unordered_map<string, Person> ::iterator itt;
        for (itt = people.begin(); itt != people.end(); itt++)
        {

            cout << itt->second.getId() << "\t" << itt->second.getAge() << "\t" << itt->second.getName() << "\t"
                << itt->second.getGender() << "\t" << itt->second.getGov() << "\t\t"
                << itt->second.getPassword() << "\t\t" << itt->second.getv1() << "\t"
                << itt->second.getv2() << endl;

        }
        cout << endl;
    }
    system("pause");
}
void Admin::displayWaiting1() {
    if (waitingL1.empty())
    {
        cout << "No One In The Waiting List " << endl;
    }
    else
    {
        cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------- \n";
        while (!waitingL1.empty()) {
            Person p = waitingL1.front();
            wL1.push(p);
            p.display();
            waitingL1.pop();
        }

        while (!wL1.empty())
        {
            Person p2 = wL1.front();
            waitingL1.push(p2);
            wL1.pop();
        }
    }
    system("pause");
}
void Admin::displayWaiting2() {
    if (waitingL2.empty())
    {
        cout << "No One In The Waiting List " << endl;
    }
    else
    {
        cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------- \n";
        while (!waitingL2.empty()) {
            Person p2 = waitingL2.front();
            wL2.push(p2);
            p2.display();
            waitingL2.pop();
        }

        while (!wL2.empty())
        {
            Person p2 = wL2.front();
            waitingL2.push(wL2.front());
            wL2.pop();
        }
    }
    system("pause");
}
void Admin::displayDose1()
{
    if (dose1.empty())
    {
        cout << "No One Took Dose 1" << endl;
    }
    else
    {
        cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------- \n";
        while (!dose1.empty()) {
            Person p2 = dose1.front();
            d1.push(p2);
            p2.display();
            dose1.pop();
        }

        while (!d1.empty())
        {
            Person p2 = d1.front();
            dose1.push(d1.front());
            d1.pop();
        }
    }
    system("pause");
}
void Admin::displayDose2()
{
    if (dose2.empty())
    {
        cout << "No One Took Dose 2" << endl;
    }
    else
    {
        cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------- \n";
        while (!dose2.empty()) {
            Person p2 = dose2.front();
            d2.push(p2);
            p2.display();
            dose2.pop();
        }

        while (!d2.empty())
        {
            Person p2 = d2.front();
            dose2.push(d2.front());
            d2.pop();
        }
    }
    system("pause");
}
void Admin::del()
{
    queue<Person> t1, t2, t3, t4;
    string id;
    cout << "Enter The ID Of The Account You Want To Delete " << endl;
    cin >> id;
    auto it = people.find(id);
    if (it != people.end())
    {
        while (!waitingL1.empty())
        {
            Person p = waitingL1.front();

            if (it->second.getId() == p.getId())
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

            if (it->second.getId() == p.getId())
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

            if (it->second.getId() == p.getId())
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

            if (it->second.getId() == p.getId())
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
        if (it->second.getGender() == "female")
        {
            fcnt--;
        }
        else if (it->second.getGender() == "male")
        {
            mcnt--;
        }
        if (it->second.getv1() == 1 && it->second.getv2() == 0)
        {
            cntv1--;
        }
        else if (it->second.getv2() == 1 && it->second.getv1() == 1)
        {
            cntv2--;
            cntv1--;
        }
        people.erase(it);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << "\nPerson has been deleted." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    }
    else
    {
        cout << "Invalid ID " << endl;
    }
    system("pause");
}
void Admin::display_people_ordered_by_age()
{
    vector<pair<string, Person>> people_vec;
    for (auto kv : people) {
        people_vec.push_back(kv);
    }
    sort(people_vec.begin(), people_vec.end(), [](pair<string, Person>& p1, pair<string, Person>& p2) {
        return p1.second.getAge() < p2.second.getAge();
        });

    cout << "ID\tAGE\tName\tGender\tGovernorate\tPassword\tDose1\tDose2" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------- \n";
    for (auto it = people_vec.begin(); it != people_vec.end(); ++it) {
        it->second.display();

    }
    system("pause");
}
void Admin::DeleteAll()
{
    people.clear();
    while (!waitingL1.empty())
    {
        waitingL1.pop();
    }
    while (!waitingL2.empty())
    {
        waitingL2.pop();
    }
    while (!dose1.empty())
    {
        dose1.pop();
    }
    while (!dose2.empty())
    {
        dose2.pop();
    }
    cntv1 = 0, cntv1 = 0, fcnt = 0, mcnt = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "\nAll the recorders have been deleted." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    system("pause");
}
void Admin::admin_menu()
{
    int ch;
    Admin a;

    do {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << "\t\t============================================" << endl;
        cout << "\t\t|          Administator Portal              |" << endl;
        cout << "\t\t============================================" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "1. Find Person" << endl;
        cout << "2. Display all" << endl;
        cout << "3. Display waiting list for first dose" << endl;
        cout << "4. Display waiting list for second dose" << endl;
        cout << "5. Display The list For First Dose" << endl;
        cout << "6. Display The list For Second Dose" << endl;
        cout << "7. To Delete a Profile" << endl;
        cout << "8. To Delete All Profiles" << endl;
        cout << "9. Display Statistics" << endl;
        cout << "10. To Display Persons Ordered By Age" << endl;
        cout << "11. Exit Admin Dashboard" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            findPerson();
            break;
        case 2:
            system("cls");
            displayPerson();
            break;
        case 3:
            system("cls");
            displayWaiting1();
            break;
        case 4:
            system("cls");
            displayWaiting2();
            break;
        case 5:
            system("cls");
            displayDose1();
            break;
        case 6:
            system("cls");
            displayDose2();
            break;
        case 7:
            system("cls");
            del();
            break;
        case 8:
            system("cls");
            DeleteAll();
            break;
        case 9:
            system("cls");
            cout << "-> Press 1 For Male Percentage\n-> Press 2 For Female Percentage\n-> Press 3 For First Dose Percentage\n-> Press 4 For Second Dose Percentage" << endl;
            int cho;
            cin >> cho;
            switch (cho)
            {
            case 1:
                a.percantages(1);
                system("pause");
                break;
            case 2:
                a.percantages(2);
                system("pause");
                break;
            case 3:
                a.percantages(3);
                system("pause");
                break;
            case 4:
                a.percantages(4);
                system("pause");
                break;
            default:
                break;
            }
            break;
        case 10:
            system("cls");
            display_people_ordered_by_age();
            break;

        default:
            break;
        }
    } while (ch != 11);
}