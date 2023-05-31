#include <iostream>
#include <vector>


template<class T>
struct Node {
    T data;
    Node *next = nullptr;

    Node(T d = 0) : next(nullptr), data(d) {}
};

template<class T>
struct LinkedListIterator {
    Node<T> *ptr = nullptr;

    LinkedListIterator &operator++() {
        ptr = ptr->next;
    }
};

template<class T>
struct LinkedList {
    Node<T> *head = nullptr;

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        auto next = head->next;
        delete head;
        head = next;
    }

    void push_front(const T &d) {
        auto newNode = new Node<T>(d);
        newNode->next = head;
        head = newNode;
    }

    bool empty() const {
        return head == nullptr;
    }

    void push_back(const T &d) {

        auto *cur = head;
        if (cur == nullptr) {
            auto *newNode = new Node(d);
            head = newNode;
            return;
        }
        while (cur != nullptr) {
            if (cur->next == nullptr) {
                auto *newNode = new Node(d);
                cur->next = newNode;
                return;
            }
            cur = cur->next;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *cur = head;
        while (cur->next != nullptr) {
            if (cur->next->next == nullptr) {
                delete cur->next;
                cur->next = nullptr;
                return;
            }
            cur = cur->next;
        }
        printf("something is wrong!\n");
    }

};

template<class T>
std::ostream &operator<<(std::ostream &os, LinkedList<T> list) {
    Node<T> *cur = list.head;
    while (cur != nullptr) {
        os << cur->data << " ";
        cur = cur->next;
    }
    return os;
}

template<class T>
struct Queue {
    LinkedList<T> list;

    void pop() {
        list.pop_front();
    }

    void push(const T &data) {
        list.push_back(data);
    }

    //원래 코드 이렇게 짜면 안되는데 동작지정하지말라고 하셔서 그냥 냅둡니다
    T front() const {
        if (this->empty() == false) {
            return list.head->data;
        }
    }

    bool empty() const {
        if (list.empty()) {
            return true;
        }
        return false;

    }
};

template<class T>
struct Stack {
    LinkedList<T> list1;

    void pop() {
        list1.pop_back();
    }

    void push(const T &data) {
        list1.push_back(data);
    }

    //원래 코드 이렇게 짜면 안되는데 동작지정하지말라고 하셔서 그냥 냅둡니다
    T top() const {
        if (this->empty() == false) {
            if (list1.head->next == nullptr) {
                return list1.head->data;
            }
            Node<T> *cur = list1.head;
            while (cur->next != nullptr) {
                if (cur->next->next == nullptr) {
                    return cur->next->data;
                }
                cur = cur->next;
            }
        }
    }

    bool empty() const {
        return list1.empty();
    }
};

int main() {
//    Queue<int> que;
//    que.empty(); //비어야함
//    que.pop();  //비어야함
//    que.front(); //비어야함
//    que.push(1); //1
//    que.push(2); //1 2
//    que.push(3); // 1 2 3
//    que.push(4); // 1 2 3 4
//    que.push(5); // 1 2 3 4 5
//    que.front(); //1
//    que.pop(); //2 3 4 5
//    que.front(); //2
//    que.pop(); // 3 4 5
//    que.front(); //3
//    que.push(6); // 3 4 5 6
//    que.front(); //3
//    que.empty(); //비면 안됨
//    que.pop();
//    que.pop();
//    que.pop();
//    que.front(); //6
//    que.pop(); //비어야함
//    que.front(); //비어야함
//    que.pop(); //비어야함
//    que.empty(); //비어야함
//
//    Stack<int> stack;
//    stack.empty(); //비어야함
//    stack.pop();  //비어야함
//    stack.top(); //비어야함
//    stack.push(1); //1
//    stack.push(2); //1 2
//    stack.push(3); // 1 2 3
//    stack.push(4); // 1 2 3 4
//    stack.push(5); // 1 2 3 4 5
//    stack.top(); //5
//    stack.pop(); //1 2 3 4
//    stack.top(); //4
//    stack.pop(); // 1 2 3
//    stack.top(); //3
//    stack.push(6); // 1 2 3 6
//    stack.top(); //6
//    stack.empty(); //비면 안됨
//    stack.pop();
//    stack.pop();
//    stack.pop();
//    stack.top(); //1
//    stack.pop(); //비어야함
//    stack.top(); //비어야함
//    stack.pop(); //비어야함
//    stack.empty(); //비어야함
}

