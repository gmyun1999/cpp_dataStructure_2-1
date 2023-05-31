#include <iostream>

class Node {
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(int data, Node *left = nullptr, Node *right = nullptr) : data(data), left(left), right(right) {
    }

    auto getLeft() {
        return left;
    }

    auto getRight() {
        return right;
    }

    int getData() {
        return data;
    }

    void setRight(Node *node) {
        right = node;
    }

    void setLeft(Node *node) {
        left = node;
    }
};

class Bst {
private:
    Node *root = nullptr;

    void impl_insert(Node *cur, int dat);

    void impl_deleteNode(Node *cur, int data);

    Node *find_descendant(Node *start, int data);

public:
    void insertNode(int data);

    void deleteNode(int data);

    Node *findNode(Node *cur, int data);

    auto getRoot() {
        return root;
    }
};
//이건 재귀 안쓰고 만들어본 insert 함수
//void Bst::insertNode(int data) {
//    Node *newNode =new Node(data);
//    if (getRoot() == nullptr) {
//        root = newNode;
//        return ;
//    }
//    auto cur = root;
//    auto curPre = root;
//    int is_left = 0;
//    while (cur != nullptr) {
//        if (cur->getData() == data) {
//            std::cout << "already exist" << data << std::endl;
//            return;
//        } else if (cur->getData() < data) {
//            curPre = cur;
//            cur = curPre->getRight();
//            is_left = 0;
//        } else {
//            curPre = cur;
//            cur = curPre->getLeft();
//            is_left = 1;
//        }
//    }
//    //빠져나온다음에 내가 어디쪽에서 빠져나온지를 알려줘야함
//    if (is_left == 1) {
//        curPre->setLeft(newNode);
//    } else {
//        curPre->setRight(newNode);
//    }
//}

void Bst::insertNode(int data) {
    if (getRoot() == nullptr) {
        Node *node = new Node(data);
        root = node;
        return;
    } else {
        impl_insert(root, data);
    }
}

void Bst::impl_insert(Node *cur, int dat) {
    if (cur->getData() == dat) {
        std::cout << dat << std::endl;
        return;
    } else if (cur->getData() < dat) {
        if (cur->getLeft() == nullptr) {
            Node *node = new Node(dat);
            cur->setLeft(node);
            return;
        } else {
            cur = cur->getLeft();
            impl_insert(cur, dat);
        }
    } else {
        if (cur->getRight() == nullptr) {
            Node *node = new Node(dat);
            cur->setRight(node);
            return;
        } else {
            cur = cur->getRight();
            impl_insert(cur, dat);
        }
    }
}

void Bst::deleteNode(int data) {
    if (!findNode(root, data)) {
        return;
    } else {
        impl_deleteNode(root, data);
    }
}

void Bst::impl_deleteNode(Node *cur, int data) {
    Node *node = findNode(cur, data);
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        delete cur;
    } else if (node->getLeft() != nullptr || node->getRight() != nullptr) {

    } else {

    }


}

Node *Bst::findNode(Node *cur, int data) {
    if (cur == nullptr) {
        return nullptr;
    }
    if (cur->getData() == data) {
        return cur;
    } else if (cur->getData() > data) {
        findNode(cur->getLeft(), data);
    } else {
        findNode(cur->getRight(), data);
    }
}

//자기를 대체할 자손노드찾기
Node *Bst::find_descendant(Node *start, int data) {
    if (start->getData() == data) {
        find_descendant(start->getRight(), data);
    } else {
        if (start->getLeft() == nullptr) {
            return start;
        } else {
            find_descendant(start->getLeft(), data);
        }
    }
    return nullptr;
}


int main() {
    Bst bst;
    bst.insertNode(1);
    bst.insertNode(2);
    bst.insertNode(3);
    bst.insertNode(4);
    bst.insertNode(5);
    bst.insertNode(6);
    bst.insertNode(7);
    bst.insertNode(8);
    bst.insertNode(1);
    bst.insertNode(2);
    bst.insertNode(3);
    bst.insertNode(4);
    bst.insertNode(5);
    bst.insertNode(6);
    bst.insertNode(7);
    bst.insertNode(8);
    bst.insertNode(9);

}