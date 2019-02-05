#include "Ball.hpp"
#include "HumanPlayer.hpp"
#include <iostream>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Desk
{
    private:
        int deskX;
        int deskY;

    public:
        Desk(int inputDeskX, int inputDeskY){
            deskX = inputDeskX;
            deskY = inputDeskY;
        }

        // obsolete
        int detectKeyPress(){
            // currently for my own PC
            // up : 65 // down: 66 // right: 67 // left: 68
            std::cout << "KeyPress: ";
            int c = getchar();
            if (c == 65){
                std::cout << c << " up" << std::endl;
                return 1;
            }
            if (c == 66){
                std::cout << c << " down" << std::endl;
                return -1;
            }
        }
        // obsolete
        void simulateOneStep(Ball& ballObj, HumanPlayer& humanObj){
            int key = detectKeyPress();
            Stick& stick = humanObj.getStick();
            if (key == 1){
                stick.moveUp();
            }

            if (key == -1){
                stick.moveDown();
            }

            // std::cout << stick.getStickPosition() << std::endl;
        }
};