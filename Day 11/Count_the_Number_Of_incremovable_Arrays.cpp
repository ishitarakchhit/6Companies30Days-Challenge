class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int i=0, j=0;
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                bool flag = true;
                int last = INT_MIN;
                int k = 0;

                while(k<n){
                    if(!(k>=i && k<=j)){
                        if(nums[k]<= last){
                            flag = false;
                            break;
                        }
                        else{
                            last = nums[k];
                        }
                    }
                    k++;
                }
                
                if(flag == true) count++;        
            }
        }
        return count;
        
    }
};
