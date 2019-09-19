#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//wi-fi e autenticação no Firebase
#define FIREBASE_HOST "https://homesweethome-521d1.firebaseio.com/"
#define FIREBASE_AUTH "w57pNiZ6Pt1RBjIWyBeEanjpyYR5ZpffzG3vZY9Q"
#define WIFI_SSID "ifdoce"
#define WIFI_PASSWORD "10tifsul"

//mapeamento de portas
#define LED_AZUL 3
#define LED_VERMELHO 16

void autenticarFirebase(){
  //autentica e inicializa o serviço de Realtimedatabase do Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void conectarWiFi(){
  //conecta com o wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\nconnecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  autenticarFirebase();
}

void setup() {
  //inicializa a comunicação serial com o monitor da IDE
  Serial.begin(9600);
  
  pinMode(LED_AZUL, OUTPUT); //led buit in azul
  pinMode(LED_VERMELHO, OUTPUT); //led buit in vermelho 

  conectarWiFi();
  
}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    if(Firebase.success()) {
      
      FirebaseObject sala = Firebase.get("Casa 3/Sala");
      if(sala.getBool("/Lampada1")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }
      
      FirebaseObject cozinha = Firebase.get("Casa 3/Cozinha");
      if(cozinha.getBool("Lampada2")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }

      FirebaseObject corredor = Firebase.get("Casa 3/Corredor");
      if(cozinha.getBool("Lampada3")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }

      FirebaseObject banheiro = Firebase.get("Casa 3/Banheiro");
      if(cozinha.getBool("Lampada4")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }

      FirebaseObject quarto1 = Firebase.get("Casa 3/Quarto1");
      if(quarto1.getBool("Lampada5")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }
      if(quarto1.getBool("Ar1")){
        Serial.println("Ar-Condicionado Ligado");
      }else{
        Serial.println("Ar-Condicionado Desligado");
      }

      FirebaseObject quarto2 = Firebase.get("Casa 3/Quarto2");
      if(quarto2.getBool("Lampada6")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }
      if(quarto2.getBool("Ar2")){
        Serial.println("Ar-Condicionado Ligado");
      }else{
        Serial.println("Ar-Condicionado Desligado");
      }

      FirebaseObject quarto3 = Firebase.get("Casa 3/Quarto3");
      if(quarto3.getBool("Lampada7")){
        Serial.println("Lampada Acessa.");
      }else{
        Serial.println("Lampada Desligada.");
      }
      if(quarto3.getBool("Ar3")){
        Serial.println("Ar-Condicionado Ligado");
      }else{
        Serial.println("Ar-Condicionado Desligado");
      }
      
    }else{
      Serial.println("Erro na autenticão com o Firebase");
    }
  }else{
    conectarWiFi();
  }
  
  delay(500);
}
