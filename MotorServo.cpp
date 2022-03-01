#include "mbed.h"
#include "SPI_TFT_ILI9341.h"
#include "string"
#include "Arial24x23.h"
#include "Arial28x28.h"
#include "UTouch.h"
#include "stdio.h"

extern SPI_TFT_ILI9341 TFT;
extern unsigned char flecha[];
extern UTouch  myTouch;
extern float x,y;

int tortaServo(float x, float y);
void angulosVerde();
void angulosBlack();
void pantallaPrincipal();

static int teclaPrecionada = 0;

PwmOut myServo(A3);



void pantallaServo()
{
    myServo.period_ms(25);
    
    bool isRunning = true;
    TFT.background(Red);
    TFT.set_font((unsigned char*) Arial28x28);
    TFT.fillrect(0,0,240,320,Red);
    TFT.locate(15,20);
    printf("SERVOMOTOR");

    TFT.fillcircle(120,185,100,Black);
    TFT.circle(120,185,100,White);
    TFT.circle(120,185,80,White);

    TFT.fillrect(20,186,220,290,Red);
    TFT.line(20,186,220,186,White);

    TFT.set_font((unsigned char*) Arial24x23);
    TFT.locate(10,188);
    printf("0");
    TFT.locate(175,188);
    printf("180");
    TFT.locate(105,62);
    printf("90");
    TFT.rect(5,5,235,315,Black);

    TFT.rect(169,249,221,301,White);
    TFT.Bitmap(170,250,50,50,flecha);

    angulosVerde();
    angulosBlack();

    while(isRunning) {

        if (myTouch.DataAvailable()) {
            if(myTouch.Read()) {
                x = myTouch.GetX(); // toma x del touch
                y = myTouch.GetY(); // toma y del touch
                TFT.locate(20,240);
                printf("Grado:");
                TFT.locate(20,266);

                teclaPrecionada = tortaServo(x,y);

                if(teclaPrecionada!=219) {
               
                    printf("%d   ",teclaPrecionada);
                    myServo.write((0.05+((0.05*teclaPrecionada)/45))/2.5);
                }
                
                if(y>3&&x>115&&y<26&&x<138) {
                    isRunning=false;
                    myServo.write(0.06);
                    pantallaPrincipal();
                }
            }
        }
    }
}

int tortaServo(float x, float y)
{
    angulosBlack();
    int a=0;
    //////0
    if (y>86&&x>=80&&y<102&&x<84) {
        TFT.line(120,185,40,185,Green);//0
        return 0;
    }
    //////5
    if (y>86&&x>=76&&y<102&&x<80) {
        TFT.line(120,185,41,179,Green);//5
        return 5;
    }
    //////10
    if (y>86&&x>=72&&y<102&&x<76) {
        TFT.line(120,185,42,172,Green);//10
        return 10;
    }
    //////15
    if (y>86&&x>=68&&y<102&&x<72) {
        TFT.line(120,185,43,165,Green);//15
        return 15;
    }
    //////20
    if (y>86&&x>=64&&y<102&&x<68) {
        TFT.line(120,185,45,158,Green);//20
        return 20;
    }
    //////25
    if (y>86&&x>=60&&y<102&&x<64) {
        TFT.line(120,185,48,152,Green);//25
        return 25;
    }
    //////30
    if (y>76&&x>=56&&y<95&&x<60) {
        TFT.line(120,185,51,145,Green);//30
        return 30;
    }
    //////35
    if (y>76&&x>=52&&y<95&&x<56) {
        TFT.line(120,185,55,140,Green);//35
        return 35;
    }
    //////40
    if (y>76&&x>=51&&y<95&&x<52) {
        TFT.line(120,185,59,134,Green);//40
        return 40;
    }
    //////45
    if (y>81&&x>=44&&y<95&&x<51) {
        TFT.line(120,185,50,115,Green);//45
        return 45;
    }
    ////////////////
    //////90
    if (y>=49&&x>30&&y<=51&&x<51) {
        TFT.line(120,185,120,85,Green);//90
        return 90;
    }
    //////50
    if (y>77&&x>30&&y<=81&&x<51) {
        TFT.line(120,185,69,124,Green);//50
        return 50;
    }
    //////55
    if (y>73&&x>30&&y<=77&&x<51) {
        TFT.line(120,185,75,120,Green);//55
        return 55;
    }
    //////60
    if (y>69&&x>30&&y<=73&&x<51) {
        TFT.line(120,185,80,116,Green);//60
        return 60;
    }
    //////65
    if (y>66&&x>30&&y<=69&&x<51) {
        TFT.line(120,185,87,113,Green);//65
        return 65;
    }
    //////70
    if (y>63&&x>30&&y<=66&&x<51) {
        TFT.line(120,185,93,110,Green);//70
        return 70;
    }
    //////75
    if (y>59&&x>30&&y<=63&&x<51) {
        TFT.line(120,185,100,108,Green);//75
        return 75;
    }
    //////80
    if (y>55&&x>30&&y<=59&&x<51) {
        TFT.line(120,185,107,107,Green);//80
        return 80;
    }
    //////85
    if (y>51&&x>30&&y<=55&&x<51) {
        TFT.line(120,185,114,106,Green);//85
        return 85;
    }
    //////////
    //////135
    if (y>5&&x>=44&&y<24&&x<51) {
        TFT.line(120,185,190,115,Green);//135
        return 135;
    }

    //////140
    if (y>5&&x>=51&&y<24&&x<52) {
        TFT.line(120,185,181,134,Green);//140
        return 140;
    }
    //////150
    if (y>5&&x>=56&&y<24&&x<60) {
        TFT.line(120,185,189,145,Green);//150
        return 150;
    }
    //////145
    if (y>5&&x>=52&&y<24&&x<56) {
        TFT.line(120,185,185,140,Green);//145
        return 145;
    }

    //////180
    if (y>1&&x>=80&&y<20&&x<84) {
        TFT.line(120,185,220,185,Green);//180
        return 180;
    }
    //////175
    if (y>1&&x>=76&&y<20&&x<80) {
        TFT.line(120,185,199,179,Green);//175
        return 175;
    }
    //////170
    if (y>1&&x>=72&&y<20&&x<76) {
        TFT.line(120,185,198,172,Green);//170
        return 170;
    }
    //////165
    if (y>1&&x>=68&&y<20&&x<72) {
        TFT.line(120,185,197,165,Green);//165
        return 165;
    }
    //////160
    if (y>1&&x>=64&&y<20&&x<68) {
        TFT.line(120,185,195,158,Green);//160
        return 160;
    }
    //////155
    if (y>1&&x>=60&&y<20&&x<64) {
        TFT.line(120,185,192,152,Green);//155
        return 155;
    }
    ///////
    //////95
    if (y>=46&&x>30&&y<49&&x<51) {
        TFT.line(120,185,126,106,Green);//95
        return 95;
    }
    //////100
    if (y>=43&&x>30&&y<46&&x<51) {
        TFT.line(120,185,133,107,Green);//100
        return 100;
    }
    //////105
    if (y>=40&&x>30&&y<43&&x<51) {
        TFT.line(120,185,140,108,Green);//105
        return 105;
    }
    //////110
    if (y>=37&&x>30&&y<40&&x<51) {
        TFT.line(120,185,147,110,Green);//110
        return 110;
    }
    //////115
    if (y>=34&&x>30&&y<37&&x<51) {
        TFT.line(120,185,153,113,Green);//115
        return 115;
    }
    //////120
    if (y>=31&&x>30&&y<34&&x<51) {
        TFT.line(120,185,160,116,Green);//120
        return 120;
    }
    //////125
    if (y>=28&&x>30&&y<31&&x<51) {
        TFT.line(120,185,165,120,Green);//125
        return 125;
    }
    //////130
    if (y>=24&&x>30&&y<28&&x<51) {
        TFT.line(120,185,171,124,Green);//130
        return 130;
    }
    return 219;
}

void angulosVerde()
{
    TFT.line(120,185,20,185,Green);//0
    TFT.line(120,185,41,179,Green);//5
    TFT.line(120,185,42,172,Green);//10
    TFT.line(120,185,43,165,Green);//15
    TFT.line(120,185,45,158,Green);//20
    TFT.line(120,185,48,152,Green);//25
    TFT.line(120,185,51,145,Green);//30
    TFT.line(120,185,55,140,Green);//35
    TFT.line(120,185,59,134,Green);//40
    TFT.line(120,185,50,115,Green);//45
    TFT.line(120,185,69,124,Green);//50
    TFT.line(120,185,75,120,Green);//55
    TFT.line(120,185,80,116,Green);//60
    TFT.line(120,185,87,113,Green);//65
    TFT.line(120,185,93,110,Green);//70
    TFT.line(120,185,100,108,Green);//75
    TFT.line(120,185,107,107,Green);//80
    TFT.line(120,185,114,106,Green);//85
    TFT.line(120,185,120,85,Green);//90
    TFT.line(120,185,126,106,Green);//95
    TFT.line(120,185,133,107,Green);//100
    TFT.line(120,185,140,108,Green);//105
    TFT.line(120,185,147,110,Green);//110
    TFT.line(120,185,153,113,Green);//115
    TFT.line(120,185,160,116,Green);//120
    TFT.line(120,185,165,120,Green);//125
    TFT.line(120,185,171,124,Green);//130
    TFT.line(120,185,190,115,Green);//135
    TFT.line(120,185,181,134,Green);//140
    TFT.line(120,185,185,140,Green);//145
    TFT.line(120,185,189,145,Green);//150
    TFT.line(120,185,192,152,Green);//155
    TFT.line(120,185,195,158,Green);//160
    TFT.line(120,185,197,165,Green);//165
    TFT.line(120,185,198,172,Green);//170
    TFT.line(120,185,199,179,Green);//175
    TFT.line(120,185,220,185,Green);//180
}

void angulosBlack()
{
    TFT.line(120,185,40,185,Black);//0
    TFT.line(120,185,41,179,Black);//5
    TFT.line(120,185,42,172,Black);//10
    TFT.line(120,185,43,165,Black);//15
    TFT.line(120,185,45,158,Black);//20
    TFT.line(120,185,48,152,Black);//25
    TFT.line(120,185,51,145,Black);//30
    TFT.line(120,185,55,140,Black);//35
    TFT.line(120,185,59,134,Black);//40
    TFT.line(120,185,64,129,Black);//45
    TFT.line(120,185,69,124,Black);//50
    TFT.line(120,185,75,120,Black);//55
    TFT.line(120,185,80,116,Black);//60
    TFT.line(120,185,87,113,Black);//65
    TFT.line(120,185,93,110,Black);//70
    TFT.line(120,185,100,108,Black);//75
    TFT.line(120,185,107,107,Black);//80
    TFT.line(120,185,114,106,Black);//85
    TFT.line(120,185,120,105,Black);//90
    TFT.line(120,185,126,106,Black);//95
    TFT.line(120,185,133,107,Black);//100
    TFT.line(120,185,140,108,Black);//105
    TFT.line(120,185,147,110,Black);//110
    TFT.line(120,185,153,113,Black);//115
    TFT.line(120,185,160,116,Black);//120
    TFT.line(120,185,165,120,Black);//125
    TFT.line(120,185,171,124,Black);//130
    TFT.line(120,185,176,129,Black);//135
    TFT.line(120,185,181,134,Black);//140
    TFT.line(120,185,185,140,Black);//145
    TFT.line(120,185,189,145,Black);//150
    TFT.line(120,185,192,152,Black);//155
    TFT.line(120,185,195,158,Black);//160
    TFT.line(120,185,197,165,Black);//165
    TFT.line(120,185,198,172,Black);//170
    TFT.line(120,185,199,179,Black);//175
    TFT.line(120,185,200,185,Black);//180
}