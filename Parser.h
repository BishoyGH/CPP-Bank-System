#pragma once

class Parser
{
private:
  static vector<string> split(string line);

public:
  static Client parseToClient(string line);
  static Employee parseToEmployee(string line);
  static Admin parseToAdmin(string line);
};