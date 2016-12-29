#ifndef ANTO_WIFI_H
#define ANTO_WIFI_H

#include <WiFi.h>

class AntoWiFi
{
    public:
        AntoWiFi(void) { }

        // timeout is under development
        bool begin(
                const char* ssid,
                const char *passphrase,
                uint16_t timeout = 0)
        {
            bool result = false;
            uint8_t count;

            WiFi.begin((char*)ssid, passphrase);

            for (count = 50; count && (WiFi.status() != WL_CONNECTED); --count)
                delay(100);

            if (count)
                result = true;

            return result;
        }
};

#endif
