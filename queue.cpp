#include <iostream>

using namespace std;

// A Queue follow FIFO (First In, First out), like a queue of crazy kids wanting to slide in a water slide

class Node {
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;

	}
};

class Queue {
private:
	Node* first;
	Node* last;
	int length;

public:
	Queue(int value) {
		Node* newNode = new Node(value);
		first = newNode;
		last = newNode;
		length = 1;

	}

	void printQueue() {
		Node* temp = first;
		while (temp) {
			cout << temp->value << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}

	void getFirst() {
		cout << "First: " << first->value << endl;
	}

	void getLast() {
		cout << "Last: " << last->value << endl;
	}

	void getLength(){
		cout << "Length: " << length << endl;
	}

	void enqueue(int value) {
		Node* newNode = new Node(value);

		if (length == 0) {
			first = newNode;
			last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
		length++;
	}

	int dequeue() {
		if (length == 0) return INT_MIN;
		if (length == 1) {
			first = nullptr;
			last = nullptr;
			return 0;

		}
		else {
			Node* temp = first;
			int dequeueado = first->value;
			first = first->next;
			delete temp;
			length--;
			return dequeueado;
		}
		
	}
};

int main() {

	Queue* QUEUE = new Queue(8);

	int arr[] = { 1, 4, 5, 6, 9, 13, 19 };
	int tam = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < tam; i++) {
		QUEUE->enqueue(arr[i]);
	}
	QUEUE->printQueue();
	QUEUE->dequeue();
	QUEUE->printQueue();
}