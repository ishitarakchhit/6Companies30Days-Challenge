/*Approach
2 pointer

Complexity
Time complexity: O(nlog(n) + mlog(m) + n + m)
Space complexity: O(1)
Code */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i=0, j=0;
        int child = 0;
        while(i<g.size() && j<s.size()){
            if(g[i] <= s[j]){
                i++; 
                child++;
            }
            j++;
        }
        return child;
    }
};
