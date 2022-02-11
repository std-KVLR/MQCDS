#include "Serialization.h"

#include <fstream>

#include <boost/json/src.hpp>


void json_serialization::serialize_operation(boost::json::object& val)
{
    std::cout << "LOG: new configuration file values " << boost::json::serialize(val) << '\n';
    try
    {
        std::ofstream confFileStream(confFileName, std::ios::trunc);

        boost::json::serializer ser;
        ser.reset(&val);
        while(!ser.done()){
            char c;
            ser.read(&c, 1);
            confFileStream << c;
            if(c == ',') confFileStream << '\n';

        }
    }
    catch(std::runtime_error &e)
    {
        std::cout << "LOG: Error " << e.what() << "!\n";
    }

    std::cout << "LOG: Success!" << std::endl;
}






