#include<iostream>
#define sub(a,b) a - b
using namespace std;

class Integer {
private:
    int val;
public:
    Integer() {
        //this->val = 0;
    };
    Integer(int);
    Integer(Integer*);
    ~Integer() {};
    void print();

    Integer operator + (Integer const& obj) {
        Integer ans ;
        
        ans.val = val + obj.val;
        return ans;
    }
};

Integer::Integer(int num) {
    this->val = num;
}

Integer::Integer(Integer* num) {
    this->val = num->val;
}


void Integer::print() {
    cout << this->val << endl;
}

int main() {
   /* int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer c(z);
    a.print(); b.print();
    (a + b + c + 4).print();
    */
    cout << 3 * sub(3 - 5, 7 - 8) * 2;
    return 0;
}