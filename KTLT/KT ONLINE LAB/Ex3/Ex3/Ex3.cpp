#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node(int val, Node* next) : val(val), next(next) {}
};

void addNode(Node* node, int val)
{
    while (node->next)
        node = node->next;
    node->next = new Node(val, nullptr);
}

void print(Node* root)
{
    if (!root)
    {
        cout << "Empty list";
        return;
    }
    while (root)
    {
        cout << root->val << " ";
        root = root->next;
    }
}
//


Node* deletepos(Node* head, int pos) {//0 1 2
    Node* temp=head;
    int count = 0;
    
        
    if (pos == 0) {
        temp = temp->next;
        delete head;
        return temp;
    }
        while (temp != NULL) {
            if (count == pos) break;
            count++;

            temp = temp->next;

        }

        temp->next = temp->next->next;

        return head;
    
}

Node* listDiff(Node* l0, Node* l1)
{
    Node* head1 = l0;
    Node* head2 = l1;
    while (head1==NULL) {
        while (head2 == NULL) {
            if (head1->val == head2->val) {

            }
        }
    }
    return l0;
}
void change(int* a, int b) {
    int temp = *a;
    *a = b;
    b = temp;
}
int main() {
    /*int arr0[] = {1, 4, 6, 7, 9};
    int arr1[] = { 1, 2, 6, 7, 10, 12 };
    Node* l0 = new Node(0, nullptr);
    Node* l1 = new Node(0, nullptr);

    for (unsigned int i = 0; i < sizeof(arr0) / sizeof(arr0[0]); i++)
        addNode(l0, arr0[i]);
    for (unsigned int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
        addNode(l1, arr1[i]);
    l1 = deletepos(l1, 0);
    print(l1);
    /*
    Node* result = listDiff(l0, l1);
    print(result);
    */

    int a = 10;
    int& b = a;
    cout << "Value of a :" << a << endl;
    cout << "Value of a reference :" << b << endl;
    a = 6;
    b = 9;
    cout << "Value of a :" << a << endl;
    cout << "Value of a reference :" << b << endl;


    return 0;
}