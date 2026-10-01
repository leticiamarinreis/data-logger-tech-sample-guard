#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RTClib.h>
#include <EEPROM.h>
#include <DHT.h>
 
// =====================================================
// CONFIGURAÇÕES GERAIS
// =====================================================
 
#define SERIAL_OPTION 1
 
// =====================================================
// SENSOR DHT11 & LDR
// =====================================================
 
#define DHTPIN 3
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
#define LDR_PIN A0
 
// =====================================================
// LCD I2C & RTC
// =====================================================
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 RTC;
 
// =====================================================
// LEDs & BUZZER & BOTÕES
// =====================================================
 
#define LED_VERDE 6
#define LED_VERMELHO 5
#define BUZZER 9
 
#define BOTAO_CIMA 10
#define BOTAO_BAIXO 11
#define BOTAO_ENTER 12
 
// =====================================================
// CARACTERES CUSTOMIZADOS (LOGO)
// =====================================================
 
// IMAGEM 1
const byte charA[] PROGMEM = { B00000, B00000, B00000, B00000, B00111, B01000, B01010, B01001 };
const byte charB[] PROGMEM = { B00000, B00000, B00001, B11110, B00000, B00000, B00000, B00000 };
const byte charC[] PROGMEM = { B00000, B00111, B11000, B00000, B00000, B00000, B00000, B00000 };
const byte charD[] PROGMEM = { B00000, B00000, B10000, B01000, B00100, B00010, B00001, B11101 };
const byte charE[] PROGMEM = { B01000, B01000, B00100, B00010, B00001, B00000, B00000, B00000 };
const byte charF[] PROGMEM = { B00001, B11110, B10000, B10000, B10000, B00011, B11100, B00000 };
const byte charG[] PROGMEM = { B11000, B00000, B00000, B00000, B01111, B10000, B00000, B00000 };
const byte charH[] PROGMEM = { B00001, B00001, B00011, B11100, B00000, B00000, B00000, B00000 };
 
// IMAGEM 2
const byte charI[] PROGMEM = { B00000, B00000, B00000, B01111, B10000, B10100, B10000, B00001 };
const byte charJ[] PROGMEM = { B00000, B00001, B11110, B00000, B00000, B00000, B00000, B00000 };
const byte charK[] PROGMEM = { B00111, B11000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charL[] PROGMEM = { B10000, B01000, B00100, B00010, B00001, B00000, B01110, B10000 };
const byte charM[] PROGMEM = { B10000, B10000, B10000, B01000, B00100, B00010, B00001, B00000 };
const byte charN[] PROGMEM = { B11000, B10000, B10000, B10000, B00000, B00000, B00001, B11110 };
const byte charO[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00111, B11000, B00000 };
const byte charP[] PROGMEM = { B00000, B00000, B00000, B00001, B11110, B00000, B00000, B00000 };
 
// IMAGEM 3
const byte charQ[] PROGMEM = { B00000, B00001, B11110, B00000, B00000, B01000, B00100, B00000 };
const byte charR[] PROGMEM = { B00011, B11100, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charS[] PROGMEM = { B01100, B00011, B00000, B00000, B00000, B00001, B01100, B10000 };
const byte charT[] PROGMEM = { B00000, B00000, B00000, B10000, B10000, B10000, B10000, B10000 };
const byte charU[] PROGMEM = { B00001, B00001, B00001, B00001, B00001, B00001, B00000, B00000 };
const byte charV[] PROGMEM = { B00000, B00001, B00001, B00001, B00000, B00001, B10000, B01100 };
const byte charW[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B01111, B10000 };
const byte charX[] PROGMEM = { B00000, B00000, B00000, B00000, B00111, B11000, B00000, B00000 };
 
// IMAGEM 4
const byte charY[] PROGMEM  = { B00000, B00011, B00100, B00100, B00100, B00100, B00100, B00100 };
const byte charZ[] PROGMEM  = { B11100, B00000, B00000, B00000, B10000, B01000, B00100, B00000 };
const byte charAA[] PROGMEM = { B00111, B00000, B00000, B00000, B00001, B00110, B10000, B00000 };
const byte charAB[] PROGMEM = { B00000, B11000, B00100, B00100, B00100, B00100, B00100, B00100 };
const byte charAC[] PROGMEM = { B00100, B00100, B00100, B00100, B00100, B00100, B00100, B00011 };
const byte charAD[] PROGMEM = { B00010, B00010, B00010, B00000, B00010, B00010, B00010, B00000 };
const byte charAE[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B11110 };
const byte charAF[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00111, B11000 };
 
// IMAGEM 5
const byte charAG[] PROGMEM = { B00100, B00100, B00100, B00100, B00100, B11000, B00000, B00000 };
const byte charAH[] PROGMEM = { B00111, B01000, B01000, B01001, B01000, B01000, B01000, B01000 };
const byte charAI[] PROGMEM = { B00000, B00000, B00000, B00000, B10000, B00000, B00100, B00000 };
const byte charAJ[] PROGMEM = { B00000, B00000, B00000, B00110, B10000, B00000, B00000, B00000 };
const byte charAK[] PROGMEM = { B11000, B00100, B00010, B00010, B00010, B00010, B00010, B00010 };
const byte charAL[] PROGMEM = { B01000, B01000, B01000, B01000, B01000, B01000, B01000, B00100 };
const byte charAM[] PROGMEM = { B00100, B00100, B00000, B00000, B00000, B00100, B00000, B00000 };
const byte charAN[] PROGMEM = { B00010, B00010, B00010, B00010, B00010, B00010, B00010, B01100 };
 
// IMAGEM 6
const byte charAO[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charAP[] PROGMEM = { B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
const byte charAQ[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00001 };
const byte charAR[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B10000 };
const byte charAS[] PROGMEM = { B00001, B00001, B00001, B00001, B00001, B00001, B00001, B00001 };
const byte charAT[] PROGMEM = { B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
const byte charAU[] PROGMEM = { B00001, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charAV[] PROGMEM = { B10000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
 
// IMAGEM 7
const byte charAW[] PROGMEM = { B00001, B00001, B00001, B00001, B00001, B00001, B00001, B00001 };
const byte charAX[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011 };
const byte charAY[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B10000, B11000 };
const byte charAZ[] PROGMEM = { B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
const byte charBA[] PROGMEM = { B00001, B00001, B00001, B00001, B00001, B00001, B00001, B00001 };
const byte charBB[] PROGMEM = { B00011, B00001, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charBC[] PROGMEM = { B11000, B10000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charBD[] PROGMEM = { B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
 
// IMAGEM 8
const byte charBE[] PROGMEM = { B00011, B00011, B00011, B00011, B00011, B00011, B00011, B00011 };
const byte charBF[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011 };
const byte charBG[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B01100, B10100, B11000 };
const byte charBH[] PROGMEM = { B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000 };
const byte charBI[] PROGMEM = { B00011, B00011, B00011, B00011, B00011, B00011, B00011, B00011 };
const byte charBJ[] PROGMEM = { B00011, B00101, B00110, B00000, B00000, B00000, B00000, B00000 };
const byte charBK[] PROGMEM = { B11000, B10000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charBL[] PROGMEM = { B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000 };
 
// IMAGEM 9
const byte charBM[] PROGMEM = { B00010, B00110, B00100, B00100, B00110, B00010, B00110, B00100 };
const byte charBN[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011 };
const byte charBO[] PROGMEM = { B00000, B00000, B00000, B00000, B00110, B01010, B10100, B11000 };
const byte charBP[] PROGMEM = { B10000, B10000, B11000, B01000, B11000, B10000, B10000, B11000 };
const byte charBQ[] PROGMEM = { B00010, B00010, B00110, B00100, B00110, B00010, B00110, B00100 };
const byte charBR[] PROGMEM = { B00011, B00101, B01010, B01100, B00000, B00000, B00000, B00000 };
const byte charBS[] PROGMEM = { B11000, B10000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charBT[] PROGMEM = { B01000, B11000, B10000, B11000, B01000, B01000, B11000, B10000 };
 
// IMAGEM 10
const byte charBU[] PROGMEM = { B00100, B00100, B01000, B01000, B01000, B00100, B01000, B01000 };
const byte charBV[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00011 };
const byte charBW[] PROGMEM = { B00000, B00000, B00000, B00000, B00111, B01001, B10010, B11000 };
const byte charBX[] PROGMEM = { B00100, B00100, B00100, B00010, B00010, B00100, B00100, B00010 };
const byte charBY[] PROGMEM = { B00100, B00100, B01000, B01000, B00100, B00100, B00100, B01000 };
const byte charBZ[] PROGMEM = { B00011, B00101, B01000, B01010, B01100, B00000, B00000, B00000 };
const byte charCA[] PROGMEM = { B11000, B10000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charCB[] PROGMEM = { B00010, B00010, B00100, B00010, B00010, B00010, B00100, B00100 };
 
// IMAGEM 11
const byte charCC[] PROGMEM = { B00000, B01000, B00000, B10000, B10000, B01000, B10000, B00000 };
const byte charCD[] PROGMEM = { B00000, B00000, B00000, B00100, B00000, B00000, B00001, B00011 };
const byte charCE[] PROGMEM = { B00000, B00000, B00000, B00000, B00111, B01001, B10010, B11000 };
const byte charCF[] PROGMEM = { B00000, B00010, B00010, B00000, B00001, B00010, B00000, B00001 };
const byte charCG[] PROGMEM = { B01000, B00000, B10000, B10000, B01000, B00000, B01000, B00000 };
const byte charCH[] PROGMEM = { B00011, B00101, B01000, B01010, B01100, B00000, B00000, B00000 };
const byte charCI[] PROGMEM = { B11000, B10000, B00000, B00000, B00100, B00000, B00000, B00000 };
const byte charCJ[] PROGMEM = { B00000, B00001, B00000, B00001, B00001, B00000, B00000, B00010 };
 
// IMAGEM 12
const byte charCK[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charCL[] PROGMEM = { B00000, B00000, B00100, B01110, B00100, B00000, B00001, B00011 };
const byte charCM[] PROGMEM = { B00000, B00000, B00000, B00000, B00111, B01001, B10010, B11000 };
const byte charCN[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charCO[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
const byte charCP[] PROGMEM = { B00011, B00101, B01000, B01010, B01100, B00000, B00000, B00000 };
const byte charCQ[] PROGMEM = { B11000, B10000, B00000, B00000, B01110, B00000, B00000, B00000 };
const byte charCR[] PROGMEM = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
 
// =====================================================
// LIMITES E CONFIGURAÇÕES INICIAIS
// =====================================================
 
float tempMin = 18.0;
float tempMax = 28.0;
float umidMin = 30.0;
float umidMax = 50.0;
float luzMin = 0.0;
float luzMax = 30.0;
 
byte idioma = 0;       // 0 = Português, 1 = English
byte unidadeTemp = 0;  // 0 = Celsius, 1 = Fahrenheit
 
// =====================================================
// EEPROM - MAPA DE MEMÓRIA (LOG DE INICIALIZAÇÕES)
// =====================================================
 
const int EEPROM_POINTER = 50;
const int RECORD_SIZE = 10;
const int START_ADDRESS = 52;
const int MAX_RECORDS = 10;
const int END_ADDRESS = START_ADDRESS + (MAX_RECORDS * RECORD_SIZE);
 
int currentAddress = START_ADDRESS;
 
// =====================================================
// VARIÁVEIS DOS SENSORES E CONTROLES
// =====================================================
 
float temperatura = 0.0;
float umidade = 0.0;
float luminosidade = 0.0;
int valorLDR = 0;
 
bool alertaGeral = false;
bool alertaTemperatura = false;
bool alertaUmidade = false;
bool alertaLuminosidade = false;
 
unsigned long ultimaLeitura = 0;
const unsigned long INTERVALO_LEITURA = 3000;
 
unsigned long ultimoSalvamento = 0;
const unsigned long INTERVALO_SALVAMENTO = 60000;
 
int telaAtual = 0;
 
bool estadoAnteriorCima = HIGH;
bool estadoAnteriorBaixo = HIGH;
bool estadoAnteriorEnter = HIGH;
 
// Modos Especiais
bool emConfiguracao = false;
int passoConfig = 0;
int cfgDia, cfgMes, cfgAno, cfgHora, cfgMin;
bool manterConfigs = true;
 
bool emHistorico = false;
int indiceHistorico = 0;
 
// =====================================================
// FUNÇÕES AUXILIARES
// =====================================================
 
const char* tr(const char* pt, const char* en) {
  return (idioma == 0) ? pt : en;
}
 
float getTempAtual() {
  if (unidadeTemp == 1) return (temperatura * 1.8) + 32.0;
  return temperatura;
}
 
char getUnidadeChar() {
  return (unidadeTemp == 0) ? 'C' : 'F';
}
 
// =====================================================
// FUNÇÕES DE EXIBIÇÃO DA LOGO
// =====================================================
 
void criarCharProgmem(byte num, const byte* mapa) {
  byte buffer[8];
  for (int i = 0; i < 8; i++) {
    buffer[i] = pgm_read_byte_near(mapa + i);
  }
  lcd.createChar(num, buffer);
}
 
void imagem1() {
  criarCharProgmem(0, charA); criarCharProgmem(1, charB);
  criarCharProgmem(2, charC); criarCharProgmem(3, charD);
  criarCharProgmem(4, charE); criarCharProgmem(5, charF);
  criarCharProgmem(6, charG); criarCharProgmem(7, charH);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("     *"));
  lcd.write(0); lcd.write(1); lcd.write(2); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("      "));
  lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
  lcd.print(F("*"));
}
 
void imagem2() {
  criarCharProgmem(0, charI); criarCharProgmem(1, charJ);
  criarCharProgmem(2, charK); criarCharProgmem(3, charL);
  criarCharProgmem(4, charM); criarCharProgmem(5, charN);
  criarCharProgmem(6, charO); criarCharProgmem(7, charP);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("      "));
  lcd.write(0); lcd.write(1); lcd.write(2); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("      "));
  lcd.write(4); lcd.write(5); lcd.write(6); lcd.write(7);
}
 
void imagem3() {
  criarCharProgmem(0, charQ); criarCharProgmem(1, charR);
  criarCharProgmem(2, charS); criarCharProgmem(3, charT);
  criarCharProgmem(4, charU); criarCharProgmem(5, charV);
  criarCharProgmem(6, charW); criarCharProgmem(7, charX);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("      "));
  lcd.write(0); lcd.write(1); lcd.print(F(" ")); lcd.write(2); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("     "));
  lcd.write(4); lcd.write(5); lcd.print(F(" ")); lcd.write(6); lcd.write(7);
}
 
void imagem4() {
  criarCharProgmem(0, charY); criarCharProgmem(1, charZ);
  criarCharProgmem(2, charAA); criarCharProgmem(3, charAB);
  criarCharProgmem(4, charAC); criarCharProgmem(5, charAD);
  criarCharProgmem(6, charAF); criarCharProgmem(7, charAG);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("     "));
  lcd.write(0); lcd.write(1); lcd.print(F("  ")); lcd.write(2); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("     "));
  lcd.write(4); lcd.write(5); lcd.print(F("  ")); lcd.write(6); lcd.write(7);
}
 
void imagem5() {
  criarCharProgmem(0, charAH); criarCharProgmem(1, charAI);
  criarCharProgmem(2, charAJ); criarCharProgmem(3, charAK);
  criarCharProgmem(4, charAL); criarCharProgmem(5, charAM);
  criarCharProgmem(6, charAN); criarCharProgmem(7, charAO);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("     "));
  lcd.write(0); lcd.write(1); lcd.print(F("  ")); lcd.write(2); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("     "));
  lcd.write(4); lcd.write(5); lcd.print(F("   ")); lcd.write(6); lcd.write(7);
}
 
void imagem6() {
  criarCharProgmem(0, charAP); criarCharProgmem(1, charAQ);
  criarCharProgmem(2, charAR); criarCharProgmem(3, charAS);
  criarCharProgmem(4, charAT); criarCharProgmem(5, charAU);
  criarCharProgmem(6, charAV); criarCharProgmem(7, charAW);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("     "));
  lcd.write(0); lcd.print(F(" ")); lcd.write(1); lcd.write(2); lcd.print(F(" ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("     "));
  lcd.write(4); lcd.print(F(" ")); lcd.write(5); lcd.write(6); lcd.print(F(" ")); lcd.write(7);
}
 
void imagem7() {
  criarCharProgmem(0, charAW); criarCharProgmem(1, charAX);
  criarCharProgmem(2, charAY); criarCharProgmem(3, charAZ);
  criarCharProgmem(4, charBA); criarCharProgmem(5, charBB);
  criarCharProgmem(6, charBC); criarCharProgmem(7, charBD);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void imagem8() {
  criarCharProgmem(0, charBE); criarCharProgmem(1, charBF);
  criarCharProgmem(2, charBG); criarCharProgmem(3, charBH);
  criarCharProgmem(4, charBI); criarCharProgmem(5, charBJ);
  criarCharProgmem(6, charBK); criarCharProgmem(7, charBL);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void imagem9() {
  criarCharProgmem(0, charBM); criarCharProgmem(1, charBN);
  criarCharProgmem(2, charBO); criarCharProgmem(3, charBP);
  criarCharProgmem(4, charBQ); criarCharProgmem(5, charBR);
  criarCharProgmem(6, charBS); criarCharProgmem(7, charBT);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void imagem10() {
  criarCharProgmem(0, charBU); criarCharProgmem(1, charBV);
  criarCharProgmem(2, charBW); criarCharProgmem(3, charBX);
  criarCharProgmem(4, charBY); criarCharProgmem(5, charBZ);
  criarCharProgmem(6, charCA); criarCharProgmem(7, charCB);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void imagem11() {
  criarCharProgmem(0, charCC); criarCharProgmem(1, charCD);
  criarCharProgmem(2, charCE); criarCharProgmem(3, charCF);
  criarCharProgmem(4, charCG); criarCharProgmem(5, charCH);
  criarCharProgmem(6, charCI); criarCharProgmem(7, charCJ);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void imagem12() {
  criarCharProgmem(0, charCK); criarCharProgmem(1, charCL);
  criarCharProgmem(2, charCM); criarCharProgmem(3, charCN);
  criarCharProgmem(4, charCO); criarCharProgmem(5, charCP);
  criarCharProgmem(6, charCQ); criarCharProgmem(7, charCR);
 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print(F("    "));
  lcd.write(0); lcd.print(F("  ")); lcd.write(1); lcd.write(2); lcd.print(F("  ")); lcd.write(3);
 
  lcd.setCursor(0, 1); lcd.print(F("    "));
  lcd.write(4); lcd.print(F("  ")); lcd.write(5); lcd.write(6); lcd.print(F("  ")); lcd.write(7);
}
 
void exibirLogoAnima() {
  imagem1(); delay(3500);
  imagem2(); delay(250);
  imagem3(); delay(250);
  imagem4(); delay(250);
  imagem5(); delay(250);
  imagem6(); delay(250);
  imagem7(); delay(250);
  imagem8(); delay(250);
  imagem9(); delay(250);
  imagem10(); delay(250);
  imagem11(); delay(250);
  imagem12(); delay(3500);
}
 
// =====================================================
// SETUP
// =====================================================
 
void setup()
{
  Serial.begin(9600);
  dht.begin();
  Wire.begin();
  lcd.init();
  lcd.backlight();
 
  // EXIBE LOGO INICIAL
  exibirLogoAnima();
 
  if (!RTC.begin()) {
    lcd.clear(); lcd.print("ERRO NO RTC");
    while (true);
  }
  if (!RTC.isrunning()) {
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
 
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BOTAO_CIMA, INPUT_PULLUP);
  pinMode(BOTAO_BAIXO, INPUT_PULLUP);
  pinMode(BOTAO_ENTER, INPUT_PULLUP);
 
  // ---------------------------------------------
  // EEPROM & CONFIGS
  // ---------------------------------------------
  byte magic;
  EEPROM.get(0, magic);
 
  if (magic != 0x42) {
    salvarConfigsEEPROM();
    magic = 0x42;
    EEPROM.put(0, magic);
    currentAddress = START_ADDRESS;
    EEPROM.put(EEPROM_POINTER, currentAddress);
  } else {
    EEPROM.get(1, idioma); EEPROM.get(2, unidadeTemp);
    EEPROM.get(3, tempMin); EEPROM.get(7, tempMax);
    EEPROM.get(11, umidMin); EEPROM.get(15, umidMax);
    EEPROM.get(19, luzMin); EEPROM.get(23, luzMax);
   
    EEPROM.get(EEPROM_POINTER, currentAddress);
    if (currentAddress < START_ADDRESS || currentAddress >= END_ADDRESS) {
      currentAddress = START_ADDRESS;
    }
  }
 
  // ---------------------------------------------
  // LÓGICA DE NOVA SESSÃO (NOVA INICIALIZAÇÃO)
  // ---------------------------------------------
  lerSensores();
  verificarTriggers();
 
  DateTime agora = RTC.now();
 
  if (magic == 0x42) {
    currentAddress += RECORD_SIZE;
    if (currentAddress >= END_ADDRESS) currentAddress = START_ADDRESS;
    EEPROM.put(EEPROM_POINTER, currentAddress);
  }
 
  EEPROM.put(currentAddress, agora.unixtime());
  salvarDadosSessaoAtual();
 
  // INICIA O PROCESSO DE PERGUNTAS DE BOOT
  iniciarConfiguracao();
}
 
// =====================================================
// LOOP PRINCIPAL
// =====================================================
 
void loop()
{
  if (emConfiguracao) {
    verificarBotoesConfiguracao();
  }
  else if (emHistorico) {
    verificarBotoesHistorico();
  }
  else {
    unsigned long tempoAtual = millis();
 
    if (tempoAtual - ultimaLeitura >= INTERVALO_LEITURA) {
      ultimaLeitura = tempoAtual;
      lerSensores();
      verificarTriggers();
     
      if (SERIAL_OPTION) enviarSerial();
      mostrarTela();
    }
   
    if (tempoAtual - ultimoSalvamento >= INTERVALO_SALVAMENTO) {
      ultimoSalvamento = tempoAtual;
      salvarDadosSessaoAtual();
    }
   
    verificarBotoes();
  }
}
 
// =====================================================
// FUNÇÕES DE LOG E SESSÃO
// =====================================================
 
void salvarDadosSessaoAtual() {
  int16_t tempInt = (int16_t)(getTempAtual() * 10);
  int16_t humiInt = (int16_t)(umidade * 10);
  uint8_t luzInt = (uint8_t)luminosidade;
  uint8_t status = alertaGeral ? 1 : 0;
 
  EEPROM.put(currentAddress + 4, tempInt);
  EEPROM.put(currentAddress + 6, humiInt);
  EEPROM.put(currentAddress + 8, luzInt);
  EEPROM.put(currentAddress + 9, status);
}
 
void salvarConfigsEEPROM() {
  EEPROM.put(1, idioma); EEPROM.put(2, unidadeTemp);
  EEPROM.put(3, tempMin); EEPROM.put(7, tempMax);
  EEPROM.put(11, umidMin); EEPROM.put(15, umidMax);
  EEPROM.put(19, luzMin); EEPROM.put(23, luzMax);
}
 
void lerSensores() {
  float novaTemp = dht.readTemperature();
  float novaUmid = dht.readHumidity();
  if (!isnan(novaTemp) && !isnan(novaUmid)) {
    temperatura = novaTemp;
    umidade = novaUmid;
  }
  valorLDR = analogRead(LDR_PIN);
  luminosidade = (valorLDR / 1023.0) * 100.0;
}
 
void verificarTriggers() {
  float t = getTempAtual();
  alertaTemperatura = (t <= tempMin || t >= tempMax);
  alertaUmidade = (umidade <= umidMin || umidade >= umidMax);
  alertaLuminosidade = (luminosidade <= luzMin || luminosidade >= luzMax);
  alertaGeral = alertaTemperatura || alertaUmidade || alertaLuminosidade;
 
  if (alertaGeral) {
    digitalWrite(LED_VERDE, LOW); digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER, 1000, 300);
  } else {
    digitalWrite(LED_VERDE, HIGH); digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
  }
}
 
// =====================================================
// TELAS E INTERFACE
// =====================================================
 
void mostrarTela() {
  lcd.clear();
  if (telaAtual == 0) {
    DateTime agora = RTC.now();
    lcd.setCursor(0, 0); lcd.print(tr("DATA: ", "DATE: "));
    if (agora.day() < 10) lcd.print("0"); lcd.print(agora.day()); lcd.print("/");
    if (agora.month() < 10) lcd.print("0"); lcd.print(agora.month()); lcd.print("/");
    lcd.print(agora.year());
    lcd.setCursor(0, 1); lcd.print(tr("HORA: ", "TIME: "));
    if (agora.hour() < 10) lcd.print("0"); lcd.print(agora.hour()); lcd.print(":");
    if (agora.minute() < 10) lcd.print("0"); lcd.print(agora.minute());
  }
  else if (telaAtual == 1) {
    lcd.setCursor(0, 0); lcd.print("T:"); lcd.print(getTempAtual(), 1); lcd.print(getUnidadeChar()); lcd.print(" ");
    lcd.print("U:"); lcd.print(umidade, 0); lcd.print("%");
    lcd.setCursor(0, 1); lcd.print("L:"); lcd.print(luminosidade, 0); lcd.print("%");
  }
  else if (telaAtual == 2) {
    lcd.setCursor(0, 0); lcd.print(tr("STATUS:", "STATUS:"));
    lcd.print(alertaGeral ? tr(" ALERTA", " ALERT") : tr(" NORMAL", " NORMAL"));
 
    lcd.setCursor(0, 1);
    if (!alertaGeral) lcd.print(tr("Tudo dentro OK", "All bounds OK"));
    else if (alertaTemperatura && !alertaUmidade && !alertaLuminosidade) lcd.print(tr("Temp fora de faixa", "Temp out bounds"));
    else if (alertaUmidade && !alertaTemperatura && !alertaLuminosidade) lcd.print(tr("Umid fora de faixa", "Hum out bounds"));
    else if (alertaLuminosidade && !alertaTemperatura && !alertaUmidade) lcd.print(tr("Luz fora de faixa", "Light out bounds"));
    else if (alertaTemperatura && alertaUmidade && !alertaLuminosidade) lcd.print(tr("Temp e Umid fora de faixa", "Temp and Hum out bounds"));
    else if (alertaTemperatura && alertaLuminosidade && !alertaUmidade) lcd.print(tr("Temp e Luz fora faixa", "Temp and Light out bounds"));
    else if (alertaUmidade && alertaLuminosidade && !alertaTemperatura) lcd.print(tr("Umid e Luz fora de faixa", "Hum and Light out bounds"));
    else if (alertaUmidade && alertaLuminosidade && alertaTemperatura) lcd.print(tr("Todos fora de faixa", "Everything out bounds"));
  }
  else if (telaAtual == 3) {
    lcd.setCursor(0, 0);
    lcd.print(tr("PARAMETROS", "PARAMETERS"));
    lcd.setCursor(0, 1);
    lcd.print(tempMin, 1); lcd.print(getUnidadeChar());
    lcd.print(" < T < ");
    lcd.print(tempMax, 1); lcd.print(getUnidadeChar());
  }
  else if (telaAtual == 4) {
    lcd.setCursor(0, 0);
    lcd.print(umidMin, 0); lcd.print("% < U < "); lcd.print(umidMax, 0); lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print(luzMin, 0); lcd.print("% < L < "); lcd.print(luzMax, 0); lcd.print("%");
  }
  else if (telaAtual == 5) {
    lcd.setCursor(0, 0); lcd.print(tr("CONFIGURACOES", "SETTINGS MENU"));
    lcd.setCursor(0, 1); lcd.print(tr("Aperte ENTER", "Press ENTER"));
  }
  else if (telaAtual == 6) {
    lcd.setCursor(0, 0); lcd.print(tr("VER HISTORICO", "VIEW HISTORY"));
    lcd.setCursor(0, 1); lcd.print(tr("Aperte ENTER", "Press ENTER"));
  }
}
 
void verificarBotoes() {
  bool cCima = digitalRead(BOTAO_CIMA);
  bool cBaixo = digitalRead(BOTAO_BAIXO);
  bool cEnter = digitalRead(BOTAO_ENTER);
 
  if (cCima == LOW && estadoAnteriorCima == HIGH) {
    telaAtual++;
    if (telaAtual > 6) telaAtual = 0;
    mostrarTela(); delay(200);
  }
  if (cBaixo == LOW && estadoAnteriorBaixo == HIGH) {
    telaAtual--;
    if (telaAtual < 0) telaAtual = 6;
    mostrarTela(); delay(200);
  }
  if (cEnter == LOW && estadoAnteriorEnter == HIGH) {
    if (telaAtual == 5) iniciarConfiguracao();
    else if (telaAtual == 6) iniciarHistorico();
    else mostrarStatus();
    delay(200);
  }
  estadoAnteriorCima = cCima; estadoAnteriorBaixo = cBaixo; estadoAnteriorEnter = cEnter;
}
 
// =====================================================
// NAVEGAÇÃO DE HISTÓRICO
// =====================================================
 
void iniciarHistorico() {
  emHistorico = true;
  indiceHistorico = 0;
  mostrarRegistroHistorico();
}
 
void verificarBotoesHistorico() {
  bool cCima = digitalRead(BOTAO_CIMA);
  bool cBaixo = digitalRead(BOTAO_BAIXO);
  bool cEnter = digitalRead(BOTAO_ENTER);
 
  if (cCima == LOW && estadoAnteriorCima == HIGH) {
    indiceHistorico--;
    if (indiceHistorico < 0) indiceHistorico = MAX_RECORDS - 1;
    mostrarRegistroHistorico(); delay(200);
  }
  if (cBaixo == LOW && estadoAnteriorBaixo == HIGH) {
    indiceHistorico++;
    if (indiceHistorico >= MAX_RECORDS) indiceHistorico = 0;
    mostrarRegistroHistorico(); delay(200);
  }
  if (cEnter == LOW && estadoAnteriorEnter == HIGH) {
    emHistorico = false;
    mostrarTela(); delay(200);
  }
  estadoAnteriorCima = cCima; estadoAnteriorBaixo = cBaixo; estadoAnteriorEnter = cEnter;
}
 
void mostrarRegistroHistorico() {
  lcd.clear();
 
  int offset = indiceHistorico * RECORD_SIZE;
  int addr = currentAddress - offset;
  if (addr < START_ADDRESS) {
    addr = END_ADDRESS - (START_ADDRESS - addr);
  }
 
  uint32_t timestamp;
  EEPROM.get(addr, timestamp);
 
  if (timestamp == 0 || timestamp == 0xFFFFFFFF) {
    lcd.setCursor(0, 0); lcd.print("Registro Vazio");
    lcd.setCursor(0, 1); lcd.print("-");
    return;
  }
 
  int16_t tempInt, humiInt;
  uint8_t luzInt;
  EEPROM.get(addr + 4, tempInt);
  EEPROM.get(addr + 6, humiInt);
  EEPROM.get(addr + 8, luzInt);
 
  DateTime dt(timestamp);
 
  lcd.setCursor(0, 0);
  if (dt.day() < 10) lcd.print("0"); lcd.print(dt.day()); lcd.print("/");
  if (dt.month() < 10) lcd.print("0"); lcd.print(dt.month()); lcd.print("/");
  lcd.print(dt.year() % 100); lcd.print(" ");
  if (dt.hour() < 10) lcd.print("0"); lcd.print(dt.hour()); lcd.print(":");
  if (dt.minute() < 10) lcd.print("0"); lcd.print(dt.minute());
 
  lcd.setCursor(0, 1);
  lcd.print("T:"); lcd.print(tempInt / 10.0, 1);
  lcd.print(" U:"); lcd.print(humiInt / 10.0, 0);
  lcd.print(" L:"); lcd.print(luzInt);
}
 
// =====================================================
// MODO DE CONFIGURAÇÃO (BOOT E MENU)
// =====================================================
 
void iniciarConfiguracao() {
  emConfiguracao = true;
  passoConfig = 1; // Passo 1: Selecionar Idioma
  manterConfigs = true;
 
  DateTime agora = RTC.now();
  cfgDia = agora.day();
  cfgMes = agora.month();
  cfgAno = agora.year();
  cfgHora = agora.hour();
  cfgMin = agora.minute();
 
  estadoAnteriorCima = digitalRead(BOTAO_CIMA);
  estadoAnteriorBaixo = digitalRead(BOTAO_BAIXO);
  estadoAnteriorEnter = digitalRead(BOTAO_ENTER);
 
  mostrarTelaConfiguracao();
}
 
void verificarBotoesConfiguracao() {
  bool cCima = digitalRead(BOTAO_CIMA);
  bool cBaixo = digitalRead(BOTAO_BAIXO);
  bool cEnter = digitalRead(BOTAO_ENTER);
 
  if (cCima == LOW && estadoAnteriorCima == HIGH) {
    alterarConfiguracao(1);
    mostrarTelaConfiguracao();
    delay(150);
  }
 
  if (cBaixo == LOW && estadoAnteriorBaixo == HIGH) {
    alterarConfiguracao(-1);
    mostrarTelaConfiguracao();
    delay(150);
  }
 
  if (cEnter == LOW && estadoAnteriorEnter == HIGH) {
    // Lógica para pular/avançar passos conforme a escolha de manter configs
    if (passoConfig == 2) {
      if (manterConfigs) {
        passoConfig = 3; // Vai direto para Data/Hora
      } else {
        passoConfig = 3; // Vai para Data/Hora e continuará até os parâmetros
      }
    } else if (passoConfig == 7 && manterConfigs) {
      // Se optou por manter configs e finalizou a Hora/Min (passo 7), encerra aqui
      finalizarConfiguracao();
      return;
    } else {
      passoConfig++;
    }
 
    if (passoConfig > 14) {
      finalizarConfiguracao();
    } else {
      mostrarTelaConfiguracao();
    }
    delay(200);
  }
 
  estadoAnteriorCima = cCima;
  estadoAnteriorBaixo = cBaixo;
  estadoAnteriorEnter = cEnter;
}
 
void alterarConfiguracao(int direcao) {
  switch (passoConfig) {
    case 1: idioma = !idioma; break;
    case 2: manterConfigs = !manterConfigs; break;
    case 3: cfgDia += direcao; if(cfgDia > 31) cfgDia=1; if(cfgDia < 1) cfgDia=31; break;
    case 4: cfgMes += direcao; if(cfgMes > 12) cfgMes=1; if(cfgMes < 1) cfgMes=12; break;
    case 5: cfgAno += direcao; if(cfgAno > 2099) cfgAno=2000; if(cfgAno < 2000) cfgAno=2099; break;
    case 6: cfgHora += direcao; if(cfgHora > 23) cfgHora=0; if(cfgHora < 0) cfgHora=23; break;
    case 7: cfgMin += direcao; if(cfgMin > 59) cfgMin=0; if(cfgMin < 0) cfgMin=59; break;
    case 8: unidadeTemp = !unidadeTemp; break;
    case 9: tempMin += direcao * 0.5; break;
    case 10: tempMax += direcao * 0.5; break;
    case 11: umidMin += direcao * 1.0; break;
    case 12: umidMax += direcao * 1.0; break;
    case 13: luzMin += direcao * 1.0; break;
    case 14: luzMax += direcao * 1.0; break;
  }
}
 
void mostrarTelaConfiguracao() {
  lcd.clear();
  lcd.setCursor(0, 0);
 
  switch (passoConfig) {
    case 1: lcd.print(tr("1. Idioma:", "1. Language:")); lcd.setCursor(0, 1); lcd.print(idioma == 0 ? "Portugues" : "English"); break;
    case 2: lcd.print(tr("Manter Configs?", "Keep Settings?")); lcd.setCursor(0, 1); lcd.print(manterConfigs ? tr("SIM", "YES") : tr("NAO", "NO")); break;
    case 3: lcd.print(tr("Data (Dia):", "Date (Day):")); lcd.setCursor(0, 1); lcd.print(cfgDia); break;
    case 4: lcd.print(tr("Data (Mes):", "Date (Month):")); lcd.setCursor(0, 1); lcd.print(cfgMes); break;
    case 5: lcd.print(tr("Data (Ano):", "Date (Year):")); lcd.setCursor(0, 1); lcd.print(cfgAno); break;
    case 6: lcd.print(tr("Hora (Hora):", "Time (Hour):")); lcd.setCursor(0, 1); lcd.print(cfgHora); break;
    case 7: lcd.print(tr("Hora (Min):", "Time (Min):")); lcd.setCursor(0, 1); lcd.print(cfgMin); break;
    case 8: lcd.print(tr("Unidade Temp:", "Temp Unit:")); lcd.setCursor(0, 1); lcd.print(unidadeTemp == 0 ? "Celsius (C)" : "Fahrenheit (F)"); break;
    case 9: lcd.print("Temp Min:"); lcd.setCursor(0, 1); lcd.print(tempMin, 1); lcd.print(getUnidadeChar()); break;
    case 10: lcd.print("Temp Max:"); lcd.setCursor(0, 1); lcd.print(tempMax, 1); lcd.print(getUnidadeChar()); break;
    case 11: lcd.print("Umid Min:"); lcd.setCursor(0, 1); lcd.print(umidMin, 0); lcd.print("%"); break;
    case 12: lcd.print("Umid Max:"); lcd.setCursor(0, 1); lcd.print(umidMax, 0); lcd.print("%"); break;
    case 13: lcd.print("Luz Min:"); lcd.setCursor(0, 1); lcd.print(luzMin, 0); lcd.print("%"); break;
    case 14: lcd.print("Luz Max:"); lcd.setCursor(0, 1); lcd.print(luzMax, 0); lcd.print("%"); break;
  }
}
 
void finalizarConfiguracao() {
  emConfiguracao = false;
 
  RTC.adjust(DateTime(cfgAno, cfgMes, cfgDia, cfgHora, cfgMin, 0));
  salvarConfigsEEPROM();
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(tr("SALVO!", "SAVED!"));
  delay(1000);
 
  telaAtual = 0;
  mostrarTela();
}
 
void mostrarStatus() {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (alertaGeral) {
    lcd.print("!!! ALERTA !!!");
    tone(BUZZER, 1500, 500);
  } else {
    lcd.print(tr("SISTEMA NORMAL", "SYSTEM NORMAL"));
  }
  delay(1500);
  mostrarTela();
}
 
// =====================================================
// COMUNICAÇÃO SERIAL
// =====================================================
 
void enviarSerial() {
  DateTime agora = RTC.now();
  Serial.println("==============================");
  Serial.print("Data/Hora: "); Serial.print(agora.day()); Serial.print("/"); Serial.print(agora.month());
  Serial.print("/"); Serial.print(agora.year()); Serial.print(" "); Serial.print(agora.hour());
  Serial.print(":"); Serial.println(agora.minute());
 
  Serial.print("Temp: "); Serial.print(getTempAtual()); Serial.println(getUnidadeChar());
  Serial.print("Umid: "); Serial.print(umidade); Serial.println(" %");
  Serial.print("Luz:  "); Serial.print(luminosidade); Serial.println(" %");
  Serial.print("Status: "); Serial.println(alertaGeral ? "ALERTA" : "NORMAL");
  Serial.println("==============================");
}
 