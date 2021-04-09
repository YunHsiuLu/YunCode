# practise how to use class to show the linked list
# you need to define two class: node and linked list


class Node:
    def __init__(self, value=None, next=None):
        self.value = value
        self.next = next

    def Val(self):
        return self.value

    def Next(self):
        if (self.value == None):
            return print("it's the end!")
        elif (self.next == None):
            return Node()
        else:
            return self.next


class List:
    def __init__(self, node=Node()):
        self.head = node

    def ShowRoot(self):
        return self.head

    def InsertElement(self, node):
        if (node.Next() == self.head):
            self.head = node

    def CountElement(self):
        temp_node = self.head
        c = 0
        while(temp_node.Val() != None):
            c += 1
            temp_node = temp_node.Next()
        print(c)

    def ListPrint(self):
        temp_node = self.head
        arrow = " -> "
        s = str(temp_node.Val())
        temp_node = temp_node.Next()
        while(temp_node.Val() != None):
            s += arrow + str(temp_node.Val())
            temp_node = temp_node.Next()
        print(s)


node1 = Node(1)
node2 = Node(2, node1)
list1 = List(node1)
list1.InsertElement(node2)
list1.CountElement()
list1.ListPrint()
