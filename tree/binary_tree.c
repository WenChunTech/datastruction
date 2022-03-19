#include <stdio.h>
#include<stdlib.h>

/*
                            1
                    2             3

                4      5     NULL     NULL


*/

typedef struct TreeNode
{
    int data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

/*前序遍历*/
void preOrder(TreeNode* tree)
{
    if (NULL == tree)
        return;
    printf("%d ", tree->data);
    preOrder(tree->lchild);
    preOrder(tree->rchild);
}
/*中序遍历*/
void inOrder(TreeNode* tree)
{
    if (NULL == tree)
        return;
    inOrder(tree->lchild);
    printf("%d ", tree->data);
    inOrder(tree->rchild);
}

/*后序遍历*/
void postOrder(TreeNode* tree)
{
    if (NULL == tree)
        return;
    postOrder(tree->lchild);
    postOrder(tree->rchild);
    printf("%d ", tree->data);
}

int main() {
    //TreeNode* n1, * n2, * n3, * n4, * n5;
    TreeNode* n1 = malloc(sizeof(TreeNode));
    TreeNode* n2 = malloc(sizeof(TreeNode));
    TreeNode* n3 = malloc(sizeof(TreeNode));
    TreeNode* n4 = malloc(sizeof(TreeNode));
    TreeNode* n5 = malloc(sizeof(TreeNode));

    n1->data = 1;
    n1->lchild = n2;
    n1->rchild = n3;

    n2->data = 2;
    n2->lchild = n4;
    n2->rchild = n5;

    n3->data = 3;
    n3->lchild = NULL;
    n3->rchild = NULL;

    n4->data = 4;
    n4->lchild = NULL;
    n4->rchild = NULL;

    n5->data = 5;
    n5->lchild = NULL;
    n5->rchild = NULL;

    printf("preOrder: ");
    preOrder(n1);
    printf("\n");

    printf("inOrder: ");
    inOrder(n1);
    printf("\n");

    printf("postOrder: ");
    postOrder(n1);
    printf("\n");



    return 0;
}