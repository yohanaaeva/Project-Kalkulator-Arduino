//Proyek #35:Arduino Kalkulator 
#include <LiquidCrystal.h>
#include <Keypad.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
//defenisikan jumlah kolom dan baris keypad 4 x 4
const byte JmlBaris = 4;
const byte JmlKolom = 4;
//definsikan keymap
char keys[JmlBaris][JmlKolom] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', 'x'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};
  byte PinBaris[JmlBaris] = {6, 5, 4, 3}; 
  byte PinKolom[JmlKolom] = {2, 1, 0, 13}; 

Keypad myKeypad = Keypad(makeKeymap(keys), PinBaris, PinKolom, JmlBaris, JmlKolom );

boolean valOnePresent = false;
boolean final = false;
String num1, num2;
long ans;
char op;
void setup(){
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("Kalkulator-Ku!");
  delay(1000);
  lcd.clear();
}
void loop(){
  char key = myKeypad.getKey();
  if(key!=NO_KEY && key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='0'){
  if (valOnePresent != true){
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(15-numLength, 0);
      lcd.print(num1);
    }
    else {
      num2 = num2 + key;
      int numLength = num2.length();
      lcd.setCursor(15 - numLength, 1);
      lcd.print(num2);
      final = true;
    }
  }
  else if (valOnePresent == false && key != NO_KEY && (key  
       == '/' || key == 'x' || key == '-' || key == '+')){
   
   if (valOnePresent == false){
       valOnePresent = true;
       op = key;
       lcd.setCursor(15,0); 
       lcd.print(op);
    }
  }
  else if (final == true && key != NO_KEY && key == '='){
    if (op == '+'){
      ans = num1.toInt() + num2.toInt();
    }
    else if (op == '-'){
      ans = num1.toInt() - num2.toInt();
    }
    else if (op == 'x'){
      ans = num1.toInt() * num2.toInt();
    }
    else if (op == '/'){
      ans = num1.toInt() / num2.toInt();
    }    
      lcd.clear();
      lcd.setCursor(15,0);
      lcd.autoscroll();
      lcd.print(ans);
      lcd.noAutoscroll();
  }
  else if (key != NO_KEY && key == 'C'){
    lcd.clear();
    valOnePresent = false;
    final = false;
    num1 = "";
    num2 = "";
    ans = 0;
    op = ' ';
  }
}
