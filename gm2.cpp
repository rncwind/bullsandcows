#include <array>
#include <iostream>
#include <string>

int getbulls(std::array<bool,9> code, std::array<bool,9> guess);

int gm2loop()
{
    std::string input;
    std::array<bool,9> code;
    std::cout << "Please enter the code\n>";

    std::array<bool,9> guess {0,0,0,0,0,0,0,0,0};
    while(std::cin >> input)
    {
        int it = 0;
        for(auto& i : input){
            code.at(it) = (i == '1');
            ++it;
        }
        std::cout << "Bulls : ";
        getbulls(code,guess);
    }
    return 0;
}
