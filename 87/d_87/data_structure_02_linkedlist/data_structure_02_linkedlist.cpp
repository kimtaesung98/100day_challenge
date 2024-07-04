#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int x) :data(x), next(nullptr) {}
};

void printlist(Node* n) {
	while (n != nullptr) {
		cout << n->data << " ";
		n = n->next;
	}
}
int main() {
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	printlist(head);
}