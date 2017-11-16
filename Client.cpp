#include <iostream>
#include <string>
#include "../common/Socket.hpp"

int main(int argc, char *argv[]) {
    NaviRice::Networking::Socket socket;
    socket.onReceiveData([](NaviRice::Networking::Buffer buffer) -> void {
        std::cout << "Client received: " << buffer.data << std::endl;
    });
    socket.connect("127.0.0.1", 8080);

    std::string buffer = "Hello, I'm client!";
    std::cout << socket.send((void *)buffer.c_str(), buffer.size()) << std::endl;
    socket.close();
}