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
};