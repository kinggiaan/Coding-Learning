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
    node* temp = new node;
    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            node* tmp = new node;
            cin >> tmp->data;
            tmp->next = NULL;
            head = tmp;
        }
        else {
            node* tmp = new node;
            cin >> tmp->data;
            tmp->next = NULL;
            temp = head  ;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = tmp;
        }
    }
    return head;
}
int countNode(node* head)
{
    node* temp = new node;
    temp = head;
    int count = 0;
    while (temp != NULL) {
       
        count++;
        temp = temp->next;
    }
    return count;
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
    print(head);
    cout << endl;
    cout << countNode(head);
    return 0;
}
