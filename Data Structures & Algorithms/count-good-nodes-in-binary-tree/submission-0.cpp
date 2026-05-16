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
    void checkNodeIsGood(TreeNode* root, int currMax, int* count){
        if(root->val >= currMax){
            (*count)++;
            currMax = root->val;
        }

        if(root->left) checkNodeIsGood(root->left, currMax, count);
        if(root->right) checkNodeIsGood(root->right, currMax, count);
    }

    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        int countVal = 0;
        int* count = &countVal;

        checkNodeIsGood(root, INT_MIN, count);
        return *count;
    }
};
