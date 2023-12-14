#ifndef tic_tac_toe
#define tic_tac_toe

#include <iostream>

// Tic Tac Toe - Textures
SDL_Texture *tic_tac_toe_position_X_texture = nullptr;
SDL_Texture *tic_tac_toe_position_O_texture = nullptr;
SDL_Texture *tic_tac_toe_position_line_texture = nullptr;

// main.cpp - Global variables
extern bool timerRunning;
extern bool countdownStarted;
extern int countdownSeconds;

// Tic Tac Toe - Global variables
int tic_tac_toe_ROWS = 3;
int tic_tac_toe_COLUMNS = 3;
int tic_tac_toe_player_choice = 3;   // 0 = O, 1 = X, 3 = garbage value
int tic_tac_toe_opponent_choice = 3; // 0 = O, 1 = X, 3 = garbage value
std::vector<int> tic_tac_toe_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
int tic_tac_toe_winner = 0; // 1 = player, 2 = opponent, 3 = Draw
bool tic_tac_toe_game_over = false;
bool tic_tac_toe_opponentsTurn = false;
bool tic_tac_toe_showPopup = true;                  // for popup
bool tic_tac_toe_player_choose_x_or_o = false;      // for popup - Choose X or O
int tic_tac_toe_choose_lives = 0;                   // For popup - choose rounds | lives
bool tic_tac_toe_starting_player_chosen = false;    // For popup - starting player
bool tic_tac_toe_starting_player_is_x = false;      // For popup - starting player
bool tic_tac_toe_play_against_human = false;        // For popup - play against human or computer
std::vector<int> tic_tac_toe_winner_history;        // for winners frequency rect
std::vector<int> tic_tac_toe_winner_choice_history; // for winners frequency rect

// FUNCTION PROTOTYPES - Functions called from main.cpp
SDL_Texture *load_texture(const char *path, const char *name);                                      // In main.cpp
void render_text(const std::string &text, int x, int y);                                            // In main.cpp
void draw_timer();                                                                                  // In main.cpp
void draw_lives(int lives);                                                                         // In main.cpp
void draw_win_frequency(const std::vector<int> &winners, const std::vector<int> &winnersChoice);    // In main.cpp
void toggle_countdown();                                                                            // In main.cpp
void tic_tac_toe_SDL_cleanup();                                                                     // for keyboard_handle ESC = quit
void exit_SDL();                                                                                     // for keyboard_handle ESC = quit

// Tic Tac Toe - Draws
void tic_tac_toe_load_textures()
{
    tic_tac_toe_position_X_texture = load_texture("assets/graphics/games/tic_tac_toe/buttons/tic_tac_toe_X_texture.png", "Tic Tac Toe X image");
    tic_tac_toe_position_O_texture = load_texture("assets/graphics/games/tic_tac_toe/buttons/tic_tac_toe_O_texture.png", "Tic Tac Toe O image");
    tic_tac_toe_position_line_texture = load_texture("assets/graphics/games/tic_tac_toe/tic_tac_toe_line_texture.png", "Tic Tac Toe Line image");
    romeDayBackgroundTexture = load_texture("assets/graphics/backgrounds/rome-day.jpg", "Rome Day Background");
}
void tic_tac_toe_draw_field()
{
    // Play area
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Set the blend mode to enable transparency
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 64);       // RGB value: light grey, last digit (Alpha value = 256 / 4) (75% transparency)
    SDL_Rect tic_tac_toe_rect = {(windowWidth / 4), (windowHeight / 4), (windowWidth / 2), (windowHeight / 2)};
    SDL_RenderFillRect(renderer, &tic_tac_toe_rect);

    // Grid lines
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB value: Black

    // Calculate the number of squares inside the Tic Tac Toe rectangle
    int innertic_tac_toe_COLUMNS = tic_tac_toe_COLUMNS;
    int innertic_tac_toe_ROWS = tic_tac_toe_ROWS;

    // Calculate the size of each square
    int squareWidth = tic_tac_toe_rect.w / tic_tac_toe_COLUMNS;
    int squareHeight = tic_tac_toe_rect.h / tic_tac_toe_ROWS;

    // Draw vertical lines within the Tic Tac Toe rectangle
    for (int i = 1; i < innertic_tac_toe_COLUMNS; ++i)
    {
        SDL_RenderDrawLine(renderer, tic_tac_toe_rect.x + i * squareWidth, tic_tac_toe_rect.y, tic_tac_toe_rect.x + i * squareWidth, tic_tac_toe_rect.y + tic_tac_toe_rect.h);
    }

    // Draw horizontal lines within the Tic Tac Toe rectangle
    for (int i = 1; i < innertic_tac_toe_ROWS; ++i)
    {
        SDL_RenderDrawLine(renderer, tic_tac_toe_rect.x, tic_tac_toe_rect.y + i * squareHeight, tic_tac_toe_rect.x + tic_tac_toe_rect.w, tic_tac_toe_rect.y + i * squareHeight);
    }
}
void tic_tac_toe_draw_setup_game_popup_window()
{
    // DONT FORGET TO UPDATE mouse handles rects within world-games.cpp

    // Draw popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect borderRect = {(windowWidth / 4) - 2, (windowHeight / 4) - 2, (windowWidth / 2) + 4, (windowHeight / 2) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw popup
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255); // Popup color lime green
    SDL_Rect popupRect = {(windowWidth / 4), (windowHeight / 4), (windowWidth / 2), (windowHeight / 2)};
    SDL_RenderFillRect(renderer, &popupRect);

    // Draw a close button
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.69), static_cast<int>(windowHeight * 0.28), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &closeButtonRect);

    /*

        Choose X or O

    */
    if (!tic_tac_toe_player_choose_x_or_o)
    {
        render_text("Select Crosses (X) or Naughts (0)", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26));
    }
    else // after picking choice advise player what they choose
    {
        if (tic_tac_toe_player_choice == 0)
        {
            render_text("You choose: 0", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26));
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
        else
        {
            render_text("You choose: X", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.26));
            // highlight selected rect, and in if condition dont hide, so player can repick.
        }
    }

    // X button
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect XborderLineRect = {static_cast<int>(windowWidth * 0.32) - 4, static_cast<int>(windowHeight * 0.34) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &XborderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect XborderRect = {static_cast<int>(windowWidth * 0.32) - 2, static_cast<int>(windowHeight * 0.34) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &XborderRect);

    SDL_Rect tic_tac_toe_X_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.34), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &tic_tac_toe_X_rect);

    // O button
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect OborderLineRect = {static_cast<int>(windowWidth * 0.42) - 4, static_cast<int>(windowHeight * 0.34) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &OborderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect OborderRect = {static_cast<int>(windowWidth * 0.42) - 2, static_cast<int>(windowHeight * 0.34) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &OborderRect);

    SDL_Rect tic_tac_toe_O_rect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.34), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_position_O_texture, nullptr, &tic_tac_toe_O_rect);

    if (!tic_tac_toe_starting_player_chosen)
    {
        render_text("Starting player", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.44));
    }
    else
    {
        if (!tic_tac_toe_starting_player_is_x)
        {
            render_text("You choose: Starting player O", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.44));
        }
        else if (tic_tac_toe_starting_player_is_x)
        {
            render_text("You choose: Starting player X", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.44));
        }
    }

    // player starts first
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect startingPlayerBorderLineRect = {static_cast<int>(windowWidth * 0.32) - 4, static_cast<int>(windowHeight * 0.54) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &startingPlayerBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect startingPlayerBorderRect = {static_cast<int>(windowWidth * 0.32) - 2, static_cast<int>(windowHeight * 0.54) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &startingPlayerBorderRect);

    SDL_Rect tic_tac_toe_player_start_first_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &tic_tac_toe_player_start_first_rect);

    // Opponent starts first
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect startingOpponentBorderLineRect = {static_cast<int>(windowWidth * 0.42) - 4, static_cast<int>(windowHeight * 0.54) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &startingOpponentBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect startingOpponentBorderRect = {static_cast<int>(windowWidth * 0.42) - 2, static_cast<int>(windowHeight * 0.54) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &startingOpponentBorderRect);

    SDL_Rect tic_tac_toe_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_position_O_texture, nullptr, &tic_tac_toe_opponent_start_first_rect);

    if (!tic_tac_toe_play_against_human)
    {
        render_text("Play against", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.62));
    }
    else
    {
        if (tic_tac_toe_player_choice == 0)
        {
            render_text("You choose: Play against Human", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.62));
        }
        else
        {
            render_text("You choose: Play against Computer", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.62));
        }
    }

    // player starts first
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect humanBorderLineRect = {static_cast<int>(windowWidth * 0.32) - 4, static_cast<int>(windowHeight * 0.72) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &humanBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect humanBorderRect = {static_cast<int>(windowWidth * 0.32) - 2, static_cast<int>(windowHeight * 0.72) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &humanBorderRect);

    SDL_Rect humanRect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, humanTexture, nullptr, &humanRect);

    // Opponent starts first
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect computerBorderLineRect = {static_cast<int>(windowWidth * 0.42) - 4, static_cast<int>(windowHeight * 0.72) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &computerBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect computerBorderRect = {static_cast<int>(windowWidth * 0.42) - 2, static_cast<int>(windowHeight * 0.72) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &computerBorderRect);

    SDL_Rect computerRect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.72), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, computerTexture, nullptr, &computerRect);

    /*

    render_text("Rounds | Lives", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.72));

    // 1 Round
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect startingPlayerBorderLineRect = {static_cast<int>(windowWidth * 0.32) - 4, static_cast<int>(windowHeight * 0.54) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &startingPlayerBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect startingPlayerBorderRect = {static_cast<int>(windowWidth * 0.32) - 2, static_cast<int>(windowHeight * 0.54) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &startingPlayerBorderRect);

    SDL_Rect tic_tac_toe_player_start_first_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_starting_player_texture, nullptr, &tic_tac_toe_player_start_first_rect);
    */

    /*
    render_text("Timer", static_cast<int>(windowWidth * 0.26), static_cast<int>(windowHeight * 0.44));

    // 2 seconds
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect startingPlayerBorderLineRect = {static_cast<int>(windowWidth * 0.32) - 4, static_cast<int>(windowHeight * 0.54) - 4, rectWidth + 8, rectHeight + 8};
    SDL_RenderFillRect(renderer, &startingPlayerBorderLineRect);

    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect startingPlayerBorderRect = {static_cast<int>(windowWidth * 0.32) - 2, static_cast<int>(windowHeight * 0.54) - 2, rectWidth + 4, rectHeight + 4};
    SDL_RenderFillRect(renderer, &startingPlayerBorderRect);

    SDL_Rect tic_tac_toe_player_start_first_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_RenderCopy(renderer, tic_tac_toe_starting_player_texture, nullptr, &tic_tac_toe_player_start_first_rect);
    */
}
void tic_tac_toe_draw_X_or_O()
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
    for (size_t i = 0; i < tic_tac_toe_positions.size(); ++i)
    {
        if (tic_tac_toe_positions[i] == 0)
        {
            SDL_RenderCopy(renderer, tic_tac_toe_position_O_texture, nullptr, &positionRects[i]);
        }
        else if (tic_tac_toe_positions[i] == 1)
        {
            SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &positionRects[i]);
        }
        else if (tic_tac_toe_positions[i] == 2)
        {
            // Do nothing for position 2
        }
    }
}
void tic_tac_toe_draw_settings_buttons()
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
std::vector<int> tic_tac_toe_update_ai_check_available_moves(std::vector<int> &tic_tac_toe_positions)
{
    /*
        A vector function that accepts the 9 int vector postitions
        finds any available spaces and returns them;
    */
    std::vector<int> moves;
    for (int i = 0; i < tic_tac_toe_positions.size(); ++i)
    {
        if (tic_tac_toe_positions[i] == 2)
        {
            moves.push_back(i);
        }
    }
    return moves;
}
int tic_tac_toe_update_possible_winning_moves(std::vector<int> tic_tac_toe_positions, int player)
{
    for (int i = 0; i < tic_tac_toe_positions.size(); ++i)
    {
        if (tic_tac_toe_positions[i] == 2)
        {
            std::vector<int> testBoard = tic_tac_toe_positions;
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
int tic_tac_toe_update_find_winning_moves(std::vector<int> tic_tac_toe_positions, int tic_tac_toe_opponent_choice, int tic_tac_toe_player_choice)
{
    /*
        Check for winning moves for the AI and Player
        the priority of movement will be
        1. Winning move for AI
        2. Blocking player from winning
        3. Make a random move if neither above condition is true
    */

    int aiWinningMove = tic_tac_toe_update_possible_winning_moves(tic_tac_toe_positions, tic_tac_toe_opponent_choice); // AI check winning moves
    if (aiWinningMove != -1)
    {
        return aiWinningMove;
    }

    int humanWinningMove = tic_tac_toe_update_possible_winning_moves(tic_tac_toe_positions, tic_tac_toe_player_choice); // Human check winning moves
    if (humanWinningMove != -1)
    {
        return humanWinningMove;
    }

    std::vector<int> moves = tic_tac_toe_update_ai_check_available_moves(tic_tac_toe_positions);
    if (!moves.empty())
    {
        return moves[rand() % moves.size()];
    }

    return -1;
}
void tic_tac_toe_update_winning_logic()
{
    /* Tic Tac Toe field positioning
    1 | 2 | 3
    _________
    4 | 5 | 6
    _________
    7 | 8 | 9 */

    // Player win condition
    if ((tic_tac_toe_positions[0] == tic_tac_toe_player_choice && tic_tac_toe_positions[1] == tic_tac_toe_player_choice && tic_tac_toe_positions[2] == tic_tac_toe_player_choice) || // Top row
        (tic_tac_toe_positions[3] == tic_tac_toe_player_choice && tic_tac_toe_positions[4] == tic_tac_toe_player_choice && tic_tac_toe_positions[5] == tic_tac_toe_player_choice) || // Middle row
        (tic_tac_toe_positions[6] == tic_tac_toe_player_choice && tic_tac_toe_positions[7] == tic_tac_toe_player_choice && tic_tac_toe_positions[8] == tic_tac_toe_player_choice) || // Bottom row
        (tic_tac_toe_positions[0] == tic_tac_toe_player_choice && tic_tac_toe_positions[3] == tic_tac_toe_player_choice && tic_tac_toe_positions[6] == tic_tac_toe_player_choice) || // Left column
        (tic_tac_toe_positions[1] == tic_tac_toe_player_choice && tic_tac_toe_positions[4] == tic_tac_toe_player_choice && tic_tac_toe_positions[7] == tic_tac_toe_player_choice) || // Middle column
        (tic_tac_toe_positions[2] == tic_tac_toe_player_choice && tic_tac_toe_positions[5] == tic_tac_toe_player_choice && tic_tac_toe_positions[8] == tic_tac_toe_player_choice) || // Right column
        (tic_tac_toe_positions[0] == tic_tac_toe_player_choice && tic_tac_toe_positions[4] == tic_tac_toe_player_choice && tic_tac_toe_positions[8] == tic_tac_toe_player_choice) || // Diagonal 1
        (tic_tac_toe_positions[2] == tic_tac_toe_player_choice && tic_tac_toe_positions[4] == tic_tac_toe_player_choice && tic_tac_toe_positions[6] == tic_tac_toe_player_choice))   // Diagonal 2
    {
        if (!tic_tac_toe_game_over)
        {
            std::cout << "Player wins" << std::endl;
            toggle_countdown();
            tic_tac_toe_game_over = true;
            tic_tac_toe_winner = 1;
            tic_tac_toe_opponentsTurn = false;
            Mix_PlayChannel(-1, winGameSound, 0);
        }
    }

    // Opponent win condition
    if ((tic_tac_toe_positions[0] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[1] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[2] == tic_tac_toe_opponent_choice) || // Top row
        (tic_tac_toe_positions[3] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[4] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[5] == tic_tac_toe_opponent_choice) || // Middle row
        (tic_tac_toe_positions[6] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[7] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[8] == tic_tac_toe_opponent_choice) || // Bottom row
        (tic_tac_toe_positions[0] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[3] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[6] == tic_tac_toe_opponent_choice) || // Left column
        (tic_tac_toe_positions[1] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[4] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[7] == tic_tac_toe_opponent_choice) || // Middle column
        (tic_tac_toe_positions[2] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[5] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[8] == tic_tac_toe_opponent_choice) || // Right column
        (tic_tac_toe_positions[0] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[4] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[8] == tic_tac_toe_opponent_choice) || // Diagonal 1
        (tic_tac_toe_positions[2] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[4] == tic_tac_toe_opponent_choice && tic_tac_toe_positions[6] == tic_tac_toe_opponent_choice))   // Diagonal 2
    {
        if (!tic_tac_toe_game_over)
        {
            std::cout << "Opponent wins" << std::endl;
            toggle_countdown();
            tic_tac_toe_game_over = true;
            tic_tac_toe_winner = 2;
            tic_tac_toe_opponentsTurn = false;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    // Draw condition
    if (!tic_tac_toe_showPopup && !tic_tac_toe_game_over) // If game has started and not over (to not keep cout "it's a draw")
    {
        bool tic_tac_toe_all_positions_used = true;
        for (int i = 0; i < tic_tac_toe_positions.size(); ++i)
        {

            if (tic_tac_toe_positions[i] == 2) // Check for any empty position
            {
                tic_tac_toe_all_positions_used = false; // no empty positions
                break;
            }
        }

        if (tic_tac_toe_all_positions_used && tic_tac_toe_winner != 1 && tic_tac_toe_winner != 2)
        {
            toggle_countdown();
            std::cout << "It's a Draw." << std::endl;
            tic_tac_toe_opponentsTurn = false;
            tic_tac_toe_game_over = true;
            tic_tac_toe_winner = 3;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    if (tic_tac_toe_game_over) // Add winner and combination to Frequency rect
    {
        tic_tac_toe_winner_history.push_back(tic_tac_toe_winner);

        if (tic_tac_toe_winner == 1)
        {
            tic_tac_toe_winner_choice_history.push_back(tic_tac_toe_player_choice);
        }
        else if (tic_tac_toe_winner == 2)
        {
            tic_tac_toe_winner_choice_history.push_back(tic_tac_toe_opponent_choice);
        }
        else if (tic_tac_toe_winner == 3)
        {
            tic_tac_toe_winner_choice_history.push_back(2); // Draw
        }
    }
}
void tic_tac_toe_update_new_game_reset_variables()
{
    tic_tac_toe_player_choice = 3;
    tic_tac_toe_opponent_choice = 3;
    tic_tac_toe_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    tic_tac_toe_player_choose_x_or_o = false;
    tic_tac_toe_winner = 0;
    tic_tac_toe_game_over = false;
    tic_tac_toe_opponentsTurn = false;
    tic_tac_toe_showPopup = true;
    tic_tac_toe_play_against_human = false;
    tic_tac_toe_choose_lives = 0;
    tic_tac_toe_starting_player_is_x = false;
    tic_tac_toe_starting_player_chosen = false;

    // Restart timer - generic function
    timerRunning = false;
    countdownStarted = false;
    countdownSeconds = 20;
}
void tic_tac_toe_update_is_position_taken(int index)
{
    int gridPosition = index + 1;
    std::string competitor = tic_tac_toe_opponentsTurn ? "Opponent" : "Player";

    if (tic_tac_toe_positions[index] == 2)
    {
        int choice = (competitor == "Player") ? tic_tac_toe_player_choice : tic_tac_toe_opponent_choice;
        tic_tac_toe_positions[index] = choice;

        tic_tac_toe_opponentsTurn = !tic_tac_toe_opponentsTurn;
    }
    else
    {
        std::cout << competitor << ", Position: " << gridPosition << " is taken. Try again." << std::endl;
    }
}
void tic_tac_toe_update_ai_logic()
{
    while (tic_tac_toe_opponentsTurn)
    {
        int aiMoveIndex = tic_tac_toe_update_find_winning_moves(tic_tac_toe_positions, tic_tac_toe_opponent_choice, tic_tac_toe_player_choice);
        if (aiMoveIndex != -1)
        {
            tic_tac_toe_update_is_position_taken(aiMoveIndex);
        }
    }
}

// Tic Tac Toe - Handles
void tic_tac_toe_mouse_handle(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

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

    SDL_Rect helpRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect restartRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect worldMapRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_Rect timerRect = {static_cast<int>(windowWidth * 0.05), static_cast<int>(windowHeight * 0.05), (windowWidth / 4), (windowHeight / 8)};

    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.69), static_cast<int>(windowHeight * 0.28), rectWidth, rectHeight};

    SDL_Rect tic_tac_toe_X_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.34), rectWidth, rectHeight};
    SDL_Rect tic_tac_toe_O_rect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.34), rectWidth, rectHeight};
    SDL_Rect tic_tac_toe_player_start_first_rect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_Rect tic_tac_toe_opponent_start_first_rect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.54), rectWidth, rectHeight};
    SDL_Rect humanRect = {static_cast<int>(windowWidth * 0.32), static_cast<int>(windowHeight * 0.74), rectWidth, rectHeight};
    SDL_Rect computerRect = {static_cast<int>(windowWidth * 0.42), static_cast<int>(windowHeight * 0.74), rectWidth, rectHeight};

    // Choose X or O to start
    if (!tic_tac_toe_game_over)
    {
        if (!tic_tac_toe_showPopup) // main game code
        {
            for (int i = 0; i < positionRects.size(); ++i)
            {
                if (SDL_PointInRect(&mousePosition, &positionRects[i]))
                {
                    int gridPosition = i + 1;
                    std::cout << "Player choose Position: " << gridPosition << std::endl;
                    tic_tac_toe_update_is_position_taken(i);
                }
            }
        }
        else // Popup code
        {
            if (SDL_PointInRect(&mousePosition, &closeButtonRect))
            {
                if (tic_tac_toe_player_choose_x_or_o && tic_tac_toe_starting_player_chosen)
                {
                    std::cout << "You clicked Close Popup window" << std::endl;
                    tic_tac_toe_showPopup = false;
                    toggle_countdown();
                }
                else
                {
                    std::cout << "Error: Cannot close popup without choosing X or O." << std::endl;
                }
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_X_rect))
            {
                std::cout << "You choose: X" << std::endl;
                tic_tac_toe_player_choice = 1;
                tic_tac_toe_opponent_choice = 0;
                tic_tac_toe_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_O_rect))
            {
                std::cout << "You choose: O" << std::endl;
                tic_tac_toe_player_choice = 0;
                tic_tac_toe_opponent_choice = 1;
                tic_tac_toe_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_player_start_first_rect))
            {
                std::cout << "You choose: Starting player X" << std::endl;
                if (tic_tac_toe_player_choice == 1)
                {
                    tic_tac_toe_opponentsTurn = false;
                }
                else if (tic_tac_toe_player_choice == 0)
                { 
                    tic_tac_toe_opponentsTurn = true;
                }
                tic_tac_toe_starting_player_is_x = true;
                tic_tac_toe_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_opponent_start_first_rect))
            {
                std::cout << "You choose: Starting player O" << std::endl;
                if (tic_tac_toe_player_choice == 0)
                {            
                    tic_tac_toe_opponentsTurn = false;              
                }
                else if (tic_tac_toe_player_choice == 1)
                {
                    tic_tac_toe_opponentsTurn = true;
                }
                tic_tac_toe_starting_player_is_x = false;;
                tic_tac_toe_starting_player_chosen = true;
            }
            else if (SDL_PointInRect(&mousePosition, &humanRect))
            {
                std::cout << "You choose: Play against Human" << std::endl;
            }
            else if (SDL_PointInRect(&mousePosition, &computerRect))
            {
                std::cout << "You choose: Play against Computer" << std::endl;
            }
        }
    }
    // HUD Buttons
    if (SDL_PointInRect(&mousePosition, &helpRect))
    {
        lastScene = scene;
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (SDL_PointInRect(&mousePosition, &restartRect))
    {
        std::cout << "You clicked Restart" << std::endl;
        tic_tac_toe_update_new_game_reset_variables();
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
        scene = 6;
    }
    else if (SDL_PointInRect(&mousePosition, &timerRect))
    {
        std::cout << "You clicked: Restart Timer" << std::endl;
        toggle_countdown();
    }
}
void tic_tac_toe_keyboard_handle(SDL_Event event)
{
    SDL_Rect tic_tac_toe_X_rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};
    SDL_Rect tic_tac_toe_O_rect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};

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
        tic_tac_toe_SDL_cleanup();
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
            tic_tac_toe_update_new_game_reset_variables();
        }
        else if (SDL_PointInRect(&selectedPoint, &closeButtonRect))
        {
            std::cout << "You clicked: Close popup" << std::endl;
            tic_tac_toe_showPopup = false;
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void tic_tac_toe_gamepad_handle(int button)
{
}

// Tic Tac Toe - SDL Integration
void tic_tac_toe_SDL_draw()
{
    SDL_RenderCopy(renderer, romeDayBackgroundTexture, NULL, NULL);
    render_text("Ancient Rome - Tic Tac Toe", static_cast<int>(windowWidth * 0.37), static_cast<int>(windowHeight * 0.1));

    // HUD Buttons
    draw_timer();
    tic_tac_toe_draw_settings_buttons();
    draw_win_frequency(tic_tac_toe_winner_history, tic_tac_toe_winner_choice_history);
    draw_lives(tic_tac_toe_choose_lives);

    tic_tac_toe_draw_field();

    if (tic_tac_toe_showPopup)
    {
        tic_tac_toe_draw_setup_game_popup_window();
    }
    else
    {
        tic_tac_toe_draw_X_or_O();
    }

    if (tic_tac_toe_winner == 1)
    {
        render_text("player wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8));
    }
    else if (tic_tac_toe_winner == 2)
    {
        render_text("Opponent wins", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8));
    }
    else if (tic_tac_toe_winner == 3)
    {
        render_text("It's a Draw.", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.8));
    }
}
void tic_tac_toe_SDL_update()
{
    tic_tac_toe_update_winning_logic();
    tic_tac_toe_update_ai_logic();
    tic_tac_toe_update_winning_logic();
    songTitle = "assets/sounds/music/Old Rome - PianoAmor.mp3";
    load_music(songTitle);
}
void tic_tac_toe_SDL_cleanup()
{
    // tic_tac_toe_textures
    SDL_DestroyTexture(tic_tac_toe_position_X_texture);
    SDL_DestroyTexture(tic_tac_toe_position_O_texture);
    SDL_DestroyTexture(tic_tac_toe_position_line_texture);
}


#endif
