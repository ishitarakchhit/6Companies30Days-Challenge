class Solution {
public:
    
    bool isInside(string big, string &small){ 
        //word should be present in the end of big
        int k = small.size()-1;
        int i= big.size()-1;
        while(k>=0 && i>=0){
            if(big[i] != small[k]) return false;
            k--;
            i--;
        }

        return true;
    }
    void check(unordered_map<string,bool> &mp, string &word){
        for(auto m:mp){
            if(m.second){
                if(isInside(m.first, word)){
                    return;
                }
            }
        }
        mp[word] = true;
    }

    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string,bool> mp;         //word, isPresent
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

        for(int i=words.size()-1; i>=0; i--){
            string word= words[i];
            //check if that word is present in the map as a substring ot not
            //if it is not present then create a key with value true
            check(mp, word);
        }

        int ans = 0;
        for(auto m:mp){
            if(m.second){
                ans += m.first.length();
                ans++;
            }
        }

        return ans;

    }
};
