# RoboCar
This is a NodeMCU project (esp8266 chip). It uses my custom built robot with four wheels, but no steering wheel so rotation is performed around car center.

## Example Visual Studio Code configuration
arduino.json
```json
{
    "sketch": "main.cpp",
    "board": "esp8266:esp8266:nodemcuv2",
    "configuration": "CpuFrequency=80,UploadSpeed=115200,FlashSize=4M3M",
    "port": "/dev/ttyUSB0",
    "output": "../robo_out"
} 
```