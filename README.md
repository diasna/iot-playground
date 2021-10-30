# iot-playground
![Schema](https://github.com/diasna/iot-playground/blob/main/IoT%20Playground.jpg?raw=true)

Obtain cert fingerprint
```bash
openssl s_client -connect <YOUR_BROKER_HOST>:8883 2>&1|openssl x509 -noout -serial
```

Build flags such as WiFi SSID & Password can be set on [platformio.ini](platformio.ini)
