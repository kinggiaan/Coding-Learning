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
    //Return true if insert successfully, false otherwise
    //TODO
    bool flag = false;
    if(list.head != NULL){
        if((pos < 0) || (pos > list.size)) 
            flag = false;
	    else{	
        SoldierNode* sd = new SoldierNode;
        (*sd).data = element; 
        (*sd).next = NULL;
        SoldierNode* tmp = new SoldierNode;
            if (pos == 0){
                (*sd).next = list.head;
                list.head = sd;
                list.size++;
                flag = true;
            }
            else if((pos > 0) && (pos < list.size)){
                tmp = list.head;
                for(int i=0; i<pos-1; i++){
                    tmp = (*tmp).next;
                }
                SoldierNode* tmp1 = (*tmp).next;
                (*tmp).next = sd;
                (*sd).next = tmp1;
                list.size++;
                flag =  true;
            }
            else if(pos == list.size){
                tmp = list.head;
                while((*tmp).next != NULL){
                    tmp = (*tmp).next;
                }
                (*tmp).next = sd;
                list.size++;
                flag =  true;
            }
            
        }
    }
    else {
        if (pos == 0) {
            SoldierNode* tmp = new SoldierNode;
            tmp->data = element;
            tmp->next = NULL;
            list.head = tmp;
            list.size++;
            flag = 1;
        }
        else flag = 0;
    }
    return flag;
}
bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO 0 1 2 3 size 4 pos 4
    bool flag = false;
    SoldierNode* tmp = new SoldierNode;
    SoldierNode* tmp1 = new SoldierNode;
    if(list.head != NULL){
        if((idx < 0) || (idx >= list.size))
            flag = 0;
        else{
            if(idx == 0){
                tmp = list.head;
                list.head = (*(list.head)).next;
                delete tmp;
                list.size -= 1;
                flag = 1;
            }
            else if((idx > 0) && (idx < list.size)){
                int s = 1;
                tmp = list.head;
                while(s < idx){
                    tmp = (*tmp).next;
                    s += 1;
                }
                tmp1 = (*tmp).next;
                *tmp = *tmp1;
                delete tmp1;
                list.size -= 1;
                flag = 1;
            }
            else{
                tmp = list.head;
                for(int i=0; i<list.size; i++){
                    while((*tmp).next != NULL){
                        tmp = (*tmp).next;
                    }
                    (*tmp).next = NULL;
                    list.size -= 1;
                    flag = 1;
                }
            }
            
        }   
    }
    else flag = false;
    return flag;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    int idx = 0;
    SoldierNode* tmp = new SoldierNode;
    tmp = list.head;
    if(list.head != NULL){
        while(tmp != NULL){
            if(tmp->data.HP == HP){
                removeAt(list,idx);
                tmp = NULL;
                delete tmp;
                return -1;
                break;
            }
            else{
                idx += 1;
                tmp = (*tmp).next;
            } 
        }
        tmp = NULL;
        delete tmp;
        return -1;
    }
    else return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    SoldierNode* tmp = new SoldierNode;
    tmp = list.head;
    if(list.head != NULL){
        while(tmp != NULL){
            if((((*tmp).data).HP == soldier.HP) && (((*tmp).data).ID == soldier.ID) && (((*tmp).data).isSpecial == soldier.isSpecial)){
                return 1;
            }
            else tmp = (*tmp).next;
        }
        tmp = NULL;
        delete tmp;
        return -1;
    }
    else return -1;
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    if(list.head == NULL){
        return 0;
    }
    else return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if(list.head == NULL){
        return true;
    }
    else return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    SoldierNode* tmp = new SoldierNode;
    if(list.head != NULL){
        while(list.head != NULL){
        tmp = list.head;
        list.head = (*list.head).next;
        free(tmp);
        }
        list.size = 0;
    }
    delete tmp;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
    int s = 0; // s ~ size;
    string id;
    if(list.head != NULL){
        SoldierNode* tmp = new SoldierNode;
        tmp = list.head;
        if((pos >= 0) && (pos < list.size)){
            while(s < pos){
                tmp = (*tmp).next;
                s += 1; 
            }
            id = ((*tmp).data).ID;
            tmp = NULL;
            delete tmp;
            return id;
        }
        else return "-1";  
    }
    else return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
    int s = 0;
    int hp;
    if(list.head != NULL){
        SoldierNode* tmp = new SoldierNode;
        tmp = list.head;
        if((pos >= 0) && (pos < list.size)){
            while(s < pos){
                tmp = (*tmp).next;
                s += 1;
            }
            hp = ((*tmp).data).HP;
            tmp = NULL;
            delete tmp;
            return hp;
        }
        else return -1;
    }
    else return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    int s = 0;
    if(list.head != NULL){
        SoldierNode* tmp = new SoldierNode;
        tmp = list.head;
        if((pos >= 0) && (pos < list.size)){
            while(s < pos){
            tmp = (*tmp).next;
            s += 1;
        }
        ((*tmp).data).HP = HP;
        tmp = NULL;
        delete tmp;
        return 1;
        }
        else return false;
    }
    else return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    bool flag  = false;
    if(list.head != NULL){
        SoldierNode* tmp = new SoldierNode;
        tmp = list.head;
        while(tmp != NULL){
            if((((*tmp).data).HP == soldier.HP) && (((*tmp).data).isSpecial == soldier.isSpecial) && (((*tmp).data).ID == soldier.ID)){
                flag = true;
                break;
            }
            else tmp = (*tmp).next;
        }
        tmp = NULL;
        delete tmp;
       
    }
    else flag =  false;
    return flag;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
