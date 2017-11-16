#include <iostream>
#include <string>
#include "../common/Socket.hpp"
#include "../common/build/header.message.pb.h"

int main(int argc, char *argv[]) {
    NaviRice::Networking::Socket socket;
    socket.onReceiveData([](NaviRice::Networking::Buffer buffer) -> void {
        std::cout << "Client received: " << buffer.data << std::endl;
    });
    socket.connect("127.0.0.1", 8080);

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    protocol::MessageHeader messageHeader;

    messageHeader.set_version(1);
    messageHeader.set_sequenceid(1);
    messageHeader.set_type(protocol::MessageHeader_MessageType_DATA);
    messageHeader.set_sourceservice(protocol::MessageHeader_Service_HEAD_TRACKING);
    messageHeader.set_destinationservice(protocol::MessageHeader_Service_RENDERING);

    std::string output = messageHeader.SerializeAsString();

    void *data = (void *)(output.c_str());
    std::cout << socket.send(data, output.size()) << std::endl;
    socket.close();
}