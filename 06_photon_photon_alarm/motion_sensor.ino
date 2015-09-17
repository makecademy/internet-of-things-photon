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
}

void loop() {
    
    // Motion sensor measurement
    motion = digitalRead(motion_sensor_pin);
    if (motion != last_motion) {
        
        // Publish data
        Particle.publish("motion_yjMgA5xX", String(motion));
    }
    
    // Save state
    last_motion = motion;
}