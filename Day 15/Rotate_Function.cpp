class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f_k1 = 0;            //initially this will be f(k-1) or f(0)
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++){
            f_k1 += nums[i]*i;
            sum+= nums[i];
        }
        
        int ans = f_k1;

        //to find f(k) = f(k-1) + sumof(nums) - n*(k-1)th_element_from_end
        for(int i=1; i<n; i++){
            int f_k = f_k1 + sum - n*(nums[n-i]);
            ans = max(ans, f_k);
            f_k1 = f_k;
        }

        return ans;

    }
};
