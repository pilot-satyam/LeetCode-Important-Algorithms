/* The idea here is to generate all the subsets possible and then apply the constraint given and select only the required answer*/

class Solution {
public:
    
    void solve(int idx,int n,int k,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(idx > n)
        {
            if(ds.size() == k)  // Required size constraint acc.to the question
            {
                ans.push_back(ds);
            }
            return;// so that more copmbinations are not generated
        }
        ds.push_back(idx);
        solve(idx+1,n,k,ans,ds);
        ds.pop_back();
        solve(idx+1,n,k,ans,ds);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,n,k,ans,ds);
        return ans;
    }
};
