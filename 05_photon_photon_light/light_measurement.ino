// Variables
int light;

// Pins
int light_sensor_pin = A0;

void setup() {
    
}
void loop() {
    
    // Light level measurement
    float light_measurement = analogRead(light_sensor_pin);
    light = (int)(light_measurement/4096*100);
    
    // Publish data
    Particle.publish("light_f39JEHmP", String(light));
    delay(2000);
    
}