Approach1: using stack
approach2: using iteration

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;

        //Approach: 
        //who will be the winner if only 1 friend is there ? then only 2 friend is there ? then 3 ? then n
        for(int i=1; i<=n; i++){
            ans = (ans+k)%i;
        }
        return ans+1;
    }
};
