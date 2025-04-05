#ifndef CATEGORYNODE_H
#define CATEGORYNODE_H

template<class T>
class CategoryNode{
    public:
        T data;
        CategoryNode<T>* left;
        CategoryNode<T>* right;

        CategoryNode()
        :data(0),left(nullptr),right(nullptr){}

        CategoryNode(T d)
        :data(d),left(nullptr),right(nullptr){}
};


#endif