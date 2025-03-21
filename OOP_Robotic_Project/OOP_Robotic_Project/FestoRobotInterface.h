/**
 * @file   FestoRobotInterface.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the FestoRobotInterface class.
 *
 * This class extends the RobotInterface to provide a specific implementation
 * for controlling the robot using the FestoRobotAPI.
 */
#include <vector>
#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "Pose.h"
#include "RobotInterface.h"
#include "SensorInterface.h"

#ifndef NAOROBOTINTERFACE_H
#define NAOROBOTINTERFACE_H


 /**
  * @class FestoRobotInterface
  * @brief Extends RobotInterface to interact with the FestoRobotAPI.
  *
  * The FestoRobotInterface class provides an abstraction for controlling a robot
  * using the FestoRobotAPI. It defines various movement commands and sensor management
  * features for controlling and interacting with the robot.
  */
class FestoRobotInterface : public RobotInterface
{
private:
    FestoRobotAPI* robotAPI;/*!< Pointer to the FestoRobotAPI for robot interactions. */

public:
    /**
    * @brief Constructor for the FestoRobotInterface class.
    *
    * Initializes the robot interface with a reference to the FestoRobotAPI.
    * @param _robotAPI A pointer to the FestoRobotAPI object for API interactions.
    */
    FestoRobotInterface(FestoRobotAPI* _robotAPI);

    /**
     * @brief Turns the robot to the left.
     */
    void turnLeft() override;

    /**
     * @brief Turns the robot to the right.
     */
    void turnRight() override;

    /**
     * @brief Moves the robot forward.
     */
    void moveForward() override;

    /**
     * @brief Moves the robot backward.
     */
    void moveBackward() override;

    /**
     * @brief Moves the robot to the left.
     */
    void moveLeft() override;

    /**
     * @brief Moves the robot to the right.
     */
    void moveRight() override;

    /**
     * @brief Stops the robot.
     */
    void stop() override;

    /**
     * @brief Gets the current pose of the robot.
     * @return A pointer to the Pose object representing the robot's position.
     */
    Pose* getPose() override;

    /**
     * @brief Prints the robot's current status.
     */
    void print() override;

    /**
     * @brief Connects the robot to the interface.
     * @return True if the robot was successfully connected, false otherwise.
     */
    bool connectRobot() override;

    /**
     * @brief Disconnects the robot from the interface.
     * @return True if the robot was successfully disconnected, false otherwise.
     */
    bool disconnectRobot() override;

    /**
     * @brief Updates the positions of the robot.
     */
    void updatePositions();

    /**
     * @brief Gets the sensors connected to the robot.
     * @return A vector containing pointers to the SensorInterface objects.
     */
    std::vector<SensorInterface*> getSensors();

    /**
     * @brief Moves the robot forward with safety checks.
     */
    void moveForwardSafe() override;

    /**
     * @brief Moves the robot backward with safety checks.
     */
    void moveBackwardSafe() override;
};

#endif