#include <iostream>

using namespace std;
// implement calculate factorial function in here
long fact(int N) {
    if (N == 1) return 1;
    return N * (fact(N - 1));
}


int main(int narg, char** argv)
{
    int N;
    cin >> N;
    long result;
    result = fact(N);


    cout << result << endl;
    return 0;
}