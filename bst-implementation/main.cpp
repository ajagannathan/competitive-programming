#include "header.h"

int main()
{
    // ReadMe();
    BinarySearchTree<int> tree;
    tree.InsertNode(50);
    tree.InsertNode(14);
    tree.InsertNode(30);

    BSTNode<int> *rootNode = tree.GetRootNode();

    tree.Show(rootNode);
}