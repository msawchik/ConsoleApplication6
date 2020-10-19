// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//




// inserting into a list

using namespace std;
#include <iostream>


struct node
{
    int key_value;
    node* left;
    node* right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node* search(int key);
        void destroy_tree();
        node* getnode() 
        {
            return root;
        }

    private:
        void destroy_tree(node* leaf);
        void insert(int key, node* leaf);
        node* search(int key, node* leaf);

        node* root;
};

btree::btree()
{
    root = NULL;
}

btree::~btree()
{
    destroy_tree();
}

void btree::destroy_tree()
{
    destroy_tree(root);
}

void btree::destroy_tree(node* leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void btree::insert(int key)
{
    if (root != NULL)
        insert(key, root);
    else
    {
        root = new node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void btree::insert(int key, node * leaf)
{
    if (key < leaf->key_value)
    {
        if (leaf->left != NULL)
            insert(key, leaf->left);
        else
        {
            leaf->left = new node;
            leaf->left->key_value = key;
            leaf->left->left = NULL;    //Sets the left child of the child node to null
            leaf->left->right = NULL;   //Sets the right child of the child node to null
        }
    }
    else if (key >= leaf->key_value)
    {
        if (leaf->right != NULL)
            insert(key, leaf->right);
        else
        {
            leaf->right = new node;
            leaf->right->key_value = key;
            leaf->right->left = NULL;  //Sets the left child of the child node to null
            leaf->right->right = NULL; //Sets the right child of the child node to null
        }
    }
}

node* btree::search(int key)
{
    return search(key, root);
}

node* btree::search(int key, node* leaf)
{
    if (leaf != NULL)
    {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return NULL;
}



int main()
{
    btree mybtree;
    node* mynode;
    int values[] = { 25, 75, 50, 10, 20, 150, 125, 30, 6, 15, 15 };
 
    for (int i : values)
    {
        mybtree.insert(i);
    }

    mynode = mybtree.search(150);

    if(mynode != NULL)
    {
        cout << mynode->key_value << endl;
    }
    else
    {
        cout << mynode << " Means not found" << endl;
    }

    //mybtree.~btree();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
