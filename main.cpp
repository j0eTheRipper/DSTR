#include "LinkedList/LinkedList.h"
#include <iostream>
using namespace std;

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
