#include "ipc/TcpClient.h"
#include <iostream>

int main(){
    TcpClient client;

    std::string response = client.sendRequest("127.0.0.1", 54000, "hello");

    std::cout << "Response: " << response << std::endl;
}