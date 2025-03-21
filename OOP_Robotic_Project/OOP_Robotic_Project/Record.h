#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <string>

/**
 * @file Record.h
 * @author Emirhan Kalkan
 * @date December, 2024
 * @brief Declaration of the Record class for file operations.
 *
 * This class provides functionality to open, close, read, and write lines
 * from a file. It allows for setting the file name and includes overloads
 * for input and output stream operators to handle file operations easily.
 */

 /**
  * @class Record
  * @brief Handles file reading and writing operations.
  *
  * The Record class provides methods to open, close, read, and write lines
  * to a file. It also includes methods to set the file name, read a line,
  * and write a line to the file. Additionally, the class overloads the stream
  * insertion (<<) and extraction (>>) operators for convenient input and output
  * handling of file data.
  */
class Record {
private:
    /**
     * @brief File stream for reading and writing to a file.
     */
    std::fstream file;

    /**
     * @brief The name of the file to open.
     */
    std::string fileName;

public:
    /**
         * @brief Opens the file associated with the fileName.
         *
         * This function opens the file in both read and write mode.
         *
         * @return True if the file was opened successfully, false otherwise.
         */
    bool openFile();

    /**
     * @brief Closes the currently open file.
     *
     * This function closes the file if it is open.
     *
     * @return True if the file was closed successfully, false otherwise.
     */
    bool closeFile();
    /**
     * @brief Sets the name of the file to operate on.
     *
     * This function sets the file name that will be used for subsequent
     * file operations.
     *
     * @param filename The name of the file to set.
     */
    void setFileName(const std::string& filename);

    /**
     * @brief Reads a line from the currently opened file.
     *
     * This function reads one line of text from the file.
     *
     * @return A string containing the line read from the file.
     */
    std::string readLine();
    /**
     * @brief Writes a line to the currently opened file.
     *
     * This function writes a single line of text to the file.
     *
     * @param line The string to write to the file.
     * @return True if the write operation succeeded, false otherwise.
     */
    bool writeLine(const std::string& line);

    /**
     * @brief Overloads the output stream operator to display Record information.
     *
     * This function allows printing the Record object using an output stream.
     *
     * @param os The output stream.
     * @param record The Record object to display.
     * @return The output stream with the Record's information.
     */
    friend std::ostream& operator<<(std::ostream& os, const Record& record);

    /**
     * @brief Overloads the input stream operator to read into a Record object.
     *
     * This function allows reading data from an input stream into a Record object.
     *
     * @param is The input stream.
     * @param record The Record object to fill with data.
     * @return The input stream after reading the data.
     */
    friend std::istream& operator>>(std::istream& is, Record& record);
};

#endif // RECORD_H

