/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void addImportance(unordered_map<int, Employee*> imp, int id, int &sum) {
        sum += imp[id] -> importance;
        for (auto i : imp[id] -> subordinates) {
            addImportance(imp, i, sum);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> imp;
        
        for (auto e : employees)
            imp[e -> id] = e;
        
        int sum = 0;
        addImportance(imp, id, sum);
        return sum;
    }
};
