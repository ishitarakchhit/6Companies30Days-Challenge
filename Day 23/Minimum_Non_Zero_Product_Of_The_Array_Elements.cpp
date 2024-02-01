/*
Intuition
ab is always greater than 1c
so we convert every numbers product from num1num2 to 1num.
for the given range 0 is complimentary to 2^p-1 and so on,
so product will be (n-1)^n/2 * n

Approach
greedy with recursion(to calculate power of a number)

Complexity
Time complexity: O(log(n))
Space complexity: O(n/2)
Code
*/
class Solution {
public:
    long long modulo = 1000000007;
    long long power(long long num, long long n){
        if(n==0) return (long long)1;
        if(n==1) return num%modulo;
        long long p = power(num,n/2);
        p=p%modulo;
        if(n&2==0) return (p*p)%modulo;
        else return (((p*p)%modulo)*(num%modulo))%modulo;

    }

    int minNonZeroProduct(int p) {
        long long n = pow(2, p);
        n--;
        long long extra = n;
        long long num = n-1;
        n=(long long)(n/2); 

        long long product = (long long)1;
        product = power(num, n);
        product = ((product)*(extra%modulo))%modulo;
        return (int)product;
    }
};
