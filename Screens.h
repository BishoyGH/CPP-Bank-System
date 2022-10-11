#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
using namespace std;
#pragma once

class Screens
{
public:
  static void bankname();
  static void welcome();
  static void loginOptions();
  static int loginAs();
  static void invalid(int c);
  static void logout();
  static void loginScreen(int c);
  static void runApp();
  static void clearScreen();
};