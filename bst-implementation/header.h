#ifndef HEADER_H
#define HEADER_H

#include <iostream>

// void ReadMe();

template <typename T>
struct BSTNode
{

    T data;
    BSTNode *left;
    BSTNode *right;
};

template <typename T>
class BinarySearchTree
{

public:
    BinarySearchTree();
    BinarySearchTree(T val);
    BSTNode<T> *GetRootNode();
    BSTNode<T> *GetNewNode(T data);
    void InsertNode(T data);
    void Show(BSTNode<T> *node);
    ~BinarySearchTree();

private:
    BSTNode<T> *_root;
};

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
    _root = nullptr;
}

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree(T val)
{
    _root = GetNewNode(val);
}

template <typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
    //delete _root;
}

template <typename T>
inline BSTNode<T> *BinarySearchTree<T>::GetRootNode()
{
    return _root;
}

template <typename T>
inline BSTNode<T> *BinarySearchTree<T>::GetNewNode(T val)
{
    BSTNode<T> *node = new BSTNode<T>();

    node->data = val;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

template <typename T>
inline void BinarySearchTree<T>::InsertNode(T val)
{
    //BSTNode<T> *node = _root;
    if (_root == nullptr)
    {
        _root = GetNewNode(val);
    }
    else
    {
        BSTNode<T> *node = _root;
        while (val < node->data && node->left != nullptr)
        {
            node = node->left;
        }

        while (val > node->data && node->right != nullptr)
        {
            node = node->right;
        }

        if (val <= node->data)
        {
            node->left = GetNewNode(val);
        }
        else
        {
            node->right = GetNewNode(val);
        }

        // while (node->left != nullptr && node->right != nullptr)
        // {
        //     if (val <= node->data)
        //     {
        //         node = node->left;
        //     }
        //     else
        //     {
        //         node = node->right;
        //     }
        // }
        // if (val <= node->data)
        // {
        //     node->left = GetNewNode(val);
        // }
        // else
        // {
        //     node->right = GetNewNode(val);
        // }
    }
}

template <typename T>
inline void BinarySearchTree<T>::Show(BSTNode<T> *node)
{
    if (node == nullptr)
    {
        std::cout << "Null\n";
        return;
    }
    else
    {
        std::cout << node->data << "\n";
        Show(node->left);
        Show(node->right);
    }
}

#endif //HEADER_H