#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void process1(string fileName) {
    ifstream iFs;
    iFs.open(fileName);
    string string1;
    if (iFs.is_open()) {
        getline(iFs, string1);
    }
    iFs.close();
    int length = string1.length();
    int space = 0, num = 0, alpha = 0;
    for (int i = 0; i < length; i++) {
        if (string1[i] == 32)  space++;
        if ((string1[i] <= 57) && (string1[i] >= 48)) num++;
        if ((string1[i] <= 122) && (string1[i] >= 97)) alpha++;
        //cout << string1[i] << endl;
    }
    cout << space << " " << length << " " << alpha++;



}
/*int main() {
    const char* filename = "testcase.txt";
    process(filename);
    return 0;
}*/
#include <iostream>
#include<string.h>

using namespace std;


void process(string fileName) {
    ifstream file;
    file.open(fileName, ios::in);
    size_t num = 0;
    double aveW = 0, aveH = 0;
    if (file.is_open()) {
        file >> num;
        double* H = new double[num], * W = new double[num];
        for (size_t i = 0; i < num; i++) {
            string data;
            file>> data;
            size_t found=0;
            size_t start=0, end=0;

            for (size_t j = 0; j < data.length(); j++) {
                if (data[j] == ','){
                 found++;
                 if (found == 3) { start = j + 1; }
                 else if (found == 4) {
                    end = j - 1;
                    H[i] = stod(data.substr(start, start - end + 1));//12345
                    start = j + 1;
                    W[i] = stod(data.substr(start, start - data.length()));

                }
                }
            }
            aveH += H[i]; aveW += W[i];
        }
        aveH = aveH /double(num);aveW = aveW / double(num);
        cout << aveH << " " << aveW;
        delete[]H;
        delete[] W;
    }
    file.close();
}
int main() {
    string s="testcase.txt";
    process(s);
    /*int temp = 1, last = 0;
    for (size_t i = 0; i < s.length() ; i++) {

        if (s[i] == s[i + 1]) temp++;
        else temp = 1;
        if (temp > last) last = temp;

    }
    cout << last;
    */
}