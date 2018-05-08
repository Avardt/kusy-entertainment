//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
int i=0;
/*AnsiString pytanie1,pytanie2,pytanie3;
AnsiString odpa1,odpa2,odpa3;
AnsiString odpb1,odpb2,odpb3;
AnsiString odpc1,odpc2,odpc3;
AnsiString odpd1,odpd2,odpd3;
AnsiString poprawna1,poprawna2,poprawna3;*/
AnsiString pytanie1="Kto rzucil swoj¹ kolezanka na studniowke o parkiet ?";
AnsiString odpa1="Konrad";
AnsiString odpb1="Dszefo";
AnsiString odpc1="Korek";
AnsiString odpd1="Kusy";
AnsiString pytanie2="Kim jest osoba ktora odbywa swoje chwile triumfu";
AnsiString odpa2="Pietrek";
AnsiString odpb2="Korek";
AnsiString odpc2="Dszefo";
AnsiString odpd2="Korbal";
int h=0;
AnsiString pytanie3="Szlachetny szkolny p³yn zwany przez niektórych kompotem mia³ te¿ mniej pochlebn¹ nazwe... jak ta nazwa brzmi ?";
AnsiString odpa3="podloga";
AnsiString odpb3="Sciera";
AnsiString odpc3="kwas bezsmakowy";
AnsiString odpd3="recznik";

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{

       sndPlaySound("folder wav/Sabaton - The Price Of A Mile 8bit.wav",SND_ASYNC);
       Label2->Visible=false;
       Restart->Visible=false;
       KoniecPoziomu2->Visible=false;
       Button1->Visible=false;
       Label1->Visible=false;
       Poziom2->Visible=false;
       Pytanie1->Visible=true;Pytanie1->Caption=pytanie1;
       Odpa1->Visible=true;Odpa1->Caption=odpa1;
       Odpb1->Visible=true;Odpb1->Caption=odpb1;
       Odpc1->Visible=true;Odpc1->Caption=odpc1;
       Odpd1->Visible=true;Odpd1->Caption=odpd1;
       h=0;
       i=0;
        przegrana->Visible=false;
        zwyciestwo->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Odpa1Click(TObject *Sender)
{
if(h==0)
{
      sprawdz1->Caption="Dobrze! Zdobywasz Punkt!";
      sprawdz1->Visible=true;;
      Konrad->Visible=true;
      i++;
      h++;

}
else if(h==1)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      Pomocnicze->Visible=false;
      h++;
}
else if(h==2)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
      Pytanie1->Visible=false;
      Odpa1->Visible=false;
      Odpb1->Visible=false;
      Odpc1->Visible=false;
      Odpd1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Odpb1Click(TObject *Sender)
{
if(h==0)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;

      h++;
}
else if(h==1)
{
      sprawdz1->Caption="Dobrze! Zdobywasz Punkt!";
      sprawdz1->Visible=true;
      Pomocnicze->Visible=false;
      h++;
      i++;
}
else if(h==2)
{
      sprawdz1->Caption="Dobrze! Zdobywasz Punkt!";
      sprawdz1->Visible=true;
      h++;
      i++;
}
      Pytanie1->Visible=false;
      Odpa1->Visible=false;
      Odpb1->Visible=false;
      Odpc1->Visible=false;
      Odpd1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Odpc1Click(TObject *Sender)
{
if(h==0)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
if(h==1)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      Pomocnicze->Visible=false;;
      h++;
}
else if(h==2)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
      Pytanie1->Visible=false;
      Odpa1->Visible=false;
      Odpb1->Visible=false;
      Odpc1->Visible=false;
      Odpd1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Odpd1Click(TObject *Sender)
{
if(h==0)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
else if(h==1)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
else if(h==2)
{
      sprawdz1->Caption="Zle!";
      sprawdz1->Visible=true;
      h++;
}
      Pytanie1->Visible=false;
      Odpa1->Visible=false;
      Odpb1->Visible=false;
      Odpc1->Visible=false;
      Odpd1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::sprawdz1Click(TObject *Sender)
{
       Konrad->Visible=false;
       if(h==1)
       {
       Pytanie1->Visible=true;Pytanie1->Caption=pytanie2;
       Odpa1->Visible=true;Odpa1->Caption=odpa2;
       Odpb1->Visible=true;Odpb1->Caption=odpb2;
       Odpc1->Visible=true;Odpc1->Caption=odpc2;
       Odpd1->Visible=true;Odpd1->Caption=odpd2;
       Pomocnicze->Picture->LoadFromFile("poziom2/korek1.bmp");
       Pomocnicze->Visible=true;
       }
       else if(h==2)
       {
       Pomocnicze->Picture->LoadFromFile("poziom2/stadnicki.bmp");
       Pomocnicze->Visible=true;
       Pytanie1->Visible=true;Pytanie1->Caption=pytanie3;
       Odpa1->Visible=true;Odpa1->Caption=odpa3;
       Odpb1->Visible=true;Odpb1->Caption=odpb3;
       Odpc1->Visible=true;Odpc1->Caption=odpc3;
       Odpd1->Visible=true;Odpd1->Caption=odpd3;
       }
       /*else if(h==3)
       {
       Pytanie1->Visible=true;Pytanie1->Caption=pytanie3;
       Odpa1->Visible=true;Odpa1->Caption=odpa3;
       Odpb1->Visible=true;Odpb1->Caption=odpb3;
       Odpc1->Visible=true;Odpc1->Caption=odpc3;
       Odpd1->Visible=true;Odpd1->Caption=odpd3;
       }    */
       else if(h==3)
       {
                Pomocnicze->Visible=false;
           Label2->Visible=true;
           Label2->Caption="Zdobyte Punkty "+IntToStr(i)+"/3";
           if(i==3){Label3->Caption="Gratulacje! Zwyciezyles!";KoniecPoziomu2->Visible=true;Restart->Visible=true; zwyciestwo->Visible=true; }
           else {Label3->Caption="Sprobuj jeszcze raz";Restart->Visible=true; przegrana->Visible=true;}
       }
       sprawdz1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::KoniecPoziomu2Click(TObject *Sender)
{
        Form4->Visible=false;
        Form5->Visible=true;
}
//---------------------------------------------------------------------------


