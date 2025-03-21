/**
 * @file   IRSensor.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the IRSensor class.
 *
 * This class provides functionality for interacting with an infrared (IR) sensor.
 * It allows reading distance values, updating sensor data, and retrieving sensor
 * information. The class inherits from the FestoRobotSensorInterface to integrate
 * with a robotic system.
 */
#pragma once

#include "../../oop_project/Project_Packet/FestoRobotAPI.h"
#include <stdexcept>
#include "FestoRobotSensorInterface.h"
using namespace std;

/**
 * @class IRSensor
 * @brief Provides functionality to interact with an infrared (IR) sensor.
 *
 * The IRSensor class reads and updates distance measurements from the IR sensor.
 * It provides utility functions to access sensor values, print sensor data, and
 * retrieve the sensor type. The class integrates with the robotic system via
 * the FestoRobotSensorInterface.
 */
class IRSensor : public FestoRobotSensorInterface{
private:
    
    double ranges[9];        /*!< Array to store distance values from the sensor.*/

public:
    /**
     * @brief Default constructor for the IRSensor class.
     *
     * Initializes the IRSensor object without associating it with a specific API.
     */
    IRSensor();
    /**
     * @brief Constructor for the IRSensor class with API integration.
     *
     * Initializes the IRSensor object and associates it with a FestoRobotAPI instance.
     * @param api A pointer to the FestoRobotAPI instance used for sensor interaction.
     */
    IRSensor(FestoRobotAPI* api);
    /**
     * @brief Updates the sensor readings.
     *
     * Fetches the latest distance measurements from the sensor and stores them
     * in the internal array.
     */
    void updateSensor();
    /**
     * @brief Retrieves the distance value at the specified index.
     *
     * @param index The index of the distance value to retrieve (0-8).
     * @return The distance value at the given index.
     * @throws std::out_of_range if the index is invalid.
     */
    double getRange(int index) const;
    /**
     * @brief Overloaded subscript operator to access distance values.
     *
     * Provides direct access to distance values using the subscript notation.
     * @param i The index of the distance value to retrieve (0-8).
     * @return The distance value at the specified index.
     * @throws std::out_of_range if the index is invalid.
     */
    double operator[](int i) const;

    /**
     * @brief Retrieves the sensor value at the specified position.
     *
     * @param x The position index for which the sensor value is needed.
     * @return The sensor value at the given position.
     */
    double getSensorValue(int x) override;
    /**
     * @brief Prints the sensor data to the console.
     *
     * Outputs the current sensor readings for debugging or monitoring purposes.
     */
    void printSensor() override;
    /**
     * @brief Retrieves the sensor type as a string.
     *
     * Provides the type of the sensor (e.g., "Infrared").
     * @return The type of the sensor.
     */
    string getSensorType() override;
    /**
     * @brief Initializes the IR sensor.
     *
     * Prepares the sensor for operation, ensuring it is ready to take measurements.
     */
    void initializeIRSensor();
};

