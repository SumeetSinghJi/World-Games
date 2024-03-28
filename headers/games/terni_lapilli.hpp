/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++17
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "../global_variables.hpp"

// terni lapilli - Textures
SDL_Texture *ternilapilli_xTexture = nullptr;
SDL_Texture *ternilapilli_oTexture = nullptr;
SDL_Texture *ternilapilli_lineTexture = nullptr;

// terni lapilli - Global variables
int ternilapilli_ROWS = 3;                                             // Core Logic - for drawing 9 grid array
int ternilapilli_COLUMNS = 3;                                          // Core Logic - for drawing 9 grid array
int ternilapilli_player_choice = 3;                                    // Core Logic - 0 = O, 1 = X, 3 = garbage value
int ternilapilli_opponent_choice = 3;                                  // Core Logic - 0 = O, 1 = X, 3 = garbage value
std::vector<int> ternilapilli_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2}; // Core Logic - 9 grid positions 3 top, 3 middle, 3 bottom
int ternilapilli_winner = 0;                                           // Core Logic - 1 = player, 2 = opponent, 3 = Draw
bool ternilapilli_game_over = false;                                   // Core Logic - after any players turn check _update_win_logic() to see if game over true
bool ternilapilli_opponentsTurn = false;                               // Core Logic - after players turn, this turns true;
bool ternilapilli_showPopup = true;                                    // Popup - toggle close after selections below with mouse_handle
bool ternilapilli_player_choose_x_or_o = false;                        // Popup - Choose X or O
int ternilapilli_rounds = 0;                                           // Popup - choose rounds
bool ternilapilli_choose_rounds = false;                               // Popup - Choose rounds
bool ternilapilli_starting_player_chosen = false;                      // Popup - starting player
bool ternilapilli_starting_player_is_x = false;                        // Popup - starting player
bool ternilapilli_choose_human_or_computer = false;                    // Popup - play against human or computer
bool ternilapilli_play_against_human = false;                          // Popup - play against human or computer
bool ternilapilli_timer_set = false;                                   // Popup - Timer
std::vector<int> ternilapilli_winner_history;                          // HUD - winners frequency rect
std::vector<int> ternilapilli_winner_choice_history;                   // HUD - winners frequency rect

// FUNCTION PROTOTYPES - Functions called from main.cpp
SDL_Texture *load_texture(const char *path, const char *name);                                   // In main.cpp
void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize);        // In main.cpp
void draw_timer();                                                                               // In main.cpp
void draw_lives(int lives);                                                                      // In main.cpp
void draw_win_frequency(const std::vector<int> &winners, const std::vector<int> &winnersChoice); // In main.cpp
void toggle_countdown(bool& subGameSettingsShowPopup, bool& subGameOver, int& subGameWinner);                                                                         // In main.cpp
void ternilapilli_SDL_cleanup();                                                                          // keyboard_handle - ESC = quit
void exit_SDL();                                                                                 // keyboard_handle - ESC = quit

// terni lapilli - Draws
void ternilapilli_load_textures()
{
    ternilapilli_xTexture = load_texture("assets/graphics/buttons/popup/x.png", "terni lapilli X image");
    ternilapilli_oTexture = load_texture("assets/graphics/buttons/popup/o.png", "terni lapilli O image");
    ternilapilli_lineTexture = load_texture("assets/graphics/hud/line.png", "terni lapilli Line image");
    romeDayBackgroundTexture = load_texture("assets/graphics/backgrounds/rome-day.jpg", "Rome Day Background");
}
void ternilapilli_draw_field()
{
    // Play area
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 64);       // RGB value: light grey, last digit (Alpha value = 256 / 4) (75% transparency)
    SDL_Rect ternilapilli_rect = {(windowWidth / 4), (windowHeight / 4), (windowWidth / 2), (windowHeight / 2)};
    SDL_RenderFillRect(renderer, &ternilapilli_rect);

    // Grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB value: Black

    // Calculate the number of squares inside the terni lapilli rectangle
    int innerternilapilli_COLUMNS = ternilapilli_COLUMNS;
    int innerternilapilli_ROWS = ternilapilli_ROWS;

    // Calculate the size of each square
    int squareWidth = ternilapilli_rect.w / ternilapilli_COLUMNS;
    int squareHeight = ternilapilli_rect.h / ternilapilli_ROWS;

    // Draw vertical lines within the terni lapilli rectangle
    for (int i = 1; i < innerternilapilli_COLUMNS; ++i)
    {
        SDL_RenderDrawLine(renderer, ternilapilli_rect.x + i * squareWidth, ternilapilli_rect.y, ternilapilli_rect.x + i * squareWidth, ternilapilli_rect.y + ternilapilli_rect.h);
    }

    // Draw horizontal lines within the terni lapilli rectangle
    for (int i = 1; i < innerternilapilli_ROWS; ++i)
    {
        SDL_RenderDrawLine(renderer, ternilapilli_rect.x, ternilapilli_rect.y + i * squareHeight, ternilapilli_rect.x + ternilapilli_rect.w, ternilapilli_rect.y + i * squareHeight);
    }
}
void ternilapilli_draw_setup_game_popup_window()
{
    // Draw popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.15) - 2, static_cast<int>(windowHeight * 0.15) - 2, static_cast<int>(windowWidth * 0.7) + 4, static_cast<int>(windowHeight * 0.8) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw popup
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect popupRect = {static_cast<int>(windowWidth * 0.15), static_cast<int>(windowHeight * 0.15), static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.8)};
    SDL_RenderFillRect(renderer, &popupRect);

    // close button - grey square background black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect closeButtonBorderLineRect = {static_cast<int>(windowWidth * 0.75) - 4, static_cast<int>(windowHeight * 0.2) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &closeButtonBorderLineRect);

    // close button - grey square background
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect closeButtonBorderRect = {static_cast<int>(windowWidth * 0.75) - 2, static_cast<int>(windowHeight * 0.2) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &closeButtonBorderRect);

    // close button
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.75), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_xTexture, nullptr, &closeButtonRect);

    /*

        Choose X or O

    */
    if (!ternilapilli_player_choose_x_or_o)
    {
        render_text("Choose: Cross (X) or Naughts (0)", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.16), 255, 0);
    }
    else // after picking choice advise player what they choose
    {
        if (ternilapilli_player_choice == 0)
        {
            render_text("You choose: 0", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.16), 255, 0);
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
        else
        {
            render_text("You choose: X", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.16), 255, 0);
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
    }

    // Button - for choose X
    SDL_Rect ternilapilli_XbuttonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.26) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_XbuttonRect);

    SDL_Rect ternilapilli_X_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_xTexture, nullptr, &ternilapilli_X_rect);

    // Button - for choose O
    SDL_Rect ternilapilli_ObuttonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.26) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_ObuttonRect);

    SDL_Rect ternilapilli_O_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &ternilapilli_O_rect);

    /*

        Starting Player

    */

    if (!ternilapilli_starting_player_chosen)
    {
        render_text("Who starts first: X or 0", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.30), 255, 0);
    }
    else
    {
        if (!ternilapilli_starting_player_is_x)
        {
            render_text("You choose: Starting player O", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.30), 255, 0);
        }
        else
        {
            render_text("You choose: Starting player X", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.30), 255, 0);
        }
    }

    // player starts first
    SDL_Rect ternilapilli_player_start_first_button_Rect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.40) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_player_start_first_button_Rect);

    SDL_Rect ternilapilli_player_start_first_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_xTexture, nullptr, &ternilapilli_player_start_first_rect);

    // Opponent starts first
    SDL_Rect ternilapilli_opponent_start_first_button_Rect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.40) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_opponent_start_first_button_Rect);

    SDL_Rect ternilapilli_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &ternilapilli_opponent_start_first_rect);

    /*

        Play against

    */

    if (!ternilapilli_choose_human_or_computer)
    {
        render_text("Play against: Human or Computer", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.46), 255, 0);
    }
    else
    {
        if (ternilapilli_play_against_human)
        {
            render_text("You choose: Play against Human", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.46), 255, 0);
        }
        else
        {
            render_text("You choose: Play against Computer", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.46), 255, 0);
        }
    }

    // player starts first
    SDL_Rect ternilapilli_humanButtonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.56) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_humanButtonRect);

    SDL_Rect humanRect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, humanTexture, nullptr, &humanRect);

    // Opponent starts first
    SDL_Rect ternilapilli_computerButtonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.56) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &ternilapilli_computerButtonRect);

    SDL_Rect computerRect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.56), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, computerTexture, nullptr, &computerRect);

    /*

        Rounds

    */

    if (!ternilapilli_choose_rounds)
    {
        render_text("Rounds: 1, 3, 5, custom", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.62), 255, 0);
    }
    else
    {
        std::string renderRounds = "You choose: " + std::to_string(ternilapilli_rounds) + " rounds";
        render_text(renderRounds, static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.62), 255, 0);
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

   if (!ternilapilli_timer_set)
    {
        render_text("Timer: 10s, 30s, 1m, 5m, 10m, 30m, 1hr, custom (s) ", static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.78), 255, 0);
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
        render_text(renderTimer, static_cast<int>(windowWidth * 0.19), static_cast<int>(windowHeight * 0.78), 255, 0);
    }

    
    // 10 seconds
    SDL_Rect seconds10ButtonRect = {static_cast<int>(windowWidth * 0.16) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds10ButtonRect);

    SDL_Rect seconds10Rect = {static_cast<int>(windowWidth * 0.16), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds10Rect);

    // 30 seconds
    SDL_Rect seconds30ButtonRect = {static_cast<int>(windowWidth * 0.26) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds30ButtonRect);

    SDL_Rect seconds30Rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds30Rect);

    // 1 minute
    SDL_Rect seconds60ButtonRect = {static_cast<int>(windowWidth * 0.36) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds60ButtonRect);

    SDL_Rect seconds60Rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds60Rect);

    // 5 minute
    SDL_Rect seconds300ButtonRect = {static_cast<int>(windowWidth * 0.46) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds300ButtonRect);

    SDL_Rect seconds300Rect = {static_cast<int>(windowWidth * 0.46), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds300Rect);

    // 10 minute
    SDL_Rect seconds600ButtonRect = {static_cast<int>(windowWidth * 0.56) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds600ButtonRect);

    SDL_Rect seconds600Rect = {static_cast<int>(windowWidth * 0.56), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds600Rect);

    // 30 minute
    SDL_Rect seconds1800ButtonRect = {static_cast<int>(windowWidth * 0.66) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds1800ButtonRect);

    SDL_Rect seconds1800Rect = {static_cast<int>(windowWidth * 0.66), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds1800Rect);

    // 1 hour
    SDL_Rect seconds3600ButtonRect = {static_cast<int>(windowWidth * 0.76) - buttonXOffset, static_cast<int>(windowHeight * 0.88) - buttonYOffset, buttonWidth, buttonHeight};
    SDL_RenderCopy(renderer, buttonTexture, nullptr, &seconds3600ButtonRect);

    SDL_Rect seconds3600Rect = {static_cast<int>(windowWidth * 0.76), static_cast<int>(windowHeight * 0.88), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &seconds3600Rect);
}
void ternilapilli_draw_X_or_O()
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
    for (size_t i = 0; i < ternilapilli_positions.size(); ++i)
    {
        if (ternilapilli_positions[i] == 0)
        {
            SDL_RenderCopy(renderer, ternilapilli_oTexture, nullptr, &positionRects[i]);
        }
        else if (ternilapilli_positions[i] == 1)
        {
            SDL_RenderCopy(renderer, ternilapilli_xTexture, nullptr, &positionRects[i]);
        }
        else if (ternilapilli_positions[i] == 2)
        {
            // Do nothing for position 2
        }
    }
}
void ternilapilli_draw_settings_buttons()
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

// terni lapilli - Updates
std::vector<int> ternilapilli_update_ai_check_available_moves(std::vector<int> &ternilapilli_positions)
{
    /*
        A vector function that accepts the 9 int vector postitions
        finds any available spaces and returns them;
    */
    std::vector<int> moves;
    for (int i = 0; i < ternilapilli_positions.size(); ++i)
    {
        if (ternilapilli_positions[i] == 2)
        {
            moves.push_back(i);
        }
    }
    return moves;
}
int ternilapilli_update_possible_winning_moves(const std::vector<int> ternilapilli_positions, int player)
{
    for (int i = 0; i < ternilapilli_positions.size(); ++i)
    {
        if (ternilapilli_positions[i] == 2)
        {
            std::vector<int> testBoard = ternilapilli_positions;
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
int ternilapilli_update_find_winning_moves(std::vector<int> ternilapilli_positions, int ternilapilli_opponent_choice, int ternilapilli_player_choice)
{
    /*
        Check for winning moves for the AI and Player
        the priority of movement will be
        1. Winning move for AI
        2. Blocking player from winning
        3. Make a random move if neither above condition is true
    */

    int aiWinningMove = ternilapilli_update_possible_winning_moves(ternilapilli_positions, ternilapilli_opponent_choice); // AI check winning moves
    if (aiWinningMove != -1)
    {
        return aiWinningMove;
    }

    int humanWinningMove = ternilapilli_update_possible_winning_moves(ternilapilli_positions, ternilapilli_player_choice); // Human check winning moves
    if (humanWinningMove != -1)
    {
        return humanWinningMove;
    }

    std::vector<int> moves = ternilapilli_update_ai_check_available_moves(ternilapilli_positions);
    if (!moves.empty())
    {
        return moves[rand() % moves.size()];
    }

    return -1;
}
void ternilapilli_update_winning_logic()
{
    /* terni lapilli field positioning
    1 | 2 | 3
    _________
    4 | 5 | 6
    _________
    7 | 8 | 9 */

    // Player win condition
    if ((ternilapilli_positions[0] == ternilapilli_player_choice && ternilapilli_positions[1] == ternilapilli_player_choice && ternilapilli_positions[2] == ternilapilli_player_choice) || // Top row
        (ternilapilli_positions[3] == ternilapilli_player_choice && ternilapilli_positions[4] == ternilapilli_player_choice && ternilapilli_positions[5] == ternilapilli_player_choice) || // Middle row
        (ternilapilli_positions[6] == ternilapilli_player_choice && ternilapilli_positions[7] == ternilapilli_player_choice && ternilapilli_positions[8] == ternilapilli_player_choice) || // Bottom row
        (ternilapilli_positions[0] == ternilapilli_player_choice && ternilapilli_positions[3] == ternilapilli_player_choice && ternilapilli_positions[6] == ternilapilli_player_choice) || // Left column
        (ternilapilli_positions[1] == ternilapilli_player_choice && ternilapilli_positions[4] == ternilapilli_player_choice && ternilapilli_positions[7] == ternilapilli_player_choice) || // Middle column
        (ternilapilli_positions[2] == ternilapilli_player_choice && ternilapilli_positions[5] == ternilapilli_player_choice && ternilapilli_positions[8] == ternilapilli_player_choice) || // Right column
        (ternilapilli_positions[0] == ternilapilli_player_choice && ternilapilli_positions[4] == ternilapilli_player_choice && ternilapilli_positions[8] == ternilapilli_player_choice) || // Diagonal 1
        (ternilapilli_positions[2] == ternilapilli_player_choice && ternilapilli_positions[4] == ternilapilli_player_choice && ternilapilli_positions[6] == ternilapilli_player_choice))   // Diagonal 2
    {
        if (!ternilapilli_game_over)
        {
            std::cout << "Player wins" << std::endl;
            toggle_countdown(ternilapilli_showPopup, ternilapilli_game_over, ternilapilli_winner);
            ternilapilli_game_over = true;
            ternilapilli_winner = 1;
            ternilapilli_opponentsTurn = false;
            Mix_PlayChannel(-1, winGameSound, 0);
            unlocked_achievement(0);
        }
    }

    // Opponent win condition
    if ((ternilapilli_positions[0] == ternilapilli_opponent_choice && ternilapilli_positions[1] == ternilapilli_opponent_choice && ternilapilli_positions[2] == ternilapilli_opponent_choice) || // Top row
        (ternilapilli_positions[3] == ternilapilli_opponent_choice && ternilapilli_positions[4] == ternilapilli_opponent_choice && ternilapilli_positions[5] == ternilapilli_opponent_choice) || // Middle row
        (ternilapilli_positions[6] == ternilapilli_opponent_choice && ternilapilli_positions[7] == ternilapilli_opponent_choice && ternilapilli_positions[8] == ternilapilli_opponent_choice) || // Bottom row
        (ternilapilli_positions[0] == ternilapilli_opponent_choice && ternilapilli_positions[3] == ternilapilli_opponent_choice && ternilapilli_positions[6] == ternilapilli_opponent_choice) || // Left column
        (ternilapilli_positions[1] == ternilapilli_opponent_choice && ternilapilli_positions[4] == ternilapilli_opponent_choice && ternilapilli_positions[7] == ternilapilli_opponent_choice) || // Middle column
        (ternilapilli_positions[2] == ternilapilli_opponent_choice && ternilapilli_positions[5] == ternilapilli_opponent_choice && ternilapilli_positions[8] == ternilapilli_opponent_choice) || // Right column
        (ternilapilli_positions[0] == ternilapilli_opponent_choice && ternilapilli_positions[4] == ternilapilli_opponent_choice && ternilapilli_positions[8] == ternilapilli_opponent_choice) || // Diagonal 1
        (ternilapilli_positions[2] == ternilapilli_opponent_choice && ternilapilli_positions[4] == ternilapilli_opponent_choice && ternilapilli_positions[6] == ternilapilli_opponent_choice))   // Diagonal 2
    {
        if (!ternilapilli_game_over)
        {
            std::cout << "Opponent wins" << std::endl;
            toggle_countdown(ternilapilli_showPopup, ternilapilli_game_over, ternilapilli_winner);
            ternilapilli_game_over = true;
            ternilapilli_winner = 2;
            ternilapilli_opponentsTurn = false;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    // Draw condition
    if (!ternilapilli_showPopup && !ternilapilli_game_over) // If game has started and not over (to not keep cout "it's a draw")
    {
        bool ternilapilli_all_positions_used = true;
        for (int i = 0; i < ternilapilli_positions.size(); ++i)
        {

            if (ternilapilli_positions[i] == 2) // Check for any empty position
            {
                ternilapilli_all_positions_used = false; // no empty positions
                break;
            }
        }

        if (ternilapilli_all_positions_used && ternilapilli_winner != 1 && ternilapilli_winner != 2)
        {
            toggle_countdown(ternilapilli_showPopup, ternilapilli_game_over, ternilapilli_winner);
            std::cout << "It's a Draw." << std::endl;
            ternilapilli_opponentsTurn = false;
            ternilapilli_game_over = true;
            ternilapilli_winner = 3;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    if (ternilapilli_game_over) // Add winner and combination to Frequency rect
    {
        ternilapilli_winner_history.push_back(ternilapilli_winner);

        if (ternilapilli_winner == 1)
        {
            ternilapilli_winner_choice_history.push_back(ternilapilli_player_choice);
        }
        else if (ternilapilli_winner == 2)
        {
            ternilapilli_winner_choice_history.push_back(ternilapilli_opponent_choice);
        }
        else if (ternilapilli_winner == 3)
        {
            ternilapilli_winner_choice_history.push_back(2); // Draw
        }
    }
}
void ternilapilli_update_new_game_reset_variables()
{
    ternilapilli_player_choice = 3;
    ternilapilli_opponent_choice = 3;
    ternilapilli_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    ternilapilli_player_choose_x_or_o = false;
    ternilapilli_winner = 0;
    ternilapilli_game_over = false;
    ternilapilli_opponentsTurn = false;
    ternilapilli_showPopup = true;
    ternilapilli_play_against_human = false;
    ternilapilli_choose_human_or_computer = false;
    ternilapilli_rounds = 0;
    ternilapilli_choose_rounds = false;
    ternilapilli_starting_player_is_x = false;
    ternilapilli_starting_player_chosen = false;
    ternilapilli_timer_set = false;

    // Restart timer - generic function
    timerRunning = false;
    countdownStarted = false;
    countdownSeconds = 300;
}
void ternilapilli_update_is_position_taken(int index)
{
    int gridPosition = index + 1;
    std::string competitor = ternilapilli_opponentsTurn ? "Opponent" : "Player";

    if (ternilapilli_positions[index] == 2)
    {
        int choice = (competitor == "Player") ? ternilapilli_player_choice : ternilapilli_opponent_choice;
        ternilapilli_positions[index] = choice;

        ternilapilli_opponentsTurn = !ternilapilli_opponentsTurn;
    }
    else
    {
        std::cout << competitor << ", Position: " << gridPosition << " is taken. Try again." << std::endl;
    }
}
void ternilapilli_update_ai_logic()
{
    while (ternilapilli_opponentsTurn)
    {
        int aiMoveIndex = ternilapilli_update_find_winning_moves(ternilapilli_positions, ternilapilli_opponent_choice, ternilapilli_player_choice);
        if (aiMoveIndex != -1)
        {
            ternilapilli_update_is_position_taken(aiMoveIndex);
        }
    }
}

// terni lapilli - Handles
void ternilapilli_mouse_handle(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    // ternilapilli - Buttons
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
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.75), static_cast<int>(windowHeight * 0.2), rectWidth, rectHeight};
    SDL_Rect ternilapilli_X_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_Rect ternilapilli_O_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.26), rectWidth, rectHeight};
    SDL_Rect ternilapilli_player_start_first_rect = {static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
    SDL_Rect ternilapilli_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.36), static_cast<int>(windowHeight * 0.40), rectWidth, rectHeight};
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
    if (!ternilapilli_game_over)
    {
        if (!ternilapilli_showPopup) // main game code
        {
            for (int i = 0; i < positionRects.size(); ++i)
            {
                if (SDL_PointInRect(&mousePosition, &positionRects[i]))
                {
                    int gridPosition = i + 1;
                    std::cout << "Player choose Position: " << gridPosition << std::endl;
                    ternilapilli_update_is_position_taken(i);
                }
            }
        }
        else // Popup code
        {
            if (SDL_PointInRect(&mousePosition, &closeButtonRect))
            {
                if (ternilapilli_player_choose_x_or_o && ternilapilli_starting_player_chosen && ternilapilli_choose_human_or_computer && ternilapilli_choose_rounds && ternilapilli_timer_set)
                {
                    std::cout << "You clicked Close Popup window" << std::endl;
                    ternilapilli_showPopup = false;
                    toggle_countdown(ternilapilli_showPopup, ternilapilli_game_over, ternilapilli_winner);
                }
                else
                {
                    std::cout << "Error: Cannot close popup without choosing new game settings" << std::endl;
                }
            }
            else if (SDL_PointInRect(&mousePosition, &ternilapilli_X_rect))
            {
                std::cout << "You choose: X" << std::endl;
                ternilapilli_player_choice = 1;
                ternilapilli_opponent_choice = 0;
                ternilapilli_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ternilapilli_O_rect))
            {
                std::cout << "You choose: O" << std::endl;
                ternilapilli_player_choice = 0;
                ternilapilli_opponent_choice = 1;
                ternilapilli_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ternilapilli_player_start_first_rect))
            {
                std::cout << "You choose: Starting player X" << std::endl;
                if (ternilapilli_player_choice == 1)
                {
                    ternilapilli_opponentsTurn = false;
                }
                else if (ternilapilli_player_choice == 0)
                {
                    ternilapilli_opponentsTurn = true;
                }
                ternilapilli_starting_player_is_x = true;
                ternilapilli_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &ternilapilli_opponent_start_first_rect))
            {
                std::cout << "You choose: Starting player O" << std::endl;
                if (ternilapilli_player_choice == 0)
                {
                    ternilapilli_opponentsTurn = false;
                }
                else if (ternilapilli_player_choice == 1)
                {
                    ternilapilli_opponentsTurn = true;
                }
                ternilapilli_starting_player_is_x = false;
                ;
                ternilapilli_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &humanRect))
            {
                std::cout << "You choose: Play against Human" << std::endl;
                ternilapilli_play_against_human = true;
                ternilapilli_choose_human_or_computer = true;
            }
            else if (SDL_PointInRect(&mousePosition, &computerRect))
            {
                std::cout << "You choose: Play against Computer" << std::endl;
                ternilapilli_play_against_human = false;
                ternilapilli_choose_human_or_computer = true;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds1Rect))
            {
                std::cout << "You choose: Play 1 round" << std::endl;
                ternilapilli_choose_rounds = true;
                ternilapilli_rounds = 1;
                
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds3Rect))
            {
                std::cout << "You choose: Play 3 rounds" << std::endl;
                ternilapilli_choose_rounds = true;
                ternilapilli_rounds = 3;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds5Rect))
            {
                std::cout << "You choose: Play 5 rounds" << std::endl;
                ternilapilli_choose_rounds = true;
                ternilapilli_rounds = 5;
            }
            else if (SDL_PointInRect(&mousePosition, &heartRounds10Rect))
            {
                std::cout << "You choose: Play 10 rounds" << std::endl;
                ternilapilli_choose_rounds = true;
                ternilapilli_rounds = 10;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds10Rect))
            {
                std::cout << "You choose: 10 second timer" << std::endl;
                countdownSeconds = 10;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds30Rect))
            {
                std::cout << "You choose: 30 second timer" << std::endl;
                countdownSeconds = 30;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds60Rect))
            {
                std::cout << "You choose: 60 second timer" << std::endl;
                countdownSeconds = 60;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds300Rect))
            {
                std::cout << "You choose: 5 minutes timer" << std::endl;
                countdownSeconds = 300;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds600Rect))
            {
                std::cout << "You choose: 10 minutes timer" << std::endl;
                countdownSeconds = 600;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds1800Rect))
            {
                std::cout << "You choose: 30 minutes timer" << std::endl;
                countdownSeconds = 1800;
                ternilapilli_timer_set = true;
            }
            else if (SDL_PointInRect(&mousePosition, &seconds3600Rect))
            {
                std::cout << "You choose: 1 hour timer" << std::endl;
                countdownSeconds = 3600;
                ternilapilli_timer_set = true;
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
        ternilapilli_update_new_game_reset_variables();
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
        toggle_countdown(ternilapilli_showPopup, ternilapilli_game_over, ternilapilli_winner);
    }
}
void ternilapilli_keyboard_handle(SDL_Event event)
{
    SDL_Rect ternilapilli_X_rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};
    SDL_Rect ternilapilli_O_rect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};

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

    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.75), static_cast<int>(windowHeight * 0.2), (windowWidth / 20), (windowHeight / 20)};

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
        ternilapilli_SDL_cleanup();
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
            ternilapilli_update_new_game_reset_variables();
        }
        else if (SDL_PointInRect(&selectedPoint, &closeButtonRect))
        {
            std::cout << "You clicked: Close popup" << std::endl;
            ternilapilli_showPopup = false;
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void ternilapilli_gamepad_handle(int button)
{
}

// terni lapilli - SDL Integration
void ternilapilli_SDL_draw()
{
    SDL_RenderCopy(renderer, romeDayBackgroundTexture, NULL, NULL);
    render_text("Ancient Rome - terni lapilli", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.05), 255, 0);

    // HUD Buttons
    draw_timer();
    ternilapilli_draw_settings_buttons();
    draw_win_frequency(ternilapilli_winner_history, ternilapilli_winner_choice_history);
    draw_lives(ternilapilli_rounds);

    ternilapilli_draw_field();

    if (ternilapilli_showPopup)
    {
        ternilapilli_draw_setup_game_popup_window();
    }
    else
    {
        ternilapilli_draw_X_or_O();
    }

    if (ternilapilli_winner == 1)
    {
        render_text("player wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
    else if (ternilapilli_winner == 2)
    {
        render_text("Opponent wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
    else if (ternilapilli_winner == 3)
    {
        render_text("It's a Draw.", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8), 255, 0);
    }
}
void ternilapilli_SDL_update()
{
    ternilapilli_update_winning_logic();
    if (!ternilapilli_play_against_human && ternilapilli_choose_human_or_computer)
    {
        ternilapilli_update_ai_logic();
    }
    ternilapilli_update_winning_logic();
    songTitle = "assets/sounds/music/Old Rome - PianoAmor.mp3";
    load_music(songTitle);
}
void ternilapilli_SDL_cleanup()
{
    // ternilapilli_textures
    SDL_DestroyTexture(ternilapilli_xTexture);
    SDL_DestroyTexture(ternilapilli_oTexture);
    SDL_DestroyTexture(ternilapilli_lineTexture);
}