#ifndef BST_H
#define BST_H

class BST
{
private:
    struct node
    {
        int key;
        node *right;
        node *left;

        node(){};
        node(int k, node *r = nullptr, node *l = nullptr)
        {
            this->key = k;
            this->right = r;
            this->left = l;
        }
    };

    node *root;

    void AddLeaf(int key, node* p);
    void PrintInOrder(node* p);

public:
    BST();

    node *CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();
};

#endif /* BST_H */