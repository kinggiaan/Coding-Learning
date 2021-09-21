// DynamicArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class DynamicArray {
public: 
    int size;
    int capacity;
    float* storage;
    DynamicArray() {
        size = 0;
        capacity = 10;
        storage = new float[capacity];

    }
    DynamicArray(int capacity) {
        size = 0;
        this->capacity = capacity;
        storage = new float[capacity];
    }
    ~DynamicArray() {
        delete[] storage;
    }

    void setcapa(int );
    void ensurecapa(int );
    void pack();
    void trim();

    void rangeCheck(int );
    void set(int, float);
    float get(int);
    void getInsert(int, float);
    void remove(int);

    void print();

};

void DynamicArray::setcapa(int newCapacity) {
    float* newStorage = new float[newCapacity];
    memcpy(newStorage, storage, sizeof(float) * size);
    capacity = newCapacity;
    delete[] storage;
    storage = newStorage;
}

void DynamicArray::ensurecapa(int minCapacity) {
    if (minCapacity > capacity) {
        int newCapacity = (capacity) * 3 / 2 + 1;

        if (newCapacity < minCapacity)
            newCapacity = minCapacity;
        setcapa(newCapacity);
    }
}

void DynamicArray::pack() {
    if (size <= capacity / 2){
        int newCapacity = (size * 3) / 2 + 1;
    setcapa(newCapacity);
    }
}

void DynamicArray::trim() {
    int newCapacity = size;
    setcapa(newCapacity);
}

void DynamicArray::rangeCheck(int idx) {
    if (idx < 0 || idx > size)
        throw "Index out of bounds ";

}

void DynamicArray::set(int idx, float value) {
    rangeCheck(idx);
    storage[idx] = value;
}

float DynamicArray::get(int idx) {
    rangeCheck(idx);
    return storage[idx];
}

void DynamicArray::getInsert(int idx, float value) {
    rangeCheck(idx);
    ensurecapa(size + 1);
    int moveCount = size - idx;
    if (moveCount != 0)
        memmove(storage + idx + 1,
            storage + idx,
            sizeof(float) * moveCount);
    storage[idx] = value;
    size++;
}
void DynamicArray::remove(int idx) {
    rangeCheck(idx);
    int moveCount = size - idx - 1;
    if (moveCount > 0)
        memmove(storage + idx,
            storage + (idx + 1),
            sizeof(float) * moveCount);
    size--;
    pack();
}
void DynamicArray::print() {
    for(int i = 0; i < size; i++) {
        cout << storage[i] << "_";
    }
}

int main()
{
    DynamicArray array;
    array.setcapa(21);
    for (int i = 0; i < 20; i++) {
        array.getInsert(i,float(i));
    }
    for (int i = 16; i < 20; i++) {
        array.getInsert(i, float(i));
    }
    array.print();
    cout << array.size;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
