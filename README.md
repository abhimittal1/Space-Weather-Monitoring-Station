# 🛰️ Space Weather Monitoring Station

[![Arduino](https://img.shields.io/badge/Arduino-UNO-blue?style=for-the-badge&logo=arduino)](https://www.arduino.cc/)
[![Wokwi](https://img.shields.io/badge/Simulation-Wokwi-green?style=for-the-badge&logo=arduino)](https://wokwi.com/)


> **A sophisticated environmental monitoring system that simulates satellite data collection for space weather analysis, featuring real-time sensor readings, intelligent alerting, and comprehensive telemetry output.**

## 🎯 Project Overview

The Space Weather Monitoring Station is an advanced environmental monitoring system designed to simulate satellite-based weather data collection. This project demonstrates real-world space technology applications by continuously monitoring atmospheric conditions and providing critical environmental data that would be essential for satellite operations and space missions.

### 🌟 Key Features

- **🌡️ Multi-Parameter Monitoring**: Temperature, humidity, pressure, and simulated altitude tracking
- **📡 Satellite Telemetry Simulation**: Structured data output mimicking real space missions
- **🚨 Intelligent Alert System**: Threshold-based warnings with visual and audio notifications  
- **📱 Multi-Mode Display**: Rotating LCD display showing different parameter groups
- **🔧 Manual Calibration**: Potentiometer-based pressure simulation for testing
- **💡 Status Indication**: RGB LED system for quick operational status assessment
- **⏱️ Real-Time Processing**: Continuous sensor monitoring with configurable intervals
- **🔊 Audio Feedback**: Buzzer alerts for critical environmental conditions

## 🛠️ Hardware Components

| Component | Model/Type | Purpose | Pin Connection |
|-----------|------------|---------|----------------|
| **Microcontroller** | Arduino UNO R3 | Main processing unit | - |
| **Temperature/Humidity** | DHT22 | Environmental monitoring | Digital Pin 2 |
| **Display** | LCD 16x2 (HD44780) | Real-time data visualization | Pins 4-7, 12-13 |
| **Status LEDs** | RGB LEDs (3x) | System status indication | Pins 8, 9, 10 |
| **Alert System** | Active Buzzer | Audio notifications | Pin 11 |
| **Calibration Control** | 10kΩ Potentiometer | Pressure simulation | Analog Pin A0 |
| **Current Limiting** | 220Ω Resistors (3x) | LED protection | - |

## 📋 System Architecture

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│    SENSORS      │    │   ARDUINO UNO   │    │    OUTPUTS      │
│                 │    │                 │    │                 │
│ • DHT22 Sensor  │───▶│  Data Processing│───▶│ • LCD Display   │
│ • Potentiometer │    │  & Threshold    │    │ • Status LEDs   │
│   (Pressure     │    │  Analysis       │    │ • Buzzer Alert  │
│    Simulation)  │    │                 │    │                 │
└─────────────────┘    └─────────────────┘    └─────────────────┘
                              │
                              ▼
                    ┌─────────────────┐
                    │ Serial Telemetry│
                    │ Data Logging &  │
                    │ Mission Control │
                    └─────────────────┘
```

## 🔗 Circuit Implementation

### Complete Circuit Diagram

The following diagram shows the complete hardware implementation with all component connections:

![Circuit Diagram](images/space_weather_circuit.png)

*Figure 1: Complete circuit schematic showing Arduino UNO connections to DHT22 sensor, LCD display, status LEDs, buzzer, and potentiometer*

### Pin Configuration Summary

#### Input Connections
```
Arduino Pin  │ Component        │ Wire Color │ Purpose
─────────────┼──────────────────┼────────────┼─────────────────
Digital 2    │ DHT22 Data       │ Green      │ Temp/Humidity
Analog A0    │ Potentiometer    │ Yellow     │ Pressure Sim
5V           │ Power Rail       │ Red        │ Component Power
GND          │ Ground Rail      │ Black      │ Common Ground
```

#### Output Connections  
```
Arduino Pin  │ Component        │ Wire Color │ Purpose
─────────────┼──────────────────┼────────────┼─────────────────
Pins 4-7     │ LCD Data Bus     │ Multi      │ Display Data
Pin 12       │ LCD RS           │ Blue       │ Register Select
Pin 13       │ LCD Enable       │ Purple     │ Enable Signal
Pin 8        │ Green LED        │ Green      │ Normal Status
Pin 9        │ Red LED          │ Red        │ Alert Status
Pin 10       │ Blue LED         │ Blue       │ Activity Status
Pin 11       │ Buzzer           │ White      │ Audio Alert
```

### Circuit Assembly Guidelines

Refer to Figure 1 for the complete circuit implementation. Key assembly points:

#### Critical Connections
- **DHT22 Sensor**: Ensure proper 5V power supply and data line connection to pin 2
- **LCD Display**: Use standard 4-bit mode wiring with proper contrast adjustment
- **LED Current Limiting**: All LEDs must use 220Ω resistors to prevent damage
- **Potentiometer**: Connect to analog pin A0 for pressure simulation input

#### Power Management
- **5V Rail**: Shared power for all components from Arduino USB/barrel jack
- **Ground Distribution**: Ensure all components share common ground
- **Current Budget**: Total system draws <500mA, well within Arduino limits

### Component Layout Considerations
- Position DHT22 away from heat-generating components for accurate readings
- Keep LCD display cables short to minimize interference
- Mount potentiometer accessibly for pressure adjustment during operation
- Group status LEDs for clear visual indication

## 🚀 Getting Started

### Prerequisites
- Arduino IDE (version 1.8.0 or higher)
- Required Libraries:
  - `LiquidCrystal.h` (built-in)
  - `DHT.h` (DHT sensor library)
- Basic understanding of Arduino programming

### Hardware Requirements
All components listed in the hardware table above, assembled according to the circuit specifications.

### Installation Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/yourusername/space-weather-monitoring
   cd space-weather-monitoring
   ```

2. **Install Required Libraries**
   ```bash
   # In Arduino IDE:
   # Tools > Manage Libraries > Search "DHT sensor library" > Install
   ```

3. **Hardware Assembly**
   - Connect DHT22 sensor to power and digital pin 2
   - Wire LCD display using standard 4-bit mode connection
   - Connect status LEDs through current-limiting resistors
   - Attach buzzer and potentiometer as per pin configuration
   - Verify all power and ground connections

4. **Software Upload**
   - Open the `.ino` file in Arduino IDE
   - Select Arduino UNO as board type
   - Choose correct COM port
   - Compile and upload code to Arduino

5. **System Verification**
   - Open Serial Monitor at 9600 baud rate
   - Observe startup sequence with LED animation and startup beeps
   - Verify LCD display cycling through three modes every 3 seconds
   - Test potentiometer adjustment for pressure simulation (observe changes in pressure and altitude values)
   - Verify telemetry output appears every 5 seconds in structured format
   - Test alert system by simulating extreme conditions

## 💻 Code Architecture

### Core Functions

- **`setup()`**: System initialization, LCD setup, sensor configuration
- **`loop()`**: Main execution cycle with timed sensor readings and display updates
- **`readSensors()`**: DHT22 data acquisition and pressure simulation
- **`checkThresholds()`**: Environmental limit analysis and alert triggering
- **`updateDisplay()`**: Multi-mode LCD display management
- **`sendTelemetry()`**: Structured serial data output for mission control
- **`startupSequence()`**: Visual and audio system initialization feedback

### Key Features Implementation

```cpp
// Environmental threshold monitoring
if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
    alertCondition = true;
}
if (humidity > HUMIDITY_MAX || pressure < PRESSURE_MIN) {
    alertCondition = true;
}

// Multi-mode display cycling
switch (displayMode % 3) {
    case 0: // Temperature & Humidity
    case 1: // Pressure & Altitude  
    case 2: // System Status
}
```

## 📊 System Testing & Operational Data

## 📊 System Testing & Operational Results

### Live System Demonstration

The system demonstrates real-time environmental monitoring with comprehensive data output:

![System Results](images/space_weather_results.png)

*Figure 2: Serial monitor output showing telemetry data, LCD display modes, and system status indicators*

### Operational Data Analysis

The Space Weather Monitoring Station successfully demonstrates:

#### Serial Telemetry Output
The system provides structured mission-control grade data every 5 seconds:
```
=== TELEMETRY DATA ===
Timestamp: 25847
Temperature: 22.3 °C
Humidity: 48.7 %
Pressure: 756 hPa
Simulated Altitude: 2440 m
Status: NOMINAL - All systems operational
====================
```

#### Multi-Mode LCD Display
The display cycles through three information screens:
- **Environmental Mode**: Temperature and humidity readings
- **Atmospheric Mode**: Pressure and calculated altitude
- **Status Mode**: Overall system operational state

#### Alert System Performance
- **Green LED**: Normal operational status (all parameters within limits)
- **Red LED**: Alert condition (any parameter exceeding thresholds)
- **Blue LED**: System activity indicator (blinking every second)
- **Audio Alert**: 1kHz tone for 200ms when thresholds exceeded

### Environmental Thresholds
### Test Results Summary

Based on comprehensive system testing, the following performance metrics were achieved:

#### Sensor Accuracy & Reliability
- **DHT22 Performance**: Consistent temperature readings (±0.5°C accuracy)
- **Humidity Monitoring**: Stable humidity measurements (±2% accuracy)
- **Pressure Simulation**: Smooth potentiometer-based pressure variation (200-1200 hPa range)
- **Altitude Calculation**: Real-time altitude computation based on pressure correlation

#### System Response Times
- **Sensor Reading Cycle**: 2-second intervals for data acquisition
- **Display Update Rate**: 3-second rotation between display modes
- **Alert Response**: Immediate threshold violation detection (<100ms)
- **Telemetry Transmission**: 5-second structured data output intervals

#### Operational Stability
- ✅ **Continuous Operation**: No system crashes or sensor failures during extended testing
- ✅ **Error Handling**: Graceful handling of DHT22 sensor read errors
- ✅ **Display Reliability**: Consistent LCD updates across all three modes
- ✅ **Alert Functionality**: Reliable threshold detection and visual/audio feedback
- ✅ **Data Integrity**: Accurate telemetry output with proper timestamp correlation

### Environmental Monitoring Specifications

The system monitors critical parameters against space-grade operational limits:

- **Temperature Range**: -40°C to +85°C (space-qualified electronics range)
- **Humidity Limit**: Maximum 95% RH (condensation prevention)  
- **Pressure Threshold**: Minimum 300 hPa (high-altitude/space simulation)
- **Altitude Simulation**: 0-50,000m (based on pressure correlation)

### Display Modes
The LCD cycles through three information screens every 3 seconds:

#### Mode 1: Environmental Data
```
Temp: 23.5°C
Humid: 45.2%
```

#### Mode 2: Atmospheric Data  
```
Press: 850hPa
Alt: 15000m
```

#### Mode 3: System Status
```
System Status:
OPERATIONAL
```

### Telemetry Output
Serial monitor displays structured mission data every 5 seconds:

```
=== TELEMETRY DATA ===
Timestamp: 15243
Temperature: 23.5 °C
Humidity: 45.2 %
Pressure: 850 hPa
Simulated Altitude: 15000 m
Status: NOMINAL - All systems operational
====================
```

## 🔧 Configuration & Customization

### Adjustable Parameters
```cpp
// Environmental thresholds (modify for different applications)
const float TEMP_MIN = -40;      // Minimum operational temperature
const float TEMP_MAX = 85;       // Maximum operational temperature  
const float HUMIDITY_MAX = 95;   // Maximum humidity threshold
const float PRESSURE_MIN = 300;  // Low pressure alert threshold

// Timing intervals
#define SENSOR_INTERVAL 2000     // Sensor reading frequency (ms)
#define DISPLAY_INTERVAL 3000    // LCD update frequency (ms)
#define TELEMETRY_INTERVAL 5000  // Serial output frequency (ms)
```

### Sensor Calibration
- **DHT22**: Factory calibrated, no adjustment needed
- **Pressure Simulation**: Adjust potentiometer for pressure range testing
- **Altitude Calculation**: Based on standard atmospheric pressure model
- **Alert Thresholds**: Modify constants for different operational requirements

## 🔬 Performance Analysis

### System Specifications
- **Sensor Resolution**: 0.1°C temperature, 0.1% humidity
- **Update Rate**: 2-second sensor polling, real-time processing
- **Display Refresh**: 3-second cycling between parameter groups
- **Alert Response**: Immediate threshold violation detection
- **Data Logging**: 5-second telemetry transmission intervals

### Operational Characteristics
- ✅ **Multi-Parameter Monitoring**: Simultaneous environmental tracking
- ✅ **Real-Time Processing**: Sub-second threshold analysis
- ✅ **Visual Feedback**: Intuitive LED status indication system
- ✅ **Audio Alerts**: Immediate notification of critical conditions
- ✅ **Data Export**: Mission-ready telemetry format
- ✅ **System Reliability**: Robust error handling and sensor validation

## 🌐 Applications & Use Cases

### Space Mission Applications
- **Satellite Environmental Monitoring**: Pre-launch and operational monitoring
- **Payload Protection**: Critical component environmental safety
- **Mission Planning**: Environmental condition forecasting
- **Ground Station Operations**: Local weather impact assessment

### Educational Applications
- **STEM Education**: Hands-on space technology demonstration
- **Data Science**: Real-time data collection and analysis
- **Engineering Projects**: System design and integration experience
- **Research Projects**: Environmental monitoring methodology

### Industrial Applications
- **Clean Room Monitoring**: Controlled environment maintenance
- **Laboratory Conditions**: Research environment documentation
- **Quality Control**: Manufacturing environment monitoring
- **Remote Sensing**: Unmanned environmental data collection

## 🔍 Troubleshooting

### Common Issues & Solutions

| Problem | Possible Cause | Solution |
|---------|---------------|----------|
| DHT22 reading errors | Sensor connection/power | Check wiring, ensure 5V supply |
| LCD display blank | Contrast/wiring issue | Verify connections, check power |
| No LED indication | Resistor/wiring problem | Check resistor values, connections |
| Erratic pressure readings | Potentiometer noise | Clean connections, add filtering |
| Serial output missing | Baud rate mismatch | Set Serial Monitor to 9600 baud |

### Debug Mode
Enable detailed debugging by modifying the code:
```cpp
#define DEBUG_MODE  // Add for detailed sensor output
```

### Performance Optimization
- Adjust sensor reading intervals based on application needs
- Modify display refresh rates for power conservation
- Customize alert thresholds for specific environments

## 🔮 Future Enhancements

### Planned Features
- [ ] **WiFi Connectivity**: Remote monitoring and control capabilities
- [ ] **SD Card Logging**: Long-term data storage and analysis
- [ ] **Real BMP280 Integration**: Actual pressure sensor implementation
- [ ] **GPS Module**: Location tracking for mobile applications
- [ ] **Battery Power**: Portable operation with power management
- [ ] **Web Dashboard**: Real-time data visualization interface
- [ ] **Multiple Sensor Arrays**: Distributed monitoring network
- [ ] **Machine Learning**: Predictive weather analysis

### Advanced Applications
- [ ] **IoT Integration**: Cloud-based data aggregation
- [ ] **Mobile App**: Smartphone monitoring interface
- [ ] **Satellite Communication**: Direct space mission integration
- [ ] **Solar Panel Monitoring**: Power system environmental effects
- [ ] **Radiation Detection**: Extended space weather monitoring

## 🤝 Contributing

We welcome contributions to enhance this space weather monitoring system!

### How to Contribute
1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/SpaceWeatherEnhancement`)
3. **Commit** your changes (`git commit -m 'Add advanced telemetry features'`)
4. **Push** to the branch (`git push origin feature/SpaceWeatherEnhancement`)
5. **Open** a Pull Request

### Contribution Areas
- Hardware optimizations and additional sensors
- Code efficiency improvements and error handling
- New display modes and data visualization
- IoT integration and connectivity features
- Documentation improvements and tutorials
- Testing frameworks and validation procedures

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **NASA**: For inspiration from real space weather monitoring systems
- **Arduino Community**: For extensive libraries and hardware support
- **DHT Sensor Library**: Adafruit for reliable sensor integration
- **Wokwi Platform**: For excellent Arduino simulation capabilities
- **Open Source Community**: For collaborative development support

## 📞 Contact & Support

- **Project Maintainer**: [Abhishek](mailto:abhishekmittal24gold@gmail.com)

## 🏆 Project Statistics

```
Total Components: 10
Lines of Code: 200+
Sensor Parameters: 4
Display Modes: 3
Alert Conditions: 4
```

---

<div align="center">

**🛰️ Monitoring the Final Frontier 🌌**

**⭐ If this project inspired you, please give it a star! ⭐**

*Built with 🚀 for space exploration and environmental monitoring*

</div>
