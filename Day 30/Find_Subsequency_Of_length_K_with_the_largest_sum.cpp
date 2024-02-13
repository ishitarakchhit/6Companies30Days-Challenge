
/*Intuition
we have to find the largest sum using k elements,
so we can easily return an array with the largest k elements.
But we also need to maintain the order.
So why don't we take up all the k largest elements and map it to an unordered map? Then traverse the original array and push it

Approach
push all elements into a priority queue(min). and make sure this heap contains only k elements at once. now map the frequency of these elements in unordered map. now traverse the original array and push elements which occur in our map

Complexity
Time complexity: O(n + n)
Space complexity: O(k + k + k)
Code
*/
class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        //push all the elements in the min heap so it contains only k elements which were our largest elements from the given array
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }

        //now push the maximum elements in a map
        unordered_map<int,int> mp;
        while(pq.size()){
            mp[pq.top()]++;
            pq.pop();
            k--;
        }

        //now from the original array push the elements which are in mp to answr vector
        vector<int> ans;
        for(auto it: nums){
            if(mp[it]){
                ans.push_back(it);
                mp[it]--;
            }
        }
        return ans;
        
    }
};
