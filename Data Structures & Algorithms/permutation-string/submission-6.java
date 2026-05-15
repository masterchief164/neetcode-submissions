class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] freq1 = new int[26], freq2 = new int[26];

        int l = s1.length(), n = s2.length();
        if(l>n) return false;
        
        int have = 0;
        for(int i =0;i<l;i++) {
            freq1[s1.charAt(i)- 'a']++;
            freq2[s2.charAt(i)- 'a']++;
            if(s1.charAt(i) == s2.charAt(i)) 
                have++;
        }
        
        if(Arrays.equals(freq1, freq2)){
            return true;
        }

        for(int i = l;i<n;i++){
            freq2[s2.charAt(i)-'a']++;
            freq2[s2.charAt(i-l)-'a']--;

            if(Arrays.equals(freq1, freq2)){
                return true;
            }
        }
        return false;
    }
}
