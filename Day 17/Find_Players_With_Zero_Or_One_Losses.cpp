class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;          //player , matches lost

        for(int i=0 ;i<matches.size(); i++){
            mp[matches[i][0]]=0;
            mp[matches[i][1]]=0;
        }
        for(int i=0 ;i<matches.size(); i++){
            mp[matches[i][1]]++;
        }

        int lost0=0, lost1=0;
        vector<vector<int>> ans(2);
        for(auto m:mp){
            if(m.second==0){
                ans[0].push_back(m.first);
            }
            else if(m.second==1){
                ans[1].push_back(m.first);
            }
        }

        return ans;


    }
};
