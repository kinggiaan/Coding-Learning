#include<iostream>
#include<vector>
using namespace std;
bool checkDuplicate(vector<int> ar)
{
    
    if (ar.size() == 1) return true;
    for (size_t i = 1; i < ar.size(); i++) {
        if (ar[0] == ar[i])
            return  false;
        
    }
    vector<int> curar = ar;
    curar.erase(curar.begin());
    return checkDuplicate(curar);
}
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];
    cout << checkDuplicate(ar);
    return 0;
}

