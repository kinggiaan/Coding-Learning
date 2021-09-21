#include <iostream>
#include<string.h>
#include <vector>
using namespace std;
bool completeNum(int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (N % i == 0) sum += i;
    }
    if (sum == N) return true;
    else return false;
}
long long calcPermutation(vector<int>ar, int n)
{
    static int res = 0;
    int diff = 0;
    static int begin = 0;
    diff = abs(ar[begin] - ar[begin + 1]);
    res += diff;
    if (begin == n - 2) return res;
    begin++;
    return calcPermutation(ar, n);
}
int main() {
    /*int M = 0, N = 0;
    cin >> M >> N;
    string* a = new string[M];
    string* b = new string[N];

    for (int i = 0; i < M; i++)
    {
        cin >> a[i];
        if (i != 0) a[0] += a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        if (i != 0) b[0] += b[i];
    }
    if (a[0] == b[0]) cout << "true";
    else cout << "false";
    cout << "\n";
    int* c = &N;
    cout << c << " " << *c<<endl;

    cout << completeNum(N);
    */
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << calcPermutation(arr, n);
    return 0;
    
}