class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int idx = 0; // Write pointer: where the next character should go
        
        // Step 2: Process each word, clean up spaces, and reverse the word back
        for (int start = 0; start < n; ++start) {
            // Skip spaces
            if (s[start] != ' ') {
                // If we are not at the very beginning, add a single space separator
                if (idx != 0) {
                    s[idx] = ' ';
                    idx++;
                }
                
                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[idx] = s[end]; // Copy character to the clean section
                    idx++;
                    end++;
                }
                
                // Reverse the word we just copied to put its letters in the correct order
                // The word starts at (idx - word_length) and ends at (idx - 1)
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                
                // Skip the rest of the word in the outer loop
                start = end; 
            }
        }
        
        // Step 3: Resize the string to remove the leftover characters at the end
        s.resize(idx);
        return s;
    }
};