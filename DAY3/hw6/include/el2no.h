//el2no类
#ifndef EL2NO_H
#define EL2NO_H

#include <iostream>
#include <map>
using namespace std;

class El2no
{
    private:
        map<string,int> elmap;
    
    public:
        El2no(int no1Value, int no2Value, int no3Value);
        El2no();
        ~El2no();
        void set(string name, int Num);
        void set(int no1Value, int no2Value, int no3Value);
        void display();
        int get(string name);        
};
#endif
