/**
 * @file Mapper.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the Mapper class for mapping the environment.
 *
 * The Mapper class manages a grid-based map using data from a LidarSensor and a
 * RobotControler. It provides methods to update the map based on sensor data,
 * save the map to a file, and display the map visually.
 */
#ifndef MAPPER_H
#define MAPPER_H

#include "MAP.h"
#include "RobotControler.h"
#include "LidarSensor.h"
#include "Record.h"
#include <iostream>

 /**
  * @class Mapper
  * @brief Maps the environment using lidar sensor data and robot control data.
  *
  * The Mapper class is responsible for managing and updating a grid-based map using
  * the LidarSensor to detect obstacles and the RobotControler to track the robot's
  * position and movements. It offers functionality to update the map, record it to a file,
  * and visually display the current state of the map.
  */
class Mapper {
private:
    /**
     * @brief MAP object to represent the environment map.
     */
    MAP map;

    /**
     * @brief Pointer to the RobotControler class for managing robot position and movement.
     */
    RobotControler* robotControler;

    /**
     * @brief Pointer to the LidarSensor class for obtaining lidar sensor data.
     */
    LidarSensor* lidarSensor;

public:
    /**
     * @brief Constructor for the Mapper class.
     *
     * Initializes the Mapper with pointers to RobotControler and LidarSensor,
     * and sets the map's grid size and dimensions.
     *
     * @param robotControler Pointer to the RobotControler class.
     * @param lidarSensor Pointer to the LidarSensor class.
     * @param sizeX The number of grids in the x direction.
     * @param sizeY The number of grids in the y direction.
     * @param gridSize The size of each grid cell.
     */
    Mapper(RobotControler* robotControler, LidarSensor* lidarSensor, int sizeX,int sizeY,double gridSize);

    /**
     * @brief Updates the map based on lidar sensor data.
     *
     * This method uses data from the LidarSensor to update the map, inserting
     * new points and adjusting the grid accordingly.
     */
    void updateMap();

    /**
     * @brief Records the map to a file.
     *
     * Saves the current state of the map to a file using the Record class.
     *
     * @return True if the map was recorded successfully, false otherwise.
     */
    bool recordMap();

    /**
     * @brief Displays the map visually.
     *
     * Prints a visual representation of the map to the console.
     */
    void showMap();
};

#endif // MAPPER_H
