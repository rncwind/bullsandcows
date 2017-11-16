#include <iostream>
#include <string>
#include <vector>

int gameloop(){
    std::string input;
    std::vector<bool> guess;
    while(true)
    {
        std::cin >> input;
        for (auto i : input)
            guess.push_back(i == '1');      //kind of a hack to convert string value to bool
        std::cout << "\nyour guess is\n";
        for (auto i : guess)
            std::cout << i;
        std::cout << "\n";
    }
}
