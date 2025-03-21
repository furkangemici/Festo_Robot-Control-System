/**
 * @file Robot.h
 * @author Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the Robot class.
 *
 * This class is responsible for managing the robot's components and interactions.
 * It acts as a centralized controller for various subsystems such as sensors,
 * navigation, and mapping. This class integrates multiple interfaces to allow
 * effective interaction and operation of the robot.
 */
#pragma once

#include "RobotControler.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include <iostream>
#include <string>
#include "IRSensor.h"
#include "LidarSensor.h"
#include "FestoRobotInterface.h"
#include "SafeNavigation.h"
#include "Mapper.h"

 /**
  * @class Robot
  * @brief Manages the robot's components and interactions.
  *
  * The Robot class initializes and integrates different components of the robot,
  * including sensors, navigation, and mapping systems. It serves as the central
  * point for coordinating robot functionalities.
  */
class Robot {
public:
    FestoRobotAPI* robotAPI;           /*!< Pointer to the FestoRobotAPI for simulator interaction. */
    RobotControler* robotControler;   /*!< Pointer to the RobotControler for motion management. */
    SafeNavigation* safeNavigation;   /*!< Pointer to the SafeNavigation for obstacle avoidance. */
    FestoRobotInterface* robot;       /*!< Pointer to the FestoRobotInterface for robot operations. */
    IRSensor* irSensor;               /*!< Pointer to the IRSensor for IR sensor data. */
    LidarSensor* lidarSensor;         /*!< Pointer to the LidarSensor for Lidar sensor data. */
    Mapper* mapper;                   /*!< Pointer to the Mapper for map creation and updates. */

    /**
     * @brief Default constructor for the Robot class.
     *
     * Initializes all the robot's components and subsystems, setting up the
     * necessary interfaces for robot operation.
     */
    Robot();
};