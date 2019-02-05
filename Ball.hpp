#define XStep 1
#include <vector>

class Ball
{
    private:
        float positionX;
        float positionY;

        int speed;
        int speedY;

        float speedRatio;
    
    public:
        Ball(int inputPositionX, int inputPositionY, int inputSpeed){
            positionX = inputPositionX;
            positionY = inputPositionY;
            speed = inputSpeed;
        }

        // interact with either ball or a wall
        // multiply speed with some constant
        float getPositionX(){
            return positionX;
        }

        float getPositionY(){
            return positionY;
        }

        void moveYPos(){
            if (positionY > 1)
                positionY -= XStep;
        }

        void moveYNeg(){
            if (positionY < 100)
                positionY += XStep;
        }

        void moveXPos(){
            if (positionX <100)
                positionX += XStep;
        }

        void moveXNeg(){
            if (positionX > 0)
                positionX -= XStep;
        }

};