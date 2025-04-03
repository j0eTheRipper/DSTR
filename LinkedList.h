#ifndef __LinkedList_H_INCLUDED__
#define __LinkedList_H_INCLUDED__

#include "Node.h"
#include <iostream>

class EmployeeList {
  public:
    EmployeeList(std::string name, std::string id, double salary);
    void insertToStart(Employee *newEmp);
    void insertToEnd(Employee *newEmp);
    void display();
    void reverse();

  private:
    Employee *head;
    Employee *getLastElement();
};

#endif
