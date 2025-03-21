/**
 * @file   LidarSensor.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the LidarSensor class.
 *
 * This class provides functionality for interacting with a Lidar sensor.
 * It supports reading range values, finding minimum and maximum ranges,
 * and retrieving sensor information. The class inherits from the
 * FestoRobotSensorInterface to integrate with a robotic system.
 */

#pragma once

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include "SensorInterface.h"
#include "FestoRobotSensorInterface.h"

 /**
  * @class LidarSensor
  * @brief Provides functionality to interact with a Lidar sensor.
  *
  * The LidarSensor class dynamically stores range measurements from the Lidar sensor
  * and provides utility functions to access sensor data, print information, and
  * retrieve sensor properties. It integrates with the robotic system via the
  * FestoRobotSensorInterface.
  */
class LidarSensor : public FestoRobotSensorInterface {
private:
    double* ranges;           /*!< Array to dynamically store Lidar range values. */
    int rangeNumber;          /*!< Number of ranges measured by the Lidar sensor. */
    

public:
    /**
     * @brief Constructor for the LidarSensor class.
     *
     * Initializes the LidarSensor object and associates it with a FestoRobotAPI instance.
     * @param robotAPI A pointer to the FestoRobotAPI instance used for sensor interaction.
     */
    LidarSensor(FestoRobotAPI* robotAPI);
   
    /**
     * @brief Destructor for the LidarSensor class.
     *
     * Frees dynamically allocated memory and cleans up resources used by the sensor.
     */
    ~LidarSensor();

    /**
     * @brief Updates the sensor readings.
     *
     * Fetches the latest range measurements from the sensor and stores them in
     * the internal array.
     */
    void updateSensor();

    /**
     * @brief Retrieves the range value at the specified index.
     *
     * @param index The index of the range value to retrieve.
     * @return The range value at the given index.
     * @throws std::out_of_range if the index is invalid.
     */
    double getRange(int index) const;

    /**
     * @brief Finds the minimum range value and its index.
     *
     * @param index A reference to store the index of the minimum range value.
     * @return The minimum range value.
     */
    double getMin(int& index) const;

    /**
     * @brief Finds the maximum range value and its index.
     *
     * @param index A reference to store the index of the maximum range value.
     * @return The maximum range value.
     */
    double getMax(int& index) const;

    /**
     * @brief Overloaded subscript operator to access range values.
     *
     * Provides direct access to range values using the subscript notation.
     * @param i The index of the range value to retrieve.
     * @return The range value at the specified index.
     * @throws std::out_of_range if the index is invalid.
     */
    double operator[](int i) const;

    /**
     * @brief Retrieves the angle corresponding to a range value.
     *
     * @param i The index of the range value.
     * @return The angle at the specified index.
     * @throws std::out_of_range if the index is invalid.
     */
    double getAngle(int i) const;

    /**
     * @brief Retrieves the sensor type as a string.
     *
     * Provides the type of the sensor (e.g., "Lidar").
     * @return The type of the sensor.
     */
    string getSensorType() override;
    
    /**
     * @brief Retrieves the sensor value at the specified position.
     *
     * @param index The position index for which the sensor value is needed.
     * @return The sensor value at the given position.
     */
    double getSensorValue(int index);

    /**
     * @brief Retrieves the number of ranges measured by the sensor.
     *
     * @return The number of ranges measured by the sensor.
     */
    double getRangeNumber() const;
    /**
     * @brief Prints the sensor data to the console.
     *
     * Outputs the current sensor readings for debugging or monitoring purposes.
     */
    void printSensor() override;
    
    /**
     * @brief Initializes the Lidar sensor.
     *
     * Prepares the sensor for operation, ensuring it is ready to take measurements.
     */
    void initializeLidarSensor();

};
