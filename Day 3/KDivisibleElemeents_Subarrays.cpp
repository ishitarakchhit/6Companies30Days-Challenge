class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> ans;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            count = 0;
            vector<int> temp;
            for(int j=i; j<nums.size(); j++){
                if(count == k){
                    if(nums[j]%p !=0){
                        temp.push_back(nums[j]);
                    }
                    else break;
                }
                else{
                    if(nums[j]%p == 0){
                        count ++;
                        temp.push_back(nums[j]);
                    }
                    else{
                        temp.push_back(nums[j]);
                    }
                }
                ans.insert(temp);
            }

        }


        return ans.size();
    }
};
