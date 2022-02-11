#ifndef AAAPROJECT_SERIALIZATION_H
#define AAAPROJECT_SERIALIZATION_H

#include <fstream>
#include <iostream>

#include <boost/json/serializer.hpp>
#include <boost/json/object.hpp>
#include <boost/json/string_view.hpp>



#include <QTextEdit>





namespace json_serialization
{
namespace
{

    const boost::json::string_view c_ipAddressNaming = "Broker IP Address";
    const boost::json::string_view c_portNaming = "Port";
    const boost::json::string_view c_subTopNaming = "Sub topic";
    const boost::json::string_view c_pubTopNaming = "Pub topic";
    const boost::json::string_view c_cIDNaming = "cID";
    const boost::json::string_view c_usernameNaming = "Username";
    const boost::json::string_view c_passwordNaming = "Password";
}
    void serialize_operation(boost::json::object& val);

    constexpr char confFileName[] = "configuration.json";

    template<typename T, size_t N>
    void serialization(std::array<T,N>valuesContainer)
    {
        boost::json::object val = {{c_ipAddressNaming, valuesContainer[0]->displayText().toStdString()},
                                  {c_portNaming, valuesContainer[1]->displayText().toStdString()},
                                  {c_subTopNaming, valuesContainer[2]->displayText().toStdString()},
                                  {c_pubTopNaming, valuesContainer[3]->displayText().toStdString()},
                                  {c_cIDNaming, valuesContainer[4]->displayText().toStdString()},
                                  {c_usernameNaming, valuesContainer[5]->displayText().toStdString()},
                                  {c_passwordNaming, valuesContainer[6]->displayText().toStdString()}
                                 };
        serialize_operation(val);
    }


}

#endif // SERIALIZATION_H
