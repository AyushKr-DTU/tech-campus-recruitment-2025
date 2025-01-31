#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void extract_logs(const std::string& filename, const std::string& date) {
    std::ifstream input(filename, std::ios::in);
    if (!input) {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return;
    }

    // create output dir
    std::string output_dir = "output";
    if (!fs::exists(output_dir)) {
        fs::create_directory(output_dir);
    }

    std::string output_file = output_dir + "/output_" + date + ".txt";
    std::ofstream output(output_file, std::ios::out);
    if (!output) {
        std::cerr << "Error: Cannot create output file: " << output_file << std::endl;
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        // line start date check 
        if (line.compare(0, date.length(), date) == 0) {
            output << line << '\n';
        }
    }

    std::cout << "Log entries for " << date << " saved to " << output_file << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <log_file> <YYYY-MM-DD>" << std::endl;
        return 1;
    }

    std::string log = argv[1];
    std::string date = argv[2];

    extract_logs(log, date);
    return 0;
}
