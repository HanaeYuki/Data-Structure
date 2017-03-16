#include <iostream>
#include <iostream>
#include <stdlib.h>
#include "h_seqlist.h"
using namespace std;

/* 构造函数 constructor*/
template<class T>
SeqList<T>::SeqList(int sz)
{
	maxSize = sz;
	curLen = 0;
	Data = new T[maxSize];
	if (Data == NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
}
/* 复制构造函数 copy constructor*/
template<class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
	maxSize = L.ListSize();
	curLen = L.ListLen();
	T value;
	Data = new T[maxSize];
	if (Data == NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	for (int i = 0; i<curLen; i++)
	{
		L.GetData(i, value);
		Data[i] = value;
	}
}
//增加表项数
template<class T>
void SeqList<T>::AddSize(int addSize)
{
	int newSize;
	int num = curLen;
	if (addSize <= 0)
	{
		cerr << "无效的数组大小！" << endl;
		return;
	}
	newSize = addSize + maxSize;
	T *newArray = new T[newSize];
	if (newArray == NULL)
	{
		cerr << "存储分配错误！" << endl;
		exit(1);
	}
	T *srcptr = Data;//源数组首地址source
	T *destptr = newArray; //目的数组首地址destination
	while (num)
		*destptr++ = *srcptr++;//while num>0;*destptr=*srcptr;*destptr++;*srcptr++;
	delete[]Data; //????
	Data = newArray;
	maxSize = newSize;
}
/* 获取第i个元素 */
template<class T>
bool SeqList<T>::GetData(int i, T&x)
{
	if (i <= 0 || i>curLen)
		return false;
	x = Data[i - 1];
	return true;
}
/* 插入到第i个元素之前，变成新的第i个元素 */
template<class T>
bool SeqList<T>::Insert(int i, T&x)
{
	if (curLen == maxSize)
		return false;
	if (i<1 || i>curLen)
		return false;
	for (int j = curLen - 1; j >= i - 1; j--)
		Data[j + 1] = Data[j];
	Data[i - 1] = x;
	curLen += 1;
	return true;
}
/* 移除第i个元素 */
template<class T>
bool SeqList<T>::Remove(int i, T&x)
{
	if (curLen == 0)
		return false;
	if (i<1 || i>curLen)
		return false;
    x = Data[i - 1];
	for (int j = i - 1; j<curLen - 1; j++)
		Data[j] = Data[j + 1];
	curLen -= 1;
	return true;
}
/* 给某个项设置值 */
template<class T>
bool SeqList<T>::SetElem(int i, T x)
{
	if (i<1 || i>curLen)
		return false;
	Data[i - 1] = x;
	return true;
}
/* 寻找表中与x相同的项并返回其序号 */
template<class T>
int SeqList<T>::Search(T&x)
{
	//sequence number
	for (int i = 0; i<curLen; i++)
		if (Data[i] == x)
			return i+1;
    cout<<"未找到该元素！"<<endl;
	return 0;
}
/* 定位表中第i个表项的位置，返回其位置的序号 */
template<class T>
int SeqList<T>::Locate(int i)
{
	if (i >= 1 && i <= curLen)
		return i - 1;
    return 0;
}
/* 从标准输入获取数据 */
template<class T>
void SeqList<T>::Input()
{
	cout << "请输入顺序表长度:";
	cin >> curLen;
	//if(curLen>maxSize)
 //   {this->AddSize(curLen-maxSize);}
	for (int i = 0; i<curLen; i++)
    {
        cout<<"  #"<<i+1<<":";
        cin >> Data[i];
    }
}
/* 输出到屏幕上 */
template<class T>
void SeqList<T>::Output()
{
	cout << "  ---你的顺序表---" << endl;
	for (int i = 0; i<curLen; i++)
		cout << "  #" << i + 1 << ":" << Data[i] << endl;
    cout << "  ----------------"<<endl;
}
/* 菜单 */
template<class T>
void SeqList<T>::Menu()
{
    cout<<endl;
    cout<<"      * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"      *                 菜 单               *"<<endl;
    cout<<"      *  1.输入顺序表  Input                *"<<endl;
    cout<<"      *  2.获取当前表最大项数               *"<<endl;
    cout<<"      *  3.获取当前表已存项数               *"<<endl;
    cout<<"      *  4.获取元素  GetData                *"<<endl;
    cout<<"      *  5.插入元素  Insert                 *"<<endl;
    cout<<"      *  6.移除元素  Remove                 *"<<endl;
    cout<<"      *  7.设置元素  SetElem                *"<<endl;
    cout<<"      *  8.搜索元素  Search                 *"<<endl;
    cout<<"      *  9.定位元素  Locate                 *"<<endl;
    cout<<"      *  10.判断存储状态  IsEmpty/IsFull    *"<<endl;
    cout<<"      *  11.输出顺序表  Output              *"<<endl;
    cout<<"      *  12.退出                            *"<<endl;
    cout<<"      * * * * * * * * * * * * * * * * * * * *"<<endl;
}
