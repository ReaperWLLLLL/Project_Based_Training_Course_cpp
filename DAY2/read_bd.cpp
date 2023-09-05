//第四次课后作业2，内容主要为文件读写
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Bd2no
{
private:
    int bd = 0;
    int no1 = 1;
    int no2 = 2;
    static int count;

public:
    Bd2no(int bdValue, int no1Value, int no2Value);
    ~Bd2no();
    void set(string name, int data);
    void set(int bdValue, int no1Value, int no2Value);
    void display();
};

int Bd2no::count = 0;

Bd2no::Bd2no(int bdValue, int no1Value, int no2Value) : bd(bdValue), no1(no1Value), no2(no2Value)
{
    //cout << "Class Bd2no has been created" << endl;
    count++;
}

Bd2no::~Bd2no()
{
    //cout << "Class Bd2no has been destroyed" << endl;
    count--;
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

int main(){
    //新建vector，用于存储Bd2no类的对象
    vector<Bd2no> vec;

    //读取文件
    ifstream infile;
    infile.open("mesh.txt");
    if (!infile.is_open())
    {
        cout << "Open file failure" << endl;
        return 0;
    }

    //读取文件内容
    string line;
    bool flag = true;
    while (getline(infile, line))
    {
        if (line == "# Elements" && flag){
            for(int i = 0; i < 51; i++){
                getline(infile, line);
                //以空格为分界读取两个int型数据
                int no1Value, no2Value;
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1);
                no1Value = stoi(xStr);
                no2Value = stoi(yStr);
                //新建对象
                Bd2no bd2no(i + 1, no1Value, no2Value);
                //将对象添加到vector中
                vec.push_back(bd2no);
            }
            flag = false;
        }

        if(line == "# Geometric entity indices"){
            for (int i = 0; i < 51; i++)
            {
                getline(infile, line);
                int bd = stoi(line);
                vec[i].set("bd", bd);
            }
        }
    }
    infile.close();
    
    //遍历vector，输出所有对象的数据
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].display();
    }
}
