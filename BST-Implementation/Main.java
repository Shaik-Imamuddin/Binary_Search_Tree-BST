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

    void insert(int val){
        Node newNode  = new Node(val);
        
        if(root==null){
            root = newNode;
            return;
        }

        Node temp = root;

        while(true){
            if(val<temp.data){
                if(temp.left==null){
                    temp.left = newNode;
                    break;
                }
                temp = temp.left;
            }
            else{
                if(temp.right==null){
                    temp.right = newNode;
                    break;
                }
                temp = temp.right;
            }
        }
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
        BinarySearchTree bst = new BinarySearchTree();

        int val;

        do{
            val = sc.nextInt();
            if(val!=-1)
                bst.insert(val);
        }while(val!=-1);

        bst.inorder(bst.root);
        System.out.println();
        bst.preorder(bst.root);
        System.out.println();
        bst.postorder(bst.root);
    }
}