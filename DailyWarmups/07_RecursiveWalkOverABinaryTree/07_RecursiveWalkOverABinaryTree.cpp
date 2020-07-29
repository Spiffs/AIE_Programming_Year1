#include <iostream>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {}
};

void PrintTree(Node* root)
{
    std::cout << root->data << ", ";

    if (root->left != NULL)
        PrintTree(root->left);

    if (root->left != NULL)
        PrintTree(root->right);
}

void DeleteTree(Node* root)
{
    if (root != NULL)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        std::cout << "Deleted node: " << root->data << std::endl;
        delete root;
    }
}

int main(int argc, char** argv)
{
    /************************
               50
       20             70
     10   30        60  80
    ************************/
    Node* root = new Node(50,
        new Node(20, new Node(10), new Node(30)),
        new Node(70, new Node(60), new Node(80))
    );
    PrintTree(root);
    // pre - 50, 20, 10, 30, 70, 60, 80
    // post - 10, 30, 20, 60, 80, 70, 50

    std::cout << std::endl;

    DeleteTree(root);
    return 0;
}