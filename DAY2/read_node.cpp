//第四次课后作业1，作业内容主要为文件读写
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class No2xy
{
private:
    double x = 0;
    double y = 0;
    static int count;

public:
    No2xy(double xValue, double yValue);
    ~No2xy();
    void set(string name, double data);
    void set(double xValue, double yValue);
    void display();
};

int No2xy::count = 0;

No2xy::No2xy(double xValue, double yValue) : x(xValue), y(yValue)
{
    //cout << "Class No2xy has been created" << endl;
    count++;
}

No2xy::~No2xy()
{
    //cout << "Class No2xy has been destroyed" << endl;
    //count--;
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
    cout << "Below is the data of No2xy "<< endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    //新建vector，用于存储No2xy类的对象
    vector<No2xy> vec;
    //读取名为mesh.txt的文件
    ifstream meshFile;
    meshFile.open("mesh.txt");
    if (!meshFile.is_open())
    {
        cout << "Fail to open mesh.txt" << endl;
        return 0;
    }
    //读取文件中的数据，当读取到“# Mesh point coordinates”时开始向vector中添加对象，共107个
    string line;
    while (getline(meshFile, line))
    {
        if (line == "# Mesh point coordinates")
        {
            for (int i = 0; i < 107; i++)
            {
                getline(meshFile, line);
                //以空格为分界读取两个double型数据
                int pos = line.find(" ");
                string xStr = line.substr(0, pos);
                string yStr = line.substr(pos + 1, line.length() - pos - 1);
                double x = stod(xStr);
                double y = stod(yStr);
                //新建对象
                No2xy no2xy(x, y);
                //向vector中添加对象
                vec.push_back(no2xy);
            }
        }
    }
    meshFile.close();
    //遍历vector，输出所有对象的数据
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].display();
    }
    


    
}
