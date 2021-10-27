
/* Using Two pointer approach*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 0,high = 0,ans = INT_MAX,sum=0;
        while(high < n)
        {
            sum+=nums[high];
            while(sum>=target)
            {
                ans = min(ans,high-low+1);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
