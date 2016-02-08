// initial state of the Board
// I: *Board, Tile
// O: -
void resetBoard(Board *B, Tile T) {

    // main question
    B->setSpec(16, 4, 4);

    // Tile tileA("A", 2, 3, true);
    // Tile tileB("B", 2, 2, true);
    // Tile tileC("C", 2, 1, true);

    // B->putTile(tileA, 1, 1);
    // B->putTile(tileB, 2, 1);
    // B->putTile(tileC, 3, 1);
    // B->putTile(T, 4, 1);
    
    // easy tester
    B->setSpec(9, 3, 3);
    Tile tileA("A", 1, 3, true);
    Tile tileB("B", 2, 2, true);
    Tile tileC("C", 3, 1, true);


    B->putTile(tileA, 1, 2);
    B->putTile(tileB, 2, 2);
    B->putTile(tileC, 3, 2);
    B->putTile(T, 2, 1);

    // 8-puzzle
    // B->setSpec(9, 3, 3);
    // Tile tile1("1", 2, 3, true);
    // Tile tile2("2", 3, 3, true);
    // Tile tile3("3", 1, 2, true);
    // Tile tile4("4", 2, 2, true);
    // Tile tile5("5", 3, 2, true);
    // Tile tile6("6", 1, 1, true);
    // Tile tile7("7", 2, 1, true);
    // Tile tile8("8", 3, 1, true);

    // B->putTile(tile1, 3, 1);
    // B->putTile(tile2, 2, 3);
    // B->putTile(tile3, 2, 1);
    // B->putTile(tile4, 3, 3);
    // B->putTile(tile5, 1, 2);
    // B->putTile(tile6, 3, 2);
    // B->putTile(tile7, 1, 3);
    // B->putTile(tile8, 1, 1);
    // B->putTile(T, 2, 2);
}   

// check index of tile
// I: *Board, Tile
// O: Index
int findTile(Board *B, Tile T) {
    for (int i = 0; i < B->getSize(); ++i)
    {
        if (T.isEqual(B->getContent()[i]))
        {
            return i;
            break;
        }
    }
    return 0;
}

// find particular tile position
// I: *Board, Tile, Output Code (1:X, 2:Y)
// O: Position
int tilePosition(Board *B, Tile T, int O) {
    switch(O) {
        case 1: 
            return (findTile(B, T)%B->getWidth())+1;
            break;
        case 2:
            return B->getHeight()-(findTile(B, T)/B->getWidth());
            break; 
    }
}

// move tile
// I: *Board, Tile, Direction Code
    // D:
    //     0: up
    //     1: right
    //     2: down
    //     3: left
// O: -
void moveAgent(Board *B, Tile T, int D) {
    int XPos, YPos, indexPos, nextIndex;

    XPos = tilePosition(B, T, 1);
    YPos = tilePosition(B, T, 2);
    indexPos = findTile(B, T);

    switch(D) {
        case 0:
            if (YPos < B->getHeight())
                YPos++;
            break;
        case 1:
            if (XPos < B->getWidth())
                XPos++;
            break;
        case 2:
            if (YPos > 1)
                YPos--;
            break;
        case 3:
            if (XPos > 1)
                XPos--;
            break;
    }

    nextIndex = (B->getHeight()-YPos)*B->getWidth()+(XPos-1);
    if (B->getContent()[nextIndex].isMoveable())
    {
        B->putIndex(B->getContent()[nextIndex], indexPos);
        B->putIndex(T, nextIndex);
    }
}

// check if it is a valid move for the tile
// I: *Board, Tile, Direction Code
    // D:
    //     0: up
    //     1: right
    //     2: down
    //     3: left
// O: -
bool isValidMove(Board *B, Tile T, int D) {
    Board dummyBoard;

    B->copyBoard(&dummyBoard);
    moveAgent(&dummyBoard, T, D);
    return (!B->isEqual(&dummyBoard));
}

// check if all tiles is in the goal position
// I: *Board
// O: boolean
bool isFinished(Board *B) {
    bool isGoal = true;

    for (int i = 0; i < B->getSize(); ++i)
    {
        if (B->getContent()[i].getGoalX() != 0 && B->getContent()[i].getGoalY() != 0)
        {
            isGoal = isGoal && (tilePosition(B, B->getContent()[i], 1) == B->getContent()[i].getGoalX()) && (tilePosition(B, B->getContent()[i], 2) == B->getContent()[i].getGoalY());
        }

    }
    return isGoal;
}

// manhattan distance
// I: *Board, Tile (uncounted tile)
// O: int (heuristic value)
int manhattanDist(Board *B, Tile T) {
    int distance = 0;

    for (int i = 0; i < B->getSize(); ++i)
    {
        if (B->getContent()[i].getGoalX() != 0 && B->getContent()[i].getGoalY() != 0)
        {
            if (!T.isEqual(B->getContent()[i])) {
                distance = distance + abs(tilePosition(B, B->getContent()[i], 1) - B->getContent()[i].getGoalX()) + abs(tilePosition(B, B->getContent()[i], 2) - B->getContent()[i].getGoalY());
            }
        }
    }
    return distance;
}