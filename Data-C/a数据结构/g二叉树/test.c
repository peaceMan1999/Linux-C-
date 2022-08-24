#include "Tree.h"

int main()
{
    TreeNode* A = Init('A');
    TreeNode* B = Init('B');
    TreeNode* C = Init('C');
    TreeNode* D = Init('D');
    TreeNode* E = Init('E');
    TreeNode* F = Init('F');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    prevOrder(A);

    int count = TreeSize(A);
    printf("节点个数 : %d\n", count);


    int layer = Layer(A);
    printf("层数 : %d\n", layer);

    return 0;
}