#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include "Validation.cpp"
#include "Person.cpp"
#include "Client.cpp"
#include "Employee.cpp"
#include "Admin.cpp"
#include "DataSourceInterface.h"
#include "parser.cpp"
#include "FilesHelper.cpp"
#include "FileManager.cpp"
#include "Screens.cpp"
#include "ClientManger.cpp"
#include "EmployeeManager.cpp"
#include "AdminManager.cpp"

using namespace std;

int main()
{
  Screens::runApp();
  return 0;
}