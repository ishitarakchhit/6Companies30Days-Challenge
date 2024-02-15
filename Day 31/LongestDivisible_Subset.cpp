//Approach: similar to LIS

/*
Complexity
Time complexity: O(n^2)
Space complexity: O(n)*2
Code
  */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);    //LIS for every index will be 1
        vector<int> hash(n);    //to backtrack the subset
        int maxLength = 1;
        int max_index = 0;

        hash[0] = 0;

        for(int i=1; i<nums.size(); i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxLength){
                maxLength = dp[i];
                max_index = i;
            }
        }

        //backtrack to find the subset
        int i = max_index;
        vector<int> ans;
        ans.push_back(nums[i]);
        while(hash[i]!=i){
            i = hash[i];
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
