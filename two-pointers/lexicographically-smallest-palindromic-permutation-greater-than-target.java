class Solution {
    int[] freq = new int[26];
    int n, half, oddIdx = -1;
    Integer[] dp;
    String target;

    private boolean revLeftIsGrR(String t) {
        for (int i = 0; i < half; i++) {
            if (t.charAt(half - 1 - i) > t.charAt(half + (n & 1) + i)) return true;
            if (t.charAt(half - 1 - i) < t.charAt(half + (n & 1) + i)) return false;
        }
        return false;
    }

    private boolean canPlace(int i, int hasC) {
        if (dp[i] != null) return dp[i];
        int c = target.charAt(i) - 'a';
        if (freq[c] == 0) return dp[i] = false;

        freq[c]--;
        int hasC1 = hasC;
        if (freq[c] == 0) hasC1 &= ~(1 << c);

        boolean ans;
        if (i == half - 1) {
            if ((n & 1) == 1) {
                int mid = target.charAt(half) - 'a';
                if (oddIdx != mid) ans = oddIdx > mid;
                else ans = revLeftIsGrR(target);
            } else {
                ans = revLeftIsGrR(target);
            }
        } else {
            int nxt = target.charAt(i + 1) - 'a';
            if ((hasC1 >>> (nxt + 1)) != 0) ans = true;
            else if (((hasC1 >>> nxt) & 1) == 0) ans = false;
            else ans = canPlace(i + 1, hasC1);
        }

        freq[c]++;
        return dp[i] = ans;
    }

    private String buildPalindrome(String built) {
        StringBuilder pal = new StringBuilder(built);
        if ((n & 1) == 1) pal.append((char) ('a' + oddIdx));
        pal.append(new StringBuilder(built).reverse());
        return pal.toString();
    }

    public String lexPalindromicPermutation(String s, String target) {
        this.target = target;
        n = s.length();
        half = n >> 1;
        dp = new Integer[half][];
        dp = new Integer[half];
        int hasC = 0, par = 0;
        for (char ch : s.toCharArray()) {
            int idx = ch - 'a';
            freq[idx]++;
            hasC |= (1 << idx);
            par ^= (1 << idx);
        }
        if (Integer.bitCount(par) > 1) return "";

        if ((n & 1) == 1) oddIdx = Integer.numberOfTrailingZeros(par);

        for (int mask = hasC; mask != 0; mask &= (mask - 1)) {
            int i = Integer.numberOfTrailingZeros(mask);
            freq[i] >>= 1;
            if (freq[i] == 0) hasC &= ~(1 << i);
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < half; i++) {
            int t_i = target.charAt(i) - 'a';
            if (freq[t_i] > 0 && canPlace(i, hasC)) {
                ans.append(target.charAt(i));
                freq[t_i]--;
                if (freq[t_i] == 0) hasC &= ~(1 << t_i);
            } else {
                int higher = hasC >>> (t_i + 1);
                if (higher == 0) return "";
                int choice = Integer.numberOfTrailingZeros(higher) + t_i + 1;
                freq[choice]--;
                if (freq[choice] == 0) hasC &= ~(1 << choice);
                ans.append((char) ('a' + choice));

                for (int j = i + 1; j < half; j++) {
                    int idx = Integer.numberOfTrailingZeros(hasC);
                    ans.append((char) ('a' + idx));
                    freq[idx]--;
                    if (freq[idx] == 0) hasC &= ~(1 << idx);
                }
                return buildPalindrome(ans.toString());
            }
        }

        String pal = buildPalindrome(ans.toString());
        return pal.compareTo(target) > 0 ? pal : "";
    }
}