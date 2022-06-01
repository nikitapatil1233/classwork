#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE newn;
    int x;
    newn = (NODE)malloc(sizeof(struct node));
    printf("enter data to be stored....if no more data to be inserted enter -1\n");
    scanf("%d", &x);

    if (x == -1)
    {
        return 0;
    }

    newn->data = x;

    printf("enter left child of %d\n", x);
    newn->left = getnode();

    printf("enter right child of %d\n", x);
    newn->right = getnode();

    return newn;
}

void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

int count(NODE root)
{
    int a = 1;

    if (root == NULL)
    {
        return 0;
    }

    else
    {
        a += count(root->left);
        a += count(root->right);
        return a;
    }
}

void main()
{
    NODE root;
    root = getnode();

    printf("preorder is : \n");
    preorder(root);
    printf("\n");

    printf("postorder is : \n");
    postorder(root);
    printf("\n");

    printf("inorder is : \n");
    inorder(root);
    printf("\n");

    int c = count(root);
    printf("no of nodes are %d\n", &c);
}