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
    int maxBranchSum(TreeNode* root, int &ans){
        int leftBranchSum = 0, rightBranchSum = 0;

        if(root->left) leftBranchSum = max(maxBranchSum(root->left, ans), 0);
        if(root->right) rightBranchSum = max(maxBranchSum(root->right, ans), 0);

        ans = max(ans, root->val + leftBranchSum + rightBranchSum);

        return max(root->val + max(leftBranchSum, rightBranchSum), 0);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;

        maxBranchSum(root, ans);

        return ans;
    }
};
