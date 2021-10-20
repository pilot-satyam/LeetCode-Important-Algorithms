class Solution {
public: 
         int start = 0;
        int end = nums.size()-1;
        
        while(start < end)
        {
            int mid  = start + (end - start)/2;
            if(nums[mid] > nums[mid+1])
                end = mid;
            else
                start = mid +1;
        }
        //this loop will continue 
        // this is start = end points same place
        return start;
    }
};
