// "Copyright 4/4/2022 Jacob George"
#pragma once
#ifndef EDISTANCE_H
#define EDISTANCE_H

#include <string>
#include <vector>
#include <algorithm>

class EDistance {
 public:
    EDistance(std::string aStr, std::string bStr);
    static int penalty(char a, char b);
    static int min(int a, int b, int c);
    int optDistance(void);
    std::string alignment(void);

 private:
    std::string a, b;
    int i, j;
    std::vector<std::vector<int>> opt;
};

#endif
