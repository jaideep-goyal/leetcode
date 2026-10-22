class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();
        for(int i = 0 ; i < n - 1; i++){
            int c = s[i] - '0';
            int p = s[i + 1] - '0';
            if(c % 2 == 0 && p % 2 == 0){
                if(c > p){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
            else if(c % 2 != 0 && p % 2 != 0){
                if(c > p){
                    swap(s[i],s[i+1]);
                    break;
                }
            }
        }
        return s;
    }
};