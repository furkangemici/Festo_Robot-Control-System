/**
 * @file   SensorMenu.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the SensorMenu class.
 *
 * The SensorMenu class provides a menu interface for displaying and managing
 * sensor information. It allows the user to view information about IR and Lidar sensors,
 * navigate back, or quit the application.
 */

#include <string>
#include "Menus.h"
#include "SensorInterface.h"
#include "LidarSensor.h"
#include "IRSensor.h"

#ifndef SENSORMENU_H
#define SENSORMENU_H

 /**
   * @class SensorMenu
   * @brief Provides a menu interface for managing sensor-related options.
   *
   * The SensorMenu class inherits from the Menus class and provides options
   * for viewing sensor information, navigating back, or quitting the application.
   */
class SensorMenu : public Menus {
private:
    int state0 = 0; /*!< Initial state for the menu. */
    int state1 = 1; /*!< Alternate state for the menu. */
    std::string choice = "1. IR Sensor Info\n"
        "2. Lidar Sensor Info\n"
        "3. Back\n"
        "4. Quit\n"; /*!< Menu choices displayed to the user. */
public:
    /**
     * @brief Constructor for the SensorMenu class.
     *
     * Initializes the SensorMenu with a reference to the Robot object.
     * @param robot A pointer to the Robot object associated with the menu.
     */
    SensorMenu(Robot* robot) : Menus(robot) {}

    /**
     * @brief Prints the available menu choices.
     *
     * Displays the menu options to the console for the user to select.
     */
    void printChoice() override;

    /**
     * @brief Executes the menu functionality.
     *
     * Runs the menu loop, allowing the user to interact with the sensor-related options.
     * @return True if the menu continues to run, false if the user chooses to quit.
     */
    bool run() override;
};

#endif
