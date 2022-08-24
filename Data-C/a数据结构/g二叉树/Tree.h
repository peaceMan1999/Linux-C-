#pragma once 
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

typedef char T;

typedef struct TreeNode{
    T data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

// 初始化
TreeNode* Init(T x);

// 前序遍历
void prevOrder(TreeNode* bt);

// 树的节点
int TreeSize(TreeNode* bt);

// 树的层数
int Layer(TreeNode* bt);



