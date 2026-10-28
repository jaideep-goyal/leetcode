class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        int j = min({s1.size(), s2.size(), s3.size()});

        while(i < j) {
            if(s1[i] == s2[i] && s2[i] == s3[i]){
                i++;
            }
            else{
                break;
            }
        }

        if(i == 0) return -1;
        
        return s1.size() + s2.size() + s3.size() - 3 * i;    
    }
};