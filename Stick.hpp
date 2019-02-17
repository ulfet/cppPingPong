# define boundaryUpY 100
# define boundaryDownY 0
# define stepY 1
#include <iostream>

class Stick
{
    private:
        float positionY;
        int stickLength;

    public:
        Stick(){
            // create a stick
            stickLength = 20;
            positionY = 40;
        }

        int getStickPosition(){
            return positionY;
        }
        
        int getStickLength(){
            return stickLength;
        }

        void moveUp(){
            if (positionY < boundaryUpY - stickLength){
                positionY += stepY;
            }
        }

        void moveDown(){
            if ( positionY > boundaryDownY){
                positionY -= stepY;
            }
        }

        void resetPositionToOriginal() {
            positionY = 40;
        }
};