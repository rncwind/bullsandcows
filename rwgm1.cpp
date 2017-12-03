#include <array>
#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::array <bool, 4> cows;
    cows.fill(true);
    std::array <bool,4> guess;
    std::string inputstr;
    std::cin >> inputstr;
    int it = 0;
    for (auto& i : inputstr){
        guess.at(it) = (i == '1');
        ++it;
    }
    std::cout << "your guess is: ";
    for (auto i : guess)
        std::cout << i;
    std::cout << '\n';
}
