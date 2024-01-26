class Solution {
public:
    int modulo = 1e9+7;

    int helper(vector<int> &nums, int size, int lastInd, int mask, vector<vector<int>> &dp){
        //base case
        if(size == nums.size()){
            return 1;
        }

        if(dp[lastInd][mask]!= -1) return dp[lastInd][mask];

        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            int num= nums[i];
            int last = nums[lastInd];

            if(mask&(1<<i)) continue;         //if this num has been visited

            if(mask!=0 && last%num!=0 && num%last!=0) continue;

            //else
            ans = ans + helper(nums, size+1, i, mask|(1<<i), dp)%modulo;
        }
        dp[lastInd][mask] = ans%modulo;
        return ans%modulo;
    }

    
    int specialPerm(vector<int>& nums) {
        int mask =0;     //i represents nums's index
        int n= nums.size();
        vector<vector<int>> DP(n, vector<int> (1<<(n), -1));
        return helper(nums, 0, 0, mask, DP);  //nums , size as 0 and last num as 1
    }
};
