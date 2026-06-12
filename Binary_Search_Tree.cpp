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