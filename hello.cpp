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

    globalClock = chrono::steady_clock::now();
    // std::cout << std::chrono::duration_cast<chrono::milliseconds>(globalClock - dummy).count() << std::endl;

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


}





int main()
{
    int windowWidth = 640;
    int windowHeight = 480;

    int deskX = 1000;
    int deskY = 500;

    HumanPlayer humanPlayer = HumanPlayer();
    Desk desk = Desk(deskX, deskY);
    Ball ball = Ball(50, 50, 1);

    auto globalClock = chrono::steady_clock::now();

    

    // stick drawing object
    sf::RectangleShape sf_stick;
    sf_stick.setFillColor(sf::Color::Blue);
    sf_stick.setSize(sf::Vector2f(10, humanPlayer.getStick().getStickLength() / 100.0 * windowHeight));
    
    // ball drawing object
    sf::CircleShape sf_ball;
    sf_ball.setFillColor(sf::Color::Blue);
    sf_ball.setRadius(10);
    sf_ball.setPosition(ball.getPositionX() / 100 * windowWidth,  ball.getPositionY() / 100 * windowHeight);


    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Happy go PingPong!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        keyPressEventMonitor(humanPlayer, globalClock, ball);
        // std::cout << humanPlayer.getStick().getStickPosition() << std::endl;
        sf_stick.setPosition(
            10,
            humanPlayer.getStick().getStickPosition() / 100.0 * windowHeight
        );

        sf_ball.setPosition(
            ball.getPositionX() / 100 * windowWidth,  
            ball.getPositionY() / 100 * windowHeight
        );

        cout << ball.getPositionY() << endl;

        window.clear();
        window.draw(sf_stick);
        window.draw(sf_ball);
        window.display();
    }


    return 0;
}