/*
Approach
Convex Hull

Step1: sort the entire array
Step2: Traverse the entire array and pick last 2 points from ans array with current point from original array and check if it forms a concave or convex vector. If concave pop the last element from answer vector
repeat this until size of ans array is 2
or when you stop getting concave vectors
push the current element inside the answer vector
repeat the entire algo while traversing the array in reverse fashion

Complexity
Time complexity: O(n*n)
Space complexity: O(n)
Code
*/
class Solution {
public:
    int angle(vector<int> p, vector<int> q, vector<int> r){
        return (q[1]-p[1])*(r[0]-q[0])-(q[0]-p[0])*(r[1]-q[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> ans;

        sort(trees.begin(), trees.end());

        for(int i=0; i<trees.size(); i++){
            while(ans.size()>1 && angle(ans[ans.size()-2], ans.back(), trees[i])>0){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }

        if(ans.size()==trees.size()) return ans;  //no more fence can be allocated

        //now run the entire algo in reverse operation 
        for(int i=trees.size()-2; i>=0; i--){
            while(ans.size()>1 && angle(ans[ans.size()-2], ans.back(), trees[i])>0){
                ans.pop_back();
            }
            ans.push_back(trees[i]);
        }

        //since the starting point will be repeated so pop it
        ans.pop_back();
        return ans;
    }
};
