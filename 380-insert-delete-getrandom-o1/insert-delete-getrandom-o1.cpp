class RandomizedSet {
public:
        vector<int> nums;
        unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val)) {
        return false;
        }
        mp[val] = nums.size();
        nums.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)){
            return false;
        }
        int index = mp[val];
        int last = nums.back();
        nums[index] = last;
        nums.pop_back();

        mp[last] = index;
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */