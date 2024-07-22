class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node
        new_node.prev = last_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

    def display_reverse(self):
        current = self.head
        while current and current.next:
            current = current.next
        while current:
            print(current.data, end=" <-> ")
            current = current.prev
        print("None")

    def delete(self, key):
        current = self.head

        if current and current.data == key:
            self.head = current.next
            if self.head:
                self.head.prev = None
            current = None
            return

        while current and current.data != key:
            current = current.next

        if current is None:
            return

        if current.next:
            current.next.prev = current.prev

        if current.prev:
            current.prev.next = current.next

        current = None

# 使用範例
dll = DoublyLinkedList()
dll.append(10)
dll.append(20)
dll.append(30)
dll.append(40)

print("初始雙向鏈結串列: ")
dll.display()

dll.delete(20)
print("刪除節點 20 後的雙向鏈結串列: ")
dll.display()

dll.delete(40)
print("刪除節點 40 後的雙向鏈結串列: ")
dll.display()

print("反向顯示雙向鏈結串列: ")
dll.display_reverse()

