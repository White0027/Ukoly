// Odkaz přes pointery.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.

#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* next;
};

void printNode(Node* node);
Node* newNode(int val);
void addNode(Node* node, int val);

int main()
{
	Node* node1 = newNode(1);
	printNode(node1);
	
	Node* node2 = newNode(2);
	printNode(node2);
	node1->next = node2;
	printNode(node1);
	
	Node* node3 = newNode(3);
	printNode(node3);
	node2->next = node3;

	return 0;
}

void printNode(Node* node)
{
	cout << "[Add: " << node << ", val: " << node->val << ", next: " << node->next << "]" << endl;
	if (node->next != NULL) printNode(node->next);
}

Node* newNode(int val)
{
	Node* newNode = new Node();
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void addNode(Node* previous, int val)
{
	Node* newNode = new Node();
	newNode->val;
	
	newNode->next = previous->next;
	previous->next = newNode;
}







