//bd2no类的声明
#ifndef BD2NO_H
#define BD2NO_H // 防止重复引用
#include <map>
using namespace std;

class Bd2no
{
    private:
        map<string, int> bd2noMap;

    public:
        Bd2no(int bdValue, int no1Value, int no2Value);
        Bd2no();
        ~Bd2no();
        void set(string name, int Num);
        void set(int bdValue, int no1Value, int no2Value);
        void display();
        int get(string name);
};
#endif
