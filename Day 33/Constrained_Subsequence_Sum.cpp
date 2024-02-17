/*
//Approach 1: DP (n*k)
dp[i] will denote the constrained sum upto index i if index i is included


approach2: dp using priority queue (n*logk)
heap will only contain k elements one at a time 
heap => element, index to check if the heap's top can be considered in the sum for the current index or not


approach3: dp using map (n*log) 
similar to heap solution, but we will keep track of the elements using map and map will only contain k elements

approach4: dp using deque (n)
deque will only contain k elements,
for every index i 
- pop front if front's index is lower than the range of i-k to i-1.
- pop back from deque whenever you find an element lower than it's front


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
