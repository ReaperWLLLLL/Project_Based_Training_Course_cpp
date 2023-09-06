//bd2no.cpp
#include <include/bd2no.h>
#include <iostream>
using namespace std;
Bd2no::Bd2no(int bdValue, int no1Value, int no2Value) : bd2noMap({{"bd", bdValue}, {"no1", no1Value}, {"no2", no2Value}})
{
    //cout << "Class Bd2no has been created" << endl;
}

Bd2no::Bd2no() : bd2noMap({{"bd", 0}, {"no1", 1}, {"no2", 2}})
{
    //cout << "Class Bd2no has been created" << endl;
}

Bd2no::~Bd2no()
{
    //cout << "Class Bd2no has been destroyed" << endl;
}

void Bd2no::set(string name, int data)
{
    //若未找到需要抛出异常
    try{
        bd2noMap.find(name)->second = data;
    }
    catch(exception& e){
        cout << e.what() << endl;
        exit(1);
    }
}

int Bd2no::get(string name)
{
    //若未找到需要抛出异常
    try{
        return bd2noMap.find(name)->second;
    }
    catch(exception& e){
        cout << e.what() << endl;
        exit(1);
    }
}

void Bd2no::set(int bdValue, int no1Value, int no2Value)
{
    bd2noMap["bd"] = bdValue;
    bd2noMap["no1"] = no1Value;
    bd2noMap["no2"] = no2Value;
}

void Bd2no::display()
{
    cout << "*********" << endl;
    for (auto it = bd2noMap.begin(); it != bd2noMap.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}



