#include"teacherhead.h"
void Menu::menu()
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"**************  教师工资管理系统 ***************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"**************  [1]录入教师数据  ***************"<<endl;
    cout<<"**************  [2]修改教师数据  ***************"<<endl;
    cout<<"**************  [3]查询显示数据  ***************"<<endl;
    cout<<"**************  [4]退出管理系统  ***************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menu::choose()
{
        while(1)
    {
        cout<<"请输入1~4之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else if(choose=="4")
            return '4';
        else
            continue;
    }
}
void Menuinput::menu()
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"************    教师工资管理系统   *************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"************  [1]录入教师基本信息  *************"<<endl;
    cout<<"************  [2]录入教师工资信息  *************"<<endl;
    cout<<"************  [3]  返回一级菜单    *************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menuinput::choose()
{
        while(1)
    {
        cout<<"请输入1~3之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else
            continue;
    }
}
void Menuchange::menu()
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********        教师工资管理系统       *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********    [1]根据工号修改教师信息    *********"<<endl;
    cout<<"********    [2]根据姓名修改教师信息    *********"<<endl;
    cout<<"********    [3]删除某一工号教师信息    *********"<<endl;
    cout<<"********    [4]   返回一级菜单         *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menuchange::choose()
{
        while(1)
    {
        cout<<"请输入1~4之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else if(choose=="4")
            return '4';
        else
            continue;
    }
}
void Menusearch::menu()
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********        教师工资管理系统       *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********    [1]根据工号查询教师信息    *********"<<endl;
    cout<<"********    [2]根据姓名查询教师信息    *********"<<endl;
    cout<<"********    [3]根据月份显示工资信息    *********"<<endl;
    cout<<"********    [4]显示所有教师基本信息    *********"<<endl;
    cout<<"********    [5]   返回一级菜单         *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menusearch::choose()
{
        while(1)
    {
        cout<<"请输入1~5之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else if(choose=="4")
            return '4';
        else if(choose=="5")
            return '5';

        else
            continue;
    }
}
void Menuanaly::menu()
{
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"************         教师工资管理系统        *************"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"************  [1]按月份统计不同学院教师工资  *************"<<endl;
    cout<<"************  [2]按月份统计不同职称教师工资  *************"<<endl;
    cout<<"************  [3]       返回一级菜单         *************"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

}
char Menuanaly::choose()
{
        while(1)
    {
        cout<<"请输入1~3之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else
            continue;
    }
}
char choose()
{
        while(1)
    {
        cout<<"请输入1~4之间的数字:";
        string choose;
        cin>>choose;
        if(choose=="1")
            return '1';
        else if(choose=="2")
            return '2';
        else if(choose=="3")
            return '3';
        else if(choose=="4")
            return '4';
        else
            continue;
    }
}
Money::Money(string id,int monthtmp)
{
    next=NULL;
    ID=id;
    month=monthtmp;
    cout<<"请输入基本工资:";
    cin>>base;
    cout<<"请输入业绩津贴:";
    cin>>jin;
    cout<<"请输入扣除费用:";
    cin>>kou;
    should=base+jin;
    fact=should-kou;
}
Money::~Money()
{
    if(next)
        delete next;
}
void Money::showall()
{
    cout<<setiosflags(ios::left)<<setw(20)<<ID;
    cout<<setiosflags(ios::left)<<setw(20)<<month;
    cout<<setiosflags(ios::left)<<setw(20)<<base;
    cout<<setiosflags(ios::left)<<setw(20)<<jin;
    cout<<setiosflags(ios::left)<<setw(20)<<kou;
    cout<<setiosflags(ios::left)<<setw(20)<<should;
    cout<<setiosflags(ios::left)<<setw(20)<<fact<<endl;
    if(next)
       next->showall();
}
Money*&Money::getend()
{
    if(next)
        return next->getend();
    else
        return next;
}
void Money::change()
{
    cout<<"请输入基本工资:";
    cin>>base;
    cout<<"请输入业绩津贴:";
    cin>>jin;
    cout<<"请输入扣除费用:";
    cin>>kou;
    should=base+jin;
    fact=should-kou;
    cout<<"修改成功"<<endl;
}
void Money::showself()
{
    cout<<setiosflags(ios::left)<<setw(20)<<ID;
    cout<<setiosflags(ios::left)<<setw(20)<<month;
    cout<<setiosflags(ios::left)<<setw(20)<<base;
    cout<<setiosflags(ios::left)<<setw(20)<<jin;
    cout<<setiosflags(ios::left)<<setw(20)<<kou;
    cout<<setiosflags(ios::left)<<setw(20)<<should;
    cout<<setiosflags(ios::left)<<setw(20)<<fact<<endl;
}
//    string ID;
//    int month;
//    float base;
//    float jin;
//    float kou;
//    float should;
//    float fact;
//    Money*next;
Person::Person(string tmp)
{
    next=NULL;
    money=NULL;
    id=tmp;
    cout<<"请输入教师的姓名:";
    cin>>name;
    cout<<"请选择教师的学院:[1]信工学院[2]数统学院[3]法学院[4]审计学院"<<endl;
    switch(choose())
    {
    case '1':
        school="信工学院";
        break;
    case '2':
        school="数统学院";
        break;
    case '3':
        school="法学院";
        break;
    case '4':
        school="审计学院";
        break;
    }
    cout<<"请选择教师的职称:[1]教授[2]副教授[3]讲师[4]助教"<<endl;
    switch(choose())
    {
    case '1':
        job="教授";
        break;
    case '2':
        job="副教授";
        break;
    case '3':
        job="讲师";
        break;
    case '4':
        job="助教";
        break;
    }
    cout<<"录入成功"<<endl;
}
Person::~Person()
{
    if(next)
        delete next;
    if(money)
        delete money;
}
Person*& Person::getend()
{
    if(!next)
        return next;
    else
        return next->getend();
}
void Person::showall()
{
    cout<<setiosflags(ios::left)<<setw(20)<<id;
    cout<<setiosflags(ios::left)<<setw(20)<<name;
    cout<<setiosflags(ios::left)<<setw(20)<<school;
    cout<<setiosflags(ios::left)<<setw(20)<<job<<endl;
    if(next)
        next->showall();
}
void Person::showself()
{
    cout<<setiosflags(ios::left)<<setw(20)<<id;
    cout<<setiosflags(ios::left)<<setw(20)<<name;
    cout<<setiosflags(ios::left)<<setw(20)<<school;
    cout<<setiosflags(ios::left)<<setw(20)<<job<<endl;
}
void Person::change()
{
    cout<<"请输入教师的姓名:";
    cin>>name;
    cout<<"请选择教师的学院:[1]信工学院[2]数统学院[3]法学院[4]审计学院"<<endl;
    switch(choose())
    {
    case '1':
        school="信工学院";
        break;
    case '2':
        school="数统学院";
        break;
    case '3':
        school="法学院";
        break;
    case '4':
        school="审计学院";
        break;
    }
    cout<<"请选择教师的职称:[1]教授[2]副教授[3]讲师[4]助教"<<endl;
    switch(choose())
    {
    case '1':
        job="教授";
        break;
    case '2':
        job="副教授";
        break;
    case '3':
        job="讲师";
        break;
    case '4':
        job="助教";
        break;
    }
    cout<<"修改成功"<<endl;

}
void Person::del(Person*p)
{
    Person*tmp=this;
    p->next=this->next;
    tmp->next=NULL;
    delete tmp;
    cout<<"删除成功"<<endl;
}
Person&Person::operator=(Person&p)
{
    id=p.id;
    name=p.name;
    school=p.school;
    job=p.job;
    money=p.money;
    return *this;
}
Person::Person()
{

}
//    string id;
//    string name;
//    string school;
//    string job;
//。教师的基本信息包括：工号、姓名、学院、职称，职称分为：教授、副教授、讲师、助教。
//教师的工资信息包括：工号、月份、基本工资、业绩津贴、扣除费用、应发工资、实发工资，不同职称教师的基本工资、业绩津贴、扣除费用不同
