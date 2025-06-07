class Solution {
    int mod=1e9+7;
public:
    long long power(long long base, long long exp)
    {
        long long res=1;
        base=base%mod;
        while(exp>0)
        {
            if(exp%2!=0) res=(res*base)%mod;
            base=(base*base)%mod;
            exp=exp/2;
        }
        return res;
    }
    int countGoodNumbers(long long n) 
    {
        long long even_idx=(n+1)/2;
        long long odd_idx=n/2;
        long long even=power(5,even_idx);
        long long odd=power(4,odd_idx);
        return (even*odd)%mod;
    }
};