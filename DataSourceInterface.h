#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
#pragma once

class DataSourceInterface
{
public:
  virtual void addClient(Client) = 0;
  virtual void addEmployee(Employee) = 0;
  virtual void addAdmin(Admin) = 0;
  virtual map<int, Client> getAllClients() = 0;
  virtual map<int, Employee> getAllEmployees() = 0;
  virtual map<int, Admin> getAllAdmins() = 0;
  virtual void removeAllClients() = 0;
  virtual void removeAllEmployees() = 0;
  virtual void removeAllAdmins() = 0;
};