// /*
//   ESP-NOW Demo - Receive
//   esp-now-demo-rcv.ino
//   Reads data from Initiator

//   DroneBot Workshop 2022
//   https://dronebotworkshop.com
// */
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include <Wire.h>
// // Include Libraries
// #include <WiFi.h>
// #include <esp_now.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels

// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// // game loop
// typedef struct struct_game {
//   uint8_t gameStage;    // 0: waiting, 1: playing, 2: wined
//   uint8_t playerNumber; // 1: player1, 2: player2, 0: default
//   uint8_t action;       // 1: block, 2: hit(lost blood), 0: default
//   int player1health;
//   int player2health;
// } struct_game;

// // Create a structured object
// struct_game myData;

// // Callback function executed when data is received
// void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
//   memcpy(&myData, incomingData, sizeof(myData));
//   Serial.print("Data received: ");
//   Serial.println(len);
//   Serial.print("Game Stage: ");
//   Serial.println(myData.gameStage);
//   Serial.print("Player Number: ");
//   Serial.println(myData.playerNumber);
//   Serial.print("Action: ");
//   Serial.println(myData.action);
//   Serial.print("Player1 Health: ");
//   Serial.println(myData.player1health);
//   Serial.print("Player2 Health: ");
//   Serial.println(myData.player2health);
//   Serial.println();

//   // d1
//   // display1.clearDisplay();
//   // display1.setTextSize(1);
//   // display1.setTextColor(WHITE);
//   // display1.setCursor(0, 10);
//   // // Display static text
//   // display1.println("Game Stage: ");
//   // display1.println(sprintf("%d", myData.gameStage));
//   // // display1.println("Player Number: ");
//   // // display1.println(myData.playerNumber);
//   // display1.println("Action: ");
//   // display1.println(myData.action);
//   // display1.println("Player1 Health: ");
//   // display1.println(myData.player1health);
//   // display1.println("Player2 Health: ");
//   // display1.println(myData.player2health);
//   // display1.display();

//   // d2
//   // display2.clearDisplay();
//   // display2.setTextSize(1);
//   // display2.setTextColor(WHITE);
//   // display2.setCursor(0, 10);
//   // // Display static text
//   // // display2.println("Game Stage: ");
//   // // display2.println(myData.gameStage);
//   // // display2.println("Player Number: ");
//   // // display2.println(myData.playerNumber);
//   // display2.println("Action: ");
//   // display2.println(myData.action);
//   // display2.println("Player1 Health: ");
//   // display2.println(myData.player1health);
//   // display2.println("Player2 Health: ");
//   // display2.println(myData.player2health);
//   // display2.display();
// }

// void setup() {
//   // Set up Serial Monitor
//   Serial.begin(9600);
//   Serial.println("ESP-NOW Receiver");

//   // Print MAC Address to Serial monitor
//   Serial.print("MAC Address: ");
//   Serial.println(WiFi.macAddress());

//   // Set ESP32 as a Wi-Fi Station
//   WiFi.mode(WIFI_STA);

//   // Initilize ESP-NOW
//   if (esp_now_init() != ESP_OK) {
//     Serial.println("Error initializing ESP-NOW");
//     return;
//   }

//   // display1.setTextSize(1);
//   // display1.setTextColor(WHITE);
//   // display1.setCursor(0, 10);
//   // display1.println("Hello, world! d1");

//   // display2.setTextSize(1);
//   // display2.setTextColor(WHITE);
//   // display2.setCursor(0, 10);
//   // display2.println("Hello, world! d2");

//   // Register callback function
//   esp_now_register_recv_cb(OnDataRecv);
// }

// void loop() {
// }

// // #include <Adafruit_GFX.h>
// // #include <Adafruit_SSD1306.h>
// // #include <Wire.h>

// // #define SCREEN_WIDTH 128 // OLED display width, in pixels
// // #define SCREEN_HEIGHT 64 // OLED display height, in pixels

// // // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// // Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// // Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// // void setup() {
// //   Serial.begin(115200);

// //   if (!display1.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
// //     Serial.println(F("SSD1306 allocation failed display1"));
// //     for (;;)
// //       ;
// //   }

// //   if (!display2.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
// //     Serial.println(F("SSD1306 allocation failed display2"));
// //     for (;;)
// //       ;
// //   }

// //   delay(2000);

// //   // d1
// //   display1.clearDisplay();

// //   display1.setTextSize(1);
// //   display1.setTextColor(WHITE);
// //   display1.setCursor(0, 10);
// //   // Display static text
// //   display1.println("Hello, world! d1");
// //   display1.display();

// //   // d2
// //   display2.clearDisplay();

// //   display2.setTextSize(1);
// //   display2.setTextColor(WHITE);
// //   display2.setCursor(0, 10);
// //   // Display static text
// //   display2.println("Hello, world! d2");
// //   display2.display();
// // }

// // void loop() {
// // }

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <Wire.h>
#include <esp_now.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long previousMillis = 0;           // Variable to store the last time the function was called
const unsigned long timeoutInterval = 1000; // Timeout interval in milliseconds (5 seconds)

struct struct_game {
  uint8_t gameStage;
  uint8_t playerNumber;
  uint8_t action;
  int player1health;
  int player2health;
} myData;

volatile bool newDataAvailable = false;

void displayWaiting() {
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 10);
  display1.println("Waiting");
  display1.display();

  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 10);
  display2.println("Waiting");
  display2.display();
}

void displayPlaying(int playerNum) {
  Adafruit_SSD1306 *display;
  if (playerNum == 1) {
    display = &display1;
  } else {
    display = &display2;
  }

  display->clearDisplay();
  display->setTextSize(2);
  display->setTextColor(WHITE);
  display->setCursor(0, 10);
  display->println("Player: " + String(playerNum));
  display->println("HP: " + String(playerNum == 1 ? myData.player1health : myData.player2health));
  display->display();
}

void displayGotHit(int playerNum) {
  Adafruit_SSD1306 *display;
  if (playerNum == 1) {
    display = &display1;
  } else {
    display = &display2;
  }

  display->clearDisplay();
  display->setTextSize(2);
  display->setTextColor(WHITE);
  display->setCursor(0, 10);
  display->println("Got Hit!" + String(playerNum));
  display->display();

  previousMillis = millis();
}

void displayBlock(int playerNum) {
  Adafruit_SSD1306 *display;
  if (playerNum == 1) {
    display = &display1;
  } else {
    display = &display2;
  }

  display->clearDisplay();
  display->setTextSize(2);
  display->setTextColor(WHITE);
  display->setCursor(0, 10);
  display->println("Block!");
  display->display();

  previousMillis = millis();
}

void displayWin(int playerNum) {

  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 10);
  display1.println("Player " + String(playerNum) + " \nWin!");
  display1.display();

  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 10);
  display2.println("Player " + String(playerNum) + " \nWin!");
  display2.display();
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Game Stage: ");
  Serial.println(myData.gameStage);
  Serial.print("Player Number: ");
  Serial.println(myData.playerNumber);
  Serial.print("Action: ");
  Serial.println(myData.action);

  if (myData.gameStage == 0) {
    displayWaiting();

  } else if (myData.gameStage == 1) {
    if (myData.action == 1) {
      displayBlock(myData.playerNumber);
      displayPlaying(myData.playerNumber == 1 ? 2 : 1);
    } else if (myData.action == 2) {
      displayGotHit(myData.playerNumber);
      displayPlaying(myData.playerNumber == 1 ? 2 : 1);
    } else if (myData.action == 0) {
      displayPlaying(1);
      displayPlaying(2);
    }

  } else if (myData.gameStage == 2) {
    displayWin(myData.playerNumber);
  }
  // newDataAvailable = true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("ESP-NOW Receiver");
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  if (!display1.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed display1"));
    for (;;)
      ;
  }

  if (!display2.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed display2"));
    for (;;)
      ;
  }

  sleep(1);

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {

  // if (newDataAvailable) {

  //   if (myData.gameStage == 0) {
  //     displayWaiting();
  //   } else if (myData.gameStage == 1) {
  //     if (myData.action == 1) {
  //       displayBlock(myData.playerNumber);
  //       displayPlaying(myData.playerNumber == 1 ? 2 : 1);
  //     } else if (myData.action == 2) {
  //       displayGotHit(myData.playerNumber);
  //       displayPlaying(myData.playerNumber == 1 ? 2 : 1);
  //     } else if (myData.action == 0) {
  //       displayPlaying(1);
  //       displayPlaying(2);
  //     }
  //   } else if (myData.gameStage == 2) {
  //     displayWin(myData.playerNumber);
  //   }
  //   newDataAvailable = false; // Reset the flag
  // }

  // Other loop code
  if ((millis() - previousMillis) > timeoutInterval && myData.gameStage == 1) {
    displayPlaying(1);
    displayPlaying(2);
  }
}
