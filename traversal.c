#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} tree_node;

tree_node *insert_node(tree_node *root, int value)
{
    if (root == NULL)
    {
        root = (tree_node *)malloc(sizeof(tree_node));
        root->data = value;
        root->left = root->right = NULL;
    }
    else
    {
        if (value > root->data)
        {
            root->right = insert_node(root->right, value);
        }
        if (value < root->data)
        {
            root->left = insert_node(root->left, value);
        }
    }
    return root;
}

void preorder(tree_node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(tree_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(tree_node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    tree_node *root = NULL;
    int n;
    int node;
    scanf("%d", &n);
    int i;
    for (i= 0; i < n; i++)
    {
        scanf("%d", &node);
        root = insert_node(root, node);
    }

    // PRE-ORDER 
    preorder(root);
    printf("\n");

    // INORDER 
    inorder(root);
    printf("\n");

    // POST-ORDER 
    postorder(root);

    return 0;
}
