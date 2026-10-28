class Solution {
public:
    int findPermutationDifference(string s, string t) {

        int i = 0;
        int n = s.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < t.size(); i++) mp[t[i]] = i;
        
        int sum = 0;

        for(int i = 0; i < s.size(); i++){
            sum += abs(i - mp[s[i]]);
        }

        return sum;
        
    }
};