#ifndef _HEADER_H
#define _HEADER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

typedef std::chrono::high_resolution_clock high_res_clock;
typedef std::chrono::time_point<high_res_clock> high_res_time_point;
typedef std::chrono::duration<float> duration;

struct Pos
{
    int r, c;
    Pos()
        : r(0), c(0)
    {
    }
    Pos(int x, int y)
        : r(x), c(y)
    {
    }
    ~Pos() {}
};
struct Timer
{
    high_res_time_point start, end;
    duration d;
    Timer()
        : start(high_res_clock::now())
    {
    }
    ~Timer()
    {
        end = high_res_clock::now();
        d = end - start;
        std::cout << "\nRuntime : " << d.count() * 1000.0f << " ms\n";
    }
};

template <typename T>
struct TreeNode
{
    T data;
    //Pos pos;
    std::vector<TreeNode *> branches;
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *m_root;
    TreeNode<T> *m_getNewNode(T &);

public:
    Tree();
    Tree(T val);
    void insertNode(TreeNode<T> *, T);
    TreeNode<T> *getRootNode() const;
    ~Tree();
};

template <typename T>
inline Tree<T>::Tree() : m_root(NULL) {}

template <typename T>
inline Tree<T>::Tree(T val) : m_root(m_getNewNode(val)) {}

template <typename T>
inline TreeNode<T> *Tree<T>::m_getNewNode(T &val)
{
    TreeNode<T> *newNode = new TreeNode<T>();
    newNode->data = val;
    return newNode;
}

template <typename T>
inline void Tree<T>::insertNode(TreeNode<T> *root, T val)
{
    TreeNode<T> *newNode = m_getNewNode(val);
    if (root == NULL)
    {
        m_root = newNode;
    }
    else
    {
        root->branches.push_back(newNode);
    }
}

template <typename T>
inline TreeNode<T> *Tree<T>::getRootNode() const { return m_root; }

#endif
