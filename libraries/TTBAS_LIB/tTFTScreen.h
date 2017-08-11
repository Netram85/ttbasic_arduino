#ifndef __tTFTScreen_h__
#define __tTFTScreen_h__

#include <Arduino.h>
#include "tscreenBase.h"
#include <Adafruit_GFX_AS.h>      // Core graphics library, with extra fonts.
#include <Adafruit_ILI9341_STM.h> // STM32 DMA Hardware-specific library

class tTFTScreen : public tscreenBase {
 private:
  Adafruit_ILI9341_STM* tft;
  uint8_t* tftfont;    // 利用フォント
  uint16_t f_width;    // フォント幅(ドット)
  uint16_t f_height;   // フォント高さ(ドット)
  uint16_t g_width;    // 画面横ドット数(ドット)
  uint16_t g_height;   // 画面縦ドット数(ドット)
  uint16_t fgcolor;
  uint16_t bgcolor;

 protected:
    void INIT_DEV();                             // デバイスの初期化
    void MOVE(uint8_t y, uint8_t x);             // キャラクタカーソル移動
    void WRITE(uint8_t x, uint8_t y, uint8_t c); // 文字の表示
    void CLEAR();                                // 画面全消去
    void CLEAR_LINE(uint8_t l);                  // 行の消去
    void SCROLL_UP();                            // スクロールアップ
    void SCROLL_DOWN();                          // スクロールダウン
    void INSLINE(uint8_t l);                     // 指定行に1行挿入(下スクロール)
    void scrollFrame(uint16_t vsp);              // 指定利用のスクロール
    void drawBitmap_x2(int16_t x, int16_t y,
           const uint8_t *bitmap, int16_t w, int16_t h,
           uint16_t color);

  public:
    inline uint8_t IS_PRINT(uint8_t ch) { return (ch); };
    void beep(){};                               // BEEP音の発生
    void show_curs(uint8_t flg);                 // カーソルの表示/非表示
    void draw_cls_curs();                        // カーソルの消去
    void setColor(uint16_t fc, uint16_t bc);     // 文字色指定
    void setAttr(uint16_t attr);                 // 文字属性
    uint8_t get_ch();                            // 文字の取得
    uint8_t isKeyIn();                           // キー入力チェック
    int16_t peek_ch();                           // キー入力チェック(文字参照)

    uint8_t drawCurs(uint8_t x, uint8_t y);      // カーソル表示
};

#endif