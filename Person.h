#pragma once
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

extern int mcnt, fcnt, cntv1, cntv2;
class Person {
private:
    int Age;
    string ID;
    string Name;
    string Password;
    string Gender;
    string Governorate;
    bool V1;
    bool V2;
public:
    Person();
    Person(string id, int age, string name, string gen, string gov, string pass, bool v1, bool v2);
    void setId(string id);
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);
    void setGov(string gov);
    void setPassword(string pas);
    void setv1(bool v1);
    void setv2(bool v2);
    string getId();
    string getName();
    int getAge();
    string getGender();
    string getGov();
    string getPassword();
    bool getv1();
    bool getv2();
    static void login();
    void display();
    static void registerp();
    static void deletep(string id);
    static void edit(string id, Person p);
};