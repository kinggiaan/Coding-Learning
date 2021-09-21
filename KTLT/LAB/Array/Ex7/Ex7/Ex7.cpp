#include <iostream>

using namespace std;

int main()
{
    int n, c = 0;
    int a[99];
    cin >> n;
    if (n < 0) n = n * -1;
    while (n >= 10) {
        a[c] = n % 10;
        n = n / 10;
        c++;
    }
    a[c] = n;
    //for (int i = 0; i <= c; i++) {
//cout << a[i] << " ";
   // }
    int cc = c / 2; //cout << endl <<cc;
    bool flag = true;
    for (int i = 0; i <= cc; i++) {
        if (!(a[i] == a[c - i])) {
            flag = false;
            break;
        }
    }
    if (flag) cout << 1;
    else cout << -1;
}
