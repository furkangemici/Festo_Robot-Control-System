#pragma once
/**
 * @file   Pose.h
 * @Author Cem Levent Avcý (cemlevent54@gmail.com)
 * @date   December, 2024
 * @brief  Header file for the Pose class.
 *
 * This file contains the declaration of the Pose class, which represents
 * the position (x, y) and orientation (theta) of a robot in a 2D space.
 */
#pragma once

#include <iostream>
#include <string>

 //! Pose class
 /*!
  * @brief Represents the position and orientation of a robot in a 2D space.
  *
  * The Pose class stores the x and y coordinates (in meters) and the orientation
  * (theta, in degrees) of a robot in a 2D space. It provides functionalities for
  * setting and retrieving these values, as well as performing operations such as
  * distance and angle calculations.
  */
class Pose {
private:
    double x;  /*!< x-coordinate of the robot in the 2D space (meters). */
    double y;  /*!< y-coordinate of the robot in the 2D space (meters). */
    double th; /*!< Orientation of the robot in the 2D space (degrees). */

public:
    //! Default constructor.
   /*!
    * Initializes the Pose object with default values (x = 0, y = 0, th = 0).
    */
    Pose();

    //! Parameterized constructor.
    /*!
     * Initializes the Pose object with the given x, y, and theta values.
     * @param x X-coordinate (meters).
     * @param y Y-coordinate (meters).
     * @param th Orientation (degrees).
     */
    Pose(double x, double y, double th);

    
    //! Gets the X-coordinate.
    /*!
     * @return The X-coordinate (meters).
     */
    double getX();

    //! Sets the X-coordinate.
    /*!
     * @param x The new X-coordinate (meters).
     */
    void setX(double x);

    //! Gets the Y-coordinate.
    /*!
     * @return The Y-coordinate (meters).
     */
    double getY();

    //! Sets the Y-coordinate.
    /*!
     * @param y The new Y-coordinate (meters).
     */
    void setY(double y);

    //! Gets the orientation (theta).
    /*!
     * @return The orientation (degrees).
     */
    double getTh();

    //! Sets the orientation (theta).
    /*!
     * @param th The new orientation (degrees).
     */
    void setTh(double th);

    //! Equality operator.
    /*!
     * Compares two Pose objects for equality.
     * @param other The other Pose object to compare with.
     * @return True if both Pose objects are equal, false otherwise.
     */
    bool operator==(const Pose& other);

    //! Addition operator.
    /*!
     * Adds two Pose objects (component-wise addition).
     * @param other The other Pose object to add.
     * @return A new Pose object that is the sum of the two poses.
     */
    Pose operator+(const Pose& other);

    //! Subtraction operator.
    /*!
     * Subtracts one Pose object from another (component-wise subtraction).
     * @param other The other Pose object to subtract.
     * @return A new Pose object that is the difference of the two poses.
     */
    Pose operator-(const Pose& other);

    //! In-place addition with a scalar.
    /*!
     * Adds a scalar to all components of the Pose.
     * @param value The scalar value to add.
     * @return A reference to the modified Pose object.
     */
    Pose& operator+=(const double& value);

    //! In-place subtraction with a scalar.
    /*!
     * Subtracts a scalar from all components of the Pose.
     * @param value The scalar value to subtract.
     * @return A reference to the modified Pose object.
     */
    Pose& operator-=(const double& value);
    
    //! Less-than operator.
    /*!
     * Compares two Pose objects based on their x-coordinates (and y-coordinates if x is equal).
     * @param other The other Pose object to compare with.
     * @return True if the current Pose is less than the other Pose, false otherwise.
     */
    bool operator<(const Pose& other);

    //! Gets the full pose values.
    /*!
     * Retrieves the x, y, and theta values of the Pose object.
     * @param _x Reference to store the X-coordinate.
     * @param _y Reference to store the Y-coordinate.
     * @param _th Reference to store the orientation (theta).
     */
    void getPose(double& _x, double& _y, double& _th);

    //! Sets the full pose values.
    /*!
     * Updates the x, y, and theta values of the Pose object.
     * @param _x The new X-coordinate.
     * @param _y The new Y-coordinate.
     * @param _th The new orientation (theta).
     */
    void setPose(double _x, double _y, double _th);

    //! Calculates the distance to another pose.
    /*!
     * @param pos The other Pose object.
     * @return The Euclidean distance between the two poses (meters).
     */
    double findDistanceTo(const Pose& pos);

    //! Calculates the angle to another pose.
    /*!
     * @param pos The other Pose object.
     * @return The angle (in degrees) from the current Pose to the other Pose.
     */
    double findAngleTo(const Pose& pos);
};