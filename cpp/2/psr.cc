#include <iostream>
#include <fstream>

int getPoints(char move) {
    switch(move) {
        case 'A':
        case 'X':
            return 1;
        case 'B':
        case 'Y':
            return 2;
        case 'C':
        case 'Z':
            return 3;
        default:
            return 0;
    }
}

int getOutcomePoints(char myMove, char opponentMove) {

    // There has to be a better way of doing this...
    if ((myMove == 'X' && opponentMove == 'A')
            || (myMove == 'Y' && opponentMove == 'B')
            || (myMove == 'Z' && opponentMove == 'C')) {
        std::cout << "draw" << std::endl;
        return 3;
    }

    if ((myMove == 'X' && opponentMove == 'C')
            || (myMove == 'Y' && opponentMove == 'A')
            || (myMove == 'Z' && opponentMove == 'B')) {
        std::cout << "win" << std::endl;
        return 6;
    }

    return 0;
}

int main() {
    int points = 0;
    std::string line;
    std::ifstream file;
    char opponentMove;
    char myMove;

    file.open("moves.txt");

    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    while(std::getline (file, line)) {
        myMove = line[2];
        opponentMove = line[0];
        /* opponentMove = static_cast<OpponentMove>(line[2]); */
        /* myMove = static_cast<MyMove>(line[0]); */

        points += (getPoints(myMove) + getOutcomePoints(myMove, opponentMove));
    }

    std::cout << points << std::endl;

  return 0;
}
