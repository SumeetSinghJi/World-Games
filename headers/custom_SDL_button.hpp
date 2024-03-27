/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++17
    Purpose: Class Declaration/Definition file combined
    License: MIT License
    Description: read the attached MANUAL.txt file
*/

#pragma once

#include <iostream>
// #include <SDL.h>
// #include <SDL_ttf.h>
// #include <SDL_image.h>
#include <string>
#include <memory>
#include <cmath>
#include <limits>

/*
REQUIREMENTS:
SDL library - https://github.com/libsdl-org/SDL
SDL_Image library - https://github.com/libsdl-org/SDL_image
SDL_TTF - https://github.com/libsdl-org/SDL_ttf

PURPOSE:
SDL Class for Buttons initialised with Custom_SDL_Button::button
Supports the following button elements within SDL;
* Button
* Textfields
* Slider
* Checkboxes
* Radio boxes
* Toggles
Requires passing a renderer* from main source code to function correctly.
Requires initialising a button vector of Custom_SDL_Button type in main.cpp and push back of button objects



EXAMPLE:

INITIALISATION

0. Explanation of variable parameters
e.g. submitEmailPasswordButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                  static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                  "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green

1st parameter = type: int x  = rect x pos in window  e.g. static_cast<int>(windowWidth * 0.2)
2nd parameter = type: int y = rect y pos in window e.g. static_cast<int>(windowHeight * 0.8)
3rd parameter = type: int width = button width rect size e.g. static_cast<int>(windowWidth * 0.2)
4th parameter = type: int height = button height rect size e.g. static_cast<int>(windowHeight * 0.1)
5th parameter = type: const std::string &text = Text label to appear over button (in between 3rd/4th parameters)
6th parameter = type: Uint8 r = button rgb red colour value e.g. 144 = combined with rgb = light green button colour
7th parameter = type: Uint8 g = button rgb green colour value e.g. 238 = combined with rgb = light green button colour
8th parameter = type: Uint8 b = button rgb blue colour value e.g. 144 = combined with rgb = light green button colour
9th parameter = type: Uint8 alpha = transperancy of font, low number means more transparent font e.g. 255
10th parameter = type: std::string path = string path of asset to load e.g. (example not shown above but an real use case would
look like this) "assets/graphics/buttons/settings/save-button.png"
11th parameter = type: bool selected = used by find_euclidean_distance() to find selected button or called in handles to
select buttons = e.g. false


1. create global variable e.g;

Custom_SDL_Button submitUsernameButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);
Custom_SDL_Button backButton(0, 0, 0, 0, "Button", 0, 0, 0, 0, "", false);

1.1. (Optional) Initialise button vectors e.g.
std::vector<Custom_SDL_Button *> scene12buttons;
std::vector<Custom_SDL_Button *> scene13buttons;
std::vector<Custom_SDL_Button *> scene14buttons;

1.2 (Optional) Add buttons depending on scene to related scene vector
void load_buttons_to_vector()
{
    scene12buttons.push_back(&scene12submitEmailPasswordButton);
    scene12buttons.push_back(&scene12backButton);
}

2. In a function or main populate variables e.g;
Note: If there is an texture to load instead of text, call function .set_button_texture(renderer);

void load_buttons_2()
{
    submitEmailPasswordButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.8),
                                                  static_cast<int>(windowWidth * 0.2), static_cast<int>(windowHeight * 0.1),
                                                  "SUBMIT", 144, 238, 144, 255, "", false); // RGB: Light green
    backButton = Custom_SDL_Button(static_cast<int>(windowWidth * 0.7), static_cast<int>(windowHeight * 0.7),
                                   static_cast<int>(windowWidth * 0.1), static_cast<int>(windowHeight * 0.1),
                                   "", 144, 238, 144, 255, "assets/graphics/buttons/settings/back-button.png", false); // RGB: Light green
    backButton.set_button_texture(renderer);                                                                               // load button texture at runtime to stop infinite file access in rendercopy() loop
}

3. Load the buttons somewhere e.g;

In start_SDL() {
    load_buttons_2();
}

4. Render the buttons in a function which will draw it to the screen in your appropriate function e.g, draw();

void draw_buttons_2()
{
    submitEmailPasswordButton.render(renderer);
    backButton.render(renderer);
}


RENDERING

1. Draw the buttons targetting your Draw loop with the .render_button_rect(renderer);

void draw_buttons_11()
{
    draw_textbox();
    scene11submitUsernameButton.render_button_rect(renderer);
    scene11registerButton.render_button_rect(renderer);
    scene11fontScaleButton.render_button_rect(renderer);
}

HANDLES

NOTE: when having games like chess, you can have mouse clicks to be is selected so you're aware of what's selected

1. For Mouse handles set .set_selected(); for button on click

void mouse_handles_11(int mouseX, int mouseY)
{
    SDL_Point mousePosition = {mouseX, mouseY};

    if (!showPrivacyPolicyPopup)
    {
        if (scene11submitUsernameButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: SUBMIT" << std::endl;
            scene11submitUsernameButton.set_selected();
        }
        else if (scene11registerButton.isClicked(mousePosition))
        {
            std::cout << "You clicked: Register for online access" << std::endl;
            scene11registerButton.set_selected();
        }


*/

class Custom_SDL_Button
{
private:
    SDL_Rect rect;
    std::string buttonText;
    SDL_Color bgColor;
    std::string buttonPath;
    bool isSelected;
    static Custom_SDL_Button *selectedButton; // Static pointer to keep track of the selected button
    TTF_Font *buttonFont;                     // destroyed with deconstructor
    TTF_Font *buttonfont_24;
    TTF_Font *buttonfont_36;
    TTF_Font *buttonfont_48;
    SDL_Texture *buttonTexture = nullptr; // destroyed with deconstructor

    void render_button_text(const std::string &text, int x, int y, SDL_Renderer *renderer, Uint8 alpha) const
    {
        if (buttonFont)
        {
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            SDL_Color textColor = {0, 0, 0, alpha}; // black color, alpha passed as variable usually 255 on init
            SDL_Surface *textSurface = TTF_RenderUTF8_Blended(buttonFont, text.c_str(), textColor);

            if (textSurface)
            {
                // Calculate textWidth and textHeight using TTF_SizeText
                int btextWidth, btextHeight;
                TTF_SizeText(buttonFont, text.c_str(), &btextWidth, &btextHeight);

                SDL_Texture *btextTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                SDL_FreeSurface(textSurface);

                if (btextTexture)
                {
                    SDL_Rect textRect = {x, y, btextWidth, btextHeight};
                    SDL_RenderCopy(renderer, btextTexture, nullptr, &textRect);
                }
            }
        }
    }

public:
    Custom_SDL_Button(int x, int y, int width, int height, const std::string &text,
                      Uint8 r, Uint8 g, Uint8 b, Uint8 alpha, std::string path, bool selected)
        : rect({x, y, width, height}), buttonText(text),
          bgColor{r, g, b, alpha}, buttonPath(path), isSelected(selected)
    {
        buttonFont = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 24);
        buttonfont_24 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 24);
        buttonfont_36 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 36);
        buttonfont_48 = TTF_OpenFont("assets/fonts/noto-sans/NotoSansJP-Regular.ttf", 48);
        std::cout << "Button constructed: " << buttonText << std::endl;
    }

    ~Custom_SDL_Button()
    {
        if (buttonTexture != nullptr)
        {
            SDL_DestroyTexture(buttonTexture);
            buttonTexture = nullptr;
        }
        // TTF_CloseFont(buttonFont); - CAUSES SEG FAULT
        buttonFont = nullptr;
        buttonfont_24 = nullptr;
        buttonfont_36 = nullptr;
        buttonfont_48 = nullptr;
        std::cout << "Button destroyed: " << buttonText << std::endl;
    }

    bool isClicked(const SDL_Point &point) const
    {
        return SDL_PointInRect(&point, &rect);
    }

    bool is_selected() const
    {
        return isSelected;
    }

    void set_selected()
    {
        // Deselect the previous selected button
        if (selectedButton != nullptr)
        {
            selectedButton->isSelected = false;
        }

        isSelected = true;
        selectedButton = this;
    }

    void set_button_texture(SDL_Renderer *renderer, const std::string customButtonPath)
    {
        if (!customButtonPath.empty())
        {
            buttonPath = customButtonPath;
        }
        buttonTexture = IMG_LoadTexture(renderer, buttonPath.c_str());
        if (buttonTexture == nullptr)
        {
            std::cout << "Button texture failed to load: " << IMG_GetError() << std::endl;
        }
    }

    void set_font_size(int size)
    { // why it's not directly read from file path like set_button_textures is to reduce performance load
        if (size == 24)
        {
            buttonFont = buttonfont_24;
            rect.w = rect.w - 40;
            rect.h = rect.h - 40;
        }
        else if (size == 36)
        {
            buttonFont = buttonfont_36;
            rect.w = rect.w + 20;
            rect.h = rect.h + 20;
        }
        else if (size == 48)
        {
            buttonFont = buttonfont_48;
            rect.w = rect.w + 20;
            rect.h = rect.h + 20;
        }
    }

    void render_button_rect(SDL_Renderer *renderer) const
    {

        if (buttonPath.empty())
        {
            // Render the button differently based on the isSelected flag
            if (isSelected)
            {
                // Draw border
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black border
                SDL_Rect borderRect = {rect.x - 2, rect.y - 2, rect.w + 4, rect.h + 4};
                SDL_RenderFillRect(renderer, &borderRect);
                // Render the selected button with a different color or texture
                // For example, you can change the background color
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for selected button
                SDL_RenderFillRect(renderer, &rect);
                // Draw text
                render_button_text(buttonText, rect.x + 20, rect.y + 10, renderer, bgColor.a);
            }
            else
            {
                // Draw border
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black border
                SDL_Rect borderRect = {rect.x - 2, rect.y - 2, rect.w + 4, rect.h + 4};
                SDL_RenderFillRect(renderer, &borderRect);

                // Draw button
                SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
                SDL_RenderFillRect(renderer, &rect);

                // Draw text
                render_button_text(buttonText, rect.x + 20, rect.y + 10, renderer, bgColor.a);
            }
        }

        // Draw image
        if (!buttonPath.empty())
        {
            SDL_RenderCopy(renderer, buttonTexture, nullptr, &rect);
        }
    }

    static double find_euclidean_distance(int x1, int y1, int x2, int y2)
    {
        // Measure Euclidean distance used in finding closest button to navigate to using directional navigation keys
        // E.g. if you press up directional arrow key on a keyboard or gamepad all the buttons north in -y scale
        // will be calculated to find the nearest button.
        double results = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        return results;
    }

    void find_nearest_button(std::vector<Custom_SDL_Button *> sceneVector, SDL_Keycode keyCode, int gamepadButton) const
    {
        /*
        Say there are 1 reference point button A, and 4 buttons
        A - B = 1cm away
        A - C = 5cm away
        A - D = 10cm away
        A - E = 100cm away
        minDistance is set to largest float value e.g. 1000cm
        Starting from the highest number minDistance will update to it e.g.
        A - E = 100cm therefore minDistance - 100cm.
        Then
        A - D = 10cm < minDistance (1000cm) therefore minDistance = 10cm
        A - C = 5cm < minDistance (100cm) therefore minDistance = 10cm
        A - B = 1cm < minDistance (5cm) therefore minDistance is 1cm or points A - B.

        If there are another button A - F which is 1cm away same as A - B, regardless
        minDistance will just hold (1) value.
        */
        float minDistance = std::numeric_limits<float>::max();

        /*
            Get current buttons position
            rect.x; = rect column position
            rect.y; = rect row position
            rect.w / 2 and rect.h / 2 middle of the button rect
        */

        int currentButtonXpos = rect.x + rect.w / 2; // Middle of button
        int currentButtonYpos = rect.y + rect.h / 2; // Middle of button

        for (Custom_SDL_Button *button : sceneVector)
        {
            if (button != this)
            {
                // exclude this button object that is calling the function from the vector e.g.
                //  dont count scene11submitbutton

                /*
                    compare this button with scene button
                    find_euclidean_distance(
                        x2 = button->rect.x + button->rect.w / 2 (finding middle of target button like in above)
                        y2 = button->rect.y + button->rect.h / 2
                )
                */
                float dist = find_euclidean_distance(currentButtonXpos, currentButtonYpos,
                                                     button->rect.x + button->rect.w / 2,
                                                     button->rect.y + button->rect.h / 2);

                switch (keyCode)
                {
                case SDLK_UP:
                    // Check if the button is in the up direction (with respect to the current button)
                    if (button->rect.y < rect.y)
                    {
                        // If the button is above the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDLK_DOWN:
                    // Check if the button is in the down direction (with respect to the current button)
                    if (button->rect.y > rect.y)
                    {
                        // If the button is below the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDLK_LEFT:
                    // Check if the button is in the left direction (with respect to the current button)
                    if (button->rect.x < rect.x)
                    {
                        // If the button is to the left of the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDLK_RIGHT:
                    // Check if the button is in the right direction (with respect to the current button)
                    if (button->rect.x > rect.x)
                    {
                        // If the button is to the right of the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                default:
                    // Handle other keycodes if needed
                    break;
                }

                // Gamepad
                switch (gamepadButton)
                {
                case SDL_CONTROLLER_BUTTON_DPAD_UP:
                    // Check if the button is in the up direction (with respect to the current button)
                    if (button->rect.y < rect.y)
                    {
                        // If the button is above the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                    // Check if the button is in the down direction (with respect to the current button)
                    if (button->rect.y > rect.y)
                    {
                        // If the button is below the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                    // Check if the button is in the left direction (with respect to the current button)
                    if (button->rect.x < rect.x)
                    {
                        // If the button is to the left of the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                    // Check if the button is in the right direction (with respect to the current button)
                    if (button->rect.x > rect.x)
                    {
                        // If the button is to the right of the current button, update the distance
                        if (dist < minDistance)
                        {
                            minDistance = dist;
                            button->set_selected();
                        }
                    }
                    break;
                default:
                    // Handle other keycodes if needed
                    break;
                }
            }
        }
    }
};
