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
    
    TreeNode* traverse(TreeNode* &root, int low, int high){
        //base casae
        if(!root) return NULL;
        
        if(root->val <low){
            return traverse(root->right, low, high);
        }
        if(root->val>high){
            return traverse(root->left, low, high);
        }
        else{
            if(root->left){
                root->left = traverse(root->left, low, high);
            }
            if(root->right){
                root->right = traverse(root->right, low, high);
            }
        }
        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traverse(root, low, high);
        return root;
    }
};
