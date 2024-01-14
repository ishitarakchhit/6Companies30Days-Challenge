class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //create the window by using hasing and count the frequcny of each window then finally iterate over the map to return all dna sequences which occur more than once

        unordered_map<string, int> mp;  //dna mapped to frequency
        string window = "";
        vector<string> ans;

        if(s.size() <10) return ans;
        
        //now create the first window
        for(int i=0; i<10; i++){
            window += s[i];
        }

        mp[window] = 1;

        int t = 0, h = 9;

        while(h<s.size() && h-t+1 >=10){
            window.erase(0, 1);
            t++;
            h++;
            if(h<s.size())
            window += s[h];

            //if this window already exists increase the frequency of this window otherwise create new entry
            mp[window]++;
        }

        //now iterate over the map to generate all answers

        for(auto &it: mp){
            if(it.second >1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
