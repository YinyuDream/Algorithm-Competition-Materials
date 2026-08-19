class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n!=m)return false;
        else{
            for(int i=0;i<n;i++){
                if(s1[i]!=s2[n-i-1])
                    return false;
            }
            return true;
        }
    }
};