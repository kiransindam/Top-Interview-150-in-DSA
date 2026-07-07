class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Step 1: Sort the array in ascending order
        sort(citations.begin(), citations.end());
        int n = citations.size();
        
        // Step 2: Find the first index where the condition is met
        for (int i = 0; i < n; i++) {
            // Number of papers from index i to the end is (n - i)
            // If the current paper has at least (n - i) citations, 
            // then (n - i) is our h-index!
            if (citations[i] >= n - i) {
                return n - i;
            }
        }
        
        // If no paper has enough citations, the h-index is 0
        return 0;
    }
};