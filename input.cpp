/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration/Definition/Implementation file combined
    License: MIT License
    Description: Test Development environment
*/

#include "headers/global_variables.hpp"

/*  TO DO
    1. Add mouse handle 11 privacy policy popup onclick code to keyboard and controller
    Add code for all the keyboard/gamepad handles
    2. Fix button class
            * keyboard highlight and select
            * Gamepad highlight/select
    3. Fix Input class
        SDL function to call platforms native virtual keyboard
        Profanity filter
    4. Read Privacy notice from .txt file in popup window
    5. In new_game()
    load_game() loads username from txt file if not ignore
    !username.empty() - scene = 25;
    else continue;
    on submit.onclick() save username to txt file
    6. Update on World Games
*/

// SDL2 library
SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Event event;
SDL_GameController *controller;

// SDL Image
SDL_Texture *splashScreenTexture = nullptr;
SDL_Texture *rockpaperscissorsRulesTexture = nullptr;

// Global variables automatically destroyed at end of main() no need to manual destroy
// Scene 11
Custom_SDL_Button scene11submitUsernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11registerButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11acceptButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11denyButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene11fontScaleButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 12
Custom_SDL_Button scene12submitEmailPasswordButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene12backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 13
Custom_SDL_Button scene13submitLoginButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene13backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 14
Custom_SDL_Button scene14hostGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14joinGameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14searchGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14searchFriendsGamesButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14refreshButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button scene14backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
// Scene 25
Custom_SDL_Button scene25backusernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

// For SDL_Custom_button find_nearest() to find nearest button through kb handle arrow direction keys for GUI navigation
std::vector<Custom_SDL_Button *> scene1buttons;
std::vector<Custom_SDL_Button *> scene2buttons;
std::vector<Custom_SDL_Button *> scene3buttons;
std::vector<Custom_SDL_Button *> scene4buttons;
std::vector<Custom_SDL_Button *> scene5buttons;
std::vector<Custom_SDL_Button *> scene6buttons;
std::vector<Custom_SDL_Button *> scene7buttons;
std::vector<Custom_SDL_Button *> scene8buttons;
std::vector<Custom_SDL_Button *> scene9buttons;
std::vector<Custom_SDL_Button *> scene10buttons;
std::vector<Custom_SDL_Button *> scene11buttons;
std::vector<Custom_SDL_Button *> scene12buttons;
std::vector<Custom_SDL_Button *> scene13buttons;
std::vector<Custom_SDL_Button *> scene14buttons;
std::vector<Custom_SDL_Button *> scene15buttons;
std::vector<Custom_SDL_Button *> scene16buttons;
std::vector<Custom_SDL_Button *> scene17buttons;
std::vector<Custom_SDL_Button *> scene18buttons;
std::vector<Custom_SDL_Button *> scene19buttons;
std::vector<Custom_SDL_Button *> scene20buttons;
std::vector<Custom_SDL_Button *> scene21buttons;
std::vector<Custom_SDL_Button *> scene22buttons;
std::vector<Custom_SDL_Button *> scene23buttons;
std::vector<Custom_SDL_Button *> scene24buttons;
std::vector<Custom_SDL_Button *> scene25buttons;
std::vector<Custom_SDL_Button *> scene26buttons;
std::vector<Custom_SDL_Button *> scene27buttons;
std::vector<Custom_SDL_Button *> scene28buttons;
std::vector<Custom_SDL_Button *> scene29buttons;
std::vector<Custom_SDL_Button *> scene30buttons;
std::vector<Custom_SDL_Button *> scene31buttons;
std::vector<Custom_SDL_Button *> scene32buttons;
std::vector<Custom_SDL_Button *> scene33buttons;
std::vector<Custom_SDL_Button *> scene34buttons;
std::vector<Custom_SDL_Button *> scene35buttons;
std::vector<Custom_SDL_Button *> scene36buttons;
std::vector<Custom_SDL_Button *> scene37buttons;
std::vector<Custom_SDL_Button *> scene38buttons;
std::vector<Custom_SDL_Button *> scene39buttons;
std::vector<Custom_SDL_Button *> scene40buttons;
std::vector<Custom_SDL_Button *> scene41buttons;
std::vector<Custom_SDL_Button *> scene42buttons;
std::vector<Custom_SDL_Button *> scene43buttons;
std::vector<Custom_SDL_Button *> scene44buttons;
std::vector<Custom_SDL_Button *> scene45buttons;
std::vector<Custom_SDL_Button *> scene46buttons;
std::vector<Custom_SDL_Button *> scene47buttons;
std::vector<Custom_SDL_Button *> scene48buttons;
std::vector<Custom_SDL_Button *> scene49buttons;
std::vector<Custom_SDL_Button *> scene50buttons;

std::vector<Custom_SDL_Button *> allButtons;
Custom_SDL_Button *Custom_SDL_Button::selectedButton = nullptr;

int scene = 11;
std::string language = "English";

bool quit = false;
int windowWidth = 800;
int windowHeight = 600;

// Multiplayer
std::string playerUsername = "";
std::string playerEmail = "";
std::string playerPassword = "";
bool submitUsername = false;
bool showPrivacyPolicyPopup = false;
bool acceptedPrivacyPolicy = false;

// SDL2 TTF library
TTF_Font *font_24;
TTF_Font *font_36;
TTF_Font *font_48;
int fontSize = 24;

void render_text(const std::string &text, int x, int y, Uint8 alpha, int customFontSize)
{
    /* Example
     1. Parameter definitions
     const std::string &text: The text to render to screen
     int x, x position e.g. static_cast<int>(windowWidth * 0.1) = if there are 10 columns it will appear in 1st column from left
     int y: y position e.g. static_cast<int>(windowHeight * 0.3) = if there are 10 rows it will appear in 3rd row from top
     Uint8 alpha: transperancy, leave at 255 per default unless you want particular text transparent scale 0 - 255
     int customFontSize = leave as 0 to scale with all global fontsize functions, however can statically
     set to values equal to fonts on loop below e.g. 24, 36, 48 for fixed heading sizes

     2. Populate parameters
     render_text("Enter Username: ", static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2), 255, 0);
    */
    TTF_Font *font = nullptr;
    if (customFontSize == 0)
    {
        if (fontSize == 24)
        {
            font = font_24;
        }
        else if (fontSize == 36)
        {
            font = font_36;
        }
        else if (fontSize == 48)
        {
            font = font_48;
        }
    }
    else if (!customFontSize == 0)
    {
        if (customFontSize == 24)
        {
            font = font_24;
        }
        else if (customFontSize == 36)
        {
            font = font_36;
        }
        else if (customFontSize == 48)
        {
            font = font_48;
        }
    }

    if (font)
    {
        SDL_Color textColor = {0, 0, 0, alpha};
        SDL_Surface *textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), textColor);

        if (textSurface)
        {
            // Calculate textWidth and textHeight using TTF_SizeText
            int textWidth, textHeight;
            TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);

            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_FreeSurface(textSurface);

            if (textTexture)
            {
                SDL_Rect textRect = {x, y, textWidth, textHeight};
                SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            }
        }
    }
}
SDL_Texture *render_texture(std::string path, std::string name)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture)
    {
        std::cerr << "Error: Failed to load texture: " << name << ". SDL Image Error: " << IMG_GetError() << std::endl;
    }
    else
    {
        std::cout << "Successfully loaded texture: " << name << std::endl;
    }
    return texture; // local variable is automatically destroyed when out of scope no need to free this *texture
}

void render_text_from_file(const std::string &filename, int x, int y, Uint8 alpha, int customFontSize)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error:Failed to open file: " << filename << std::endl;
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Read the entire file into the stringstream;
    std::string text = buffer.str();

    // Call render_text function with the text read from the file
    render_text(text, x, y, alpha, customFontSize);
}

// LOGIC
void scale_font_and_button_size()
{
    for (Custom_SDL_Button *button : allButtons) // for loop variable* has to match buttonsVector*
    {
        if (fontSize == 24)
        {
            button->set_font_size(36);
        }
        else if (fontSize == 36)
        {
            button->set_font_size(48);
        }
        else if (fontSize == 48)
        {
            button->set_font_size(24);
        }
    }
    if (fontSize == 24)
    {
        fontSize = 36;
    }
    else if (fontSize == 36)
    {
        fontSize = 48;
    }
    else if (fontSize == 48)
    {
        fontSize = 24;
    }
}

void load_textures()
{
    splashScreenTexture = render_texture("assets/graphics/AgniSamooh/AgniSamooh-HD-logo.png", "Developer Splash screen");
    rockpaperscissorsRulesTexture = render_texture("assets/graphics/encyclopedia/encyclopedia-image-1.png", "Developer Splash screen");
}
void load_fonts()
{
    font_24 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 24);
    font_36 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 36);
    font_48 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 48);
    if (!font_24 || !font_36 || !font_48)
    {
        std::cerr << "Error: Failed to load font size: " << TTF_GetError() << std::endl;
    }
}

void load_buttons_to_scene_vectors()
{
    scene11buttons.push_back(&scene11submitUsernameButton);
    scene11buttons.push_back(&scene11registerButton);
    scene11buttons.push_back(&scene11acceptButton);
    scene11buttons.push_back(&scene11denyButton);
    scene11buttons.push_back(&scene11fontScaleButton);

    scene12buttons.push_back(&scene12submitEmailPasswordButton);
    scene12buttons.push_back(&scene12backButton);

    scene13buttons.push_back(&scene13submitLoginButton);
    scene13buttons.push_back(&scene13backButton);

    scene14buttons.push_back(&scene14hostGameButton);
    scene14buttons.push_back(&scene14joinGameButton);
    scene14buttons.push_back(&scene14searchGamesButton);
    scene14buttons.push_back(&scene14searchFriendsGamesButton);
    scene14buttons.push_back(&scene14refreshButton);
    scene14buttons.push_back(&scene14backButton);

    scene25buttons.push_back(&scene25backusernameButton);
}
void load_buttons_to_allButtons_vector()
{
    allButtons.insert(allButtons.end(), scene1buttons.begin(), scene1buttons.end());
    allButtons.insert(allButtons.end(), scene2buttons.begin(), scene2buttons.end());
    allButtons.insert(allButtons.end(), scene3buttons.begin(), scene3buttons.end());
    allButtons.insert(allButtons.end(), scene4buttons.begin(), scene4buttons.end());
    allButtons.insert(allButtons.end(), scene5buttons.begin(), scene5buttons.end());
    allButtons.insert(allButtons.end(), scene6buttons.begin(), scene6buttons.end());
    allButtons.insert(allButtons.end(), scene7buttons.begin(), scene7buttons.end());
    allButtons.insert(allButtons.end(), scene8buttons.begin(), scene8buttons.end());
    allButtons.insert(allButtons.end(), scene9buttons.begin(), scene9buttons.end());
    allButtons.insert(allButtons.end(), scene10buttons.begin(), scene10buttons.end());
    allButtons.insert(allButtons.end(), scene11buttons.begin(), scene11buttons.end());
    allButtons.insert(allButtons.end(), scene12buttons.begin(), scene12buttons.end());
    allButtons.insert(allButtons.end(), scene13buttons.begin(), scene13buttons.end());
    allButtons.insert(allButtons.end(), scene14buttons.begin(), scene14buttons.end());
    allButtons.insert(allButtons.end(), scene15buttons.begin(), scene15buttons.end());
    allButtons.insert(allButtons.end(), scene16buttons.begin(), scene16buttons.end());
    allButtons.insert(allButtons.end(), scene17buttons.begin(), scene17buttons.end());
    allButtons.insert(allButtons.end(), scene18buttons.begin(), scene18buttons.end());
    allButtons.insert(allButtons.end(), scene19buttons.begin(), scene19buttons.end());
    allButtons.insert(allButtons.end(), scene20buttons.begin(), scene20buttons.end());
    allButtons.insert(allButtons.end(), scene21buttons.begin(), scene21buttons.end());
    allButtons.insert(allButtons.end(), scene22buttons.begin(), scene22buttons.end());
    allButtons.insert(allButtons.end(), scene23buttons.begin(), scene23buttons.end());
    allButtons.insert(allButtons.end(), scene24buttons.begin(), scene24buttons.end());
    allButtons.insert(allButtons.end(), scene25buttons.begin(), scene25buttons.end());
    allButtons.insert(allButtons.end(), scene26buttons.begin(), scene26buttons.end());
    allButtons.insert(allButtons.end(), scene27buttons.begin(), scene27buttons.end());
    allButtons.insert(allButtons.end(), scene28buttons.begin(), scene28buttons.end());
    allButtons.insert(allButtons.end(), scene29buttons.begin(), scene29buttons.end());
    allButtons.insert(allButtons.end(), scene30buttons.begin(), scene30buttons.end());
}

void load_buttons_11()
{
    scene11submitUsernameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                    static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                    "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11registerButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "REGISTER", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11acceptButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.6),
                                            static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                            "ACCEPT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11denyButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.6), static_cast<int>(windowHeight * 0.6),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "DENY", 144, 238, 144, 255, "", false); // RGB: Light green
    scene11fontScaleButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                               static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                               "CHANGE FONT", 144, 238, 144, 255, "", false); // RGB: Light green
}
void load_buttons_12()
{
    scene12submitEmailPasswordButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                         static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                         "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene12backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene12backButton.set_button_texture(renderer);
}
void load_buttons_13()
{
    scene13submitLoginButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                 static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                 "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene13backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene13backButton.set_button_texture(renderer);
}
void load_buttons_14()
{
    scene14hostGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene14joinGameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                              static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                              "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    scene14searchGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                 static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                 "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene14searchFriendsGamesButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                        static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                        "SUBMIT", 144, 238, 144, 255, "assets/graphics/buttons/settings/zoom-button.png", false); // RGB: Light green
    scene14refreshButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                             static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                             "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/refresh-button.png", false); // RGB: Light green
    scene14backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                          static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                          "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene14backButton.set_button_texture(renderer);
}
void load_buttons_25()
{
    scene25backusernameButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                                  static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                                  "BACK", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    scene25backusernameButton.set_button_texture(renderer);
}

void draw_textbox()
{
    // Draw text input rect black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect borderRect = {static_cast<int>(windowWidth * 0.4) - 2, static_cast<int>(windowHeight * 0.2) - 2, static_cast<int>(windowWidth * 0.4) + 4, static_cast<int>(windowHeight * 0.1) + 4};
    SDL_RenderFillRect(renderer, &borderRect);

    // draw text input rect
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255); // RGB: Light grey
    SDL_Rect textInputRect = {static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.1)};
    SDL_RenderFillRect(renderer, &textInputRect);
}
void draw_privacy_policy_popup_window()
{
    // Draw privacy policy popup black border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // RGB: Black
    SDL_Rect privacypolicyPopupBorderRect = {static_cast<int>(windowWidth * 0.1) - 2, static_cast<int>(windowHeight * 0.1) - 2, static_cast<int>(windowWidth * 0.7) + 4, static_cast<int>(windowHeight * 0.7) + 4};
    SDL_RenderFillRect(renderer, &privacypolicyPopupBorderRect);

    // draw privacy policy popup
    SDL_SetRenderDrawColor(renderer, 144, 238, 144, 255); // RGB: Light green
    SDL_Rect privacypolicyPopupRect = {static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1), static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7)};
    SDL_RenderFillRect(renderer, &privacypolicyPopupRect);

    if (showPrivacyPolicyPopup)
    {
        render_text("Read Privacy Policy below then accept or deny for online access",
                    static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1), 255, 0);
        scene11acceptButton.render_button_rect(renderer);
        scene11denyButton.render_button_rect(renderer);
    }
}

void draw_texts_11()
{
    if (language == "English")
    {
        render_text("Enter Username: ", static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.2), 255, 0);
    }
    else if (language == "日本語")
    {
    }
}
void draw_texts_12()
{
    if (language == "English")
    {
        render_text("SIGN UP FOR ONLINE SERVICES", static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.1), 255, 0);
        render_text("Enter Email: ", static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.2), 255, 0);
        render_text("Enter Password: ", static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.4), 255, 0);
    }
    else if (language == "日本語")
    {
    }
}
void draw_texts_13()
{
    if (language == "English")
    {
        render_text("LOGIN FOR ONLINE SERVICES", static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.1), 255, 0);
        render_text("Enter Email: ", static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.2), 255, 0);
        render_text("Enter Password: ", static_cast<int>(windowWidth * 0.4), static_cast<int>(windowHeight * 0.6), 255, 0);
    }
    else if (language == "日本語")
    {
    }
}
void draw_texts_14()
{
    if (language == "English")
    {
        render_text("MULTIPLAYER AND ONLINE SERVICES", static_cast<int>(windowWidth * 0.25), static_cast<int>(windowHeight * 0.1), 255, 0);
    }
    else if (language == "日本語")
    {
    }
}
void draw_texts_25()
{
    if (language == "English")
    {
        // draw results to blank screen
        render_text("Your details are", static_cast<int>(windowWidth * 0.35), static_cast<int>(windowHeight * 0.1), 255, 0);
        std::string playersUsername = "You're Username is: " + playerUsername;
        std::string playersEmail = "You're Email is: " + playerEmail;
        render_text(playersUsername, static_cast<int>(windowWidth * 0.3), static_cast<int>(windowHeight * 0.3), 255, 0);
        render_text(playersEmail, static_cast<int>(windowWidth * 0.3), static_cast<int>(windowHeight * 0.4), 255, 0);
    }
    else if (language == "日本語")
    {
    }
}

void draw_images_11()
{
    SDL_Rect rockpaperscissorsRulesRect = {static_cast<int>(windowWidth * 0.8),
                                           static_cast<int>(windowHeight * 0.6),
                                           static_cast<int>(windowWidth * 0.2),
                                           static_cast<int>(windowHeight * 0.2)};
    SDL_RenderCopy(renderer, rockpaperscissorsRulesTexture, nullptr, &rockpaperscissorsRulesRect);
}

void draw_buttons_11()
{
    draw_textbox();
    scene11submitUsernameButton.render_button_rect(renderer);
    scene11registerButton.render_button_rect(renderer);
    scene11fontScaleButton.render_button_rect(renderer);
}
void draw_buttons_12()
{
    draw_textbox();
    draw_textbox();
    scene12submitEmailPasswordButton.render_button_rect(renderer);
    scene12backButton.render_button_rect(renderer);
}
void draw_buttons_13()
{
    draw_textbox();
    draw_textbox();
    scene13submitLoginButton.render_button_rect(renderer);
    scene13backButton.render_button_rect(renderer);
}
void draw_buttons_14()
{
    scene14hostGameButton.render_button_rect(renderer);
    scene14joinGameButton.render_button_rect(renderer);
    scene14searchGamesButton.render_button_rect(renderer);
    scene14searchFriendsGamesButton.render_button_rect(renderer);
    scene14refreshButton.render_button_rect(renderer);
    scene14backButton.render_button_rect(renderer);
}
void draw_buttons_25()
{
    scene25backusernameButton.render_button_rect(renderer);
}

void start_SDL()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    window = SDL_CreateWindow("Text Input Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    load_fonts();
    load_textures();
    load_buttons_11();
    load_buttons_12();
    load_buttons_13();
    load_buttons_14();
    load_buttons_25();
    load_buttons_to_scene_vectors();
    load_buttons_to_allButtons_vector();
}

void mouse_handles_11(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    SDL_Rect rockpaperscissorsRulesRect = {static_cast<int>(windowWidth * 0.8),
                                           static_cast<int>(windowHeight * 0.6),
                                           static_cast<int>(windowWidth * 0.2),
                                           static_cast<int>(windowHeight * 0.2)};

    if (!showPrivacyPolicyPopup)
    {
        if (scene11submitUsernameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            submitUsername = true;
            scene = 12; // To world map
        }
        else if (scene11registerButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Register for online access" << std::endl;
            showPrivacyPolicyPopup = true;
        }
        else if (scene11fontScaleButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Change font size" << std::endl;
            scale_font_and_button_size();
        }
        else if (SDL_PointInRect(&mousePosition, &rockpaperscissorsRulesRect))
        {
            std::cout << "You clicked: Encyoclopedia" << std::endl;
            render_text_from_file("help.txt", 1, 1, 255, 0);
        }
    }

    if (showPrivacyPolicyPopup)
    {
        if (scene11acceptButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Accept Privacy Policy" << std::endl;
            showPrivacyPolicyPopup = false;
            acceptedPrivacyPolicy = true;
            scene = 12;
        }
        else if (scene11denyButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Deny Privacy Policy" << std::endl;
            showPrivacyPolicyPopup = false;
        }
    }
}
void mouse_handles_12(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene12submitEmailPasswordButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: SUBMIT" << std::endl;
        submitUsername = true;
        scene = 12;
    }
    else if (scene12backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Back" << std::endl;
        scene = 11;
    }
}
void mouse_handles_13(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene13submitLoginButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: SUBMIT" << std::endl;
        submitUsername = true;
        scene = 12;
    }
    else if (scene13backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Back" << std::endl;
        scene = 11;
    }
}
void mouse_handles_14(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene14hostGameButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Host game" << std::endl;
    }
    else if (scene14joinGameButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Join game" << std::endl;
    }
    else if (scene14searchGamesButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Search Games" << std::endl;
    }
    else if (scene14searchFriendsGamesButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Search friends" << std::endl;
    }
    else if (scene14refreshButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Refresh" << std::endl;
    }
    else if (scene14backButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Back" << std::endl;
        scene = 11;
    }
}
void mouse_handles_25(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (scene25backusernameButton.isClicked(mousePosition))
    {
        std::cout << "You clicked: Back" << std::endl;
        scene = 11;
    }
}

void keyboard_handles_11(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "You clicked button: ESC" << std::endl;
        break;
    case SDLK_UP:
        std::cout << "You clicked button: UP" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_UP, 0);
        break;
    case SDLK_DOWN:
        std::cout << "You clicked button: DOWN" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_DOWN, 0);
        break;
    case SDLK_LEFT:
        std::cout << "You clicked button: LEFT" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_LEFT, 0);
        break;
    case SDLK_RIGHT:
        std::cout << "You clicked button: RIGHT" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, SDLK_RIGHT, 0);
        break;
    case SDLK_RETURN:
        std::cout << "You clicked button: ENTER" << std::endl;
        if (scene11submitUsernameButton.is_selected())
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            submitUsername = true;
            scene = 12; // To world map
        }
        else if (scene11registerButton.is_selected())
        {
            std::cout << "You clicked: REGISTER" << std::endl;
            showPrivacyPolicyPopup = true;
        }
        else if (scene11fontScaleButton.is_selected())
        {
            std::cout << "You clicked: FONT" << std::endl;
            scale_font_and_button_size();
        }
        break;
    default:
        std::cout << "You pressed a non-configured keyboard input." << std::endl;
        break;
    }
}
void keyboard_handles_12(SDL_Event event)
{
}
void keyboard_handles_13(SDL_Event event)
{
}
void keyboard_handles_14(SDL_Event event)
{
}
void keyboard_handles_25(SDL_Event event)
{
}

void gamepad_handles_11(int button)
{
    switch (button)
    {
    case SDL_CONTROLLER_BUTTON_START:
        std::cout << "You pressed controller button: START" << std::endl;
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_UP:
        std::cout << "You pressed controller button: UP" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_UP);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
        std::cout << "You pressed controller button: DOWN" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_DOWN);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
        std::cout << "You pressed controller button: LEFT" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_LEFT);
        break;
    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
        std::cout << "You pressed controller button: RIGHT" << std::endl;
        scene11submitUsernameButton.find_nearest_button(scene11buttons, 0, SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
        break;
    case SDL_CONTROLLER_BUTTON_A:
        std::cout << "You pressed controller button: A" << std::endl;
        if (scene11submitUsernameButton.is_selected())
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            submitUsername = true;
            scene = 12; // To world map
        }
        else if (scene11registerButton.is_selected())
        {
            std::cout << "You clicked: REGISTER" << std::endl;
            showPrivacyPolicyPopup = true;
        }
        else if (scene11fontScaleButton.is_selected())
        {
            std::cout << "You clicked: FONT" << std::endl;
            scale_font_and_button_size();
        }
        break;
    default:
        std::cout << "You pressed a non-configured Gamepad input." << std::endl;
        break;
    }
}
void gamepad_handles_12(int button)
{
}
void gamepad_handles_13(int button)
{
}
void gamepad_handles_14(int button)
{
}
void gamepad_handles_25(int button)
{
}

void handle_events()
{
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            if (scene == 11)
            {
                keyboard_handles_11(event);
            }
            else if (scene == 12)
            {
                keyboard_handles_12(event);
            }
            else if (scene == 13)
            {
                keyboard_handles_13(event);
            }
            else if (scene == 14)
            {
                keyboard_handles_14(event);
            }
            else if (scene == 25)
            {
                keyboard_handles_25(event);
            }
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_FINGERDOWN)
        {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            if (scene == 11)
            {
                mouse_handles_11(mouseX, mouseY);
            }
            else if (scene == 12)
            {
                mouse_handles_12(mouseX, mouseY);
            }
            else if (scene == 13)
            {
                mouse_handles_13(mouseX, mouseY);
            }
            else if (scene == 14)
            {
                mouse_handles_14(mouseX, mouseY);
            }
            else if (scene == 25)
            {
                mouse_handles_25(mouseX, mouseY);
            }
        }
        else if (event.type == SDL_CONTROLLERBUTTONDOWN)
        {
            SDL_ControllerButtonEvent controllerButtonEvent = event.cbutton;
            int button = controllerButtonEvent.button;
            {
                if (scene == 11)
                {
                    gamepad_handles_11(button);
                }
                else if (scene == 12)
                {
                    gamepad_handles_12(button);
                }
                else if (scene == 13)
                {
                    gamepad_handles_13(button);
                }
                else if (scene == 14)
                {
                    gamepad_handles_14(button);
                }
                else if (scene == 25)
                {
                    gamepad_handles_25(button);
                }
            }
        }
    }
}
void draw()
{
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Set the blend mode to enable transparency
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);      // RGB - light grey
    SDL_RenderClear(renderer);
    if (scene == 11)
    {
        draw_images_11();
        draw_buttons_11();
        draw_texts_11();
        if (showPrivacyPolicyPopup)
        {
            draw_privacy_policy_popup_window();
        }
    }
    else if (scene == 12)
    {
        draw_texts_12();
        draw_buttons_12();
    }
    else if (scene == 13)
    {
        draw_texts_13();
        draw_buttons_13();
    }
    else if (scene == 14)
    {
        draw_texts_14();
        draw_buttons_14();
    }
    else if (scene == 25)
    {
        draw_texts_25();
        draw_buttons_25();
    }
    SDL_RenderPresent(renderer);
}
void run_SDL()
{
    while (!quit)
    {
        handle_events();
        draw();
    }
}
void quit_SDL()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_DestroyTexture(splashScreenTexture);
    SDL_DestroyTexture(rockpaperscissorsRulesTexture);

    TTF_CloseFont(font_24);
    TTF_CloseFont(font_36);
    TTF_CloseFont(font_48);

    // Close game controller
    if (controller)
    {
        SDL_GameControllerClose(controller);
    }

    // Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    start_SDL();

    // .get() used to retrieve raw pointer from smart pointer similar to c_str() retrieves const char* from std::string
    SDL_RenderCopy(renderer, splashScreenTexture, NULL, NULL); // Display the splash screen for 2 seconds
    SDL_RenderPresent(renderer);
    SDL_Delay(100);

    run_SDL();
    quit_SDL();
    SDL_GetNumAllocations();
    return 0;
}
