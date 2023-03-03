class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty()) {
            return -1;
        }
        int n = haystack.length();
        int m = needle.length();
        vector<int> lps(m, 0);
        int j = 0;
        computeLPS(needle, lps);
        for (int i = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = lps[j-1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
    
    void computeLPS(string pattern, vector<int>& lps) {
        int m = pattern.length();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0) {
                    len = lps[len-1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};
