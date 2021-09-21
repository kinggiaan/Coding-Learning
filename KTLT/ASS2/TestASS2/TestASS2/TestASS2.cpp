/*
#include <iostream>
#include <string>
#include <vector>
#define get(a) #a 
#define LIMIT 100
#undef LIMIT
#define sub_then_add(a, b, c) (a - b) + c
using namespace std;


struct Soldier {
    Soldier() : HP(-1), isSpecial(false), ID("") {}
    Soldier(int HP, int isSpecial, string ID) : HP(HP), isSpecial(isSpecial), ID(ID) {}

    int HP;
    bool isSpecial;
    string ID;
};

struct SoldierNode {
    SoldierNode() : data(Soldier()), next(NULL) {}
    SoldierNode(Soldier data, SoldierNode* next) : data(data), next(next) {}

    Soldier data;
    SoldierNode* next;
};

struct SLinkedList {
    SLinkedList() : head(NULL), size(0) {}
    SLinkedList(SoldierNode* head, int size) : head(head), size(size) {}

    SoldierNode* head;
    int size;
};

struct Array {
    Array() : arr(NULL), size(0), capacity(0) {}

    Soldier* arr;
    int size;
    int capacity;
};

vector<string> tokenize(string s, string del = " ") {
    //Used for testcase tokenizer, students don't need to take care of this function.
    vector<string> res;
    int start = 0;
    int end = (int)s.find(del);
    while (end != -1) {
        res.push_back(s.substr(start, end - start));
        start = (int)end + (int)del.size();
        end = (int)s.find(del, start);
    }
    res.push_back(s.substr(start, end - start));
    return res;
}

void initArray(Array& array, int cap) {
    //Init a new array with capacity equals to cap
    array.arr = new Soldier[cap];
    array.capacity = cap;
}
void print(SLinkedList& list) {
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head) {
        std::cout << head->data.HP << "->";
        head = head->next;
    }
    std::cout << "NULL" << endl;
}

bool insertAt(SLinkedList& list, Soldier element, int pos) {
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise 0 1 2
    if (pos > list.size || pos < 0) return false;
    else {
        SoldierNode* head = list.head;
        //for (int i = 0; i <= pos; i++);
    }

    return false;
}
void clear(SLinkedList& list) {
    //Delete all of the elements in list
    SoldierNode* tmp = list.head;
    while (tmp != NULL) {
        SoldierNode* temp = tmp;
        tmp = tmp->next;
        free(temp);
        cout << temp;
    }
    list.head = NULL;

}
int main() {
    SLinkedList list;
    int pos,n;
    cin >> n;
    SoldierNode* head = list.head;
    SoldierNode* tmp = NULL;
    for (int i = 0; i < n; i++) {
        SoldierNode* temp = new SoldierNode;
        cin>>temp->data.HP;
        if (head == NULL) {
            head = temp;
            list.size++;
      
        }
        else {
            tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = temp;
            list.size++;
        }
    }
    list.head = head;
    print(list);

    cin >> pos; // 0 -> 1 ->2
    head = list.head;
    tmp = head;
    SoldierNode* temp = new SoldierNode;
    cin >> temp->data.HP;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }
    temp->next = tmp->next;
    tmp->next = temp;
    list.head = head;
    list.size++;
    
    print(list);
    
    cin >> pos;
    tmp = head;// 0 1 2 3 
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }
    SoldierNode* dele = tmp->next;
    tmp->next = tmp->next->next;
    delete dele;
    list.head = head;
    list.size--;

    print(list);

    clear(list);

    return 0;
}
 */
 // C++ code for linked list merged sort
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
};

/* function prototypes */
Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
    Node** frontRef, Node** backRef);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef)
{
    Node* head = *headRef;
    Node* a;
    Node* b;

    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);

    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);

    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this
function */
Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,
    and return the two lists using the reference parameters.
    If the length is odd, the extra node should go in the front list.
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source,
    Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast
->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    Node* res = NULL;
    Node* a = NULL;

    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    /* Sort the above created Linked List */
    MergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}


void FrontBackSplit(SoldierNode* source, SoldierNode** frontRef, SoldierNode** backRef) {
    SoldierNode* fast;
    SoldierNode* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast
            ->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}