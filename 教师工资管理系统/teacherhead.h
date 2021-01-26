#ifndef _TEACHERHEAD_H_
#define _TEACHERHEAD_H_
#include"class person.h"
#include<iomanip>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#define FILENAME1 "教师基本信息表.txt"
#define FILENAME2 "教师工资信息表.txt"
enum
{
    Input='1',
    Change='2',
    Search='3',
    Exit='4'
};
char menu();
void sys();
bool isexit();
char menu(Menu&m);
void input(char);
void input1();
void input2();
bool panduan(string Id);
bool panduanname(string tmp);
void showqian();
bool panduanmonth(int monthtmp,Money*tmp);
void change(char);
void change1();
void change2();
void change3();
void showmoney();
void research(char);
void research1();
void research2();
void research3();
void research4();
void mysort();
#endif // _TEACHERHEAD_H_
