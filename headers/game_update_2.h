#ifndef game_update_2
#define game_update_2

#include <iostream>
#include <cstring>
#include <filesystem>
#include <cstdlib> // multiplatform e.g. std::system("pkill") to run system commands e.g terminate app,

extern std::string os_version;

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
void deleteDirectory(const std::string &folderPath)
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
                deleteDirectory(entry.path().string());
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

    // Call the recursive deleteDirectory function
    deleteDirectory(existing_game_folder_path);
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
    } else if (os_version == "linux" || os_version == "Mac OS X")
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

#endif
