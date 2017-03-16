#ifndef H_SEQLIST_H_INCLUDED
#define H_SEQLIST_H_INCLUDED

// sequential list
template<class T>
class SeqList
{
private:
    int maxSize; //可容纳最大项数
    int curLen; //当前项数
    T *Data; //存放数据
    void AddSize(int addSize);
public:
    SeqList(int sz = 3);              //constructor
    SeqList(SeqList<T> &L);           //copy constructor
    ~SeqList()
    {
        delete[]Data;    //destructor
    }
    int ListSize()
    {
        return maxSize;    //返回某表最大项数
    }
    int ListLen()
    {
        return curLen;    //返回某表当前项数（长度）
    }
    bool GetData(int i, T&x);         //获取某个元素
    bool Insert(int i, T&x);
    bool Remove(int i, T&x);
    bool SetElem(int i, T x);         //给某个项设置值
    int Search(T&x);                  //寻找表中与x相同的项并返回其序号
    int Locate(int i);                //定位表中第i个表项的位置，返回其位置的序号
    bool IsEmpty()
    {
        return (curLen == 0) ? true : false;
    }
    bool IsFull()
    {
        return (curLen == maxSize) ? true : false;
    }
    void Input();                     //从标准输入获取数据
    void Output();                    //输出到屏幕上
    void Menu();
    //    SeqList<T>& operator=(SeqList<T> &L);//表整体赋值
    //???重载输出函数怎么写？
};

#endif // H_SEQLIST_H_INCLUDED
