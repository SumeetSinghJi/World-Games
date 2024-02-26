/*
    Author: Sumeet Singh
    Dated: 14/02/2024
    Minimum C++ Standard: C++11
    Purpose: Declaration/Definition file combined
    License: MIT License
    Description: read the attached help.txt file
*/

#pragma once

#include <iostream>
// #include <zip.h>      // for unzipping downloaded game from GitHub/source repo
#include "../src/libzip/lib/zip.h"
#include <fstream>    // multiplatform method for for file open read write objects
#include <filesystem> // multiplatform method for creating and deleting directories (folders)
#include <string>     // For getline()
#include <cstdlib>    // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,

// GLOBAL VARIABLES
extern std::string os_version;
extern std::string zip_file_path;

// Extract Zip of downloaded game update from curl of Github repo
bool extract_zip()
{
    struct zip *zip_archive;
    struct zip_file *zip_file;
    struct zip_stat zip_stat;
    char buf[100];

    // Get the directory path from the zip_file_path
    std::filesystem::path zip_directory = std::filesystem::path(zip_file_path).parent_path();

    std::cout << "Starting Extract Zip function..." << std::endl;

    // Open the zip archive
    zip_archive = zip_open(zip_file_path.c_str(), ZIP_RDONLY, nullptr);
    if (zip_archive == nullptr)
    {
        std::cout << "Error opening zip archive." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Zip archive opened successfully." << std::endl;
    }

    // Get the number of entries in the zip archive
    int num_entries = zip_get_num_entries(zip_archive, 0);
    std::cout << "Number of entries in the zip archive: " << num_entries << std::endl;

    // Extract each entry in the zip archive
    for (int i = 0; i < num_entries; i++)
    {
        // Get information about the current entry
        if (zip_stat_index(zip_archive, i, 0, &zip_stat) == 0)
        {
            // Get the name of the entry
            std::string entry_name = zip_get_name(zip_archive, i, 0);

            // Check if the entry is a directory
            bool is_directory = entry_name.back() == '/';

            // Create full output file path
            std::filesystem::path output_file_path = std::filesystem::path(zip_directory) / entry_name;

            if (!is_directory)
            {
                // If it's a file, open the entry
                zip_file = zip_fopen_index(zip_archive, i, ZIP_FL_UNCHANGED);
                if (zip_file == nullptr)
                {
                    std::cout << "Error opening file in zip archive." << std::endl;
                    zip_close(zip_archive);
                    return false;
                }
                else
                {
                    std::cout << "Opened entry " << i << " in the zip archive." << std::endl;
                }

                // Create directories if needed using filesystem
                std::filesystem::create_directories(output_file_path.parent_path());

                // Open the output file
                FILE *output_file = fopen(output_file_path.string().c_str(), "wb");
                if (output_file == nullptr)
                {
                    std::cout << "Error creating output file." << std::endl;
                    zip_fclose(zip_file);
                    zip_close(zip_archive);
                    return false;
                }
                else
                {
                    std::cout << "Created output file: " << output_file_path.string() << std::endl;
                }

                // Extract the current entry and write it to the output file
                zip_int64_t n;
                while ((n = zip_fread(zip_file, buf, sizeof(buf))) > 0)
                {
                    fwrite(buf, n, 1, output_file);
                }

                // Close the output file and the current entry
                fclose(output_file);
                zip_fclose(zip_file);

                std::cout << "Zip entry extracted successfully." << std::endl;
            }
            else
            {
                // If it's a directory, create the directory
                std::filesystem::create_directories(output_file_path);
                std::cout << "Created directory: " << output_file_path.string() << std::endl;
            }
        }
        else
        {
            std::cout << "Error getting information about zip entry." << std::endl;
            zip_close(zip_archive);
            return false;
        }
    }

    std::cout << "Game updates unzipped successful." << std::endl;
    std::cout << "Press ENTER key to continue..." << std::endl;

    // Close the zip archive
    zip_close(zip_archive);
    return true;
}

// Getting filepath to existing non updated folder "world-games"
std::string get_existing_game_folder_path()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;
    std::string existing_game_directory_path = "";

    if (os_version == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE");
        existing_game_directory_path = std::string(home_directory) + filepath_separator + "world-games";
    }
    else if (os_version == "linux" || os_version == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME");
        existing_game_directory_path = std::string(home_directory) + filepath_separator + "world-games";
    }
    else
    {
        std::cout << "Error: filepath to 'world-games' under users Home directory not found! " << std::endl;
    }
    return existing_game_directory_path;
}

// Getting filepath to unzipped folder "world-games-master"
std::string get_unzipped_game_destination_path()
{
    std::string filepath_separator = "";
    const char *home_directory = nullptr;
    std::string unzipped_game_destination_path = "";

    if (os_version == "Windows")
    {
        filepath_separator = '\\';
        home_directory = getenv("USERPROFILE");
        unzipped_game_destination_path = std::string(home_directory) + filepath_separator + "world-games-master";
    }
    else if (os_version == "linux" || os_version == "Mac OS X")
    {
        filepath_separator = '/';
        home_directory = getenv("HOME");
        unzipped_game_destination_path = std::string(home_directory) + filepath_separator + "world-games-master";
    }
    else
    {
        std::cout << "Error: filepath to 'world-games-master' unzipped updated game folder under users Home directory not found! " << std::endl;
    }
    return unzipped_game_destination_path;
}

// Copy save from original game directory "world-games" to unzipped folder "world-games-master"
void copy_save_to_extracted_folder()
{
    std::cout << "STARTING - copy save from original directory to unzipped new updated game folder" << std::endl;

    std::filesystem::path sourceDirectory = get_existing_game_folder_path();
    std::filesystem::path sourcePath = sourceDirectory / "world-games_save.txt";
    std::filesystem::path destinationDirectory = get_unzipped_game_destination_path();
    std::filesystem::path destinationPath = destinationDirectory / "world-games_save.txt"; // Include the filename

    try
    {
        // Check if the source file exists
        if (std::filesystem::exists(sourcePath))
        {
            // Check if the destination file exists
            if (std::filesystem::exists(destinationPath))
            {
                // Delete the existing destination file
                std::filesystem::remove(destinationPath);
                std::cout << "Existing destination file deleted." << std::endl;
            }

            // Copy the file
            std::filesystem::copy_file(sourcePath, destinationPath, std::filesystem::copy_options::overwrite_existing);

            std::cout << "File copied successfully." << std::endl;
        }
        else
        {
            std::cerr << "Source file not found." << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Press ENTER key to continue..." << std::endl;
    std::cin.get();
}

// Close existing world-games executable
void exit_game()
{
    std::cout << "STARTING - Close game" << std::endl;
    std::string windows_terrinate_process_command = "taskkill /F /IM main.exe";
    std::string unix_terrinate_process_command = "pkill main";

    if (os_version == "Windows")
    {
        system(windows_terrinate_process_command.c_str());
    }
    else
    {
        system(unix_terrinate_process_command.c_str());
    }
}

// Function to delete a directory and its contents using the rmdir command
void delete_directory(const std::string &folderPath)
{
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.is_directory())
        {
            // Check if the directory is hidden by checking its name
            if (!entry.path().filename().string().empty() && entry.path().filename().string()[0] == '.')
            {
                // Delete the hidden folder and its contents using the rmdir command
                std::string command = "rmdir /s /q \"" + entry.path().string() + "\"";
                int result = system(command.c_str());

                if (result == 0)
                {
                    std::cout << "Directory deleted: " << entry.path().string() << std::endl;
                }
                else
                {
                    std::cerr << "Error deleting directory: " << entry.path().string() << std::endl;
                }
            }
            else
            {
                delete_directory(entry.path().string());
            }
        }
        else if (entry.is_regular_file())
        {
            try
            {
                std::filesystem::remove(entry);
            }
            catch (const std::filesystem::filesystem_error &exception)
            {
                std::cerr << "Error deleting file: " << exception.what() << std::endl;
            }
        }
    }

    // Use the rmdir command to delete the current directory

    if (os_version == "Windows")
    {
        std::string command = "rmdir /s /q \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
        }
    }
    else
    {
        std::string command = "rm -r \"" + folderPath + "\"";
        int result = system(command.c_str());

        if (result == 0)
        {
            std::cout << "Directory deleted: " << folderPath << std::endl;
        }
        else
        {
            std::cerr << "Error deleting directory: " << folderPath << std::endl;
        }
    }
}

// Delete original game directory and its subdirectories
void delete_original_game_directory_subdirectories()
{
    std::cout << "STARTING - delete original game directory - subdirectories" << std::endl;
    std::cout << "Existing game folder to be deleted is: " << get_existing_game_folder_path() << std::endl;
    std::string existing_game_folder_path = get_existing_game_folder_path();

    // Call the recursive delete_directory function
    delete_directory(existing_game_folder_path);
}

// Delete original game directory
void delete_original_game_folder()
{
    std::cout << "STARTING - delete original game directory" << std::endl;
    std::cout << "Existing game folder to be deleted is: " << get_existing_game_folder_path() << std::endl;
    std::string existing_game_folder_path = get_existing_game_folder_path();

    if (os_version == "Windows")
    {
        try
        {
            std::filesystem::remove_all(existing_game_folder_path); // Use remove_all to delete hidden folders as well
            std::cout << "Original game directory deleted." << std::endl;
        }
        catch (const std::filesystem::filesystem_error &exception)
        {
            std::cout << "Error deleting original game directory: " << exception.what() << std::endl;
        }
    }
    else if (os_version == "linux" || os_version == "Mac OS X")
    {
        std::cout << "delete original game directory Work in progress" << std::endl;
    }
}

// Rename unzipped new updated game folder "world-games-master" to "world-games"
void rename_extracted_folder()
{
    std::string worldgames_master_folder_path_old_name = get_unzipped_game_destination_path();
    std::string worldgames_master_folder_path_new_name = get_existing_game_folder_path();

    std::cout << "STARTING - rename unzipped folder to world-games" << std::endl;
    try
    {
        rename(worldgames_master_folder_path_old_name.c_str(), worldgames_master_folder_path_new_name.c_str());
        std::cout << "Unzipped folder sucessfully rename from 'world-games-master' to 'world-games'." << std::endl;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error renaming Unzipped folder from 'world-games-master' to 'world-games': " << e.what() << std::endl;
    }
}

// TEST THEN DEPLOY - Run CMAKE, to copy shortcut to desktop
void CMAKE_build()
{
    std::cout << "Running CMAKE build steps to copy shortcuts to desktop" << std::endl;
    if (os_version == "Windows")
    {
        std::string scriptPath = "windows-add-icon.ps1";
        int result = system(("powershell.exe -ExecutionPolicy Bypass -File " + std::string(scriptPath)).c_str());
        if (result == 0)
        {
            std::cout << "Succesfully copied shortcut to users desktop" << std::endl;
        }
        else
        {
            std::cout << "Error: Failed to copy shortcut to users desktop" << std::endl;
        }
    }
    else if (os_version == "linux" || os_version == "Mac OS X")
    {
        std::cout << "CMAKE for Linux/MacOS Work in progress" << std::endl;
    }
}

// TEST THEN DEPLOY - Open new game executable or binary to complete update game step
void game_start()
{
    std::cout << "STARTING - Opening game executable or binary" << std::endl;
    std::string new_game_directory_path = get_existing_game_folder_path();
    std::string start_command;

    if (os_version == "Windows")
    {
        start_command = "start \"\" \"" + new_game_directory_path + "\\world-games.exe\"";
        system(start_command.c_str());
    }
    else
    {
        start_command = "chmod +x \"" + new_game_directory_path + "/world-games.bin\"";
        system(start_command.c_str());
    }
}