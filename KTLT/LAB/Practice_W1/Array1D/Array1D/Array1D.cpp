
#include <iostream>
#include <vector>
using namespace std;
//18) Sum 3 smallest NEGATIVE NUMBER
void Bai18() {
    int N;
    cin >> N;
    int* a = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    int Ne1=0,Ne2=0,Ne3=0;
    for (int i = 0; i < N;i++){
        if (a[i] < 0) {
            if (a[i] < Ne1) {
                
                Ne1 = a[i];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i] < Ne2 && a[i] < Ne1) {

            Ne2 = a[i];
        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i] < Ne3 && a[i] < Ne2 && a[i] < Ne1) {
            Ne3 = a[i];
        }
    }
    delete[] a;
    int sum = Ne1 + Ne2 + Ne3;
    cout << sum;
    
}
// Bai nay chua on => Theo cach lam bai 16 se tot hon

//16) SUm 3 smallest ODD NUMBER
void Bai16() {
    int n;
    cin >> n;
    vector<int> vec, temp;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    int num1 = 0, num2 = 0, num3 = 0;
    for (size_t i = 0; i < vec.size(); i++) {//Find first ODD
        if (vec[i] % 2) {
            num1 = vec[i];
            break;
        }

    }
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 && vec[i] <= num1) {
            num1 = vec[i];
        }

    }


    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 && vec[i] > num1) {

            temp.push_back(vec[i]);

        }
    }
    if (temp.size()) {
        num2 = temp[0];
        for (size_t i = 1; i < temp.size(); i++) {
            if (temp[i] < num2)
                num2 = temp[i];
        }
    }
    
    temp.clear();

    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 && vec[i] > num1 && vec[i] > num2) {
            temp.push_back(vec[i]);
        }
    }
    if (temp.size()) {
        num3 = temp[0];
        for (size_t i = 1; i < temp.size(); i++) {
            if (temp[i] < num3)
                num3 = temp[i];
        }
    }
    
    temp.clear();

    vec.clear();
    cout << num1 << "  " << num2 << "  " << num3 << endl;
    int sum = num1 + num2 + num3;
    cout << sum;
}



bool isPrime(int n) {
    bool flager = true;
    if (n < 2) flager = false;
    else {
        for (int i = 2; i < n - 1; i++) {
            if (n % i == 0) {
                flager = false;
                break;
            }
        }
    }
    return flager;
}

int main()
{
    int n, m, small, true1 = 1;
    cin >> n>>m;
    int a[99][99], b[99][99];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0, k = 0; i < n; i++, k++) {
        for (int j = 0, h =0; j < n; j++, h++) {
            b[h][k] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}
