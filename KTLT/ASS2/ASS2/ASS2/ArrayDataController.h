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
    //TODO
    array.arr = new Soldier [cap];
    array.size = 0;
    array.capacity = cap;
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if(array.arr != NULL){
        if(array.size >0)
        array.size += 1;
        if((pos >= 0) && (pos < array.size)){
            for(int i = array.size-1 ; i>=pos; i--){
                array.arr[i].HP = array.arr[i-1].HP;
                array.arr[i].ID = array.arr[i-1].ID;
                array.arr[i].isSpecial = array.arr[i-1].isSpecial;
            }
            array.arr[pos-1].HP = element.HP;
            array.arr[pos-1].ID = element.ID;
            array.arr[pos-1].isSpecial = element.isSpecial;
            return 1;
        }
        else return 0;
    }
    else return false;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if(array.arr != NULL){
        for(int i=idx-1; i<array.size-1; i++){
            array.arr[i].HP = array.arr[i+1].HP;
            array.arr[i].ID = array.arr[i+1].ID;
            array.arr[i].isSpecial = array.arr[i+1].isSpecial;
        }
        array.size -= 1;
        return 1;
    }
    else return false;
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    if(array.arr != NULL){
        for(int i=0; i<array.size; i++){
            if(array.arr[i].HP == HP){
                removeAt(array,i+1);
            }
            return 1;
        }
    }
    else return false;
    return false;
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    if(array.arr != NULL){
        array.capacity = newCap;
    }
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if(array.arr != NULL){
        for(int i=0; i<array.size; i++){
            if((array.arr[i].HP == soldier.HP) && (array.arr[i].ID == soldier.ID) && (array.arr[i].isSpecial == soldier.isSpecial)){
                return 1;
            }
        }
    }
    else return -1;
    return -1;
}

int size(Array& array){
    //Return size of the array
    //TODO
    return array.size;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if(array.size != 0){ 
        return 0;
    }
    else return 1;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
    if(array.arr != NULL){
        if((pos >= 0) && (pos < array.size)){
            return array.arr[pos].ID;
        }
        else return "-1";
    }
    else return "-1";
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(array.arr != NULL){
        if((pos >= 0) && (pos < array.size)){
            return array.arr[pos].HP;
        }
        else return -1;
    }
    return -1;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if(array.arr != NULL){
        if((pos > 0) && (pos < array.size)){
            array.arr[pos].HP = HP;
            return 1;
        }
        else return 0;
    }
    else return false;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
    if(array.arr != NULL){
        delete[] array.arr;
    }
    array.arr = NULL;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    if(array.arr != NULL){
        for(int i=0; i<array.size; i++){
            if((array.arr[i].HP == soldier.HP) && (array.arr[i].ID == soldier.ID) && (array.arr[i].isSpecial == soldier.isSpecial)){
                return 1;
            }
        }
    }
    else return false;
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
