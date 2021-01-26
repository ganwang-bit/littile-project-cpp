#include"teacherhead.h"
bool Empty=true;
Person *Head;
void sys()
{
    system("pause");
    system("cls");
    Sleep(200);
}
bool isexit()
{
    string n;
    cout<<"确认是否退出"<<endl;
    while(1)
    {
        cout<<"确认请输入Y/y 取消请输入N/n:";
        cin>>n;
        if(n=="y"||n=="Y")
            return true;
        else if(n=="N"||n=="n")
            return false;
        else
            continue;
    }
}
char menu(Menu&m)
{
    m.menu();
    char tmp=m.choose();
    return tmp;
}
void input1()
{
    string tmp;
    cout<<"请输入教师的工号:";
    cin>>tmp;
    if(Empty)
    {
        Empty=false;
        Head=new Person(tmp);
    }
    else
    {
        if(panduan(tmp))
            cout<<"工号为"<<tmp<<"的教师信息已录入"<<endl;
        else
        {
            Person*&End=Head->getend();
            End=new Person(tmp);
        }
    }
}
void showqian()
{
    cout<<setiosflags(ios::left)<<setw(20)<<"工号";
    cout<<setiosflags(ios::left)<<setw(20)<<"姓名";
    cout<<setiosflags(ios::left)<<setw(20)<<"学院";
    cout<<setiosflags(ios::left)<<setw(20)<<"职称"<<endl;
}
void input2()
{
    string tmpid;
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        Person*tmp=Head;
        int month;
        showqian();
        Head->showall();
        cout<<"请输入已有教师工号:";
        cin>>tmpid;
        if(panduan(tmpid))
        {
            while(tmp)
            {
                if(tmp->id==tmpid)
                    break;
                tmp=tmp->next;
            }
            cout<<"请输入月份:";
            cin>>month;
            if(!tmp->money)
                tmp->money=new Money(tmp->id,month);
            else
            {
                if(!panduanmonth(month,tmp->money))
                {
                    Money*&End=tmp->money->getend();
                    End=new Money(tmp->id,month);
                }
                else
                    cout<<"工号为"<<tmp->id<<"教师的"<<month<<"月份工资信息已录入"<<endl;
            }
        }
        else
        {
            cout<<"工号为"<<tmpid<<"的教师信息未录入"<<endl;
        }
    }
}
void input(char choose)
{
    if(choose=='1')
        input1();
    else if(choose=='2')
        input2();
    else
        return;
}
bool panduan(string Id)
{
    Person*tmp=Head;
    while(tmp)
    {
        if(tmp->id==Id)
            return true;
        tmp=tmp->next;
    }
    return false;
}
bool panduanmonth(int monthtmp,Money*tmp)
{
    while(tmp)
    {
        if(tmp->month==monthtmp)
            return true;
        tmp=tmp->next;
    }
    return false;
}
void change(char choose)
{
    if(choose=='1')
        change1();
    else if(choose=='2')
        change2();
    else if(choose=='3')
        change3();
    else
        return;
}
void showmoney()
{
    cout<<setiosflags(ios::left)<<setw(20)<<"工号";
    cout<<setiosflags(ios::left)<<setw(20)<<"月份";
    cout<<setiosflags(ios::left)<<setw(20)<<"基本工资";
    cout<<setiosflags(ios::left)<<setw(20)<<"业绩津贴";
    cout<<setiosflags(ios::left)<<setw(20)<<"扣除费用";
    cout<<setiosflags(ios::left)<<setw(20)<<"应发工资";
    cout<<setiosflags(ios::left)<<setw(20)<<"实发工资"<<endl;
}
void change1()
{
    string tmp;
    Person*head=Head;
    int monthtmp;
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        cout<<"请输入要修改的教师工号:";
        cin>>tmp;
        if(panduan(tmp))
        {
            while(head)
            {
                if(head->id==tmp)
                    break;
                head=head->next;
            }
            showqian();
            head->showself();
            if(head->money)
            {
                showmoney();
                head->money->showall();
            }
            cout<<"请输入要修改的信息 (基本信息/工资信息)"<<endl;
            cin>>tmp;
            if(tmp=="工资信息")
            {
                if(!head->money)
                {
                    cout<<"工号为"<<head->id<<"的教师未录入工资信息"<<endl;
                    return;
                }
                cout<<"请输入要修改的月份:";
                cin>>monthtmp;
                if(panduanmonth(monthtmp,head->money))
                {
                    Money*tmpm=head->money;
                    while(tmpm)
                    {
                        if(tmpm->month==monthtmp)
                            break;
                        tmpm=tmpm->next;
                    }
                    tmpm->change();
                }
                else
                    cout<<"工号为"<<head->id<<"的教师"<<monthtmp<<"月份的工资信息未录入"<<endl;
            }
            else if(tmp=="基本信息")
            {
                head->change();
            }
            else
            {
                cout<<"输入错误,修改失败"<<endl;
            }
        }
        else
            cout<<"工号为"<<tmp<<"的教师信息未录入"<<endl;
    }

}
void change2()
{
    string tmp;
    int flag=0;
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        cout<<"请输入要修改的教师的姓名:";
        cin>>tmp;
        Person*head=Head;
        while(head)
        {
            if(head->name==tmp)
            {
                showqian();
                head->showself();
                if(head->money)
                {
                    showmoney();
                    head->money->showall();
                }
                flag=1;
            }
            head=head->next;
        }
        if(flag==0)
        {
            cout<<"姓名为"<<tmp<<"的教师信息未录入"<<endl;
            return ;
        }
        head=Head;
        cout<<"请输入要修改的教师工号:";
        cin>>tmp;
        if(panduan(tmp))
        {
            while(head)
            {
                if(head->id==tmp)
                    break;
                head=head->next;
            }
            cout<<"请输入要修改的信息 (基本信息/工资信息)"<<endl;
            cin>>tmp;
            if(tmp=="工资信息")
            {
                int monthtmp;
                if(!head->money)
                {
                    cout<<"工号为"<<head->id<<"的教师未录入工资信息"<<endl;
                    return;
                }
                cout<<"请输入要修改的月份:";
                cin>>monthtmp;
                if(panduanmonth(monthtmp,head->money))
                {
                    Money*tmpm=head->money;
                    while(tmpm)
                    {
                        if(tmpm->month==monthtmp)
                            break;
                        tmpm=tmpm->next;
                    }
                    tmpm->change();
                }
                else
                    cout<<"工号为"<<head->id<<"的教师"<<monthtmp<<"月份的工资信息未录入"<<endl;
            }
            else if(tmp=="基本信息")
            {
                head->change();
            }
            else
            {
                cout<<"输入错误,修改失败"<<endl;
            }
        }
        else
            cout<<"工号为"<<tmp<<"的教师信息未录入"<<endl;

    }
}
void change3()
{
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        Person*head=Head;
        Person*cur=Head;
        string tmp;
        cout<<"请输入要删除的教师工号:";
        cin>>tmp;
        if(panduan(tmp))
        {
            bool flag1=isexit();
            bool flag2=isexit();
            if(!(flag2&&flag1))
            {
                cout<<"放弃删除,删除失败"<<endl;
                return ;
            }
            while(head)
            {
                if(head->id==tmp)
                    break;
                cur=head;
                head=head->next;
            }
            if(cur==head)
            {
                Person*tmp=Head;
                Head=Head->next;
                tmp->next=NULL;
                delete tmp;
                cout<<"删除成功"<<endl;
            }
            else
                head->del(cur);
            if(!Head)
            {
                Empty=true;
            }
        }
        else
        {
            cout<<"工号为"<<tmp<<"的教师未录入"<<endl;
        }
    }
}
void research(char choose)
{
    if(choose=='1')
        research1();
    else if(choose=='2')
        research2();
    else if(choose=='3')
        research3();
    else if(choose=='4')
        research4();
    else
        return ;
}
void research1()
{
    string tmp;
    Person*head=Head;
    int monthtmp;
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        cout<<"请输入要查询的教师工号:";
        cin>>tmp;
        cout<<"请输入要查询的工资月份:";
        cin>>monthtmp;
        if(panduan(tmp))
        {
            while(head)
            {
                if(head->id==tmp)
                    break;
                head=head->next;
            }
            showqian();
            head->showself();
            Money*mtmp=head->money;
            if(panduanmonth(monthtmp,head->money))
            {
                while(mtmp)
                {
                    if(mtmp->month==monthtmp)
                        break;
                    mtmp=mtmp->next;
                }
                showmoney();
                mtmp->showself();
            }
            else
                cout<<"工号为"<<head->id<<"的教师"<<monthtmp<<"月份的工资信息未录入"<<endl;
        }
        else
            cout<<"工号为"<<tmp<<"的教师信息未录入"<<endl;
    }
}
bool panduanname(string tmp)
{
    Person*head=Head;
    while(head)
    {
        if(head->name==tmp)
            return true;
        head=head->next;
    }
    return false;
}
void research2()
{
    string tmp;
    Person*head=Head;
    int monthtmp;
    if(Empty)
        cout<<"未录入教师信息"<<endl;
    else
    {
        cout<<"请输入要查询的教师姓名:";
        cin>>tmp;
        cout<<"请输入要查询的工资月份:";
        cin>>monthtmp;
        if(panduanname(tmp))
        {
            while(head)
            {
                if(head->name==tmp)
                    break;
                head=head->next;
            }
            showqian();
            head->showself();
            Money*mtmp=head->money;
            if(panduanmonth(monthtmp,head->money))
            {
                while(mtmp)
                {
                    if(mtmp->month==monthtmp)
                        break;
                    mtmp=mtmp->next;
                }
                showmoney();
                mtmp->showself();
            }
            else
                cout<<"姓名为"<<head->id<<"的教师"<<monthtmp<<"月份的工资信息未录入"<<endl;
        }
        else
            cout<<"姓名为"<<tmp<<"的教师信息未录入"<<endl;
    }
}
void research3()
{
    int month;
    int flag=0;
    Person*head=Head;
    if(Empty)
    {
        cout<<"未录入教师信息"<<endl;
        return ;
    }
    cout<<"请输入查询的月份:";
    cin>>month;
    mysort();
    while(head)
    {
        Money*mtmp=head->money;
        while(mtmp)
        {
            if(mtmp->month==month)
             {
                 if(!flag)
                    showmoney();
                 flag=1;
                 mtmp->showself();
             }
            mtmp=mtmp->next;
        }
        head=head->next;
    }
    if(flag==0)
        cout<<"月份为"<<month<<"的工资信息未录入"<<endl;
}
void research4()
{
    mysort();
    Head->showall();
}
void mysort()
{
    if(Empty)
    {
        cout<<"未录入教师信息"<<endl;
        return ;
    }
    Person*head=Head;
    while(Head&&Head->next&&head&&head->next)
    {
        if(head->id>head->next->id)
        {
            Person tmp;
            tmp=*head;
            *head=*(head->next);
            *(head->next)=tmp;
        }
        head=head->next;
    }
}
