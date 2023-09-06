//vscode在多文件编译时的劣势已经体现的淋漓尽致了，准备换用cmake
#include <iostream>
#include "include/mesh.h"

using namespace std;

int main()
{
    Mesh mesh;
    mesh.readall("mesh.txt");
    mesh.sort_element("no1", true);
    mesh.sort_boundary("bd", false);
    mesh.sort_node("x", true);
    vector<El2no> result = mesh.find_mid_element("no1", 1, 3);
    for (int i = 0; i < result.size(); i++)
    {
        result[i].display();
    }
    //mesh.display();
    return 0;
}