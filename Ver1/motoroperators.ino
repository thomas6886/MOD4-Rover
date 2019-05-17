// direction(0: backward ; 1: forward) drives motors until said otherwise
void drive(int direction){
  if(direction == 0){    
    evshield.bank_a.motorRunUnlimited( SH_Motor_Both, SH_Direction_Forward, speed);
  }else{
    evshield.bank_a.motorRunUnlimited( SH_Motor_Both, SH_Direction_Reverse, speed);
  }
}


void doStop(){
  evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Float);
  delay(300);
}

void driveDistance(int direction, int drivingDistance){
  float run100 = 100;
  float runFactor = drivingDistance / run100;
  float runDegree = runFactor * numMeterDegrees;
  Serial.println(runDegree);
  if(direction == 0){
    evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Forward, speed, (long)runDegree, SH_Completion_Wait_For, SH_Next_Action_Float);
  }else{
    evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Reverse, speed, (long)runDegree, SH_Completion_Wait_For, SH_Next_Action_Float);
  }
  delay(300);
}

// direction(0: left ; 1: right) degrees(how many degrees you want to turn in the direction)
void turn(int direction, float degrees){
  float totalCircle = 360;
  float turnFactor = degrees / totalCircle;
  float turnDegrees = turnFactor * numCircleDegrees;
  
  if(direction == 0){//LEFT
    evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Forward, speed, (long)turnDegrees, SH_Completion_Dont_Wait, SH_Next_Action_Float);
    evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, speed, (long)turnDegrees, SH_Completion_Wait_For, SH_Next_Action_Float);   
  }else{
    evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, speed, (long)turnDegrees, SH_Completion_Dont_Wait, SH_Next_Action_Float);
    evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse, speed, (long)turnDegrees, SH_Completion_Wait_For, SH_Next_Action_Float);
  }
  delay(2000);
  evshield.bank_a.motorReset();
   
}

int turnUltrasone(int direction, float turnDegrees){
  if(direction == 0){
    evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, speed, (long)turnDegrees, SH_Completion_Wait_For, SH_Next_Action_Brake);
  }else{
    evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, speed, (long)turnDegrees, SH_Completion_Wait_For, SH_Next_Action_Brake);
  }
  
}
