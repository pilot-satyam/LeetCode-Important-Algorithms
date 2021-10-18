class Solution {
public:
    int searchPos(vector<int> n, int t, bool p) {
        int lo = 0, hi = n.size()-1, res = -1, mid;
        
        while(lo <= hi) {
            mid = (hi-lo)/2 + lo;
            
            if (n[mid] == t) {
                res = mid;
                if(p == 0) 
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if (n[mid] < t) {
                lo = mid + 1;
            }
            if (n[mid] > t) {
                hi = mid - 1;
            }
        }
        return res;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        // 0 -> starting position & 1 -> ending position
        return { searchPos(nums, target, 0), searchPos(nums, target, 1) };
    }
};


