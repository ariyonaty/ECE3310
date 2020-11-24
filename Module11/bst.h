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

    void AddLeaf(int key, node *p);
    void PrintInOrder(node *p);
    node *ReturnNode(int key, node *p);
    int FindSmallest(node *p);
    void RemoveNode(int key, node *parent);
    void RemoveRootMatch();
    void RemoveMatch(node *parent, node* match, bool left);

public:
    BST();

    node *CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    node *ReturnNode(int key);
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);
};

#endif /* BST_H */