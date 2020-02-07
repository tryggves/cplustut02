/**
 * Created by Tryggve Sørensen on 09/01/2020.
 * Parsing JSON with rapidjson.org
 */

#include <iostream>
#include "JsonMessage.h"

int main(int argc, char **argv) {
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== RAPIDJSON EXAMPLE 01                                              ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    JsonMessage headers;
    std::cout << headers.m_headers << std::endl;
}
