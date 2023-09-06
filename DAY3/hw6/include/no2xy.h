#ifndef NO2XY_H
#define NO2XY_H

#include <iostream>
#include <map>
using namespace std;

class No2xy
{
private:
    map<string, double> nomap;

public:
    No2xy(double xValue, double yValue);
    No2xy();
    ~No2xy();
    void set(string name, double value);
    double get(string name);
    void display();
};

#endif