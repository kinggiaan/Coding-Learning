#include<iostream>
#include<vector>
using namespace std;
vector<int> per(vector<int> ar, int n) {
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = ar[n - i -1];
    }
    return temp;
}
long long calcPermutation(vector<int>ar, int n)
{
    ar = per(ar, n);

    return 1;
}
int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << arr[0];
   // cout << calcPermutation(arr, n);
    return 0;
}
