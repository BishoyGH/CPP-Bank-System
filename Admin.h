#include "Employee.h"
using namespace std;
#pragma once

class Admin : public Employee
{
public:
  // Constructor
  Admin()
  {
  }
  Admin(string name, string password, string salary) : Employee(name, password, salary)
  {
  }
  Admin(int id, string name, string password, string salary) : Employee(id, name, password, salary)
  {
  }
  // Methods
  void addEmployee(Employee &employee);
  Employee *searchEmployee(int id);
  void editEmployee(int id, string name, string password, double salary);
  void listEmployee();
};