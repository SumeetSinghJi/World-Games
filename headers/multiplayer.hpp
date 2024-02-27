/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached help.txt file
*/

#pragma once

#include "global_variables.hpp"

/*
This header is for multiplayer functionality (scene 7) that players
can challenge each other through a multiplayer game lobby
and results will be uploaded via JSON to a website leaderboard
for in game (scene 8) and public viewing www.agnisamooh.com/leaderboards 
*/

void join_available_game() {
    std::cout << "Joining available multiplayer game" << std::endl;
}

void create_available_game() {
    std::cout << "Create available multiplayer game" << std::endl;
}

void invite_freind_to_available_game() {
    std::cout << "Invite friend to available multiplayer game" << std::endl;
}

void refresh_available_games() {
    std::cout << "Refresh available multiplayer game" << std::endl;
}

void return_to_available_games() {
    std::cout << "Returning to available multiplayer lobby" << std::endl;
}

void POST_resuts_to_leaderboard() {
    // Use JSON to post results over the internet to AWS RDS through Lambda
    std::cout << "Post results of match won to global leaderboard" << std::endl;
}

void GET_resuts_to_leaderboard() {
    // Get (curl) leaderboard results from www.agnisamooh.com/leaderboards
    std::cout << "Get (curl) leaderboard results from www.agnisamooh.com/leaderboards" << std::endl;
}