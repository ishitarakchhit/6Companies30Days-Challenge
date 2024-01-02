class Solution {
public:
    void f(vector<string> &ans, string &temp, int d, string &digits, map<int, string> &mapping){
        cout<<temp;
        if(temp.length() == digits.length()){
            ans.push_back(temp);
            return;
        }
        if( d== digits.length()) return;
        //else
        //three cases to pair i, j, i&j
        int digit = digits[d]-'0';
        string map = mapping[digit];

        for(int j=0; j<map.size() ; j++){
            //use the current letter
            temp = temp+ map[j];
            f(ans, temp, d+1, digits, mapping);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        map<int, string> mapping;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        vector<string> ans;
        if(digits.size() == 0) return ans;
         
        string temp;
        f(ans, temp, 0, digits, mapping);
        return ans;
    }
};
