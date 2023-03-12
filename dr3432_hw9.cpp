#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
using namespace std;

const int BOARD_X_SIZE = 20, BOARD_Y_SIZE = 20;
const int DIR_X[] = {1, 0, -1, 0}, DIR_Y[] = {0, 1, 0, -1};
const int NUM_MOVES = 4;
const char ANT_SYMBOL = 'o', DOODLEBUG_SYMBOL = 'X', EMPTY_SPACE = '-';

class Organism{
private:
    static int numOrganisms;
    void initBoard();

protected:
    const int maxX, maxY;
    char **board;
    const char identifier;
    const int breedTime;

public:
    int posX, posY;
    int timePassed;
    Organism(char identifier, int breedTime, char **board);
    Organism(char identifier, int breedTime, char **board, int positionX, int positionY);
    ~Organism() {numOrganisms--;}
    // Move will return 4 if it moved normally, and 0-3 (cardinal dir chosen) if it moved and ate (only for doodlebug).
    virtual int move() = 0;
    bool isTimeToBreed() const;
    void placeOnBoard();
    bool checkValidPosition(int x, int y) const;
    bool checkInsideBoard(int x, int y) const;
};

//Counter for number of organisms.
int Organism::numOrganisms = 0;

Organism::Organism(char identifier, int breedTime, char **board): 
maxX(BOARD_X_SIZE), 
maxY(BOARD_Y_SIZE),
board(board), 
identifier(identifier), 
breedTime(breedTime)
{
    if (board == nullptr) {
        cout << "Board was not set, please try again" << endl;
        exit(EXIT_FAILURE);
    }
    if (numOrganisms++ == 0) initBoard();
    if (numOrganisms == BOARD_X_SIZE * BOARD_Y_SIZE) {
        cout << "Attempted to place too many critters." << endl;
        cout << "Maximum number is " << BOARD_X_SIZE * BOARD_Y_SIZE << "for a board of [" 
            << BOARD_X_SIZE << " x " << BOARD_Y_SIZE << "]" << endl;
        exit(EXIT_FAILURE);
    }
    placeOnBoard();
    timePassed = 0;
}

Organism::Organism(char identifier, int breedTime, char **board, int positionY, int positionX): 
maxX(BOARD_X_SIZE), 
maxY(BOARD_Y_SIZE),
board(board), 
identifier(identifier), 
breedTime(breedTime){
    if (board == nullptr) {
        cout << "Board was not set, please try again" << endl;
        exit(EXIT_FAILURE);
    }
    if (numOrganisms == 0) initBoard();
    if (numOrganisms == BOARD_X_SIZE * BOARD_Y_SIZE) {
        cout << "Attempted to place too many critters." << endl;
        cout << "Maximum number is " << BOARD_X_SIZE * BOARD_Y_SIZE << "for a board of [" 
            << BOARD_X_SIZE << " x " << BOARD_Y_SIZE << "]" << endl;
        exit(EXIT_FAILURE);
    }

    if (!checkValidPosition(positionX, positionY)){
        cout << "ERROR, place was already occupied." << endl;
        exit(EXIT_FAILURE);
    }

    posX = positionX;
    posY = positionY;
    board[posY][posX] = identifier;
    
    timePassed = 0;
}

void Organism::initBoard() {
    srand(time(0));
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++)
            board[i][j] = EMPTY_SPACE;
    }
}

void Organism::placeOnBoard() {
    do {
        posX = rand() % maxX;
        posY = rand() % maxY;
    }while(board[posY][posX] == ANT_SYMBOL || board[posY][posX] == DOODLEBUG_SYMBOL);

    board[posY][posX] = identifier;
}

bool Organism::checkValidPosition(int x, int y) const{
    bool insideBoard = ((x >= 0) && (x < maxX) && (y >= 0) && (y < maxY));
    if (!insideBoard) return false;
    
    bool occupied = (board[y][x] == ANT_SYMBOL || board[y][x] == DOODLEBUG_SYMBOL);
    if (occupied) return false;
    
    return  (insideBoard && (!occupied));
}

bool Organism::checkInsideBoard(int x, int y) const {
    return ((x >= 0) && (x < maxX) && (y >= 0) && (y < maxY));
}

bool Organism::isTimeToBreed() const{
    return (timePassed != 0 && timePassed % breedTime == 0);
}

class Ant : public Organism{
private:
    static int numAnts;

public:
    Ant(char **board);
    Ant(char **board, int positionY, int positionX);
    Ant(const Ant &rhs);
    ~Ant(){numAnts--;}

    int move();
    Ant* breed();

};

int Ant::numAnts = 0;

Ant::Ant(char **board): Organism::Organism(ANT_SYMBOL, 3, board){
    numAnts++;
}

Ant::Ant(char **board, int positionY, int positionX): Organism::Organism(ANT_SYMBOL, 3, board, positionY, positionX){
    numAnts++;
}

Ant::Ant(const Ant &rhs): Organism::Organism(ANT_SYMBOL, 3, board, rhs.posY, rhs.posX){
    this->timePassed = rhs.timePassed;
}

int Ant::move() {
    int pickedMove = rand() % NUM_MOVES;
    if (checkValidPosition(posX + DIR_X[pickedMove], posY + DIR_Y[pickedMove])) {
        board[posY][posX] = EMPTY_SPACE;
        posY += + DIR_Y[pickedMove];
        posX += DIR_X[pickedMove];
        board[posY][posX] = identifier;
    }
    timePassed++;
    return 4;
}

Ant* Ant::breed(){
    Ant *temp;
    for (int i = 0; i < NUM_MOVES; i++) {
        if (checkValidPosition(posX + DIR_X[i], posY + DIR_Y[i])){
            temp = new Ant(board, posY + DIR_Y[i], posX + DIR_X[i]);
            return temp;
        }
    }
    return nullptr;
}

class Doodlebug : public Organism{
private:
    static int numDoodlebugs;
    const int starveTime = 3;
    int lastEaten;
    bool nextToAnt(int &direction);

public:
    Doodlebug(char **board);
    Doodlebug(char **board, int positionY, int positionX);
    Doodlebug(const Doodlebug &rhs);
    ~Doodlebug(){numDoodlebugs--;}

    int move();
    Doodlebug* breed();
    bool starved();
};
int Doodlebug::numDoodlebugs = 0;

Doodlebug::Doodlebug(char **board): Organism::Organism(DOODLEBUG_SYMBOL, 8, board){
    numDoodlebugs++;
    lastEaten = 0;
}

Doodlebug::Doodlebug(char **board, int positionY, int positionX): Organism::Organism(DOODLEBUG_SYMBOL, 8, board, positionY, positionX){
    numDoodlebugs++;
    lastEaten = 0;
}

Doodlebug::Doodlebug(const Doodlebug &rhs): Organism::Organism(DOODLEBUG_SYMBOL, 8, board, rhs.posY, rhs.posX){
    this->timePassed = rhs.timePassed;
    lastEaten = rhs.lastEaten;
}

int Doodlebug::move() {
    int direction = -1;
    int pickedMove = rand() % NUM_MOVES;
    if (nextToAnt(direction)) {
        board[posY][posX] = EMPTY_SPACE;
        posY += + DIR_Y[direction];
        posX += DIR_X[direction];
        board[posY][posX] = identifier;
        lastEaten = 0;
    }
    else if (checkValidPosition(posX + DIR_X[pickedMove], posY + DIR_Y[pickedMove])) {
        direction = 4;
        board[posY][posX] = EMPTY_SPACE;
        posY += + DIR_Y[pickedMove];
        posX += DIR_X[pickedMove];
        board[posY][posX] = identifier;
        lastEaten++;
    }
    timePassed++;
    return direction;
}

bool Doodlebug::nextToAnt(int &direction) {
    for (int i = 0; i < NUM_MOVES; i++) {
        if (checkInsideBoard(posX + DIR_X[i], posY + DIR_Y[i]) && board[posY + DIR_Y[i]][posX + DIR_X[i]] == ANT_SYMBOL){
            direction = i;
            return true;
        }
    }
    return false;
}

Doodlebug* Doodlebug::breed(){
    Doodlebug *temp;
    for (int i = 0; i < NUM_MOVES; i++) {
        if (checkValidPosition(posX + DIR_X[i], posY + DIR_Y[i])){
            temp = new Doodlebug(board, posY + DIR_Y[i], posX + DIR_X[i]);
            return temp;
        }
    }
    return nullptr;
}

bool Doodlebug::starved(){
    if (lastEaten >= starveTime){
        board[posY][posX] = EMPTY_SPACE;
        posX = -1;
        posY = -1;
        return true;
    }
    return false;
}


void printBoardState(char **board, int boardYSize, int boardXSize);
void simulation();
char** createBoard();
void placeCritters(char **board, vector<Doodlebug*>& doodlebugs, vector<Ant*>& ants);
void findEatenAnt(vector<Ant*>& ants, int x, int y);
void removeDoodlebug(vector<Doodlebug*>& doodlebugs, int index);
void deleteBoard(char** board);

int main(){
    simulation();

    return 0;
}

void simulation(){
    char **board = createBoard();
    vector<Doodlebug*> doodlebugs;
    vector<Ant*> ants;
    
    placeCritters(board, doodlebugs, ants);
    cout << "Starting state:" << endl;
    printBoardState(board,BOARD_Y_SIZE, BOARD_X_SIZE);

    char cont = '\n';
    do {
        cout << "Press Enter to continue, or any other key and then enter to exit: ";
        cont = getchar();
        system("cls");

        // Simulation:
        // Move al critters
        for (Doodlebug* d : doodlebugs) {
            switch(d->move()){
                case 0: case 1: case 2: case 3: 
                    findEatenAnt(ants, d->posX, d->posY);
                    break;

                case 4:
                    break;
            }
        }

        for (Ant *a : ants){
            a->move();
        }

        // Breed all critters that fit condition
        int numDoodlebugs = doodlebugs.size();
        for (int i = 0; i < numDoodlebugs; i++) {
            if (doodlebugs[i]->isTimeToBreed()) {
                Doodlebug* temp = doodlebugs[i]->breed();
                if (temp) doodlebugs.push_back(temp);
            }
        }

        int numAnts = ants.size();
        for (int i = 0; i < numAnts; i++) {
            if (ants[i]->isTimeToBreed()) {
                Ant* temp = ants[i]->breed();
                if (temp) ants.push_back(temp);
            }
        }

        // Remove starved Doodlebugs
        vector<int> deleteList;
        numDoodlebugs = doodlebugs.size();
        for (int i = 0; i < numDoodlebugs; i++) {
            if (doodlebugs[i]->starved()) {
                deleteList.push_back(i);
            }
        }
        int countDeleted = 0;
        for (int i : deleteList){
            removeDoodlebug(doodlebugs, i - countDeleted++);
        }

        printBoardState(board,BOARD_Y_SIZE, BOARD_X_SIZE);
        cout << endl;
    }while (cont == '\n');
    cout << "Final state before exiting." << endl;
    cout << endl << endl;
}

char** createBoard(){
    char **board = new char *[BOARD_Y_SIZE];
    for (int i = 0; i < BOARD_Y_SIZE; i++)
        board[i] = new char [BOARD_X_SIZE];

    return board;
}

void placeCritters(char **board, vector<Doodlebug*>& doodlebugs, vector<Ant*>& ants) {
    for (int i = 0; i < 5; i++){
        doodlebugs.push_back(new Doodlebug(board));
    }

    for (int i = 0; i < 100; i++){
        ants.push_back(new Ant(board));
    }
}

void findEatenAnt(vector<Ant*>& ants, int x, int y){
    if (ants.empty()) return;

    for (int i = 0; i < ants.size(); i++) {
        if (ants[i]->posX == x && ants[i]->posY == y) {
            delete ants[i];
            ants.erase(ants.begin() + i);
            return;
        }
    }
}

void removeDoodlebug(vector<Doodlebug*>& doodlebugs, int index) {
    delete doodlebugs[index];
    doodlebugs.erase(doodlebugs.begin() + index);
}

void deleteBoard(char **board) {
    for (int i = 0; i < BOARD_Y_SIZE; i++)
        delete [] board[i];
    delete[] board;
}

void printBoardState(char **board, int boardYSize, int boardXSize) {
    cout << endl;
    for (int i = 0; i < boardYSize; i++) {
        for (int j = 0; j < boardXSize; j++)
            cout << board[i][j] << "\t";
        
        cout << endl;
    }
}