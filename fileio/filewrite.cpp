//
// Created by Tryggve Sørensen on 14/12/2022.
//
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
void writeCharsetToFile (const std::string& filename);
void outputFile (const std::string& filename);
void outputFileByStreamBuffer (const std::string& filename);

int main(int argc, char **argv) {
  std::cout << "==========================================================================" << std::endl;
  std::cout << "=== FILE WRITE EXAMPLE                                                ====" << std::endl;
  std::cout << "=== Program name: " << argv[0] << std::endl;
  std::cout << "=== Number of arguments: " << argc << std::endl;
  std::cout << "==========================================================================" << std::endl;

  writeCharsetToFile("charset.txt");
  // outputFile("charset.txt");
  outputFileByStreamBuffer("charset.txt");
  exit(0);
}

void writeCharsetToFile (const std::string& filename) {
  // Create the output file stream
  // Note that C++11 supports filename as string
  std::ofstream outfile(filename);
  if (!outfile) {
    std::cerr << "Cannot open output file: " << filename << std::endl;
    exit (EXIT_FAILURE);
  }

  for (int i=32; i<256; i++) {
    // Use the overloaded << operator to write data to the file stream
    // Manipulator function setw sets the field width of the number to 3
    outfile << "value: " << std::setw(3) << i << "   "
            << "char:  " << static_cast<char>(i) << std::endl;
  }
  // Automatic close of file when function ends
}

void outputFile(const std::string& filename) {
  // Open input file
  std::ifstream infile(filename);
  if (!infile) {
    std::cerr << "Cannot open input file: " << filename << std::endl;
    exit (EXIT_FAILURE);
  }

  // Read the file character by character
  char c;
  while (infile.get(c)) {
    std::cout.put(c);
  }
}

void outputFileByStreamBuffer(const std::string& filename) {
  // Open input file
  std::ifstream infile(filename);
  if (!infile) {
    std::cerr << "Cannot open input file: " << filename << std::endl;
    exit (EXIT_FAILURE);
  }

  // Read the entire file using stream buffer
  std::cout << infile.rdbuf();
}