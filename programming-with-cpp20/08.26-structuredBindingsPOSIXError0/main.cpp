// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cerrno>
#include <cstdio>
#include <string_view>

int open(const char*)
{
  return 1;
}

struct ReturnCode {
  int returnCode;
  int err;
};

auto Open(std::string_view fileName)
{
  return ReturnCode{open(fileName.data()), errno};
}

int main()
{
  auto [code, err] = Open("myfile.txt");

  printf("errno: %d, value: %d\n", err, code);
}