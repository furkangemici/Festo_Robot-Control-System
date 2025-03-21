/**
 * @file Menus.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the Menus.h class.
 *
 * This class serves as a base class for different menus in the application,
 * providing a common interface for menu-related functionality such as displaying
 * choices and running actions associated with each menu.
 */
#pragma once

#include <string>
#include "Robot.h"

#ifndef MENUS_H
#define MENUS_H

 /**
   * @class Menus
   * @brief Represents a base class for different menus in the application.
   *
   * The Menus class provides a basic framework for managing menus within the application.
   * It contains functionality for printing menu choices and running the menu logic.
   * Derived classes can extend this class to implement specific behavior for various menus.
   */
class Menus {
protected:
	/**
	 * @brief Error message for connection issues.
	 *
	 * This message is shown when an action is attempted without establishing
	 * a connection with the robot.
	 */
	std::string connectionErr = "Please connect to robot before this action!";

	/**
	 * @brief Pointer to the Robot object representing the robot.
	 *
	 * This pointer allows the menu classes to interact with the robot, accessing
	 * and manipulating its state as required by the specific menu.
	 */
	Robot* robot;

public:
	/**
	 * @brief Constructor for the Menus class.
	 *
	 * Initializes the Menus object with a pointer to a Robot object. This enables
	 * menu classes to access and control the robot.
	 *
	 * @param _robot Pointer to the Robot object to associate with this menu.
	 */
	Menus(Robot* _robot) : robot(_robot) {}


	/**
	 * @brief Virtual function to print menu choices.
	 *
	 * This function is virtual and can be overridden in derived classes to
	 * print the available choices for the menu. By default, it does nothing.
	 */
	virtual void printChoice() { return; }

	/**
	 * @brief Virtual function to run the menu.
	 *
	 * This function is virtual and may be overridden in derived classes to
	 * execute the specific functionality of the menu.
	 *
	 * @return Returns false by default, indicating no specific action to continue.
	 */
	virtual bool run() { return false; }
};

#endif