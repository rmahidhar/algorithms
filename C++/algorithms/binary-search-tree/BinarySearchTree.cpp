//
// Created by Mahidhar Rajala on 8/7/17.
//

#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

template<typename T>
class BinarySearchTree {
public:
    struct TreeNode {
        T data;
        TreeNode *left;
        TreeNode *right;
        explicit TreeNode(T val) {
            data = val;
            left = nullptr;
            right = nullptr;
        }
    };
    TreeNode *mRoot;
public:

    BinarySearchTree() : mRoot(nullptr) {

    }

    void insert(T data) {
        mRoot = insert(mRoot, data);
    }

    void inorder() {
        inorderNR(mRoot);
        std::cout << std::endl;
    }

    void preorder() {
        preorderNR(mRoot);
        std::cout << std::endl;
    }

    void postorder() {
        postorderNR1(mRoot);
        std::cout << std::endl;
    }

    TreeNode* lookup(T data) {
        return lookup(mRoot, data);
    }

    TreeNode* lca(T item1, T item2) {
        TreeNode* node1 = lookup(mRoot, item1);
        TreeNode* node2 = lookup(mRoot, item2);
        if (node1 && node2) {
            return lca1(mRoot, item1, item2);
        }
        return nullptr;
    }

    bool isBalanced() {
        int height = 0;
        return isBalanced(mRoot, height);
    }

    bool isBst() {
        return isBst(mRoot, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    }

    void path(T item1, T item2) {
        TreeNode* node1 = lookup(mRoot, item1);
        TreeNode* node2 = lookup(mRoot, item2);
        if (node1 && node2) {
            TreeNode *lca = lca_(mRoot, item1, item2);
            if (lca) {
                TreeNode* m = lca;
                if (lca->data == node1->data) {
                    m = node1;
                } else if (lca->data == node2->data) {
                    m = node2;
                }

                std::vector<T> lpath;
                std::vector<T> rpath;
                if (std::min(item1, item2) < m->data) {
                    path(m->left, std::min(item1, item2), lpath);
                }

                if (std::max(item1, item2) > m->data) {
                    path(m->right, std::max(item1, item2), rpath);
                }

                //std::reverse_copy(lpath.begin(), lpath.end(), eepath.begin());
                lpath.push_back(m->data);
                std::reverse(rpath.begin(), rpath.end());
                std::for_each(rpath.begin(), rpath.end(), [&](auto item) {lpath.push_back(item);});
                std::for_each(lpath.begin(), lpath.end(), [](auto item) { std::cout << item << " "; });
                std::cout << std::endl;
            }
        }
    }

    void path1(T item1, T item2) {
        TreeNode* node1 = lookup(mRoot, item1);
        TreeNode* node2 = lookup(mRoot, item2);
        if (node1 && node2) {
            TreeNode *lca = lca1(mRoot, item1, item2);
            TreeNode *m = lca;
            if (lca) {
                std::vector<T> lpath;
                std::vector<T> rpath;
                if (lca->data == item1) {
                    m = node1;
                } else if (lca->data == item2) {
                    m = node2;
                }
                path1(lca->left, item1, item2, lpath);
                path1(lca->right, item1, item2, rpath);

                //std::reverse_copy(lpath.begin(), lpath.end(), eepath.begin());
                lpath.push_back(m->data);
                std::reverse(rpath.begin(), rpath.end());
                std::for_each(rpath.begin(), rpath.end(), [&](auto item) {lpath.push_back(item);});
                std::for_each(lpath.begin(), lpath.end(), [](auto item) { std::cout << item << " "; });
                std::cout << std::endl;
            }
        }
    }

    void levelOrder() {
        levelOrder(mRoot);
    }

    void deserialize(std::list<T>& preOrderList) {
        T item = preOrderList.front();
        preOrderList.pop_front();
        deserialize(mRoot, item, std::numeric_limits<T>::min(), std::numeric_limits<T>::max(), preOrderList);
    }

    void deserialize(TreeNode*& node, T& insertVal, T min, T max, std::list<T>& list) {
        if (insertVal > min && insertVal < max) {
            T val = insertVal;
            node = new TreeNode(val);
            if (!list.empty()) {
                insertVal = list.front();
                list.pop_front();
                deserialize(node->left, insertVal, min, val, list);
                deserialize(node->right, insertVal, val, max, list);
            }
        }
    }

    void serialize(std::list<T>& list) {
        preorder(mRoot, list);
    }

    void preorder(TreeNode *node, std::list<T>& list) {
        if (node == nullptr) {
            return;
        }
        list.push_back(node->data);
        preorder(node->left, list);
        preorder(node->right, list);
    }

    void serialize1(std::list<T>& preOrderList) {
        preorder1(mRoot, preOrderList);
    }

    void preorder1(TreeNode *node, std::list<T>& list) {
        if (node == nullptr) {
            list.push_back(-1);
            return;
        }
        list.push_back(node->data);
        preorder1(node->left, list);
        preorder1(node->right, list);
    }

    void deserialize1(std::list<T>& preOrderList) {
        deserialize1(mRoot, preOrderList);
    }

    void deserialize1(TreeNode*& node, std::list<T>& list) {
        if (!list.empty()) {
            T insertVal = list.front();
            list.pop_front();
            if (insertVal != -1) {
                node= new TreeNode(insertVal);
                deserialize1(node->left, list);
                deserialize1(node->right, list);
            }
        }
    }

    bool compare(BinarySearchTree& bst) {
        return compare(mRoot, bst.mRoot);
    }

    bool compare(TreeNode *lt, TreeNode *rt) {
        if (lt && rt && lt->data == rt->data) {
            return compare(lt->left, rt->left) && compare(lt->right, rt->right);
        } else {
            return lt == nullptr && rt == nullptr;
        }
    }

private:

    bool isBalanced(TreeNode* node, int& height) {
        if (node == nullptr) {
            height = 0;
            return true;
        }
        int lheight = 0, rheight = 0;
        bool lbalanced = isBalanced(node->left, lheight);
        bool rbalanced = isBalanced(node->right, rheight);
        height = std::max(lheight, rheight) + 1;
        return lbalanced && rbalanced && abs(lheight - rheight) <= 1;
    }

    void path(TreeNode* node, T item, std::vector<T>& p) {
        if (node == nullptr) return;

        if (node->data == item) {
            p.push_back(node->data);
            return;
        }

        if (item < node->data) {
            path(node->left, item, p);
        } else {
            path(node->right, item, p);
        }
        p.push_back(node->data);
    }

    TreeNode* path1(TreeNode* node, T item1, T item2, std::vector<T>& p) {
        if (node == nullptr) return nullptr;

        if (node->data == item1 || node->data == item2 ) {
            p.push_back(node->data);
            return node;
        }

        TreeNode* left = path1(node->left, item1, item2, p);
        TreeNode* right = path1(node->right, item1, item2, p);

        if (left) {
            p.push_back(node->data);
            return node;
        } else if (right) {
            p.push_back(node->data);
            return node;
        } else {
            return nullptr;
        }
    }

    TreeNode* insert(TreeNode *node, T data) {
        if (node == nullptr) {
            node = new TreeNode(data);
        } else {
            if (data <= node->data) {
                node->left = insert(node->left, data);
            } else {
                node->right = insert(node->right, data);
            }
        }
        return node;
    }

    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void inorderNR(TreeNode *node) {
        std::stack<TreeNode*> stack;
        while(node != nullptr || !stack.empty()) {
            if (node != nullptr) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                std::cout << node->data << " ";
                node = node->right;
            }
        }
    }

    void preorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorderNR(TreeNode *node) {
        std::stack<TreeNode*> stack;
        while(node != nullptr || !stack.empty()) {
            if (node != nullptr) {
                std::cout << node->data << " ";
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                node = node->right;
            }
        }
    }

    void postorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    void postorderNR(TreeNode *node) {
        std::stack<TreeNode*> stack;
        TreeNode *prev = nullptr;
        TreeNode *curr = nullptr;
        stack.push(node);
        while(!stack.empty()) {
            curr = stack.top();
            if (!prev || prev->left == curr || prev->right == curr) {
                // traversing down the tree
                if (curr->left) {
                    stack.push(curr->left);
                } else if (curr->right) {
                    stack.push(curr->right);
                }
            } else if (curr->left == prev) {
                // traversing up, left subtree
                if (curr->right) {
                    stack.push(curr->right);
                }
            } else {
                // traversing up, right subtree
                std::cout << curr->data << " ";
                stack.pop();
            }
            prev = curr;
        }
    }

    // postorder non iterative using two stacks
    // 1. push the root to the first stack.
    // 2. pop the node from first stack and push to second stack.
    // 3. push the left child followed by right child to the first stack.
    // 4. repeat 2 and 3 till first stack is empty.
    // 5. once done, the second stack have all the nodes ready to be traversed in post-order.
    // 6. pop of the nodes from the stack one by one.
    void postorderNR1(TreeNode *node) {
        std::stack<TreeNode*> firststack;
        std::stack<TreeNode*> secondstack;
        firststack.push(node);
        while(!firststack.empty()) {
            TreeNode *n = firststack.top();
            secondstack.push(n);
            firststack.pop();
            if (n->left) firststack.push(n->left);
            if (n->right) firststack.push(n->right);
        }
        while(!secondstack.empty()) {
            std::cout << secondstack.top()->data << " ";
            secondstack.pop();
        }
    }

    TreeNode* lookup(TreeNode *node, T data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            return lookup(node->left, data);
        } else if (data > node->data) {
            return lookup(node->right, data);
        } else {
            return node;
        }
    }

    // Lowest common ancestor in binary search tree
    TreeNode* lca_(TreeNode *node, T item1, T item2) {
        if (node == nullptr) return nullptr;
        if (std::max(item1, item2) < node->data) {
            return lca_(node->left, item1, item2);
        } else if (std::min(item1, item2) > node->data) {
            return lca_(node->right, item1, item2);
        } else {
            return node;
        }
    }

    // Lowest common ancestor in non-binary search tree
    TreeNode* lca1(TreeNode *node, T item1, T item2) {
        if (node == nullptr) return nullptr;
        if (node->data == item1 || node->data == item2) {
            return node;
        }
        TreeNode *lnode = lca1(node->left, item1, item2);
        TreeNode *rnode = lca1(node->right, item1, item2);
        if (lnode && rnode) {
            return node;
        }
        return lnode ? lnode : rnode;
    }

    bool isBst(TreeNode *node, int min, int max) {
        if (node == nullptr) {
            return true;
        }
        if (node->data < min || node->data > max) {
            return false;
        }
        return isBst(node->left, min, node->data) &&
               isBst(node->right, node->data, max);
    }

    void levelOrder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        std::list<TreeNode*> parents;
        std::list<TreeNode*> children;
        parents.push_back(node);
        while(!parents.empty()) {
            TreeNode *parent = parents.front();
            parents.pop_front();
            if (parent->left) children.push_back(parent->left);
            if (parent->right) children.push_back(parent->right);
            if (parents.empty()) {
                std::cout << parent->data << std::endl;
                std::for_each(children.begin(), children.end(), [&](auto item) {parents.push_back(item);});
                children.clear();
            } else {
                std::cout << parent->data << " ";
            }
        }
    }
};


int main(int argc, char* argv[]) {
    BinarySearchTree<int> bst;
    std::vector<int> items = {60, 41, 74, 16, 53, 65, 25, 46, 55, 63, 70, 42, 62, 64};
    std::for_each(items.begin(), items.end(), [&](auto item) { bst.insert(item); } );
    bst.inorder();
    bst.preorder();
    bst.postorder();
    int item = 53;
    if (bst.lookup(item) != nullptr) {
        std::cout << "Found item:" << item << std::endl;
    }
    int item1 = 41;
    int item2 = 42;
    BinarySearchTree<int>::TreeNode *lca = bst.lca(item1, item2);
    if (lca) {
        std::cout << "LCA(" << item1 << "," << item2 << "):" << lca->data << std::endl;
    }
    std::cout << "is bst: " << bst.isBst() << std::endl;
    bst.path(42, 64);
    bst.levelOrder();

    std::list<int> buf;
    bst.serialize1(buf);
    std::for_each(buf.begin(), buf.end(), [](auto item) { std::cout << item << " ";});
    std::cout << std::endl;
    BinarySearchTree<int> bst1;
    bst1.deserialize1(buf);
    bst1.preorder();
    std::cout << "binary tree equal:" << bst1.compare(bst) << std::endl;
}
