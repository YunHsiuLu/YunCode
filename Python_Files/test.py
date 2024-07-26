class Node():
    def __init__(self, data=None):
        self.data = data
        self.next = None
        

class LinkedList():
    def __init__(self):
        self.head = None

    def ShowNodes(self):
        t = self.head
        while not (t == None or t.data == None):
            print("%d ->" % t.data, end=" ")
            t = t.next
        print("None")
    
    def AddNodes(self, data=None):
        if self.head == None:
            self.head = Node(data)
        else:
            t = self.head
            while not (t.next == None):
                t = t.next
            t.next = Node(data)

l = LinkedList()
l.ShowNodes()
l.AddNodes(1)
l.AddNodes(2)
l.AddNodes(3)
l.ShowNodes()
