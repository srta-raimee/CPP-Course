#include <iostream>

using namespace std;

// A stack follows LIFO (Last In, First Out), like a tower of pancakes

class Node {
public:
	Node* next = nullptr;
	int value;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}

};

class Stack {
private:
	Node* top;
	int height;

public:
	Stack(int value) {
		Node* newNode = new Node(value);
		top = newNode;
		height = 1;
	}

	void printStack() {
		Node* temp = top;
		while (temp) {
			cout << temp->value << endl << "____ " << endl;
			temp = temp->next;

		}
		//cout << "nullptr" << endl;
	}

	void getTop() {
		cout << "Top: " << top->value << endl;
	}

	void getHeight() {
		cout << "Height: " << height << endl;
	}

	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		height++;
	}
	int pop() {
		if (height == 0) return INT_MIN ;

		Node* temp = top;
		int popped = top->value;
		top = top->next;
		delete temp;
		height--;

		return popped;
	}

};

//int main() {
//	Stack* STK = new Stack(8);
//
//	/*STK->getTop();
//	STK->getHeight();*/
//	int arr[] = { 1, 4, 5, 6, 9, 13, 19 };
//	int tam = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < tam; i++) {
//		STK->push(arr[i]);
//	}
//
//	STK->printStack();
//	STK->pop();
//
//	cout << endl << "========= With pop ========= " << endl;
//	STK->printStack();
//
//};