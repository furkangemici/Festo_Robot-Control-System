/**
 * @file Point.h
 * @Author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Header file for the Point class.
 *
 * This file contains the declaration of the Point class, which represents
 * a point in a 2D coordinate system. It provides methods to manipulate
 * and retrieve point data, calculate distances, and find angles.
 */
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>


 //! A class representing a point in 2D space.
 /*!
  This class stores the x and y coordinates of a point and provides
  various utility functions for calculations and comparisons.
 */
class Point
{
private:
    //! The X-coordinate of the point.
    double x;

    //! The Y-coordinate of the point.
    double y;

public:
    
    //! Default constructor.
    /*!
     * Initializes the point at (0, 0).
     */
    Point();

    //! Parameterized constructor.
    /*!
     * Initializes the point with the given coordinates.
     * @param _x The X-coordinate of the point.
     * @param _y The Y-coordinate of the point.
     */
    Point(double _x, double _y);

    //! Gets the X-coordinate of the point.
    /*!
     * @return The X-coordinate value.
     */
    double getX() const;

    //! Sets the X-coordinate of the point.
    /*!
     * @param _x The new X-coordinate value.
     */
    void setX(double _x);

    //! Gets the Y-coordinate of the point.
    /*!
     * @return The Y-coordinate value.
     */
    double getY() const;

    //! Sets the Y-coordinate of the point.
    /*!
     * @param _y The new Y-coordinate value.
     */
    void setY(double _y);

    //! Equality operator.
    /*!
     * Compares two points for equality.
     * @param other The other point to compare.
     * @return True if the points have the same coordinates, false otherwise.
     */
    bool operator==(const Point& other) const;

    //! Retrieves the coordinates of the point.
    /*!
     * @param _x Reference to store the X-coordinate.
     * @param _y Reference to store the Y-coordinate.
     */
    void getPoint(double& _x, double& _y) const;

    //! Sets the coordinates of the point.
    /*!
     * @param _x The new X-coordinate.
     * @param _y The new Y-coordinate.
     */
    void setPoint(double _x, double _y);

    //! Calculates the distance to another point.
    /*!
     * @param other The other point to calculate the distance to.
     * @return The distance between the points.
     */
    double findDistanceTo(const Point& other) const;

    //! Calculates the angle to another point.
    /*!
     * @param other The other point to calculate the angle to.
     * @return The angle (in radians) between the points.
     */
    double findAngleTo(const Point& other) const;

    
    

    
    
};

#endif // POINT_H
