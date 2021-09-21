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

bool isEqual(node* head1, node* head2)
{
    bool flag1 = true, flag2 = true;
    while ((head1 != NULL) && (head2 != NULL)) {
        if (head1->data != head2->data) {
            flag1 = false;
            break;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 != head2) flag2 = false;
    return flag2 && flag1;
}
int main()
{
    int n = 0;
    cin >> n;
    node* head1 = createLinkedList(n);
    int m = 0;
    cin >> m;
    node* head2 = createLinkedList(m);
    cout << isEqual(head1, head2) <<"\n"<<"a"<< endl;
    return 0;
}
