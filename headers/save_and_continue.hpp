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

bool savefileExists = false; // used in SDL_mouse_handles.hpp
int overwriteGame = 0;
std::string saveFileName = "world-games_save.txt";

void new_game();

bool save_settings() {
    std::fstream file(saveFileName); // replaces ifstream (reading) and ofstream (writing) for both
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open save file." << std::endl;
        return false;
    }

    // Read the entire file into a string
    std::string fileContents;
    std::string line;
    while (std::getline(file, line)) {
        fileContents += line + '\n';
    }

    // Find and replace the lines containing strings, e.g., "Language: " and "Font size: ", with the updated lines
    size_t pos_language = fileContents.find("Language: ");
    size_t pos_fontsize = fileContents.find("Font size: ");
    if (pos_language != std::string::npos && pos_fontsize != std::string::npos) {
        size_t end_language = fileContents.find("\n", pos_language);
        size_t end_fontsize = fileContents.find("\n", pos_fontsize);
        fileContents.replace(pos_language, end_language - pos_language, "Language: " + language);
        fileContents.replace(pos_fontsize, end_fontsize - pos_fontsize, "Font size: " + fontSize);
    } else {
        // If the lines "Language: " or "Font size: " don't exist, add them
        if (pos_language == std::string::npos) {
            fileContents = "Language: " + language + '\n' + fileContents;
        }
        if (pos_fontsize == std::string::npos) {
            fileContents = "Font size: " + fontSize + '\n' + fileContents;
        }
    }

    // Reset file pointer to the beginning and write the modified contents back to the file
    file.clear(); // Clear any error flags
    file.seekp(0, std::ios::beg); // Move to the beginning of the file
    file << fileContents;
    file.close(); // Close the file

    return true;
}

bool load_settings()
{
  // The purpose of this is to load variables from save_settings()
  std::ifstream file(saveFileName);
  if (!file.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line))
  {
    if (line.find("Language: ") != std::string::npos)
    {

      std::istringstream iss(line);
      std::string word;
      // Extract the second word after "Language: "
      if (iss >> word && iss >> word)
      {
        language = word;
      }
    }
  }
  return true;
}

bool save_game()
{
  // fstream replaces ifstream (reading) and ofstream (writing) for both
  // , std::fstream::app indicates to create the file if it doesn't exist
  std::fstream savefileObject(saveFileName, std::fstream::app);
  if (!savefileObject.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
    return false;
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
        savefileObject << ",";
      }
    }
    savefileObject << "\n";

    savefileObject.close();
    std::cout << "Game saved" << std::endl;
  }
  return true;
}

bool load_game()
{
  // The purpose of this is to load variables from save_game()
  std::fstream savefileObject(saveFileName); // replaces ifstream (reading) and ofstream (writing) for both
  if (!savefileObject.is_open())
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
    return false;
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
  return true;
}

void does_save_file_exist()
{
  std::cout << "Checking to see if any saves exist" << std::endl;

  if (std::ifstream(saveFileName))
  {
    std::cout << "Save file exists: " << saveFileName << "Do you want to delete it? (y/n)";
    savefileExists = true;
    if (overwriteGame == 1)
    {
      std::remove(saveFileName.c_str());
      new_game();
      scene = 25;
      overwriteGame = 0;
    }
    else if (overwriteGame == 2)
    {
      std::cout << "Save game not deleted. Loading saved game..." << std::endl;
      load_game();
      overwriteGame = 0;
    }
  }
  else
  {
    std::cout << "Save game doesn't exist." << std::endl;
    new_game();
    scene = 25;
  }
}