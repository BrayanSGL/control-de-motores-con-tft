#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "stdio.h"
#include "string"
#include "Arial28x28.h"
#include "Arial12x12.h"
#include "UTouch.h"
//#include "platform/mbed_thread.h"

//#define BLINKING_RATE_MS 15

using namespace std;

extern SPI_TFT_ILI9341 TFT;
extern UTouch myTouch;
extern float x, y;
extern unsigned char flecha[];

static int teclaPrecionada = 0;

int botonesPaso(float x, float y);
void pantallaPrincipal();

BusOut motor_p(PA_12, PA_11, PB_12, PB_11);
const char pasos[4]{0x9, 0xc, 0x6, 0x3};
int i = 0, cantPasos = 0;

void pantallaPaso()
{
    bool isRunning = true;
    std::string textoIngresado;
    //    char textoIngresado[10] = "";
    int contador = 0, MAX = 13;

    TFT.background(Red);
    TFT.set_font((unsigned char *)Arial28x28);
    //Dibibujo del cuadrado
    TFT.fillrect(0, 0, 240, 320, Red);
    TFT.fillrect(161, 269, 238, 318, Black);
    TFT.Bitmap(174, 269, 50, 50, flecha);
    TFT.rect(2, 2, 238, 102, White);
    TFT.rect(3, 3, 237, 101, White);
    TFT.rect(2, 106, 238, 319, White);
    TFT.locate(10, 5);
    printf("PASO A PASO");
    TFT.line(2, 30, 238, 30, White);
    TFT.locate(10, 38);
    TFT.set_font((unsigned char *)Arial12x12);
    printf("NUMERO DE PASOS:");
    //Lineas
    TFT.line(80, 106, 80, 319, White);
    TFT.line(160, 106, 160, 319, White);
    TFT.line(240, 106, 240, 319, White);

    TFT.line(2, 160, 238, 160, White);
    TFT.line(2, 214, 238, 214, White);
    TFT.line(2, 268, 238, 268, White);
    //Los números
    TFT.set_font((unsigned char *)Arial28x28);
    TFT.locate(30, 120);
    printf("1");
    TFT.locate(110, 120);
    printf("2");
    TFT.locate(190, 120);
    printf("3");

    TFT.locate(30, 174);
    printf("4");
    TFT.locate(110, 174);
    printf("5");
    TFT.locate(190, 174);
    printf("6");

    TFT.locate(30, 228);
    printf("7");
    TFT.locate(110, 228);
    printf("8");
    TFT.locate(190, 228);
    printf("9");

    TFT.locate(30, 282);
    printf(">");
    TFT.locate(110, 282);
    printf("0");

    while (isRunning)
    {

        if (myTouch.DataAvailable() && myTouch.Read())
        {

            x = myTouch.GetX(); // toma x del touch
            y = myTouch.GetY(); // toma y del touch

            TFT.locate(5, 60);

            teclaPrecionada = botonesPaso(x, y);

            if (teclaPrecionada == 42)
            {
                for (int j = 0; j < cantPasos; j++)
                {
                    motor_p = pasos[i];
                    i++;
                    if (i == 4)
                        i = 0;
                    wait(0.015);
                    //thread_sleep_for(BLINKING_RATE_MS);
                }
            }
            else if (teclaPrecionada == 35)
            {
                isRunning = false;
                pantallaPrincipal();
            }
            else if (teclaPrecionada == 219 && textoIngresado.size() > 1)
            {
                textoIngresado = textoIngresado.substr(0, textoIngresado.size() - 1);
                char char_array[textoIngresado.length() + 1];
                strcpy(char_array, textoIngresado.c_str());
                //TFT.printf("%d",teclaPrecionada);
                TFT.fillrect(5, 60, 235, 89, Red);
                TFT.printf(char_array);
                wait(0.5);
            }
            else if (textoIngresado.length() < 13 && teclaPrecionada != 219)
            {
                textoIngresado += std::to_string(teclaPrecionada);
                char char_array[textoIngresado.length() + 1];
                strcpy(char_array, textoIngresado.c_str());
                TFT.printf(char_array);
                wait(0.3);
            }
            cantPasos = stoi(textoIngresado);
            //TFT.locate(5,60);
            //TFT.printf("%d", cantPasos+1);
        }
    }
}

int botonesPaso(float x, float y)
{
    int a = 0;
    /////////////1
    if (y > 66 && x > 44 && y < 100 && x < 69)
    {
        return 1;
    }
    /////////////2
    if (y > 33 && x > 44 && y < 66 && x < 69)
    {
        return 2;
    }
    /////////////3
    if (y > 0 && x > 44 && y < 33 && x < 69)
    {
        return 3;
    }
    /////////////4
    if (y > 66 && x > 69 && y < 100 && x < 94)
    {
        return 4;
    }
    /////////////5
    if (y > 33 && x > 69 && y < 66 && x < 94)
    {
        return 5;
    }
    /////////////6
    if (y > 0 && x > 69 && y < 33 && x < 94)
    {
        return 6;
    }

    /////////////7
    if (y > 66 && x > 94 && y < 100 && x < 119)
    {
        return 7;
    }

    /////////////8
    if (y > 33 && x > 94 && y < 66 && x < 119)
    {
        return 8;
    }

    /////////////9
    if (y > 0 && x > 94 && y < 33 && x < 119)
    {
        return 9;
    }

    /////////////*
    if (y > 66 && x > 119 && y < 100 && x < 144)
    {
        return 42;
    }

    /////////////0
    if (y > 33 && x > 119 && y < 66 && x < 144)
    {
        return 0;
    }
    /////////////#
    if (y > 0 && x > 119 && y < 33 && x < 144)
    {
        return 35;
    }
    return 219;
}