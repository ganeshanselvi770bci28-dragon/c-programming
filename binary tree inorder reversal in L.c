#include <stdlib.h>

void traverse(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) {
        return;
    }
    traverse(root->left, result, returnSize);
    result[(*returnSize)++] = root->val;
    traverse(root->right, result, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(100 * sizeof(int));
    *returnSize = 0;
    traverse(root, result, returnSize);
    return result;
}
