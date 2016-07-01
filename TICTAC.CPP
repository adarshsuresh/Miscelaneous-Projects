#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <iostream.h>
void star();
void text()
{
 int gd=DETECT,gm,i[4],j[4],x[4]={320,320,320,320},y[4]={320,320,320,320},cnt,t;
 initgraph(&gd,&gm,"");
i[0]=1;j[0]=1;
i[1]=-1;j[1]=1;
i[2]=1;j[2]=-1;
i[3]=-1;j[3]=-1;
 while(!kbhit())
 { delay(10);
   cleardevice();            putpixel(0,0,1);putpixel(0,0,1);putpixel(1,0,1);
   setcolor(4);
   settextstyle(1,0,3);
   setcolor(BLUE);
   outtextxy(x[0],y[0],"CREATED BY" );
   setcolor(4);
   outtextxy(x[1],y[1],"ADARSH" );
   outtextxy(x[2],y[2],"VARUN"    );
   outtextxy(x[3],y[3],"ARUN BABU"    );
   for (t=0;t<4;t++)
    {

     x[t]+=i[t]; y[t]+=j[t];

      if(x[t]>600||x[t]<0)
	i[t]=-i[t];
      if(y[t]>400||y[t]<0)
	j[t]=-j[t];
   }
  }
getch();
closegraph();
}

void win(char a[3][3],char player[20],char p)
{cleardevice();
int k=DETECT,b;
int i,j;
randomize();
initgraph(&k,&b," ");
for(i=0;i<3;i++)
{for(j=0;j<3;j++)
if(a[i][j]==p)
cout<<p<<"\t";
else
cout<<" \t";
cout<<endl<<endl;}
setcolor(4);
settextstyle(1,0,3);
star();
outtextxy(150,175,"HURRAY!!!!!!!!");
outtextxy(110,200,"CONGRATULATIONS");
outtextxy(150,225,player);
outtextxy(150,250,"WINS...........");
setcolor(4);
settextstyle(1,0,2);
outtextxy(80,320,"\nENTER A KEY TO GO BACK 2 MENU");

getch();
}

void game(char a[][3],int&co,char p1,char p2,char player1[],char player2[])
{clrscr();
randomize();
cleardevice();
 int i,j;char n;
 textcolor(random(14));
for(i=0;i<3;i++)
{cout<<endl;
for(j=0;j<3;j++)
cout<<a[i][j]<<"\t";
cout<<endl;}
if(co%2==0)
{cout<<"\n\nEnter the place where "<<player2<<" want to place your symbol:";
cin>>n;}
else
{cout<<"\n\nEnter the place where "<<player1<<" want to place your symbol:";
cin>>n;}
for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(a[i][j]==n&&co%2==0)
{a[i][j]=p2;
co++;}
else if(a[i][j]==n&&co%2!=0)
{a[i][j]=p1;
co++;}
}

void play()
{ cleardevice();
int ka=DETECT,b;
 initgraph(&ka,&b,"");
char cont;
 char player1[20],player2[20];
char p1,p2,a[3][3];
int co=1,i,j;
setcolor(4);
   settextstyle(1,0,2);
   outtextxy(70,20,"PLAYER 1");
   cout<<"\n\n\nEnter your name:";
   gets(player1);
   outtextxy(70,80,"PLAYER 2");
   cout<<"\n\n\nEnter your name :";
   gets(player2);
accept:
cout<<"\n\nEnter "<<player1<<"'s symbol(X/O):";
cin>>p1;
if(p1=='X')
p2='O';
else if(p1=='O')
p2='X';
else
{cout<<"\nInvalid symbol\nPress a key to restart\n";
getch();
goto accept;}
int k=65;
for(i=0;i<3;i++)
for(j=0;j<3;j++,k++)
a[i][j]=k;
cleardevice();
setcolor(4);
settextstyle(1,0,4);
outtextxy(180,150,player1);
outtextxy(180,200,"PLAYSFIRST");
setcolor(1);
settextstyle(1,0,4);
outtextxy(220,300,"LOADING...");
  delay(100);
  settextstyle(1,0,4);
  for(i=100;i<500;i++)
  {outtextxy(i,340,"|");
  delay(6);}
  getch();
  clrscr();
  cleardevice();
  while(co<=9)
  {
   game(a,co,p1,p2,player1,player2);
   for(i=0;i<3;i++)
       {if((a[i][0]==p1 &&a[i][1]==p1&&a[i][2]==p1)||
	   (a[0][i]==p1 &&a[1][i]==p1&&a[2][i]==p1)||
	   (a[0][0]==p1 &&a[1][1]==p1&&a[2][2]==p1)||
	   (a[2][0]==p1 &&a[1][1]==p1&&a[0][2]==p1))
	   {win(a,player1,p1);
	   goto rp;
	   }
	if((a[i][0]==p2 &&a[i][1]==p2&&a[i][2]==p2)||
	   (a[0][i]==p2&&a[1][i]==p2&&a[2][i]==p2)||
	   (a[0][0]==p2&&a[1][1]==p2&&a[2][2]==p2)||
	   (a[2][0]==p2&&a[1][1]==p2&&a[0][2]==p2))
	   {win(a,player2,p2);
	      goto rp;
	   }


 }}
 setcolor(4);
 settextstyle(1,0,2);
 outtextxy(190,280,"Game is tied");
 outtextxy(80,320,"\nENTER A KEY TO GO BACK 2 MENU");
 getch();
 rp:

 }

void star()
{randomize();
for(int i=0;i<2000;i++)
putpixel(random(640),random(480),50);}
void main()
{int a=DETECT,b;
initgraph(&a,&b,"");
setcolor(4);
settextstyle(1,0,5);
delay(2000);
outtextxy(90,200,"P");sound(256);delay(200);nosound();
outtextxy(90,200,"PR");sound(288);delay(200);nosound();
outtextxy(90,200,"PRE");sound(320);delay(200);nosound();
outtextxy(90,200,"PRES");sound(342);delay(200);nosound();
outtextxy(90,200,"PRESE");sound(384);delay(200);nosound();
outtextxy(90,200,"PRESEN");sound(426);delay(200);nosound();
outtextxy(90,200,"PRESENT");sound(480);delay(200);nosound();
outtextxy(90,200,"PRESENTI");sound(512);delay(200);nosound();
outtextxy(90,200,"PRESENTIN");sound(480);delay(200);nosound();
outtextxy(90,200,"PRESENTING ");sound(426);delay(200);nosound();
outtextxy(90,200,"PRESENTING T");sound(384);delay(200);nosound();
outtextxy(90,200,"PRESENTING TO ");sound(342);delay(200);nosound();
outtextxy(90,200,"PRESENTING TO Y");sound(320);delay(200);nosound();
outtextxy(90,200,"PRESENTING TO YO");sound(288);delay(200);nosound();
outtextxy(90,200,"PRESENTING TO YOU");sound(256);delay(1000);nosound();
cleardevice();
 for(int i =3,j=220;i<=8;j-=30,i++)
{setcolor(i);
 settextstyle(4,0,i);
 outtextxy(j,180,"TIC TAC TOE");
 delay(250);
 cleardevice();
}
star();
for(i =8;i>=0;i--)
{ setcolor(i);
 settextstyle(4,0,8);
 outtextxy(40,180,"TIC TAC TOE");
 delay(200);
}
cleardevice();
setcolor(4);
settextstyle(4,0,8);
outtextxy(180,120,"Z");
outtextxy(186,137,"Z");
settextstyle(4,0,5);
outtextxy(240,180,"SOFTWARES");
setcolor(14);
settextstyle(1,0,4);
outtextxy(100,240,"PUT YOUR CAPSLOCK ON!!!");
setcolor(7);
settextstyle(1,0,4);
outtextxy(220,300,"LOADING...");
  delay(100);
  settextstyle(1,0,4);
  for(i=100;i<500;i++)
  {outtextxy(i,340,"|");
  delay(6);}
  getch();


menu:
cleardevice();
setcolor(50);
settextstyle(1,0,6);
for(i=0;i<=250;i+=3)
{cleardevice();
outtextxy(i,20,"MENU");
delay(7);
}
settextstyle(1,0,4);
setcolor(4);outtextxy(10,150,"1.");setcolor(50);outtextxy(40,150,"Play Game");
setcolor(4);outtextxy(10,200,"2.");setcolor(50);outtextxy(40,200,"Instructions");
setcolor(4);outtextxy(10,250,"3.");setcolor(50);outtextxy(40,250,"Exit");
settextstyle(1,0,3);
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t    ";
outtextxy(10,308,"Enter your choice:");
int opt;
cin>>opt;
if(opt==1)
{cleardevice();
play();
clrscr();
goto menu;}
else if(opt==2)
{cleardevice();
/*instruct();*/
clrscr();
goto menu;}
else if (opt==3)
{text();
exit(0);}
else
goto menu;
}
