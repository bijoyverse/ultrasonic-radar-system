import processing.serial.*;

Serial myPort;
String data = "";
float angle = 0;
float distance = 0;

void setup() {
  size(1200, 700);
  smooth();
  
  // Print available serial ports
  printArray(Serial.list());
  
  // Change the index [0] to match your Arduino port
  // Check the console output above to find the correct port
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  noStroke();
  fill(0, 4);
  rect(0, 0, width, height);
  
  drawRadar();
  drawLine();
  drawObject();
  drawText();
}

void serialEvent(Serial myPort) {
  try {
    data = myPort.readStringUntil('\n');
    if (data != null) {
      data = data.trim();
      int commaIndex = data.indexOf(',');
      if (commaIndex > 0) {
        angle = float(data.substring(0, commaIndex));
        distance = float(data.substring(commaIndex + 1));
      }
    }
  } catch (Exception e) {
    // Ignore parsing errors
  }
}

void drawRadar() {
  pushMatrix();
  translate(width/2, height - 74);
  noFill();
  strokeWeight(2);
  stroke(98, 245, 31);
  
  // Draw arc lines
  arc(0, 0, 800, 800, PI, TWO_PI);
  arc(0, 0, 600, 600, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  arc(0, 0, 200, 200, PI, TWO_PI);
  
  // Draw angle lines
  line(-400, 0, 400, 0);
  line(0, 0, -400 * cos(radians(30)), -400 * sin(radians(30)));
  line(0, 0, -400 * cos(radians(60)), -400 * sin(radians(60)));
  line(0, 0, -400 * cos(radians(90)), -400 * sin(radians(90)));
  line(0, 0, -400 * cos(radians(120)), -400 * sin(radians(120)));
  line(0, 0, -400 * cos(radians(150)), -400 * sin(radians(150)));
  line(-400 * cos(radians(30)), 0, 400 * cos(radians(30)), 0);
  
  popMatrix();
}

void drawLine() {
  pushMatrix();
  strokeWeight(9);
  stroke(30, 250, 60);
  translate(width/2, height - 74);
  line(0, 0, 400 * cos(radians(angle)), -400 * sin(radians(angle)));
  popMatrix();
}

void drawObject() {
  pushMatrix();
  translate(width/2, height - 74);
  strokeWeight(9);
  stroke(255, 10, 10);
  
  float pixelDistance = distance * 2; // Scale for display
  
  if (distance < 100) {
    float x = pixelDistance * cos(radians(angle));
    float y = -pixelDistance * sin(radians(angle));
    point(x, y);
  }
  popMatrix();
}

void drawText() {
  pushMatrix();
  fill(0, 0, 0);
  noStroke();
  rect(0, height - 74, width, 74);
  fill(98, 245, 31);
  textSize(25);
  
  text("10cm", width/2 - 400 + 25, height - 74 - 190);
  text("20cm", width/2 - 400 + 225, height - 74 - 190);
  text("30cm", width/2 - 400 + 425, height - 74 - 190);
  text("40cm", width/2 - 400 + 625, height - 74 - 190);
  
  textSize(40);
  text("Ultrasonic Radar", width/2 - 150, 50);
  text("Angle: " + int(angle) + "°", width/2 - 400, height - 20);
  text("Distance: " + int(distance) + "cm", width/2 + 100, height - 20);
  
  popMatrix();
}