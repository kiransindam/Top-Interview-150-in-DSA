class RandomizedSet {
private:
    vector<int> nums;                  // Stores the actual values
    unordered_map<int, int> valToIndex; // Maps value -> index in the nums array

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // If it already exists, we can't insert it again
        if (valToIndex.count(val)) {
            return false;
        }
        
        // Add to the end of the array and record its index in the map
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        // If it doesn't exist, we can't remove it
        if (!valToIndex.count(val)) {
            return false;
        }
        
        int indexToRemove = valToIndex[val];
        int lastVal = nums.back();
        
        // 1. Overwrite the element to remove with the last element
        nums[indexToRemove] = lastVal;
        
        // 2. Update the map with the new index of the last element
        valToIndex[lastVal] = indexToRemove;
        
        // 3. Pop the last element from the array and erase the removed value from the map
        nums.pop_back();
        valToIndex.erase(val);
        
        return true;
    }
    
    int getRandom() {
        // Pick a random index between 0 and size - 1
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};