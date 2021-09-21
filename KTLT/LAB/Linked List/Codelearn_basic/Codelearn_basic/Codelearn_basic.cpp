/*#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* CreateNode(int x) {
    node* p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}
node* AddElement(node* l, int x) {
    node* h = l;
    node* p = CreateNode(x);
    l->next = p;
    return p;
}
node* AddEndElement(node* l, int x) {
    node* p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    node* t = CreateNode(x);
    p->next = t;
    return l;
}
node* AddHead(node* l, int x) {
    node* head = l;
    node* temp = CreateNode(x);
    temp->next = head;
    return temp;
}
node* AddPosElement(node* l, int pos, int x) {
    node* p = l;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }

    node* temp = CreateNode(x);
    temp->next = p->next;
    p->next = temp;
    return l;
}
void Print(node* l) {
    node* p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}
int main() {
    int n, x, pos;
    cin >> n;
    cin >> x;
    node* l = CreateNode(x);
    node* p = l;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p = AddElement(p, x);
    }
    cin >> pos;
    cin >> x;
    if (pos == 0) l = AddHead(l, x);
    else if (pos == n) l = AddEndElement(l, x);
    else l = AddPosElement(l, pos, x);
    Print(l);
    return 0;
}
*/

#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int x) {
    node* temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

void printList(node* l) {
    node* p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

node* addElement(node* p, int x) {
    node* temp = createNode(x);
    p->next = temp;
    return temp;
}

int GetNum(node* l, int pos) {
    node* p = l;
    int te;
    for (int i = 0; i < pos; i++) {
        p = p->next;
    }
    te = p->data;

    return te;
}
node* AddTail(node* l, int x) {
    node* p = l;
    node* temp = createNode(x);
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    return l;
}

node* DeleteNum(node* l, int x) {
    node* p = l;
    node* ans = new node;
    while (p != NULL) {
        if (p->data <= x) {
            ans = createNode(p->data);
            p = p->next;
            break;
           }
        p = p->next;
    }
    while (p != NULL) {
        if (p->data <= x) {
            ans = AddTail(ans, p->data);
        }
        p = p->next;
    }

    return ans;
}
int main(){
    int n, x, k;
    cin >> n;
    cin >> x;
    node* l = createNode(x);
    node* p = l;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p = addElement(p, x);
    }
    cin >> k;
    l = DeleteNum(l, GetNum(l, k));
    printList(l);
    return 0;
}