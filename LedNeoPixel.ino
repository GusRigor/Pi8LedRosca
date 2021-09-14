/* Trabalho realizado por Aurora Campos & Fernando Campos
Trata-se do modelo com 12 LEDs
Apaga a cada volta todos os LEDdo NeoPixel 
Vai variando a cor de acordo com os códigos RGB
Comando através de um só condutor porta 2 do arduino.
Os leds são alimentados a partir do arduino
Utiliza livraria especifica Adafruit_NeoPixel.h
Mais informação e modelos pode ser encontrado em 
https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

*/

/* Inclusão de livraria e variáveis globais */

#include <Adafruit_NeoPixel.h>

#define PIN 2          // define o pin de saida para comunicação
#define NUMPIXELS  16 // numero de leds utilizados no modelo

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Inicializa  estrutura de acordo com as carateristicas do modelo


int delayval = 100; // tempo de delay para a sensação de movimento
                     // utilizar por exemplo entre 10 (dez meilisegundos)e 1000 (1 segundo) 
                     // valor por defeito 100 milisegundos

// inicialização das variáveis da cor vermelha, verde e azul com o código da cor 

int redColor = 0;      
int greenColor = 0;
int blueColor = 0;
long numAleatorioInt;

// Configura porta série e NeoPixel
void setup() {
  // Inicializa a livraria do NeoPixel
pixels.begin();
 pixels.show(); // Inicializa com todos os leds apagados
  // Inicializa porta série a 9600 Baud
Serial.begin(9600);
  // inicializa o gerador de números aleatórios.
  // um pino analógico desconectado irá retornar um
  // valor aleatório de tensão em analogRead()
  randomSeed(analogRead(0));
//  pixels.setBrightness(64);
  delay  (100); // espera no arranque
}

void loop() {
 
  randomSeed(analogRead(0)); // Semente variável a partir de uma fonte aleatória

 setColor();

  
for(int i=0;i<NUMPIXELS;i++){
//  a função pixels.Color tem como parametro de entrada os valores entre 0 e 255 
  // respeitantes às cores vermelha, verde e azul (RGB), variáveis
  // redColor, greenColor, blueColor.
  // O primeiro argumento i , no exemplo é o pixel (led) number ao longo da cadeia de leds ,
  // começando no 0 .
pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
  // Envia a cor para o Hardware do NeoPixel
pixels.show();
  
delay(delayval); // atraso de acordo com valor progranado na variável global delayval

if (i == 0){
 // após ter chegado ao número máximo de Leds do NeoPixel inicia tudo novamente
 // e apaga os 12 leds
   pixels.clear(); // limpa o NeoPixel
  numAleatorioInt = random(256);
 // pixels.setBrightness(numAleatorioInt);
 // pixels.show();
  delay (100);

}
 
}
}

/* função setColor()
  gera valores RGB aleatórios
  Envia informação para o Monitor Serial com o código usado
  e valor é usado para ser usado nas funções do NeoPixel
   pixels.setPixelColor, no comando do respetivo LED i*/

void setColor(){
redColor = random(0, 255);
greenColor = random(0,255);
blueColor = random(0, 255);
Serial.print("red: ");
Serial.println(redColor);
Serial.print("green: ");
Serial.println(greenColor);
Serial.print("blue: ");
Serial.println(blueColor);
}
