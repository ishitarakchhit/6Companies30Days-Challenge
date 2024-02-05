/*
Intuition
brute force, product is highest when low value numbers are minimum

Approach
push all numbers into a min heap and then take out the minimum number once and incremenet it by 1. do this until k is exhausted.

Complexity
Time complexity: O(k)
Space complexity: O(n)
Code
*/
class Solution {
public:
int modulo = 1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long >, greater<long long >> pq;

        for(auto it:nums) pq.push(it);

        while(k){
            long long top = pq.top(); pq.pop();
            top+=1;
            pq.push(top);
            k--;
        }
        long long product =1;
        while(pq.size()>0){
            product=((long long)(product*pq.top()))%modulo;
             pq.pop();
        }
        return product;
    }
};
