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
    node* tmp = new node;
    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            node* temp = new node;
            cin >> temp->data;
            temp->next = NULL;
            head = temp;
        }
        else {
            node* temp = new node;
            cin >> temp->data;
            temp->next = NULL;
            tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = temp;
        }
    }
    return head;
}
int searchLinkedList(node* head, int key)
{
    node* temp = head;
    int count = 0; bool flag = false;
    while (temp->next != NULL) {
        if (temp->data == key) { flag = 1; break; }
        else {
            temp = temp->next;
            count++;
        }
    }
    if (flag)
        return count;
    else return -1;
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
    int m;
    cin >> m;
    cout << searchLinkedList(head, m);
    return 0;
}
