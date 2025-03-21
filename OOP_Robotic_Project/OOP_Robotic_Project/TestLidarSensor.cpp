///**
// * @file   LidarSensorTest.cpp
// * @author Furkan Gemici
// * @date   December, 2024
// * @brief  Source file for testing the LidarSensor class.
// *
// * Implements the test methods defined in LidarSensorTest.h to ensure
// * the correct functionality of the LidarSensor class.
// */
//
//#include "LidarSensor.h"
//#include <iostream>
//#include <cassert>
//#include <vector>
//
//#include "TestLidarSensor.h"
//
//MockFestoRobotAPI::MockFestoRobotAPI(const std::vector<float>& mockData)
//    : mockData(mockData), currentIndex(0) {}
//
//void MockFestoRobotAPI::getLidarRange(float* range) {
//    if (currentIndex < mockData.size()) {
//        *range = mockData[currentIndex++];
//    }
//    else {
//        *range = 0.0f; // Default value
//    }
//}
//
//void MockFestoRobotAPI::reset() {
//    currentIndex = 0;
//}
//
//void LidarSensorTest::runAllTests() {
//    testUpdate();
//    testGetRange();
//    testGetMinAndMax();
//    testOperatorOverload();
//    testGetAngle();
//    testPrint();
//    std::cout << "All tests passed successfully!" << std::endl;
//}
//
//void LidarSensorTest::testUpdate() {
//    std::vector<float> mockData = { 1.5f, 2.0f, 3.0f, 4.5f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    sensor.update();
//
//    for (int i = 0; i < mockData.size(); ++i) {
//        assert(sensor.getRange(i) == mockData[i]);
//    }
//
//    mockAPI.reset();
//    std::cout << "testUpdate passed!" << std::endl;
//}
//
//void LidarSensorTest::testGetRange() {
//    std::vector<float> mockData = { 10.0f, 20.0f, 30.0f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    sensor.update();
//    assert(sensor.getRange(0) == 10.0);
//    assert(sensor.getRange(1) == 20.0);
//    assert(sensor.getRange(2) == 30.0);
//
//    try {
//        sensor.getRange(5); // Invalid index
//        assert(false);
//    }
//    catch (const std::out_of_range&) {
//        std::cout << "testGetRange passed!" << std::endl;
//    }
//}
//
//void LidarSensorTest::testGetMinAndMax() {
//    std::vector<float> mockData = { 5.0f, 1.0f, 3.0f, 10.0f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    sensor.update();
//
//    int minIndex, maxIndex;
//    double minValue = sensor.getMin(minIndex);
//    double maxValue = sensor.getMax(maxIndex);
//
//    assert(minValue == 1.0);
//    assert(minIndex == 1);
//    assert(maxValue == 10.0);
//    assert(maxIndex == 3);
//
//    std::cout << "testGetMinAndMax passed!" << std::endl;
//}
//
//void LidarSensorTest::testOperatorOverload() {
//    std::vector<float> mockData = { 3.0f, 6.0f, 9.0f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    sensor.update();
//
//    assert(sensor[0] == 3.0);
//    assert(sensor[1] == 6.0);
//    assert(sensor[2] == 9.0);
//
//    try {
//        sensor[5]; // Invalid access
//        assert(false);
//    }
//    catch (const std::out_of_range&) {
//        std::cout << "testOperatorOverload passed!" << std::endl;
//    }
//}
//
//void LidarSensorTest::testGetAngle() {
//    std::vector<float> mockData = { 1.0f, 2.0f, 3.0f, 4.0f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    assert(sensor.getAngle(0) == 0.0);
//    assert(sensor.getAngle(1) == 90.0);
//    assert(sensor.getAngle(2) == 180.0);
//    assert(sensor.getAngle(3) == 270.0);
//
//    std::cout << "testGetAngle passed!" << std::endl;
//}
//
//void LidarSensorTest::testPrint() {
//    std::vector<float> mockData = { 1.0f, 2.0f, 3.0f };
//    MockFestoRobotAPI mockAPI(mockData);
//    LidarSensor sensor(&mockAPI, mockData.size());
//
//    sensor.update();
//    sensor.print(); // Manually verify output
//    std::cout << "testPrint passed!" << std::endl;
//}
