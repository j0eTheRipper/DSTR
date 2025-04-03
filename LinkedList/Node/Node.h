#ifndef __NODE_H_INCLUDED__
#define __NODE_H_INCLUDED__

#include <string>

struct Employee {
    std::string EmpName;
    std::string EmpId;
    double EmpSalary;
    Employee *next;

    Employee(std::string name, std::string id, double salary);
};

#endif // !
