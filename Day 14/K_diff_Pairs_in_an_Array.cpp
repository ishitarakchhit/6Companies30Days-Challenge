class Solution {
public:
    set<pair<int,int>> st;   //diff pair
    void found(vector<int> &nums, int num,int k,  int start, int end){
        
        while(start<=end){
            int mid = start + (end-start)/2;
            int diff = abs(nums[mid] - num);
            if(diff == k){
                st.insert({num, nums[mid]}); return;
            }
            else if(diff > k)
                end = mid-1;
            else 
                start = mid+1;
        }
        
    }

    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            int num  = k;

            //to find k in the subspace;
            found(nums, nums[i], num, i+1, nums.size()-1);    //array, num to find, indices to search space
        }

        return st.size();
    }
};
