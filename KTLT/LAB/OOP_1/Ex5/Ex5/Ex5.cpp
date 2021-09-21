#include<iostream>
using namespace std;

class Rectangle {

    
public:
    float h, w;
    Rectangle(float hi, float we) {
        this->h = hi;
        this->w = we;
    };
    ~Rectangle() {};
    void display();
};

void Rectangle::display()
{
    cout << "Info of rectangle: \n";
    cout << "height = " << this->h << ' ' << "width = " << this->w << endl;
}

int main() {
    // TODO
    float hi, we;
    cin >> hi >> we;
    Rectangle* pRec = new Rectangle(hi, we);
    pRec->display();
    Rectangle* ptr = pRec;
    delete pRec;
    ptr->display();
    return 0;
}

