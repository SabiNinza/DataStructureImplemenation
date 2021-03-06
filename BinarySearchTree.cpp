#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;

    //constructor
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
    //insertion in the binary search tree
    Node * add(Node *root,int val){
        //base case
        if(root==NULL) return new Node(val);
        //rec case
        if(root->data>val){
            root->left=add(root->left,val);
        }
        if(root->data<val){
            root->right = add(root->right, val);
        }
        return root;
    }
    //search a key in the binary search tree
    bool search(Node *root,int val){
        //base case
        if(root->data==val){return true;}
        //rec case
        if(root->data<val)
            return search(root->right,val);
        if(root->data>val) return search(root->left,val);
        return false;
    }
    Node * remove(Node *root,int val){
        //base case key does'nt exist
        if(root==NULL) return NULL;
        //search in left subtree
        else if(root->data>val){
            root->left=remove(root->left,val);
            return root;
        }
        //search in right subtree
        else if(root->data<val){
            root->right=remove(root->right,val);
            return root;
        }
        else{
            //key exist or match found
            if(root->data==val){
                //0 children
                if(root->left==NULL&&root->right==NULL) {
                    delete root;
                    return NULL;
                }
                //1 childern
                else if(root->left!=NULL&&root->right==NULL){
                    Node *temp=root->left;
                    delete root;
                    return temp;
                }
                else if(root->left==NULL&&root->right!=NULL){
                    Node *temp=root->right;
                    delete root;
                    return temp;
                }
                //2 children
                else{
                    //temp is right minimum or left subtree max value
                    Node * temp=root->right;
                    while(temp->left!=NULL){
                        temp=temp->left;
                    }
                    root->data=temp->data;
                    root->right=remove(root->right,val);
                    return root;
                }
            }
        }

    }
    //build binary search tree using sorted array
    Node * buildArray_BST(int arr[],int s,int e){
        //base case
        if(s>e) return NULL;
        int mid=(s+e)/2;
         Node *root=new Node(arr[mid]);
         root->left=buildArray_BST(arr,s,mid-1);
         root->right=buildArray_BST(arr,mid+1,e);
         return root;
    }
    //build binary search tree
    Node *Build_BST(){
        int val;
        cin>>val;
        Node *root=NULL;

        while(val!=-1){
            root=add(root,val);
            cin>>val;
        }
        return root;
    }
int main() {
    Node*root=Build_BST();
    return 0;
}
