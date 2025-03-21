/**
 * @file MAP.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the MAP class for managing a grid-based map.
 *
 * The MAP class provides functionalities to manage a grid-based map. It includes methods
 * to insert points, modify and access grid values, clear the map, print its details, and
 * display the map visually.
 */

#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include "Point.h"
 /**
  * @class MAP
  * @brief Represents a grid-based map system for managing map data.
  *
  * The MAP class allows for the insertion of points into the map, accessing and modifying
  * the grid values, clearing the map, and displaying the map's information. The map is
  * stored in a 2D grid, and each cell can hold integer values representing the map's
  * structure.
  */
class MAP {
private:
    /**
     * @brief 2D vector to store the map grid.
     *
     * A grid of integers that represent the map's structure.
     */
    std::vector<std::vector<int>> grid;

    /**
     * @brief Number of grids in the x direction.
     */
    int numberX;

    /**
     * @brief Number of grids in the y direction.
     */
    int numberY;

    /**
     * @brief Size of each grid cell.
     */
    double gridSize;

public:
    /**
     * @brief Default constructor for the MAP class.
     *
     * Initializes the map with default values.
     */
    MAP();
    
    /**
     * @brief Parameterized constructor for the MAP class.
     *
     * Initializes the map with the specified dimensions and grid size.
     *
     * @param numberX The number of grids in the x direction.
     * @param numberY The number of grids in the y direction.
     * @param gridSize The size of each grid cell.
     */
    MAP(int numberX, int numberY, double gridSize);
    
    /**
     * @brief Inserts a point into the map.
     *
     * Adds a point to the map at the appropriate location, updating the grid accordingly.
     *
     * @param point The point to be inserted into the map.
     */
    void insertPoint(const Point& point);
    /**
     * @brief Gets the value from the specified grid cell.
     *
     * Retrieves the value stored in the specified (x, y) grid location.
     *
     * @param x The x-coordinate of the grid.
     * @param y The y-coordinate of the grid.
     * @return The value stored at the specified grid location.
     */
    int getGrid(int x, int y) const;
    /**
     * @brief Sets the value at a specified grid location.
     *
     * Sets the value at the specified (x, y) grid location to the given value.
     *
     * @param x The x-coordinate of the grid.
     * @param y The y-coordinate of the grid.
     * @param value The value to set at the specified grid location.
     */
    void setGrid(int x, int y, int value);
    /**
     * @brief Clears the map.
     *
     * Resets the entire map, clearing all data stored in the grid.
     */
    void clearMap();
    /**
     * @brief Prints information about the map.
     *
     * Displays details about the map, such as its dimensions and grid size.
     */
    void printInfo();
    /**
     * @brief Shows the map visually.
     *
     * Displays the map as a grid, showing the current values of each grid cell.
     */
    void showMap() const;

    /**
     * @brief Gets the number of grids in the x direction.
     *
     * @return The number of grids in the x direction.
     */
    int getNumberX() const;
    /**
      * @brief Gets the number of grids in the y direction.
      *
      * @return The number of grids in the y direction.
      */
    int getNumberY() const;
    /**
     * @brief Gets the size of each grid cell.
     *
     * @return The size of each grid cell.
     */
    double getGridSize() const;

    /**
     * @brief Sets the size of each grid cell.
     *
     * @param _gridsize The new size for each grid cell.
     */
    void setGridSize(double _gridsize);
    /**
     * @brief Overloads the output stream operator to display the map.
     *
     * This operator allows printing the MAP object using an output stream,
     * providing a formatted view of the map's details.
     *
     * @param os The output stream.
     * @param map The MAP object to display.
     * @return The output stream with the formatted map details.
     */
    friend std::ostream& operator<<(std::ostream& os, const MAP& map);
};

#endif // MAP_H
