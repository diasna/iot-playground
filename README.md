# iot-playground
![Schema](https://github.com/diasna/iot-playground/blob/main/IoT%20Playground.jpg?raw=true)

Obtain cert fingerprint
```bash
openssl s_client -connect bbce1a8cdbf94cf7b61c22aa22b7d0af.s1.eu.hivemq.cloud:8883 2>&1|openssl x509 -noout -serial
```