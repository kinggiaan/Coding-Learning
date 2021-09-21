//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise 0 1 2
    if (pos > list.size || pos < 0) return false;
    else {
        SoldierNode* head = list.head;
        if (pos == 0) {
            list.size++;
            if (head == NULL) {
                SoldierNode* temp = new SoldierNode;
                temp->data.HP = element.HP;
                temp->data.ID = element.ID;
                temp->data.isSpecial = element.isSpecial;
                head = temp;
                list.head = head;
            }
            else {
                SoldierNode* temp = new SoldierNode;
                temp->data.HP = element.HP;
                temp->data.ID = element.ID;
                temp->data.isSpecial = element.isSpecial;
                
                temp->next = head;
                list.head = temp;

            }
        }
        else if (pos == list.size) {
            SoldierNode* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            SoldierNode* temp = new SoldierNode;
            temp->data.HP = element.HP;
            temp->data.ID = element.ID;
            temp->data.isSpecial = element.isSpecial;

            tmp->next = temp;
            list.head = head;
            list.size++;

        }
        else { //0 ->1 -> 2 -> 3  4
            SoldierNode* tmp = head;
            SoldierNode* temp = new SoldierNode;
            temp->data.HP = element.HP;
            temp->data.ID = element.ID;
            temp->data.isSpecial = element.isSpecial;
            for (int i = 0; i < pos - 1; i++) {
                tmp = tmp->next;
            }
            temp->next = tmp->next;
            tmp->next = temp;
            list.head = head;
            list.size++;

        }
        return true;
    }
    
    
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    if (idx >= list.size || idx < 0 || list.head == NULL) return false;
    else {
        SoldierNode* head = list.head;
        if (idx == 0) {
            
            SoldierNode* tmp = head;
            tmp = tmp->next;
            delete head;
            list.head = tmp;

        }
        else if (idx == list.size - 1) {// 0 1 2 3 
            SoldierNode* tmp = head;
            while (tmp->next->next != NULL) {
                tmp = tmp->next;
            }
            delete tmp->next;
            tmp->next = NULL;
            list.head = head;
        }
        else {
            SoldierNode* tmp = head;// 0 1 2 3 
            for (int i = 0; i < idx - 1; i++) {
                tmp = tmp->next;
            }
            SoldierNode* dele = tmp->next;
            tmp->next = tmp->next->next;
            delete dele;
            list.head = head;

        }
        list.size--;
        return true;
    }
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    SoldierNode* head = list.head;
    SoldierNode* tmp = list.head;
    bool flag = false;
    int pos = 0;
    while (tmp != NULL) {
        if (HP == tmp->data.HP) {
            flag = true;
            break;
        }
        pos++;
        tmp = tmp->next;

    }
    if (flag) {
        return removeAt(list, pos);
    }
    
    else return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    SoldierNode* head = list.head;
    SoldierNode* tmp = list.head;
    bool flag = false;
    int pos = 0;
    while (tmp != NULL) {
        if (soldier.HP == tmp->data.HP &&
            soldier.ID == tmp->data.ID &&
            soldier.isSpecial == tmp->data.isSpecial) {
            flag = true;
            break;
        }
        pos++;
        tmp = tmp->next;

    }
    if (flag) {
        return pos;
    }

    else return -1;
    
}

int size(SLinkedList& list){
    //Return size of the list
    
    
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    if (list.size != 0) return false;
    else return true;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    SoldierNode* tmp = list.head;
    while (tmp != NULL) {
        SoldierNode* temp = tmp;
        tmp = tmp->next;
        delete temp;
    }
    list.head = NULL;
    list.size = 0;
    
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    if (pos >= list.size || pos < 0 || list.head == NULL) return "-1";
    else {
        string ans = "-1";
        //SoldierNode* head = list.head;
        SoldierNode* tmp = list.head;
        for (int i = 0; i < pos; i++) {
            tmp = tmp->next;
        }
        ans = tmp->data.ID;

        return ans;
    }
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    if (pos >= list.size || pos < 0 || list.head == NULL) return -1;
    else {
        int ans = -1;
        //SoldierNode* head = list.head;
        SoldierNode* tmp = list.head;
        for (int i = 0; i < pos; i++) {
            tmp = tmp->next;
        }
        ans = tmp->data.HP;

        return ans;
    }
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    if (pos >= list.size || pos < 0 || list.head == NULL) return false;
    else {
        //SoldierNode* head = list.head;
        SoldierNode* tmp = list.head;
        for (int i = 0; i < pos; i++) {
            tmp = tmp->next;
        }
        tmp->data.HP = HP;

        return true;
    }
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    SoldierNode* head = list.head;
    SoldierNode* tmp = list.head;
    bool flag = false;
    while (tmp != NULL) {
        if (soldier.HP == tmp->data.HP &&
            soldier.ID == tmp->data.ID &&
            soldier.isSpecial == tmp->data.isSpecial) {
            flag = true;
            break;
        }
        tmp = tmp->next;

    }
    return flag;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
