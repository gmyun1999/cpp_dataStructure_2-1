#include <iostream>
#include <string>

using namespace std;


template <class T>
class Node {
private:
    int key;
    T value;
    Node *next;

public:
    Node(int key, T value, Node *next = nullptr) : key(key), value(value), next(next) {
    }

    Node *getNext() {
        return this->next;
    }

    T getValue() {
        return value;
    }

    int getKey() {
        return key;
    }

    void setNext(Node *node) {
        next = node;
    }
};


class LinkedList {
private:
    Node<void> *head = nullptr;
    int capacity = 0;

public:
    void search_node(int key) {
        if (!head) {
            std::cout << "list is empty";
            return;
        }
        Node *mptr = this->head;
        while (mptr != nullptr) {

        }
    }

    void delete_node(int key) {
        if (!head) {
            std::cout << "list is empty";
            return;
        }
        Node *mptr = this->head;
        Node *prePtr = this->head;

        while (mptr != nullptr) {
            if (mptr->getKey() == key) {
                if (mptr == this->head) {
                    this->head = mptr->getNext();
                } else {
                    prePtr->setNext(mptr->getNext());
                }
                delete mptr;    //mptr이 가리키는 노드는 지워야하는 노드이므로 메모리반환해준다
                this->capacity -= 1;
                return;
            }
            prePtr = mptr;
            mptr = mptr->getNext();
        }
    }

    template<typename T>
    void push_node(int key, T value) {
        Node<void> *newNode = reinterpret_cast<Node<void>*>(new Node<T>(key, value));
        if (!head) {
            this->head = newNode;
            this->capacity += 1;
            return;
        }
        //여기서 전노드의 타입을 알아여하는데 이거는 전부 int,double 등등으로 오버로딩마냥 하나씩 if문으로 설정해줘야한다.
        Node *mptr = this->head;
        // mptr�� next�� ������ ���� �װ� ������ �����.
        while (mptr->getNext() != nullptr) {
            mptr = mptr->getNext();
        }
        mptr->setNext(newNode);
        this->capacity += 1;
        return;
    }

    int getCapacity() {
        return this->capacity;
    }
};

int main() {
    LinkedList *list = new LinkedList;
    list->push_node(1, 1);
    list->push_node(2, 2);
    list->push_node(3, 3);
    list->push_node(4, 4);
    list->push_node(5, 5);
    std::cout << list->getCapacity() << endl; //5
    list->delete_node(2);
    std::cout << 1 << endl; //5
    std::cout << list->getCapacity() << endl; //4
    list->delete_node(3);
    list->delete_node(4);
    list->delete_node(9);   //print
    list->delete_node(5);
    std::cout << list->getCapacity() << endl; //1
    list->delete_node(1);
    std::cout << list->getCapacity() << endl; //0
    list->delete_node(1);   //print
    delete list;

}