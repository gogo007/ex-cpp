#include "game.h"
int main(){
    Game *aGameTest = new Game();
    bool isPlaying=true;
    while(isPlaying)
    {
        aGameTest->playTour();
        isPlaying=aGameTest->isContinue();
    }
    return 0;
}
