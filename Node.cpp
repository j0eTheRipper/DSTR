#include "Node.h"

Employee::Employee(std::string name, std::string id, double salary) {
    this->EmpName = name;
    this->EmpId = id;
    this->EmpSalary = salary;
    this->next = nullptr;
}
