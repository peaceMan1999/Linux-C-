#include "Tree.h"

// 初始化
TreeNode* Init(T x)
{
    TreeNode* root = (TreeNode*) malloc (sizeof(TreeNode));
    if (root == NULL){
        perror("Init");
        exit(-1);
    }

    root->data = x;
    root->left = root->right = NULL;

    return root;
}

// 前序遍历 -根-左-右
void prevOrder(TreeNode* root)
{
    if (root == NULL){
        return;
    }

    printf("%c ", root->data);
    prevOrder(root->left);
    prevOrder(root->right);

}

// 树的节点
int TreeSize(TreeNode* root)
{
    return root == NULL ? 0 : 1 + TreeSize(root->left) + TreeSize(root->right);
}

// 树的层数
int Layer(TreeNode* root)
{
    if (root == NULL){
        return 0;
    }

    return Layer(root->left) > Layer(root->right) ? Layer(root->left) + 1 : Layer(root->right) + 1;
}




