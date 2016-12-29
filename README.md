## Anto client library for ESP32-Arduino
### This branch is a development on adopting Paho MQTT to ESP32
### According to uncompleteness of the WiFi core library, you need to modify some library files
###### Prerequisite
- In file WiFiClient.cpp (in esp32 directory), go to line 195 and then comment the whole `if` block. It will look like this
```c++
int WiFiClient::available()
{
    if(!_connected) {
        return 0;
    }
    int count;
    int res = ioctl(sockfd, FIONREAD, &count);
    // if(res < 0) {
    //     log_e("%d", errno);
    //     stop();
    //     return 0;
    // }
    return count;
}
```
