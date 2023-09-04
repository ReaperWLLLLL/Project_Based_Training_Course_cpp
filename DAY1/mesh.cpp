// 高电压课组第一次课后作业
#include <iostream>
using namespace std;

class El2no
{
private:
    int no1 = 1;
    int no2 = 2;
    int no3 = 3;

public:
    El2no(int no1Value, int no2Value, int no3Value);
    El2no();
    ~El2no();
    void set(string name, int nodeNum);
    void set(int no1Value, int no2Value, int no3Value);
    void display();
};

El2no::El2no(int no1Value, int no2Value, int no3Value) : no1(no1Value), no2(no2Value), no3(no3Value)
{
    cout << "Class El2no has been created" << endl;
}

El2no::~El2no()
{
    cout << "Class El2no has been destroyed" << endl;
}

void El2no::set(string name, int nodeNum)
{
    if (name == "no1")
    {
        no1 = nodeNum;
    }
    else if (name == "no2")
    {
        no2 = nodeNum;
    }
    else if (name == "no3")
    {
        no3 = nodeNum;
    }
    else
    {
        cout << "Wrong node name" << endl;
    }
}

void El2no::set(int no1Value, int no2Value, int no3Value)
{
    no1 = no1Value;
    no2 = no2Value;
    no3 = no3Value;
}

void El2no::display()
{
    cout << "Below is the data of El2no:" << endl;
    cout << "no1 = " << no1 << endl;
    cout << "no2 = " << no2 << endl;
    cout << "no3 = " << no3 << endl;
}

class Bd2no
{
private:
    int bd = 0;
    int no1 = 1;
    int no2 = 2;

public:
    Bd2no(int bdValue, int no1Value, int no2Value);
    ~Bd2no();
    void set(string name, int data);
    void set(int bdValue, int no1Value, int no2Value);
    void display();
};

Bd2no::Bd2no(int bdValue, int no1Value, int no2Value) : bd(bdValue), no1(no1Value), no2(no2Value)
{
    cout << "Class Bd2no has been created" << endl;
}

Bd2no::~Bd2no()
{
    cout << "Class Bd2no has been destroyed" << endl;
}

void Bd2no::set(string name, int data)
{
    if (name == "bd")
    {
        bd = data;
    }
    else if (name == "no1")
    {
        no1 = data;
    }
    else if (name == "no2")
    {
        no2 = data;
    }
    else
    {
        cout << "Wrong node name" << endl;
    }
}

void Bd2no::set(int bdValue, int no1Value, int no2Value)
{
    bd = bdValue;
    no1 = no1Value;
    no2 = no2Value;
}

void Bd2no::display()
{
    cout << "Below is the data of Bd2no:" << endl;
    cout << "bd = " << bd << endl;
    cout << "no1 = " << no1 << endl;
    cout << "no2 = " << no2 << endl;
}

class No2xy
{
private:
    double x = 0;
    double y = 0;

public:
    No2xy(double xValue, double yValue);
    ~No2xy();
    void set(string name, double data);
    void set(double xValue, double yValue);
    void display();
};

No2xy::No2xy(double xValue, double yValue) : x(xValue), y(yValue)
{
    cout << "Class No2xy has been created" << endl;
}

No2xy::~No2xy()
{
    cout << "Class No2xy has been destroyed" << endl;
}

void No2xy::set(string name, double data)
{
    if (name == "x")
    {
        x = data;
    }
    else if (name == "y")
    {
        y = data;
    }
    else
    {
        cout << "Wrong node name" << endl;
    }
}

void No2xy::set(double xValue, double yValue)
{
    x = xValue;
    y = yValue;
}

void No2xy::display()
{
    cout << "Below is the data of No2xy:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    cout << "Below is the test of El2no" << endl;
    El2no el2no1(1, 2, 3);
    el2no1.display();
    el2no1.set("no8", 4);
    el2no1.set("no1", 4);
    el2no1.display();
    el2no1.set(5, 6, 7);
    el2no1.display();
    cout << "Below is the test of Bd2no" << endl;
    Bd2no bd2no1(1, 2, 3);
    bd2no1.display();
    bd2no1.set("no8", 4);
    bd2no1.set("bd", 4);
    bd2no1.display();
    bd2no1.set(5, 6, 7);
    bd2no1.display();
    cout << "Below is the test of No2xy" << endl;
    No2xy no2xy1(1, 2);
    no2xy1.display();
    no2xy1.set("no8", 4);
    no2xy1.set("x", 4);
    no2xy1.display();
    no2xy1.set(5, 6);
    no2xy1.display();
    return 0;
}
