//
// Created by lewis on 07/10/2024.
//

#ifndef TABLE_H
#define TABLE_H
//this is the table for the game
/*0 = empty
 *1= Player X
 * 2 = AI 0
 */


class table {
    public:
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };



    table() = default;




public:
    void display() {
        for (auto & i : board) {
            // Print the current row using printf
            printf("\n %c %c %c \n", i[0], i[1], i[2]);
        }
    }

    void playerturn() {
        std::string player;
        std::cin >> player;



        std::hash<std::string> hasher;
        auto hashed = hasher(player); //tbd find a way to hash the string tomake it easier with a switch

        // switch (player) {
        //
        //     case "top left":
        //         board[0][0] = 'x';
        //     case "top middle":
        //         board[0][1] = 'x';
        //     case "top right":
        //         board[0][2] = 'x';
        //
        //     case "middle left":
        //         board[1][0] = 'x';
        //     case "middle middle":
        //         board[1][1] = 'x';
        //     case "middle right":
        //         board[1][2] = 'x';
        //
        //     case "bottom left":
        //         board[2][0] = 'x';
        //     case "bottom middle":
        //         board[2][1] = 'x';
        //     case "bottom right":
        //         board[2][2] = 'x';

        if(player == "tl") {
            board[0][0] = 'x';
        }else if(player == "tm") {
            board[0][1] = 'x';

        }else if(player == "tr") {
            board[0][2] = 'x';
        }else if(player == "ml") {
            board[1][0] = 'x';
        }else if(player == "mm") {
            board[1][1] = 'x';
        }else if(player == "mr") {
            board[1][2] = 'x';
        }else if(player == "bl") {
            board[2][0] = 'x';
        }else if(player == "bm") {
            board[2][1] = 'x';
        }else if(player == "br") {
            board[2][2] = 'x';
        }else {
            printf("You entered a wrong input try again\n");
            display();
            playerturn();
        }
    }

    // char checkWinner() {
    //     // Check rows for a win
    //     for (int i = 0; i < 3; i++) {
    //         if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
    //             return board[i][0];  // Return the winner ('X' or 'O')
    //         }
    //     }
    //
    //     // Check columns for a win
    //     for (int i = 0; i < 3; i++) {
    //         if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
    //             printf("you win");
    //             return board[0][i];  // Return the winner ('X' or 'O')
    //         }
    //     }
    //
    //     // Check diagonals for a win
    //     if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
    //         return board[0][0];  // Return the winner ('X' or 'O')
    //     }
    //     if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
    //         return board[0][2];  // Return the winner ('X' or 'O')
    //     }
    //
    //     // No winner yet
    //     return '-';
    // }
    //
    // // char board[3][3]
    // bool Check_Win() {
    //     // printf("You Win");
    //     display();
    //
    //     if((board[0][0] != '-') && (board[0][0] == board[1][1] && board[1][1] == board[2][2] )) {
    //         printf("You Win");
    //         return true;
    //
    //     }
    // }

    bool Check_Win(std::string player) {
        // Check rows for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                printf("Player %s wins!\n", player.c_str());
                return true;
            }
        }

        // Check columns for a win
        for (int i = 0; i < 3; i++) {
            if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                printf(" %s wins!\n", player.c_str());
                return true;
            }
        }

        // Check diagonals for a win
        if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            printf(" %s wins!\n", player.c_str());
            return true;
        }
        if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            printf(" %s wins!\n", player.c_str());
            return true;
        }

        // No winner yet
        return false;
    }

};



#endif //TABLE_H
