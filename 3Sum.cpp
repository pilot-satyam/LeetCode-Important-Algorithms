
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        
        //1. Sort the given vector
        sort(nums.begin(), nums.end());
        
        //a+b+c = 0 => b+c = -a
        //Moving for value of 'a' (a=num[i]) which is not a duplicate
        for(int i=0; i<nums.size()-2; i++){
            
            if(i==0 || nums[i] != nums[i-1]){
                int low = i+1, high = nums.size()-1, sum = 0-nums[i];
                //sum is the pair we are finding in the array
                
                while(low < high){
                    //If a pair is found, insert triplet in res
                    if(nums[low] + nums[high] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]); //a
                        temp.push_back(nums[low]); //b
                        temp.push_back(nums[high]); //c
                        res.push_back(temp);
                        
                        //Now move low forward and high backwards, until they skip the current element
                        while(low<high && nums[low] == nums[low+1]) low++;
                        while(low<high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum) low++;
                    else if(nums[low] + nums[high] > sum) high--;
                }            }
        }
        return res;
    }
};

//2nd Method

/*
Two Pointer Approach:
The basic thinking logic for this is:
Fix any one number in sorted array and find the other two numbers after it. The other two numbers can be easily found using two pointers (as array is sorted) and two numbers should have sum = -1*(fixed number).

Traverse the array and fix a number at every iteration.
If number fixed is +ve, break there because we can't make it zero by searching after it.
If number is getting repeated, ignore the lower loop and continue. This is for unique triplets. We want the last instance of the fixed number, if it is repeated.
Make two pointers high and low, and initialize sum as 0.
Search between two pointers, just similiar to binary search. Sum = num[i] + num[low] + num[high].
If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
If sum is 0, that means we have found the required triplet, push it in answer vector.
Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively. Update the low and high with last occurences of low and high.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
         if(n<3)
            return ans;
        int i=0, low=1, high=n-1, a=nums[0], b=0, c=0, x=0;
        while(i<n){
           if(nums[i]!=a){
                a= nums[i];
                high = n-1;
                low = i+1;
           }
            if(nums[i]==a && low<high){
                x=0-a;
               
                b=nums[low];
                c=nums[high];
                if(b+c==x)
                {
                    ans.push_back({a,b,c});
                    low++;
                    high--;
                    
                    while(low<n && b==nums[low]){
                        
                            low++;
                    }
                    while(high>=0 && b==nums[high]){
                        
                            high--;
                    }
                   
                    continue;
                }
                else if(b+c<x && low<n)
                   { low++;continue;}
                else if(b+c>x && high>=0)
                   { high--;continue;}
            }
            
            if(low>=high || (nums[i]==a && i>0))
                i++;
        }
        return ans;
    }
};


