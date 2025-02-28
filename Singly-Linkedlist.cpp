#include <iostream>
using namespace std;


class Node {
public :
    int data;
    Node *next;
};

class Linkedlist {
public:
       Node *Head;  // pointer to point to the first Node
    Linkedlist() {
        Head = NULL;
    }

    bool isEmpty() {
        if (Head == NULL) {
            return true;
        }
        return false;
    }

    void insertFirst(int newvalue) {
        Node *newNode = new Node();
        newNode->data = newvalue;
        if (isEmpty()) {
            newNode->next = NULL;
            Head = newNode;
        }
        else {                             // the list not empty
            newNode->next = Head;
            Head = newNode;
        }
    }

    // To Travese list items print,sum..etc
    void travers() {
        Node *temp = Head;
        while (temp != NULL) {
            cout << temp->data <<"--> " ;
            temp = temp->next;            // To move to the next node
        }
        cout <<"Null"<< endl;
    }

    // To search for spacific Item "Key"
    bool isFound(int key) {
        Node *temp = Head;  // temp pointer to traverse on list
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            else
                temp = temp->next;
        }

        return false;
    }

    void insertBeforitem(int item , int newValue) {

        if (isFound(item)) {            // check if the item exist in list or not
            Node *newNode = new Node();
            newNode->data = newValue;

            Node *temp = Head;
            // To connect the newNode to the list
            while (temp != NULL && temp->next->data != item) {
                //save at temp the address of node before the item node
                temp = temp->next;
            }
            newNode->next = temp->next;

            temp->next = newNode;
        }
        else
            cout << "The item not exist in list\n";
    }

    void insert_at_end(int newitem) {
        if (isEmpty()) {               // if list is empty then the newitem will be first item
            insertFirst(newitem);
        }
        Node *temp = Head;             //to traverse over the list
        while (temp->next != NULL) {           // not (temp != NULL)  becaus this get out of list
            temp = temp->next;                // move to the next node
        }
        Node *newnode = new Node();
        newnode->data = newitem;
        temp->next = newnode;
        newnode->next = NULL;
    }

    void delete_first() {
        Node *temp = Head;
        Head = Head -> next;
        delete(temp);
    }



    void delete_item(int item) {
        if (isEmpty())
            cout << "List is empty ! \n";
        if(Head->data == item) {            // in first of list
            Node *delptr = Head;
            Head = Head-> next ;
            delete(delptr);
        }
        else {                             //unknown location
            Node *dellptr = Head;
            Node *previos = NULL;
            while (dellptr->data != item) {
                previos = dellptr;             // move the privios ptr
                dellptr = dellptr->next;        // move the dellptr
            }
            previos = dellptr->next;             //  let prev ptr point to node after deleted node
            delete(dellptr);
        }

    }

//End Of Class
};

int main()
{
    Linkedlist list;
    if (list.isEmpty()) {
        cout << "The list is Empty ! \n" ;
    }else
        cout << "Not empty ";
    int item ;
    for (int i =0 ; i < 4 ; i++) {
        cout << "Enter item to insert it to first of list \n";
        cin >> item;
        list.insertFirst(item);
    }

    cout << "List befoire append\n";
    list.travers();

    // cout << "Enter new item in last of list : ";
    // cin >> item;
    // list.insert_at_end(item);


    list.delete_first();
    cout << "List After delete\n";
    list.travers();
    // // Insert a new value before a specified item
    // int newvalue;
    // cout << "Enter the item and the new value to be inserted before the item: ";
    // cin >> item >> newvalue;
    // list.insertBeforitem(item, newvalue);



     return 0;
}
