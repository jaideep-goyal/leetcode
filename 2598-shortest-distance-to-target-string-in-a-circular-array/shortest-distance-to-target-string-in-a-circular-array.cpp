class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size() ;

        vector<string> temp ;
        for(int i = 0 ; i < words.size() ; i++)
        {
            temp.push_back(words[i]) ;
        }
        for(int i = 0 ; i < words.size() ; i++)
        {
            temp.push_back(words[i]) ;
        }
        

        int ans = INT_MAX ;
        for(int i = startIndex ; i < startIndex + n ; i++)
        {
            if(temp[i] == target) {
                ans = min(ans , abs(i - startIndex)) ;
                break ;
            }
        }
        for(int i = startIndex + n ; i >= startIndex; i--) 
        {
            if(temp[i] == target) {
                ans = min(ans , abs(i - (startIndex + n)) );  
                break ;
            }
        }

        if(ans == INT_MAX) return -1 ;

        return ans ;

        
    }
};