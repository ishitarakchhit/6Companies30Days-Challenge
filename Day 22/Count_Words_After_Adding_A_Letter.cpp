/*
Approach
using unordered_set and string matching

Complexity
Time complexity: O(targetWords.size()(word.size())(log(startWords.size)))
Space complexity: O(startWords.size())
Code
*/
class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        for(int i=0; i<targetWords.size(); i++){
            sort(targetWords[i].begin(), targetWords[i].end());
        }
        for(int i=0; i<startWords.size(); i++){
            sort(startWords[i].begin(), startWords[i].end());
            st.insert(startWords[i]);
        }

        int count = 0;
        bool flag = false;
        for(int i=0; i<targetWords.size(); i++){
            flag = false;
            string word = targetWords[i];
            for(int j=0; j<word.size(); j++){
                string temp = word;
                temp.erase(temp.begin()+j);
                if(st.find(temp)!=st.end()){
                    flag = true; break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};
