class Solution {
public:
    int findMin(vector<int>& nums) {
        
        //O(N)
        /*
        int mini = *min_element(nums.begin(),nums.end());
        return mini;
        */
        
        //O(logN) - Binary Search
        
        int n = nums.size(),left = 0,right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[left]>nums[right])
                if(nums[left]>nums[mid])
                    right = mid;
                else
                    left = mid+1;
            else
                return nums[left];
        }
        return nums[0];
    }
};
