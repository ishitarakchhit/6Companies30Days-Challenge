class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int avg = nums[n/2];
        long long ans = 0;
        for(auto it: nums){
            ans += abs(avg-it);
        }
        return ans;


    }
};
