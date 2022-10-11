#include <iostream>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

#pragma once

Client *createClient()
{
  string name, password, balance;

  cout << "Client Name: ";
  getline(cin, name, '\n');

  cout << "Client Password: ";
  getline(cin, password, '\n');

  cout << "Client Initial Balance: ";
  getline(cin, balance, '\n');

  return new Client(name, password, balance);
}
Employee *createEmployee()
{
  string name, password, salary;

  cout << "Employee Name: ";
  getline(cin, name, '\n');
  cout << "Employee Password: ";
  getline(cin, password, '\n');
  cout << "Employee Initial Salary: ";
  getline(cin, salary, '\n');

  return new Employee(name, password, salary);
}
Admin *createAdmin()
{
  string name, password, salary;

  cout << "Admin Name: ";
  getline(cin, name, '\n');
  cout << "Admin Password: ";
  getline(cin, password, '\n');
  cout << "Admin Initial Salary: ";
  getline(cin, salary, '\n');

  return new Admin(name, password, salary);
}