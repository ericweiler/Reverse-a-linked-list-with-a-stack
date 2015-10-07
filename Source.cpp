#include <iostream>
#include <stack>
using namespace std;

struct node{
	int data;
	node* next;
};

node* createnode(int data){
	node* address = new node;
	address->data = data;
	address->next = NULL;
	return address;
}

void printlist(node* head){
	while (head != NULL){
		cout << head->data << endl; 
		head = head->next;
	}
}
int main(){
	node* head = createnode(0);
	node* current = head;
	for (int i = 1; i < 100; i++){
		current->next = createnode(i);
		current = current->next;
	}
	printlist(head);
	current = head;
	stack<int> myStack;
	while (current != NULL){
		myStack.push(current->data);
		current = current->next;
	}
	current = head;
	while (!myStack.empty()){
		current->data = myStack.top();
		myStack.pop();
		current = current->next;
	}
	printlist(head);
}