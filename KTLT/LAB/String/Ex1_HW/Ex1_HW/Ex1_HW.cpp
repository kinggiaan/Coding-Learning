#include <iostream>
#include <string.h>

using namespace std;

int main() {
    string s = "";

    while (1) {
        cin >> s;
        if (s == "***") break;

        if ((s[0] <= s[1])&& (s[1] <= s[2])) cout << "true" << endl;
        else cout << "false" << endl;
    }

}
