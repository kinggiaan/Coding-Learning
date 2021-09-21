//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

void ensureCapacity(Array& array, int newCap);
void moveRightRestArray(Array array, int pos);
void moveLeftRestArray(Array array, int pos);
void CoutArray(Array& array);
//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    array.arr = new Soldier[cap];
    array.capacity = cap;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise  0 0 
    if ((pos > array.size ) || (pos < 0) || (array.arr == NULL) ) return false;
    else {
        if (pos == array.capacity) ensureCapacity(array,int( double(array.capacity) * 1.5));
        if (!(pos >= array.size)) {
            moveRightRestArray(array, pos);
            array.arr[pos].HP = element.HP;
            array.arr[pos].isSpecial = element.isSpecial;
            array.arr[pos].ID = element.ID;

           
        }
        else {
            array.arr[pos].HP = element.HP;
            array.arr[pos].isSpecial = element.isSpecial;
            array.arr[pos].ID = element.ID;

            
        }
        array.size++;

        
        return true;
    }
}

bool removeAt(Array& array, int idx) {
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise 
    if (array.arr == NULL || array.size == 0) return false;
    else {
        if ((idx >= array.size ) || (idx < 0)) return false;
        else {

            moveLeftRestArray(array, idx);
            array.arr[array.size].HP = 0;
            array.arr[array.size].isSpecial = 0;
            array.arr[array.size].ID = "";
            array.size--;
            return true;
        }
    }
}
bool removeFirstItemWithHP (Array& array, int HP){ //LOI SAU KHI CHAY XONG
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    if (array.arr == NULL || array.size == 0) return false;
    else {
        bool flag = false;
        for (int i = 0; i < array.size; i++) {
            if (array.arr[i].HP == HP) {
                flag = removeAt(array, i);

                break;
            }
        }
      
        return flag;
    }
}

void ensureCapacity(Array& array, int newCap){ // XEM SAU
    //Extend the capacity of the array
    // Newcap should newCap= cap*1.5;
    if (newCap == 1) newCap = 2;
    Array temp;
    initArray(temp, array.capacity);
    temp.size = array.size;
    for (int i = 0; i < array.size; i++) {
        temp.arr[i].HP = array.arr[i].HP;
        temp.arr[i].ID = array.arr[i].ID;
        temp.arr[i].isSpecial = array.arr[i].isSpecial;
    }
    delete [] array.arr;
    array.arr = NULL;
    initArray( array, newCap);
    
    for (int i = 0; i < temp.size; i++) {
        array.arr[i].HP = temp.arr[i].HP;
        array.arr[i].ID = temp.arr[i].ID;
        array.arr[i].isSpecial = temp.arr[i].isSpecial;
    }
    array.size = temp.size;
    delete [] temp.arr;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    if (array.arr == NULL || array.size == 0) return -1;
    else {
        int ans = -1;
        for (int i = 0; i < array.size; i++) {
            if (array.arr[i].HP == soldier.HP &&
                array.arr[i].ID == soldier.ID &&
                array.arr[i].isSpecial == soldier.isSpecial)
            {
                ans = i;
                break;
            }
        }

        return ans;
    }
}

int size(Array& array){
    //Return size of the array
    
    
    return array.size; 
}

bool empty(Array& array){
    //Check whether the array is empty
    if (array.size == 0) return true;
    else return false;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos  
    size_t p = pos;
        string ans = "";
        if (pos<0 || pos >= array.size || array.size == 0 || array.arr == NULL) ans = "-1";
        else ans = array.arr[p].ID;

        return ans;
 }


int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos 0
    if (array.arr == NULL || array.size == 0) return -1;
    else {
        int ans = -1;
        if (pos<0 || pos >= array.size ) ans = -1;
        else {
            
            ans = array.arr[pos].HP;
        }
        return ans;
    }
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos<0 || pos > array.size - 1 || array.arr ==NULL || array.size == 0) return false;
    else {
        array.arr[pos].HP = HP;
        return true;
    }
}

void clear(Array& array){
    //Delete all of the elements in array
    delete [] array.arr;
    array.arr = NULL;
    array.capacity = 0;
    array.size = 0;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    if (array.arr == NULL || array.size == 0) return false;
    else {
        int ans = false;
        for (int i = 0; i < array.size; i++) {
            if (array.arr[i].HP == soldier.HP &&
                array.arr[i].ID == soldier.ID &&
                array.arr[i].isSpecial == soldier.isSpecial) {
                ans = true;
                break;
            }
        }

        return ans;
    }
}


//You can write your own functions here
void moveRightRestArray(Array array, int pos) {//dich chuyen phan RIGHT con lai cua Array
    for (int i = array.size; i >= pos; i--) {
        array.arr[i + 1].HP = array.arr[i].HP;
        array.arr[i + 1].isSpecial = array.arr[i].isSpecial;
        array.arr[i + 1].ID = array.arr[i].ID;
    }   
}

void moveLeftRestArray(Array array, int pos) {
    for (int i = pos; i < array.size - 1; i++) {
        array.arr[i].HP = array.arr[i+1].HP;
        array.arr[i].isSpecial = array.arr[i+1].isSpecial;
        array.arr[i].ID = array.arr[i+1].ID;
    }
}
void CoutArray(Array& array) {
    cout << "Current array: " << endl;
    for (int i = 0; i < array.capacity ; i++) {
        cout << array.arr[i].HP << "  " << array.arr[i].isSpecial << "  " << array.arr[i].ID << endl;
    }
    cout << endl;
}
//End your own functions

#endif /* ArrayDataController_h */
