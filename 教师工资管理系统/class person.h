#ifndef CLASS_PERSON_H_INCLUDED
#define CLASS_PERSON_H_INCLUDED
#include<iostream>
using namespace std;
#include<string>
class Person;
class Money
{
public:
    Money(string id,int monthtmp);
    ~Money();
    void change();
    Money*&getend();
    friend Person;
    friend bool panduanmonth(int monthtmp,Money*tmp);
    friend void input2();
    friend void change1();
    friend void change2();
    friend void research1();
    friend void research2();
    friend void research3();
    friend void research4();
    void showall();
    void showself();
private:
    string ID;
    int month;
    float base;
    float jin;
    float kou;
    float should;
    float fact;
    Money*next;
};
class Person
{
public:
    Person(string tmp);
    Person();
    ~Person();
    void change();
    Person*&getend();
    Person&operator=(Person&);
    friend bool panduan(string Id);
    friend void input1();
    friend void input2();
    friend Money;
    friend void change1();
    friend void change2();
    friend void change3();
    friend void research1();
    friend void research2();
    friend void research3();
    friend void research4();
    friend void mysort();
    friend bool panduanname(string tmp);
    void showall();
    void showself();
    void del(Person*p);
private:
    string id;
    string name;
    string school;
    string job;
    Money*money;
    Person *next;
};
class Menu
{
public:
    virtual void menu();
    virtual char choose();
};
class Menuinput:public Menu
{
public:
    virtual void menu();
    virtual char choose();
};
class Menuchange:public Menu
{
public:
    virtual void menu();
    virtual char choose();
};
class Menusearch:public Menu
{
public:
    virtual void menu();
    virtual char choose();
};
class Menuanaly:public Menu
{
public:
    virtual void menu();
    virtual char choose();
};
#endif // CLASS_PERSON_H_INCLUDED
