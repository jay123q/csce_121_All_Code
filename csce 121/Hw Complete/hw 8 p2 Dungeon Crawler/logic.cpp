#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"



using std::cout, std::endl, std::ifstream, std::string,std::getline;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    string FileLine;
    char CharacterHERE;
    bool ValidExit = false;

    // cout << " We are running : " << fileName << " :" << endl;
    ifstream inputfile(fileName);
// file not opened
    if (!(inputfile))
    {
        // cout <<"Invalid File: Cannot open file"<<endl;
        return nullptr;
    }

    inputfile >> maxRow;
    
    if (inputfile.fail() | ((maxRow <= 0)| (maxRow > INT32_MAX)))
    {
        // cout << " max Row failed " << endl;
        return nullptr;
    }
    inputfile >> maxCol;
    if (inputfile.fail()| ((maxCol <= 0) | (maxCol > INT32_MAX)))
    {
        // cout << " max Col failed " << endl;
        return nullptr;
    }
    inputfile  >> player.row;
    if (inputfile.fail()| ((player.row < 0)| (player.row > INT32_MAX)))
    {
        // cout << " playerRow failed " << endl;
        return nullptr;
    }
    inputfile >> player.col;
    if (inputfile.fail() | ((player.col < 0)| (player.col > INT32_MAX)))
    {
        // cout << " playerCol failed " << endl;
        return nullptr;
    }
    // Check if the player spawns in bounds
    if((player.row >= maxRow) | (player.col >= maxCol))
    {
        // cout << " The player row or column is greater than the max "<< endl;
        return nullptr;
    }
    if(maxRow > INT32_MAX / maxCol)
    {
        // cout << "Product of the max Row and Column exceeds int 32 max " << endl;
        return nullptr;
    }


    char** map = createMap(maxRow, maxCol);
    // declare the player position
    // run a for loop for each position and check it is valid
    /*
    const char TILE_PLAYER    = 'o';    // tile for player's current location
    const char TILE_TREASURE  = '$';    // tile for treasure location
    const char TILE_AMULET    = '@';    // tile for hazard that enlarges the dungeon
    const char TILE_MONSTER   = 'M';    // tile for monster current location
    const char TILE_PILLAR    = '+';    // tile for unpassable pillar location
    const char TILE_DOOR      = '?';    // tile for door to the next room
    const char TILE_EXIT      = '!';    // tile for exit door out of dungeon
 */
    char CheckingIFstream;
    /*
    - - -
    - - - -
    - - ?
    */
    for(int ThisRow = 0; ThisRow  < maxRow; ThisRow++)
    {


        for(int ThisCol = 0; ThisCol < maxCol ; ThisCol++)
        {

            inputfile  >> CheckingIFstream;
            if(inputfile.fail())
            {
                // cout<< " if stream failed "<< endl;
                deleteMap(map,maxRow);
                return nullptr;
            }
            CharacterHERE = CheckingIFstream;
         //   cout << CharacterHERE<<endl;
            // these will ask if the map is valid
            if(CharacterHERE == TILE_EXIT)
            {
                // cout << "! is true"<<endl;
                ValidExit = true;

            }

            if(CharacterHERE == TILE_DOOR)
            {
                // cout << "? is true"<<endl;
                ValidExit = true;

            }


                switch (CharacterHERE)
                {
                case TILE_OPEN:
                    //Good Case
                    break;
                case TILE_TREASURE:
                     //Good Case
                     break;
                case TILE_AMULET:
                    break;
                case TILE_PLAYER:
                    CharacterHERE = TILE_OPEN;
                    //Good Case
                    break;
                case TILE_MONSTER:
                    //Good Case
                    break;
                case TILE_PILLAR:
                    //Good Case
                    break;
                case TILE_DOOR:
                    //Good Case
                    break;
                case TILE_EXIT:
                    //Good Case
                    break;
            
                default:
                    // else
                    deleteMap(map,maxRow);
                    // cout << "bad map of Invalid Charcters line 153 logic"<< fileName <<endl;
                    return nullptr;
                    break;
                }
         //   cout << "At position (" << ThisRow << "," << ThisCol <<")" << " There is " << CharacterHERE << endl;
            map[ThisRow][ThisCol] = CharacterHERE;
            
        // this tests out of boundscharcters

        }
        }


    inputfile >> CheckingIFstream;
    if (!(inputfile.fail()))
    {
        // cout << "Extra Data in map line 160" << endl;
        deleteMap(map,maxRow);
        return nullptr;
    }

    // // check that the players ground is clear to spawn on
    // if (map[player.row][player.col]!=TILE_OPEN)
    // {
    //     cout << "Something under the player " <<endl;
    //     deleteMap(map,maxRow);
    //     return nullptr;
    // }


    // check if the map has ! and $ or ?
    if (!(ValidExit))
    {
        // cout << "bad map of logic 182 NO ! and $ "<< fileName  <<endl;
        deleteMap(map,maxRow);
        return nullptr;
    }


    map[player.row][player.col] = TILE_PLAYER;
    return map;

}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 * // constants for user's keyboard inputs
    const char INPUT_QUIT     = 'q';    // quit command
    const char INPUT_STAY     = 'e';    // no movement
    const char MOVE_UP        = 'w';    // up movement
    const char MOVE_LEFT     = 'a';    // left movement
    const char MOVE_DOWN      = 's';    // down movement
    const char MOVE_RIGHT     = 'd';    // right movement


// function signatures, do not change
 */
void getDirection(char input, int& nextRow, int& nextCol) 
{
//  cout << " The user input is " << input <<endl;

 switch (input)
 {
 case INPUT_QUIT : //quit
    break;
 case INPUT_STAY : // stay
    nextRow = nextRow;
    nextCol = nextCol;
    break;
 case MOVE_UP : //up
    nextRow = nextRow-1;
    nextCol = nextCol;
    break;
 case MOVE_LEFT: //left
    nextRow = nextRow;
    nextCol = nextCol-1;
    break;
 case MOVE_DOWN : // down
    nextRow = nextRow+1;
    nextCol = nextCol;
    break;
 case MOVE_RIGHT: //right
    nextRow = nextRow;
    nextCol = nextCol+1;
    break;
 }

}
/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 * const char TILE_OPEN      = '-';    // blank tile
 */
// DONE
char** createMap(int maxRow, int maxCol) 
{
      char ** map = new char *[maxRow];
  for (int row = 0; row<maxRow;row++)
  {
    map[row] = new char[maxCol];
    for(int col = 0; col<maxCol;col++)
    {
        map[row][col] = TILE_OPEN;
    }

  }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
// DONE
void deleteMap(char**& map, int& maxRow) 
{

    if(map == nullptr)
    {
        maxRow = 0;
        return;
    }
    for(int row = 0; row < maxRow ;  row++)
    {
        delete [] map[row];
    }
    delete [] map;
    map = nullptr;
    // sus
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 * const char TILE_OPEN      = '-';    // blank tile
const char TILE_PLAYER    = 'o';    // tile for player's current location
const char TILE_TREASURE  = '$';    // tile for treasure location
const char TILE_AMULET    = '@';    // tile for hazard that enlarges the dungeon
const char TILE_MONSTER   = 'M';    // tile for monster current location
const char TILE_PILLAR    = '+';    // tile for unpassable pillar location
const char TILE_DOOR      = '?';    // tile for door to the next room
const char TILE_EXIT      = '!';    // tile for exit door out of dungeon
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) 
{
    if((map == nullptr) || (maxRow < 1) || (maxCol < 1))
    {
        
        return nullptr;

    }


    int oldRow = maxRow;
    int oldCol = maxCol;
    int playerRow = 0;
    int playerCol =0;
    int rowCounter = 0;
    int colCounter = 0;

    char TileHere;
    // I want to find and retain the player
    for(int row = 0; row<oldRow;row++)
    {

        for(int col = 0; col< oldCol;col++)
        {
 
            TileHere = map[row][col];
            if (TileHere == TILE_PLAYER)
            {
                playerRow = row;
                playerCol = col;
                map[row][col] = TILE_OPEN;
            }
        }
    }
    maxRow*=2;
    maxCol*=2;
    // if max row is 500000 then the prodcut is int32max
    if((maxRow <=1)|(maxRow > INT32_MAX/maxCol))
    {
        deleteMap(map,maxRow);
        return nullptr;
    }
    // if max col is 500000 then the prodcut is int32max
    if((maxCol<=1)|(maxCol > INT32_MAX/maxRow))
    {
        deleteMap(map,maxRow);
        return nullptr;
    }

    char** ResizeMap = new char * [maxRow];
    for(int row = 0;row<maxRow;row++)
    {
        ResizeMap[row] = new char[maxCol];

        
        for(int col = 0; col<maxCol;col++)
        {
         if(colCounter >= oldCol)
        {
            colCounter =0;
        }       
         if(rowCounter >= oldRow)
        {
            rowCounter =0;
        }
            ResizeMap[row][col]=map[rowCounter][colCounter];
            colCounter++;
        }
        rowCounter++;

    }

    ResizeMap[playerRow][playerCol]=TILE_PLAYER;

    deleteMap(map, oldRow);

    return ResizeMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 * constants for tile status
 * const char TILE_OPEN      = '-';    // blank tile
 * const char TILE_PLAYER    = 'o';    // tile for player's current location
 * const char TILE_TREASURE  = '$';    // tile for treasure location
 * const char TILE_AMULET    = '@';    // tile for hazard that enlarges the dungeon
 * const char TILE_MONSTER   = 'M';    // tile for monster current location
 * const char TILE_PILLAR    = '+';    // tile for unpassable pillar location
 * const char TILE_DOOR      = '?';    // tile for door to the next room
 * const char TILE_EXIT      = '!';    // tile for exit door out of dungeon
 * constants for movement status flags 
 * const int STATUS_STAY     = 0;      // flag indicating player has stayed still
 * const int STATUS_MOVE     = 1;      // flag indicating player has moved in a direction
 * const int STATUS_TREASURE = 2;      // flag indicating player has stepped onto the treasure
 * const int STATUS_AMULET   = 3;      // flag indicating player has stepped onto an amulet
 * const int STATUS_LEAVE    = 4;      // flag indicating player has left the current room
 * const int STATUS_ESCAPE   = 5;      // flag indicating player has gone through the dungeon exit
 */
//DONE!
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol)
{
    if((nextRow >= maxRow) | (nextRow < 0))
    {

        return STATUS_STAY;
    }
    if((nextCol >= maxCol) | (nextCol < 0))
    {

        return STATUS_STAY;
    }
    char playerNextTile = map[nextRow][nextCol];
    switch(playerNextTile)
    {
    case TILE_OPEN:
        //remove player from map
        map[player.row][player.col]=TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_MOVE;
    case TILE_TREASURE:
        map[player.row][player.col]=TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col]=TILE_PLAYER;
        player.treasure +=1;
        return STATUS_TREASURE;
    case TILE_AMULET:
        map[player.row][player.col]=TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col]=TILE_PLAYER;
        return STATUS_AMULET;
    case TILE_MONSTER:
        // player.row = player.row;
        // player.col = player.col;
        return STATUS_STAY;
    case TILE_PILLAR:
        // player.row = player.row;
        // player.col = player.col;
        // DONT MOVE IF A +
        return STATUS_STAY;
    case TILE_DOOR:
        map[player.row][player.col]=TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col]=TILE_PLAYER;
        return STATUS_LEAVE;
    }
    if (playerNextTile == TILE_EXIT && player.treasure >= 1)
    {
        map[player.row][player.col]=TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col]=TILE_PLAYER;
        return STATUS_ESCAPE;
    }
    else
    {
        // player.row = player.row;
        // player.col = player.col;
        return STATUS_STAY;
    }


    return 0;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */

bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
   // first check the values up
   /*
 * const char TILE_OPEN      = '-';    // blank tile
 * const char TILE_PLAYER    = 'o';    // tile for player's current location
 * const char TILE_TREASURE  = '$';    // tile for treasure location
 * const char TILE_AMULET    = '@';    // tile for hazard that enlarges the dungeon
 * const char TILE_MONSTER   = 'M';    // tile for monster current location
 * const char TILE_PILLAR    = '+';    // tile for unpassable pillar location
 * const char TILE_DOOR      = '?';    // tile for door to the next room
 * const char TILE_EXIT      = '!';    // tile for exit door out of dungeon
 * 
 */
   char CheckTile;
    bool endme = false;

// see if a monster exists at all
//rows
//up
for(int CheckRowsUp = player.row-1;CheckRowsUp>=0;CheckRowsUp--)
{
        CheckTile = map[CheckRowsUp][player.col];
    switch (CheckTile)
    {
    case TILE_PILLAR:
        endme = true;
        break;
    case TILE_MONSTER:
        map[CheckRowsUp][player.col] = TILE_OPEN;
        map[CheckRowsUp+1][player.col] = TILE_MONSTER;
        break;
    }
    // if(map[player.row][player.col]== TILE_MONSTER)
    // {
    //     return true;
    // }
    if (endme)
    {
        break;
    }
}
endme = false; 
//down
for(int CheckRowsDown = player.row+1;CheckRowsDown<maxRow;CheckRowsDown++)
{
    CheckTile = map[CheckRowsDown][player.col];
    switch (CheckTile)
    {
    case TILE_PILLAR:
        endme = true;
        break;
    case TILE_MONSTER:
        map[CheckRowsDown][player.col] = TILE_OPEN;
        map[CheckRowsDown-1][player.col] = TILE_MONSTER;
        break;
    }
    // if(map[player.row][player.col]== TILE_MONSTER)
    // {
    //     return true;
    // }
    if(endme)
    {
        break;
    }
}
endme = false;
//lefft
for(int CheckColumnRight = player.col-1;CheckColumnRight>=0;CheckColumnRight--)
{
     CheckTile = map[player.row][CheckColumnRight];
    switch (CheckTile)
    {
    case TILE_PILLAR:
        endme = true;
        break;
    case TILE_MONSTER:
        map[player.row][CheckColumnRight] = TILE_OPEN;
        map[player.row][CheckColumnRight+1] = TILE_MONSTER;
        break;
    }
    // if(map[player.row][player.col]== TILE_MONSTER)
    // {
    //     return true;
    // }
    if (endme)
    {
        break;
    }
}

endme =false;
// right
for(int CheckColumnLeft =player.col+1;CheckColumnLeft<maxCol;CheckColumnLeft++)
{
    CheckTile = map[player.row][CheckColumnLeft];
    switch (CheckTile)
    {
    case TILE_PILLAR:
        endme = true;
        break;
    case TILE_MONSTER:
        map[player.row][CheckColumnLeft] = TILE_OPEN;
        map[player.row][CheckColumnLeft-1] = TILE_MONSTER;
        break;
    }
    // if(map[player.row][player.col]== TILE_MONSTER)
    // {
    //     return true;
    // }
    if (endme)
    {
        break;
    }
}
endme =false;
 
if (map[player.row][player.col]== TILE_MONSTER)
{
    return true;
}
return false;
}

