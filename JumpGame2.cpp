class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;   //base case
        
        //initialize jump=1 , we are taking jump from 0th index to the range mxjump
        //currjump =>we can take jump from particular  index
		//mxjump => we cango up to maximum
		// jump => to count no. of jump
        int jump=1,n=nums.size(),currjmp=nums[0],mxjmp=nums[0];
        
        int i=0;
		
		//till we reach last index, NOTE: Not necessary to cross last index
        while(i<n-1)
        {
            mxjmp=max(mxjmp,i+nums[i]);
             
            if(currjmp==i) //we have to take jump now because our currjump now ends.
            {
                jump++;//increment in jump
                currjmp=mxjmp; //assign new maxjmp to currjmp
            }
            i++;
        }
        if(currjmp<n-1)return -1; //we are not able to reach at the end of array because there may be some zeroes are present in given array so that we cannot move further
        return jump;
    }
};
