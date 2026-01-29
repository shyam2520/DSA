from collections import defaultdict

class DLL: 
    def __init__(self,key,val): 
        self.key=key 
        self.val=val 
        self.prev=None 
        self.next=None 


class LRUCache:


    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = DLL(-1,-1)
        self.tail = DLL(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head 
        self.map = defaultdict(DLL)    
        self.size = 0 

    def insertFront(self,Node: DLL): 
        headNext = self.head.next 
        Node.next = headNext 
        self.head.next = Node 
        headNext.prev=Node 
        Node.prev = self.head
        self.size+=1

    def delNode(self,Node:DLL):
        prevNode = Node.prev
        nextNode = Node.next 
        prevNode.next = nextNode 
        nextNode.prev = prevNode
        self.map.pop(Node.key)
        self.size-=1

    def get(self, key: int) -> int:
        if key in self.map: 
            nodeaddr = self.map[key] 
            self.delNode(nodeaddr) 
            self.map[key]=nodeaddr 
            self.insertFront(nodeaddr)
            return nodeaddr.val
        else: 
            return -1 


    def put(self, key: int, value: int) -> None:
        if key in self.map: 
            nodeaddr = self.map[key]
            nodeaddr.val = value 
            self.delNode(nodeaddr) # remove from map as well
            self.map[key]=nodeaddr 
            self.insertFront(nodeaddr)
        else: 
            newnode = DLL(key=key,val=value)
            self.map[key]=newnode 
            self.insertFront(newnode)
        
        while self.size>self.cap:
            self.delNode(self.tail.prev)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)