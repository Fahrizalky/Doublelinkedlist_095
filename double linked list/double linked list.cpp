#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedlist {
private:
	Node* START = NULL;
public:;

	  void addNode();
	  bool search(int rollNo, Node** previous, Node** current);
	  bool deleteNode(int rollNo);
	  bool listEmpty();
	  void traverse();
	  void revtraverse();
	  void hapus();
	  void searchData();
};

void DoubleLinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;

	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; //step 2
	newNode->name = nm; //step 2

	/*insert a node in the begining o a doubly - Linked List*/
	if (START == NULL || nim <= START->noMhs) { //check if data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; //step 3
		if (START != NULL)
			START->prev = newNode; //step 4
		newNode->prev = NULL; //step 5 
		START = newNode; //step 6
		return;
	}

	/*inserting  a Node Between two Nodes in the List*/
	Node* current = START; //1.a
	Node* previous = NULL; //1.b
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}


	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; //step 4
	newNode->prev = current; //step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; //step 7
}

bool DoubleLinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = NULL; //step 1.a
	*current = START; //1.b
	while (*current != NULL && (*current)->noMhs != rollNo) { // step 1.c
		*previous = *current; //step 1.d
		*current = (*current)->next; // step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step 2
	if (previous != NULL)
		previous->next = current->next; // step 3
	else
		START = current->next;

	delete current; //step 4
	return true;
}

bool DoubleLinkedlist::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedlist::traverse() {
	if (listEmpty())
		cout << "\nlist is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecord in descending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedlist::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number: " << rollNo << "deleted" << endl;
}

void DoubleLinkedlist::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DoubleLinkedlist::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

