#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* createLinkedList(int n)
{
    node* head = NULL;

    for (int i = 0; i < n; i++) {
        node* temp = new node;
        cin >> temp->data;
        temp->next = NULL;
        if (head == NULL) head = temp;
        else {
            node* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = temp;
        }
    }
    return head;
}
node* evenThenOddLinkedList(node* head)
{
    node* p = head;
    node* even = NULL;
    node* odd = NULL;
    node* ans = NULL;
    int hasE = 0, hasO = 0;
    // First even
    while (p != NULL) {
        if (p->data % 2 == 0) {
            hasE = 1;
            node* tmp = new node;
            tmp->data = p->data;
            tmp->next = NULL;
            if (even == NULL) even = tmp;
            else {
                node* temp = even;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = tmp;
                
            }
        }
        else {
            hasO = 1;
            node* tmp = new node;
            tmp->data = p->data;
            tmp->next = NULL;
            if (odd == NULL) odd = tmp;
            else {
                node* temp = odd;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = tmp;
            
            }
        }
        p = p->next;
    }
    //Merge 2 linked list
    if (hasE && hasO) {
        node* k = even;
        while (k->next != NULL) {
            k = k->next;
        }
        k->next = odd;
        ans = even;
    }
    else if (hasO) ans = odd;
    else ans = even;

    return ans;

}
node* eledel(node* head,int key) {
    node* tmp = head;
    for (int i = 0; i < key; i++) {
        tmp = tmp->next;
    }
    node* del = tmp->next;
    free (del);
    tmp->next = NULL;
    return head;
}
void print(node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    int n = 0;
    cin >> n;
    node* head = createLinkedList(n);
    print(head);
    head = evenThenOddLinkedList(head);
    head = eledel(head);
    print(head);
    return 0;
}