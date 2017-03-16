#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include "h_seqlist.h"
#include "seqlist.cpp"
using namespace std;

int main()
{
    SeqList <int> List1(100);
    while(1)
    {
        int value ;
	    int num ;//序号
	    int x ;//输入的值
	    int m ;//保存输入序号
        List1.Menu();
        cin>>m;
        switch(m)
        {
            case 1:/*1.输入顺序表  Input*/
                List1.Input();
                break;
            case 2:/*2.获取当前表最大项数*/
                cout<<"  当前表最大项数为："<<List1.ListSize()<<endl;
                break;
            case 3:/*3.获取当前表已存项数*/
                cout<<"  当前表已存项数为："<<List1.ListLen()<<endl;
                break;
            case 4:/*4.获取元素  GetData*/
                cout<<"  请输入要获取的元素序号(1~"<<List1.ListLen()<<"):"<<endl;
                cin>>num;
                List1.GetData(num, value);
                cout<<"  #"<<num<<"："<<value<<endl;
                break;
            case 5:/*5.插入元素  Insert*/
                cout<<"  请输入要插入的项数序号(1~"<<List1.ListLen()<<")及要插入的元素（用空格隔开）："<<endl;
                cin>>num>>x;
                while(List1.GetData(num, value)==false)
                {
                     cout<<"  你输入的序号超出范围！请重新输入:";
                     cin>>num>>x;
                }
                cout<<"  原#"<<num<<"："<<value<<endl;
                List1.Insert(num,x);
                List1.GetData(num, value);
                cout<<"  现#"<<num<<"："<<value<<endl;
                break;
            case 6:/*6.移除元素  Remove*/
                 cout<<"  请输入要移除的元素序号(1~"<<List1.ListLen()<<")："<<endl;
                 cin>>num;
                 while(List1.Remove(num, value)==false)
                {
                     cout<<"  你输入的序号超出范围！请重新输入:";
                     cin>>num;
                }
                 List1.Remove(num,value);
                 cout<<"  #"<<num<<":"<<value<<"已移除！"<<endl;
                break;
            case 7:/*7.设置元素  SetElem*/
                cout<<"  请输入要设置的元素序号(1~"<<List1.ListLen()<<")及其赋值（用空格隔开）："<<endl;
                cin>>num>>x;
                List1.GetData(num, value);
                cout<<"  原#"<<num<<"："<<value<<endl;
                List1.SetElem(num,x);
                List1.GetData(num, value);
                cout<<"  现#"<<num<<"："<<value<<endl;
                break;
            case 8:/*8.搜索元素  Search*/
                cout<<"  请输入要搜索的元素值："<<endl;
                cin>>x;
                cout<<"  该元素的序号为:#"<<List1.Search(x)<<endl;
                break;
            case 9:/*9.定位元素  Locate*/
                cout<<"  请输入要定位的表项序号(1~"<<List1.ListLen()<<")："<<endl;
                cin>>num;
                cout<<"  #"<<num<<"的位置是："<<List1.Locate(num)<<endl;
                break;
            case 10:/*10.判断存储状态  IsEmpty/IsFull*/
                if(List1.IsEmpty())
                    cout<<"  顺序表为空！"<<endl;
                else if(List1.IsFull())
                    cout<<"  顺序表已满！"<<endl;
                else
                    cout<<"  当前顺序表存储状态为："
                        <<"("<<List1.ListLen()<<"/"<<List1.ListSize()<<")"<<endl;
                break;
            case 11:/*11.输出顺序表  Output*/
                List1.Output();
                break;
            case 12:/*12.退出*/
                cout<<"  ……即将退出程序……"<<endl;
                return 0 ;
                break;
            default:
            cout << "error" << endl;
            return 0;
        }
    }
	return 0;
}
