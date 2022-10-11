#include "FileManager.h"
using namespace std;
#pragma once

/******************************************************
 * Insert New Data
 *****************************************************/

void FileManager::addClient(Client client)
{
  FilesHelper::saveClient(client);
}
void FileManager::addEmployee(Employee employee)
{
  FilesHelper::saveEmployee("Employee.txt", FilesHelper::lastEmployeeIdFile, employee);
}
void FileManager::addAdmin(Admin admin)
{
  FilesHelper::saveEmployee("Admin.txt", FilesHelper::lastEmployeeIdFile, admin);
}

/******************************************************
 * Get Data Collection
 *****************************************************/

map<int, Client> FileManager::getAllClients()
{
  string line;
  map<int, Client> clients;
  fstream file("Clients.txt", fstream::in);
  while (getline(file, line, '\n'))
  {
    Client client = Parser::parseToClient(line);
    clients.insert(pair<int, Client>(client.getId(), client));
  }
  return clients;
}
map<int, Employee> FileManager::getAllEmployees()
{
  string line;
  map<int, Employee> employees;
  fstream file("Employee.txt", fstream::in);
  while (getline(file, line, '\n'))
  {
    Employee employee = Parser::parseToEmployee(line);
    employees.insert(pair<int, Employee>(employee.getId(), employee));
  }
  return employees;
}
map<int, Admin> FileManager::getAllAdmins()
{
  string line;
  map<int, Admin> admins;
  fstream file("Admin.txt", fstream::in);
  while (getline(file, line, '\n'))
  {
    Admin admin = Parser::parseToAdmin(line);
    admins.insert(pair<int, Admin>(admin.getId(), admin));
  }
  return admins;
}

/******************************************************
 * System Reset
 *****************************************************/

void FileManager::removeAllClients()
{
  FilesHelper::clearFile("Clients.txt", FilesHelper::lastClientIdFile);
  FilesHelper::saveLast(FilesHelper::lastClientIdFile, 1);
}
void FileManager::removeAllEmployees()
{
  FilesHelper::clearFile("Employee.txt", FilesHelper::lastEmployeeIdFile);
  FilesHelper::saveLast(FilesHelper::lastEmployeeIdFile, 1);
}
void FileManager::removeAllAdmins()
{
  FilesHelper::clearFile("Admin.txt", FilesHelper::lastEmployeeIdFile);
  FilesHelper::saveLast(FilesHelper::lastEmployeeIdFile, 1);
}