#include<iostream>
using namespace std;
int gcdRecursion(int p, int q)
{
    
    int b, s;
    if (p < q) { b = q; s = p; }
    else {
        b = p; s = q;
    }
    if (s != 0) return gcdRecursion(s, b % s);
    else return b;
}
int gcdIteration(int p, int q)
{
    if (!p || !q) return 0;
    int small, gcd = 1;
    if (p < q) small = p;
    else small = q;
    for (int i = 2; i <= small; i++) {

        if ((p % i == 0) && (q % i == 0)) {
            gcd = i;
        }
    }
    return gcd;
}
int main()
{
    int p, q;
    cin >> p >> q;
    cout << gcdRecursion(p, q) << " " << gcdIteration(p, q);
    return 0;
}
