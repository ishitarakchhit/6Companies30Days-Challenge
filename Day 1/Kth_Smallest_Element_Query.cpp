class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q: queries){
            
            vector<pair<string,int>> temp;

            for(int i=0; i<nums.size(); i++){
                temp.push_back({nums[i].substr(nums[i].size()- q[1]), i});
            }
            sort(temp.begin(), temp.end());

            ans.push_back(temp[q[0]-1].second);
        }
        return ans;
    }
};
