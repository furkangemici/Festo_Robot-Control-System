/**
 * @file App.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the App.h class.
 *
 * This class is responsible for managing the main application, including authentication and menus.
 *
 */

#include <string>
#include "Authentication.h"
#include "ConnectionMenu.h"
#include "SensorMenu.h"
#include "MotionMenu.h"
#include "MapMenu.h"

#ifndef APP_H
#define APP_H

/**
 * @class App
 * @brief Represents the main application that manages authentication and menus.
 */
class App {
private:
	/**
	 * @brief Main menu options for the application.
	 *
	 * The menu provides the user with different options such as connection,
	 * motion control, sensor settings, and map navigation.
	 */
	std::string mainMenu = "1. Connection\n"
		"2. Motion\n"
		"3. Sensor\n"
		"4. Map\n"
		"0. Quit\n";


    /**
     * @brief Authentication object to handle user login.
     */
    Authentication authentication;

    /**
     * @brief Pointer to the ConnectionMenu object for managing connection options.
     */
    ConnectionMenu* connectionMenu;

    /**
     * @brief Pointer to the SensorMenu object for managing sensor settings.
     */
    SensorMenu* sensorMenu;

    /**
     * @brief Pointer to the MotionMenu object for managing robot motion.
     */
    MotionMenu* motionMenu;

    /**
     * @brief Pointer to the MapMenu object for managing the robot's map.
     */
    MapMenu* mapMenu;

    /**
     * @brief Pointer to the Robot object representing the robot instance.
     */
    Robot* robot;



public:
	/**
   * @brief Default constructor for the App class.
   *
   * Initializes the App object by creating instances of Authentication,
   * Robot, ConnectionMenu, SensorMenu, and MotionMenu.
   */
	App() : authentication() {
		robot = new Robot();
		connectionMenu = new ConnectionMenu(robot);
		sensorMenu = new SensorMenu(robot);
		motionMenu = new MotionMenu(robot);
		mapMenu = new MapMenu(robot);
	}

	/**
 * @brief Runs the main application.
 *
 * This function is responsible for executing the main functionality of the application,
 * including authentication and navigating through different menus.
 */
	void run();
};
#endif