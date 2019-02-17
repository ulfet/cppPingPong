#define XStep 1
#include <vector>

class Ball
{
    private:
        float positionX;
        float positionY;

        float speedX;
        float speedY;

        float ballRadius;

        float speedRatio;
    
    public:
        Ball(int inputPositionX, int inputPositionY, float inputSpeed, int inputBallRadius){
            positionX = inputPositionX;
            positionY = inputPositionY - inputBallRadius;
            speedY = inputSpeed;
            speedX = inputSpeed;
            ballRadius = inputBallRadius;
        }

        // interact with either ball or a wall
        // multiply speed with some constant
        float getPositionX(){
            return positionX;
        }

        void revertSpeedY(){
            speedY *= -1;
        }

        float getSpeedY(){
            return speedY;
        }

        void setSpeedY(float inputSpeedY){
            speedY = inputSpeedY;
        }

        float getBallRadius(){
            return ballRadius;
        }

        void increaseSize(){
            if (ballRadius < 50)
                ballRadius += 1;
        }

        void decreaseSize(){
            if (ballRadius > 2)
                ballRadius -= 1;
        }

        float getPositionY(){
            return positionY;
        }

        // why 2*ballRadius
            // because an object is initiated on its topleft, see the + sign
            // +-------------
            // |            |
            // |            |
            // --------------

        void moveYNeg(){
            if (positionY > 0)
                positionY += speedY;
                std::cout << positionY << " " << ballRadius  << std::endl;
        }

        void moveYPos(){
            if (positionY + ballRadius*2 < 100)
                positionY += speedY;
                std::cout << positionY << " " << ballRadius  << std::endl;
        }

        void moveXPos(){
            if (positionX + ballRadius*2 < 100)
                positionX += XStep;
        }

        void moveXNeg(){
            if (positionX > 0)
                positionX -= XStep;
        }

        void setYPos(float yCoord){
            positionY = yCoord;
        }

        // TODO: refactor the code
        // it is actually down
        bool canMoveUp(){
            if (positionY + ballRadius*2 + speedY < 100)
                return true;
            return false;
        }

        bool canMoveDown(){
            if (positionY + speedY > 0)
                return true;
            return false;
        }

        bool touchingWallBelow(){
            if (positionY + ballRadius*2 + speedY >= 100)
                return true;
            return false;
        }
        
        bool touchingWallAbove(){
            if (positionY + speedY < 0)
                return true;
            return false;
        }
        

};