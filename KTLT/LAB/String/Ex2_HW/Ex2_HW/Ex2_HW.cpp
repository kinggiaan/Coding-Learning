/*#include <iostream>
#include<string.h>


using namespace std;

int convertBitoDec(string s){
    int size = s.length() -1;
    int sum = 0;
    for (int i = size, h = 0; i >= 0; i--,h++) {
        int pow = 1;
        
            for (int i = 1; i <= h; i++) {
                pow = pow * 2;
            }
        
        if (s[i] == '1') {
            sum += pow;
        }
        
    }
    return sum;
}
string convertDectoBi(int num) {
    string s = "";
    //int temp = num;
    if (num == 0) return "0";
    while (num >= 1) {
        if (num % 2==1) {
            s = "1" + s;
            num = num / 2;
        }
        else {
            s = "0" + s;
            num = num / 2;
        }
    }
    return s;
}
int main() {
    string m, n;
    cin >> n >> m;
    cout << convertDectoBi(convertBitoDec(n)+convertBitoDec(m))<<endl;
    


}*/
#include <iostream>
using namespace std;
enum designFlags {
    BOLD = 1,//1
    ITALICS = 2,
    UNDERLINE = 4//100
};
int main()
{
    int myDesign = BOLD | UNDERLINE;
    cout << myDesign;
    return 0;
}
