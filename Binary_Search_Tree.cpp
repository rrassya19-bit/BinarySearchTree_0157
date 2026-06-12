#include <iostream>
using namespace std;

class Node {
public:
    string info;
    Node* leftChild;
    Node* rightChild;

    Node(string i, Node* l, Node* r) 
    {
        info = i;
        leftChild = l;
        rightChild = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree() 
    {
        ROOT = nullptr;
    }

    void insert(string element) 
    {
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);

        if (parent == NULL)
        {
            ROOT = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftChild = newNode;
        }

        else if (element > parent->info)
        {
            parent->rightChild = newNode;
        }
    }

    void search(string element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;
        parent = NULL;

        while((currentNode != NULL) &&
            (currentNode->info != element))
            {
                parent = currentNode;

                if (element < currentNode->info)
                    currentNode = currentNode->leftChild;
                else
                    currentNode = currentNode->rightChild;
        }
    }

    void inorder(Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL)
        {
            inorder(ptr->leftChild);
            cout << ptr->info << " ";
            inorder(ptr->rightChild);
        }
    }

     void preorder(Node *ptr)
    {
        if (ROOT == NULL)
        {
            cout <<"Tree is empty" <<  endl;
            return;
        }

        if (ptr != NULL)
        {
            cout << ptr->info << " ";
            preorder(ptr->leftChild);
            preorder(ptr->rightChild);
        }
    }
};