#ifndef SERVERCORE_H
#define SERVERCORE_H


#include <iostream>

namespace core
{
    class Server final
    {

        struct Configuration final
        {

        };

    public:
        static Server& Instance()
        {
            static Server srv;
            return srv;
        }

        void set_config();
        void start()
        {
            std::cout << "Server is started!" << std::endl;
        }

        void stop()
        {
            std::cout << "Server is stopped!" << std::endl;
        }

    private:
        Server(){}
        ~Server(){}
        Server(const Server&);
        Server& operator=(const Server&);

    };
}

#endif
