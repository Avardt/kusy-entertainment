//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit9.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
int przyjaciele=0;
int pozycjax[9999];
int pozycjay[9999];
int nr_ruchu=0;
bool start=0;
int friends=0;
int punkty=0;

        bool kolizja(int f , TImage*piet, TImage*osobniki)
        {
             if(piet->Left >= osobniki->Left-piet->Width &&
                piet->Left <= osobniki->Left+osobniki->Width &&
                piet->Top >= osobniki->Top-piet->Height &&
                piet->Top <= osobniki->Top+osobniki->Height )
                {
if( f==2|| f==5 || f==6 || f==12 || f==3 || f == 14 || f==18 || f==21 || f==22 || f==23 || f==28 )
{ punkty=punkty+2; }
else if(  f==1 || f==4 || f==8 || f==7 || f == 9 || f==10 || f==15 || f==11 || f==16 || f==13 || f==17 || f==19 || f==20 || f==24 || f == 25
|| f==26 || f==27 )
{ punkty=punkty++; }
Form8->Punkty_sp->Caption="Punkty Spolecznosci:" +IntToStr(punkty);









friends++; return true;
}
             else return false;
        }

//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------







void __fastcall TForm8::lewoTimer(TObject *Sender)
{
if(nr_ruchu==9990){ nr_ruchu=1;}
pozycjax[nr_ruchu]=pietrek->Left;
pozycjay[nr_ruchu]=pietrek->Top;
int k=3;
for( int f=1;f<=friends;f++)
{
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Left=pozycjax[nr_ruchu-k];
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Top=pozycjay[nr_ruchu-k];
 k=k+3;
}



 prawo->Enabled=false;
 gora->Enabled=false;
 dol->Enabled=false;
 pietrek->Left -=10;
 nr_ruchu++;

}
//---------------------------------------------------------------------------

void __fastcall TForm8::prawoTimer(TObject *Sender)
{
if(nr_ruchu==9990){ nr_ruchu=1;}
pozycjax[nr_ruchu]=pietrek->Left;
pozycjay[nr_ruchu]=pietrek->Top;
int k=3;
for( int f=1;f<=friends;f++)
{
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Left=pozycjax[nr_ruchu-k];
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Top=pozycjay[nr_ruchu-k];
 k=k+3;
}

lewo->Enabled=false;
gora->Enabled=false;
dol->Enabled=false;
pietrek->Left +=10;
 nr_ruchu++;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::goraTimer(TObject *Sender)
{
if(nr_ruchu==9990){ nr_ruchu=1;}
pozycjax[nr_ruchu]=pietrek->Left;
pozycjay[nr_ruchu]=pietrek->Top;
int k=3;
for( int f=1;f<=friends;f++)
{

 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Left=pozycjax[nr_ruchu-k];
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Top=pozycjay[nr_ruchu-k];
 k=k+3;
}

lewo->Enabled=false;
prawo->Enabled=false;
pietrek->Top -=10;
dol->Enabled=false;
nr_ruchu++;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::dolTimer(TObject *Sender)
{
if(nr_ruchu==9990){ nr_ruchu=1;}
pozycjax[nr_ruchu]=pietrek->Left;
pozycjay[nr_ruchu]=pietrek->Top;
int k=3;
for( int f=1;f<=friends;f++)
{
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Left=pozycjax[nr_ruchu-k];
 dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f)))->Top=pozycjay[nr_ruchu-k];
 k=k+3;
}

lewo->Enabled=false;
prawo->Enabled=false;
pietrek->Top +=10;
gora->Enabled=false;
nr_ruchu++;
}
//---------------------------------------------------------------------------




void __fastcall TForm8::restart8Click(TObject *Sender)
{
if(punkty>=5){ZakonczGre->Visible=true;}
Image1->Visible=false;

for( int f=1;f<29;f++ )
        {
restart8->Caption="Od nowa";
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Left=random(900)+55;
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Top=random(640)+30;
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
        }
for(int f=1;f<=4;f++)
        {
dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Left=random(900)+55;
dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Top=random(640)+30;
dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Visible=false;
        }

p29->Left=-50;
p29->Top= 100;



lewo->Enabled=false;
prawo->Enabled=false;
gora->Enabled=false;
dol->Enabled=false;
p1->Visible=true;
pietrek->Visible=true;
nr_ruchu=0;
friends=0;
punkty=0;

 restart8->Visible=false;
 tlo_inst->Visible=false;
 Punkty_sp->Caption="Punkty Społecznosci:0";

 pietrek->Left=50;
 pietrek->Top=264;



}
//---------------------------------------------------------------------------



void __fastcall TForm8::pietrektimerTimer(TObject *Sender)
{
if(punkty>=30) {ZakonczGre->Visible=false;}

for( int f=0;f<=friends;f++)
{
if(friends==f) kolizja(f+1,pietrek,dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f+1)/*1*/ )/*2*/ )/*3*/ );
}
for( int f=0;f<=friends; f++ )
{
   if( friends==f  && dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f+1)))->Visible == false)
   {dynamic_cast<TImage*>(FindComponent("p" + IntToStr(f+1)))->Visible = true;}
}
if(nr_ruchu==9990){ nr_ruchu=1;}
   if(friends==5 ){zli1->Visible=true;}
   if(friends==10 ){zli2->Visible=true;}
   if(friends==15 ){zli3->Visible=true;}
   if(friends==20 ){zli4->Visible=true;}

if( friends==29 ) { ZakonczGre->Visible=true;}


if( pietrek->Left<50)   //kolizja z lewo
{
pietrek->Visible=false;
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
}
restart8->Visible=true;
}


else if( pietrek->Left>=scianap->Left)  //kolizja z prawo
{
pietrek->Visible=false;
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
}
restart8->Visible=true;
}

else if( pietrek->Top+ pietrek->Height <=25)  //kolizja z gory
{
pietrek->Visible=false;
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
}
restart8->Visible=true;
}

else if( pietrek->Top>=scianad->Top - scianad->Height)  //kolizja z dolu
{
pietrek->Visible=false;
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
}
restart8->Visible=true;
}
for(int f=1;f<=4;f++)    //kolizja konrad/magde
{
if( pietrek->Left >= dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Left-pietrek->Width &&
                pietrek->Left <= dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Left+dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Width &&
                pietrek->Top >= dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Top-dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) )) ->Height &&
                pietrek->Top <= dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Top+dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Height &&
                dynamic_cast<TImage*>(FindComponent("zli"+IntToStr(f) ))->Visible==true )

                {
                  pietrek->Visible=false;
                for( int f=1;f<=friends;f++ )
                      {
                dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
                        }
                        restart8->Visible=true;

                }
}

    if( pietrek->Left>=scianap->Left)  //kolizja z prawo
{
pietrek->Visible=false;
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Visible=false;
}
restart8->Visible=true;
}

if( pietrek->Visible==false)
{
 if(punkty < 5)Image1->Picture->LoadFromFile("poziom4/1.bmp");
 else if(punkty >=5 && punkty < 15 ) {Image1->Picture->LoadFromFile("poziom4/2.bmp");}
 else if(punkty >=15 && punkty < 25) {Image1->Picture->LoadFromFile("poziom4/5.bmp");}
 else if(punkty >=25 && punkty < 32){Image1->Picture->LoadFromFile("poziom4/3.bmp");}
 else if(punkty >=32 ){Image1->Picture->LoadFromFile("poziom4/4.bmp");}
 Image1->Visible=true;
}

}
//---------------------------------------------------------------------------


void __fastcall TForm8::FormCreate(TObject *Sender)
{
randomize();
for( int f=1;f<=friends;f++ )
{
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Left=random(810)+55;
dynamic_cast<TImage*>(FindComponent("p"+IntToStr(f) ))->Top=random(240)+30;
}


}
//---------------------------------------------------------------------------






void __fastcall TForm8::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if( Key==VK_LEFT ) lewo->Enabled=true;
     if( Key==VK_RIGHT ) prawo->Enabled=true;
     if( Key==VK_UP ) gora->Enabled=true;
     if( Key==VK_DOWN ) dol->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ZakonczGreClick(TObject *Sender)
{
        Form8->Visible=false;
        Form9->Visible=true;
        sndPlaySound("folder wav/Sabaton - The Price Of A Mile 8bit.wav",SND_ASYNC");

}
//---------------------------------------------------------------------------

