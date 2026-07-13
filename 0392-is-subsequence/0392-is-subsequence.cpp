class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for the subsequence (s)
        int j = 0; // Pointer for the main string (t)
        
        // Traverse both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, we found our checkpoint! Move to the next one in s.
            if (s[i] == t[j]) {
                i++;
            }
            // Always move forward in t, regardless of whether there was a match
            j++;
        }
        
        // If we successfully matched all characters in s, i will equal s.length()
        return i == s.length();
    }
};