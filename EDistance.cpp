// "Copyright 4/4/2022 Jacob George"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "EDistance.h"

EDistance::EDistance(std::string aStr, std::string bStr) {
    a = aStr;
    b = bStr;
    for (size_t i = 0; i <= a.length()+1; i++) {
        std::vector<int> tempVector;
        for (size_t j = 0; j <= b.length()+1; j++) {
            tempVector.push_back(0);
        }
        opt.push_back(tempVector);
    }
    for (auto &i : opt) {
        std::fill(i.begin(), i.end(), 0);
    }
}

int EDistance::min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else if (c <= a && c <= b)
        return c;
    else
        return -1;
}

int EDistance::penalty(char a, char b) {
    if (a == b)
        return 0;
    else if (a != b)
        return 1;
    return -1;
}


int EDistance::optDistance(void) {
    this->i = a.length();
    this->j = b.length();
    int it = 0;
    int it2 = 0;
    while (it <= j) {
        opt.at(i).at(it) = (2 * (j - it));
        ++it;
    }
    while (it2 <= i) {
        opt.at(it2).at(j) = (2 * (i - it2));
        ++it2;
    }
    this->i = a.length();
    this->j = b.length();

    for (int h = i - 1; h >= 0; --h) {
        for (int e = j - 1; e >= 0; --e) {
opt[h][e] = this->min(opt[h+1][e+1] + this->penalty(this->a[h], this->b[e]), opt[h+1][e] + 2, opt[h][e+1] + 2);
        }
    }
    this->i = 0;
    this->j = 0;
    return opt.at(i).at(j);
}

std::string EDistance::alignment(void) {
    std::stringstream os;
    while (i < a.length() && j < b.length()) {
        if (opt[i][j] == opt[i+1][j+1] && this->a[i] == this->b[j]) {
            os << this->a[i] << " " << this->b[j] << " 0" << "\n";
            ++j;
            ++i;
        } else if (opt[i][j] == opt[i+1][j+1] + 1 && this->a[i] != this->b[j]) {
            os << this->a[i] << " " << this->b[j] << " 1" << "\n";
            ++j;
            ++i;
        } else if (opt[i][j] == opt[i][j+1] + 2) {
            os << "-" << " " << this->b[j] << " 2" << "\n";
            ++j;
        } else if (opt[i][j] == opt[i+1][j] + 2) {
            os << this->a[i] << " " << "-" << " 2" << "\n";
            ++i;
        }
    }
    return os.str();
}
