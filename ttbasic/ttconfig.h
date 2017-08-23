//
// 豊四季Tiny BASIC for Arduino STM32 構築コンフィグレーション
// 作成日 2017/06/22 たま吉さん
//
// 修正日 2017/07/29 NTSC利用有無指定の追加
// 修正日 2017/08/06 Wireライブラリ新旧対応
// 修正日 2017/08/23 設定の整合性チェック＆補正対応
//

#ifndef __ttconfig_h__
#define __ttconfig_h__

// ** TFTILI9341 SPI)液晶モジュール利用有無(まだ不完全) **********************
#define USE_TFT   0  // 0:利用しない 1:利用する (デフォルト:0)
                     // 利用時は USE_NTSC を0にすること
                     // ※ 、SDカード併用でフリーズ発生
                     
// ** NTSCビデオ出力利用有無 *************************************************
#define USE_NTSC  1  // 0:利用しない 1:利用する (デフォルト:1)

// ** デフォルトスクリーンモードの指定 0:ターミナルモード 1:NTSCビデオ 224x216
#define USE_SCREEN_MODE 1  // USE_NTSC=0の場合、0を指定すること (デフォルト:1)

// 設定の矛盾補正
#if USE_TFT  == 1
 #define USE_NTSC 0
#endif
#if USE_NTSC == 0 && USE_SCREEN_MODE == 1
 #define USE_SCREEN_MODE 0
#endif

// ** ターミナルモード時のデフォルト スクリーンサイズ  ***********************
// ※ 可動中では、WIDTHコマンドで変更可能  (デフォルト:80x25)
#define TERM_W       80
#define TERM_H       25

// ** Serial1のデフォルト通信速度 *********************************************
#define GPIO_S1_BAUD    115200 // // (デフォルト:115200)

// ** デフォルトのターミナル用シリアルポートの指定 0:USBシリアル 1:GPIO UART1
// ※ 可動中では、SMODEコマンドで変更可能
#define DEF_SMODE     0 // (デフォルト:0)

// ** 起動時にBOOT1ピン(PB2)によるシリアルターミナルモード起動選択の有無
#define FLG_CHK_BOOT1  1 // 0:なし  1:あり // (デフォルト:1)

//** Wireライブラリ新旧指定対応
#define OLD_WIRE_LIB  0 // 0:2017/08/04以降のバージョン 1:R20170323相当

// ** I2Cライブラリの選択 0:Wire(ソフトエミュレーション) 1:HWire  *************
#define I2C_USE_HWIRE  1 // (デフォルト:1)

// ** 内蔵RTCの利用指定   0:利用しない 1:利用する *****************************
#define USE_INNERRTC   1 // (デフォルト:1) ※ SDカード利用時は必ず1とする

// ** SDカードの利用      0:利用しない 1:利用する *****************************
#define USE_SD_CARD    1 // (デフォルト:1)
#define USE_SD_CARD    1 // (デフォルト:1)
#if USE_SD_CARD == 1 && USE_INNERRTC == 0
 #define USE_INNERRTC 1
#endif

// ** フォントデータ指定 ******************************************************
#define FONTSELECT  1  // 0 ～ 3 (デフォルト :1)

#if FONTSELECT == 0
  // 6x8 TVoutフォント
  #define TV_DISPLAY_FONT font6x8
  #include <font6x8.h>

#elif FONTSELECT == 1
  // 6x8ドット オリジナルフォント(デフォルト)
  #define TV_DISPLAY_FONT font6x8tt
  #include <font6x8tt.h>

#elif FONTSELECT == 2
  // 8x8 TVoutフォント
  #define TV_DISPLAY_FONT font8x8
  #include <font8x8.h>

#elif FONTSELECT == 3
  // 8x8 IchigoJamフォント(オプション機能 要フォント)
  #define TV_DISPLAY_FONT ichigoFont8x8 
  #include <ichigoFont8x8.h>
#endif

#endif
