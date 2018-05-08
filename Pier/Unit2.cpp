//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

        int ruch_rzymu=0;
        int ruch_cart=0;
        int zajete_pola[9];
        int wylosowana;
        int numer_ruchu=0;    //po prostu tura
        char p1,p2,p3,p4,p5,p6,p7,p8,p9;    // przynaleznosc pola
        char kto;             //kto ma ruch
        bool x;   //sprawdza czy juz ktoras ze stron odniosla zwyciestwo
        bool z=0;     //zwyciestwo
        void sprawdz()
        {
         Form2->tura->Caption="Tura:"+IntToStr(numer_ruchu);
         Form2->Label3->Caption="Ruch CAR:"+IntToStr(ruch_cart);
         Form2->Label4->Caption="Ruch ROM:"+IntToStr(ruch_rzymu);
         if( (p1==p2 && p2==p3 && p1==p3 && p1 !='n' && p2!='n' && p3!='n')||
             (p4==p5 && p5==p6 && p6==p4 && p4 !='n' && p5!='n' && p6!='n')||
             (p7==p8 && p8==p9 && p7==p9 && p7 !='n' && p8!='n' && p9!='n')||

             (p1==p4 && p4==p7 && p1==p7 && p1 !='n' && p4!='n' && p7!='n')||
             (p2==p5 && p5==p8 && p2==p8 && p2 !='n' && p5!='n' && p8!='n')||
             (p3==p6 && p6==p9 && p3==p9 && p3 !='n' && p6!='n' && p9!='n')||

             (p1==p5 && p5==p9 && p1==p9 && p1 !='n' && p5!='n' && p9!='n')||
             (p3==p5 && p5==p7 && p3==p7 && p3 !='n' && p5!='n' && p7!='n'))
             {
             char * w;
             if(kto=='r') {Form2->chmuraz->Visible=true; z=1;Form2->KoniecPoziomu1->Visible=true;}
             else {Form2->chmurap->Visible=true;}
             x=1;
                char *p="Partia zakonczona";
                Application->MessageBox(p,"KoniecGry",MB_OK);
             }
         else if( numer_ruchu==9)
         { Form2->chmurar->Visible=true; x=1;          char *w="Partia zakonczona";
         Application->MessageBox(w,"KoniecGry",MB_OK);}

        }   //sprawdz
        void ruch_cpu()
        {
        if(x==0)
        {
                Application->ProcessMessages();Sleep(500);
           if(numer_ruchu==1 && p5=='n')
           {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");  p5='r'; Form2->pole5->Enabled=false;}
           else if(numer_ruchu==1 && p5!='n')
           {
             wylosowana=random(8)+1;
             switch(wylosowana)
             {
            case 1:  {
              Form2->pole1->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole1->Enabled=false;
              p1='r';
              //zajete_pola[numer_ruchu]=1;
                break;
              }
            case 2:  {
              Form2->pole2->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole2->Enabled=false;
              p2='r';
              //zajete_pola[numer_ruchu]=2;
                break;
              }
            case 3:  {
              Form2->pole3->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole3->Enabled=false;
              p3='r';
              //zajete_pola[numer_ruchu]=3;
                break;
              }
            case 4:  {
              Form2->pole4->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole4->Enabled=false;
              p4='r';
              //zajete_pola[numer_ruchu]=4;
                break;
              }
            case 5:  {
              Form2->pole6->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole6->Enabled=false;
              p6='r';
              //zajete_pola[numer_ruchu]=6;
                break;
              }
            case 6:  {
              Form2->pole7->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole7->Enabled=false;
              p7='r';
              //zajete_pola[numer_ruchu]=7;
                break;
              }
            case 7:  {
              Form2->pole8->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole8->Enabled=false;
              p8='r';
              //zajete_pola[numer_ruchu]=8;
                break;
              }
            case 8:  {
              Form2->pole9->Picture->LoadFromFile ("poziom1/ROMd.bmp");
               Form2->pole9->Enabled=false;
              p9='r';
              //zajete_pola[numer_ruchu]=9;
                break;
              }
             }
            }  //else if
            else if(numer_ruchu!=1 && p1=='r' && p2=='r' && p3=='n') //chec wygranej
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='r' && p3=='r' && p2=='n')
            {Form2->pole2->Picture->LoadFromFile("poziom1/ROMd.bmp");p2='r'; Form2->pole2->Enabled=false;}
            else if(numer_ruchu!=1 && p2=='r' && p3=='r' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole3->Enabled=false;}

            else if(numer_ruchu!=1 && p4=='r' && p5=='r' && p6=='n')
            {Form2->pole6->Picture->LoadFromFile("poziom1/ROMd.bmp");p6='r'; Form2->pole6->Enabled=false;}
            else if(numer_ruchu!=1 && p5=='r' && p6=='r' && p4=='n')
            {Form2->pole4->Picture->LoadFromFile("poziom1/ROMd.bmp");p4='r'; Form2->pole4->Enabled=false;}
            else if(numer_ruchu!=1 && p4=='r' && p6=='r' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}

            else if(numer_ruchu!=1 && p7=='r' && p8=='r' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p7=='r' && p9=='r' && p8=='n')
            {Form2->pole8->Picture->LoadFromFile("poziom1/ROMd.bmp");p8='r'; Form2->pole8->Enabled=false;}
            else if(numer_ruchu!=1 && p8=='r' && p9=='r' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}

            else if(numer_ruchu!=1 && p1=='r' && p4=='r' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='r' && p7=='r' && p4=='n')
            {Form2->pole4->Picture->LoadFromFile("poziom1/ROMd.bmp");p4='r'; Form2->pole4->Enabled=false;}
            else if(numer_ruchu!=1 && p4=='r' && p7=='r' && p1=='n')
            {Form2->pole1->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole1->Enabled=false;}

            else if(numer_ruchu!=1 && p2=='r' && p5=='r' && p8=='n')
            {Form2->pole8->Picture->LoadFromFile("poziom1/ROMd.bmp");p8='r'; Form2->pole8->Enabled=false;}
            else if(numer_ruchu!=1 && p5=='r' && p8=='r' && p2=='n')
            {Form2->pole2->Picture->LoadFromFile("poziom1/ROMd.bmp");p2='r'; Form2->pole2->Enabled=false;}
            else if(numer_ruchu!=1 && p2=='r' && p8=='r' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}

            else if(numer_ruchu!=1 && p3=='r' && p6=='r' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p6=='r' && p9=='r' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='r' && p9=='r' && p6=='n')
            {Form2->pole6->Picture->LoadFromFile("poziom1/ROMd.bmp");p6='r'; Form2->pole6->Enabled=false;}

            else if(numer_ruchu!=1 && p1=='r' && p5=='r' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='r' && p5=='r' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='r' && p9=='r' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='r' && p7=='r' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}
            else if(numer_ruchu!=1 && p9=='r' && p5=='r' && p1=='n')
            {Form2->pole1->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole1->Enabled=false;}
            else if(numer_ruchu!=1 && p7=='r' && p5=='r' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}

else
{                                                                 //chec blokowania
            if(numer_ruchu!=1 && p1=='c' && p2=='c' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='c' && p3=='c' && p2=='n')
            {Form2->pole2->Picture->LoadFromFile("poziom1/ROMd.bmp");p2='r'; Form2->pole2->Enabled=false;}
            else if(numer_ruchu!=1 && p2=='c' && p3=='c' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole3->Enabled=false;}

            else if(numer_ruchu!=1 && p4=='c' && p5=='c' && p6=='n')
            {Form2->pole6->Picture->LoadFromFile("poziom1/ROMd.bmp");p6='r'; Form2->pole6->Enabled=false;}
            else if(numer_ruchu!=1 && p5=='c' && p6=='c' && p4=='n')
            {Form2->pole4->Picture->LoadFromFile("poziom1/ROMd.bmp");p4='r'; Form2->pole4->Enabled=false;}
            else if(numer_ruchu!=1 && p4=='c' && p6=='c' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}

            else if(numer_ruchu!=1 && p7=='c' && p8=='c' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p7=='c' && p9=='c' && p8=='n')
            {Form2->pole8->Picture->LoadFromFile("poziom1/ROMd.bmp");p8='r'; Form2->pole8->Enabled=false;}
            else if(numer_ruchu!=1 && p8=='c' && p9=='c' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}

            else if(numer_ruchu!=1 && p1=='c' && p4=='c' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='c' && p7=='c' && p4=='n')
            {Form2->pole4->Picture->LoadFromFile("poziom1/ROMd.bmp");p4='r'; Form2->pole4->Enabled=false;}
            else if(numer_ruchu!=1 && p4=='c' && p7=='c' && p1=='n')
            {Form2->pole1->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole1->Enabled=false;}

            else if(numer_ruchu!=1 && p2=='c' && p5=='c' && p8=='n')
            {Form2->pole8->Picture->LoadFromFile("poziom1/ROMd.bmp");p8='r'; Form2->pole8->Enabled=false;}
            else if(numer_ruchu!=1 && p5=='c' && p8=='c' && p2=='n')
            {Form2->pole2->Picture->LoadFromFile("poziom1/ROMd.bmp");p2='r'; Form2->pole2->Enabled=false;}
            else if(numer_ruchu!=1 && p2=='c' && p8=='c' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}

            else if(numer_ruchu!=1 && p3=='c' && p6=='c' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p6=='c' && p9=='c' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='c' && p9=='c' && p6=='n')
            {Form2->pole6->Picture->LoadFromFile("poziom1/ROMd.bmp");p6='r'; Form2->pole6->Enabled=false;}

            else if(numer_ruchu!=1 && p1=='c' && p5=='c' && p9=='n')
            {Form2->pole9->Picture->LoadFromFile("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='c' && p5=='c' && p7=='n')
            {Form2->pole7->Picture->LoadFromFile("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}
            else if(numer_ruchu!=1 && p1=='c' && p9=='c' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}
            else if(numer_ruchu!=1 && p3=='c' && p7=='c' && p5=='n')
            {Form2->pole5->Picture->LoadFromFile("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}
            else if(numer_ruchu!=1 && p9=='c' && p5=='c' && p1=='n')
            {Form2->pole1->Picture->LoadFromFile("poziom1/ROMd.bmp");p1='r'; Form2->pole1->Enabled=false;}
            else if(numer_ruchu!=1&& p7=='c'&& p5=='c' && p3=='n')
            {Form2->pole3->Picture->LoadFromFile("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}

            else                                   // gdy nie ma co zrobic
            {
            if(  p5=='n'){Form2->pole5->Picture->LoadFromFile ("poziom1/ROMd.bmp");p5='r'; Form2->pole5->Enabled=false;}
            else if(  p1=='n'){Form2->pole1->Picture->LoadFromFile ("poziom1/ROMd.bmp");p1='r'; Form2->pole1->Enabled=false;}
            else if(  p2=='n'){Form2->pole2->Picture->LoadFromFile ("poziom1/ROMd.bmp");p2='r'; Form2->pole2->Enabled=false;}
            else if(  p3=='n'){Form2->pole3->Picture->LoadFromFile ("poziom1/ROMd.bmp");p3='r'; Form2->pole3->Enabled=false;}
            else if(  p4=='n'){Form2->pole4->Picture->LoadFromFile ("poziom1/ROMd.bmp");p4='r'; Form2->pole4->Enabled=false;}
            else if(  p6=='n'){Form2->pole6->Picture->LoadFromFile ("poziom1/ROMd.bmp");p6='r'; Form2->pole6->Enabled=false;}
            else if(  p7=='n'){Form2->pole7->Picture->LoadFromFile ("poziom1/ROMd.bmp");p7='r'; Form2->pole7->Enabled=false;}
            else if(  p8=='n'){Form2->pole8->Picture->LoadFromFile ("poziom1/ROMd.bmp");p8='r'; Form2->pole8->Enabled=false;}
            else if(  p9=='n'){Form2->pole9->Picture->LoadFromFile ("poziom1/ROMd.bmp");p9='r'; Form2->pole9->Enabled=false;}
            }
         numer_ruchu++;
         ruch_rzymu++;
}

         Form2->male ->Picture->LoadFromFile ("poziom1/CAR.bmp");
         wylosowana=0;
         kto='c';
         sprawdz();
        }
        }//void


//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
       //sndPlaySound("poziom1/snd/Sabaton - Attero Dominatus 8-bit.wav",SND_ASYNC);
       Label1->Visible=false;
       Label2->Visible=false;
       Button1->Visible=false;
        pole1->Visible=true; pole1->Enabled=true;
        pole1->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole2->Visible=true; pole2->Enabled=true;
        pole2->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole3->Visible=true; pole3->Enabled=true;
        pole3->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole4->Visible=true; pole4->Enabled=true;
        pole4->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole5->Visible=true; pole5->Enabled=true;
        pole5->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole6->Visible=true; pole6->Enabled=true;
        pole6->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole7->Visible=true; pole7->Enabled=true;
        pole7->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole8->Visible=true; pole8->Enabled=true;
        pole8->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        pole9->Visible=true; pole9->Enabled=true;
        pole9->Picture->LoadFromFile ("poziom1/pustyd.bmp");
        male->Visible=true;
        male->Picture->LoadFromFile("poziom1/CAR.bmp");
        Restart->Visible=true;
        x=0;
        if(z==1) {KoniecPoziomu1->Visible=true;}
        kto='c';
        p1='n'; p2='n'; p3='n';
        p4='n'; p5='n'; p6='n';
        p7='n'; p8='n'; p9='n';
        ruch_rzymu=0;
        ruch_cart=0;
        numer_ruchu=0;
        tura->Caption="Tura:0";
        Label4->Caption="Ruchy ROM:0";
        Label3->Caption="Ruchy CAR:0";
        chmuraz->Visible=false;
        chmurar->Visible=false;
        chmurap->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole1Click(TObject *Sender)
{
if(p1=='n' && x==0)
{
        if(kto=='c')
        {
         pole1->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p1='c';
         kto='r';
         zajete_pola[numer_ruchu]=1;
         numer_ruchu++;
        ruch_cart++;
        pole1->Enabled=false;
        }
}
        sprawdz();
        ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole2Click(TObject *Sender)
{
if(p2=='n' && x==0)
{
        if(kto=='c')
        {
         pole2->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p2='c';
         kto='r';
         zajete_pola[numer_ruchu]=2;
         numer_ruchu++;
        ruch_cart++;
        pole2->Enabled=false;
        }
}
        sprawdz();
        ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole3Click(TObject *Sender)
{
if(p3=='n' && x==0)
{
        if(kto=='c')
        {
         pole3->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p3='c';
         kto='r';
         zajete_pola[numer_ruchu]=3;
         numer_ruchu++;
        ruch_cart++;
        pole3->Enabled=false;
        }
}
        sprawdz();
        ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole4Click(TObject *Sender)
{
if(p4=='n' && x==0)
{
        if(kto=='c')
        {
         pole4->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p4='c';
         kto='r';
         zajete_pola[numer_ruchu]=4;
         numer_ruchu++;
        ruch_cart++;
        pole4->Enabled=false;
        }
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole5Click(TObject *Sender)
{
if(p5=='n' && x==0)
{
        if(kto=='c')
        {
         pole5->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p5='c';
         kto='r';
         zajete_pola[numer_ruchu]=5;
         numer_ruchu++;
        ruch_cart++;
        pole5->Enabled=false;
        }
        /*else
        {
         pole5->Picture->LoadFromFile ("poziom1/ROMd.bmp");
         male->Picture->LoadFromFile  ("poziom1/CAR.bmp");
         kto='c';
         p5='r';
        } */
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole6Click(TObject *Sender)
{
if(p6=='n' && x==0)
{
        if(kto=='c')
        {
         pole6->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p6='c';
         kto='r';
         zajete_pola[numer_ruchu]=6;
         numer_ruchu++;
        ruch_cart++;
        pole6->Enabled=false;
        }
        /*else
        {
         pole6->Picture->LoadFromFile ("poziom1/ROMd.bmp");
         male->Picture->LoadFromFile  ("poziom1/CAR.bmp");
         kto='c';
         p6='r';
        } */
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole7Click(TObject *Sender)
{
if(p7=='n' && x==0)
{
        if(kto=='c')
        {
         pole7->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p7='c';
         kto='r';
         zajete_pola[numer_ruchu]=7;
         numer_ruchu++;
        ruch_cart++;
        pole7->Enabled=false;
        }
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole8Click(TObject *Sender)
{
if(p8=='n' && x==0)
{
        if(kto=='c')
        {
         pole8->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p8='c';
         kto='r';
         zajete_pola[numer_ruchu]=8;
         numer_ruchu++;
        }
        ruch_cart++;
        pole8->Enabled=false;
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::pole9Click(TObject *Sender)
{
if(p9=='n' && x==0)
{
        if(kto=='c')
        {
         pole9->Picture->LoadFromFile ("poziom1/CARd.bmp");
         male ->Picture->LoadFromFile ("poziom1/ROM.bmp");
         p9='c';
         kto='r';
         zajete_pola[numer_ruchu]=9;
         numer_ruchu++;
        }
        ruch_cart++;
        pole9->Enabled=false;
}
        sprawdz();
         ruch_cpu();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::KoniecPoziomu1Click(TObject *Sender)
{
        Form2->Visible=false;
        Form3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
        randomize();
}
//---------------------------------------------------------------------------

