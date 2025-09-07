class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1;
        int high=INT_MIN;
        for(int pile:piles)
        {
            if(high<pile) high=pile;
        }
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long sum=0;
            for(int i=0;i<piles.size();i++)
            {
                sum+=(piles[i]+mid-1)/mid;
            }
            if(sum<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};