#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left, *right;
    int data;
    } *root = NULL;
    
int *inorder, *postorder, s;
    
int findnextnode(int st, int end)
    {
    int i, j;
    for (i = s - 1; i >= 0; i--)
    {
        for (j = st; j <= end; j++)
        {
            if (postorder[i] == inorder[j])
                return j;
        }
    }
    return -1;
}    

    
struct node *buildtree(struct node *root, int st, int end)
{
    if (st > end)
        return NULL;
    root = (struct node *)malloc(sizeof(struct node));
    root->left = root->right = NULL;


    int index = findnextnode(st, end);
    root->data = inorder[index];


    if (st== end)
        return root;


    root->left = buildtree(root->left, st, index - 1);
    root->right = buildtree(root->right, index + 1, end);

    return root;
}




void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int i;
    scanf("%d", &s);

    inorder = (int *)malloc(sizeof(int) * s);
    postorder = (int *)malloc(sizeof(int) * s);
    
    for (i = 0; i < s; i++)
        scanf("%d", &inorder[i]);

    for (i = 0; i < s; i++)
        scanf("%d", &postorder[i]);
    root = buildtree(root, 0, s - 1);

    preorder(root);
    return 0;
}
