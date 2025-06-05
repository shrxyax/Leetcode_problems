class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    int left = 0, right = 1;

    while (right < n) {
        int diff = nums[right] - nums[left];

        if (diff == k) {
            int lCount = 1, rCount = 1;

            // Count duplicates of nums[left]
            while (left + 1 < right && nums[left] == nums[left + 1]) {
                lCount++;
                left++;
            }

            // Count duplicates of nums[right]
            while (right + 1 < n && nums[right] == nums[right + 1]) {
                rCount++;
                right++;
            }

            count += lCount * rCount;
            left++;
            right++;
        } else if (diff < k) {
            right++;
        } else {
            left++;
            if (left == right) right++; // Maintain left < right
        }
    }

    return count;
    }
};

