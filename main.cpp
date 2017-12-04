#include <iostream>

int gm1loop();
int gm2loop();

int main()
{
    std::cout << "Enter (1) for Gamemode 1\nEnter (2) for Gamemode 2\n>";
    auto mode = 0;
    std::cin >> mode;
    switch(mode){
        case 1:
            gm1loop(); break;
        case 2:
            gm2loop(); break;
    }
    return 0;
}
