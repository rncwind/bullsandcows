#include <iostream>
#include <string>
#include <array>
#include <bitset>

std::array<bool,4> indexToCode(int i);

auto const printContainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto strToBoolArr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

int gm2loop()
{
    std::string input;
    std::array<bool,4> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    strToBoolArr(code,input);
    printContainer(indexToCode(2));
    printContainer(indexToCode(4));
    printContainer(indexToCode(8)); 
    printContainer(indexToCode(15));
    return 9000;
}


std::array<bool,4> indexToCode(int i){
    std::string codestr = std::bitset<4>(i).to_string();
    std::array<bool,4> code;
    strToBoolArr(code,codestr);
    return code;
}
