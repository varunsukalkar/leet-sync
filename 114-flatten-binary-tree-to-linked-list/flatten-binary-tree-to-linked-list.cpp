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


    TreeNode * flattenn(TreeNode * root){
        if(root==nullptr ){
            return nullptr;
        }
        TreeNode * left = flattenn(root->left);
        TreeNode * right = flattenn(root->right);
        TreeNode * temp = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode * temp2 = root;
        while(temp2 ->right){
            temp2=temp2->right;
        }
        temp2->right = temp;
        return root;
    }
    void flatten(TreeNode* root) {
        root=flattenn(root);
    }
};