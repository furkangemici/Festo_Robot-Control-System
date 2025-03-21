/**
 * @file   LidarSensorTest.h
 * @author Furkan Gemici
 * @date   December, 2024
 * @brief  Header file for testing the LidarSensor class.
 *
 * Declares the LidarSensorTest class with test methods to ensure the
 * functionality of the LidarSensor class.
 */

#ifndef LIDAR_SENSOR_TEST_H
#define LIDAR_SENSOR_TEST_H

#include "LidarSensor.h"
#include <vector>
#include <iostream>

 /**
  * @brief Mock class for FestoRobotAPI.
  *
  * Simulates the behavior of the real FestoRobotAPI for testing purposes.
  */
class MockFestoRobotAPI : public FestoRobotAPI {
public:
    /**
     * @brief Constructor for MockFestoRobotAPI.
     * @param mockData A vector of mock range values.
     */
    MockFestoRobotAPI(const std::vector<float>& mockData);

    /**
     * @brief Simulates getting a Lidar range value.
     * @param range Pointer to store the retrieved range value.
     */
    virtual void getLidarRange(float* range); // "override" çýkarýldý, çünkü temel sýnýfta eksik olabilir.

    /**
     * @brief Resets the mock API's internal state.
     */
    void reset();

private:
    std::vector<float> mockData;
    size_t currentIndex;
};

/**
 * @brief Test class for LidarSensor.
 *
 * Contains unit tests for validating the functionality of the LidarSensor class.
 */
class LidarSensorTest {
public:
    /**
     * @brief Runs all test cases for LidarSensor.
     */
    void runAllTests();

private:
    void testUpdate();
    void testGetRange();
    void testGetMinAndMax();
    void testOperatorOverload();
    void testGetAngle();
    void testPrint();
};

#endif // LIDAR_SENSOR_TEST_H