# Ultrasonic Radar System

A real-time object detection radar system built with Arduino and an ultrasonic sensor. The system sweeps 180 degrees, detects objects, and displays them on a radar-style visualization interface.


## 🎯 Features

- 180-degree scanning range
- Real-time object detection up to 100cm
- Visual radar display with distance measurements
- Smooth servo motor control
- Serial communication between Arduino and Processing

## 🛠️ Hardware Requirements

| Component | Quantity | Notes |
|-----------|----------|-------|
| Arduino Uno/Nano | 1 | Any Arduino board works |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement |
| SG90 Servo Motor | 1 | 180-degree rotation |
| Jumper Wires | Several | For connections |
| Breadboard | 1 | Optional |
| USB Cable | 1 | For Arduino connection |

## 📋 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8.0 or higher)
- [Processing IDE](https://processing.org/download) (v3.0 or higher)
- Servo library (included with Arduino IDE)

## 🔌 Circuit Diagram

### HC-SR04 Ultrasonic Sensor Connections:
- **VCC** → Arduino 5V
- **GND** → Arduino GND
- **TRIG** → Arduino Pin 9
- **ECHO** → Arduino Pin 8

### SG90 Servo Motor Connections:
- **Red Wire (VCC)** → Arduino 5V
- **Brown/Black Wire (GND)** → Arduino GND
- **Orange/Yellow Wire (Signal)** → Arduino Pin 3

### Assembly:
Mount the HC-SR04 sensor on top of the servo motor so it rotates with the motor shaft.

## 🚀 Installation & Usage

### Step 1: Upload Arduino Code
1. Open Arduino IDE
2. Open `arduino_code/radar_scanner.ino`
3. Select your board: **Tools → Board → Arduino Uno**
4. Select your port: **Tools → Port → [Your Arduino Port]**
5. Click **Upload** button

### Step 2: Run Processing Visualization
1. Open Processing IDE
2. Open `processing_code/radar_visualization.pde`
3. Check the console output to find your Arduino port
4. Modify this line if needed:
   ```java
   myPort = new Serial(this, Serial.list()[0], 9600);
   ```
   Change `[0]` to the correct port index
5. Click **Run** button (play icon)

### Step 3: Watch the Radar
You should see a green radar screen with a sweeping line detecting objects in real-time!

## 📊 How It Works

1. **Servo Motor** rotates the ultrasonic sensor from 0° to 180° and back
2. **HC-SR04 Sensor** measures distance at each angle using sound waves
3. **Arduino** sends angle and distance data via Serial port
4. **Processing** receives the data and visualizes it on a radar display
5. **Red dots** appear on the screen showing detected objects

## 🎨 Visualization Display

The Processing visualization shows:
- **Green arcs**: Distance markers (10cm, 20cm, 30cm, 40cm)
- **Green sweeping line**: Current scanning angle
- **Red dots**: Detected objects
- **Text display**: Current angle and distance readings

## 🔧 Troubleshooting

**Problem: Radar screen doesn't appear**
- Check if Arduino is connected and Serial Monitor is closed
- Verify the correct COM port in Processing code

**Problem: Servo jitters or doesn't move smoothly**
- Use external 5V power supply for servo (Arduino may not provide enough current)
- Increase delay in Arduino code

**Problem: Inaccurate distance readings**
- Ensure HC-SR04 is mounted firmly
- Check wiring connections
- Test with Serial Monitor first

**Problem: Processing shows "Port busy" error**
- Close Arduino IDE Serial Monitor
- Disconnect other serial applications

## 📝 Customization

### Change Detection Range:
In `arduino_code/radar_scanner.ino`, modify the delay:
```cpp
delay(15); // Lower = faster scan, Higher = more accurate
```

### Adjust Display Scale:
In `processing_code/radar_visualization.pde`, modify:
```java
float pixelDistance = distance * 2; // Change multiplier
```

### Change Color Scheme:
Modify stroke colors in Processing code:
```java
stroke(98, 245, 31); // RGB values for green
```

## 🎓 Learning Outcomes

This project teaches:
- Arduino programming and hardware interfacing
- Ultrasonic sensor operation
- Servo motor control
- Serial communication protocols
- Data visualization with Processing
- Real-time embedded systems

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests
- Improve documentation

## 📜 License

This project is open source and available under the [MIT License](LICENSE).

## 👨‍💻 Author

**Md. Biplob Hasan Bijoy**
- GitHub: [@bijoyverse](https://github.com/bijoyverse)

## 🙏 Acknowledgments

- Inspired by traditional radar systems
- Built with Arduino and Processing communities' support
- Thanks to HC-SR04 and servo motor manufacturers



## 🔗 Useful Links

- [Arduino Documentation](https://www.arduino.cc/reference/en/)
- [Processing Documentation](https://processing.org/reference/)
- [HC-SR04 Datasheet](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)

---

**Star ⭐ this repository if you find it helpful!**
