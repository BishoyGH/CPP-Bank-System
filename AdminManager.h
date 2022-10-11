using namespace std;
#pragma once

class AdminManager
{
public:
  static void chooseToBack(Admin *admin);
  static void goBackToAdminMenu(Admin *admin);
  static void rewriteAdmins(Admin *admin);

  static void printAdminMenu();
  static Admin *login(int id, string password);
  static void AdminOptions(Admin *admin);
};