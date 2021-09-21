#include <iostream>

using namespace std;

class Coordinate {
    
public:
    float x, y;
    Coordinate(float a,float b) {
        x = a; y = b;
    }
   // ~Coordinate();
    void setX(float X) {
        x = X;
    }
    void setY(float Y) {
        y = Y;
    }
    float getX() {
        return x;
    };
    float getY() {
        return this->y;
    }
    float distanceTo(Coordinate& next) {
        float dis;
        dis = abs(this->x - next.x) + abs(this->y - next.y);
        return dis;
    }
};

int main() {
    float Xa, Xb, Ya, Yb;
    cin >> Xa >> Xb >> Ya >> Yb;
    Coordinate a(1, 2);
    Coordinate b(0, 1);
    cout << a.distanceTo(b) << endl;
    a.setX(Xa); a.setY(Ya);
    b.setX(Xb); b.setY(Yb);
    cout << abs(a.getX() - b.getX()) + abs(a.getY() - b.getY()) << endl;
    cout << a.distanceTo(b) << endl;
    cout << abs(Xa - Xb) + abs(Ya - Yb);
    return 0;
}