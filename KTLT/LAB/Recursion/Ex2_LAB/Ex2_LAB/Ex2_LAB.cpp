#include<iostream>
#include<vector>
using namespace std;
long long infinite2DArray(int x, int y)
{
    if ((x == 0) && (y == 0)) return 0;
    if (((x == 0) && (y == 1)) || ((x == 1) && (y == 0))) return 1;
    if ((x >= 2) && (y == 0)) return infinite2DArray(x - 1, 0) + infinite2DArray(x - 2, 0);
    if ((x == 0) && (y >= 2)) return infinite2DArray(0, y - 1) + infinite2DArray(0, y - 2);
    if ((x >= 1) && (y >= 1)) return infinite2DArray(x - 1, y) + infinite2DArray(x, y - 1);
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << infinite2DArray(x, y)<<endl;
    string s = "abaa";
    int len = s.length();
    string temp = "";
    temp = s.substr(1, len - 2); cout << temp;
    return 0;
}