using namespace std;
#pragma once

class EmployeeManager
{
public:
  static void chooseToBack(Employee *employee);
  static void goBackToEmployeeMenu(Employee *employee);
  static void rewriteEmployees(Employee *employee);
  static void printEmployeeMenu();
  static void newClient(Employee *employee);
  static void listAllClients(Employee *employee);
  static void searchForClient(Employee *employee);
  static void editClientInfo(Employee *employee);
  static Employee *login(int id, string password);
  static void employeeOptions(Employee *employee);
};