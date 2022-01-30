#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> randomSet;
    vector<int> values;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (randomSet.find(val) != randomSet.end()) return false;
        values.push_back(val);
        randomSet[val] = values.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (randomSet.find(val) == randomSet.end()) return false;
        
        int last = values.back();
        randomSet[last] = randomSet[val];
        values[randomSet[val]] = last;
        values.pop_back();
        randomSet.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIdx = rand() % values.size();
        return values[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	// Add driver code
	
	return 0;
}
