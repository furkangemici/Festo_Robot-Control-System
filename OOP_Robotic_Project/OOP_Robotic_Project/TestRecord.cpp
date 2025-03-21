//#include "TestRecord.h"
//#include <iostream>
//#include <fstream>
//#include <cstdio> // For std::remove
//
///**
// * @brief Runs all tests for the Record class.
// */
//void TestRecord::runAllTests() {
//    testConstructor();
//    testOpenFile();
//    testCloseFile();
//    testSetFileName();
//    testReadLine();
//    testWriteLine();
//    testStreamOperators();
//    std::cout << "All tests completed." << std::endl;
//}
//
///**
// * @brief Tests the constructor of the Record class.
// */
//void TestRecord::testConstructor() {
//    Record record;
//    if (record.readLine().empty()) {
//        std::cout << "testConstructor: Default constructor passed." << std::endl;
//    }
//    else {
//        std::cout << "testConstructor: Default constructor failed." << std::endl;
//    }
//
//    Record recordWithFilename("testfile.txt");
//    if (recordWithFilename.openFile()) {
//        std::cout << "testConstructor: Parameterized constructor passed." << std::endl;
//        recordWithFilename.closeFile();
//    }
//    else {
//        std::cout << "testConstructor: Parameterized constructor failed." << std::endl;
//    }
//}
//
///**
// * @brief Tests the openFile method.
// */
//void TestRecord::testOpenFile() {
//    Record record("testfile.txt");
//    if (record.openFile()) {
//        std::cout << "testOpenFile: Passed." << std::endl;
//        record.closeFile();
//    }
//    else {
//        std::cout << "testOpenFile: Failed." << std::endl;
//    }
//}
//
///**
// * @brief Tests the closeFile method.
// */
//void TestRecord::testCloseFile() {
//    Record record("testfile.txt");
//    record.openFile();
//    if (record.closeFile()) {
//        std::cout << "testCloseFile: Passed." << std::endl;
//    }
//    else {
//        std::cout << "testCloseFile: Failed." << std::endl;
//    }
//}
//
///**
// * @brief Tests the setFileName method.
// */
//void TestRecord::testSetFileName() {
//    Record record;
//    record.setFileName("newfile.txt");
//    std::ofstream outFile("newfile.txt", std::ios::trunc); // Ensure the file exists and is empty.
//    outFile.close();
//    if (record.openFile()) {
//        std::cout << "testSetFileName: Passed." << std::endl;
//        record.closeFile();
//    }
//    else {
//        std::cout << "testSetFileName: Failed." << std::endl;
//    }
//}
//
///**
// * @brief Tests the readLine method.
// */
//void TestRecord::testReadLine() {
//    std::ofstream outFile("testfile.txt", std::ios::trunc);
//    outFile << "First line\nSecond line";
//    outFile.close();
//
//    Record record("testfile.txt");
//    record.openFile();
//    if (record.readLine() == "First line") {
//        std::cout << "testReadLine: First line passed." << std::endl;
//    }
//    else {
//        std::cout << "testReadLine: First line failed." << std::endl;
//    }
//    if (record.readLine() == "Second line") {
//        std::cout << "testReadLine: Second line passed." << std::endl;
//    }
//    else {
//        std::cout << "testReadLine: Second line failed." << std::endl;
//    }
//    record.closeFile();
//}
//
///**
// * @brief Tests the writeLine method.
// */
//void TestRecord::testWriteLine() {
//    Record record("testfile.txt");
//    record.openFile();
//    if (record.writeLine("New line")) {
//        std::cout << "testWriteLine: Passed." << std::endl;
//    }
//    else {
//        std::cout << "testWriteLine: Failed." << std::endl;
//    }
//    record.closeFile(); // Ensure file is closed before verification.
//
//    std::ifstream inFile("testfile.txt");
//    std::string line;
//    bool contentVerified = false;
//    while (std::getline(inFile, line)) {
//        if (line == "New line") {
//            contentVerified = true;
//            break;
//        }
//    }
//    if (contentVerified) {
//        std::cout << "testWriteLine: Content verification passed." << std::endl;
//    }
//    else {
//        std::cout << "testWriteLine: Content verification failed." << std::endl;
//        std::cout << "Actual content: " << line << std::endl;
//    }
//    inFile.close();
//}
//
///**
// * @brief Tests the stream insertion (<<) and extraction (>>) operators for file streams.
// */
//void TestRecord::testStreamOperators() {
//    Record record("testfile.txt");
//    record.openFile();
//    record << "Stream operator test";
//    record.closeFile(); // Ensure write is completed before reading.
//
//    record.openFile();
//    std::string line;
//    record >> line;
//    record.closeFile();//    if (line == "Stream operator test") {
//        std::cout << "testStreamOperators: Passed." << std::endl;
//    }
//    else {
//        std::cout << "testStreamOperators: Failed." << std::endl;
//        std::cout << "Actual content: " << line << std::endl;
//    }
//}
