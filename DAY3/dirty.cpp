// 第五次课后作业，使用类和STL容器实现对网格数据的读取和处理，极其dirty，快给自己恶心到了，下次作业无论如何都得多文件编程了
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class El2no
{
private:
    map<string, double> elm = {{"no1", 1}, {"no2", 2}, {"no3", 3}};

public:
    El2no(int no1Value, int no2Value, int no3Value);
    ~El2no();
    void set(string name, int nodeNum);
    int get(string name);
    void set(int no1Value, int no2Value, int no3Value);
    void display();
    static vector<El2no> find_mid(vector<El2no> el2noVec, string attr, double lowerbound, double upperbound);//静态成员函数，用于查找满足条件的元素
};

El2no::El2no(int no1Value, int no2Value, int no3Value) : elm({{"no1", no1Value}, {"no2", no2Value}, {"no3", no3Value}})
{
    //cout << "Class El2no has been created" << endl;
}

El2no::~El2no()
{
    //cout << "Class El2no has been destroyed" << endl;
}

void El2no::set(string name, int nodeNum)
{
    elm.find(name)->second = nodeNum;
}

int El2no::get(string name)
{
    return elm.find(name)->second;
}

void El2no::set(int no1Value, int no2Value, int no3Value)
{
    elm["no1"] = no1Value;
    elm["no2"] = no2Value;
    elm["no3"] = no3Value;
}

void El2no::display()
{
    cout << "*********" << endl;
    for (auto it = elm.begin(); it != elm.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

vector<El2no> El2no::




find_mid(vector<El2no> el2noVec, string attr, double lowerbound, double upperbound)
{
    //说实话暂未体会出匿名内部类的优雅之处，可能是在内存上有优势，但看起来是真的丑
    vector<El2no> result;
    auto it = copy_if(el2noVec.begin(), el2noVec.end(), back_inserter(result), [attr, lowerbound, upperbound](El2no a) -> bool { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
};

//重写sort函数
bool cmp_el2no(El2no a, El2no b)
{
    return a.get("no1") > b.get("no1");
}

class Bd2no
{
private:
    map<string, double> bd = {{"bd", 0}, {"no1", 1}, {"no2", 2}};

public:
    Bd2no(int bdValue, int no1Value, int no2Value);
    ~Bd2no();
    void set(string name, int data);
    int get(string name);
    void set(int bdValue, int no1Value, int no2Value);
    void display();
    static vector<Bd2no> find_mid(vector<Bd2no> bd2noVec, string attr, double lowerbound, double upperbound);
};

Bd2no::Bd2no(int bdValue, int no1Value, int no2Value) : bd({{"bd", bdValue}, {"no1", no1Value}, {"no2", no2Value}})
{
    //cout << "Class Bd2no has been created" << endl;
}

Bd2no::~Bd2no()
{
    //cout << "Class Bd2no has been destroyed" << endl;
}

void Bd2no::set(string name, int data)
{
    bd.find(name)->second = data;
}

int Bd2no::get(string name)
{
    return bd.find(name)->second;
}

void Bd2no::set(int bdValue, int no1Value, int no2Value)
{
    bd["bd"] = bdValue;
    bd["no1"] = no1Value;
    bd["no2"] = no2Value;
}

void Bd2no::display()
{
    cout << "*********" << endl;
    for (auto it = bd.begin(); it != bd.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

bool cmp_bd2no(Bd2no a, Bd2no b)
{
    return a.get("bd") > b.get("bd");
}

vector<Bd2no> Bd2no::find_mid(vector<Bd2no> bd2noVec, string attr, double lowerbound, double upperbound)
{
    vector<Bd2no> result;
    auto it = copy_if(bd2noVec.begin(), bd2noVec.end(), back_inserter(result), [attr, lowerbound, upperbound](Bd2no a) -> bool { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
};

class No2xy
{
private:
    map<string, double> no = {{"x", 0}, {"y", 0}};

public:
    No2xy(double xValue, double yValue);
    ~No2xy();
    void set(string name, double data);
    double get(string name);
    void set(double xValue, double yValue);
    void display();
    static vector<No2xy> find_mid(vector<No2xy> no2xyVec, string attr, double lowerbound, double upperbound);
};

No2xy::No2xy(double xValue, double yValue) : no({{"x", xValue}, {"y", yValue}})
{
    //cout << "Class No2xy has been created" << endl;
}

No2xy::~No2xy()
{
    //cout << "Class No2xy has been destroyed" << endl;
}

void No2xy::set(string name, double data)
{
    no.find(name)->second = data;
}

double No2xy::get(string name)
{
    return no.find(name)->second;
}

void No2xy::set(double xValue, double yValue)
{
    no["x"] = xValue;
    no["y"] = yValue;
}

void No2xy::display()
{
    cout << "*********" << endl;
    for (auto it = no.begin(); it != no.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
}

bool cmp_no2xy(No2xy a, No2xy b)
{
    return a.get("x") > b.get("x");
}

vector<No2xy> No2xy::find_mid(vector<No2xy> no2xyVec, string attr, double lowerbound, double upperbound)
{
    vector<No2xy> result;
    auto it = copy_if(no2xyVec.begin(), no2xyVec.end(), back_inserter(result), [attr, lowerbound, upperbound](No2xy a) -> bool { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
};

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

        if (line == "165 # number of elements" && el2noFlag)
        {
            //getline(fin, line);
            for (int i = 0; i < 165; i++)
            {
                getline(fin, line);
                int no1, no2, no3;
                fin >> no1 >> no2 >> no3;
                El2no el2no(no1, no2, no3);
                el2noVec.push_back(el2no);
            }
            el2noFlag = false;
        }
    }
    fin.close();
    /* 以下调试用
    // 输出数据
    for (int i = 0; i < el2noVec.size(); i++)
    {
        el2noVec[i].display();
    }
    for (int i = 0; i < bd2noVec.size(); i++)
    {
        bd2noVec[i].display();
    }
    for (int i = 0; i < no2xyVec.size(); i++)
    {
        no2xyVec[i].display();
    }
    */
    // 以下是task2
    cout << endl;
    cout << "Below is the test of task2" << endl;
    cout << endl;
    
    //将el2noVec中的数据按照no1从大到小排序
    sort(el2noVec.begin(), el2noVec.end(), cmp_el2no);
    // 输出排序后的数据
    cout << "Below is the sorted data of el2no:" << endl;
    for (int i = 0; i < el2noVec.size(); i++)
    {
        el2noVec[i].display();
    }

    // 将bd2noVec中的数据按照bd从大到小排序
    sort(bd2noVec.begin(), bd2noVec.end(), cmp_bd2no);
    // 输出排序后的数据
    cout << "Below is the sorted data of bd2no:" << endl;
    for (int i = 0; i < bd2noVec.size(); i++)
    {
        bd2noVec[i].display();
    }

    // 将no2xyVec中的数据按照x从大到小排序
    sort(no2xyVec.begin(), no2xyVec.end(), cmp_no2xy);//此处也可以使用lamda匿名函数，如[](No2xy a, No2xy b){return a.get("x") > b.get("x");}，我知道这更优雅但是懒得改了
    // 输出排序后的数据
    cout << "Below is the sorted data of no2xy:" << endl;
    for (int i = 0; i < no2xyVec.size(); i++)
    {
        no2xyVec[i].display();
    }

    // 以下是task3
    cout << endl;
    cout << "Below is the test of task3" << endl;
    cout << endl;
    vector<El2no> result = El2no::find_mid(el2noVec, "no1", 10, 20);
    vector<Bd2no> result2 = Bd2no::find_mid(bd2noVec, "bd", 10, 20);
    vector<No2xy> result3 = No2xy::find_mid(no2xyVec, "x", 10, 20);
    cout << "Below is the result of find_mid of El2no:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        result[i].display();
    }

    cout << "Below is the result of find_mid of Bd2no:" << endl;
    for (int i = 0; i < result2.size(); i++)
    {
        result2[i].display();
    }

    cout << "Below is the result of find_mid of No2xy:" << endl;
    for (int i = 0; i < result3.size(); i++)
    {
        result3[i].display();
    }

    return 0;
}

