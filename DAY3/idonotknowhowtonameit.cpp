// 第五次课后作业
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class El2no
{
private:
    map<string, double> elm = {{"no1", 1}, {"no2", 2}, {"no3", 3}};

public:
    El2no(int no1Value, int no2Value, int no3Value);
    ~El2no();
    void set(string name, int nodeNum);
    void set(int no1Value, int no2Value, int no3Value);
    void display();
};

El2no::El2no(int no1Value, int no2Value, int no3Value) : elm({{"no1", no1Value}, {"no2", no2Value}, {"no3", no3Value}})
{
    cout << "Class El2no has been created" << endl;
}

El2no::~El2no()
{
    cout << "Class El2no has been destroyed" << endl;
}

void El2no::set(string name, int nodeNum)
{
    elm.find(name)->second = nodeNum;
}

void El2no::set(int no1Value, int no2Value, int no3Value)
{
    elm["no1"] = no1Value;
    elm["no2"] = no2Value;
    elm["no3"] = no3Value;
}

void El2no::display()
{
    cout << "Below is the data of El2no:" << endl;
    for (auto it = elm.begin(); it != elm.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

class Bd2no
{
private:
    map<string, double> bd = {{"bd", 0}, {"no1", 1}, {"no2", 2}};

public:
    Bd2no(int bdValue, int no1Value, int no2Value);
    ~Bd2no();
    void set(string name, int data);
    void set(int bdValue, int no1Value, int no2Value);
    void display();
};

Bd2no::Bd2no(int bdValue, int no1Value, int no2Value) : bd({{"bd", bdValue}, {"no1", no1Value}, {"no2", no2Value}})
{
    cout << "Class Bd2no has been created" << endl;
}

Bd2no::~Bd2no()
{
    cout << "Class Bd2no has been destroyed" << endl;
}

void Bd2no::set(string name, int data)
{
    bd.find(name)->second = data;
}

void Bd2no::set(int bdValue, int no1Value, int no2Value)
{
    bd["bd"] = bdValue;
    bd["no1"] = no1Value;
    bd["no2"] = no2Value;
}

void Bd2no::display()
{
    cout << "Below is the data of Bd2no:" << endl;
    for (auto it = bd.begin(); it != bd.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

class No2xy
{
private:
    map<string, double> no = {{"x", 0}, {"y", 0}};

public:
    No2xy(double xValue, double yValue);
    ~No2xy();
    void set(string name, double data);
    void set(double xValue, double yValue);
    void display();
};

No2xy::No2xy(double xValue, double yValue) : no({{"x", xValue}, {"y", yValue}})
{
    cout << "Class No2xy has been created" << endl;
}

No2xy::~No2xy()
{
    cout << "Class No2xy has been destroyed" << endl;
}

void No2xy::set(string name, double data)
{
    no.find(name)->second = data;
}

void No2xy::set(double xValue, double yValue)
{
    no["x"] = xValue;
    no["y"] = yValue;
}

void No2xy::display()
{
    cout << "Below is the data of No2xy:" << endl;
    for (auto it = no.begin(); it != no.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

int main()
{
    cout << "Below is the test of task1" << endl;
    El2no el2no(1, 2, 3);
    el2no.display();
    el2no.set("no1", 4);
    el2no.display();
    el2no.set("no8", 4); // 这里不会插入新的键值对
    el2no.display();
    // 以下是文件读写部分
    ifstream fin("mesh.txt");
    string line;
    vector<El2no> el2noVec;
    vector<Bd2no> bd2noVec;
    vector<No2xy> no2xyVec;
    bool no2xyFlag = true;
    bool bd2noFlag = true;
    bool el2noFlag = true;

    while (getline(fin, line))
    {
        if (line == "# Mesh point coordinates" && no2xyFlag)
        {
            for (int i = 0; i < 107; i++)
            {
                getline(fin, line);
                // 以空格为分界读取两个double型数据
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1);
                double x = stod(xStr);
                double y = stod(yStr);
                // 新建对象
                No2xy no2xy(x, y);
                // 向vector中添加对象
                no2xyVec.push_back(no2xy);
            }
            no2xyFlag = false;
        }

        if (line == "# Elements" && bd2noFlag)
        {
            for (int i = 0; i < 51; i++)
            {
                getline(fin, line);
                // 以空格为分界读取两个int型数据
                int no1Value, no2Value;
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1); // 此处应该可以使用>>更为优雅地实现，见DAY2/read_elm.cpp
                no1Value = stoi(xStr);
                no2Value = stoi(yStr);
                // 新建对象
                Bd2no bd2no(i + 1, no1Value, no2Value);
                // 将对象添加到vector中
                bd2noVec.push_back(bd2no);
            }
            bd2noFlag = false;
        }

        if (line == "# Geometric entity indices")
        {
            for (int i = 0; i < 51; i++)
            {
                getline(fin, line);
                int bd = stoi(line);
                bd2noVec[i].set("bd", bd);
            }
        }
    }
}
