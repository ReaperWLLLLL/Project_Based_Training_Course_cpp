//第三次课后作业
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

//初始化数据结构内容为1、1、4、5、1、4、1
int array[7] = {1, 1, 4, 5, 1, 4, 1};
int* array2 = new int[7]{1, 1, 4, 5, 1, 4, 1};
vector<int> vec = {1, 1, 4, 5, 1, 4, 1};
deque<int> deq = {1, 1, 4, 5, 1, 4, 1};
list<int> li = {1, 1, 4, 5, 1, 4, 1};

int main(){
    //输出数据结构内容
    cout << "****output****" << endl;
    cout << "array: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "array2: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

    cout << "vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    cout << "list: ";
    cout << "list does not support [] operator." << endl;

    //使用迭代器输出数据结构内容
    cout << "****output using iterator****" << endl;
    cout << "array: ";
    cout << "array does not support iterator." << endl;

    cout << "array2: ";
    cout << "array2 does not support iterator." << endl;

    cout << "vector: ";
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "deque: ";
    for (deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "list: ";
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //输出下标为4的元素
    cout << "****output 4th element****" << endl;
    cout << "array[4]: " << array[4] << endl;
    cout << "array2[4]: " << array2[4] << endl;
    cout << "vector[4]: " << vec[4] << endl;
    cout << "deque[4]: " << deq[4] << endl;
    cout << "list:list does not support [] operator." << endl;

    //将下标为3的元素修改为5并打印所有元素
    cout << "****change 3rd element to 5****" << endl;
    array[3] = 5;
    cout << "array: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    array2[3] = 5;
    cout << "array2: ";
    for (int i = 0; i < 7; i++)
    {
        cout << array2[i] << " ";
    }
    cout << endl;

    vec[3] = 5;
    cout << "vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    deq[3] = 5;
    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    cout << "list:list does not support random read or write." << endl;

    //删除下标为2的元素并打印所有元素
    cout << "****erase 2nd element****" << endl;
    cout << "array: array does not support erase." << endl;

    cout << "array2: array2 does not support erase." << endl;

    vec.erase(vec.begin() + 2);
    cout << "vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    deq.erase(deq.begin() + 2);
    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    cout << "list: list does not support random erase." << endl;

    //在数据结构的尾部增加一个元素4，再次依次输出数据结构中的内容
    cout << "****push_back 4****" << endl;
    cout << "array: array does not support push_back." << endl;

    cout << "array2: array2 does not support push_back." << endl;

    vec.push_back(4);
    cout << "vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    deq.push_back(4);
    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    li.push_back(4);
    cout << "list: ";
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //在数据结构的头部增加一个元素7，再次依次输出数据结构中的内容
    cout << "****push_front 7****" << endl;
    cout << "array: array does not support push_front." << endl;

    cout << "array2: array2 does not support push_front." << endl;

    cout << "vector: vector does not support push_front." << endl;

    deq.push_front(7);
    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    li.push_front(7);
    cout << "list: ";
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //在数据结构的第5个和第6个元素中间插入一个元素3,再次依次输出数据结构中的内容
    cout << "****insert 3 between 5th and 6th element****" << endl;
    cout << "array: array does not support insert." << endl;

    cout << "array2: array2 does not support insert." << endl;

    vec.insert(vec.begin() + 5, 3);
    cout << "vector: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    deq.insert(deq.begin() + 5, 3);
    cout << "deque: ";
    for (int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;

    list<int>::iterator it = li.begin();
    for (int i = 0; i < 5; i++)
    {
        it++;
    }
    li.insert(it, 3);
    cout << "list: ";
    for (list<int>::iterator it = li.begin(); it != li.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    









    


    
    

}