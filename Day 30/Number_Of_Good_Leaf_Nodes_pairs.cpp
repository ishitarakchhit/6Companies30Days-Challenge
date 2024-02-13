/*
Approach
Maintain an array which has to returned in helper function
this array will represent the height of visited leaf nodes from the current node
Whenever you come across a leaf node, return an array with height 1,
else run a post order traversal,
now for the current node,
merge left and right arrays to form combined array which will have all the nodes from left and right array with height +1
and also compare all these nodes' height with one another and if the count is within the given distance, add one to the answer.

Complexity
Time complexity: O(n)

Space complexity: O(n)

Code
*/
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
    vector<int> helper(TreeNode* root, int &distance, int &count){
        if(root == NULL){
            vector<int> temp;
            return temp;
        }

        //if leaf node then return 1 in a vector
        if(root->left == NULL && root->right == NULL){
            vector<int> temp = {1};
            return temp;
        }

        //else visit left and right nodes
        vector<int> left = helper(root->left, distance, count);
        vector<int> right = helper(root->right, distance, count);
        vector<int> combined;

        
        for(auto it: left){
            combined.push_back(it+1);
        }
        for(auto it: right){
            combined.push_back(it+1);
        }
        for(int i=0; i<left.size(); i++){
            for(int j=0; j<right.size(); j++){
                //cout<<" inside"<<endl;
                int sum = left[i] + right[j];
                if(sum <= distance){
                    count++;
                }
            }
        }
        
        return combined;
        
    }

    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        vector<int> temp = helper(root, distance, count);

        return count;
    }
};
