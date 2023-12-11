#ifndef tic_tac_toe
#define tic_tac_toe

#include <iostream>

// tic_tac_toe_textures
SDL_Texture *tic_tac_toe_position_X_texture = nullptr;
SDL_Texture *tic_tac_toe_position_O_texture = nullptr;
SDL_Texture *tic_tac_toe_position_line_texture = nullptr;

// Game - Tic Tac Toe Variables
int tic_tac_toe_ROWS = 3;
int tic_tac_toe_COLUMNS = 3;
int tic_tac_toe_player_choice = 3;
int tic_tac_toe_opponent_choice = 3;
std::vector<int> tic_tac_toe_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
bool tic_tac_toe_player_choose_x_or_o = false;
int tic_tac_toe_winner = 0; // 1 = player, 2 = opponent, 3 = Draw
bool tic_tac_toe_game_over = false;
bool tic_tac_toe_opponentsTurn = false;
bool tic_tac_toe_showPopup = true;
bool tic_tac_toe_all_positions_available = true;

// FUNCTION PROTOTYPES
SDL_Texture *load_texture(const char *path, const char *name);
void render_text(const std::string &text, int x, int y);

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
void tic_tac_toe_draw_choose_x_or_o_popup_window()
{
    // Draw popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect borderRect = {(windowWidth / 3) - 2, (windowHeight / 3) - 2, (windowWidth / 3) + 4, (windowHeight / 3) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw popup
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255); // Popup color lime green
    SDL_Rect popupRect = {(windowWidth / 3), (windowHeight / 3), (windowWidth / 3), (windowHeight / 3)};
    SDL_RenderFillRect(renderer, &popupRect);

    // Draw a close button
    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.35), (windowWidth / 22), (windowHeight / 22)};
    SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &closeButtonRect);

    // Render text and buttons for player to pick choice
    if (tic_tac_toe_player_choose_x_or_o == false)
    {
        render_text("Select Crosses (X) or Naughts (0)", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.4));

        SDL_Rect tic_tac_toe_X_rect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};
        SDL_Rect tic_tac_toe_O_rect = {static_cast<int>(windowWidth * 0.5), static_cast<int>(windowHeight * 0.5), (windowWidth / 10), (windowHeight / 10)};
        SDL_RenderCopy(renderer, tic_tac_toe_position_X_texture, nullptr, &tic_tac_toe_X_rect);
        SDL_RenderCopy(renderer, tic_tac_toe_position_O_texture, nullptr, &tic_tac_toe_O_rect);
    }
    else // after picking choice advise player what they choose
    {
        if (tic_tac_toe_player_choice == 0)
        {
            render_text("You choose: 0", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.4));
        }
        else
        {
            render_text("You choose: X", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.4));
        }
        render_text("Press top right close "
                    "X"
                    " button to start",
                    static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.5));
    }
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

void tic_tac_toe_new_game_reset_variables()
{
    tic_tac_toe_player_choice = 3;
    tic_tac_toe_opponent_choice = 3;
    tic_tac_toe_positions = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    tic_tac_toe_player_choose_x_or_o = false;
    tic_tac_toe_winner = 0;
    tic_tac_toe_game_over = false;
    tic_tac_toe_opponentsTurn = false;
    tic_tac_toe_showPopup = true;
    tic_tac_toe_all_positions_available = true;
}

void tic_tac_toe_is_position_taken(int index)
{
    int gridPosition = index + 1;
    std::string competitor = tic_tac_toe_opponentsTurn ? "Opponent" : "Player";

    if (tic_tac_toe_positions[index] == 2)
    {
        int choice = (competitor == "Player") ? tic_tac_toe_player_choice : tic_tac_toe_opponent_choice;
        tic_tac_toe_positions[index] = choice;

        if (!tic_tac_toe_game_over)
        {
            tic_tac_toe_opponentsTurn = !tic_tac_toe_opponentsTurn;
            if (tic_tac_toe_opponentsTurn)
            {
                SDL_Delay(1000);
            }
        }
    }
    else
    {
        std::cout << competitor<< ", Position: " << gridPosition << " is taken. Try again." << std::endl;
    }
}

void tic_tac_toe_mouse_handle(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

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

    SDL_Rect helpRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.3), rectWidth, rectHeight};
    SDL_Rect restartRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.4), rectWidth, rectHeight};
    SDL_Rect settingsRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.5), rectWidth, rectHeight};
    SDL_Rect worldMapRect = {static_cast<int>(windowWidth * 0.9), static_cast<int>(windowHeight * 0.6), rectWidth, rectHeight};

    SDL_Rect closeButtonRect = {static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.35), (windowWidth / 20), (windowHeight / 20)};

    // Settings Buttons
    if (SDL_PointInRect(&mousePosition, &helpRect))
    {
        lastScene = scene;
        std::cout << "You clicked Help" << std::endl;
        scene = 5;
    }
    else if (SDL_PointInRect(&mousePosition, &restartRect))
    {
        std::cout << "You clicked Restart" << std::endl;
        tic_tac_toe_new_game_reset_variables();
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

    // Choose X or O to start
    if (!tic_tac_toe_game_over)
    {
        // After choosing X or O, drawing on grid
        if (!tic_tac_toe_showPopup) // main game code
        {
            for (int i = 0; i < positionRects.size(); ++i)
            {
                if (SDL_PointInRect(&mousePosition, &positionRects[i]))
                {
                    int gridPosition = i + 1;
                    std::cout << "Player choose Position: " << gridPosition << std::endl;
                    tic_tac_toe_is_position_taken(i);
                }
            }
        }
        else // Popup clicks
        {
            if (SDL_PointInRect(&mousePosition, &closeButtonRect))
            {
                if (tic_tac_toe_player_choose_x_or_o)
                {
                    std::cout << "You clicked Close Popup window" << std::endl;
                    tic_tac_toe_showPopup = false;
                }
                else
                {
                    std::cout << "Erro: Cannot close popup without choosing X or O." << std::endl;
                }
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_X_rect))
            {
                std::cout << "You choose X" << std::endl;
                tic_tac_toe_player_choice = 1;
                tic_tac_toe_opponent_choice = 0;
                tic_tac_toe_player_choose_x_or_o = true;
            }
            else if (SDL_PointInRect(&mousePosition, &tic_tac_toe_O_rect))
            {
                std::cout << "You choose O" << std::endl;
                tic_tac_toe_player_choice = 0;
                tic_tac_toe_opponent_choice = 1;
                tic_tac_toe_player_choose_x_or_o = true;
            }
        }
    }
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
            tic_tac_toe_game_over = true;
            tic_tac_toe_winner = 2;
            tic_tac_toe_opponentsTurn = false;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }

    // Draw condition
    if (!tic_tac_toe_showPopup) // If game has started
    {
        for (int i = 0; i < tic_tac_toe_positions.size(); ++i)
        {
            if (tic_tac_toe_positions[i] == 2) // Check for any empty position
            {
                tic_tac_toe_all_positions_available = false; // no empty positions
                break;
            }
        }

        if (tic_tac_toe_all_positions_available && tic_tac_toe_winner != 0 && tic_tac_toe_winner != 1)
        {
            std::cout << "It's a Draw." << std::endl;
            tic_tac_toe_game_over = true;
            tic_tac_toe_winner = 3;
            tic_tac_toe_opponentsTurn = false;
            Mix_PlayChannel(-1, loseGameSound, 0);
        }
    }
}

void tic_tac_toe_update_ai_logic()
{
    while (tic_tac_toe_opponentsTurn)
    {
        int i = rand() % 9; // look for 0 - 8 only as tic_tac_toe_positions vector is from 0 - 8 (9 values)
        int gridPosition = i + 1;
        std::cout << "AI choose Position: " << gridPosition << std::endl;
        tic_tac_toe_is_position_taken(i);
    }
}

void tic_tac_toe_SDL_draw()
{
    SDL_RenderCopy(renderer, romeDayBackgroundTexture, NULL, NULL);
    render_text("Ancient Rome - Tic Tac Toe", static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.1));
    tic_tac_toe_draw_field();
    tic_tac_toe_draw_X_or_O();
    if (tic_tac_toe_showPopup)
    {
        tic_tac_toe_draw_choose_x_or_o_popup_window();
    }
    else
    {
        tic_tac_toe_draw_X_or_O();
    }
    tic_tac_toe_draw_settings_buttons();

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

void tic_tac_toe_cleanup()
{
    // tic_tac_toe_textures
    SDL_DestroyTexture(tic_tac_toe_position_X_texture);
    SDL_DestroyTexture(tic_tac_toe_position_O_texture);
    SDL_DestroyTexture(tic_tac_toe_position_line_texture);
}

#endif
