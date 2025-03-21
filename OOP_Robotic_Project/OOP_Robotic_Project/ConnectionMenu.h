/**
 * @file ConnectionMenu.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the ConnectionMenu class for managing the robot connection menu.
 *
 * This class is responsible for managing the connection menu, allowing the user to
 * connect or disconnect the robot, as well as navigate through the menu options.
 */
#pragma once
#pragma once

#include "Menus.h"

 /**
   * @class ConnectionMenu
   * @brief Represents the menu for managing robot connections.
   *
   * The ConnectionMenu class provides the functionality to connect and disconnect
   * the robot, as well as navigate through different menu options such as going back
   * to the main menu or quitting the program.
   */
class ConnectionMenu : public Menus {
private:
	/**
	 * @brief A string that holds the choices available in the connection menu.
	 *
	 * This string is displayed to the user, allowing them to choose from connecting,
	 * disconnecting, going back to the previous menu, or quitting.
	 */
	std::string choice = "1. Connect Robot\n"
		"2. Disconnect Robot\n"
		"3. Back\n"
		"4. Quit\n";
public:
	/**
	 * @brief Constructor for the ConnectionMenu class.
	 *
	 * Initializes the ConnectionMenu with a pointer to the Robot object, allowing
	 * interaction with the robot for connecting and disconnecting.
	 *
	 * @param robot Pointer to the Robot object.
	 */
	ConnectionMenu(Robot* robot) : Menus(robot) {}

	/**
	 * @brief Prints the available choices in the connection menu.
	 *
	 * This method displays the available actions in the connection menu, such as
	 * connecting, disconnecting, returning to the previous menu, or quitting.
	 */
	void printChoice() override;

	/**
	 * @brief Runs the connection menu and performs corresponding actions.
	 *
	 * This method allows the user to interact with the connection menu. Based on the
	 * user's choice, it can either connect the robot, disconnect it, go back to the
	 * previous menu, or exit the application.
	 *
	 * @return Returns true to continue executing the main menu, false to exit the program.
	 */
	bool run() override;
};