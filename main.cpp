// "Copyright 4/4/2022 Jacob George"
#include "EDistance.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main(int argc, const char* argv[]) {
    sf::Clock clock;
    sf::Time t;
    std::string x;
    std::string y;

    std::cin >> x >> y;
    EDistance ED(x, y);
    std::cout << "Edit Distance = " << ED.optDistance() << std::endl;
    std::cout << ED.alignment();

    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
    return 0;
}
