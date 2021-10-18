class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        for(auto vctr : matrix)
        {
            for(auto it : vctr)
            {
                if(it == target)
                    return true;
            }
        }
        return false;
    }
};
