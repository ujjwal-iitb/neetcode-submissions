/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inorderTraverse(TreeNode* root, int &count, int &k, int&ans){
        if(root->left) inorderTraverse(root->left, count, k, ans);
        if(count == k){
            ans = root->val;
        }
        count++;
        if(root->right) inorderTraverse(root->right, count, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 1, ans = 0;
        inorderTraverse(root, count, k, ans);
        return ans;
    }
};
