/**
 * @file SafeNavigation.h
 * @Author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Header file for the SafeNavigation class.
 *
 * This file contains the declaration of the SafeNavigation class, which
 * provides functionality for safe robot navigation by managing movement states
 * and avoiding obstacles using an infrared sensor.
 */

#pragma once 

#include "IRSensor.h"
#include "RobotControler.h"

 //! An enumeration representing the movement states of the robot.
 /*!
  * MOVING: The robot is currently moving.
  * STOP: The robot is currently stopped.
  */
enum MOVESTATE { MOVING, STOP };

//! A class for safe robot navigation.
/*!
 * This class integrates an IR sensor and a robot controller to allow the robot
 * to move forward and backward safely, avoiding obstacles.
 */
class SafeNavigation {
private:
    //! Pointer to the infrared sensor used for obstacle detection.
    IRSensor* IR;

    //! Pointer to the robot controller responsible for movement commands.
    RobotControler* controler;

    //! Current movement state of the robot.
    MOVESTATE state;
public:
    //! Constructor.
    /*!
     * Initializes the SafeNavigation object with the provided IR sensor and robot controller.
     * @param ir Pointer to an IRSensor object.
     * @param ctrl Pointer to a RobotControler object.
     */
    SafeNavigation(IRSensor* ir, RobotControler* ctrl);

    //! Moves the robot forward safely.
    /*!
     * The robot moves forward until it is within 0.5 meters of an obstacle, then stops.
     */
    void moveForwardSafe();

    //! Moves the robot backward safely.
    /*!
     * The robot moves backward until it is within 0.5 meters of an obstacle, then stops.
     */
    void moveBackwardSafe();

    //! Gets the current movement state of the robot.
    /*!
     * @return The current movement state (MOVING or STOP).
     */
    MOVESTATE getState() const { return state; }
};
