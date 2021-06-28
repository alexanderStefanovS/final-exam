
#include <iostream>
#include <vector>


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};


Employee* findBoss(std::vector<Employee*> employees, int id) {
    
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i]->id = id) {
            return employees[i];
        }
    }

    return nullptr;
}

class Solution {
public:
    int getImportance(std::vector<Employee*> employees, int id) {

        Employee* boss = findBoss(employees, id);

        int sum = 0;

        for (int i = 0; i < boss->subordinates.size(); i++) {
            sum += getImportance(employees, boss->subordinates[0]);
        }

        return sum + boss->importance;
    }
};

//int main() {
//
//
//	return 0;
//}
