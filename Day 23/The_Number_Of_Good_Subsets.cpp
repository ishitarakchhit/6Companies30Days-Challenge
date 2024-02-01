class Solution {
public:
    int primes[10] = {2,3, 5, 7, 11, 13, 17, 19, 23, 29};
    int modulo = 1e9 + 7;

    long long power(long long num, int p){
        if(p==0) return 1;
        if(p==1) return num;
        long long a = power(num, p/2);
        if(p%2==0) return (a*a)%modulo;
        else return ((a*a)%modulo)*num;
    }


    long long helper(vector<int> &nums, int mask, int i, vector<vector<int>> &dp, vector<int> &freq){
        //base case
        if(i==nums.size()) return (mask>0);

        if(dp[i][mask]!=-1) return dp[i][mask]%modulo;

        long long a =0, b=0;
        if((nums[i]&mask)==0){
            a = a+((long long)(freq[nums[i]])*(long long)(helper(nums, mask|nums[i], i+1, dp, freq)))%modulo;            
            b = b+(long long)helper(nums, mask, i+1, dp, freq)%modulo;
        }
        else{
            b = (long long)helper(nums, mask, i+1, dp, freq);
        }
        
        dp[i][mask] = (a + b)%modulo;
        return (a+b)%modulo;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        int mask =0;     //represent the primes that we have already used until a particular index 
        int count1 = 0;
        vector<int> freq(1025, 0);     //mapps the frequency of each good number
        int n = nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                count1++; continue;
            }
            bool flag = false, distinct = true;
            for(int p=0; p<10; p++){
                if(nums[i]%primes[p]==0){
                    if(nums[i]%(primes[p]*primes[p])==0){
                        distinct = false; break;
                    }
                    else flag = true;
                }
            }
            if(flag && distinct){
                //now convert all elements of arr into 10 bit representeation
                int temp = 0;
                for(int p=0; p<10; p++){
                    if(nums[i]%primes[p]==0){
                        temp = temp|(1<<(p));
                    }
                }
                freq[temp]++;
                if(freq[temp]==1){
                    arr.push_back(temp);
                }
            }
        }

        
        vector<vector<int>> dp(arr.size()+1, vector<int> (1024, -1));


        long long ans = helper(arr, mask, 0, dp, freq);
        ans = ans%modulo;
        ans = (((long long)power(2, count1))*(ans))%modulo;
        return ans%modulo;
    }
};
