//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit8.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
int p=0;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Next3Click(TObject *Sender)
{
        if(p==0)
        {
        nagrody1->Visible=true;
        p++;
        }
        else if (p==1)
        {
        nagrody2->Visible=true;
        nagrody1->Visible=false;
        p++;
        }
        else if( p==2)
        {
        nagrody3->Visible=true;
        nagrody2->Visible=false;
        p++;
        }
        else if (p==3)
        {
        nagrody4->Visible=true;
        nagrody3->Visible=false;
        p++;
        }
        else if (p==4)
        {
        nagrody5->Visible=true;
        nagrody4->Visible=false;
        p++;
        }
        else if ( p==5)
        {
        nagrody6->Visible=true;
        nagrody5->Visible=false;
        p++;
        }
        else if (p==6)
        {
        nagrody6->Visible=false;
        Next3->Caption="Przejdz na poziom3";
        Form7->Visible=false;
        Form7->Enabled=false;
        Form8->Visible=true;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm7::FormCreate(TObject *Sender)
{
 // sndPlaySound("folder wav/Sabaton - The Final Solution (8-Bit).wav",SND_ASYNC);
}
//---------------------------------------------------------------------------



