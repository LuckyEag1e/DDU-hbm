#define s0 8
#define s1 9
#define s2 10
#define s3 11
#define out 12

int data=0;
int number=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);

  Serial.begin(9600);

  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);
  


}

void loop() {
  // put your main code here, to run repeatedly:

//red
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
//  Serial.print("Red value= ");
  data=pulseIn(out,LOW);
  int r=map(data,60,15,0,100);
  //Serial.print(r);
  Serial.print("\t");
  delay(20);

//green
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  //Serial.print("Green value= ");
  data=pulseIn(out,LOW);
  int g=map(data,80,20,0,100);
  //Serial.print(g);
  Serial.print("\t");
  delay(20);  

//blue
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  //Serial.print("Blue value= ");
  data=pulseIn(out,LOW);
  int b=map(data,80,11,0,100);
  //Serial.print(b);
  Serial.print("\t");
  delay(20);  


  Serial.println();

  delay(200);
  
//red
  if (r==120 || r==122) {
    if (g==101 || g==103) {
      if (b==95 || b==97) {
        //Serial.print("Red");
        number=1;
        Serial.print(number);
      }
    }
  }

//orange
  if (r==120 || r==122) {
    if (g==110 || g==111 || g==113) {
      if (b==98 || b==100) {
        //Serial.print("Orange");
        number=2;
        Serial.print(number);
      }
    }
  }

//yellow
  if (r==120 || r==124) {
    if (g==123 || g==125) {
      if (b==101 || b==102) {
        //Serial.print("Yellow");
        number=3;
        Serial.print(number);
      }
    }
  }

//green
  if (r==115 || r==117) {
    if (g==123 || g==125) {
      if (b==105 || b==107) {
        //Serial.print("Green");
        number=4;
        Serial.print(number);
      }
    }
  }

  //light blue
  if (r==111 || r==113 || r==115) {
    if (g==121 || g==123 || g==125) {
      if (b==108 || b==110) {
        //Serial.print("Light blue");
        number=5;
        Serial.print(number);
      }
    }
  }

  //dark blue
  if (r==80 || r==82 || r==84) {
    if (g==110 || g==111) {
      if (b==105 || b==107) {
        //Serial.print("Dark blue");
        number=6;
        Serial.print(number);
      }
    }
  }
  if (75<r<80) {
    if (103<g<107) {
      if (102<b<104) {
        //Serial.print("Dark blue");
      }
    }
  }

  //purple
  if (r==106 || r==108) {
    if (g==106 || g==105) {
      if (b==104 || b==102) {
        //Serial.print("Purple");
        number=7;
        Serial.print(number);
      }
    }
  }

  //pink
  if (r==124 || r==126) {
    if (g==123 || g==125) {
      if (b==110 || b==111) {
        //Serial.print("Pink");
        number=8;
        Serial.print(number);
      }
    }
  }

  //white
  if (r==124 || r==126) {
    if (g==126 || g==128) {
      if (b==110 || b==111) {
        //Serial.print("White");
        number=9;
        Serial.print(number);
      }
    }
  }

  //black
  if (r==44 || r==46 || r==48) {
    if (g==61 || g==63 || g==65) {
      if (b==65 || b==66) {
        //Serial.print("Black");
        number=0;
        Serial.print(number);
      }
    }
  }

}
