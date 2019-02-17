#include <iostream>
#include "Desk.hpp"
#include <chrono>
#include <SFML/Graphics.hpp>
#define timeStep 10
using namespace std;
#define clockObject std::chrono::time_point<std::chrono::steady_clock>


auto dummy = chrono::steady_clock::now();


void keyPressEventMonitor(HumanPlayer& humanObj, clockObject& globalClock, Ball& ballObj)
{
    // measure the time
    clockObject clockNow = chrono::steady_clock::now();
    int elapsedTime = chrono::duration_cast<chrono::milliseconds>(clockNow - globalClock).count();
    // if (elapsedTime % 1000 == 0)
    //     std::cout << "Elapsed Time: " << elapsedTime << std::endl;
    // not enought time has passed

    if (elapsedTime <= timeStep)
        return;

    // update global clock, so we can keep track of time
    // thing it as a "lap", global clock set to the last valid action frame
    globalClock = chrono::steady_clock::now();



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        humanObj.getStick().moveDown();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        humanObj.getStick().moveUp();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        humanObj.getStick().resetPositionToOriginal();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        ballObj.moveYPos();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        ballObj.moveYNeg();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        ballObj.moveXNeg();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        ballObj.moveXPos();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
    {
        std::cout << "Ball Size-" << std::endl;
        ballObj.decreaseSize();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
    {
        std::cout << "Ball Size+" << std::endl;
        ballObj.increaseSize();
    }
}


int main()
{
    int windowWidth = 480;
    int windowHeight = 480;

    HumanPlayer humanPlayer = HumanPlayer();
    Desk desk = Desk(windowWidth, windowHeight);
    Ball ball = Ball(50, 50, -0.01, 5);

    auto globalClock = chrono::steady_clock::now();

    

    // stick drawing object inside Desk
    desk.drawStickFirstTime(humanPlayer);
    
    // ball drawing object inside Desk
    desk.drawBallFirstTime(ball);
    


    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Happy go PingPong!");

    while (window.isOpen())
    {

        int currentState = desk.getDeskState();

        // game is idle
        if (currentState == 0){
            window.clear();
            window.display();
            continue;
        }

            
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // detect key press, take necessary actions
        // TODO: update based on time count, return from keyPress, not void
        keyPressEventMonitor(humanPlayer, globalClock, ball);

        // TODO: put desk into keyPress...
        desk.oneFrameBallAction(ball);
        
        // things have been updated, update their position in desk
        desk.redrawStick(humanPlayer);
        desk.redrawBall(ball);

        window.clear();
        window.draw(desk.getSFStick());
        window.draw(desk.getSFBall());
        window.display();
    }


    return 0;
}