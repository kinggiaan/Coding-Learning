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

void mergethenSort(SoldierNode** headerf);
SoldierNode* sortedthenMerge(SoldierNode* a, SoldierNode* b);
void Split(SoldierNode* source, SoldierNode** frontRef, SoldierNode** backRef);
//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier) {
    //Return true if push successfully, false otherwise

    if (array.size == 0) {

        if (array.capacity == 0) initArray(array, 1);
        //else ensureCapacity(array, array.capacity * 1.5);
        //array.arr[0].HP = soldier.HP;
        //array.arr[0].isSpecial = soldier.isSpecial;
        //array.arr[0].ID = soldier.ID;
        return insertAt(array, soldier, 0);

    }
    else return insertAt(array, soldier, array.size);
}

bool pop(Array& array) {
    //Return true if pop successfully, false otherwise
    if (array.arr == NULL) return false;
    else {
        if (array.size == 0) return false;
        else { // 5 0 1 2 3 4
            array.size--;
            array.arr[array.size].HP = 0;
            array.arr[array.size].isSpecial = 0;
            array.arr[array.size].ID = "";

            return true;
        }
    }
}

Soldier top(Array& array) {
    if (array.size == 0) return Soldier();//return this if cannot get top
    else return array.arr[array.size - 1];
}

//////////////////////////////////////////////////////  
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier) {
    //Return true if enqueue successfully, false otherwise


    return insertAt(list, soldier, list.size);
}

bool dequeue(SLinkedList& list) {
    //Return true if dequeue successfully, false otherwise
    //TODO

    return removeAt(list, 0);
}

Soldier front(SLinkedList& list) {
    if (list.head == NULL) return Soldier();//Return this if cannot get front
    else return list.head->data;
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list) {
    SoldierNode* head = list.head;
    SoldierNode* curr = head;
    SoldierNode* pre = NULL, * next = head;
    while (curr != NULL) {
        next = next->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    head = pre;
    list.head = head;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2) {
    //TODO
    if (list1.size == 0) return list2;
    else if (list2.size == 0) return list1;
    else {
        SLinkedList both;
        both.head = NULL;
        both.size = list1.size + list2.size;
        SoldierNode* a = list1.head;
        SoldierNode* b = list2.head;
        both.head = a;
        SoldierNode* tmp = both.head;

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = b;


        mergethenSort(&both.head);


        return both;
    }
}

//You can write your own functions here
void mergethenSort(SoldierNode** headrf) {
    SoldierNode* head = *headrf;
    SoldierNode* a = NULL; SoldierNode* b = NULL;

    //Base
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    //Slipt
    Split(head, &a, &b);

    //Sort recur
    mergethenSort(&a);
    mergethenSort(&b);

    //Merge 2 sorted list
    *headrf = sortedthenMerge(a, b);



}


SoldierNode* sortedthenMerge(SoldierNode* a, SoldierNode* b) {
    SoldierNode* result = NULL;

    // Base
    if (a == NULL) return b;
    else if (b == NULL) return a;

    //Choose and recur
    /// ////////
    
    if (a->data.HP != b->data.HP) {
        if (a->data.HP < b->data.HP) {
            result = a;
            result->next = sortedthenMerge(a->next, b);
        }
        else {
            result = b;
            result->next = sortedthenMerge(a, b->next);
        }
    }
    else if (a->data.isSpecial != b->data.isSpecial){
       if  (a->data.isSpecial) {
           result = b;
           result->next = sortedthenMerge(a, b->next);
       }
       else {
           result = a;
           result->next = sortedthenMerge(a->next, b);
           
       }
    }
    else if (a->data.ID != b->data.ID) {
        if (a->data.ID < b->data.ID) {
            result = a;
            result->next = sortedthenMerge(a->next, b);
        }
        else {
            result = b;
            result->next = sortedthenMerge(a, b->next);
        }
    }
    else {
        result = a;
        result->next = sortedthenMerge(a->next, b);
    }
    return result;

}



void Split(SoldierNode* source, SoldierNode** begin, SoldierNode** end) {
    SoldierNode* fast;
    SoldierNode* slow;

    fast = source->next;
    slow = source;

    //Slow move 1 step, Fast move 2 steps

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *begin = source;
    *end = slow->next;
    slow->next = NULL;
}
//End your own functions

#endif /* thirdBattle_h */
#pragma once
