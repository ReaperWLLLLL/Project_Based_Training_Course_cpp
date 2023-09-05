// 第四次平时作业3，主要内容为文件读写
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class El2no
{
private:
    int no1 = 1;
    int no2 = 2;
    int no3 = 3;
    static int count;

public:
    El2no(int no1Value, int no2Value, int no3Value);
    El2no();
    ~El2no();
    void set(string name, int nodeNum);
    void set(int no1Value, int no2Value, int no3Value);
    void display();
};

int El2no::count = 0;

El2no::El2no(int no1Value, int no2Value, int no3Value) : no1(no1Value), no2(no2Value), no3(no3Value)
{
    // cout << "Class El2no has been created" << endl;
    count++;
}

El2no::~El2no()
{
    //cout << "Class El2no has been destroyed" << endl;
    count--;
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

int main()
{
    vector<El2no> vec;
    // 读取文件
    ifstream fin("mesh.txt");
    if (!fin)
    {
        cout << "File open failed" << endl;
        return 0;
    }
    // 读取文件中的数据
    string line;
    while (getline(fin, line))
    {
        if (line == "165 # number of elements")
        {
            //getline(fin, line);
            for (int i = 0; i < 165; i++)
            {
                getline(fin, line);
                int no1, no2, no3;
                fin >> no1 >> no2 >> no3;
                El2no el2no(no1, no2, no3);
                vec.push_back(el2no);
            }
        }
    }
    // 输出数据
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].display();
    }
    fin.close();
}