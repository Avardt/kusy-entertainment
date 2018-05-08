//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int q=2;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
        if(q==2){Image1->Picture->LoadFromFile("poziom1/nagroda/2.bmp");q++;}
        else if(q==3){Image1->Picture->LoadFromFile("poziom1/nagroda/3.bmp");q++;}
        else if(q==4){Image1->Picture->LoadFromFile("poziom1/nagroda/4.bmp");q++;}
        else if(q==5){Image1->Picture->LoadFromFile("poziom1/nagroda/5.bmp");q++;Button1->Caption="Przejdz na poziom2";}
        else if(q==6){Form3->Visible=false;Form4->Visible=true;Form1->Enabled=false;}
}
//---------------------------------------------------------------------------
 