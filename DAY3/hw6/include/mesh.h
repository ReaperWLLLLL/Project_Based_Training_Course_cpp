//mesh主类的声明
#include <iostream>
#include "bd2no.h"
#include "el2no.h"
#include "no2xy.h"
#include <map>
#include <vector>

class Mesh{
    private:
        vector<Bd2no> bd2noVec;
        vector<El2no> el2noVec;
        vector<No2xy> no2xyVec;
    public:
        Mesh();
        Mesh(vector<Bd2no> bd2noVec, vector<El2no> el2noVec, vector<No2xy> no2xyVec);
        ~Mesh();
        void readall(string filename);//这个函数理论上是不是该在构造函数里面调一下？
        void sort_element(string name, bool scend);//选择通过哪个排序，升序还是降序，scend为true时升序
        void sort_boundary(string name, bool scend);
        void sort_node(string name, bool scend);
        vector<El2no> find_mid_element(string attr, int lowerbound, int upperbound);
        vector<Bd2no> find_mid_boundary(string attr, int lowerbound, int upperbound);
        vector<No2xy> find_mid_node(string attr, double lowerbound, double upperbound);
        void display();
        void display(string name);
};