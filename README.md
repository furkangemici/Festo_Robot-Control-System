# 🤖 Omni-Directional Robot Control System

Welcome to the **Omni-Directional Robot Control System** project! This software is designed to control an omni-directional robot using Webots simulation.

---

## 📌 Project Overview

This system enables:
- **Robot movement** in all directions.
- **Sensor data retrieval** (IR & Lidar).
- **Obstacle avoidance** for safe navigation.
- **Mapping** of the explored environment.

Developed using **Object-Oriented Programming (OOP)** principles, the project includes improved class structures, exception handling, and access control features.

The project covers areas such as motion control of the robot, safe navigation, data collection from sensors, mapping operations, and the management of these operations. The robot is programmed through various classes and methods in order to perform the given tasks. However, the software is limited to run only in the simulator environment. Features such as integration with external hardware and real-world deployment are excluded from the scope of this project.

---

## 🛠 Features

- **Robot Control**: Move, rotate, and retrieve real-time position data.
- **Sensor Management**: IR and Lidar sensor integration.
- **Navigation**: Safe movement with obstacle detection.
- **Mapping**: Visualize and save explored areas.
- **Access Control**: Secure authentication for robot operations.

---

## 🧑‍💻 Installation and Setup

Follow these steps to set up the project:

### Prerequisites

1. **Webots Simulator**

   - Download and install Webots from [Cyberbotics](https://cyberbotics.com). Use version R2023b.

2. **Development Environment**
   - A C++ compiler (e.g., GCC or MSVC).
   - Recommended IDE: Visual Studio Community 2022.

### Setup Steps

1. Clone the repository or download the source code.

   ```bash
   git clone <repository-url>
   ```

2. Place the provided `FestoRobotAPI.h` and `FestoRobotAPI.lib` files in the appropriate directories.

3. Open the project in your IDE and configure the build settings:

   - Include directories for headers: `C:\Program Files\Webots\include\controller\cpp`.
   - Link the `FestoRobotAPI.lib` and `Controller.lib` libraries.

4. Build the project to ensure all dependencies are resolved.

5. Follow [EK-1](https://github.com/furkangemici/Festo_Robot-Control-System/blob/main/Documentations/EK_1_Gelistirme_Ortaminin_Olusturulmasi_v1_0.pdf) for detailed setup instructions, including testing the simulator integration.

---

## 🎮 Usage

1. **Run the application** and connect the robot.
2. **Use the menu** to control movement, view sensor data, and map the environment.
3. **Check logs** for real-time feedback.

---

## 🧩 Project Structure

- **`FestoRobotAPI.h`**: Core API for robot communication.
- **`FestoRobotInterface.*`**: Interface for robot control.
- **`IRSensor.*`**: Manages IR sensor data.
- **`LidarSensor.*`**: Handles Lidar sensor data.
- **`Pose.*`**: Represents the robot's position and orientation.
- **`Mapper.*`**: Creates and manages maps.
- **`SafeNavigation.*`**: Ensures collision-free movement.
- **`RobotControler.*`**: Revised for access control and enhanced sensor management.

---

## 🌟 Highlights

✅ OOP Best Practices  
✅ Doxygen Documentation  
✅ Real-time Webots Simulation  
✅ Secure Access Control  

---


## 🤝 Contributors

- **Furkan Gemici and team** ✨

📧 Contact: **furkngemici@gmail.com**
