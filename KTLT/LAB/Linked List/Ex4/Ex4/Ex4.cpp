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
    node* curr = head;
    node *pre = NULL, *next = head;

    while (curr != NULL) {
        next = next->next;
        curr->next = pre;
        pre = curr;
        curr = next;
       }
    head = pre;
    return head;
    /*   1          2 3 
          1->2 
    
    
    */
}
void print(node* head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    if (n > 0)
    {
        node* head = createLinkedList(n);
        print(head);
    }
    else
    {
        cout << "Invalid n" << endl;
    }
    return 0;
}