#include <iostream>
#include "logic.h"
#include <fstream>
using std::cout, std::endl, std::string;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code


    void testExceptiongetDirection(int& nextRow, int& nextCol,int maxRow,int maxCol,Player player)
    {
        int originalROW = player.row;
        int originalCOL = player.col;

        // cout << "I am running!"<<endl;
        char goodInputs[6] = {'w','a','s','d','e','q'};// no longer testing for " "
        char badInputs[4] = {'!','1','2','3'};
        

            // not sure if i should be incrementing each for above, below, right and left
            // run this once
            try{
            nextCol = originalCOL+1;
            nextRow = originalROW;
            getDirection(goodInputs[0],nextRow,nextCol);
            nextCol = originalCOL-1;
            nextRow = originalROW;
            getDirection(goodInputs[0],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW-1;
            getDirection(goodInputs[0],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW+1;
            getDirection(goodInputs[0],nextRow,nextCol);
            }
            catch(...)
            {
                cout << "you went out of bounds "<<endl;
            }
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
            nextCol = originalCOL+1;
            nextRow = originalROW;
            getDirection(goodInputs[1],nextRow,nextCol);
            nextCol = originalCOL-1;
            nextRow = originalROW;
            getDirection(goodInputs[1],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW-1;
            getDirection(goodInputs[1],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW+1;
            getDirection(goodInputs[1],nextRow,nextCol);
            nextCol = player.row;
            nextRow = player.col;
            getDirection(goodInputs[1],nextRow,nextCol);
            nextCol = INT32_MIN;
            nextRow = INT32_MIN;
            getDirection(goodInputs[1],nextRow,nextCol);
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
	    	getDirection(goodInputs[2],nextRow, nextCol);
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
	    	getDirection(goodInputs[3],nextRow, nextCol);
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
	    	getDirection(goodInputs[4],nextRow, nextCol);
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
            nextCol = 100000;
            nextRow = 100000;
	    	getDirection(goodInputs[5],nextRow, nextCol);
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }

            //BAD INPUT
            try
            {
            nextCol = originalCOL+1;
            nextRow = originalROW;
            getDirection(badInputs[0],nextRow,nextCol);
            nextCol = originalCOL-1;
            nextRow = originalROW;
            getDirection(badInputs[0],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW-1;
            getDirection(badInputs[0],nextRow,nextCol);
            nextCol = originalCOL;
            nextRow = originalROW+1;
            getDirection(badInputs[0],nextRow,nextCol);
            }
            catch(...)
            {
                cout << "BAD INPUT IN DIRECTION IDIOT TF DID YOU MESS THIS UP, SPED KID " << endl;
            }
            if (!(nextRow <= maxRow))
            {
                cout <<  "Max Row does not equal next Row" << " The NEXT ROW is " << nextRow << " The Max is " << maxRow << endl;
            }
            if (!(nextCol <= maxCol))
            {
                cout <<  "Max Col does not equal next Col" << " The NEXT COL is " << nextCol << " The Max is " << maxCol << endl;
            }
            

   //    specifically test for a bad input
        // try
        // {
        // getDirection('f1',nextRow,nextCol);
        // }
        // catch(...)
        // {
        //     cout << "Your Input is incorrect f1"<< endl;
        // }
        try
        {
        getDirection(0,nextRow,nextCol);
        }
        catch(...)
        {
            cout << "Your Input is incorrect 0"<< endl;
        }
    }
    // a if statement here checking if the row and column is what I expected then if true run something


/*
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 * char** resizeMap(char** map, int& maxRow, int& maxCol);
*/
    char ** testExceptionResizingMap(string filename, Player player, int& maxRow, int& maxCol)
    {
        // id like to see this embended into doPlaer move

        char **newMap;
        char ** map;
        map = loadLevel(filename,maxRow, maxCol,player);
        int NewMaxRow = maxRow*2;
        int NewMaxCol = maxCol*2;
        cout <<"RESIZE RUNNING P1 "<<endl;
        cout << "Max Col is " << maxCol << " New Max Column " << NewMaxCol << endl;
        cout << "Max Row is "<< maxRow << " New Max Row " << NewMaxRow << endl;
        if (map==NULL) 
        {
            cout << "This is a bogus map" << endl;
            return NULL;
        }
        if (map[0]==NULL)
         {
            cout << "This is a weirdly bogus map" << endl;
            delete [] map;
            return NULL;
        }
        try
        {
           newMap = resizeMap(map, maxRow, maxCol);
  
            cout <<"RESIZE RUNNING P2"<<endl;
           if(NewMaxCol != maxCol)
           {
               cout<<"ERROR IN COLUMN the max should be " << NewMaxCol << " and it is " << maxCol << endl;
           }
           if(NewMaxRow != maxRow)
           {
               cout<<"ERROR IN ROW the max should be " << NewMaxRow << " and it is " << maxRow << endl;
           }
        }
        catch(...)
        {
            cout<<"Error in resizing "<<endl;
        }
      
        deleteMap(newMap, NewMaxRow);

        return newMap;
        
        
    }
/**
 * TODO(student): write tests for this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * const int STATUS_STAY     = 0;      // flag indicating player has stayed still
const int STATUS_MOVE     = 1;      // flag indicating player has moved in a direction
const int STATUS_TREASURE = 2;      // flag indicating player has stepped onto the treasure
const int STATUS_AMULET   = 3;      // flag indicating player has stepped onto an amulet
const int STATUS_LEAVE    = 4;      // flag indicating player has left the current room
const int STATUS_ESCAPE   = 5;      // flag indicating player has gone through the dungeon exit
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int testPlayerMovementIfStatements(char **map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol)
{
 //   try{
        int playerMove = doPlayerMove(map,maxRow,maxCol,player,nextRow,nextCol);

    //     if (playerMove == 1)
    //     {
    //         cout << " The status is move "<<endl;
    //     }
    //     else if(playerMove ==2)
    //     {
    //         cout << " The status is treasure "<<endl;
    //     }
    //     else if(playerMove ==3)
    //     {
    //        cout << " The status is amulet "<<endl;
    //        // map = testExceptionResizingMap(map,maxRow,maxCol);
    //        //deleteMap(map,maxRow);

    //     }
    //     else if(playerMove ==4)
    //     {
    //         cout << " The status is leave "<<endl;
    //     }
    //     else if(playerMove ==5)
    //     {
    //         cout << " The status is escape "<<endl;
    //     }
        return playerMove;
    //}
    // catch(...)
    // {
    //     cout << " There is an error in row " << nextRow << " or in Col " << nextCol << endl;
    // }
}
    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    void testExceptiondoPlayerMove(string filename,int maxRow, int maxCol, Player& player,int originalRow, int originalCol)
    {

        char **map;
        // run a nextrow and column that are
        // loadLevelAmulet.txt has a treasure and a exit right next to eachtoher
        int nextRow=0;
        int nextCol=0;
        // originalCol = player.col;
        // originalRow = player.row;
	    map = loadLevel(filename,maxRow, maxCol,player);
        cout << " Running This map " << filename << endl;
   //     try{
        nextRow = originalRow + 1;
        nextCol = originalCol;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
    //    cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow - 1;
        nextCol = originalCol;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
     //   cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow;
        nextCol = originalCol - 1;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
    //    cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow;
        nextCol = originalCol + 1;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
      //  cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;
        
    

    // BAD STATEMENTS

         originalCol = player.col;
         originalRow = player.row;

         cout << " Running This map " << filename << endl;
   //     try{
        nextRow = originalRow + 1;
        nextCol = originalCol;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
    //    cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow - 1;
        nextCol = originalCol;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
     //   cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow;
        nextCol = originalCol - 1;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
    //    cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;

        nextRow = originalRow;
        nextCol = originalCol + 1;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);

        nextRow = originalRow-1;
        nextCol = originalCol + 1;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);

        nextRow = 0;
        nextCol = 0;
        testPlayerMovementIfStatements(map,maxRow,maxCol,player,nextRow,nextCol);
      //  cout << "The player action from point (" << nextRow  << "," << nextCol << ") " <<endl;
        

        deleteMap(map,maxRow);
        // }
        // catch(...)
        // {
        // cout << " There is an error in row " << nextRow << " or in Col " << nextCol << endl;
        // }
    }

/**
 * TODO(student): write tests for this function
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

//bool doMonsterAttack(char** map, int maxRow, int maxCol, Player player);
    bool testMonsterIfStatements(char** map, int maxRow, int maxCol, Player player)
    {

        bool MonsterSeeing = doMonsterAttack(map,maxRow,maxCol,player);
        if (MonsterSeeing)
        {
            cout << " Monster sees you "<< endl;
            return MonsterSeeing;
        }
        else
        {
            cout << " Monster cannot see you " << endl;
            return MonsterSeeing;
        }

    }

    void testExceptiondoMonsterMove(string filename,int maxRow, int maxCol, Player& player)
    {
        
       cout << " WE ARE RUNNING "<< filename<< endl;
        char **map;
        bool MonsterSeeingYou;
        // run a nextrow and column that are
        // loadLevelAmulet.txt has a treasure and a exit right next to eachtoher

	    map = loadLevel(filename,maxRow, maxCol,player);
        cout << " Running " << filename <<endl;
        MonsterSeeingYou = testMonsterIfStatements(map,maxRow, maxCol, player);
// this is redudant
        if(MonsterSeeingYou)
        {
            cout<< "The monster sees you " <<endl;
        }
        else
        {
            cout << " the monster does not see you " << endl;
        }
        deleteMap(map,maxRow);
    
    }
    

    void testExceptionLoadMap(string& filename, int& maxRow, int& maxCol, Player& player)
    {
        char **arr;
        int nextRow = 0;
        int nextCol = 0;
        // we check to see if they move elsewhere
    	try {
	    	arr = loadLevel(filename,maxRow, maxCol,player);
            // testing next row and column
      //      cout << "WE ARE RUNNNING "<< filename << endl;
            testExceptiongetDirection(nextRow,nextCol,maxRow,maxCol,player);
            //now resize
            deleteMap(arr, maxRow);
	    }
        catch(...)
        {
      //      cout << "Error in "<< filename << endl;
        }
    // a if statement here checking if the row and column is what I expected then if true run something

    }


int main() {

   string filename;
   int maxRow = 0;
   int maxCol = 0;
   Player player;
    //test Exceptions for LOAD MAP
    // if 1 is just to allow me to close the block
if(1)
{
        filename = "loadLevelAmulet.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadquestionmark.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "invalidCharacter.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);


        filename = "0by0.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "invalidAmulet.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "2by2Happy.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "2by0.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "RM2x2.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "floatsinheader.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "1by1.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);
    
        filename = "loadLevelinvalidCharacter.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadLeveltest3MonsterHp.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadLeveltest2invalidRow.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadLeveltest3invalidCol.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "AllVariablesHappyPath.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadLevelAmulet.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "ImpossibleEscape.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "ImpossibleEscapeExitDNE.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "BadBoundsCol.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "BadBoundsRow.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename ="TaleOfTwoPlayersBAD.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);
        // NON EXISTED FILE
        filename = "THISDOESNOTEXIST.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);        

        filename = "noHeight.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);  

        filename = "noRow.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);  

        filename = "PlayerPositionDNE.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "0by1MonsterPlayer.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);    

        filename = "1by0MonsterPlayer.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "0by0Unhappy.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);    

        filename = "loadLevelAllUnpassable.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadLevelEmptyArea.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "badCharacterinCol.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "PlayerMovePlayerOnWall4x4.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "PlayerMoveTreasureEveryWhere.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "-1by3.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "intmax.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "doubleamulet.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "monster10x5Broken.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "3x1.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "monsterExclaim.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "MonsterAmulet.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "testingAllPossiblitiesDoPlayerMove.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "AllMonsterMap.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "loadquestionMark.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "playOutOfBounds.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);

        filename = "TwoExits.txt";
        testExceptionLoadMap(filename, maxRow, maxCol, player);
}

/* RESIZE MAP
P




P
*/
    
    filename = "example.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "RM2x2.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "RM4x4.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "RM5x5.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "1by1.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "GoodMap1.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "RM4x1.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "RM1x4.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);

    filename = "loadquestionMark.txt";
    testExceptionResizingMap(filename, player, maxRow,maxCol);




// try to resize 1 by 1

/* PLAYER MOVE





*/ //     void testExceptiondoMonsterMove(string filename,int maxRow, int maxCol, Player& player)
//void testExceptiondoPlayerMove(string filename,int maxRow, int maxCol, Player& player,int originalRow, int originalCol)


//REMOVED ONE BY ONE
    string ArrayOfFileNames[8] = {"example.txt","loadquestionMark.txt","RM4x4.txt","RM5x5.txt","RM2x2.txt","GoodMap1.txt","playerExitNoTreasure.txt","testingAllPossiblitiesDoPlayerMove.txt"};
    for(int i = 0; i<8;i++)
    {
        string filename = ArrayOfFileNames[i];

     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-100000,-10000);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-100,-100);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-100,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0,-100);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-1,-1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-1,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0,-1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1,-10);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1,-0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-0,1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,10,2);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,5,-5);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,2,2);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0,1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,10000000,100000);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-100000,1000000);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1,1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1,-1);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,2,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-1,-2);


     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,'a',0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0,'b');
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0.012,0);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,0.012,0.124124);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,+1,2);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,'1','a');
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,1000.1231234,-1000.1241241);
     testExceptiondoPlayerMove(filename,maxRow,maxCol,player,-100/4,-1023/1304);
  //   testExceptiondoPlayerMove(filename,6,3,player,0,0);

    }



/* DO MONSTER MOVE 



*/

//   void testExceptiondoMonsterMove(string filename,int maxRow, int maxCol, Player& player)

// MAKE SURE THERES A MONSTER IN THESE
    string ArrayOfFileNamesMonster[12] = {"example.txt","MonsterAllFourCorners.txt","monsterExclaim.txt","MonsterAmulet.txt","AllMonsterMap.txt","monsterBlocked.txt","RM4x4.txt","RM5x5.txt","RM2x2.txt","GoodMap1.txt","2by2Happy.txt","3by3BottomRight.txt"};
    for(int i = 0; i<12;i++)
    {
        filename = ArrayOfFileNamesMonster[i];
        cout << "We are running " << filename<<endl;
        testExceptiondoMonsterMove(filename,maxRow,maxCol,player);
    }
    return 0;
}
