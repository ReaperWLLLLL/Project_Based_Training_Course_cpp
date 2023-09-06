#include <include/el2no.h>
#include <iostream>
using namespace std;

El2no::El2no(int no1Value, int no2Value, int no3Value) : elmap({{"no1", no1Value}, {"no2", no2Value}, {"no3", no3Value}})
{
    //cout << "Class El2no has been created" << endl;
}

El2no::El2no() : elmap({{"no1", 0}, {"no2", 1}, {"no3", 2}})
{
    //cout << "Class El2no has been created" << endl;
}

El2no::~El2no()
{
    //cout << "Class El2no has been destroyed" << endl;
}

void El2no::set(string name, int data)
{
    //若未找到需要抛出异常
    try{
        elmap.find(name)->second = data;
    }
    catch(exception& e){
        cout << e.what() << endl;
        exit(1);
    }
    
}

int El2no::get(string name)
{
    //若未找到需要抛出异常
    try{
        return elmap.find(name)->second;
    }
    catch(exception& e){
        cout << e.what() << endl;
        exit(1);
    }
}

void El2no::set(int no1Value, int no2Value, int no3Value)
{
    elmap["no1"] = no1Value;
    elmap["no2"] = no2Value;
    elmap["no3"] = no3Value;
}

void El2no::display()
{
    cout << "*********" << endl;
    for (auto it = elmap.begin(); it != elmap.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}