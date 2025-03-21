/**
 * @file MapMenu.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the MapMenu class.
 *
 * This class is responsible for managing the map menu of the robot, allowing
 * the user to perform various actions related to the map such as updating,
 * recording, and displaying the map.
 *
 * Inherits from the Menus class to provide a menu interface for the user.
 */
#pragma once

#include "Menus.h"
#include "MAP.h"
#include "Mapper.h"
#include "LidarSensor.h"
#include "IRSensor.h"

 /**
  * @class MapMenu
  * @brief Manages the map-related menu for robot operations.
  *
  * This class provides the user interface for interacting with the map
  * system of the robot. The menu includes options to update the map,
  * record the map, show the map, go back, or quit the program.
  */
class MapMenu : public Menus {
private:
    /**
     * @brief The menu options as a string.
     *
     * Contains the choices available for the user to interact with the map
     * functionalities.
     */
    string choice = "1. Update Map\n"
		"2. Record Map\n"
		"3. Show Map\n"
		"4. Back\n"
		"5. Quit\n";

public:
    /**
     * @brief Constructor for MapMenu.
     *
     * Initializes the menu with the given robot object to interact with.
     *
     * @param robot A pointer to the Robot object to use in this menu.
     */
    MapMenu(Robot* robot) : Menus(robot) {}

    /**
     * @brief Prints the menu choices to the user.
     *
     * Overrides the printChoice method from the Menus class to display the
     * map-related options to the user.
     */
	void printChoice() override;

    /**
     * @brief Runs the selected operation from the menu.
     *
     * Based on the user's input, it performs the corresponding action such
     * as updating the map, recording the map, or showing the map.
     *
     * @return A boolean value indicating whether the operation was successful.
     */
	bool run();
};