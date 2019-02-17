#include "Ball.hpp"
#include "HumanPlayer.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

#define IDLE_STATE 0
#define PLAY_STATE 1
#define GAME_FINISHED 2

class Desk
{
    private:
        int windowWidth;
        int windowHeight;
        sf::RectangleShape sf_stick;
        sf::CircleShape sf_ball;
        int state;


    public:
        Desk(int inputDeskX, int inputDeskY){
            windowWidth = inputDeskX;
            windowHeight = inputDeskY;
            state = PLAY_STATE;
        }

        int getDeskState(){
            return state;
        }

        void drawStickFirstTime(HumanPlayer& _humanPlayer){
            // called once
            sf_stick.setFillColor(sf::Color::Blue);
            sf_stick.setSize(sf::Vector2f(10, _humanPlayer.getStick().getStickLength() / 100.0 * windowHeight));
            sf_stick.setPosition(
                10,
                _humanPlayer.getStick().getStickPosition() / 100.0 * windowHeight
            );
        }

        void redrawStick(HumanPlayer& _humanPlayer){
            sf_stick.setPosition(
                10,
                _humanPlayer.getStick().getStickPosition() / 100.0 * windowHeight
            );
        }

        void drawBallFirstTime(Ball& _ball){
            // called once
            sf_ball.setFillColor(sf::Color::Blue);
            sf_ball.setRadius(_ball.getBallRadius() / 100 * windowHeight);
            sf_ball.setPosition(_ball.getPositionX() / 100 * windowWidth,  _ball.getPositionY() / 100 * windowHeight);
        }

        void redrawBall(Ball& _ball){
            sf_ball.setPosition(
                _ball.getPositionX() / 100 * windowWidth,  
                _ball.getPositionY() / 100 * windowHeight
            );
            sf_ball.setRadius(_ball.getBallRadius() / 100 * windowHeight);
        }

        sf::RectangleShape& getSFStick(){
            return sf_stick;
        }

        sf::CircleShape& getSFBall(){
            return sf_ball;
        }

        // moves ball based on its speed
        void oneFrameBallAction(Ball& _ball){
            float bSpeedY = _ball.getSpeedY();
                
            if (bSpeedY > 0 ) 
            {
                if (_ball.canMoveUp())
                {
                    _ball.moveYPos();
                }

                if (_ball.touchingWallBelow()){
                    _ball.revertSpeedY();
                }
            }

            else if (bSpeedY < 0)
            {
                if (_ball.canMoveDown()){
                    _ball.moveYNeg();
                }

                if (_ball.touchingWallAbove()){
                    _ball.revertSpeedY();
                }
            }
            else {
                std::cout << "[ERR]: ball speed 0" << std::endl;
            }
            
        }
        
};