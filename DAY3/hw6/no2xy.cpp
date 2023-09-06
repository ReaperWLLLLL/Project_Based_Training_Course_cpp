#include <include/no2xy.h>
#include <iostream>
using namespace std;

No2xy::No2xy(double xValue, double yValue) : nomap({{"x", xValue}, {"y", yValue}})
{
    //cout << "Class No2xy has been created" << endl;
}

No2xy::No2xy() : nomap({{"x", 0}, {"y", 0}})
{
    //cout << "Class No2xy has been created" << endl;
}

No2xy::~No2xy()
{
    //cout << "Class No2xy has been destroyed" << endl;
}

void No2xy::set(string name, double value)
{
    try{
    nomap.find(name)->second = value;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        exit(1);
    }
}

double No2xy::get(string name)
{
    try{
    return nomap.find(name)->second;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
        exit(1);
    }//随缘加异常处理了属于是
}

void No2xy::display()
{
    cout << "*********" << endl;
    for (auto it = nomap.begin(); it != nomap.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}




