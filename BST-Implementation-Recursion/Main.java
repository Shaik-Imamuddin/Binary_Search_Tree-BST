import java.util.Scanner;

class Node{
    int data;
    Node left;
    Node right;

    Node(int val){
        data = val;
        left = right = null;
    }
}

class BinarySearchTree{
    Node root;
    
    BinarySearchTree(){
        root = null;
    }

    Node insert(Node root,int val){
        Node newNode  = new Node(val);        
        
        if(root==null){
            return newNode; 
        }

        if(val<root.data)
            root.left = insert(root.left,val);
        else
            root.right = insert(root.right,val);

        return root;
    }

    void inorder(Node root){
        if(root!=null){
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);
        }
    }

    void preorder(Node root){
        if(root!=null){
            System.out.print(root.data+" ");
            preorder(root.left);
            postorder(root.right);
        }
    }

    void postorder(Node root){
        if(root!=null){
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data+" ");
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        BinarySearchTree tree = new BinarySearchTree();
        int val;

        do{
            val = sc.nextInt();
            if(val!=-1)
                tree.root = tree.insert(tree.root,val);
        }while(val!=-1);

        tree.inorder(tree.root);
        System.out.println();
        tree.preorder(tree.root);
        System.out.println();
        tree.postorder(tree.root);
    }
}