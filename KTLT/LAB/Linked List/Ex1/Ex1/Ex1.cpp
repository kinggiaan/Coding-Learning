#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
node* createLinkList(int n)
{
	node *head=NULL, *temp= new node;
	
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
			temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = tmp;

		}

	}
	return head;
}

bool isEqual(node* head1, node* head2)
{
	bool flag1=true,flag2=true;
	while (head1 != NULL && head2 != NULL) {
		if (head1->data != head2->data) {
			flag1 = false;
			break;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head1 != head2) flag2 = false;
	return flag1 && flag2;
	
}
int main()
{
	int n = 0;
	cin >> n;
	node* head1 = createLinkList(n);
	int m = 0;
	cin >> m;
	node* head2 = createLinkList(m);
	cout << isEqual(head1, head2) << endl;
	return 0;
}
