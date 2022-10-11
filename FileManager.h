#include "DataSourceInterface.h"
using namespace std;
#pragma once

class FileManager : public DataSourceInterface
{
public:
  // Add New Person To File

  void addClient(Client client);
  void addEmployee(Employee employee);
  void addAdmin(Admin admin);

  // Get All

  map<int, Client> getAllClients();
  map<int, Employee> getAllEmployees();
  map<int, Admin> getAllAdmins();

  // Remove All

  void removeAllClients();
  void removeAllEmployees();
  void removeAllAdmins();
};