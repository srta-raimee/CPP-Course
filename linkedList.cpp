#include <iostream>
using namespace std;

// Linked List (thre's not much to say about this babe)

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    // destructor to guarantee that our memory will remain clean when we delete the LL
    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " -> ";
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

        if (this->length >= 1) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            this->head = newNode;
            this->tail = newNode;
        }

        length++;
    };

    void deleteLast() {
        if (length == 0) return;

        Node* temp = head;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }

        else {
            Node* pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }

            tail = pre;
            tail->next = nullptr;
            
        }
        length--;
        delete temp;
    };

    void prepend(int value) {
        Node* newNode = new Node(value);

        if (this->length > 0) {
            newNode->next = head;
            head = newNode;

        }
        else {
            this->head = newNode;
            this->tail = newNode;
        }

        length++;
    };

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            this->head = head->next;
        };
        delete temp;
        length--;
    };

    Node* get(int index) {
        if (index < 0 || index >= length) {
            cout << "This index is not valid." << endl;
            return nullptr;
        };
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        };
        return temp;
    };

    bool set(int index, int value) {
        Node* temp = get(index);

        // condição ? valor_se_verdadeiro : valor_se_falso.
        /*return temp ? (temp->value = value, true) : false;*/

        if (temp) {
            temp->value = value;
            return true;
        }
        return false;

    };

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
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
    };

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;


        // TEMP passa a ter o valor de HEAD. Onde HEAD estava passa a ser TAIL e TAIL passa a ser igual a TEMP, se tornando HEAD 
        Node* after = temp->next;  // a nova TAIL, antiga HEAD
        Node* before = nullptr;    // o antigo NEXT da antiga HEAD (que agora é TAIL)

        for (int i = 0; i < length; i++) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        };
    };

};

    //int main() {
    //      LinkedList* myLL = new LinkedList(5);


    //      myLL->printList();

    //      myLL->append(1);
    //      myLL->append(7);
    //      myLL->append(0);
    //      myLL->append(8);
    //      myLL->append(9);
    //      myLL->append(14);

    //      cout << "Add novos nodes" << endl;
    //      myLL->printList();

    //   /*   cout << "Removendo ultimo" << endl;
    //      myLL->deleteLast();
    //      cout << "Lista sem o ultimo" << endl;
    //      myLL->printList();

    //      myLL->prepend(58);
    //      cout << "Lista com novo node no inicio" << endl;
    //      myLL->printList();

    //      myLL->deleteFirst();
    //      myLL->printList();

    //      myLL->getHead();
    //      myLL->getTail();
    //      myLL->getLength();

    //      myLL->get(3)->value;
    //      myLL->set(1, 25);

    //      myLL->insert(2, 87);*/

    //      /*cout << "Removendo no meio" << endl;
    //      myLL->deleteNode(2);*/
    //      myLL->reverse();

    //      myLL->printList();
    //      return 0;
    //  };
