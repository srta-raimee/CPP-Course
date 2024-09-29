#include <iostream>

using namespace std;

// A Linked List but easier to work with 'cause now we stored the Previous node of all nodes

class Node {
public:
	int value;
	Node* next;
	Node* prev;

	Node(int value) {
		this->next = nullptr;
		this->prev = nullptr;
		this->value = value;
	};
};

class DoubleLinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int length;

public:
	DoubleLinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;

	};

	Node* get(int index) {
		if (index < 0 || index >= length) {
			cout << "This index is not valid." << endl;
			return nullptr;
		};
		
		if (index < length / 2) {
			Node* temp = head;
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			
			return temp;
		}
		else {
			Node* temp = tail;
			for (int i = length - 1; i > index; i--) {
				temp = temp->prev;
			}
	
		return temp;
		}
		
	};

	void printList() {
		Node* temp = head;
		while (temp) {
			cout << temp->value << " -> ";
		/*	cout << temp->value << " <- ";*/
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}

	void getHead() {
		cout << "Head: " << head->value << endl;
	}

	void getTail() {
		cout << "Tail: " << tail->value << endl;
	}

	void getLength() {
		cout << "Length: " << length << endl;
	}

	void append(int value) {
		Node* newNode = new Node(value);

		if (length >= 1) {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;

		}
		else {
			head = newNode;
			tail = newNode;
		};

		length++;

	}

	void deleteLast() {
		if (length == 0) return;

		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}

		else {
			Node* temp = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delete temp;
		};
		length--;
	}

	void prepend(int value) {
		Node* newNode = new Node(value);

		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		};
		length++;

	}

	void deleteFirst() {
		if (length == 0) return;

		if (length == 1) {
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		length--;
	};

	bool set(int index, int value) {
		Node* temp = get(index);

		if (temp) {
			temp->value = value;
			return true;
		}
		return false;
		
	}

	bool insert(int index, int value) {
		if (index < 0 || index > length) return false;

		if (index == 0) {
			prepend(value);
			return true;
		};
		if (index == length) {
			append(value);
			return true;
		};
		Node* newNode = new Node(value);
		Node* before = get(index - 1);
		Node* after = before->next;

		before->next = newNode;
		after->prev = newNode;

		newNode->next = after;
		newNode->prev = before;

		length++;
		return true;
	}

	void deleteNode(int index) {
		if (index < 0 || index >= length) return;

		if (index == 0) {
			deleteFirst();
			return;
		}

		if (index == length - 1) {
			deleteLast();
			return;
		}

		Node* temp = get(index);
		Node* before = temp->prev;
		Node* after = temp->next;

		if (before != nullptr) {
			before->next = after;
		}

		if (after != nullptr) {
			after->prev = before;
		}

		delete temp;
		length--;
	}

};


//int main() {
//	DoubleLinkedList* DLL = new DoubleLinkedList(7);
//	int arr[] = { 1, 3, 6, 8, 9, 15, 22};
//	int tam = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < tam; i++) {
//		DLL->append(arr[i]);
//	}
//
//	
//	DLL->printList();
//	DLL->deleteNode(2);
//	DLL->printList();
//	/*DLL->deleteLast();
//	DLL->deleteFirst();
//	DLL->printList();
//	DLL->insert(5, 14);
//	DLL->printList();*/
//
//
//};