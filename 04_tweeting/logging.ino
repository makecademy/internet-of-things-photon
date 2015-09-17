// DHT parameters
#define DHTPIN 5
#define DHTTYPE DHT11

// Variables
int temperature;
int humidity;
int light;

// Pins
int light_sensor_pin = A0;

// DHT sensor
DHT dht(DHTPIN, DHTTYPE);
void setup() {
    
    // Start DHT sensor
    dht.begin();
}

void loop() {
    
    // Humidity measurement
    temperature = dht.getTempCelcius();
    
    // Humidity measurement
    humidity = dht.getHumidity();
    
    // Light level measurement
    float light_measurement = analogRead(light_sensor_pin);
    light = (int)(light_measurement/4096*100);
    
    // Publish data
    Particle.publish("temperature", String(temperature));
    delay(2000);
    Particle.publish("humidity", String(humidity));
    delay(2000);
    Particle.publish("light", String(light));

    // Larger delay
    delay(60*1000);
    
}