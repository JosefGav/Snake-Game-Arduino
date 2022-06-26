#include <PagonGameDev_GameLoop.h>
#include "LedControl.h"
#include <math.h>

byte frown[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
};
byte smile[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
};





byte digits[10][8][8] = {
  {
  {0,1,1,1,1,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
 },
{
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
 },
 {
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
},

{
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,0,0,0},
 },

{
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,1,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,0,0},
 },

{
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
 },

 {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
 },

{
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,1,0,0,0,0},
 },

 {
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,0,0,0,0,1,0},
  {0,1,1,1,1,1,1,0},
 },

  {
  {0,0,1,1,1,1,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,0,0,0,1,0},
  {0,0,1,1,1,1,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,1,0},
 },

};

 

int snakeLength = 1; 
int gameCycles = 1;

int VRx = A4;
int VRy = A5;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int piezo = 5;


LedControl dotmatrix = LedControl(13,11,12,1);
byte gameState = 0;

// statuses:
// 0: empty
// 1: head
// 2: snake 
// 3: apple
int grid[8][8] = {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,3,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  };

int apple[2] = {3,4};
int head[2] = {3,0};
byte snake[128][2] = {
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0}, 
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
  {0,0},
};

// snake direction in terms of clock headings
int snakeDirection = 12;
bool canTeleport = true;

void movesnake();
void blinkapple();
void increaseSnakeLength();
GameInterval snakeloop(400, movesnake);
GameInterval appleloop(200,blinkapple);
//GameInterval increaseLength(3000,increaseSnakeLength);

void setup() {
  Serial.begin(9600);
  dotmatrix.shutdown(0,false); 
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  pinMode(piezo,OUTPUT);
}

void loop() {

  //increaseLength.update();
  appleloop.update();
  snakeloop.update();
  
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);


  if (mapX > 500 && (mapY > -300 && mapY < 300) && snakeDirection != 6) {
    snakeDirection = 12;
  }

  if (mapX < -500 && (mapY > -300 && mapY < 300) & snakeDirection != 12) {
    snakeDirection = 6;
  }

  if (mapY > 500 && (mapX > -300 && mapX < 300) && snakeDirection != 9) {
    snakeDirection = 3;
  }
  
  if (mapY < -500 && (mapX > -300 && mapX < 300) && snakeDirection != 3) {
    snakeDirection = 9;
  }

  if (SW_state == 0){
      canTeleport = false;
    }

};

void movesnake(){
  if (gameState == 1) {
    
    for (int r = 0; r < 8; r++){
      for (int c = 0; c < 8; c++){
        grid[r][c] = 0;
      }
    }
    
    dotmatrix.clearDisplay(0);
    for (int r = 7; r >= 0; r--) {
      for (int c = 0; c < 8; c++) {
        if (frown[r][c] == 1) {
          dotmatrix.setLed(0, c, 7-r, true);
        };
      };
    };

    delay(1000);


    
    while (true){
    dotmatrix.clearDisplay(0);
    for (int r = 7; r >= 0; r--) {
      for (int c = 0; c < 8; c++) {
        if (digits[round(snakeLength/10)][r][c] == 1) {
          dotmatrix.setLed(0, c, 7-r, true);
        };
      };
    };

    losesong(piezo);

    
    dotmatrix.clearDisplay(0);
    for (int  r = 7; r >= 0; r--) {
      for (int c = 0; c < 8; c++) {
        if (digits[snakeLength%10][r][c] == 1) {
          dotmatrix.setLed(0, c, 7-r, true);
        };
      };
    };
    losesong(piezo);

    }
    
  };

  if (snakeLength >= 48) {
      dotmatrix.clearDisplay(0);
    for (byte r = 7; r >= 0; r--) {
      for (byte c = 0; c < 8; c++) {
        if (smile[r][c] == 1) {
          dotmatrix.setLed(0, c, 7-r, true);
        };
      };
    };
    song(5);
  };
  
  if (gameState == 0 && snakeLength < 48) {

    if (gameCycles == 128) {

        for (int i = 64; i < 128;i++){
          snake[i-64][0] = snake[i][0] + 0;
          snake[i-64][1] = snake[i][1] + 0;

          snake[i][0] = 0;
          snake[i][1] = 0;
        }
        gameCycles = 64;
    };
    
    snake[gameCycles][0] = head[0];
    snake[gameCycles][1] = head[1];

    if (snakeDirection == 12) head[1]++;
    if (snakeDirection == 3) head[0]++;
    if (snakeDirection == 6) head[1]--;
    if (snakeDirection == 9) head[0]--;
    
    if (head[1] > 7 && canTeleport == true) head[1] = 0;
    else if (head[1] > 7 && canTeleport == false) gameState = 1;
    
    if (head[1] < 0 && canTeleport == true) head[1] = 7;
    else if (head[1] < 0 && canTeleport == false) gameState = 1;
    
    if (head[0] > 7 && canTeleport == true) head[0] = 0;
    else if (head[0] > 7 && canTeleport == false) gameState = 1;
    
    if (head[0] < 0 && canTeleport == true) head[0] = 7;
    else if (head[0] < 0 && canTeleport == false) gameState = 1;

    for (byte r = 0; r < 8; r++){
      for (byte c = 0; c < 8; c++){
        grid[r][c] = 0;
      }
    }
    dotmatrix.clearDisplay(0);



    for (byte i = gameCycles; i > gameCycles - snakeLength + 1; i--) {
      grid[snake[i][1]][snake[i][0]] = 2;
      dotmatrix.setLed(0,snake[i][0],snake[i][1],true);
    };
    grid[apple[1]][apple[0]] = 3;

    dotmatrix.setLed(0,head[0],head[1],true);
    if (grid[head[1]][head[0]]==2){
      Serial.println("collission");
      gameState = 1;

      
    } else if (grid[head[1]][head[0]]==3){
      // check for apple
      Serial.println("apple");
      
      for (byte r = 0; r < 8; r++){
        for (byte c = 0; c < 8; c++){
          grid[r][c] = 0;
        }
      }
      dotmatrix.clearDisplay(0);
      
      for (byte i = gameCycles; i > gameCycles - snakeLength + 1; i--) {
        grid[snake[i][1]][snake[i][0]] = 2;
        dotmatrix.setLed(0,snake[i][0],snake[i][1],true);
      };

      grid[head[1]][head[0]] = 1;
      dotmatrix.setLed(0,head[0],head[1],true);

      snakeLength++;
      gameCycles++;
      generateApple();
      tone(piezo,500,300);
    } else {
      
      grid[head[1]][head[0]] = 1;
   
      gameCycles++;
     }
  };
}

void blinkapple(){
    
  if (gameState == 0) {
    dotmatrix.setLed(0,apple[0],apple[1],false);
    dotmatrix.setLed(0,apple[0],apple[1],true);
  }
}

void increaseSnakeLength(){
   snakeLength++;
   Serial.println(snakeLength);
}

void generateApple(){
  int x = random(0,7);  
  int y = random(0,7);  

  while (grid[y][x] == 1 || grid[y][x] == 2) {
    x = random(0,7);  
    y = random(0,7); 
  }

  apple[0] = x;
  apple[1] = y;
  grid[y][x] = 3;
}

void losesong(int piezo){
  tone(piezo,500,200);
  delay(200);
  tone(piezo,500,200);
  delay(200);
  tone(piezo,500,200);
  delay(200);
  tone(piezo,800,150);
  delay(150);
  tone(piezo,500,500);
  delay(500);
  tone(piezo,600,1000);
  delay(500);
}

void song(int buzzerPin){
  
  tone(buzzerPin, 554);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 554);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 494);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 554);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 415);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 494);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 466);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 554);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 554);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 554);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(569);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 831);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 622);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 698);
  delay(189);
  noTone(buzzerPin);

  tone(buzzerPin, 740);
  delay(759);
  noTone(buzzerPin);
}
