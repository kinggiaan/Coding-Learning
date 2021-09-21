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
node* insertNode(node* head, node* newNode, int position)
{
    if (position <= 0) {
        return head;
    }
    else {
        
        if (position == 1) {
            newNode->next = head;
            return newNode;
        }
        else {
            //count number of element inlinked list
            node* p = head;
            int count = 1;
            while (p != NULL) {
                count++;
                p = p->next;
            }
            
            delete(p);
            if (position <= count) {
                node* p = head;
                for (int i = 1; i < position - 1; i++) {
                    p = p->next;
                }
                newNode->next = p->next;
                p->next = newNode;
               
                return head;
            }
            else {
                node* p = head;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = newNode;
                
                return head;
            }
        }
    }
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
    node* head = createLinkedList(n);
    node* newNode = new node();
    cin >> newNode->data;
    int position = 0;
    cin >> position;
    head = insertNode(head, newNode, position);
    print(head);
    return 0;
}


