// TowerHanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
void move(int n, char source, char desti, char auxi) {
    static int step = 0;
    if (n == 1) {
        cout << "Step " << ++step << " Move from "
            << source << " to " << desti << endl;
    }
    else {
        move(n - 1, source, auxi, desti);
        move(1, source, desti, auxi);
        move(n - 1, auxi, desti, source);
    }
    return;
    }
bool checkConstDigi(string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!(str[i] < 57 && str[i] > 48)) return false;
    }
    return true;
}
bool checkConstString(string str) {

    for (size_t i = 0; i < str.length(); i++) {
        if (!((str[i] <= 90 && str[i] >= 65) || (str[i] >= 97 && str[i] <= 122)|| (str[i] < 57 && str[i] > 48)||str[i]==32)) return false;
    }
    return true;
}
string deleteQuote(string str) {
    return str.substr(1, str.length() - 2);
}
bool checkQuote(string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == 39) return true;
    }
    return false;
}
int main()
{
    string str = "";
    while (1) {
        getline(cin,str);
        if (str == "***") break;
        cout << checkQuote(str) << endl;
        
    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
