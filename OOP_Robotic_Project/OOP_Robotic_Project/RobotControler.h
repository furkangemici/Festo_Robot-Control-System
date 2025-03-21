#pragma once
/**
 * @file   RobotControler.h
 * @Author Cem Levent Avcý (cemlevent54@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the RobotControler class.
 *
 * This file contains the declaration of the RobotControler class, which is used
 * to control the movement of a robot in a 2D space. It provides methods for controlling
 * the robot's movements, managing sensors, and handling access control.
 */

#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Pose.h"
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "Record.h"
#include "RobotOperator.h"
#include "RobotControler.h"
#include <vector>
#include "FestoRobotInterface.h"


//! RobotControler class
/*!
 * @brief Controls the movement and operation of a robot in a 2D space.
 *
 * The RobotControler class provides functionalities to control a robot's movement,
 * manage its sensors, and handle access control via the RobotOperator.
 */
class RobotControler {
private:
    RobotInterface* robot;          /*!< Pointer to the robot interface for controlling the robot. */
    RobotOperator robotOperator;    /*!< Operator handling access control for the robot. */
    const string name = "cem";      /*!< Default name of the robot operator. */
    const string surname = "avci";  /*!< Default surname of the robot operator. */
    unsigned int accessCode;        /*!< Access code for controlling the robot. */
    Record record;                  /*!< Record object for logging robot activities. */

public:
    
    //! Constructor.
    /*!
     * Initializes the RobotControler object with a robot interface.
     * @param _robot Pointer to the FestoRobotInterface object.
     */
    RobotControler(FestoRobotInterface* _robot);

    //! Destructor.
    /*!
     * Cleans up resources used by the RobotControler object.
     */
    ~RobotControler();

    //! Turns the robot left.
    void turnLeft();

    //! Turns the robot right.
    void turnRight();

    //! Moves the robot forward.
    void moveForward();

    //! Moves the robot backward.
    void moveBackward();

    //! Moves the robot left.
    void moveLeft();

    //! Moves the robot right.
    void moveRight();

    //! Stops the robot.
    void stop();

    //! Gets the current pose of the robot.
    /*!
     * @return The current pose (x, y, theta) of the robot.
     */
    Pose getPose();

    //! Prints the robot's current state.
    void print();

    //! Connects to the robot.
    /*!
     * @return True if the connection is successful, false otherwise.
     */
    bool connectRobot();

    //! Disconnects from the robot.
    /*!
     * @return True if the disconnection is successful, false otherwise.
     */
    bool disconnectRobot();

    //! Adds a sensor to the robot.
    /*!
     * @param sensor Pointer to the sensor to be added.
     */
    void addSensor(SensorInterface* sensor);

    //! Updates all sensors of the robot.
    void updateSensors();

    //! Opens access to the robot using an access code.
    /*!
     * @param accessCode The access code to authorize.
     * @return True if access is successfully opened, false otherwise.
     */
    bool openAccess(int accessCode);

    //! Closes access to the robot using an access code.
    /*!
     * @param accessCode The access code to revoke.
     * @return True if access is successfully closed, false otherwise.
     */
    bool closeAccess(int accessCode);

    //! Prints information about a specific type of sensor.
    /*!
     * @param sensorType The type of sensor to print information about.
     */
    void print(const string& sensorType);

    //! Gets a sensor by its type.
    /*!
     * @param sensorType The type of the sensor to retrieve.
     * @return Pointer to the SensorInterface object corresponding to the sensor type.
     */
    SensorInterface* getSensor(string sensorType);

    //! Moves the robot forward safely.
    /*!
     * Ensures that no obstacles are detected before moving forward.
     */
    void moveForwardSafe();

    //! Moves the robot backward safely.
    /*!
     * Ensures that no obstacles are detected before moving backward.
     */
    void moveBackwardSafe();
};
