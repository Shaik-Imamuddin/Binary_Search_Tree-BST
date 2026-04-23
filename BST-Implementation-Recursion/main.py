class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
    
class BinarySearchTree:
    def __init__(self):
        self.root = None
    
    def insert(self,root,val):
        new_node = Node(val)

        if root is None:
            return new_node

        if val<root.data:
            root.left = self.insert(root.left,val) 
        else:
            root.right = self.insert(root.right,val) 
        
        return root
    
    def inorder(self,root):
        if root is not None:
            self.inorder(root.left)
            print(root.data,end=" ")
            self.inorder(root.right)
    
    def preorder(self,root):
        if root is not None:
            print(root.data,end=" ")
            self.preorder(root.left)
            self.preorder(root.right)
    
    def postorder(self,root):
        if root is not None:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data,end=" ")


bst = BinarySearchTree()
val=0

while True:
    val = int(input())
    if(val==-1):
        break
    bst.root = bst.insert(bst.root,val)

bst.inorder(bst.root)
print()
bst.preorder(bst.root)
print()
bst.postorder(bst.root)