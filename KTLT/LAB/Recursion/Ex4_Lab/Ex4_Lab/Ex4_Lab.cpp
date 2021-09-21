#include<iostream>
#include<vector>
using namespace std;
//TODO declare and define sub-functions if needed

void permute(vector<int>ar, int l, int r)
{
    // Base case
    if (l == r)
        return;
    else
    {
        // Permutations made
        for (int i = l; i <= ar.size(); i++)
        {

            // Swapping done
            swap(ar[l], ar[i]);

            // Recursion called
            permute(ar, l + 1, r);

            //backtrack
            swap(ar[l], ar[i]);
        }
    }
}
/*long long calcPermutation(vector<int>ar, int n)
{

    long long sum = 0;
    if (ar.size() <= 2) {
        if (ar.size() == 2) {
            sum = long long(ar[1] - ar[0]);
        }
        else if (ar.size() == 1) sum = ar[0];
    }
    else {
        for (size_t i = 0; i <= ar.size() - 2; i++) {
            sum += abs(ar[i + 1] - ar[i]);
        }
    }

    if (calcPermutation(ar, n) < sum)
        return calcPermutation(ar, n);
    else return sum;
}*/
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
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << calcPermutation(arr, n);
    return 0;
}
