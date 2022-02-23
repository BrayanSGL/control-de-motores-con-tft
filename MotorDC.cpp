#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial24x23.h"
#include "Arial28x28.h"
#include "UTouch.h"
#include "stdio.h"

extern SPI_TFT_ILI9341 TFT;
extern UTouch myTouch;
extern float x, y;
extern unsigned char flecha[];

static float teclaPrecionada = 0;

float scrollDC(float x);
void pantallaPrincipal();

DigitalOut In1(PC_6);
DigitalOut In2(PC_5);
PwmOut velocidad(PC_8);

void pantallaDC()
{
    //velocidad.period_ms(20);
    bool isRunning = true;
    int a = 0;
    TFT.background(Red);
    TFT.set_font((unsigned char *)Arial28x28);
    TFT.fillrect(0, 0, 240, 320, Red);
    TFT.rect(5, 5, 235, 315, Black);
    TFT.locate(33, 20);
    printf("MOTOR DC");
    //Scroll
    TFT.fillrect(20, 68, 50, 300, Black);
    TFT.rect(20, 68, 50, 300, White);
    TFT.line(53, 184, 83, 184, White);
    TFT.line(53, 68, 83, 68, White);
    TFT.line(53, 300, 83, 300, White);
    TFT.line(68, 68, 68, 300, White);
    TFT.set_font((unsigned char *)Arial24x23);
    TFT.locate(86, 173);
    printf("0");
    TFT.locate(86, 57);
    printf("10");
    TFT.locate(86, 289);
    printf("-10");
    TFT.rect(169, 249, 221, 301, White);
    TFT.Bitmap(170, 250, 50, 50, flecha);
    //Cursor
    TFT.set_font((unsigned char *)Arial28x28);
    while (isRunning)
    {

        if (myTouch.DataAvailable() && myTouch.Read())
        {
            x = myTouch.GetX(); // toma x del touch
            y = myTouch.GetY(); // toma y del touch

            if (y > 91 && x > 24 && y < 100 && x < 136)
            {
                teclaPrecionada = scrollDC(x);
                TFT.locate(140, 169);
                TFT.printf("%1.0f  ", teclaPrecionada);

                if (teclaPrecionada == 0)
                {
                    In1 = 0;
                    In2 = 0;
                    velocidad.write(0);
                }
                if (teclaPrecionada > 0)
                {
                    In1 = 1;
                    In2 = 0;
                    velocidad.write(teclaPrecionada / 10);
                }
                if (teclaPrecionada < 0)
                {
                    In1 = 0;
                    In2 = 1;
                    velocidad.write(teclaPrecionada / -10);
                }
            }

            if (y > 3 && x > 115 && y < 26 && x < 138)
            {
                isRunning = false;
                In1 = 0;
                In2 = 0;
                pantallaPrincipal();
            }
        }
    }
}

float scrollDC(float x)
{
    TFT.fillrect(21, 69, 49, 299, Black);
    //////0
    if (x >= 76 && x <= 84)
    {
        TFT.fillrect(21, 178, 49, 189, Green);
        return 0;
    }
    //////1
    if (x >= 71 && x < 76)
    {
        TFT.fillrect(21, 167, 49, 178, Green);
        return 1;
    }
    //////2
    if (x >= 66 && x < 71)
    {
        TFT.fillrect(21, 156, 49, 167, Green);
        return 2;
    }
    //////3
    if (x >= 61 && x < 66)
    {
        TFT.fillrect(21, 145, 49, 156, Green);
        return 3;
    }
    //////4
    if (x >= 56 && x < 61)
    {
        TFT.fillrect(21, 134, 49, 145, Green);
        return 4;
    }
    //////5
    if (x >= 51 && x < 56)
    {
        TFT.fillrect(21, 123, 49, 134, Green);
        return 5;
    }
    //////6
    if (x >= 46 && x < 51)
    {
        TFT.fillrect(21, 112, 49, 123, Green);
        return 6;
    }
    //////7
    if (x >= 41 && x < 46)
    {
        TFT.fillrect(21, 101, 49, 112, Green);
        return 7;
    }
    //////8
    if (x >= 36 && x < 41)
    {
        TFT.fillrect(21, 90, 49, 101, Green);
        return 8;
    }
    //////9
    if (x >= 30 && x < 36)
    {
        TFT.fillrect(21, 79, 49, 90, Green);
        return 9;
    }
    //////10
    if (x >= 24 && x < 30)
    {
        TFT.fillrect(21, 69, 49, 79, Green);
        return 10;
    }

    //////-1
    if (x > 84 && x <= 89)
    {
        TFT.fillrect(21, 189, 49, 200, Green);
        return -1;
    }
    //////-2
    if (x > 89 && x <= 94)
    {
        TFT.fillrect(21, 200, 49, 211, Green);
        return -2;
    }
    //////-3
    if (x > 94 && x <= 99)
    {
        TFT.fillrect(21, 211, 49, 222, Green);
        return -3;
    }
    //////-4
    if (x > 99 && x <= 104)
    {
        TFT.fillrect(21, 222, 49, 233, Green);
        return -4;
    }
    //////-5
    if (x > 104 && x <= 109)
    {
        TFT.fillrect(21, 233, 49, 244, Green);
        return -5;
    }
    //////-6
    if (x > 109 && x <= 114)
    {
        TFT.fillrect(21, 244, 49, 255, Green);
        return -6;
    }
    //////-7
    if (x > 114 && x <= 119)
    {
        TFT.fillrect(21, 255, 49, 266, Green);
        return -7;
    }
    //////-8
    if (x > 119 && x <= 124)
    {
        TFT.fillrect(21, 266, 49, 277, Green);
        return -8;
    }
    //////-9
    if (x > 124 && x <= 130)
    {
        TFT.fillrect(21, 277, 49, 288, Green);
        return -9;
    }
    //////-10
    if (x > 130 && x <= 136)
    {
        TFT.fillrect(21, 288, 49, 299, Green);
        return -10;
    }
    return 0;
}