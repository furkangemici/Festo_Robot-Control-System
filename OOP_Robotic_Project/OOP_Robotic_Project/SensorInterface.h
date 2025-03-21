/**
 * @file   SensorInterface.h
 * @Author Furkan Gemici (furkngemici@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the SensorInterface class.
 *
 * The SensorInterface class serves as an abstract base class for various sensor types.
 * It provides a common interface for updating sensor data, retrieving sensor type and values,
 * and printing sensor information.
 */
#pragma once
#ifndef SENSORINTERFACE_H
#define SENSORINTERFACE_H

#include <string>
 /**
  * @class SensorInterface
  * @brief Abstract base class defining the interface for sensors.
  *
  * The SensorInterface class provides a standard interface for different types of sensors,
  * including methods to update sensor data, retrieve sensor type and values, and print sensor details.
  */
class SensorInterface
{
protected:
	std::string sensorType;/*!< Type of the sensor, stored as a string. */
public:
    /**
     * @brief Constructor for the SensorInterface class.
     *
     * Initializes the sensor interface with a specified sensor type.
     * @param _sensorType A string representing the type of the sensor.
     */
    SensorInterface(std::string _sensorType) : sensorType(_sensorType) {}

    /**
     * @brief Pure virtual method to update sensor data.
     *
     * Derived classes must implement this method to update the sensor's data.
     */
    virtual void updateSensor() = 0;

    /**
     * @brief Pure virtual method to retrieve the sensor type.
     *
     * Derived classes must implement this method to return the type of the sensor.
     * @return A string representing the sensor type.
     */
    virtual std::string getSensorType() = 0;

    /**
     * @brief Pure virtual method to retrieve a sensor value.
     *
     * Derived classes must implement this method to return the sensor value at a given index.
     * @param x An integer index specifying the sensor value to retrieve.
     * @return A double representing the sensor value at the specified index.
     */
    virtual double getSensorValue(int x) = 0;

    /**
     * @brief Pure virtual method to print sensor details.
     *
     * Derived classes must implement this method to output sensor information to the console.
     */
    virtual void printSensor() = 0;
};
#endif