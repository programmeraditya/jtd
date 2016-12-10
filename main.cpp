#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
 int dupc=0,dupr=0;
int take,col=3,row=3,previntake;
 int playerturn=0;
char storevalues[60][60], check[60][60],currentchar;
 string turn,status;
string p1,p2;
string player1,player2,winrepeat;
void movecursor();
void selector(char[][60]);
 int countpointp1=0,countpointp2=0,closebox=1;


void gotoxy(int col,int row)
{

    HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(hStdout,position);

}

void boxmade(int arow, int acol)
{
    char up,down,left,right;
   char vabove,sabove,vdown,sdown,cvabove,csabove,cvdown,csdown;
   for(int rw=arow;rw>=(arow-3);rw-=3)
   {
       for(int cn=acol;cn>=(acol-7);cn-=7)
       {
           vabove=storevalues[rw][cn],sabove=storevalues[rw][cn+7],vdown=storevalues[rw+3][cn],sdown=storevalues[rw+3][cn+7];
up=storevalues[rw][cn+2],down=storevalues[rw+3][cn+2],left=storevalues[rw+2][cn],right=storevalues[rw+2][cn+7];
//cvabove=check[rw][cn],csabove=check[rw][cn+7],cvdown=check[rw+3][cn],csdown=check[rw+3][cn+7];
        if((vabove=='f') && (sabove=='f' && sabove==vdown && sabove==sdown) && (up=='_' && up==down && up==left && up==right) && check[rw+2][cn+2]!='F')
           {
               gotoxy(cn+2,rw+1);
               cout<<turn;
           //    check[rw][cn]=check[rw][cn+7]=check[rw+3][cn]=check[rw+3][cn+7]='F';
           check[rw+2][cn+2]='F';
           if(turn==p1) {countpointp1++;}
           else {countpointp2++;}
           winrepeat="AGAIN";
           closebox++;
           }
       }
   }
}
void assignvalues(char a[][60])
{
    for(int arow=0;arow<60;arow++)
    {
        for(int acol=0;acol<60;acol++)
        {
            a[arow][acol]=NULL;
            check[arow][acol]=NULL;
        }
    }
}

void fillblank(int mapkey,int therow, int thecol)
{
    if (mapkey==97)
    {
        for(int startt=1;startt<7;startt++)
        {
            storevalues[therow][thecol+startt]='_';
        }
    }

    if (mapkey==100)
    {
        for(int startt=6;startt>0;startt--)
        {
            storevalues[therow][thecol-startt]='_';
        }
    }
    if (mapkey==115)
    {
        for(int startt=2;startt>0;startt--)
        {
            storevalues[therow-startt][thecol]='_';
        }
    }
    if (mapkey==119)
    {
        for(int startt=1;startt<3;startt++)
        {
            storevalues[therow+startt][thecol]='_';
        }
    }
}
void makedots()
{
    for(int r=3;r<=23;r+=3)
    {
        for(int c=3;c<55;c+=7)
        {
            gotoxy(c,r);
            cout<<char(248);
        }
    }
}

void makedotline(char anarr[][60],int trow,int tcol, int duptrow, int duptcol)
{
    int moverow,movecol;
    if(duptcol==97) //a
    {
        movecol=tcol+1;
        anarr[trow][tcol]='f';
        anarr[trow][tcol+7]='f';
        gotoxy(movecol,trow);
         for(int kk=1;kk<7;kk++)
        {
            cout<<char(196);
        }
        fillblank(duptcol,trow,tcol);
        gotoxy(tcol+7,row);
        cout<<char(248);
    }
    if(duptcol==100)//d
    {
        movecol=tcol-6;
        anarr[trow][tcol]='f';
        anarr[trow][tcol-7]='f';
        gotoxy(movecol,trow);
        for(int kk=1;kk<7;kk++)
        {
            cout<<char(196);
        }

        fillblank(duptcol,trow,tcol);
        gotoxy(tcol-7,row);
        cout<<char(248);

    }
    if(duptrow==115)//s
    {
        moverow=trow-2;
        anarr[trow][tcol]='f';
        anarr[trow-3][tcol]='f';
        fillblank(duptrow,trow,tcol);
        for(moverow;moverow<trow;moverow++)
        {
            gotoxy(tcol,moverow);
            cout<<char(179);
        }
        gotoxy(tcol,trow-3);
        cout<<char(248);

    }

    if(duptrow==119)//w
    {
        moverow=trow+2;
        anarr[trow][tcol]='f';
        anarr[trow+3][tcol]='f';
        fillblank(duptrow,trow,tcol);
        for(moverow;moverow>trow;moverow--)
        {
            gotoxy(tcol,moverow);
            cout<<char(179);
        }
        gotoxy(tcol,trow+3);
        cout<<char(248);

    }
}

void selector(char array[][60])
{

int    clonerow=row;
   int clonecol=col;
    int leftcolmax=clonecol-7;
    int rightcolmax=clonecol+7;
    int uprowmax=clonerow-3;
    int intake;
    int downrowmax=clonerow+3;
    do
    {
       again:

        intake=getch();
    } while(intake!=97 && intake!=100 && intake!=115 && intake!=119 && intake!=32);

    if(intake==97) //a
    {
     if(clonecol==3) {goto again;}
    if(clonerow==row && clonecol==col) {dupr=0;}
    if(dupr==115 || dupr==119) {goto again;}
    if (clonecol==leftcolmax) {goto again;}
    clonecol-=7;
    gotoxy(clonecol,clonerow);
    dupc=intake;
    goto again;
    }

    if(intake==100) //d
    {
        if(clonecol==52) {goto again;}
        if(clonerow==row && clonecol==col) {dupr=0;}
        if(dupr==115 || dupr==119) {goto again;}
        if(clonecol==rightcolmax) {goto again;}
        clonecol+=7;
        gotoxy(clonecol,clonerow);
        dupc=intake;
        goto again;
    }

      if(intake==115) //s
    {
        //if(clonecol==leftcolmax) {goto again;}
        if(clonerow==21) {goto again;}
       if(clonerow==row && clonecol==col) {dupc=0;}
       if(dupc==100 || dupc==97) {goto again;}
        if(clonerow==downrowmax || dupc==97) {goto again;}
        clonerow+=3;
        dupr=intake;
        gotoxy(clonecol,clonerow);
        goto again;
    }

      if(intake==119) //w
    {
        if(clonerow==3) {goto again;}
        if(clonerow==row && clonecol==col) {dupc=0;}
      //  if(clonerow==uprowmax || clonerow==downrowmax) {goto again;}
        if(dupc==100 || dupc==97) {goto again;}
        if(clonerow==uprowmax || dupc==97) {goto again;}
        clonerow-=3;
        dupr=intake;
        gotoxy(clonecol,clonerow);
        goto again;
    }
    if(intake==32 && ((currentchar=='+' && storevalues[clonerow][clonecol]!='+') || (currentchar=='f' && storevalues[clonerow][clonecol]!='f' && storevalues[clonerow][clonecol]!='A')))
    {
        doit: makedotline(storevalues,clonerow,clonecol,dupr,dupc);
        col=clonecol;
        row=clonerow;
        boxmade(clonerow,clonecol);
        gotoxy(70,8);cout<<countpointp1;
        gotoxy(75,8);cout<<countpointp2;
        gotoxy(col,row);
        if(winrepeat=="AGAIN") {        winrepeat="CONTINUE";goto jump;}
        playerturn++;
        status="P";
        goto jump;
    }
    else if (intake==32 && ((array[clonerow][clonecol]=='f') && currentchar=='f'))
    {
        if(dupc==97)
        {

            if(storevalues[clonerow][clonecol+1]=='_')
            {
                goto again;
            }

            else goto doit;

        }
         if(dupc==100)
        {

            if(storevalues[clonerow][clonecol-6]=='_')
            {
                goto again;
            }
            else goto doit;

        }
        if(dupr==115)
        {
            if(storevalues[clonerow-2][clonecol]=='_')
            {
                goto again;
            }
            else goto doit;

        }
         if(dupr==119)
        {
            if(storevalues[clonerow+2][clonecol]=='_')
            {
                goto again;
            }
            else goto doit;

        }
    }
    jump:
    if (intake==32 && array[clonerow][clonecol]=='A')
    {
        gotoxy(clonecol,clonerow);
        cout<<char(248);
        gotoxy(clonecol,clonerow);
        array[clonerow][clonecol]='N';
    }

    else if (intake==32 && array[clonerow][clonecol]=='+') {
            array[clonerow][clonecol]=NULL;
            gotoxy(clonecol,clonerow);
            cout<<char(248);
            status="NP";}
}

void movecursor()
{

    place: if(closebox==43)
    {
        Sleep(10000);
        if(countpointp1>countpointp2) {system("CLS");gotoxy(35,10);cout<<player1<<" has won!";}
        else if (countpointp1<countpointp2) {system("CLS");gotoxy(35,10);cout<<player2<<" has won!";}
        else {system("CLS");gotoxy(35,10);cout<<"It's a draw!";}
        goto enditall;
    }
        dupc=0,dupr=0;
    if (playerturn % 2==0) {turn=p1;}
    else {turn=p2;}
    gotoxy(70,4);
    cout<<"TURN: "<<turn;
    gotoxy(col,row);
  newplace: gotoxy(col,row);
  do
  {
      take=getch();

  } while (take!=100 && take!=97 && take!=115 && take!=119 && take!=32);

    while((take==119 || take==32 || take==97 || take==115 || take==100 || take==32))
    {
        if (take==32)
        {
           if(storevalues[row][col]=='+')
            {
                storevalues[row][col]=NULL;
                cout<<char(248);
                goto newplace;
            }
            if(storevalues[row][col]==NULL)
            {
                storevalues[row][col]='+';
                currentchar='+';
                gotoxy(col,row);
            cout<<'+';
            }

            if(storevalues[row][col]=='f')
            {
                storevalues[row][col]='A';
                gotoxy(col,row);
                currentchar='f';
            cout<<'+';
            }

            gotoxy(col,row);
            selector(storevalues);
            if (storevalues[row][col]=='N')
            {
                storevalues[row][col]='f';
                goto newplace;
            }
            if(status=="NP") {goto newplace;}
            else {goto place;}
        }

        if(take==119)
            {
               for(int count=3;count<=3;count+=3)
    {
        for(int ccount=3;ccount<=52;ccount+=7)
        {
            if (row==count && col==ccount) {goto place;}
        }
    }
                row=(row)-3;
                gotoxy(col,row);

                goto newplace;
            }
        if (take==97)
        {
            for(int count=3;count<=21;count+=3)
    {
        for(int ccount=3;ccount<=3;ccount+=2)
        {
            if (row==count && col==ccount) {goto place;}
        }
    }

            col=(col)-7;
            gotoxy(col,row);

            goto newplace;
        }
         if (take==115)
        {
            for(int count=21;count<=21;count+=3)
    {
        for(int ccount=3;ccount<=52;ccount+=7)
        {
            if (row==count && col==ccount) {goto place;}
        }
    }
            row=(row)+3;

            gotoxy(col,row);
            goto newplace;
        }
         if (take==100)
        {
             for(int count=3;count<=21;count+=3)
    {
        for(int ccount=52;ccount<=52;ccount+=7)
        {
            if (row==count && col==ccount) {goto place;}
        }

    }
            col=col+7;
            gotoxy(col,row);
        goto newplace;
        }
    }
    enditall:;
}

int main()
{
    cout<<"Player 1, Enter your name: ";
    cin>> player1;
    cout<<endl<<endl<<"Player 2, Enter your name: ";
    cin>> player2;
    system("CLS");
    p1=player1;
    p2=player2;
    p1.resize(3);
    p2.resize(3);
    gotoxy(70,7);cout<<p1;
    gotoxy(75,7);cout<<p2;
   assignvalues(storevalues);
   makedots();
   movecursor();
   gotoxy(20,15);
   cout<<"Press any key...";
   getch();
   return 0;
}
