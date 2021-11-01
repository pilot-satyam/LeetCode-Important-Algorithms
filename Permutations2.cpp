class Solution {
public:
    void permute(vector<vector<int>> &res, map<int,int>&mp, vector<int> &ans,int n)
    {
        if(ans.size()==n)
        {
            res.push_back(ans);
            return;
        }
       for(auto &it:mp)
       {
           if(it.second<=0)
               continue;
           it.second--;
           ans.push_back(it.first);
           permute(res,mp,ans,n);
           it.second++;
           ans.pop_back();
       }      
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        vector<vector<int>> res;
        vector<int> ans;
        permute(res,mp,ans,nums.size());
        return res;
    }
};
