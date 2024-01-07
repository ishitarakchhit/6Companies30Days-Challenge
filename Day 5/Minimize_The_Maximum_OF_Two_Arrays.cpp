class Solution {
public:
    bool isPossible(int &divisor1, int &divisor2, int &uniqueCnt1, int &uniqueCnt2, long long &mid){
        long long a = mid - (long long)mid/divisor1;
        long long b = mid- (long long)mid/divisor2;
        long long lcm = (long long)((long long)divisor1 * (long long)divisor2)/gcd(divisor1, divisor2);                    // !---mistake: take care of the type casting
        long long c = mid - (long long)mid/divisor1 - (long long)mid/divisor2 + (long long)(mid/lcm);

        if(a >= uniqueCnt1 && b >= uniqueCnt2 && a+b-c >= uniqueCnt1 + uniqueCnt2) return true;
        return false;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long s = 1;
        long long e = INT_MAX;
        
        long long ans = -1;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(isPossible(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};
