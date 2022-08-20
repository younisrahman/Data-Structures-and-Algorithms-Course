class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def print_list(self):
        if self.head is None:
            print("Linked List is empty")
            return
        iter = self.head
        data = ''
        while iter:
            data += str(iter.data) + ' --> ' if iter.next else str(iter.data)
            iter = iter.next
        print(data)

    def get_length(self):
        count = 0
        iter = self.head
        while iter:
            count += 1
            iter = iter.next
        return count

    def insert_at_beginning(self, data):
        node = Node(data, self.head)
        self.head = node

    def insert_at_end(self, data):
        if self.head is None:
            self.head = Node(data, None)
            return
        iter = self.head
        while iter.next:
            iter = iter.next
        iter.next = Node(data, None)

    def insert_at(self, index, data):
        if index < 0 or index > (self.get_length()):
            raise Exception("Invalid index")
        if index == 0:
            self.insert_at_beginning(data)
            return
        count = 0
        iter = self.head
        while iter:
            if count == index-1:
                node = Node(data, iter.next)
                iter.next = node
                break
            count += 1
            iter = iter.next

    def remove_at(self, index):
        if index < 0 or index > (self.get_length()):
            raise Exception("Invalid index")
        if index == 0:
            self.head = self.head.next
            return
        count = 0
        iter = self.head
        while iter:
            if count == index-1:
                iter.next = iter.next.next
                break
            count += 1
            iter = iter.next

    def insert_after_value(self, data_after, data_to_insert):
        iter = self.head
        while iter:
            if iter.data == data_after:
                node = Node(data_to_insert, iter.next)
                iter.next = node
                break
            iter = iter.next

    def remove_by_value(self, data):
        iter = self.head
        while iter:
            if iter.next.data == data:
                iter.next = iter.next.next
                break
            iter = iter.next

    def insert_values(self, data_list):
        self.head = None
        for data in data_list:
            self.insert_at_end(data)


if __name__ == '__main__':
    link = LinkedList()
    # link.insert_at_beginning(1)
    # link.insert_at_beginning(2)
    # link.insert_at_beginning(3)
    # link.insert_at_end(4)
    # link.insert_at_end(5)
    # link.print_list()
    # link.get_length()
    link.insert_values(["banana", "mango", "grapes", "orange"])
    link.insert_at(1, "blueberry")
    link.remove_at(2)
    link.insert_after_value("grapes", "pineapple")
    link.print_list()
    link.remove_by_value("grapes")
    link.print_list()

    link.insert_values([45, 7, 12, 567, 99])
    link.insert_at_end(67)

    link.print_list()
