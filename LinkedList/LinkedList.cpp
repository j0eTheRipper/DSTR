#include "LinkedList.h"
#include <iostream>
using namespace std;

Employee *head;

EmployeeList::EmployeeList(string name, string id, double salary) {
    Employee *newEmployee = new Employee(name, id, salary);
    head = newEmployee;
}

void EmployeeList::insertToStart(Employee *newEmp) {
    Employee *temp = head->next;
    head->next = newEmp;
    newEmp->next = temp;
}

void EmployeeList::insertToEnd(Employee *newEmp) {
    Employee *lastElement = getLastElement();
    lastElement->next = newEmp;
}

void EmployeeList::display() {
    Employee *temp = head;
    while (temp) {
        cout << temp->EmpName << " -> ";
        temp = temp->next;
    }
}

void EmployeeList::reverse() {
    Employee *curr = head;
    Employee *prev = nullptr;

    while (curr) {
        Employee *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Employee *EmployeeList::getLastElement() {
    Employee *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    return temp;
}
