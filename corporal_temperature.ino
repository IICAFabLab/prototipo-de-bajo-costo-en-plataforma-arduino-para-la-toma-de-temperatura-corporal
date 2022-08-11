#include <Wire.h>
#include <LiquidCrystal_I2C.h> //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2Clibrary
#include <Adafruit_MLX90614.h> //https://github.com/adafruit/Adafruit-MLX90614-Library
LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int SensorValue;
//pines sensor de distancia
const int Trigger = 2; //Pin digital 2 para el Trigger del sensor
const int Echo = 3; //Pin digital 3 para el echo del sensor
//leds
int LED_blancoPin = 5;
int LED_rojoPin = 6;
int LED_azulPin = 7;
//buzzer
int buzzerPin = 8;
void setup() {
 Serial.begin(9600);
 pinMode(Trigger, OUTPUT); //pin como salida
 pinMode(Echo, INPUT); //pin como entrada
 digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
 pinMode (buzzerPin, OUTPUT); 
 // inicializar LCD
 lcd.begin();
 //encender blacklight
 lcd.backlight();
 //inicializar sensor temp 
 mlx.begin(); 
} 
void loop() {
 //sensor de movimiento
 long t; //tiempo que demora en llegar el eco
long dis; //distancia en centimetros
 digitalWrite(Trigger, HIGH);
 delayMicroseconds(10); //Enviamos un pulso de 10us
 digitalWrite(Trigger, LOW);
 t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
 dis = t/59; //escalamos el tiempo a una distancia en cm
 delay (100);
 //sensor temperatura
 SensorValue = mlx.readObjectTempC(); //guarda la temperatura del "objeto"
 if (dis<5){
 digitalWrite (LED_blancoPin, HIGH);
 lcd.backlight();
 lcd.print("Bienvenido(a)"); 
 delay (800);
 lcd.clear();
 lcd.print("al IICA");
 delay (800);
 lcd.clear();
 if (SensorValue < 37.5) {
 digitalWrite (LED_blancoPin, LOW);
 digitalWrite (LED_azulPin, HIGH);
 lcd.clear();
 lcd.setCursor(0,0);
 Serial.print("T.Ambiente="); Serial.print(mlx.readAmbientTempC());
 lcd.print("T.Ambiente="); lcd.print(mlx.readAmbientTempC());
 lcd.setCursor(0,1);
 Serial.print("T.Corporal="); Serial.print(mlx.readObjectTempC()); 
 lcd.print("T.Corporal="); lcd.print(mlx.readObjectTempC()); 
 delay (3000);
 lcd.clear();
 lcd.print("Pase adelante!");
 delay (2500);
 lcd.clear();
 lcd.print("Por favor");
 delay (500);
 lcd.clear();
 digitalWrite (LED_azulPin, LOW);
 }
 else {
 digitalWrite (LED_blancoPin, LOW);
 digitalWrite (LED_rojoPin, HIGH);
 lcd.clear();
 lcd.setCursor(0,0);
 Serial.print("T.Ambiente="); Serial.print(mlx.readAmbientTempC());
 lcd.print("T.Ambiente="); lcd.print(mlx.readAmbientTempC());
 lcd.setCursor(0,1);
 Serial.print("T.Corporal="); Serial.print(mlx.readObjectTempC());
 lcd.print("T.Corporal="); lcd.print(mlx.readObjectTempC()); 
 delay (3000); 
 lcd.clear();
 digitalWrite (buzzerPin, HIGH);
 lcd.print("Dirijase al");
 delay (1000);
 lcd.clear();
 lcd.print ("Consultorio.");
 delay (1500);
 lcd.clear();
 lcd.print("Por favor");
 delay (500);
 lcd.clear();
 digitalWrite (LED_rojoPin, LOW);
 digitalWrite (buzzerPin, LOW); 
 }
}
 else
 lcd.print("Buen dia!");
 delay (1000);
 lcd.clear();
}
