class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0; // Points to where the next valid element should go
        
        for (int read = 0; read < nums.size(); read++) {
            if (nums[read] != val) {
                nums[write] = nums[read];
                write++;
            }
        }
        
        return write; // 'write' is exactly the count of valid elements
    }
};