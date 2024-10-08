const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

int number_1;
int number_2;
int number_3;

void setup()
{
   Serial.begin(115200);
   Serial.println();
   Serial.println("Enter 3 numbers separated by commas");
}

void loop()
{
   recvWithEndMarker();
   //showNewData();
   if (newData)
   {
      parseData();
   }
}

void recvWithEndMarker()
{
   static byte ndx = 0;
   char endMarker = '\n';
   char rc;

   while (Serial.available() > 0 && newData == false)
   {
      rc = Serial.read();

      if (rc != endMarker)
      {
         receivedChars[ndx] = rc;
         ndx++;
         if (ndx >= numChars)
         {
            ndx = numChars - 1;
         }
      }
      else
      {
         receivedChars[ndx] = '\0'; // terminate the string
         ndx = 0;
         newData = true;
      }
   }
}

void showNewData()
{
   if (newData == true)
   {
      Serial.print("Input recieved: ... ");
      Serial.println(receivedChars);
      //newData = false;
   }
}

void parseData()
{
   char *strings[8]; // an array of pointers to the pieces of the above array after strtok()
   char *ptr = NULL; byte index = 0;
   ptr = strtok(receivedChars, ",");  // delimiters, semicolon
   while (ptr != NULL)
   {
      strings[index] = ptr;
      index++;
      ptr = strtok(NULL, ",");
   }
   
   // convert string data to numbers
   number_1 = atoi(strings[0]);
   number_2 = atoi(strings[1]);
   number_3 = atoi(strings[2]);
   Serial.print("Final problem: ");
   /*String problem1 = String(strings[0]+='+');
   String problem2 = String(strings[1]+='=');
   String problem3 = String(problem1+=problem2);
   String problem = String(problem3+=strings[2]);*/
  
  if(number_1!=NULL && number_2!=NULL && number_!=NULL){
   String problem=strings[0];
   problem.concat("+");
   problem.concat(strings[1]);
   problem.concat("=");
   problem.concat(strings[2]);

   Serial.print(problem);
   Serial.println(); // blank line
   delay(1000);

   Serial.print("This problem is: ");
   bool correct = false;
   if((number_1+number_2)==number_3){
    Serial.print("true");
    correct=true;
   }else{
    Serial.print("false");
   }
   
   Serial.println();
  }else{
   Serial.println("incomplete statement"); 
  }
   newData = false;
}
