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


 Complexity
Time complexity: O(n)
Space complexity: O(n)
 */
class Solution {
public:
    //returns {{sum, isBST}, {leftmax},{rightmin}}
    pair<pair<int,bool>, pair<int,int>> helper(TreeNode* root, int &ans){
        if(root == NULL) return {{0, true}, {-1e6, 1e6}};

        //postorder
        auto left = helper(root->left, ans);
        auto right = helper(root->right, ans);

        if(left.first.second == true && right.first.second == true){
            bool isBST = false;
            int sum = 0;
            if(root->val > left.second.first && root->val < right.second.second){
                isBST = true;
                sum = root->val + left.first.first + right.first.first;
                ans = max(ans, sum);
                int mini = min(root->val, left.second.second);
                int maxi = max(root->val, right.second.first);
                return {{sum, isBST}, {maxi, mini}};                      //mistake: swapped maxi, mini while passing
            }
            else{
                sum = max(left.first.first, right.first.first);
                ans = max(ans, sum);
                return {{sum, isBST}, {left.second.second, right.second.first}};
            }
        }

        else{
            int max_Sum = max(left.first.first, right.first.first);
            ans = max(ans, max_Sum);
            return {{max_Sum, false}, {1e6, -1e6}};
        }
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};
