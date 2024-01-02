class Solution {
public:
    int m =0, n=0;
    int it = 0, jt = 0;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        int I = it, J = jt;
        if(jt+1 < n){
            jt ++;
        }
        else if(it+1 < m){
            jt = 0;
            it++;
        }
        else{
            it = 0;
            jt = 0;
        }
        return {I, J};
    }
    
    void reset() {
      //already been handled in flip() function
    }
};
