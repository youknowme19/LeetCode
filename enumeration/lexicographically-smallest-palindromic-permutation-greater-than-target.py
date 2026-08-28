class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        half = n // 2
        freq = [0] * 26
        hasC = 0
        par = 0
        for ch in s:
            idx = ord(ch) - 97
            freq[idx] += 1
            hasC |= (1 << idx)
            par ^= (1 << idx)

        if bin(par).count('1') > 1:
            return ""

        odd_idx = -1
        if n & 1:
            odd_idx = (par & -par).bit_length() - 1  # countr_zero

        mask = hasC
        while mask:
            i = (mask & -mask).bit_length() - 1
            freq[i] //= 2
            if freq[i] == 0:
                hasC &= ~(1 << i)
            mask &= mask - 1

        dp = {}

        def rev_left_is_gr_r(t: str) -> bool:
            for i in range(half):
                if t[half - 1 - i] > t[half + (n & 1) + i]:
                    return True
                if t[half - 1 - i] < t[half + (n & 1) + i]:
                    return False
            return False

        def can_place(i: int, hc: int) -> bool:
            if i in dp:
                return dp[i]
            c = ord(target[i]) - 97
            if freq[c] == 0:
                dp[i] = False
                return False

            freq[c] -= 1
            hc1 = hc
            if freq[c] == 0:
                hc1 &= ~(1 << c)

            ans = False
            if i == half - 1:
                if n & 1:
                    mid = ord(target[half]) - 97
                    if odd_idx != mid:
                        ans = odd_idx > mid
                    else:
                        ans = rev_left_is_gr_r(target)
                else:
                    ans = rev_left_is_gr_r(target)
            else:
                nxt = ord(target[i + 1]) - 97
                if hc1 >> (nxt + 1):
                    ans = True
                elif not ((hc1 >> nxt) & 1):
                    ans = False
                else:
                    ans = can_place(i + 1, hc1)

            freq[c] += 1
            dp[i] = ans
            return ans

        def build_palindrome(built: str) -> str:
            pal = built
            if n & 1:
                pal += chr(97 + odd_idx)
            pal += built[::-1]
            return pal

        ans_chars = []
        for i in range(half):
            t_i = ord(target[i]) - 97
            if freq[t_i] > 0 and can_place(i, hasC):
                ans_chars.append(target[i])
                freq[t_i] -= 1
                if freq[t_i] == 0:
                    hasC &= ~(1 << t_i)
            else:
                higher = hasC >> (t_i + 1)
                if higher == 0:
                    return ""
                choice = (higher & -higher).bit_length() - 1 + t_i + 1
                freq[choice] -= 1
                if freq[choice] == 0:
                    hasC &= ~(1 << choice)
                ans_chars.append(chr(97 + choice))

                for _ in range(i + 1, half):
                    idx = (hasC & -hasC).bit_length() - 1
                    ans_chars.append(chr(97 + idx))
                    freq[idx] -= 1
                    if freq[idx] == 0:
                        hasC &= ~(1 << idx)
                return build_palindrome(''.join(ans_chars))

        pal = build_palindrome(''.join(ans_chars))
        return pal if pal > target else ""