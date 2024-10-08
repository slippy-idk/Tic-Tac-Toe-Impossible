//
// Created by lewis on 07/10/2024.
//

#ifndef AI_H
#define AI_H
#include <ctime>
#include <stdlib.h>
#include <thread>
#include <bits/locale_classes.h>
#include <chrono>

#include "table.h"

class AI {
    public:
    unsigned int time(int i);

    table runAI(table table) {
        using namespace std::this_thread;     // sleep_for, sleep_until
        using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
        sleep_for(5ns);



        while (true) {
            int collom = rand() % 3;
            int row = rand() % 3;

            if(table.board[row][collom] == '-') {
                table.board[row][collom] = '0';

                return table;
            }
        }
    }
};

#endif //AI_H
