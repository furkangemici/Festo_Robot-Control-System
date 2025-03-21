/**
 * @file MotionMenu.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the MotionMenu.h class.
 *
 * This class is responsible for managing the motion menu, which allows the user
 * to control the robot's movement, including moving forward, backward, turning,
 * and other motion-related actions.
 */
#include <string>
#include "Menus.h"
//#include "SensorInterface.h"

#ifndef MOTIONMENU_H
#define MOTIONMENU_H

/**
 * @class MotionMenu
 * @brief Represents the menu for managing robot motion.
 *
 * The MotionMenu class provides options for controlling the robot's motion, such as
 * moving forward, backward, turning, and checking sensor data. The user can select
 * an action to perform based on the available menu choices.
 */
class MotionMenu : public Menus {
private:
	/**
	 * @brief A string containing the available choices in the motion menu.
	 *
	 * This string is displayed to the user, offering choices for various motion actions
	 * like moving the robot forward or backward, turning, or getting sensor information.
	 */
	string choice = "1.Move Robot Forward\n"
	"2.Move Robot Backward\n"
	"3.Turn Robot Left\n"
	"4.Turn Robot Right\n"
	"5.Safe Move Robot Forward\n"
	"6.Safe Move Robot Backward\n"
	"7.Close Wall\n"
	"8.Get Info\n"
	"9.Back\n"
	"0.Quit\n";

	

	

public:
	/**
	 * @brief Constructor for the MotionMenu class.
	 *
	 * Initializes the MotionMenu with a pointer to the Robot object, allowing
	 * interaction with the robot for motion control.
	 *
	 * @param robot Pointer to the Robot object.
	 */
	MotionMenu(Robot* robot) : Menus(robot) {

	}

	/**
	 * @brief Prints the available choices in the motion menu.
	 *
	 * This function outputs the available actions in the motion menu, allowing the
	 * user to select a motion-related operation such as moving forward, backward, or turning.
	 */
	void printChoice() override;

	/**
	 * @brief Runs the motion menu and performs corresponding actions.
	 *
	 * This method displays the motion menu and allows the user to choose various
	 * motion options such as moving forward, backward, turning left or right,
	 * printing the controller status, and returning to the main menu or exiting the program.
	 *
	 * @return Returns true to continue executing the main menu, false to exit the program.
	 */
	bool run();
};
#endif