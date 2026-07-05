class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // If the array has 2 or fewer elements, it's already valid
        if (n <= 2) return n; 
        
        int write = 2; // Start writing from the 3rd position
        
        for (int read = 2; read < n; read++) {
            // If the current element is different from the one 2 steps behind the write pointer
            if (nums[read] != nums[write - 2]) {
                nums[write] = nums[read];
                write++;
            }
        }
        
        return write;
    }
};