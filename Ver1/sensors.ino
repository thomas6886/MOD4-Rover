int readUltrasoneAtDegreesAndDirection(int direction, float degrees){
  turnUltrasone(direction, degrees);
  delay(500);
  unsigned int distanceToObject = sonar.ping_cm(); // read distance from ultrasonic sensor 
  Serial.println(distanceToObject);
  delay(1000);
  if(direction == 0){ // return to center
    turnUltrasone(1, degrees);
  }else{
    turnUltrasone(0, degrees);
  }
  return distanceToObject;
}

int getLongestDrivingDirection(){
  int distanceLeft = readUltrasoneAtDegreesAndDirection(0, 70);
  int distanceRight = readUltrasoneAtDegreesAndDirection(1, 70);
  //Serial.println(distanceLeft);
  //Serial.println(distanceRight);
  if(distanceLeft == distanceRight){
    return 0;
  }else if(distanceLeft > distanceRight){
    return 0;
  }else{
    return 1;
  } 
  
}
