#include <iostream>
#include <string>

#include "AI.h"
#include "table.h"


int main() {
    char Game_Done = 0;
    std::string Turn = "Player";

    //this is the table for the game
    /*0 = empty
     *1= Player X
     * 2 = AI 0
     */
    // std::array<int, 3> Top{{0,0,0}};
    // std::array<int, 3> Mid{{0,0,0}};
    // std::array<int, 3> Bot{{0,0,0}};


    table table;
    int move = 0; //
    AI AI;



    while (Game_Done == 0) {
        table.display();

        if(move == 5) {
            Game_Done = 1;
            printf("Game_Done: Draw No possible moves\n");
            return 0;
        }



        if(Turn == "Player") {

            printf("Please enter your move");
            printf("\n");


            table.playerturn();
            move++;


            if(table.Check_Win(std::string(Turn))) {
                printf("Game_Done: Win\n");
                Game_Done = 1;
                table.display();
            }
            Turn = "AI";





            // Turn = "AI";
        }else if(Turn == "AI") {
            printf("Ai is making its move \n");

            table = AI.runAI(table);

            // unsigned int time(int i);
            //
            //     using namespace std::this_thread;     // sleep_for, sleep_until
            //     using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
            //     sleep_for(5ns);
            //
            //
            //
            //     while (true) {
            //         int collom = rand() % 3;
            //         int row = rand() % 3;
            //
            //         if(table.board[row][collom] == '-') {
            //             table.board[row][collom] = '0';
            //
            //
            //         }
            //     }
            // }


            if(table.Check_Win(std::string(Turn))) {
                printf("Game_Done: Lost\n");
                Game_Done = 1;
                table.display();

            }


            Turn = "Player";



        }



    }
}

















