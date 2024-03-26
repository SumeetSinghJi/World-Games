/*
Author: Sumeet Singh
Dated: 14/02/2024
Minimum C++ Standard: C++17
Purpose: Declaration/Definition file combined
License: MIT License
Description: read the attached MANUAL.txt file
*/

#pragma once

#include "global_variables.hpp"

bool displaySavefileExistsPopup = false; // used in SDL_mouse_handles.hpp
bool overwriteGame = false;
std::string saveFileName = "ancient-games_save.txt";

void new_game();
void save_game();

void create_save_file_if_doesnt_exist()
{
  // Called in implementation file at game start to create a new save file txt if not existing (for brand new installations)
  if (!std::ifstream(saveFileName)) //std::ifstream is read only, no need to saveFileName.close()
  {
    save_game();
  }
  else {}
}

void save_settings()
{
  std::fstream file(saveFileName); // replaces ifstream (reading) and ofstream (writing) for both
  if (!file.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }

  // Read the entire file into a string
  std::string fileContents;
  std::string line;
  while (std::getline(file, line))
  {
    fileContents += line + '\n';
  }

  // Find and replace the lines containing strings, e.g., "Language: " and "Font size: ", with the updated lines
  size_t pos_language = fileContents.find("Language: ");
  size_t pos_fontsize = fileContents.find("Font size: ");
  if (pos_language != std::string::npos && pos_fontsize != std::string::npos)
  {
    size_t end_language = fileContents.find("\n", pos_language);
    size_t end_fontsize = fileContents.find("\n", pos_fontsize);
    fileContents.replace(pos_language, end_language - pos_language, "Language: " + language);
    fileContents.replace(pos_fontsize, end_fontsize - pos_fontsize, "Font size: " + std::to_string(fontSize));
  }
  else
  {
    // If the lines "Language: " or "Font size: " don't exist, add them
    if (pos_language == std::string::npos)
    {
      fileContents = "Language: " + language + '\n' + fileContents;
    }
    if (pos_fontsize == std::string::npos)
    {
      fileContents = "Font size: " + std::to_string(fontSize) + '\n' + fileContents;
    }
  }

  // Reset file pointer to the beginning and write the modified contents back to the file
  file.clear();                 // Clear any error flags
  file.seekp(0, std::ios::beg); // Move to the beginning of the file
  file << fileContents;
  file.close(); // Close the file
}

void load_settings()
{
  // The purpose of this is to load variables from save_settings()
  std::ifstream file(saveFileName);
  if (!file.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }

  std::string line;
  while (std::getline(file, line))
  {
    if (line.find("Language: ") != std::string::npos)
    {
      std::istringstream iss(line);
      std::string word;
      if (iss >> word) // Extract from string stream variable (iss) the second word after "Language: " and store in variable (word)
      {
        language = word;
      }
    }
  }
  std::cout << "Saved Settings loaded successfully" << std::endl;
}

void save_game()
{
  // fstream replaces fstream (reading) and ofstream (writing). So instead of 2 different functions just use fstream
  std::fstream savefileObject(saveFileName, std::fstream::app); // std::fstream::app (append) will create the file if it doesn't exist
  if (!savefileObject.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }

  if (savefileObject.is_open())
  {
    savefileObject << "unlockedScenes: ";
    for (size_t i = 0; i < unlockedScenes.size(); ++i)
    {
      savefileObject << unlockedScenes[i];
      if (i != unlockedScenes.size() - 1)
      {
        savefileObject << ",";
      }
    }
    savefileObject << "\n";
    savefileObject << "unlockedAchievements: ";
    for (size_t i = 0; i < unlockedAchievements.size(); ++i)
    {
      savefileObject << unlockedAchievements[i];
      if (i != unlockedAchievements.size() - 1)
      {
        savefileObject << unlockedAchievements[i] << ",";
      }
    }
    savefileObject << "\n";

    savefileObject.close();
    std::cout << "Game saved" << std::endl;
  }
}

void load_game()
{
  // The purpose of this is to load variables from save_game()
  std::fstream savefileObject(saveFileName); // replaces ifstream (reading) and ofstream (writing) for both
  if (!savefileObject.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }

  if (savefileObject.is_open())
  {
    std::cout << "Loading save..." << std::endl;
    std::string line;

    while (getline(savefileObject, line))
    {
      std::istringstream iss(line);
      std::string key;
      if (std::getline(iss, key, ':'))
      {
        std::string value;
        std::getline(iss, value);
        if (key == "unlockedScenes")
        {
          std::istringstream iss_scenes(value);
          std::string scene_val;
          size_t i = 0;
          while (std::getline(iss_scenes, scene_val, ','))
          {
            unlockedScenes[i++] = std::stoi(scene_val);
          }
        }
        else if (key == "unlockedAchievements")
        {
          std::istringstream iss_achievements(value);
          std::string achievement_val;
          size_t i = 0;
          while (std::getline(iss_achievements, achievement_val, ','))
          {
            unlockedAchievements[i++] = std::stoi(achievement_val);
          }
        }
      }
    }
    savefileObject.close();
    std::cout << "Save loaded..." << std::endl;
  }
}

void does_save_file_exist()
{
  if (std::ifstream(saveFileName)) // std::ifstream requires no .close()
  {
    displaySavefileExistsPopup = true;
    if (overwriteGame)
    {
      std::remove(saveFileName.c_str());
      new_game();
      scene = 25;
      overwriteGame = false;
      save_game();
      displaySavefileExistsPopup = false;
    }
  }
  else {
    new_game();
    scene = 25;
  }
}