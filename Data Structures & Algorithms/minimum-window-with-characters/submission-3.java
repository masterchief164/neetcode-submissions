class Solution {
    public String minWindow(String s, String t) {
        if(t == "") {
            return "";
        }
        Map<Character, Integer> countT = new HashMap<>();
        Map<Character, Integer> window = new HashMap<>();

        for(char c: t.toCharArray()) {
            countT.put(c, countT.getOrDefault(c, 0) +1);
        }

        int have = 0, need = countT.size();

        int l = 0, r = 0;
        int maxi = Integer.MAX_VALUE;
        int []res = {-1,-1};

        while(r < s.length()) {
            char curr = s.charAt(r);
            window.put(curr, window.getOrDefault(curr, 0)+1);

            if(countT.containsKey(curr) && window.get(curr).equals(countT.get(curr))) {
                have ++;
            }

            while(have==need) {
                if(r-l+1 < maxi) {
                    maxi = r-l+1;
                    res[0] = l;
                    res[1] = r;
                }
                char left = s.charAt(l);
                window.put(left, window.get(left)-1);
                if(countT.containsKey(left) && countT.get(left) > window.get(left)) {
                    have--;
                }
                l++;
            }
            r++;
        }
        return maxi == Integer.MAX_VALUE ? "": s.substring(res[0], res[1]+1);
    }
}
