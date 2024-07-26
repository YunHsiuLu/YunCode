class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
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

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def delete(self, key):
        current = self.head

        if current and current.data == key:
            self.head = current.next
            current = None
            return

        prev = None
        while current and current.data != key:
            prev = current
            current = current.next

        if current is None:
            return

        prev.next = current.next
        current = None

# 使用範例
sll = SinglyLinkedList()
sll.append(10)
sll.append(20)
sll.append(30)
sll.append(40)

print("初始單向鏈結串列: ")
sll.display()

sll.delete(20)
print("刪除節點 20 後的單向鏈結串列: ")
sll.display()

sll.delete(40)
print("刪除節點 40 後的單向鏈結串列: ")
sll.display()

