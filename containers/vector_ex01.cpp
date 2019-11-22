//
// Created by Tryggve Sørensen on 17/11/2019.
//

#include <iostream>
#include <vector>
#include <map>

int main (int argc, char **argv){
    std::cout << "==========================================================================" << std::endl;
    std::cout << "=== VECTOR EXAMPLES                                                   ====" << std::endl;
    std::cout << "=== Program name: " << argv[0] << std::endl;
    std::cout << "=== Number of arguments: " << argc << std::endl;
    std::cout << "==========================================================================" << std::endl;

    std::map<std::string, std::string> pMap1 {
            {"vdbExchange", "MessagingExchange"},
            {"vdbTopic", "Vessebus.topic1"},
            {"adapterType", "FORWARD"}
    };


    std::map<std::string, std::string> pMap2 {{
            {"vdbExchange", "MessagingExchange"},
            {"vdbTopic", "Vessebus.topic2"},
            {"adapterType", "INTERNAL"}}
    };

    std::vector<std::map<std::string, std::string>> listeners;
    listeners.push_back(pMap1);
    listeners.push_back(pMap2);

}
