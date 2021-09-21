#include<iostream>
#include<string>
using namespace std;
bool palindrome(string strg)
{
    int len, k, j;
    len = strg.length();
    k = len / 2;
    j = 0;
    bool palin = true;
    while (j < k && palin)
        if (strg[j] != strg[len - 1 - j])
            palin = false;
        else
            ++j;
    return (palin);
}
bool palindromeRecursion(string s)
{
    int len = s.length();
    if (len <= 1) return true;
    string temp = "";
    temp = s.substr(1, len - 2);
    if (s[0] == s[len - 1]) return (true && palindromeRecursion(temp));
    else return false;
    return true;

}
int main()
{
    string s = "";
    while (1) {
        cin >> s;
        if (s == "*") break;
        if (palindrome(s)) cout << "true" << " ";
        else cout << "false" << " ";
        if (palindromeRecursion(s)) cout << "true" << endl;
        else cout << "false" <<endl;
    }

}


