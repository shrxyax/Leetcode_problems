class Solution {
public:
   long long c=0;
   void merge(vector<int> &arr,int low,int mid,int high)
   {
    int j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        c += (j - (mid + 1));
    }

    vector<int> tmp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            tmp.push_back(arr[left]);
            left++;
        }
        else
        {
            tmp.push_back(arr[right]);
            right++;
        }
    
    }
    while(left<=mid)
    {
        tmp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        tmp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=tmp[i-low];
    }
   }
   void mergesort(vector<int> & arr,int low,int high)
   {
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
   }

    int reversePairs(vector<int>& nums)
    {
        c=0;
        mergesort(nums,0,nums.size()-1);
        return c;
    }
};