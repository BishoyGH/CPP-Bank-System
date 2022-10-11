using namespace std;
#pragma once

class ClientManger
{

public:
  static void goBackToClientMenu(Client *client);
  static void rewriteClients(Client *client);
  static void printClientMenu();
  static void updatePassword(Person *person);
  static Client *login(int id, string password);
  static void clientOptions(Client *client);
};