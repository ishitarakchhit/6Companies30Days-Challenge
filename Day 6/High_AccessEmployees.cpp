Time complexity: O(n) 
Space complexity: O(length of array * 4 * length of employee names)

class Solution {
public:
    bool helper(vector<string> &times, vector<string> &ans){
        sort(times.begin(), times.end());

        for(int i=0; i+2<times.size(); i++){
            string time = times[i];
            if(time[1] == '9'){
                time[1] = '0';
                time[0] += 1;
            }
            else
            time[1] = time[1] + 1;
            cout<<"here";
            if(times[i+2] < time) return true;
        }
        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<access_times.size(); i++){
            if(mp.find(access_times[i][0]) != mp.end()){
                mp[access_times[i][0]].push_back(access_times[i][1]);
            }
            else{
                vector<string> temp;
                temp.push_back(access_times[i][1]);
                mp[access_times[i][0]] = temp;
            }
        }
        vector<string> ans;
        for(auto it: mp){
            if(helper(it.second, ans)){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
