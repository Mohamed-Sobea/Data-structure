#include <iostream>
#include <queue>
using namespace std;

class treeNode {
public:
    char data;
    treeNode *left;
    treeNode *right;

    treeNode(char _data) {
        this->data = _data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binaryTree {
private:
    treeNode *root;

public:
    binaryTree() { root = nullptr; }

    void insert(char _data) {
        treeNode *newNode = new treeNode(_data);
        if (this->root == nullptr) {
            this->root = newNode;
            return;
        }

        queue<treeNode*> q;
        q.push(this->root);
        while (!q.empty()) {
            treeNode *currentNode = q.front();
            q.pop();

            if (currentNode->left == nullptr) {
                currentNode->left = newNode;
                break;
            } else {
                q.push(currentNode->left);
            }

            if (currentNode->right == nullptr) {
                currentNode->right = newNode;
                break;
            } else {
                q.push(currentNode->right);
            }
        }
    }

    int height(treeNode *node) {
        if (node == nullptr) return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int height() {
        return height(root);
    }

    void internalPreOrder(treeNode *node) {
        if (node == nullptr)
            return;
        cout << node->data << " -> ";
        internalPreOrder(node->left);
        internalPreOrder(node->right);
    }
    void PreOrder() {
        internalPreOrder(root);
        cout << "NULL" << endl;
    }

    void internalInOrder(treeNode *node) {
        if (node == nullptr)
            return;
        internalInOrder(node->left);
        cout << node->data << " -> ";
        internalInOrder(node->right);
    }
    void InOrder() {
        internalInOrder(root);
        cout << "NULL" << endl;
    }


    void internalPostOrder(treeNode *node) {
        if (node == nullptr)
            return;
        internalPostOrder(node->left);
        internalPostOrder(node->right);
        cout << node->data << " -> ";
    }
    void PostOrder() {
        internalPostOrder(root);
        cout << "NULL" << endl;
    }







};

int main() {
    binaryTree tree;
    tree.insert('A');
    tree.insert('B');
    tree.insert('C');
    tree.insert('D');
    tree.insert('E');
    tree.insert('F');
    tree.insert('G');
    tree.insert('H');
    tree.insert('I');

    cout << "PreOrder Traversal: ";
    tree.PreOrder();
    cout << "InOrder Traversal: ";
    tree.InOrder();
    cout << "PostOrder Traversal: ";
    tree.PostOrder();

    return 0;
}
