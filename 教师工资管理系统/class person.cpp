#include"teacherhead.h"
void Menu::menu()
{
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"**************  ��ʦ���ʹ���ϵͳ ***************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"**************  [1]¼���ʦ����  ***************"<<endl;
    cout<<"**************  [2]�޸Ľ�ʦ����  ***************"<<endl;
    cout<<"**************  [3]��ѯ��ʾ����  ***************"<<endl;
    cout<<"**************  [4]�˳�����ϵͳ  ***************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menu::choose()
{
        while(1)
    {
        cout<<"������1~4֮�������:";
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
    cout<<"************    ��ʦ���ʹ���ϵͳ   *************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"************  [1]¼���ʦ������Ϣ  *************"<<endl;
    cout<<"************  [2]¼���ʦ������Ϣ  *************"<<endl;
    cout<<"************  [3]  ����һ���˵�    *************"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menuinput::choose()
{
        while(1)
    {
        cout<<"������1~3֮�������:";
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
    cout<<"********        ��ʦ���ʹ���ϵͳ       *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********    [1]���ݹ����޸Ľ�ʦ��Ϣ    *********"<<endl;
    cout<<"********    [2]���������޸Ľ�ʦ��Ϣ    *********"<<endl;
    cout<<"********    [3]ɾ��ĳһ���Ž�ʦ��Ϣ    *********"<<endl;
    cout<<"********    [4]   ����һ���˵�         *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menuchange::choose()
{
        while(1)
    {
        cout<<"������1~4֮�������:";
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
    cout<<"********        ��ʦ���ʹ���ϵͳ       *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"********    [1]���ݹ��Ų�ѯ��ʦ��Ϣ    *********"<<endl;
    cout<<"********    [2]����������ѯ��ʦ��Ϣ    *********"<<endl;
    cout<<"********    [3]�����·���ʾ������Ϣ    *********"<<endl;
    cout<<"********    [4]��ʾ���н�ʦ������Ϣ    *********"<<endl;
    cout<<"********    [5]   ����һ���˵�         *********"<<endl;
    cout<<"************************************************"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

}
char Menusearch::choose()
{
        while(1)
    {
        cout<<"������1~5֮�������:";
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
    cout<<"************         ��ʦ���ʹ���ϵͳ        *************"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"************  [1]���·�ͳ�Ʋ�ͬѧԺ��ʦ����  *************"<<endl;
    cout<<"************  [2]���·�ͳ�Ʋ�ְͬ�ƽ�ʦ����  *************"<<endl;
    cout<<"************  [3]       ����һ���˵�         *************"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

}
char Menuanaly::choose()
{
        while(1)
    {
        cout<<"������1~3֮�������:";
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
        cout<<"������1~4֮�������:";
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
    cout<<"�������������:";
    cin>>base;
    cout<<"������ҵ������:";
    cin>>jin;
    cout<<"������۳�����:";
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
    cout<<"�������������:";
    cin>>base;
    cout<<"������ҵ������:";
    cin>>jin;
    cout<<"������۳�����:";
    cin>>kou;
    should=base+jin;
    fact=should-kou;
    cout<<"�޸ĳɹ�"<<endl;
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
    cout<<"�������ʦ������:";
    cin>>name;
    cout<<"��ѡ���ʦ��ѧԺ:[1]�Ź�ѧԺ[2]��ͳѧԺ[3]��ѧԺ[4]���ѧԺ"<<endl;
    switch(choose())
    {
    case '1':
        school="�Ź�ѧԺ";
        break;
    case '2':
        school="��ͳѧԺ";
        break;
    case '3':
        school="��ѧԺ";
        break;
    case '4':
        school="���ѧԺ";
        break;
    }
    cout<<"��ѡ���ʦ��ְ��:[1]����[2]������[3]��ʦ[4]����"<<endl;
    switch(choose())
    {
    case '1':
        job="����";
        break;
    case '2':
        job="������";
        break;
    case '3':
        job="��ʦ";
        break;
    case '4':
        job="����";
        break;
    }
    cout<<"¼��ɹ�"<<endl;
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
    cout<<"�������ʦ������:";
    cin>>name;
    cout<<"��ѡ���ʦ��ѧԺ:[1]�Ź�ѧԺ[2]��ͳѧԺ[3]��ѧԺ[4]���ѧԺ"<<endl;
    switch(choose())
    {
    case '1':
        school="�Ź�ѧԺ";
        break;
    case '2':
        school="��ͳѧԺ";
        break;
    case '3':
        school="��ѧԺ";
        break;
    case '4':
        school="���ѧԺ";
        break;
    }
    cout<<"��ѡ���ʦ��ְ��:[1]����[2]������[3]��ʦ[4]����"<<endl;
    switch(choose())
    {
    case '1':
        job="����";
        break;
    case '2':
        job="������";
        break;
    case '3':
        job="��ʦ";
        break;
    case '4':
        job="����";
        break;
    }
    cout<<"�޸ĳɹ�"<<endl;

}
void Person::del(Person*p)
{
    Person*tmp=this;
    p->next=this->next;
    tmp->next=NULL;
    delete tmp;
    cout<<"ɾ���ɹ�"<<endl;
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
//����ʦ�Ļ�����Ϣ���������š�������ѧԺ��ְ�ƣ�ְ�Ʒ�Ϊ�����ڡ������ڡ���ʦ�����̡�
//��ʦ�Ĺ�����Ϣ���������š��·ݡ��������ʡ�ҵ���������۳����á�Ӧ�����ʡ�ʵ�����ʣ���ְͬ�ƽ�ʦ�Ļ������ʡ�ҵ���������۳����ò�ͬ
