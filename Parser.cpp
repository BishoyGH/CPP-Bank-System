#include "Parser.h"
using namespace std;
#pragma once

vector<string> Parser::split(string line)
{
  stringstream stream(line);
  string slice;
  vector<string> lineData;
  while (getline(stream, slice, Validation::delimiter))
  {
    lineData.push_back(slice);
  }
  return lineData;
}
Client Parser::parseToClient(string line)
{
  vector<string> data = split(line);
  return Client(stoi(data[0]), data[1], data[2], data[3]);
}
Employee Parser::parseToEmployee(string line)
{
  vector<string> data = split(line);
  return Employee(stoi(data[0]), data[1], data[2], data[3]);
}
Admin Parser::parseToAdmin(string line)
{
  vector<string> data = split(line);
  return Admin(stoi(data[0]), data[1], data[2], data[3]);
}