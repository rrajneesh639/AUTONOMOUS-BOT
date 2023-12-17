int const M11 = 5;
int const M12 = 6;
int const M21 = 10;
int const M22 = 11;
int const SL=1;
int const SM=2;
int const SR=13;



void setup() {
  // put your setup code here, to run once:
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(SL,INPUT);
  pinMode(SM,INPUT);
  pinMode(SR,INPUT);
  pinMode(13,OUTPUT);
}
void moveForward(){
  analogWrite(M11,100);
  analogWrite(M12,0);
  analogWrite(M21,100);
  analogWrite(M22,0);
}
  
void moveBackward(){
analogWrite(M11,0);
analogWrite(M12,100);
analogWrite(M21,0);
analogWrite(M22,100);
}
void moveLeft(){
analogWrite(M11,100);
analogWrite(M12,0);
analogWrite(M21,0);
analogWrite(M22,100);
}
void moveRight(){
analogWrite(M11,0);
analogWrite(M12,100);
analogWrite(M21,100);
analogWrite(M22,0);
}
void stop_m(){
  analogWrite(M11,0);
analogWrite(M12,0);
analogWrite(M21,0);
analogWrite(M22,0);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
//  moveForward()  ;
  while(1){
    int l=digitalRead(SL);
    int m=digitalRead(SM);
    int r=digitalRead(SR);
    analogWrite(13,r);
    if(l==0 && m==1 && r==0){
    moveForward();
    }
    else if((l==0 && m==0 && r==1)){
    moveRight();
    }
    else if(l==1 && m==0 && r==0){
    moveLeft();
    }
    else if(l==1 && m==1 && r==0){
    moveLeft();
    }
    else if(l==1 && m==1 && r==1){
    moveLeft();
    }
    else if(l==0 && m==1 && r==1){
    moveRight();
    }
   //else if(l==0 && m==0 && r==0){
   // moveBackward();
    //}
    
  }
}