/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++11
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "global_variables.hpp"

// Tic Tac Toe - Textures
SDL_Texture *xTexture = nullptr;
SDL_Texture *oTexture = nullptr;
SDL_Texture *lineTexture = nullptr;

// Tic Tac Toe - Global variables
int ttt_ROWS = 3;                                             // Core Logic - for drawing 9 grid array
int ttt_COLUMNS = 3;                                          // Core Logic - for drawing 9 grid array
int ttt_player_choice = 3;                                    // Core Logic - 0 = O, 1 = X, 3 = garbage value
int ttt_opponent_choice = 3;                                  // Core Logic - 0 = O, 1 = X, 3 = garbage value
std::vector<int> ttt_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2}; // Core Logic - 9 grid positions 3 top, 3 middle, 3 bottom
int ttt_winner = 0;                                           // Core Logic - 1 = player, 2 = opponent, 3 = Draw
bool ttt_game_over = false;                                   // Core Logic - after any players turn check _update_win_logic() to see if game over true
bool ttt_opponentsTurn = false;                               // Core Logic - after players turn, this turns true;
bool ttt_showPopup = true;                                    // Popup - toggle close after selections below with mouse_handle
bool ttt_player_choose_x_or_o = false;                        // Popup - Choose X or O
int ttt_rounds = 0;                                           // Popup - choose rounds
bool ttt_choose_rounds = false;                               // Popup - Choose rounds
bool ttt_starting_player_chosen = false;                      // Popup - starting player
bool ttt_starting_player_is_x = false;                        // Popup - starting player
bool ttt_choose_human_or_computer = false;                    // Popup - play against human or computer
bool ttt_play_against_human = false;                          // Popup - play against human or computer
bool ttt_timer_set = false;                                   // Popup - Timer
std::vector<int> ttt_winner_history;                          // HUD - winners frequency rect
std::vector<int> ttt_winner_choice_history;                   // HUD - winners frequency rect

// FUNCTION PROTOTYPES - Functions called from main.cpp
SDL_Texture *load_texture(const char *path, const char *name);                                   // In main.cpp
void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize);        // In main.cpp
void draw_timer();                                                                               // In main.cpp
void draw_lives(int lives);                                                                      // In main.cpp
void draw_win_frequency(const std::vector<int> &winners, const std::vector<int> &winnersChoice); // In main.cpp
void toggle_countdown(bool& subGameSettingsShowPopup, bool& subGameOver, int& subGameWinner);                                                                         // In main.cpp
void ttt_SDL_cleanup();                                                                          // keyboard_handle - ESC = quit
void exit_SDL();                                                                                 // keyboard_handle - ESC = quit

// Tic Tac Toe - Draws
void ttt_load_textures()
{
    xTexture = load_texture("assets/graphics/buttons/popup/x.png", "Tic Tac Toe X image");
    oTexture = load_texture("assets/graphics/buttons/popup/o.png", "Tic Tac Toe O image");
    lineTexture = load_texture("assets/graphics/hud/line.png", "Tic Tac Toe Line image");
    romeDayBackgroundTexture = load_texture("assets/graphics/backgrounds/rome-day.jpg", "Rome Day Background");
}
void ttt_draw_field()
{
    // Play area
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 64);       // RGB value: light grey, last digit (Alpha value = 256 / 4) (75% transparency)
    SDL_Rect ttt_rect = {(windowWidth / 4), (windowHeight / 4), (windowWidth / 2), (windowHeight / 2)};
    SDL_RenderFillRect(renderer, &ttt_rect);

    // Grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB value: Black

    // Calculate the number of squares inside the Tic Tac Toe rectangle
    int innerttt_COLUMNS = ttt_COLUMNS;
    int innerttt_ROWS = ttt_ROWS;

    // Calculate the size of each square
    int squareWidth = ttt_rect.w / ttt_COLUMNS;
    int squareHeight = ttt_rect.h / ttt_ROWS;

    // Draw vertical lines within the Tic Tac Toe rectangle
    for (int i = 1; i < innerttt_COLUMNS; ++i)
    {
        SDL_RenderDrawLine(renderer, ttt_rect.x + i * squareWidth, ttt_rect.y, ttt_rect.x + i * squareWidth, ttt_rect.y + ttt_rect.h);
    }

    // Draw horizontal lines within the Tic Tac Toe rectangle
    for (int i = 1; i < innerttt_ROWS; ++i)
    {
        SDL_RenderDrawLine(renderer, ttt_rect.x, ttt_rect.y + i * squareHeight, ttt_rect.x + ttt_rect.w, ttt_rect.y + i * squareHeight);
    }
}
void ttt_draw_setup_game_popup_window()
{
    // Draw popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {(windowWidth / 4) - 2, (windowHeight / 6) - 2, (windowWidth / 2) + 4, static_cast<int>(windowHeight * 0.8) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw popup
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect popupRect = {(windowWidth / 4), (windowHeight / 6), (windowWidth / 2), static_cast<int>(windowHeight * 0.8)};
    SDL_RenderFillRect(renderer, &popupRect);

    // Draw a close button
    // close button - grey square background black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect closeButtonBorderLineRect = {static_cast<int>(windowWidth * 0.68) - 4, static_cast<int>(windowHeight * 0.2) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &closeButtonBorderLineRect);

    // close button - grey square background
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect closeButtonBorderRect = {static_cast<int>(windowWidth * 0.68) - 2, static_cast<int>(windowHeight * 0.2) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &closeButtonBorderRect);

    // close button
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.68), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, xTexture, nullptr, &closeButtonRect);

    /*

        Choose X or O

    */
    if (!ttt_player_choose_x_or_o)
    {
        render_text("Choose: Crosses (X) or Naughts (0)", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.2), 255, 0);
    }
    else // after picking choice advise player what they choose
    {
        if (ttt_player_choice == 0)
        {
            render_text("You choose: 0", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.2), 255, 0);
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
        else
        {
            render_text("You choose: X", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.2), 255, 0);
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
    }

    // Button - for choose X
    SDL_Rect ttt_XbuttonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.26) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_XbuttonRect);

    SDL_Rect ttt_X_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, xTexture, nullptr, &ttt_X_rect);

    // Button - for choose O
    SDL_Rect ttt_ObuttonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.26) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_ObuttonRect);

    SDL_Rect ttt_O_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &ttt_O_rect);

    /*

        Starting Player

    */

    if (!ttt_starting_player_chosen)
    {
        render_text("Who starts first: X or 0", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.34), 255, 0);
    }
    else
    {
        if (!ttt_starting_player_is_x)
        {
            render_text("You choose: Starting player O", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.34), 255, 0);
        }
        else if (ttt_starting_player_is_x)
        {
            render_text("You choose: Starting player X", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.34), 255, 0);
        }
    }

    // player starts first
    SDL_Rect ttt_player_start_first_button_Rect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.40) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_player_start_first_button_Rect);

    SDL_Rect ttt_player_start_first_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, xTexture, nullptr, &ttt_player_start_first_rect);

    // Opponent starts first
    SDL_Rect ttt_opponent_start_first_button_Rect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.40) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_opponent_start_first_button_Rect);

    SDL_Rect ttt_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &ttt_opponent_start_first_rect);

    /*

        Play against

    */

    if (!ttt_choose_human_or_computer)
    {
        render_text("Play against: Human or Computer", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.50), 255, 0);
    }
    else
    {
        if (ttt_play_against_human)
        {
            render_text("You choose: Play against Human", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.50), 255, 0);
        }
        else
        {
            render_text("You choose: Play against Computer", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.50), 255, 0);
        }
    }

    // player starts first
    SDL_Rect ttt_humanButtonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.56) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_humanButtonRect);

    SDL_Rect humanRect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, humanTexture, nullptr, &humanRect);

    // Opponent starts first
    SDL_Rect ttt_computerButtonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.56) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ttt_computerButtonRect);

    SDL_Rect computerRect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, computerTexture, nullptr, &computerRect);

    /*

        Rounds

    */

    if (!ttt_choose_rounds)
    {
        render_text("Rounds: 1, 3, 5, custom", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.66), 255, 0);
    }
    else
    {
        std::string renderRounds = "You choose: " + std::to_string(ttt_rounds) + " rounds";
        render_text(renderRounds, static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.66), 255, 0);
    }

    // 1 Round
    SDL_Rect heartRounds1ButtonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.72) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &heartRounds1ButtonRect);

    SDL_Rect heartRounds1Rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, heartTexture, nullptr, &heartRounds1Rect);

    // 3 Rounds
    SDL_Rect heartRounds3ButtonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.72) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &heartRounds3ButtonRect);

    SDL_Rect heartRounds3Rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, hearts3Texture, nullptr, &heartRounds3Rect);

    // 5 Rounds
    SDL_Rect heartRounds5ButtonRect = {static_cast<int>(windowWidth * 0.46) - buttonXOffset, static_cast<int>(windowHeight * 0.72) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &heartRounds5ButtonRect);

    SDL_Rect heartRounds5Rect = {static_cast<int>(windowWidth * 0.46), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, hearts5Texture, nullptr, &heartRounds5Rect);

    // 10 Rounds
    SDL_Rect heartRounds10ButtonRect = {static_cast<int>(windowWidth * 0.56) - buttonXOffset, static_cast<int>(windowHeight * 0.72) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &heartRounds10ButtonRect);

    SDL_Rect heartRounds10Rect = {static_cast<int>(windowWidth * 0.56), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, hearts10Texture, nullptr, &heartRounds10Rect);

    /*

        Timer

    */

   if (!ttt_timer_set)
    {
        render_text("Timer: 10s, 30s, 1m, 5m, 10m, 30m, 1hr, custom (s) ", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.82), 255, 0);
    }
    else
    {
        int hours = countdownSeconds / 3600;
        int remainingSecondsAfterHours = countdownSeconds % 3600;
        int minutes = remainingSecondsAfterHours / 60;
        int seconds = remainingSecondsAfterHours % 60;
        std::string renderTimer = "You chose: " + std::to_string(hours) + " h, " +
            std::to_string(minutes) + " m, " +
            std::to_string(seconds) + " s";
        render_text(renderTimer, static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.82), 255, 0);
    }

    
    // 10 seconds
    SDL_Rect seconds10ButtonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds10ButtonRect);

    SDL_Rect seconds10Rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds10Rect);

    // 30 seconds
    SDL_Rect seconds30ButtonRect = {static_cast<int>(windowWidth * 0.31) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds30ButtonRect);

    SDL_Rect seconds30Rect = {static_cast<int>(windowWidth * 0.31), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds30Rect);

    // 1 minute
    SDL_Rect seconds60ButtonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds60ButtonRect);

    SDL_Rect seconds60Rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds60Rect);

    // 5 minute
    SDL_Rect seconds300ButtonRect = {static_cast<int>(windowWidth * 0.41) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds300ButtonRect);

    SDL_Rect seconds300Rect = {static_cast<int>(windowWidth * 0.41), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds300Rect);

    // 10 minute
    SDL_Rect seconds600ButtonRect = {static_cast<int>(windowWidth * 0.46) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds600ButtonRect);

    SDL_Rect seconds600Rect = {static_cast<int>(windowWidth * 0.46), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds600Rect);

    // 30 minute
    SDL_Rect seconds1800ButtonRect = {static_cast<int>(windowWidth * 0.51) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds1800ButtonRect);

    SDL_Rect seconds1800Rect = {static_cast<int>(windowWidth * 0.51), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds1800Rect);

    // 1 hour
    SDL_Rect seconds3600ButtonRect = {static_cast<int>(windowWidth * 0.56) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds3600ButtonRect);

    SDL_Rect seconds3600Rect = {static_cast<int>(windowWidth * 0.56), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, oTexture, nullptr, &seconds3600Rect);
}
void ttt_draw_X_or_O()
{
    std::vector<SDL_Rect> positionRects = {
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)}};
    for (size_t i = 0; i < ttt_positions.size(); ++i)
    {
        if (ttt_positions[i] == 0)
        {
            SDL_RenderCopy(renderer, oTexture, nullptr, &positionRects[i]);
        }
        else if (ttt_positions[i] == 1)
        {
            SDL_RenderCopy(renderer, xTexture, nullptr, &positionRects[i]);
        }
        else if (ttt_positions[i] == 2)
        {
            // Do nothing for position 2
        }
    }
}
void ttt_draw_settings_buttons()
{
    SDL_Rect helpRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect restartRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect worldMapRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_RenderCopy(renderer, helpTexture, nullptr, &helpRect);
    SDL_RenderCopy(renderer, restartTexture, nullptr, &restartRect);
    SDL_RenderCopy(renderer, settingsTexture, nullptr, &settingsRect);
    SDL_RenderCopy(renderer, worldMapTexture, nullptr, &worldMapRect);
}

// Tic Tac Toe - Updates
std::vector<int> ttt_update_ai_check_available_moves(std::vector<int> &ttt_positions)
{
    /*
        A vector function that accepts the 9 int vector postitions
        finds any available spaces and returns them;
    */
    std::vector<int> moves;
    for (int i = 0; i < ttt_positions.size(); ++i)
    {
        if (ttt_positions[i] == 2)
        {
            moves.push_back(i);
        }
    }
    return moves;
}
int ttt_update_possible_winning_moves(std::vector<int> ttt_positions, int player)
{
    for (int i = 0; i < ttt_positions.size(); ++i)
    {
        if (ttt_positions[i] == 2)
        {
            std::vector<int> testBoard = ttt_positions;
            testBoard[i] = player; // pretend this free space on board is any player

            for (int j = 0; j < 3; ++j)
            {
                if ((testBoard[j * 3] == player && testBoard[j * 3 + 1] == player && testBoard[j * 3 + 2] == player) ||
                    (testBoard[j] == player && testBoard[j + 3] == player && testBoard[j + 6] == player))
                {
                    return i;
                }
            }
            if ((testBoard[0] == player && testBoard[4] == player && testBoard[8] == player) ||
                (testBoard[2] == player && testBoard[4] == player && testBoard[6] == player))
            {
                return i;
            }
        }
    }
    return -1;
}
int ttt_update_find_winning_moves(std::vector<int> ttt_positions, int ttt_opponent_choice, int ttt_player_choice)
{
    /*
        Check for winning moves for the AI and Player
        the priority of movement will be
        1. Winning move for AI
        2. Blocking player from winning
        3. Make a random move if neither above condition is true
    */

    int aiWinningMove = ttt_update_possible_winning_moves(ttt_positions, ttt_opponent_choice); // AI check winning moves
    if (aiWinningMove != -1)
    {
        return aiWinningMove;
    }

    int humanWinningMove = ttt_update_possible_winning_moves(ttt_positions, ttt_player_choice); // Human check winning moves
    if (humanWinningMove != -1)
    {
        return humanWinningMove;
    }

    std::vector<int> moves = ttt_update_ai_check_available_moves(ttt_positions);
    if (!moves.empty())
    {
        return moves[rand() % moves.size()];
    }

    return -1;
}
void ttt_update_winning_logic()
{
    /* Tic Tac Toe field positioning
    1 | 2 | 3
    _________
    4 | 5 | 6
    _________
    7 | 8 | 9 */

    // Player win condition
    if ((ttt_positions[0] == ttt_player_choice && ttt_positions[1] == ttt_player_choice && ttt_positions[2] == ttt_player_choice) || // Top row
        (ttt_positions[3] == ttt_player_choice && ttt_positions[4] == ttt_player_choice && ttt_positions[5] == ttt_player_choice) || // Middle row
        (ttt_positions[6] == ttt_player_choice && ttt_positions[7] == ttt_player_choice && ttt_positions[8] == ttt_player_choice) || // Bottom row
        (ttt_positions[0] == ttt_player_choice && ttt_positions[3] == ttt_player_choice && ttt_positions[6] == ttt_player_choice) || // Left column
        (ttt_positions[1] == ttt_player_choice && ttt_positions[4] == ttt_player_choice && ttt_positions[7] == ttt_player_choice) || // Middle column
        (ttt_positions[2] == ttt_player_choice && ttt_positions[5] == ttt_player_choice && ttt_positions[8] == ttt_player_choice) || // Right column
        (ttt_positions[0] == ttt_player_choice && ttt_positions[4] == ttt_player_choice && ttt_positions[8] == ttt_player_choice) || // Diagonal 1
        (ttt_positions[2] == ttt_player_choice && ttt_positions[4] == ttt_player_choice && ttt_positions[6] == ttt_player_choice))   // Diagonal 2
    {
        if (!ttt_game_over)
        {
            std::cout << "Player wins" << std::endl;
            toggle_countdown(ttt_showPopup, ttt_game_over, ttt_winner);
            ttt_game_over = true;
            ttt_winner = 1;
            ttt_opponentsTurn = false;
            Mix_PlayChannel(-1, winGameSound, 0);

            unlocked_achievement(0);
        }
    }

    // Opponent win condition
    if ((ttt_positions[0] == ttt_opponent_choice && ttt_positions[1] == ttt_opponent_choice && ttt_positions[2] == ttt_opponent_choice) || // Top row
        (ttt_positions[3] == ttt_opponent_choice && ttt_positions[4] == ttt_opponent_choice && ttt_positions[5] == ttt_opponent_choice) || // Middle row
        (ttt_positions[6] == ttt_opponent_choice && ttt_positions[7] == ttt_opponent_choice && ttt_positions[8] == ttt_opponent_choice) || // Bottom row
        (ttt_positions[0] == ttt_opponent_choice && ttt_positions[3] == ttt_opponent_choice && ttt_positions[6] == ttt_opponent_choice) || // Left column
        (ttt_positions[1] == ttt_opponent_choice && ttt_positions[4] == ttt_opponent_choice && ttt_positions[7] == ttt_opponent_choice) || // Middle column
        (ttt_positions[2] == ttt_opponent_choice && ttt_positions[5] == ttt_opponent_choice && ttt_positions[8] == ttt_opponent_choice) || // Right column
        (ttt_positions[0] == ttt_opponent_choice && ttt_positions[4] == ttt_opponent_choice && ttt_positions[8] == ttt_opponent_choice) || // Diagonal 1
        (ttt_positions[2] == ttt_opponent_choice && ttt_positions[4] == ttt_opponent_choice && ttt_positions[6] == ttt_opponent_choice))   // Diagonal 2
    {
        if (!ttt_game_over)
        {
            std::cout << "Opponent wins" << std::endl;
            toggle_countdown(ttt_showPopup, ttt_game_over, ttt_winner);
            ttt_game_over = true;
            ttt_winner = 2;
            ttt_opponentsTurn = false;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    // Draw condition
    if (!ttt_showPopup && !ttt_game_over) // If game has started and not over (to not keep cout "it's a draw")
    {
        bool ttt_all_positions_used = true;
        for (int i = 0; i < ttt_positions.size(); ++i)
        {

            if (ttt_positions[i] == 2) // Check for any empty position
            {
                ttt_all_positions_used = false; // no empty positions
                break;
            }
        }

        if (ttt_all_positions_used && ttt_winner != 1 && ttt_winner != 2)
        {
            toggle_countdown(ttt_showPopup, ttt_game_over, ttt_winner);
            std::cout << "It's a Draw." << std::endl;
            ttt_opponentsTurn = false;
            ttt_game_over = true;
            ttt_winner = 3;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    if (ttt_game_over) // Add winner and combination to Frequency rect
    {
        ttt_winner_history.push_back(ttt_winner);

        if (ttt_winner == 1)
        {
            ttt_winner_choice_history.push_back(ttt_player_choice);
        }
        else if (ttt_winner == 2)
        {
            ttt_winner_choice_history.push_back(ttt_opponent_choice);
        }
        else if (ttt_winner == 3)
        {
            ttt_winner_choice_history.push_back(2); // Draw
        }
    }
}
void ttt_update_new_game_reset_variables()
{
    ttt_player_choice = 3;
    ttt_opponent_choice = 3;
    ttt_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    ttt_player_choose_x_or_o = false;
    ttt_winner = 0;
    ttt_game_over = false;
    ttt_opponentsTurn = false;
    ttt_showPopup = true;
    ttt_play_against_human = false;
    ttt_choose_human_or_computer = false;
    ttt_rounds = 0;
    ttt_choose_rounds = false;
    ttt_starting_player_is_x = false;
    ttt_starting_player_chosen = false;
    ttt_timer_set = false;

    // Restart timer - generic function
    timerRunning = false;
    countdownStarted = false;
    countdownSeconds = 300;
}
void ttt_update_is_position_taken(int index)
{
    int gridPosition = index + 1;
    std::string competitor = ttt_opponentsTurn ? "Opponent" : "Player";

    if (ttt_positions[index] == 2)
    {
        int choice = (competitor == "Player") ? ttt_player_choice : ttt_opponent_choice;
        ttt_positions[index] = choice;

        ttt_opponentsTurn = !ttt_opponentsTurn;
    }
    else
    {
        std::cout << competitor << ", Position: " << gridPosition << " is taken. Try again." << std::endl;
    }
}
void ttt_update_ai_logic()
{
    while (ttt_opponentsTurn)
    {
        int aiMoveIndex = ttt_update_find_winning_moves(ttt_positions, ttt_opponent_choice, ttt_player_choice);
        if (aiMoveIndex != -1)
        {
            ttt_update_is_position_taken(aiMoveIndex);
        }
    }
}

// Tic Tac Toe - Handles
void ttt_mouse_handle(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    // ttt - Buttons
    std::vector<SDL_Rect> positionRects = {
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)}};

    // Settings - Buttons
    SDL_Rect helpRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect restartRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect worldMapRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    // HUD - Buttons
    SDL_Rect timerRect = {static_cast<int>(windowWidth * 0.05), static_cast<int>(windowHeight * 0.05), (windowWidth / 4), (windowHeight / 8)};

    // Popup - Buttons
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.68), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect ttt_X_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_Rect ttt_O_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_Rect ttt_player_start_first_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_Rect ttt_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_Rect humanRect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_Rect computerRect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_Rect heartRounds1Rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_Rect heartRounds3Rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_Rect heartRounds5Rect = {static_cast<int>(windowWidth * 0.46), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_Rect heartRounds10Rect = {static_cast<int>(windowWidth * 0.56) - buttonXOffset, static_cast<int>(windowHeight * 0.72) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_Rect seconds10Rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds30Rect = {static_cast<int>(windowWidth * 0.31), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds60Rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds300Rect = {static_cast<int>(windowWidth * 0.41), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds600Rect = {static_cast<int>(windowWidth * 0.46), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds1800Rect = {static_cast<int>(windowWidth * 0.51), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_Rect seconds3600Rect = {static_cast<int>(windowWidth * 0.56), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};

    // Choose X or O to start
    if (!ttt_game_over)
    {
        if (!ttt_showPopup) // main game code
        {
            for (int i = 0; i < positionRects.size(); ++i)
            {
                if (SDL_PointInRect(&mousePosition, &positionRects[i]))
                {
                    int gridPosition = i + 1;
                    std::cout << "Player choose Position: " << gridPosition << std::endl;
                    ttt_update_is_position_taken(i);
                }
            }
        }
        else // Popup code
        {
            if (SDL_PointInRect(&mousePosition, &closeButtonRect))
            {
                if (ttt_player_choose_x_or_o && ttt_starting_player_chosen && ttt_choose_human_or_computer && ttt_choose_rounds && ttt_timer_set)
                {
                    std::cout << "You clicked Close Popup window" << std::endl;
                    ttt_showPopup = false;
                    toggle_countdown(ttt_showPopup, ttt_game_over, ttt_winner);
                }
                else
                {
                    std::cout << "Error: Cannot close popup without choosing new game settings" << std::endl;
                }
            }
            else if (SDL_PointInRect(&mousePosition, &ttt_X_rect))
            {
                std::cout << "You choose: X" << std::endl;
                ttt_player_choice = 1;
                ttt_opponent_choice = 0;
                ttt_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ttt_O_rect))
            {
                std::cout << "You choose: O" << std::endl;
                ttt_player_choice = 0;
                ttt_opponent_choice = 1;
                ttt_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ttt_player_start_first_rect))
            {
                std::cout << "You choose: Starting player X" << std::endl;
                if (ttt_player_choice == 1)
                {
                    ttt_opponentsTurn = false;
                }
                else if (ttt_player_choice == 0)
                {
                    ttt_opponentsTurn = true;
                }
                ttt_starting_player_is_x = true;
                ttt_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ttt_opponent_start_first_rect))
            {
                std::cout << "You choose: Starting player O" << std::endl;
                if (ttt_player_choice == 0)
                {
                    ttt_opponentsTurn = false;
                }
                else if (ttt_player_choice == 1)
                {
                    ttt_opponentsTurn = true;
                }
                ttt_starting_player_is_x = false;
                ;
                ttt_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &humanRect))
            {
                std::cout << "You choose: Play against Human" << std::endl;
                ttt_play_against_human = true;
                ttt_choose_human_or_computer = true;
            }
            else if (SDL_PointInRect(&mousePosition, &computerRect))
            {
                std::cout << "You choose: Play against Computer" << std::endl;
                ttt_play_against_human = false;
                ttt_choose_human_or_computer = true;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds1Rect))
            {
                std::cout << "You choose: Play 1 round" << std::endl;
                ttt_choose_rounds = true;
                ttt_rounds = 1;
                
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds3Rect))
            {
                std::cout << "You choose: Play 3 rounds" << std::endl;
                ttt_choose_rounds = true;
                ttt_rounds = 3;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds5Rect))
            {
                std::cout << "You choose: Play 5 rounds" << std::endl;
                ttt_choose_rounds = true;
                ttt_rounds = 5;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds10Rect))
            {
                std::cout << "You choose: Play 10 rounds" << std::endl;
                ttt_choose_rounds = true;
                ttt_rounds = 10;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds10Rect))
            {
                std::cout << "You choose: 10 second timer" << std::endl;
                countdownSeconds = 10;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds30Rect))
            {
                std::cout << "You choose: 30 second timer" << std::endl;
                countdownSeconds = 30;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds60Rect))
            {
                std::cout << "You choose: 60 second timer" << std::endl;
                countdownSeconds = 60;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds300Rect))
            {
                std::cout << "You choose: 5 minutes timer" << std::endl;
                countdownSeconds = 300;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds600Rect))
            {
                std::cout << "You choose: 10 minutes timer" << std::endl;
                countdownSeconds = 600;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds1800Rect))
            {
                std::cout << "You choose: 30 minutes timer" << std::endl;
                countdownSeconds = 1800;
                ttt_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds3600Rect))
            {
                std::cout << "You choose: 1 hour timer" << std::endl;
                countdownSeconds = 3600;
                ttt_timer_set = true;
            }
        }
    }
    
    // Settings - Buttons
    if (SDL_PointInRect(&mousePosition, &helpRect))
    {
        lastScene = scene;
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (SDL_PointInRect(&mousePosition, &restartRect))
    {
        std::cout << "You clicked Restart" << std::endl;
        ttt_update_new_game_reset_variables();
    }
    else if (SDL_PointInRect(&mousePosition, &settingsRect))
    {
        lastScene = scene;
        std::cout << "You clicked Settings" << std::endl;
        scene = 2;
    }
    else if (SDL_PointInRect(&mousePosition, &worldMapRect))
    {
        std::cout << "You clicked return to World Map" << std::endl;
        scene = 25;
    }
    
    // HUD - Buttons
    else if (SDL_PointInRect(&mousePosition, &timerRect))
    {
        std::cout << "You clicked: Restart Timer" << std::endl;
        toggle_countdown(ttt_showPopup, ttt_game_over, ttt_winner);
    }
}
void ttt_keyboard_handle(SDL_Event event)
{
    SDL_Rect ttt_X_rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};
    SDL_Rect ttt_O_rect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};

    std::vector<SDL_Rect> positionRects = {
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.25), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.45), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.45), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)},
        {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6), (windowWidth / 8), (windowHeight / 8)}};

    SDL_Rect restartRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), (windowWidth / 8), (windowHeight / 8)};

    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.35), (windowWidth / 20), (windowHeight / 20)};

    // Highlight the selected option for keyboard arrow key and gamepad d pad key input
    SDL_Rect selectedRect = {
        static_cast<int>(windowWidth * 0.35),
        static_cast<int>(windowHeight * 0.25) + selectedOption * 100, // Spacing (must be bigger then sdl_renders.h same rect)
        static_cast<int>(windowWidth * 0.3),
        static_cast<int>(windowWidth * 0.3)};

    SDL_Point selectedPoint = {selectedRect.x, selectedRect.y}; // This is the selectedRect which overlaps the button rects

    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You clicked button: ESC" << std::endl;
        ttt_SDL_cleanup();
        exit_SDL();
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        selectedOption = (selectedOption - 1 + menuTotalOptions) % menuTotalOptions;
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        selectedOption = (selectedOption + 1) % menuTotalOptions;
        break;
    case SDLK_RETURN:
        std::cout << "You clicked button: RETURN | ENTER" << std::endl;
        if (SDL_PointInRect(&selectedPoint, &restartRect))
        {
            std::cout << "You clicked: Restart game" << std::endl;
            ttt_update_new_game_reset_variables();
        }
        else if (SDL_PointInRect(&selectedPoint, &closeButtonRect))
        {
            std::cout << "You clicked: Close popup" << std::endl;
            ttt_showPopup = false;
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void ttt_gamepad_handle(int button)
{
}

// Tic Tac Toe - SDL Integration
void ttt_SDL_draw()
{
    SDL_RenderCopy(renderer, romeDayBackgroundTexture, NULL, NULL);
    render_text("Ancient Rome - Tic Tac Toe", static_cast<int>(windowWidth * 0.37), static_cast<int>(windowHeight * 0.1), 255, 0);

    // HUD Buttons
    draw_timer();
    ttt_draw_settings_buttons();
    draw_win_frequency(ttt_winner_history, ttt_winner_choice_history);
    draw_lives(ttt_rounds);

    ttt_draw_field();

    if (ttt_showPopup)
    {
        ttt_draw_setup_game_popup_window();
    }
    else
    {
        ttt_draw_X_or_O();
    }

    if (ttt_winner == 1)
    {
        render_text("player wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
    else if (ttt_winner == 2)
    {
        render_text("Opponent wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
    else if (ttt_winner == 3)
    {
        render_text("It's a Draw.", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
}
void ttt_SDL_update()
{
    ttt_update_winning_logic();
    if (!ttt_play_against_human && ttt_choose_human_or_computer)
    {
        ttt_update_ai_logic();
    }
    ttt_update_winning_logic();
    songTitle = "assets/sounds/music/Old Rome - PianoAmor.mp3";
    load_music(songTitle);
}
void ttt_SDL_cleanup()
{
    // ttt_textures
    SDL_DestroyTexture(xTexture);
    SDL_DestroyTexture(oTexture);
    SDL_DestroyTexture(lineTexture);
}