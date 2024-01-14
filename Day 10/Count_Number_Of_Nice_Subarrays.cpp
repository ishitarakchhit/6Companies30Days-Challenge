//Approach: sliding window 
//subarrays with exact k odds = atmost k - atmost (k-1)

//Apporach2: hashing and prefix sum method

class Solution {
public:
    int helper(auto &nums, int k){
        int t = 0, h = 0;
        int ans = 0;
        int odd = 0;

        while(h < nums.size()){
            if(nums[h]%2 == 1){
                odd ++;
                if(odd > k){ //now remove elements so as to get k odds in the window
                    while(odd >k && t<=h){
                        if(nums[t]%2 == 1){
                            odd--;
                        }
                        t++;
                    }
                }

            }
            ans+= (h-t+1);
            h++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //exactly k = atmost k - atmost(k-1)

        int b = helper(nums, k);
        int a = helper(nums, k-1);

        return b -a;
        
    }
};
