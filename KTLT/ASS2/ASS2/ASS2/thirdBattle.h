//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
    if(array.size >= 0){
        if(array.size == 0){
            array.size += 1;
            array.arr[0] = soldier;
            return 1;
        }
        else {
            array.size += 1;
            array.arr[array.size-1] = soldier;
            return 1;
        }
    }
    else return 0;
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    if(array.size > 0){
        --array.size;
        return 1;
    }
    else return 0;
}

Soldier top(Array& array){
    //TODO
    if(array.size > 0){
        return array.arr[array.size-1];
    }
    else return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO

    SoldierNode* tmp = new SoldierNode; 
    SoldierNode* sd = new SoldierNode;
    (*sd).data = soldier;
    (*sd).next = NULL;
    if(list.head == NULL){
        list.head = sd;
    }
    else {
        tmp = list.head;
        while((*tmp).next != NULL){
            tmp = (*tmp).next;
        } 
        (*tmp).next = sd;
    }
    list.size += 1;
    return 1;
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    if(list.head != NULL){
        list.size -= 1;
        SoldierNode* tmp = new SoldierNode;
        tmp = list.head;
        list.head = (*(list.head)).next;
        delete tmp;
        return 1;
    }
    else return false;
}

Soldier front(SLinkedList& list){
    //TODO
    if(list.head != NULL){
        return (*(list.head)).data;
    }
    else return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO
    SoldierNode* tmp = new SoldierNode;
    SoldierNode* rev = NULL;
    SoldierNode* tmp1 = NULL;
    tmp = list.head;
    while(tmp != NULL){
        tmp1 = (*tmp).next;
        (*tmp).next = rev;
        rev = tmp;
        tmp = tmp1;  
    }
    list.head = rev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////
void swap(Soldier &x, Soldier &y){
    Soldier tmp = x;
    x = y;
    y = tmp;
}

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
    SLinkedList result;
    result.head = NULL;
    result.size = list1.size + list2.size;
    if(list1.head == NULL){
        result = list2; 
        return result;
    } 
    else if(list2.head == NULL){
        result = list1;
        return result;
    }
    else if((list1.head == NULL) && (list2.head == NULL)){
        return result;
    } 
    else{
        result.head = list1.head;
        SoldierNode* tmp = result.head;
        while((*tmp).next != NULL){
            tmp = (*tmp).next;
        }
        (*tmp).next = list2.head;
        SoldierNode* tmp1 = result.head;
        while((*tmp1).next != NULL){
            SoldierNode* tmp2 = (*tmp1).next;
            while(tmp2 != NULL){
                if(((*tmp1).data).HP > ((*tmp2).data).HP){
                    swap((*tmp1).data,(*tmp2).data);
                }
                if(((*tmp1).data).HP == ((*tmp2).data).HP){
                    if(((*tmp1).data).isSpecial > ((*tmp2).data).isSpecial){
                        swap((*tmp1).data,(*tmp2).data);
                    }
                    if(((*tmp1).data).isSpecial == ((*tmp2).data).isSpecial){
                        if(((*tmp1).data).ID > ((*tmp2).data).ID){
                            swap((*tmp1).data,(*tmp2).data);
                        }
                    }
                } 
                tmp2 = (*tmp2).next;   
            }
            tmp1 = (*tmp1).next;
        }
        return result;
    }
    return SLinkedList();
}

//You can write your own functions here

//End your own functions


#endif /* thirdBattle_h */
