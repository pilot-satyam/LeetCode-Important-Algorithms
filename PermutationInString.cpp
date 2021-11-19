class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int n = s1.size(),m = s2.size();
		map<char,int> m1;
		for(int i=0;i<n;i++) m1[s1[i]]++;
		for(int i=0;i<=m-n;i++){
			map<char,int> m2;
			for(int j=i;j<i+n;j++) m2[s2[j]]++;
			if(m1==m2) return true;
		}
		return false;
	}
};
