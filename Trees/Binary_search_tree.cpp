#include <iostream>
#include <queue>
using namespace std;

class treeNode {
public:
    int data;
    treeNode *left;
    treeNode *right;

    treeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class binarySearchTree {
public:
    treeNode* root;

    binarySearchTree() : root(nullptr) {}

    treeNode* insertBS(treeNode* r,int item){      //Using recursion
        if (r == nullptr) {
          treeNode* newNode = new treeNode(item);
            r = newNode;
            return r;
        }

        if (item < r->data)
            r->left = insertBS(r->left, item);
        else
            r->right = insertBS(r->right, item);

        return r;
    }
    // Public method to insert a value (calls the recursive function)
    void insert(int item) {
        root = insertBS(root,item);
    }

    void preOrder(treeNode* r) {  // root , left , right
        if (r == nullptr)
            return;
        cout << r->data << "\t";
        preOrder(r->left);
        preOrder(r->right);
    }

    void inOrder(treeNode* r) {  // left , root , right
        if (r == nullptr)
            return;
        inOrder(r->left);
        cout << r->data << "\t";
        inOrder(r->right);
    }

    void postOrder(treeNode* r) {  // left , right , root
        if (r == nullptr)
            return;
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << "\t";
    }

    bool Find(int item) {                     // Iterative method
        treeNode* currentNode = root;
        while (currentNode != nullptr) {
            if (item == currentNode->data) {
                return true;  // Item found
            }
            else if (item < currentNode->data) {
                currentNode = currentNode->left; // Search left
            }
            else {
                currentNode = currentNode->right; // Search right
            }
        }
        return false; // Item not found
    }

    treeNode* search(treeNode* r, int key) {   // search using recursion
        if (r == nullptr)              // no data in tree
            return nullptr;
        if (r->data == key) {
            return r;
        }
        else if(key < r->data) {
            return search(r->left,key);
        }
        else
            return search(r->right,key);
    }

    bool search(int key) {
        treeNode* value = search(root,key);
        if (value == NULL)
            return false;
        else
            return true;
    }

    treeNode* findMin(treeNode* r) {
        if (r == NULL || r->left == NULL)
            return r;
        else
            return findMin(r->left);               // by way the minimum values in left
    }

    treeNode* findMax(treeNode* r) {
        if (r == NULL || r->right == NULL)
            return r;
        else
            return findMax(r->right);
    }


    treeNode* Delete(treeNode* r , int key) {
        if (r == nullptr)     //empty tree
            return NULL;

        if (key < r->data)          // Search in the left subtree
            r->left = Delete(r->left,key);
        else if(key > r->data)      // Search in the right subtree
            r->right = Delete(r->right, key);
        else {
            // Case 1: Node is a leaf (no children)
            if (r->left == NULL && r->right == NULL) {
                delete r;
                return NULL;   // Return NULL to remove the node
            }
            // Case 2: Node has only one child (left or right)
            else if(r->left == NULL) {
                treeNode* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL) {
                treeNode* temp = r->left;
                delete r;
                return temp;  // Return the child to replace the deleted node
            }
            // Case 3: Node has two children
            else {
                treeNode* max = findMax(r->left);
                r->data = max->data;
                r->left = Delete(r->left,max->data);
            }
        }
        return r;
    }



};
int main()
{
    //45, 15, 79, 90, 10, 55, 12, 20, 50
    binarySearchTree bst;
    bst.insert(45);
    bst.insert(15);
    bst.insert(79);
    bst.insert(90);
    bst.insert(10);
    bst.insert(55);
    bst.insert(12);
    bst.insert(20);
    bst.insert(50);

    bst.inOrder(bst.root);
    cout << endl;
    bst.preOrder(bst.root);
    cout << endl;
    bst.postOrder(bst.root);
    cout <<endl<< "-------------------------" << endl;

    bool val = bst.Find(944929);
    if (val)
        cout << "Yes we find the item !!" << endl;
    else
        cout << "Nope we don't find the item !!" << endl;
    cout << "-------------------------" << endl;

    treeNode* min = bst.findMin(bst.root);
    if (min == nullptr)
        cout << "There is No Items in the tree !!" << endl;
    else
        cout << "The minmum value in the tree is "<<min->data << endl;

    cout << "-------------------------" << endl;

    treeNode* max = bst.findMax(bst.root);
    if (min == nullptr)
        cout << "There is No Items in the tree !!" << endl;
    else
        cout << "The Maximum value in the tree is "<<max->data << endl;

    return 0;
}
