class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1 ;
        stringstream ss(preorder) ;
        string s ;

        while(getline(ss,s,',')) {
            if(slots == 0) return false ;

            slots-- ;
            if(s != "#") slots += 2 ;

        }
        return slots == 0 ;
        
    }
};