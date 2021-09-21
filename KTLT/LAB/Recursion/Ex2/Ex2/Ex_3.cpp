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
    if ((s.length() == 0) || (s.length() == 1)) return true;
    if (s[0] == s[s.length() - 1]) {
        string temp = "";

        for (int i = 1; i < s.length() - 1; i++) {
            temp += s[i];
        }
        return true * palindromeRecursion(temp);
    }
    else return false;
    return true;

}
int main()
{
    while (true) {
        string s;
        cin >> s;
        if (s == "*") break;

        else {
            if (palindrome(s)) cout << "true ";
            else cout << "false ";
            if (palindromeRecursion(s)) cout << "true" << endl;
            else cout << "false" << endl;
        }
    }
    return 0;
}


