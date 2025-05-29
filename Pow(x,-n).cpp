class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n==0) return 1;
        if(x==1) return 1;
        double ans =1;
        long long m=n;
        m=abs(m);
        while(m>0)
        {
            if(m%2!=0)
            {
                ans=ans*x;
            }
            x=x*x;
            m=m/2;
        }
        if(n<0) return 1/ans;
        return ans;
    }
}; 