#include <iostream>

// 節點結構
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// 鏈結串列類別
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 新增節點到鏈結串列的末尾
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 顯示鏈結串列中的所有節點
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 刪除鏈結串列中的節點
    void deleteNode(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // 釋放鏈結串列所佔的記憶體
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    LinkedList list;

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

    return 0;
}

