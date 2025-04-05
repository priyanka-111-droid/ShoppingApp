#ifndef CATEGORYBST_H
#define CATEGORYBST_H

#include "CategoryNode.h"
#include<iostream>
using namespace std;

template<class T>
class CategoryBST{

    private:
        CategoryNode<T>* root;
        void insertHelper(CategoryNode<T>* &root,CategoryNode<T>* newNode);//for normal binary tree,use queue to insert, not insertHelper()
        void displayInorderHelper(CategoryNode<T>* &root,int level);
        void displayPreorderHelper(CategoryNode<T>* &root,int level);
        void displayPostorderHelper(CategoryNode<T>* &root,int level);
        bool searchHelper(CategoryNode<T>* &root,T data);
        int countHelper(CategoryNode<T>* &root);
        int countLeavesHelper(CategoryNode<T>* &root);
        int heightHelper(CategoryNode<T>* &root);
        CategoryNode<T>* deleteHelper(CategoryNode<T>* &root,T data);
        CategoryNode<T>* findInorderSuccessor(CategoryNode<T>* root);
        void deleteTree(CategoryNode<T>* &root);//test using memory leak tools like Valgrind 
        
    public:
        CategoryBST()//constructor
        :root(nullptr){}

        ~CategoryBST(){//destructor
            deleteTree(root);
        }

        void insert(T data);
        void displayInorder();
        void displayPreorder();
        void displayPostorder();
        bool search(T data);
        int count();
        int countLeaves();
        int height();
        void deleteNode(T data);
};

//function defenitions(moved from .cpp to header)
//templates instantiated by compiler at compile-time
//if definitions are in different .cpp file, compiler won't be able to find them unless they are explicitly instantiated

//private func
template<class T>
void CategoryBST<T>::insertHelper(CategoryNode<T>* &root,CategoryNode<T>* newNode){
    if(root==nullptr){
        root = newNode;
        return;
    }

    //rec case
    if(newNode->data<root->data){
        insertHelper(root->left,newNode);
    }
    else{
        insertHelper(root->right,newNode);
    }
}

template<class T>
void CategoryBST<T>::displayInorderHelper(CategoryNode<T>* &root,int level){
    //L-node-R
    if(root==nullptr){
        return;
    }

    displayInorderHelper(root->left,level+1);
    root->data.displayProducts();
    displayInorderHelper(root->right,level+1);
}

template<class T>
void CategoryBST<T>::displayPreorderHelper(CategoryNode<T>* &root,int level){
    //node-L-R
    if(root==nullptr){
        return;
    }
    root->data.displayProducts();
    displayPreorderHelper(root->left,level+1);
    displayPreorderHelper(root->right,level+1);
    
}

template<class T>
void CategoryBST<T>::displayPostorderHelper(CategoryNode<T>* &root,int level){
    //L-R-node
    if(root==nullptr){
        return;
    }
    displayPostorderHelper(root->left,level+1);
    displayPostorderHelper(root->right,level+1);
    root->data.displayProducts();
}


template<class T>
bool CategoryBST<T>::searchHelper(CategoryNode<T>* &root,T data){
    if(root==nullptr){
        return false;
    }
    if(root->data==data){
        return true;
    }

    //rec
    if(data< root->data){
        return searchHelper(root->left,data);
    }else{
        return searchHelper(root->right,data);
    }
}


template<class T>
int CategoryBST<T>::countHelper(CategoryNode<T>* &root){
    if(root==nullptr){
        return 0;
    }
    return 1+countHelper(root->left) + countHelper(root->right);
}

template<class T>
int CategoryBST<T>::countLeavesHelper(CategoryNode<T>* &root){
    if(root==nullptr){
        return 0;
    }
    else if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    else{
        return countLeavesHelper(root->left) + countLeavesHelper(root->right);
    }
}


template<class T>
int CategoryBST<T>::heightHelper(CategoryNode<T>* &root){
    if(root==nullptr){
        return 0;
    }
    if(heightHelper(root->left)<=heightHelper(root->right)){
        return 1+heightHelper(root->right);
    }else{
        return 1+heightHelper(root->left);
    }
}

template<class T>
CategoryNode<T>* CategoryBST<T>::findInorderSuccessor(CategoryNode<T>* root){
    CategoryNode<T>* current = root->right;
    while(current!=nullptr && current->left !=nullptr){
        current = current->left;
    }
    return current;
}

template<class T>
CategoryNode<T>* CategoryBST<T>::deleteHelper(CategoryNode<T>* &root,T data){
    if(root==nullptr){
        return nullptr;//base case:node not found;
    }

    //recursively search for node to delete.
    if(data<root->data){
        root->left = deleteHelper(root->left,data);
    }else if(data > root->data){
        root->right = deleteHelper(root->right,data);//go right
    }else{
        if(root->data==data){
            cout<<"Deleting: "<<root->data.getCategoryName()<<" or "<<root->data.getCategoryId()<<endl;

            //case 1:No children(leaf node)
            if(root->left==nullptr && root->right==nullptr){
                cout<<"No children\n";
                delete root;
                root = nullptr;
            }
            else if(root->left==nullptr){
                cout<<"One child(right)\n";
                CategoryNode<T>* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right ==nullptr){
                cout<<"One child.\n";
                CategoryNode<T>* temp = root;
                root = root->left;
                delete temp;
            }else{
                cout<<"Two children.\n";
                CategoryNode<T>* temp = findInorderSuccessor(root);
                root->data = temp->data;
                root->right = deleteHelper(root->right,temp->data);
            }
        }
    }

    return root;
}

template<class T>
void CategoryBST<T>::deleteTree(CategoryNode<T>* &root){
    if(root!=nullptr){
        deleteTree(root->left);
        deleteTree(root->right);
        //delete current node 
        delete root;
        root = nullptr;
    }
}

//public func
template<class T>
void CategoryBST<T>::insert(T data){
    //here we are declaring a pointer variable newNode to an object of type CategoryNode<T>(pointer stores memory address of object)
    //why pointer variable needed??
    //since we are using new to dynamically allocate memory(on heap) for new CategoryNode<T> object,which returns pointer to memory address
    //new returns an address, so we need to ensure newNode is a pointer variable.

    CategoryNode<T>* newNode = new CategoryNode<T>(data);
    insertHelper(root,newNode);
}

template<class T>
void CategoryBST<T>::displayInorder(){
    displayInorderHelper(root,0);
}

template<class T>
void CategoryBST<T>::displayPreorder(){
    displayPreorderHelper(root,0);
}

template<class T>
void CategoryBST<T>::displayPostorder(){
    displayPostorderHelper(root,0);
}

template<class T>
bool CategoryBST<T>::search(T data){
    return searchHelper(root,data);
}

template<class T>
int CategoryBST<T>::count(){
    return countHelper(root);
}

template<class T>
int CategoryBST<T>::countLeaves(){
    return countLeavesHelper(root);
}

template<class T>
int CategoryBST<T>::height(){
    return heightHelper(root);
}

template<class T>
void CategoryBST<T>::deleteNode(T data){
    root = deleteHelper(root,data);
    return;
}


#endif
