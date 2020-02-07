/**
 * Created by Tryggve Sørensen on 09/01/2020.
 * The JSON document to be used.
 *
 * \todo This will be part of a protobuf message.
 */

#include <string>

class JsonMessage {
public:
    std::string m_headers = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
};