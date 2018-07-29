#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// コンパイル時にヘッダーファイルが適切に編集されていない場合に
// "Height incorrect, please fix Adafruit_SSD1306.h!"
// というエラーを表示するための記述
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// RSTピンがない互換品を使用するので-1を指定
Adafruit_SSD1306 display(-1);

int x, minX;
char message1[] = "Utada Hikaru : Can You Keep A Secret?";

void setup() {
  // I2Cアドレスは使用するディスプレイに合わせて変更する
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  x = display.width();
  minX = -12 * strlen(message1);

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setTextWrap(false);
}

void loop() {
  display.clearDisplay();
  display.setCursor(x, 20);
  display.print(message1);
  display.display();

  x -= 5;

  if(x < minX) x = display.width();

}
