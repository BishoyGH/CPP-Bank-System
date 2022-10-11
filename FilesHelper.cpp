#include "FilesHelper.h"
#include "FileManager.h"
using namespace std;
#pragma once

string FilesHelper::lastClientIdFile = "lastClientId.txt";
string FilesHelper::lastEmployeeIdFile = "lastEmployeeId.txt";

/***********************************************
 * Last Id Methods
 ***********************************************/

void FilesHelper::saveLast(string fileName, int newId)
{
  fstream file(fileName, fstream::out);
  file << newId;
  file.close();
}

int FilesHelper::getLast(string fileName)
{
  string id;
  fstream file(fileName);
  getline(file, id, '\n');
  file.close();
  return stoi(id);
}

/***********************************************
 * Saving To Files Methods
 ***********************************************/

void FilesHelper::saveClient(Client c)
{
  fstream file("Clients.txt", fstream::app);
  file << c.getId() << Validation::delimiter
       << c.getName() << Validation::delimiter
       << c.getPassword() << Validation::delimiter
       << c.getBalance() << endl;
  file.close();
  saveLast(lastClientIdFile, (c.getId() + 1));
}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e)
{
  fstream file(fileName, fstream::app);
  file << e.getId() << Validation::delimiter
       << e.getName() << Validation::delimiter
       << e.getPassword() << Validation::delimiter
       << e.getSalary() << endl;
  file.close();
  saveLast(lastIdFile, (e.getId() + 1));
}

/***********************************************
 * Retrieve From Files Methods
 ***********************************************/

void FilesHelper::getClients()
{
  FileManager fm;
  auto clients = fm.getAllClients();

  for (auto client : clients)
  {
    cout << client.second.getId() << ") " << client.second.getName() << endl;
  }

  cout << "Number Of Clients is " << clients.size() << endl;
}
void FilesHelper::getEmployees()
{
  FileManager fm;
  auto employees = fm.getAllEmployees();

  for (auto employee : employees)
  {
    cout << employee.second.getId() << "]" << employee.second.getName() << endl;
  }

  cout << "Number Of Employees is " << employees.size() << endl;
}
void FilesHelper::getAdmins()
{
  FileManager fm;
  auto admins = fm.getAllAdmins();

  for (auto admin : admins)
  {
    cout << admin.second.getId() << "]" << admin.second.getName() << endl;
  }

  cout << "Number Of Admins is " << admins.size() << endl;
}

/***********************************************
 * Clear Last Id File - Reset Id
 ***********************************************/

void FilesHelper::clearFile(string fileName, string lastIdFile)
{
  fstream file(fileName, fstream::out);
  file.close();
  saveLast(lastIdFile, 1);
}
