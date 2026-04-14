class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None

class BinarySearchTree:
    def __init__(self):
        self.root=None
    
    def insert(self,val):
        newNode = Node(val)
        if self.root is None:
            self.root=newNode
            return
        
        temp = self.root
        while True:
            if val<temp.data:
                if temp.left is None:
                    temp.left=newNode
                    break
                temp = temp.left
            else:
                if temp.right is None:
                    temp.right=newNode
                    break
                temp=temp.right
            
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
    val=int(input())
    if(val==-1):
        break
    bst.insert(val)

bst.inorder(bst.root)
print()
bst.preorder(bst.root)
print()
bst.postorder(bst.root)