// 第二次平时作业
#include <iostream>
using namespace std;

class Mat
{
private:
    int *data;
    int m, n,exception;

public:
    Mat(); // 默认构造函数
    Mat(int parm);
    Mat(int parm1, int parm2);
    Mat(const Mat &mat);                    // 拷贝构造函数
    ~Mat();                                 // 析构函数
    int &at(int i, int j);                  // 返回矩阵中第i行第j列的元素
    Mat submat(int i, int j, int p, int q); // 返回矩阵中第i行，第j列起p行q列的子矩阵
    Mat resize(int parm1, int parm2);       // 将矩阵的大小调整为parm1行parm2列
    // 重载运算符+，作用为将两个矩阵相加
    Mat operator+(const Mat &mat);
    // 重载运算符-，作用为将两个矩阵相减
    Mat operator-(const Mat &mat);
    // 重载运算符<<，作用为打印数组元素
    void operator<<(const Mat &mat);
};

Mat::Mat()
{
    m = 0;
    n = 0;
    data = NULL;
}

Mat::Mat(int parm)
{
    m = parm;
    n = parm;
    data = new int[m * n];
    for (int i = 0; i < m * n; i++)
    {
        data[i] = 0;
    }
}

Mat::Mat(int parm1, int parm2)
{
    m = parm1;
    n = parm2;
    data = new int[m * n];
    for (int i = 0; i < m * n; i++)
    {
        data[i] = 0;
    }
}

Mat::Mat(const Mat &mat)
{
    m = mat.m;
    n = mat.n;
    data = new int[m * n];
    for (int i = 0; i < m * n; i++)
    {
        data[i] = mat.data[i];
    }
}

Mat::~Mat()
{
    delete[] data;
    //cout << "Class Mat has been destroyed" << endl;
}

int &Mat::at(int i, int j)
{
    // 合法性检查
    if (i > m || j > n)
    {
        cout << "Wrong index" << endl;
        return exception;
    }
    return data[(i - 1) * n + j - 1];
}

Mat Mat::submat(int i, int j, int p, int q)
{
    // 合法性检查
    if (i > m || j > n || p + i > m || q + j > n)
    {
        cout << "Wrong index" << endl;
        return Mat();
    }
    Mat submat(p, q);
    for (int k = 0; k < p; k++)
    {
        for (int l = 0; l < q; l++)
        {
            submat.at(k + 1, l + 1) = at(i + k, j + l);
        }
    }
    return submat;
}

Mat Mat::resize(int parm1, int parm2)
{
    Mat mat(parm1, parm2); // 申请新的内存
    for (int i = 0; i < parm1; i++)
    {
        for (int j = 0; j < parm2; j++)
        {
            if (i < m && j < n)
            {
                mat.at(i + 1, j + 1) = at(i + 1, j + 1);
            }
            else
            {
                mat.at(i + 1, j + 1) = 0;
            }
        }
    }
    delete[] data; // 释放原来的内存
    return mat;
}

Mat Mat::operator+(const Mat &mat)
{
    // 合法性检查
    if (m != mat.m || n != mat.n)
    {
        cout << "Wrong size" << endl;
        return Mat();
    }
    Mat matSum(m, n);
    for (int i = 0; i < m * n; i++)
    {
        matSum.data[i] = data[i] + mat.data[i];
    }
    return matSum;
}

Mat Mat::operator-(const Mat &mat)
{
    // 合法性检查
    if (m != mat.m || n != mat.n)
    {
        cout << "Wrong size" << endl;
        return Mat();
    }
    Mat matSub(m, n);
    for (int i = 0; i < m * n; i++)
    {
        matSub.data[i] = data[i] - mat.data[i];
    }
    return matSub;
}

void Mat::operator<<(const Mat &mat)
{
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            cout << mat.data[i * mat.n + j] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    // 测试实现
    Mat mat1();
    Mat mat2(3);
    Mat mat3(3, 4);
    Mat mat4(3, 4);
    mat2.at(1, 1) = 1;
    mat2.at(2, 2) = 2;
    mat3.at(1, 2) = 2;
    cout << "Below is the test of Mat::at" << endl;
    mat2.at(4, 3) = 3;//越界，此处会提示wrong index
    mat2 << mat2;
    mat3 << mat3;
    cout << "Below is the test of + -" << endl;
    Mat mat5 = mat4 + mat3;
    Mat mat6 = mat4 - mat3;
    mat5 << mat5;
    mat6 << mat6;
    cout << "Below is the test of submat" << endl;
    Mat mat7 = mat5.submat(1, 1, 2, 2);//此处会打印一个2*2的矩阵
    mat7 << mat7;
    Mat mat8 = mat7.resize(8, 8);
    mat7 = mat5.submat(1, 1, 8, 4);//此处会提示wrong index
    cout << "Below is the test of resize" << endl;
    mat8 << mat8;//此处会打印一个8*8的矩阵

    return 0;
}
