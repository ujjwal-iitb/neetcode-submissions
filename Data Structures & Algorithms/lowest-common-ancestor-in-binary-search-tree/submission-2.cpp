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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> st;
        st.insert(root);

        TreeNode* temp = root;

        while(temp!=p){
            st.insert(temp);
            if(temp->val < p->val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        st.insert(p);

        TreeNode* ans = root;
        temp = root;

        while(temp!=q){
            if(st.find(temp)!=st.end()){
                ans = temp;
            }

            if(temp->val < q->val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }

        }
        if(st.find(q)!=st.end()){
            ans = q;
        }
        return ans;
    }
};
