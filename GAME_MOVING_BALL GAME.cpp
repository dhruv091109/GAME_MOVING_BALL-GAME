#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>

#define NUMBER 1
#define RADIUS 6
#define D 20

enum { Up, Left,Down,Right };
enum { LU,LD,RD,RU };
enum{ False, True };
class BALL
{
	public:
	float X,Y,Temp_X,Temp_Y,Move_X,Move_Y;
	int Wall,Direction,Color;
};
class BAT
{
	public:
	int Bat_X,Bat_Y,Temp_X,Temp_Y;
};
int Game_Over( int G )
{
			setfillstyle( 1,WHITE );
			bar( 0,0,640,480 );
			setcolor( RED );
			settextstyle( 1,0,6 );
			if( G==1 )
			outtextxy( 100,200,"LEFT PLAYER WIN");
			else if( G==0 )
			outtextxy( 100,200,"RIGHT PLAYER WIN");
			settextstyle( 4,0,6 );
			if( G==3 )
			{
				settextstyle( 3,0,6 );
				outtextxy( 180,200,"D H R U V");
			}
			sleep(5);
			getch();
	return 1;
}
int Loop=0,Num=NUMBER,Temp1=0,Temp2=0,Temp3,Temp4=1,Game=0,DELAY=D;
float Temp,R_X=0,R_Y=0;
int main()
{
	int Number_Of_Ball=NUMBER;
	void Make_Screen_For_First_Time(void);
	void Calculate_New_Position( BALL* );
	int Is_Collision_Occur( BALL* );
	void Calculation_Of_New_Direction( BALL* );
	void Calculation_Of_Direction( BALL* );
	void Erase_Ball( BALL* );
	void Display_Ball( BALL* );
	void Display_Bat( BAT* );
	void Erase_Bat( BAT* );
	void Randomaize( void );
	void Move_Bat( BAT* );
	int Game_Over( int );
	//void Put_Ball( int,int,int );
	BALL Ball[NUMBER],*Pointer;
	BAT Bat[2],*TPointer;
	Temp=(RADIUS*RADIUS)/2;
	Bat[0].Bat_X=630;
	Bat[0].Bat_Y=200;
	Bat[1].Bat_X=0;
	Bat[1].Bat_Y=200;
	Make_Screen_For_First_Time();
	for(R_X=0;R_X<2;R_X++)
	{
		TPointer=&Bat[R_X];
		Erase_Bat( TPointer);
		Display_Bat( TPointer);
	}
	for(Loop=0;Loop<NUMBER;Loop++)
	{
		//for( Num=0;Num<2;Num++ )
	   //	Randomaize();
		Pointer=&Ball[Loop];
		Ball[Loop].X=400;//60+(Temp1++)*(4*RADIUS);//((3*RADIUS)*R_X);
		if(Ball[Loop].X>580)
		{
			Temp1=0;
			Ball[Loop].X=60+(Temp1++)*(4*RADIUS);
			Temp2+=(3*RADIUS);
		}
		Ball[Loop].Y=300;//130+Temp2;//+Loop*(2*RADIUS);((3*RADIUS)*R_Y);
		Ball[Loop].Direction=random(5);//(Loop+1)%4;
		for( Num=0;Num<3;Num++ )
		Ball[Loop].Color=(Loop%14)+4;
		//Ball[Loop].Color=WHITE;
		Display_Ball( Pointer );
		Calculation_Of_Direction( Pointer );
	}
//	for(Loop=0;Loop<Num;Loop++)

	R_X=0;
	while( !Game )
	{
		Num=(Loop++)%Number_Of_Ball;
		if(Loop>=Number_Of_Ball*100)
		{
			Temp=Loop=0;
			if( DELAY>4 )
			DELAY--;
		}
		//if(Loop==2)
		Pointer=&Ball[Num];
		Calculate_New_Position( Pointer );
		Num=Is_Collision_Occur( Pointer );
		if(Num)
		{
			//Num=Is_Collision_Occur( Pointer );
			if( Num!=2 )
			Calculation_Of_New_Direction( Pointer );
			else
			Calculation_Of_Direction( Pointer );
		}
		Erase_Ball( Pointer );
		Display_Ball( Pointer );
		char Button=' ';
	  //	if( Loop%2==0 )
		{
			//Temp4++;
			if(Temp4)//%2)
			if( kbhit() )
			{
				Button=getch();
				if( Button== 27 )
				Game=Game_Over(3);
				else if( Button=='.')
				{
					TPointer=&Bat[0];
					Bat[0].Temp_X=Bat[0].Bat_X;
					Bat[0].Temp_Y=Bat[0].Bat_Y;
					Bat[0].Bat_Y+=20;
					if( Bat[0].Bat_Y+90>490 )
					Bat[0].Bat_Y-=20;
					Erase_Bat( TPointer);
					Display_Bat( TPointer);
				}
				else if( Button==';' )
				{
					TPointer=&Bat[0];
					Bat[0].Temp_X=Bat[0].Bat_X;
					Bat[0].Temp_Y=Bat[0].Bat_Y;
					Bat[0].Bat_Y-=20;
					if( Bat[0].Bat_Y<60 )
					Bat[0].Bat_Y+=20;
					Erase_Bat( TPointer);
					Display_Bat( TPointer);
				}
			}
			if(Temp4==0)//%2)-1)
			if( kbhit() )
			{
				Button=getch();
				if( Button=='z' )
				{
					TPointer=&Bat[1];
					Bat[1].Temp_X=Bat[1].Bat_X;
					Bat[1].Temp_Y=Bat[1].Bat_Y;
					Bat[1].Bat_Y+=20;
					if( Bat[1].Bat_Y+90>490 )
					Bat[1].Bat_Y-=20;
					Erase_Bat( TPointer);
					Display_Bat( TPointer);
				}
				else if( Button=='a' )
				{
					TPointer=&Bat[1];
					Bat[1].Temp_X=Bat[1].Bat_X;
					Bat[1].Temp_Y=Bat[1].Bat_Y;
					Bat[1].Bat_Y-=20;
					if( Bat[1].Bat_Y<60 )
					Bat[1].Bat_Y+=20;
					Erase_Bat( TPointer);
					Display_Bat( TPointer);
				}
			}
		}
		R_X++;
		if(R_X>NUMBER-1)
		{
			if(!random(5))
			{
				settextstyle(1,0,5);
				setcolor(random(15));
				outtextxy( 135,0,"DHRUV PRESENTS");
			}
			delay(DELAY);
			R_X=0;
		}
	}
	closegraph();
	return 1;
}
void Randomaize( void )
{
		R_X=random(640/(4*RADIUS));
		R_Y=random(480/(4*RADIUS));
		if( getpixel( 110+((3*RADIUS)*R_X),100+((3*RADIUS)*R_Y)==BLACK ) )
		return;
		  //	if( getpixel( 110+((3*RADIUS)*R_X)+RADIUS,100+((3*RADIUS)*R_Y)==BLACK ) )
			//	if( getpixel( 110+((3*RADIUS)*R_X),100+((3*RADIUS)*R_Y)+RADIUS==BLACK ) )
			  //		if( getpixel( 110+((3*RADIUS)*R_X)-RADIUS,100+((3*RADIUS)*R_Y)==BLACK ) )
				//		if( getpixel( 110+((3*RADIUS)*R_X),100+((3*RADIUS)*R_Y)-RADIUS==BLACK ) )

		Randomaize();
}
void Calculation_Of_Direction(BALL *Ball)
{
	if( Ball->Direction==LU )
	{
		Ball->Move_X=-2;
		Ball->Move_Y=-2;
		Temp4=0;
	}
	else if( Ball->Direction==LD )
	{
		Ball->Move_X=-2;
		Ball->Move_Y=2;
	   Temp4=0;
	}
	else if( Ball->Direction==RD )
	{
		Ball->Move_X=2;
		Ball->Move_Y=2;
		Temp4=1;
	}
	else if( Ball->Direction==RU )
	{
		Ball->Move_X=2;
		Ball->Move_Y=-2;
		Temp4=1;
	}
	//Ball->Move_X-=0.0001;
	//Ball->Move_X-=0.0001;
}
void Make_Screen_For_First_Time(void)
{
	int gd = DETECT, gm;
	initgraph( &gd, &gm,"c:\\tc\\bgi");
		setfillstyle( 1,BLACK );
	bar( 0,0,640,480 );
	setcolor( RED );
	settextstyle( 7,0,5 );
	outtextxy( 170,80,"ARCHENOID" );
	setcolor( WHITE );
	settextstyle( 3,0,2 );
	outtextxy( 220,50,"DHRUV PRESENTS" );
	settextstyle( 3,0,3 );
	setcolor( BLUE );
	outtextxy( 270,280,"-DHRUV RATHOD");
	outtextxy( 270,300,"ID-dhruvthenorthstar@yahoo.com\n");
	setcolor( GREEN );
	settextstyle( 1,0,1 );
	outtextxy( 10,200,"If you have better logic to put in this program which makes it" );
	outtextxy( 10,220,"better than before, please send me your advise about ");
	outtextxy( 10,240,"this program at my Id.");
	setcolor( YELLOW );
	settextstyle( 2,0,6);
	outtextxy( 10,380,"Key");
	outtextxy( 10,400,"LEFT PLAYER  A=UP,Z=DOWN    &   RIGHT PLAYER  ;=UP,  . =DOWN");
	outtextxy( 260,440,"LODING...");
	sleep(8);
	setfillstyle( 1,BLACK );
	bar( 240,440,350,480 );
	setcolor( YELLOW );
	while( !kbhit() )
	{
		outtextxy( 250,440,"press enter");
		setfillstyle( 1,BLACK );
		delay( 800 );
		bar( 240,440,400,480 );
		delay( 400 );
	}
	if( getch()=='\r')
	clrscr();
	setfillstyle( 1,WHITE );
	bar( 0,0,640,480 );
	setfillstyle( 1,BLACK );
	bar( 0,60,640,460 );
	bar( 10,10,630,50 );
	bar( 0,460,15,480 );
	bar( 630,460,640,480 );
	//setfillstyle( 1,WHITE );
	//bar( 320,100,330,300 );

	for(R_X=1;R_X<14;R_X++)
	{
		if(R_X==3)
		R_X=12;
		setfillstyle( 1,R_X+1 );
		setcolor( R_X+1 );
		pieslice( 30+( R_X*40 ),30,0,360,20 );
		setfillstyle( 1,WHITE );
		pieslice( 30+( R_X*40 )+(20/3),30+(20/3),0,360,20/3 );
	}
	/*setfillstyle( 1,WHITE );
	bar( 10,220,100,250 );
	*/
	//setfillstyle( 1,WHITE );
	bar( 300,340,330,470 );
}
void Display_Bat( BAT *Bat )
{
	setfillstyle( 1,GREEN );
	bar( Bat->Bat_X,Bat->Bat_Y,Bat->Bat_X+15,Bat->Bat_Y+90 );
}
void Erase_Bat( BAT *Bat )
{
	setfillstyle( 1,BLACK );
	bar( Bat->Temp_X,Bat->Temp_Y,Bat->Temp_X+15,Bat->Temp_Y+90 );
}
void Calculate_New_Position( BALL *Ball )
{
	Ball->Temp_X=Ball->X;
	Ball->Temp_Y=Ball->Y;
	Ball->X+=Ball->Move_X;
	Ball->Y+=Ball->Move_Y;
}
int Is_Collision_Occur( BALL *Ball )
{
	if(getpixel(Ball->X-(RADIUS+3),Ball->Y)!=Ball->Color && getpixel(Ball->X-(RADIUS+3),Ball->Y)!=BLACK )
	{
		Ball->Wall=Left;
		return 1;
	}
	else if( getpixel(Ball->X+(RADIUS+3),Ball->Y)!=Ball->Color && getpixel(Ball->X+(RADIUS+3),Ball->Y)!=BLACK )
	{
		Ball->Wall=Right;
		return 1;
	}
	else if( getpixel(Ball->X,Ball->Y-(RADIUS+3))!=Ball->Color && getpixel(Ball->X,Ball->Y-(RADIUS+3))!=BLACK )
	{
		Ball->Wall=Up;
		return 1;
	}
	else if( getpixel(Ball->X,Ball->Y+(RADIUS+3))!=Ball->Color && getpixel(Ball->X,Ball->Y+(RADIUS+3))!=BLACK )
	{
		Ball->Wall=Down;
		return 1;
	}
	else if( getpixel(Ball->X+(sqrt(Temp)+3),Ball->Y+(sqrt(Temp)+3))!=Ball->Color && getpixel(Ball->X+(sqrt(Temp)+3),Ball->Y+(sqrt(Temp)+3))!=BLACK )
	{
		//if( Ball->direction==LU||Ball->Direction==RD )
		Ball->Direction=LU;
		return 2;
	}
	else if( getpixel(Ball->X-(sqrt(Temp)+3),Ball->Y-(sqrt(Temp)+3))!=Ball->Color && getpixel(Ball->X-(sqrt(Temp)+3),Ball->Y-(sqrt(Temp)+3))!=BLACK )
	{
	   //	if( Ball->direction==LU||Ball->Direction==RD )
		Ball->Direction=RD;
		return 2;
	}
	else if( getpixel(Ball->X-(sqrt(Temp)+3),Ball->Y+(sqrt(Temp)+3))!=Ball->Color && getpixel(Ball->X-(sqrt(Temp)+3),Ball->Y+(sqrt(Temp)+3))!=BLACK )
	{
		//if( Ball->direction==LU||Ball->Direction==RD )
		Ball->Direction=RU;
		return 2;
	}
	else if( getpixel(Ball->X+(sqrt(Temp)+3),Ball->Y-(sqrt(Temp)+3))!=Ball->Color && getpixel(Ball->X+(sqrt(Temp)+3),Ball->Y-(sqrt(Temp)+3))!=BLACK )
	{
		//if( Ball->direction==LU||Ball->Direction==RD )
		Ball->Direction=LD;
		return 2;
	}
	return False;
}
void Calculation_Of_New_Direction( BALL *Ball )
{
	if( Ball->Direction==Ball->Wall )
	Ball->Direction=( Ball->Direction+1)%4;
	else
	{
		Ball->Direction--;
		if( Ball->Direction==-1)
		Ball->Direction=3;
	}
	if( Ball->Direction==LU )
	{
		Ball->Move_X=-2;
		Ball->Move_Y=-2;
		Temp4=0;
	}
	else if( Ball->Direction==LD )
	{
		Ball->Move_X=-2;
		Ball->Move_Y=2;
		Temp4=0;
	}
	else if( Ball->Direction==RD )
	{
		Ball->Move_X=2;
		Ball->Move_Y=2;
		Temp4=1;
	}
	else if( Ball->Direction==RU )
	{
		Ball->Move_X=2;
		Ball->Move_Y=-2;
		Temp4=1;
	}
	Ball->Move_X-=0.0001;
	Ball->Move_X-=0.0001;
}
void Display_Ball(BALL *Ball)
{
	setfillstyle( 1,Ball->Color );
	setcolor( Ball->Color );
	if( Ball->X>680 )
	Game=Game_Over( 1 );
	if( Ball->X<-20 )
	Game=Game_Over( 0 );
	pieslice( Ball->X,Ball->Y,0,360,RADIUS );
	setfillstyle( 1,WHITE );
	pieslice( Ball->X+(RADIUS/3),Ball->Y+(RADIUS/3),0,360,RADIUS/3 );
	/*if(Ball->Color==BROWN||Ball->Color==RED)
	{
		setcolor(10);
		settextstyle(2,0,RADIUS/4);
		outtextxy( Ball->X-(RADIUS/2),Ball->Y-(RADIUS/1.5),"D");
	} */
}
void Erase_Ball(BALL *Ball)
{
	setfillstyle( 1,BLACK );
	setcolor( BLACK );
	pieslice( Ball->Temp_X,Ball->Temp_Y,0,360,RADIUS );
}
