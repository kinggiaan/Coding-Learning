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
node* insertNode(node* head, node* newNode, int position)
{
    node* temp = head;// 1 3 5 7 9 

    node* tempc = new node;
    tempc = head;
    int count = 0;
    while (tempc != NULL) {

        count++;
        tempc = tempc->next;
    }
    if (position <= 0) return head;
    else if (position < count) {
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    return head;

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


