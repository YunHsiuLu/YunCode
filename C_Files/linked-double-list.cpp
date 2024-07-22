#include <iostream>

// 節點結構
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// 雙向鏈結串列類別
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // 新增節點到鏈結串列的末尾
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // 顯示鏈結串列中的所有節點
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 從尾部顯示鏈結串列中的所有節點
    void displayReverse() {
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 刪除鏈結串列中的節點
    void deleteNode(int value) {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        delete temp;
    }

    // 釋放鏈結串列所佔的記憶體
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    std::cout << "初始鏈結串列: ";
    list.display();

    list.deleteNode(20);
    std::cout << "刪除節點 20 後的鏈結串列: ";
    list.display();

    list.deleteNode(40);
    std::cout << "刪除節點 40 後的鏈結串列: ";
    list.display();

    std::cout << "反向顯示鏈結串列: ";
    list.displayReverse();

    return 0;
}

