// Variables
int motion;
int last_motion;

// Motion sensor pin
int motion_sensor_pin = D0;

void setup() {
    
    // Set pin as input
    pinMode(motion_sensor_pin, INPUT);
    
    // Initialise variables
    motion = false;
    last_motion = false;

    // 1 min delay before alarms start (uncomment to activate alarm)
    // delay(60 * 1000);
}

void loop() {
    
    // Motion sensor measurement
    motion = digitalRead(motion_sensor_pin);
    if (motion != last_motion) {
        
        // Publish data
        Particle.publish("motion", String(motion));
    }
    
    // Save state
    last_motion = motion;
}