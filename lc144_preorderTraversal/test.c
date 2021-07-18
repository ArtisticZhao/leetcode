#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void left_all(struct TreeNode* root, int* res, int* cnt){
    printf("%d ", root->val);
    res[*cnt] = root->val;
    (*cnt)++;
    if(root->left!=NULL){
        left_all(root->left, res, cnt);
    }
    if(root->right!=NULL){
        left_all(root->right, res, cnt);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(root==NULL){
        *returnSize = 0;
        return NULL;
    }
    int* res = (int*)malloc(sizeof(int)*100);
    *returnSize = 0;
    left_all(root, res, returnSize);
    return res;
}
