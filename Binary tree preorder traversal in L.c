#include <stdlib.h>
void traverse(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    result[(*returnSize)++] = root->val;
    traverse(root->left, result, returnSize);
    traverse(root->right, result, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(100 * sizeof(int));
    if (root == NULL) {
        return result;
    }    
    traverse(root, result, returnSize);
    return result;
}
