#include "Admin.h"
#pragma once

// Add New Employee

void Admin::addEmployee(Employee &employee)
{
  FileManager fm;
  fm.addEmployee(employee);
}

Employee *Admin::searchEmployee(int id)
{
  FileManager fm;
  map<int, Employee> employees = fm.getAllEmployees();
  Employee employee = employees[id];
  if (employee.getName() == "EMPTY ACCOUNT")
  {
    cout << "Employee Not Found!" << endl;
    return new Employee(0, employee.getName(), employee.getPassword(), to_string(0));
  }
  // We Can't Return Employee Because It's a Local Variable;
  return new Employee(employee.getId(), employee.getName(), employee.getPassword(), to_string(employee.getSalary()));
}

// List All Employees

void Admin::listEmployee()
{
  FilesHelper::getEmployees();
}

// Edit Employee Data

void Admin::editEmployee(int id, string name, string password, double salary)
{
  Employee *e = searchEmployee(id);
  if (e->getName() == "EMPTY ACCOUNT")
  {
    // If The Employee Account Not Fount Exit
    return;
  }
  FileManager fm;
  map<int, Employee> employees = fm.getAllEmployees();
  // Delete Old Employee Data
  employees.erase(id);
  // Create New Employee After Deleting Old One
  // Because Employee Class Has No setter for salary
  e = new Employee(id,
                   Validation::validateName(name),
                   Validation::validatePassword(password),
                   to_string(Validation::validateAmount(to_string(salary), Validation::minEmployeeSalary, "Salary")));
  // Insert New Employee Data
  employees.insert(pair<int, Employee>(id, *e));
  // Remove Data On File
  fm.removeAllEmployees();
  // Write New Data On File
  for (auto employee : employees)
  {
    fm.addEmployee(employee.second);
  }
}
