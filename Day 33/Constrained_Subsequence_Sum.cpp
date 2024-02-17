/*
Approach
iterate over nums[i], Keep pushing the current maximum element into the heap with its index.
Now for every index, get into the heap to find the maximum element in i-k to i-1 range. If heap's top contains element with index lower than this range pop it otherwise calculate the maximum sum for current index and update answer variable according to maximum value.

Complexity
Time complexity: O(nlogk)
Space complexity: O(k)
Code
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;       // element, index
        int ans = nums[0];
        pq.push({ans, 0});
        
        for(int i=1; i<nums.size(); i++){
            int maxi = nums[i];

            while(!pq.empty() ){
                auto top = pq.top();
                if(top.second >= i-k){
                    maxi = max(maxi, nums[i]+top.first); 
                    break;
                }
                else{
                    pq.pop();
                }
            }
            ans =max(ans, maxi);
            pq.push({maxi, i});
        }

        return ans;
    }
};
