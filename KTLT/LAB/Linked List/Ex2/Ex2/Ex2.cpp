#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* createLinkedList(int n)
{
    node* head=NULL;
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
int countNode(node* head)
{
    int count = 0;
    node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
void print(node* head)
{
    while (head->next != nullptr)
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
