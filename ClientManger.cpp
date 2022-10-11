#include "ClientManger.h"
using namespace std;
#pragma once

// Redirect Client To Client Menu in 3 Seconds
void ClientManger::goBackToClientMenu(Client *client)
{
  cout << "\nRedirected In 3 Seconds" << endl;
  Sleep(3000);
  clientOptions(client);
}

// Delete Everything In Client.txt And Rewrite Everything
void ClientManger::rewriteClients(Client *client)
{
  FileManager fm;
  map<int, Client> clients = fm.getAllClients();
  // Delete Old Client Data
  clients.erase(client->getId());
  // Insert New Client Data
  clients.insert(pair<int, Client>(client->getId(), *client));
  // Remove Data On File
  fm.removeAllClients();
  // Write New Data On File
  for (auto c : clients)
  {
    fm.addClient(c.second);
  }
}

// List Of Client Options
void ClientManger::printClientMenu()
{
  cout << "\t[01] Deposit" << endl;
  cout << "\t[02] Withdraw" << endl;
  cout << "\t[03] Transfer Money" << endl;
  cout << "\t[04] Check Balance" << endl;
  cout << "\t[05] Display All Info" << endl;
  cout << "\t[06] Update Name" << endl;
  cout << "\t[07] Update Password" << endl;
  cout << "\t[08] Go Back" << endl;
  cout << "\t[09] Exit" << endl;
}

// Client Login
Client *ClientManger::login(int id, string password)
{
  FileManager fm;
  auto clients = fm.getAllClients();
  try
  {
    if (clients[id].getPassword() != password)
      throw exception();
  }
  catch (exception &e)
  {
    cout << "Wrong Data Entered. Please Try Again." << endl;
    Screens::loginScreen(1);
  }
  return new Client(clients[id].getId(), clients[id].getName(), clients[id].getPassword(), to_string(clients[id].getBalance()));
}

// Every Client Choice Logic
void ClientManger::clientOptions(Client *client)
{
  Screens::clearScreen();
  cout << "Welcome " << client->getName() << endl;
  cout << "Please Choose a Number: " << endl;
  printClientMenu();
  int choice;
  cout << "Your Choice: ";
  cin >> choice;
  switch (choice)
  {
  // Deposit
  case 1:
  {
    int amount;
    cout << "Amount To Deposit: ";
    cin >> amount;
    client->deposit(amount);
    cout << "You Balance Now Is: " << client->getBalance() << endl;
    rewriteClients(client);
    goBackToClientMenu(client);
    break;
  }
  // Withdraw
  case 2:
  {
    int amount;
    cout << "Amount To Withdraw: ";
    cin >> amount;
    client->withdraw(amount);
    cout << "You Balance Now Is: " << client->getBalance() << endl;
    rewriteClients(client);
    goBackToClientMenu(client);
    break;
  }
  // Transfer To
  case 3:
  {
    FileManager fm;
    auto clients = fm.getAllClients();
    int amount;
    cout << "Amount To Transfer: ";
    cin >> amount;
    while (true)
    {
      int id;
      cout << "Client ID: ";
      cin >> id;
      Client *targetClient = &clients[id];
      if (targetClient->getName() != "DEFAULT NAME")
      {
        client->transferTo(amount, *targetClient);

        cout << "Your Balance Now Is: " << client->getBalance() << endl;

        clients.erase(client->getId());

        fm.removeAllClients();

        clients.insert(pair<int, Client>(client->getId(), *client));
        clients.insert(pair<int, Client>(client->getId(), *targetClient));

        for (auto c : clients)
        {
          fm.addClient(c.second);
        }
        break;
      }
    }
    goBackToClientMenu(client);
    break;
  }
  // Check Balance
  case 4:
  {
    client->checkBalance();
    goBackToClientMenu(client);
  }
  // Display All Info
  case 5:
  {
    Screens::clearScreen();
    client->display();
    cout << "\nChoose an Option" << endl;
    cout << "\t[0] Go Back." << endl;
    int c;
    while (true)
    {
      cout << "Your Choice: ";
      cin >> c;
      if (c == 0)
      {
        goBackToClientMenu(client);
      }
      break;
    }
    break;
  }
  // Update Name
  case 6:
  {
    string name;
    cout << "Enter New Name: ";
    getline(cin, name, '\n');
    client->setName(Validation::validateName(name));
    cout << "Your Name Now Is: " << client->getName() << endl;
    rewriteClients(client);
    goBackToClientMenu(client);
    break;
  }
  // Update Password
  case 7:
  {
    string password;
    cout << "Enter New Password: ";
    getline(cin, password, '\n');
    password = Validation::validatePassword(password);
    client->setPassword(password);
    cout << "Your Password Has Been Updated." << endl;
    rewriteClients(client);
    goBackToClientMenu(client);
    break;
  }
  //  Go Back
  case 8:
  {
    Screens::clearScreen();
    cout << "You Logged Out. Redirected In 3 Seconds";
    Sleep(3000);
    Screens::loginScreen(Screens::loginAs());
    break;
  }
  // Exit
  case 9:
  {
    Screens::logout();
    break;
  }
  default:
  {
    cout << choice << " is Invalid Input.";
  }
  };
}
