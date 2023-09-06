#include "include/mesh.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

Mesh::Mesh()
{
    // cout << "Class Mesh has been created" << endl;
}

Mesh::~Mesh()
{
    // cout << "Class Mesh has been destroyed" << endl;
}

Mesh::Mesh(vector<Bd2no> bd2noVec, vector<El2no> el2noVec, vector<No2xy> no2xyVec)
{
    this->bd2noVec = bd2noVec;
    this->el2noVec = el2noVec;
    this->no2xyVec = no2xyVec;
}

void Mesh::readall(string filename)
{
    ifstream fin("mesh.txt");
    if (!fin)
    {
        cout << "File open failed" << endl;
        exit(0);
    }
    string line;
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
            // getline(fin, line);
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
}

void Mesh::sort_element(string name, bool scend)
{
    sort(el2noVec.begin(), el2noVec.end(), [name, scend](El2no a, El2no b)
         { return (a.get(name) > b.get(name)) == scend; });
}

void Mesh::sort_boundary(string name, bool scend)
{
    sort(bd2noVec.begin(), bd2noVec.end(), [name, scend](Bd2no a, Bd2no b)
         { return (a.get(name) > b.get(name)) == scend; });
}

void Mesh::sort_node(string name, bool scend)
{
    sort(no2xyVec.begin(), no2xyVec.end(), [name, scend](No2xy a, No2xy b)
         { return (a.get(name) > b.get(name)) == scend; });
}

vector<El2no> Mesh::find_mid_element(string attr, int lowerbound, int upperbound)
{
    vector<El2no> result;
    auto it = copy_if(el2noVec.begin(), el2noVec.end(), back_inserter(result), [attr, lowerbound, upperbound](El2no a) -> bool
                      { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
}

vector<Bd2no> Mesh::find_mid_boundary(string attr, int lowerbound, int upperbound)
{
    vector<Bd2no> result;
    auto it = copy_if(bd2noVec.begin(), bd2noVec.end(), back_inserter(result), [attr, lowerbound, upperbound](Bd2no a) -> bool
                      { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
}

vector<No2xy> Mesh::find_mid_node(string attr, double lowerbound, double upperbound)
{
    vector<No2xy> result;
    auto it = copy_if(no2xyVec.begin(), no2xyVec.end(), back_inserter(result), [attr, lowerbound, upperbound](No2xy a) -> bool
                      { return a.get(attr) > lowerbound && a.get(attr) < upperbound; });
    return result;
}

void Mesh::display()
{
    cout << "*********" << endl;
    cout << "Below is the display of Mesh" << endl;
    cout << "*********" << endl;
    cout << "Below is the display of bd2noVec" << endl;
    for (auto it = bd2noVec.begin(); it != bd2noVec.end(); it++)
    {
        it->display();
    }
    cout << "*********" << endl;
    cout << "Below is the display of el2noVec" << endl;
    for (auto it = el2noVec.begin(); it != el2noVec.end(); it++)
    {
        it->display();
    }
    cout << "*********" << endl;
    cout << "Below is the display of no2xyVec" << endl;
    for (auto it = no2xyVec.begin(); it != no2xyVec.end(); it++)
    {
        it->display();
    }
    cout << "*********" << endl;
}

void Mesh::display(string name)
{
    cout << "*********" << endl;
    cout << "Below is the display of Mesh" << endl;
    cout << "*********" << endl;
    cout << "Below is the display of " << name << endl;
    if (name == "bd2noVec")
    {
        for (auto it = bd2noVec.begin(); it != bd2noVec.end(); it++)
        {
            it->display();
        }
    }
    else if (name == "el2noVec")
    {
        for (auto it = el2noVec.begin(); it != el2noVec.end(); it++)
        {
            it->display();
        }
    }
    else if (name == "no2xyVec")
    {
        for (auto it = no2xyVec.begin(); it != no2xyVec.end(); it++)
        {
            it->display();
        }
    }
    else
    {
        cout << "Wrong name" << endl;
    }
    cout << "*********" << endl;
}




