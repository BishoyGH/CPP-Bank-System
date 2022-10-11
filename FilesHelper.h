#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
#pragma once

class FilesHelper
{
public:
  static string lastClientIdFile;
  static string lastEmployeeIdFile;

  static void saveLast(string fileName, int newId);
  static int getLast(string fileName);
  static void saveClient(Client c);
  static void saveEmployee(string fileName, string lastIdFile, Employee e);

  static void getClients();
  static void getEmployees();
  static void getAdmins();

  static void clearFile(string fileName, string lastIdFile);
};