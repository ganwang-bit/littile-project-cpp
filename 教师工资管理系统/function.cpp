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
    cout<<"ȷ���Ƿ��˳�"<<endl;
    while(1)
    {
        cout<<"ȷ��������Y/y ȡ��������N/n:";
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
    cout<<"�������ʦ�Ĺ���:";
    cin>>tmp;
    if(Empty)
    {
        Empty=false;
        Head=new Person(tmp);
    }
    else
    {
        if(panduan(tmp))
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣ��¼��"<<endl;
        else
        {
            Person*&End=Head->getend();
            End=new Person(tmp);
        }
    }
}
void showqian()
{
    cout<<setiosflags(ios::left)<<setw(20)<<"����";
    cout<<setiosflags(ios::left)<<setw(20)<<"����";
    cout<<setiosflags(ios::left)<<setw(20)<<"ѧԺ";
    cout<<setiosflags(ios::left)<<setw(20)<<"ְ��"<<endl;
}
void input2()
{
    string tmpid;
    if(Empty)
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        Person*tmp=Head;
        int month;
        showqian();
        Head->showall();
        cout<<"���������н�ʦ����:";
        cin>>tmpid;
        if(panduan(tmpid))
        {
            while(tmp)
            {
                if(tmp->id==tmpid)
                    break;
                tmp=tmp->next;
            }
            cout<<"�������·�:";
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
                    cout<<"����Ϊ"<<tmp->id<<"��ʦ��"<<month<<"�·ݹ�����Ϣ��¼��"<<endl;
            }
        }
        else
        {
            cout<<"����Ϊ"<<tmpid<<"�Ľ�ʦ��Ϣδ¼��"<<endl;
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
    cout<<setiosflags(ios::left)<<setw(20)<<"����";
    cout<<setiosflags(ios::left)<<setw(20)<<"�·�";
    cout<<setiosflags(ios::left)<<setw(20)<<"��������";
    cout<<setiosflags(ios::left)<<setw(20)<<"ҵ������";
    cout<<setiosflags(ios::left)<<setw(20)<<"�۳�����";
    cout<<setiosflags(ios::left)<<setw(20)<<"Ӧ������";
    cout<<setiosflags(ios::left)<<setw(20)<<"ʵ������"<<endl;
}
void change1()
{
    string tmp;
    Person*head=Head;
    int monthtmp;
    if(Empty)
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        cout<<"������Ҫ�޸ĵĽ�ʦ����:";
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
            cout<<"������Ҫ�޸ĵ���Ϣ (������Ϣ/������Ϣ)"<<endl;
            cin>>tmp;
            if(tmp=="������Ϣ")
            {
                if(!head->money)
                {
                    cout<<"����Ϊ"<<head->id<<"�Ľ�ʦδ¼�빤����Ϣ"<<endl;
                    return;
                }
                cout<<"������Ҫ�޸ĵ��·�:";
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
                    cout<<"����Ϊ"<<head->id<<"�Ľ�ʦ"<<monthtmp<<"�·ݵĹ�����Ϣδ¼��"<<endl;
            }
            else if(tmp=="������Ϣ")
            {
                head->change();
            }
            else
            {
                cout<<"�������,�޸�ʧ��"<<endl;
            }
        }
        else
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣδ¼��"<<endl;
    }

}
void change2()
{
    string tmp;
    int flag=0;
    if(Empty)
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        cout<<"������Ҫ�޸ĵĽ�ʦ������:";
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
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣδ¼��"<<endl;
            return ;
        }
        head=Head;
        cout<<"������Ҫ�޸ĵĽ�ʦ����:";
        cin>>tmp;
        if(panduan(tmp))
        {
            while(head)
            {
                if(head->id==tmp)
                    break;
                head=head->next;
            }
            cout<<"������Ҫ�޸ĵ���Ϣ (������Ϣ/������Ϣ)"<<endl;
            cin>>tmp;
            if(tmp=="������Ϣ")
            {
                int monthtmp;
                if(!head->money)
                {
                    cout<<"����Ϊ"<<head->id<<"�Ľ�ʦδ¼�빤����Ϣ"<<endl;
                    return;
                }
                cout<<"������Ҫ�޸ĵ��·�:";
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
                    cout<<"����Ϊ"<<head->id<<"�Ľ�ʦ"<<monthtmp<<"�·ݵĹ�����Ϣδ¼��"<<endl;
            }
            else if(tmp=="������Ϣ")
            {
                head->change();
            }
            else
            {
                cout<<"�������,�޸�ʧ��"<<endl;
            }
        }
        else
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣδ¼��"<<endl;

    }
}
void change3()
{
    if(Empty)
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        Person*head=Head;
        Person*cur=Head;
        string tmp;
        cout<<"������Ҫɾ���Ľ�ʦ����:";
        cin>>tmp;
        if(panduan(tmp))
        {
            bool flag1=isexit();
            bool flag2=isexit();
            if(!(flag2&&flag1))
            {
                cout<<"����ɾ��,ɾ��ʧ��"<<endl;
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
                cout<<"ɾ���ɹ�"<<endl;
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
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦδ¼��"<<endl;
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
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        cout<<"������Ҫ��ѯ�Ľ�ʦ����:";
        cin>>tmp;
        cout<<"������Ҫ��ѯ�Ĺ����·�:";
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
                cout<<"����Ϊ"<<head->id<<"�Ľ�ʦ"<<monthtmp<<"�·ݵĹ�����Ϣδ¼��"<<endl;
        }
        else
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣδ¼��"<<endl;
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
        cout<<"δ¼���ʦ��Ϣ"<<endl;
    else
    {
        cout<<"������Ҫ��ѯ�Ľ�ʦ����:";
        cin>>tmp;
        cout<<"������Ҫ��ѯ�Ĺ����·�:";
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
                cout<<"����Ϊ"<<head->id<<"�Ľ�ʦ"<<monthtmp<<"�·ݵĹ�����Ϣδ¼��"<<endl;
        }
        else
            cout<<"����Ϊ"<<tmp<<"�Ľ�ʦ��Ϣδ¼��"<<endl;
    }
}
void research3()
{
    int month;
    int flag=0;
    Person*head=Head;
    if(Empty)
    {
        cout<<"δ¼���ʦ��Ϣ"<<endl;
        return ;
    }
    cout<<"�������ѯ���·�:";
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
        cout<<"�·�Ϊ"<<month<<"�Ĺ�����Ϣδ¼��"<<endl;
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
        cout<<"δ¼���ʦ��Ϣ"<<endl;
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
