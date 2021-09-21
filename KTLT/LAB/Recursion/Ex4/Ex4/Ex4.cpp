#include<iostream>
using namespace std;
long long superPow(long long a, long long b)
{
    
   
    if (b % 2 == 0)
    {
        if (b == 2)
            return (a * a) % 1000000007;
        else {
            int nb = b / 2;
            return (superPow(a, nb) % 1000000007) * (superPow(a, nb) % 1000000007);
        }
    }
    else {
        if (b == 1) return a % 1000000007;
        else
        {
                    int nb = (b - 1) / 2;
            return ((superPow(a, nb) % 1000000007) * (superPow(a, nb) % 1000000007) * (a) % 1000000007);
        }
    }
}
 
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << superPow(a, b);
    return 0;
}