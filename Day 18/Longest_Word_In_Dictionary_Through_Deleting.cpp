class Solution {
public:
    
    bool isPossible(string s, string word){
        int i=s.length()-1, j=word.length()-1;

        while(i>=0 && j>=0){
            if(s[i] == word[j]) j--;
            i--;
        }
        
        return j<0;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        sort(dictionary.begin(), dictionary.end());

        for(auto d: dictionary){
            if(d.length()>ans.length()){
                if(isPossible(s, d)){
                    ans = d;
                }
            }
        }
        return ans;
    }
};
