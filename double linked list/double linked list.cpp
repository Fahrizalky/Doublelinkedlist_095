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

class DoubleLinkedList {
private:
	Node* START = NULL;
public:

	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool ListEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();

};

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student:";
	cin >> nim;
	cout << "\nEnter the name of the srudent:";
	cin >> nm;


	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim; // step 2
	newNode->name = nm; //step 3

	//*insert a node the begining of a doubly - linked list/
	if (START == NULL || nim <= START->noMhs) { //check idf data null
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDupLicate number not allowed" << endl;
			return;
		}

	}
}
