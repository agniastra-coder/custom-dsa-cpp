#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define SENTINEL -999999

void serialize(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) {
        arr[(*idx)++] = SENTINEL;
        return;
    }

    arr[(*idx)++] = root->val;
    serialize(root->left, arr, idx);
    serialize(root->right, arr, idx);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int nums1[10000];
    int nums2[10000];
    int count1 = 0;
    int count2 = 0;

    serialize(p, nums1, &count1);
    serialize(q, nums2, &count2);

    if (count1 != count2) {
        return false;
    }

    for (int k = 0; k < count1; k++) {
        if (nums1[k] != nums2[k]) {
            return false;
        }
    }
    return true;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode* temp = root->left;
    struct TreeNode* temp1 = root->right;
    root->left = NULL;
    root->right = NULL;
    root->left = temp1;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

bool isSymmetric(struct TreeNode* root) {
    return isSameTree(root->left, invertTree(root->right));
}
