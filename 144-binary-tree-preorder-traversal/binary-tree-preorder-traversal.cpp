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
    
     
    
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> preorder;
       if(root==nullptr){
        return preorder;
       }
       stack<TreeNode * >st;
       st.push(root);
       while(!st.empty()){
       TreeNode *  newroot = st.top();
        st.pop();
        preorder.push_back(newroot->val);
        if(newroot->right!=nullptr){
          st.push(newroot->right);
        }
        if(newroot->left!=nullptr){
            st.push(newroot->left);
        }

       }
       return preorder;
    }
};