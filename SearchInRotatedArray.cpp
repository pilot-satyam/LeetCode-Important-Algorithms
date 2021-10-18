class Solution {
public:
//first finding pivot.
    int index(vector<int>nums){
            int low=0;
         int high=nums.size()-1;
        int n=nums.size();
          while(low<high){
              int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]){low=mid+1;}
              else{
                  high=mid;
              }
          }
       return low;
    }
    
	//binary search function
    int bs(vector<int>nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
        
    }
	
    int search(vector<int>& nums, int target) {
         int i=index(nums);
        int low=0;
        int high=nums.size()-1;
        int j=bs(nums,low,i-1,target);  //finding target in left side
        int k=bs(nums,i,high,target);  //finding target in right side
        if(j==-1){return k;}         //if target not found on left side return the answer on right side and vice versa;
        else if(k==-1){return j;}
        else
            return -1;
        
    }
};
