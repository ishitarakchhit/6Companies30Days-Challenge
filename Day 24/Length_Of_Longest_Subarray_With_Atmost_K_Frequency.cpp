/*
Approach
sliding window

Complexity
Time complexity: O(n)
Space complexity: O(n)
Code
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int i=0, j=1;
        int window = 1;
        mp[nums[i]]++;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]]>k && i<j){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            window = max(window, j-i+1);
            j++;
        }
        return window;
    }
};
