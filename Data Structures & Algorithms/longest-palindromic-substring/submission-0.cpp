class Solution {
public:
    string longestPalindrome(string s) {
        int ansIdx= 0,ansLen = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            int l = i, r = i;
            while(l>=0 && r <n && s[l] == s[r]){
                if(r-l+1 > ansLen) {
                    ansLen = r-l+1;
                    ansIdx = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i +1;

            while(l>=0 && r <n && s[l] == s[r]){
                if(r-l+1 > ansLen) {
                    ansLen = r-l+1;
                    ansIdx = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(ansIdx, ansLen);
    }
};
