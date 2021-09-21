// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string clean(string s,size_t pos) {
    for (size_t i = pos; i < s.length(); i++) {
        
            s[i] = s[i + 1];
        
    }
    return s;
}
int main()
{
    string s;
    cin >> s;
    bool flag = true;
    int count = 0;
    int len = s.length();
    
       // for (size_t j = 0; j < s.length(); j++) {
    for (size_t i = 0; i < s.length() - 1; i++) {
        if (s[i] != s[i + 1]) {
            count++;
            i++;
        }
    }
        for (int j = 0; j < count; j++) {
            for (size_t i = 0; i < s.length() - 1; i++) {
                if (s[i] != s[i + 1]) {
                    s[i] = ' ';
                    s[i + 1] = ' ';
                    s = clean(s, i);
                    s = clean(s, i);
                    len -= 2;
                    break;

                }
            }

        }
        
    

    cout << len;
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
