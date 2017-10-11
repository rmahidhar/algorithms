//
// Created by Mahidhar Rajala on 8/7/17.
//

#ifndef PROJECT_BINARYSEARCHTREE_H
#define PROJECT_BINARYSEARCHTREE_H

#include <iostream>

template<typename T>
class BinarySearchTree {
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *mRoot;
public:

    void insert(T data);

    void inorder();

private:
    TreeNode* insert_(TreeNode *node, T data);

    void inorder_(TreeNode *node);
};

#endif //PROJECT_BINARYSEARCHTREE_H
