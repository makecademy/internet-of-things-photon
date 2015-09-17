// Lamp pin
int lampPin = D5;

// Thresholds
int thresholdHigh = 60;
int thresholdLow = 50;

void setup() {
    
  // Serial
  Serial.begin(9600);
    
  // Set pin as output
  pinMode(lampPin, OUTPUT);

  // Subscribe to other board light level measurement
  Particle.subscribe("light_f39JEHmP", myHandler);
  
}


void loop() {
  
}


// Function called whenever ambient light level is published
void myHandler(const char *event, const char *data)
{
  
  // Convert data to int
  int lightLevel = atoi(data);
  Serial.println(data);
  Serial.println(lightLevel);
  
  // Compare
  if (lightLevel > thresholdHigh) {
    digitalWrite(lampPin, LOW);          
  }
  
  if (lightLevel < thresholdLow) {
    digitalWrite(lampPin, HIGH);          
  }
}