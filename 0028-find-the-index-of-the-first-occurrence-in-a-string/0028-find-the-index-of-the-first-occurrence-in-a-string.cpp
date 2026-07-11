class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.length();
        int n = needle.length();
        
        // If the needle is longer than the haystack, it's impossible to find
        if (n > h) return -1;
        
        // We only need to check starting positions up to h - n
        for (int i = 0; i <= h - n; i++) {
            bool match = true;
            
            // Check if the substring starting at i matches the needle
            for (int j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break; // Mismatch found, stop checking this window
                }
            }
            
            // If we finished the inner loop without breaking, we found a match!
            if (match) {
                return i;
            }
        }
        
        return -1; // No match found after checking all possible windows
    }
};