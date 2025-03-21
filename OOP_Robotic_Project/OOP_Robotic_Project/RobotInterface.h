/**
 * @file RobotInterface.h
 * @author
 * Cem Levent Avcý
 * @date December, 2024
 * @brief Declaration of the RobotInterface class.
 *
 * This abstract class defines the interface for managing the robot's movements,
 * sensors, and connection status. It provides pure virtual functions to be implemented
 * by derived classes for robot-specific functionality.
 */
#include <vector>
#include "Pose.h"
#include "SensorInterface.h"
#include "LidarSensor.h"
#include "IRSensor.h"

#ifndef ROBOT_INTERFACE_H
#define ROBOT_INTERFACE_H


 /**
  * @class RobotInterface
  * @brief Abstract base class for managing a robot's interface and interactions.
  *
  * The RobotInterface class defines the core functionalities required for controlling
  * a robot, including movement, sensor updates, and connection management.
  */
class RobotInterface
{
protected:
    Pose* position; /*!< Pointer to the robot's position information. */
    bool connectionStatus; /*!< Indicates whether the robot is connected. */
    std::vector<SensorInterface*>* sensorList = new std::vector<SensorInterface*>; /*!< List of sensors attached to the robot. */

public:
    /**
     * @brief Virtual destructor for RobotInterface.
     *
     * Cleans up the dynamically allocated `position` object.
     */
    virtual ~RobotInterface() { delete position; }

    /**
     * @brief Turns the robot left.
     */
    virtual void turnLeft() = 0;

    /**
     * @brief Turns the robot right.
     */
    virtual void turnRight() = 0;

    /**
     * @brief Moves the robot forward.
     */
    virtual void moveForward() = 0;

    /**
     * @brief Moves the robot backward.
     */
    virtual void moveBackward() = 0;

    /**
     * @brief Moves the robot left.
     */
    virtual void moveLeft() = 0;

    /**
     * @brief Moves the robot right.
     */
    virtual void moveRight() = 0;

    /**
     * @brief Stops the robot's movement.
     */
    virtual void stop() = 0;
    

    /**
     * @brief Retrieves the robot's current position.
     * @return A pointer to a Pose object representing the robot's position.
     */
    virtual Pose* getPose() = 0;

    /**
     * @brief Prints the robot's status and information.
     */
    virtual void print() = 0;

    /**
     * @brief Connects the robot to the system.
     * @return `true` if the connection is successful, otherwise `false`.
     */
    virtual bool connectRobot() = 0;

    /**
     * @brief Disconnects the robot from the system.
     * @return `true` if the disconnection is successful, otherwise `false`.
     */
    virtual bool disconnectRobot() = 0;

    /**
     * @brief Updates the sensor data for all attached sensors.
     */
    virtual void updateSensors();

    /**
     * @brief Adds a sensor to the robot's sensor list.
     * @param sensor Pointer to a SensorInterface object to be added.
     */
    virtual void addSensor(SensorInterface* sensor);

    /**
     * @brief Retrieves the list of sensors attached to the robot.
     * @return A vector containing pointers to SensorInterface objects.
     */
    virtual std::vector<SensorInterface*> getSensors() const;

    /**
     * @brief Moves the robot forward while ensuring obstacle avoidance.
     */
    virtual void moveForwardSafe() = 0;

    /**
     * @brief Moves the robot backward while ensuring obstacle avoidance.
     */
    virtual void moveBackwardSafe() = 0;


};

#endif // ROBOT_INTERFACE_H