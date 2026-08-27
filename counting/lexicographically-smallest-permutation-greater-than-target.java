class Solution {
    private StringBuilder getRest(int f[]) {
        StringBuilder ans = new StringBuilder(); 
        for(int i = 0; i < 26; i++) {
            while(f[i] > 0) {
                ans.append((char)('a' + i)); 
                f[i]--; 
            }
        }
        return ans; 
    }
    public String lexGreaterPermutation(String s, String target) {

        int f[] = new int[26]; 
        for(int i= 0 ; i < s.length(); i++) f[s.charAt(i) - 'a']++; 
        int n = target.length(); 
        // let's find the longest prefix we can match using the characters 
        int pos = 0; 
        while(pos < n && f[target.charAt(pos)-'a'] > 0) {
            f[target.charAt(pos) - 'a']--; // reduce 
            pos++; // inc 
        }

        StringBuilder ans = new StringBuilder(); 

        // means till `pos` theprefix now matches. 
        // Now we have to move in back and just replace any character with next greater available , than we will add rest in ascending order 
        for(int i = pos; i >= 0; i--) {

            // return the current character back 
            if(i < pos && i < n) {
                f[target.charAt(i) - 'a']++; 
            }

            int pos_idx = i == n ?  -1 : target.charAt(i) - 'a'; 

            for(int k = pos_idx + 1; k < 26; k++) {
                if(f[k] > 0) {
                    // we found the first greater 
                    // append the prefix 
                    ans.append(target.substring(0, i)); 

                    // append the current 
                    ans.append((char)('a' + k)); 
                    f[k]--; 

                    // append the rest in ascending order 
                    ans.append(getRest(f)); 

                    return ans.toString(); 
                }
            }
            
        }

        return ""; // not found anything 
    }
}