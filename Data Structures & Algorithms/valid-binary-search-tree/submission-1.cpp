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

    void inOrderFlatten(TreeNode* root, vector<int>& inOrderVector){
        if(root->left) inOrderFlatten(root->left, inOrderVector);
        inOrderVector.push_back(root->val);
        if(root->right) inOrderFlatten(root->right, inOrderVector);
    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        vector<int> inOrderVector;

        inOrderFlatten(root, inOrderVector);

        for(int i = 0; i<inOrderVector.size()-1; i++){
            if(inOrderVector[i]>=inOrderVector[i+1]) return false;
        }

        return true;
    }
};
