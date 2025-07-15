class Node:
    def __init__(self, data):
        self.data = data
        self.next = None 

class Linked_List:
    # Head initialize
    def __init__(self):
        self.Head = None 
    
    # What to print if string typecast
    def __str__(self):
        for current_node in self:
            pass 
        return f"Head: {self.Head.data} | Tail: {current_node.data}"

    # Print whole linked list in specific format 
    def print_list(self):
        temp = self.Head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("End")

    def insert_start(self, node):
        node.next, self.Head = self.Head, node
    
    # Adds iterative functionality (needed for insert_end)
    def __iter__(self):
        node = self.Head 
        while node:
            yield node 
            node = node.next

    def insert_end(self, node):
        if not self.Head:
            self.Head = node 
            return 
        for current_node in self:
            pass 
        current_node.next = node 

if __name__ == "__main__":
    # Initialize list and its first few nodes
    list = Linked_List()
    list.Head = Node(4)
    node2 = Node(1)
    node3 = Node(5)

    # Link using next
    list.Head.next = node2
    node2.next = node3

    list.print_list()

    # Experimenting with insert methods
    list.insert_start(Node(2.5))
    list.insert_start(Node(8))

    list.insert_end(Node(14))

    # Comparison of the two types of print methods added
    list.print_list()
    print(list)
