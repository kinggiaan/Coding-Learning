#include<iostream>

#include<iomanip>
#include <math.h>
using namespace std;

class Course {
private:
    int ID;
    int numOfStudent;
    int numOfTeacher;
    int numOfTA;
public:
    void getinfo();
    void disinfo();
};

void Course::getinfo() {
    cout << "ID: ";
    cin >> ID;
    cout << "Number of Students: ";
    cin >> numOfStudent;
    cout << "Number of Teachers: ";
    cin >> numOfTeacher;
    cout << "Number of TAs: ";
    cin >> numOfTA;
}

void Course::disinfo()
{
    cout << endl;
    cout << "CourseID = " << ID << endl;
    cout << "Number of student = " << numOfStudent << endl;
    cout << "Number of teacher = " << numOfTeacher << endl;
    cout << "Number of TA = " << numOfTA << endl;
}


template <class T, class T1>
T sum(T a, T1 b) {
    return a + b;
}

class NODE
{public:
    int data;
    NODE* next;
};


class Rectangle
{
private:
    double width=5;
    double height;
protected:
    double protect = 10;
public:
    double test = 5;
    void setWidth(double);
    void setHeight(double);
    double getWidth();
    double getHeight();
    double getArea();
};

void Rectangle::setWidth(double w) {
    width = w;
}
double Rectangle::getWidth() {
    return width;
}


class Shape {
    int id;
public:
    Shape() { id = 0; }
    ~Shape();
    void draw();
};
class Polygon : public Shape {
    int nVertex;
   // Vector2D* pVertex;
public:
    Polygon(int n) : Shape(), nVertex(n) {}
    ~Polygon();
    void draw();
};


/*int main() {
    int n;
    cin >> n;
    Course* a = new Course[n];
    for (int i = 0; i < n; i++) {
        a[i].getinfo();
        a[i].disinfo();
    }
    //Rectangle A;
    //A.width;
    //A.setWidth(5);
    //cout << A.test << endl;
    //cout << A.getWidth() << endl;
    //cout<< sum(15.5, 5) << endl;
    int n;
    cin >> n;

    if (n < 0) n = n * (-1);
    int temp = n, num = 1;
    while (temp> 10) {
        temp = temp / 10;
        num++;
    }
    int* a = new int[num];
    for (int i = 0; i < num; i++) { 
        a[i] = n % 10;
        n = n / 10;
    }
    for (int i = 0; i < num; i++) {
        cout << a[i]<<endl;
    }
    
    return 0;
}*/
int main(){
    double ans = 1;
    double n;
    cin >> n;
    double num1, num2,dif;
    num1 = 1 - pow(-1, 1) / (1 * (1 + 1));
    num2 = 1 - pow(-1, 2) / (2 * (2 + 1));
    dif = num1 - num2;
    while(dif>) {
        ans += pow(-1, i) / (i * (i+1));
    }
    cout << setprecision(10) << fixed << ans;
    cout << setprecision(10) << ans<<endl;
   
}