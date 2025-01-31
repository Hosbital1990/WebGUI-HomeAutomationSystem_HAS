#include <iostream>
#include <fstream>
#include <vector>
#include "memory_interface.h"

namespace MemoryInterface
{
/**
 * @brief Writes data to a file.
 * 
 * @param data Vector containing data to be written.
 * @param filename Name of the file.
 * @return true If the data is successfully written.
 * @return false If the data writing fails.
 */
bool write_data(std::vector<double> data, const std::string& filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::app);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }

    // Move the put pointer to the end of the file to determine its size
    file.seekp(0, std::ios::end);
    std::streampos fileSize = file.tellp();
    if (fileSize == 0)
    {
        // Write header
        file << "Sensor name, data \n";
        // Write sensor name and data
        file << "Temprature" << ",";
        for (size_t i = 0; i < data.size(); ++i)
        {
            file << data[i];
            if (i < data.size() - 1)
            {
                file << ",";  // Separate values with commas
            }
        }
        file << "\n";
        if (file.fail())
        {
            throw std::runtime_error("Failed to write to file: " + filename);
        }
    }
    else
    {
        file << "Temprature" << ",";
        for (size_t i = 0; i < data.size(); ++i)
        {
            file << data[i];
            if (i < data.size() - 1)
            {
                file << ",";  // Separate values with commas
            }
        }
        file << "\n";
        if (file.fail())
        {
            throw std::runtime_error("Failed to write to file: " + filename);
        }
    }

    return true;
}

/**
 * @brief Reads data from a file.
 * 
 * @return int Data read from the file.
 */
int read_data()
{
    return 0;
}

}  // namespace MemoryInterface



