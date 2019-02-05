#include <iostream>
#include <string>
#include "Stick.hpp"

class HumanPlayer
{
    private:
        int _score;
        std::string _playerName;
        Stick _stick;

    public:
        HumanPlayer(){
            _score = 0;
            _playerName = "Haydar";
            _stick = Stick();
        }

        Stick& getStick()
        {
            return _stick;
        }
};