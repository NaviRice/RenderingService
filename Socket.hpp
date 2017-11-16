//
// Created by Yang Liu on 11/15/17.
//

#ifndef RENDERING_SOCKET_H
#define RENDERING_SOCKET_H

#include <string>

using namespace std;

namespace NaviRice {
    namespace Networking {
        class Socket {
            int descriptor;
        public:
            Socket();

            void listen(string, int);

            void connect(string, int);
        };
    }
}


#endif //RENDERING_SOCKET_H
