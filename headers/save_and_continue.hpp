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

void new_game();

void save_settings() {
  // on settingsSaveRect in mouse handle save settings
}

void save_game()
{
  std::ofstream savefile_object("world-games_save.txt");

  if (savefile_object.is_open())
  {
    savefile_object << "unlockedScenes: ";
    for (size_t i = 0; i < unlockedScenes.size(); ++i)
    {
      savefile_object << unlockedScenes[i];
      if (i != unlockedScenes.size() - 1)
      {
        savefile_object << ",";
      }
    }
    savefile_object << "\n";
    savefile_object << "unlockedAchievements: ";
    for (size_t i = 0; i < unlockedAchievements.size(); ++i)
    {
      savefile_object << unlockedAchievements[i];
      if (i != unlockedAchievements.size() - 1)
      {
        savefile_object << ",";
      }
    }
    savefile_object << "\n";

    savefile_object.close();
    std::cout << "Game saved" << std::endl;
  }
  else
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }
}

void load_game()
{
  std::ifstream savefile_object("world-games_save.txt");

  if (savefile_object.is_open())
  {
    std::cout << "Loading save..." << std::endl;
    std::string line;

    while (getline(savefile_object, line))
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
    savefile_object.close();
    std::cout << "Save loaded..." << std::endl;
    scene = 25; // Scene 6 = world map
  }
  else
  {
    std::cerr << "Error: Unable to open save file." << std::endl;
  }
}

void does_save_file_exist()
{
  std::cout << "Checking to see if any saves exist" << std::endl;
  std::string filename = "world-games_save.txt";
  if (std::ifstream(filename))
  {
    std::cout << "Save file exists" << filename << "Do you want to delete it? (y/n)";
    char response;
    std::cin >> response;
    if (response == 'y' || response == 'Y')
    {
      std::remove(filename.c_str());
      new_game();
    }
    else
    {
      std::cout << "Save game not deleted. Loading saved game..." << std::endl;
      load_game();
    }
  }
  else
  {
    std::cout << "Save game doesn't exist." << std::endl;
    new_game();
  }
}