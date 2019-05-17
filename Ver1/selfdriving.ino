void selfDrivingLoop(){
  int touchState = touchSensor.isPressed();
  unsigned int distance = sonar.ping_cm(); // read distance from ultrasonic sensor 
  
  if(touchState == 0 && !closeToObject(distance)){
    drive(1);
    delay(50);
  }else{
    
    doStop();
    driveDistance(0, 20);
    turn(getLongestDrivingDirection(), 70);
    
  }
}

bool closeToObject(int distanceToObject){
  Serial.print("Distance: ");
  Serial.println(distanceToObject);
    if(distanceToObject > 20 || distanceToObject == 0){
      return false;
    }else{
      return true;
    }
  }
