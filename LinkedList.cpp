#include "Node.h"
#include <iostream>
using namespace std;

class EmployeeList {
    Employee *head;

  public:
    EmployeeList(string name, string id, double salary) {
        Employee *newEmployee = new Employee(name, id, salary);
        head = newEmployee;
    }

    void insertToStart(Employee *newEmp) {
        Employee *temp = head->next;
        head->next = newEmp;
        newEmp->next = temp;
    }

    void insertToEnd(Employee *newEmp) {
        Employee *lastElement = getLastElement();
        lastElement->next = newEmp;
    }

    void display() {
        Employee *temp = head;
        while (temp) {
            cout << temp->EmpName << " -> ";
            temp = temp->next;
        }
    }

    void reverse() {
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

  private:
    Employee *getLastElement() {
        Employee *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        return temp;
    }
};

int main() {
    EmployeeList list = EmployeeList("youssef", "EMP123", 1200);

    list.display();
    cout << endl;
    list.insertToStart(new Employee("jack", "EMP3434", 120));
    list.display();
    cout << endl;
    list.insertToEnd(new Employee("jill", "EMP3434", 120));
    list.display();
    cout << endl;
    list.reverse();
    list.display();
    return 0;
}
