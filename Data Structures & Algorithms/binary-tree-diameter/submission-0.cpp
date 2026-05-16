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

    int heightOfBinaryTree(TreeNode* root, int* diameter){
        if(root==NULL){
            return 0;
        }

        int leftHeight = heightOfBinaryTree(root->left, diameter);
        int rightHeight = heightOfBinaryTree(root->right, diameter);

        *diameter = max(*diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameterVal = 0; 
        int * diameter = &diameterVal; 

        heightOfBinaryTree(root, diameter);
        return *diameter;
    }
};
