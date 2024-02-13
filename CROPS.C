#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
union REGS in,out;
int i,x,y,click,selected,selected2,selected4,summer,winter,count=0;
char create_temp[5],create_moisture[5];
int create_name_int,temp_int,moisture_int,xcor,ycor;
char create_name[40],str[60],str1[60];
char desc[10],c;
int season_done=0,name_done=0,temp_done=0,moisture_done=0;
int new_prof,quit=1,t=0;

struct profile_detail{
	char profile_name[40];
	int profile_temp;
	int profile_season;
	int profile_moisture;
	}prof[20],rof,gof;

struct crop_detail{
	char name[20];
	char description[400];
	int starttemp;
	int endtemp;
	int starthumid;
	int endhumid;
	int season;
	}cro[20],crot;

void create_pointer();
void hide_pointer();
void mouse_location();
void main_menu();
void create_profile();
void load_profile();
void help();
void crop();
void des();
void setmouse(int,int);
void main(){

	int cp_load,i;
	FILE *p;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\bgi");
	create_pointer();
	switchcase:
	main_menu();
	switch(selected){
		case 1:
			new_prof=0;
			summer=0;
			winter=0;
			create_profile();
			season_done=0;
			name_done=0;
			temp_done=0;
			moisture_done=0;
			if(new_prof==0){
				goto switchcase;
				}
			strcpy(prof[count-1].profile_name,create_name);
			prof[count-1].profile_temp=temp_int;
			prof[count-1].profile_moisture=moisture_int;
				if(summer==1){
					prof[count-1].profile_season=1;
				}
				if(winter==1){
					prof[count-1].profile_season=2;
					}
			goto switchcase;


		case 2:
			p=fopen("TOTALPRO.txt","r");
			fscanf(p,"%d",&cp_load);
			rewind(p);
			fclose(p);
				if(cp_load>4){
				p=fopen("PROFILE.txt","w");
				rewind(p);
				fclose(p);
				p=fopen("TOTALPRO.txt","w");
				rewind(p);
				fprintf(p,"%d",quit);
				fclose(p);
				 }

			if(new_prof==1){
			p=fopen("PROFILE.txt","ab");
			fwrite(&prof,sizeof(struct profile_detail),count,p);
			fclose(p);
			count=0;
			}
			load_profile();
			if(selected2==0){
				goto pass;
				}
			hide_pointer();
			cleardevice();
			setbkcolor(LIGHTCYAN);
			create_pointer();

			pass:
			switch(selected2){
				case 1:
					p=fopen("PROFILE.txt","rb");
					fread(&gof,sizeof(struct profile_detail),1,p);
					fclose(p);
					crop();
					goto switchcase;

				case 2:
					p=fopen("PROFILE.txt","rb");
					for(i=0;i<2;i++){
					fread(&gof,sizeof(struct profile_detail),1,p);
					}
					fclose(p);
					crop();

					goto switchcase;
				case 3:
					p=fopen("PROFILE.txt","rb");
					for(i=0;i<3;i++){
					fread(&gof,sizeof(struct profile_detail),1,p);
					}
					fclose(p);
					crop();

					goto switchcase;
				case 4:
					p=fopen("PROFILE.txt","rb");
					for(i=0;i<4;i++){
					fread(&gof,sizeof(struct profile_detail),1,p);
					}
					fclose(p);
					crop();

					goto switchcase;
				case 5:
					p=fopen("PROFILE.txt","rb");
					for(i=0;i<5;i++){
					fread(&gof,sizeof(struct profile_detail),1,p);
					}
					fclose(p);
					crop();

					goto switchcase;

				case 0:
					goto switchcase;
				}

			break;
		case 3:
			help();
			goto switchcase;

		case 0:
			goto exit;

		default:
			break;
		    }
	exit:
	closegraph();
	printf("\n\n\n\n\n\n\n\n\t\t\tTHANK YOU FOR USING KHWOPA CROP WIKI\n\n\n\t\t\t\tCreated by:\n\t\t\t\tBijay\n\t\t\t\tJenish\n\t\t\t\tPrajwal\n\t\t\t\tShopnil");
	delay(3000);
	}

void create_pointer(){
		in.x.ax=1;
		int86(0x33,&in,&out);
		}

void hide_pointer(){
		in.x.ax=2;
		int86(0x33,&in,&out);
		}
void setmouse(int a,int b){
		in.x.ax=4;
		in.x.cx=a;
		in.x.dx=b;
		int86(0x33,&in,&out);
		}

void main_menu(){
	hide_pointer();
	setlinestyle(SOLID_LINE,0,1);
	rectangle(10,10,627,470);
	settextstyle(DEFAULT_FONT, HORIZ_DIR,3);
	outtextxy(140,70,"KHWOPA CROP WIKI");
	settextstyle(SMALL_FONT,HORIZ_DIR,7);
	rectangle(225,200,400,225);
	outtextxy(230,200,"CREATE PROFILE");
	rectangle(225,240,400,265);
	outtextxy(240,240,"LOAD PROFILE");
	rectangle(225,280,400,305);
	outtextxy(290,280,"HELP");
	rectangle(225,320,400,345);
	outtextxy(290,320,"EXIT");
	create_pointer();
	end:
	      while(!kbhit()){
		mouse_location();
		if(x>225 && x<400 && y>280 && y<305){
			setlinestyle(SOLID_LINE,0,3);
			setcolor(RED);
			rectangle(223,277,403,308);
			if(click==1){
				selected=3;
				goto re;
				}
			}
		else if(x>225 && x<400 && y>200 && y<225){
			setlinestyle(SOLID_LINE,0,3);
			setcolor(RED);
			rectangle(223,197,403,228);
			if(click==1){
				selected=1;
				goto re;
				}

			}
		else if(x>225 && x<400 && y>240 && y<265){
			setlinestyle(SOLID_LINE,0,3);
			setcolor(RED);
			rectangle(223,237,403,268);
			if(click==1){
				selected=2;
				goto re;
				}
			}
		else if(x>225 && x<400 && y>320 && y<345){
			setlinestyle(SOLID_LINE,0,3);
			setcolor(RED);
			rectangle(223,318,403,348);
			if(click==1){
				selected=0;
				goto re;
				}
			 }
		else{
			setlinestyle(SOLID_LINE,0,3);
			setcolor(BLACK);
			rectangle(223,277,403,308);
			rectangle(223,197,403,228);
			rectangle(223,237,403,268);
			rectangle(223,318,403,348);
		}
		}
		c=getch();
		goto end;
		re:
		hide_pointer();
		cleardevice();
		setbkcolor(11);
		create_pointer();

  }
void mouse_location(){

	in.x.ax=3;
	int86(0x33,&in,&out);
	x=out.x.cx;
	y=out.x.dx;
	click=out.x.bx;
	}

void create_profile(){
		int total;
		FILE *p;
		p=fopen("TOTALPRO.txt","r+");
		fscanf(p,"%d",&total);
		rewind(p);
		hide_pointer();
		setlinestyle(SOLID_LINE,0,1);
		rectangle(10,10,627,470);
		setfillstyle(SOLID_FILL,BLUE);
		bar(20,20,60,40);

		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		setcolor(8);
		outtextxy(110,70,"CREATE NEW PROFILE");
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		setcolor(15);
		outtextxy(25,23,"BACK");
		setcolor(8);
		outtextxy(100,200,"ENTER NAME : ");
		outtextxy(100,230,"FIELD TEMP :");
		outtextxy(100,260,"SEASON     : ");
		outtextxy(100,290,"MOISTURE   : ");
		setcolor(15);
		setfillstyle(SOLID_FILL,15);
		rectangle(200,200,500,215);
		floodfill(300,210,15);
		setfillstyle(SOLID_FILL,15);
		rectangle(200,230,300,245);
		floodfill(220,235,15);
		setfillstyle(SOLID_FILL,15);
		rectangle(200,290,300,305);
		floodfill(250,295,15);
		setcolor(8);
		rectangle(265,260,280,275);
		rectangle(355,260,370,275);
		setcolor(4);
		outtextxy(210,260,"Summer");
		outtextxy(300,260,"Winter");


		create_pointer();
		setmouse(330,230);
		create:
		while(!kbhit()){
			mouse_location();

			if(x>265 && x<280 && y>260 && y<275){
				if(click==1){
					hide_pointer();
					setcolor(DARKGRAY);
					rectangle(267,262,278,273);
					floodfill(269,266,DARKGRAY);
					setcolor(LIGHTCYAN);
					rectangle(357,262,368,273);
					floodfill(360,270,LIGHTCYAN);
					create_pointer();
					summer=1;
					winter=0;
					season_done=1;

					}
				   }
			else if(x>355 && x<370 && y>260 && y<275){
				if(click==1){
					hide_pointer();
					setcolor(LIGHTCYAN);
					rectangle(267,262,278,273);
					floodfill(269,266,LIGHTCYAN);
					setcolor(DARKGRAY);
					rectangle(357,262,368,273);
					floodfill(360,270,DARKGRAY);
					create_pointer();
					winter=1;
					summer=0;
					season_done=1;

					}

				   }
			else if(x>200 && x<500 && y>200 && y<215){
				if(click==1){
					hide_pointer();
					setcolor(15);
					bar(200,200,500,215);
					xcor=200;
					ycor=200;
					for(i=0;i<40;i++){
						choose_name:
						create_name[i]=getch();
						create_name_int=create_name[i];

						if(create_name_int==8){
							if(i==0){
								goto choose_name;
								}
							i=i--;
							if(xcor>200){
								xcor=xcor-7;
								bar(xcor,200,xcor+7,215);
								   }
							goto choose_name;
							}
						if(create_name_int==13){
							create_name[i]='\0';
							goto text1;
							}
						sprintf(str,"%c",create_name[i]);
						setcolor(4);
						outtextxy(xcor,ycor,str);
						xcor+=7;
						}
				text1:
				create_pointer();
				name_done=1;

				goto create;
				}
				}
			else if(x>200 && x<300 && y>230 && y<245){
				if(click==1){
					hide_pointer();
					setcolor(15);
					bar(200,230,300,245);
					xcor=200;
					ycor=230;
						for(i=0;i<6;i++){
						       choose_temp:
						       create_temp[i]=getch();
						       temp_int=create_temp[i];
							if(temp_int==8){
							if(i==0){
								goto choose_temp;
								}
							i=i--;
							if(xcor>200){
								xcor=xcor-7;
								bar(xcor,230,xcor+7,245);
								   }
							goto choose_temp;
							}
						if(temp_int==13){
							create_temp[i]='\0';
							goto text2;
							}
							sprintf(str,"%c",create_temp[i]);
							setcolor(4);
							outtextxy(xcor,ycor,str);
							xcor+=7;

						}
				text2:
				 create_pointer();
				 temp_int=atoi(create_temp);
				 temp_done=1;
				 goto create;
				 }
				}
			else if(x>200 && x<300 && y>290 && y<305){
				if(click==1){
					hide_pointer();
					setcolor(15);
					bar(200,290,300,305);
					xcor=200;
					ycor=290;
						for(i=0;i<6;i++){
						       choose_moisture:
						       create_moisture[i]=getch();
						       moisture_int=create_moisture[i];
							if(moisture_int==8){
							if(i==0){
								goto choose_moisture;
								}
							i=i--;
							if(xcor>200){
								xcor=xcor-7;
								bar(xcor,290,xcor+7,305);
								   }
							goto choose_moisture;
							}
						if(moisture_int==13){
							create_moisture[i]='\0';
							goto text3;
							}
							sprintf(str,"%c",create_moisture[i]);
							setcolor(4);
							outtextxy(xcor,ycor,str);
							xcor+=7;

						}
				 text3:
				 create_pointer();
				 moisture_int=atoi(create_moisture);
				 moisture_done=1;

				goto create;
				}
				}
			else if(x>20 && x<60 && y>20 && y<40){
					setcolor(RED);
					rectangle(18,18,62,42);
					if(click==1){
						goto back;
						}


				}

			      else if(season_done==1 && name_done==1 && temp_done==1 && moisture_done==1){
				   goto save_button;
				}
				else{
					setcolor(11);
					rectangle(18,18,62,42);
					goto create;
					}

			}
		c=getch();
		goto create;
		save_button:
		       setcolor(DARKGRAY);
		       setfillstyle(1,BLUE);
		       rectangle(280,350,400,390);
		       floodfill(340,370,DARKGRAY);
			settextstyle(DEFAULT_FONT,0,2);
			setcolor(15);
			outtextxy(310,363,"SAVE");
			again:
			while(!kbhit()){
				mouse_location();
				if(x>280 && x<400 && y>350 && y<390){
					setcolor(RED);
					rectangle(278,348,402,392);
					if(click==1){
						goto exit1;
						}
					}
				  else if(x>20 && x<60 && y>20 && y<40){
					setcolor(RED);
					rectangle(18,18,62,42);
					if(click==1){
						goto back;
						}
						}
				else{

					setcolor(11);
					rectangle(18,18,62,42);
					rectangle(278,348,402,392);
					}
				}
			c=getch();
		       goto again;
		       exit1:
		       total++;
		       fprintf(p,"%d",total);
		       count++;
		       new_prof=1;
		       back:
		       fclose(p);
		       hide_pointer();
		       cleardevice();
		       setbkcolor(0);
		       create_pointer();
		       setcolor(15);

		}



void load_profile(){
		int total,i,xaxis=150,yaxis=80;
		FILE *p;
		hide_pointer();
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,0,1);
		rectangle(10,10,627,470);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
		outtextxy(140,25,"SELECT PROFILE");
		p=fopen("TOTALPRO.txt","r");
		fscanf(p,"%d",&total);
		fclose(p);
		for(i=0;i<total;i++){
			setfillstyle(SOLID_FILL,DARKGRAY);
			bar(xaxis,yaxis,xaxis+300,yaxis+20);
			yaxis+=40;
			}
		yaxis=80;
		setfillstyle(SOLID_FILL,BLUE);
		bar(250,420,350,450);
		setcolor(WHITE);
		outtextxy(255,425,"BACK");
		p=fopen("PROFILE.txt","rb");
		for(i=0;i<total;i++){
			setcolor(WHITE);
			settextstyle(SMALL_FONT,HORIZ_DIR,6);
			fread(&rof,sizeof(struct profile_detail),1,p);
			sprintf(str,"%s",rof.profile_name);
			outtextxy(xaxis+90,yaxis,str);
			yaxis+=40;
			}
		fclose(p);
		create_pointer();
		re:
		while(!kbhit()){
		mouse_location();
				if(x>150 && x<450 && y>80 && y<100 && total>0){
					setlinestyle(SOLID_LINE,0,DARKGRAY);
					setcolor(DARKGRAY);
					rectangle(148,78,452,102);
					if(click==1){
						selected2=1;
						goto exit;
						}
					}
			else if(x>150 && x<450 && y>120 && y<140 && total>1){
					setlinestyle(SOLID_LINE,0,DARKGRAY);
					setcolor(DARKGRAY);
					rectangle(148,118,452,142);

					if(click==1){
						selected2=2;
						goto exit;
						}
					}

			else if(x>150 && x<450 && y>160 && y<180 && total>2){
					setlinestyle(SOLID_LINE,0,DARKGRAY);
					setcolor(DARKGRAY);
					rectangle(148,158,452,182);

					if(click==1){
						selected2=3;
						goto exit;
						}
					}
			else if(x>150 && x<450 && y>200 && y<220 && total>3){
					setlinestyle(SOLID_LINE,0,DARKGRAY);
					setcolor(DARKGRAY);
					rectangle(148,198,452,222);

					if(click==1){
						selected2=4;
						goto exit;
						}
					}


			else if(x>250 && x<350 && y>420 && y<450){
					setlinestyle(SOLID_LINE,0,DARKGRAY);
					setcolor(DARKGRAY);
					rectangle(248,418,352,452);
					if(click==1){
						selected2=0;
						goto exit;
						}
					}

			else{
					setcolor(LIGHTCYAN);
					setlinestyle(SOLID_LINE,0,LIGHTCYAN);
					rectangle(148,78,452,102);
					rectangle(148,118,452,142);
					rectangle(148,158,452,182);
					rectangle(148,198,452,222);
					rectangle(248,418,352,452);
					}
				 }
		c=getch();
		goto re;
		exit:
		hide_pointer();
		cleardevice();
		setbkcolor(0);
		setcolor(15);
		create_pointer();

}

void help(){
		hide_pointer();
		cleardevice();
		setbkcolor(LIGHTCYAN);
		setcolor(DARKGRAY);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(90,70,"1.CLICK CREATE PROFILE TO SETUP A NEW PROFILE");
		outtextxy(90,90,"2.ENTER PROFILE NAME AND INFORMATION OF YOUR FIELD");
		outtextxy(90,110,"3.LOAD PROFILE TO VIEW THE CROPSUGGESTION");
		outtextxy(90,130,"4.CLICK ON THE CROP NAMES TO VIEW WIKI");
		outtextxy(120,160,"NOTE: YOU MAY ONLY SAVE UPTO 4 PROFILES CREATING");
		outtextxy(170,170,"MORE WILL DELETE THE PREVIOUS PROFILES");
		settextstyle(SMALL_FONT,HORIZ_DIR,5);
		outtextxy(220,400,"Press any key to exit...");
		getch();
		cleardevice();
		setbkcolor(BLACK);
		setcolor(15);
		create_pointer();

}

void crop(){
		int i,xa=0,xcus=280,ycus=63;
		FILE *p;
		hide_pointer();
		rewind:
			xa=0;
			xcus=280;
			ycus=63;
		p=fopen("CROPDA.txt","rb");
		while(!feof(p)){
		 fread(&crot,sizeof(struct crop_detail),1,p);
		 if(gof.profile_temp>=crot.starttemp && gof.profile_temp<=crot.endtemp && gof.profile_moisture>=crot.starthumid && gof.profile_moisture<=crot.endhumid && gof.profile_season==crot.season){
			cro[xa]=crot;
			xa++;
	       }
	       }
	       fclose(p);
	      setcolor(DARKGRAY);
	      settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	      outtextxy(250,20,"CROPS");
	      rectangle(220,10,400,50);
	      rectangle(10,60,630,410);
	      setfillstyle(SOLID_FILL,BLUE);
	      bar(240,430,400,470);
	      setcolor(15);
	      outtextxy(270,440,"BACK");

	      for(i=0;i<xa;i++){
			settextstyle(SMALL_FONT,HORIZ_DIR,5);
			setcolor(DARKGRAY);
			sprintf(str,"%s",cro[i].name);
			outtextxy(xcus,ycus,str);
			ycus+=21;
			}
	      create_pointer();
	      setmouse(300,60);
	      again2:
			while(!kbhit()){
				mouse_location();
				if(x>10 && x<630 && y>60 && y<80 && xa>0){
					setcolor(DARKGRAY);
					rectangle(12,62,628,78);
					if(click==1){
						selected4=0;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>81 && y<101 && xa>1){
					setcolor(DARKGRAY);
					rectangle(12,83,628,99);
					if(click==1){
						selected4=1;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>102 && y<122 && xa>2){
					setcolor(DARKGRAY);
					rectangle(12,104,628,120);
					if(click==1){
						selected4=2;
						goto exit4;
					}
				}
				else if(x>10 && x<630 && y>123 && y<143 && xa>3){
					setcolor(DARKGRAY);
					rectangle(12,125,628,141);
					if(click==1){
						selected4=3;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>144 && y<164 && xa>4){
					setcolor(DARKGRAY);
					rectangle(12,146,628,162);
					if(click==1){
						selected4=4;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>165 && y<185 && xa>5){
					setcolor(DARKGRAY);
					rectangle(12,167,628,183);
					if(click==1){
						selected4=5;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>186 && y<206 && xa>6){
					setcolor(DARKGRAY);
					rectangle(12,188,628,204);
					if(click==1){
						selected4=6;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>207 && y<227 && xa>7){
					setcolor(DARKGRAY);
					rectangle(12,209,628,225);
					if(click==1){
						selected4=7;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>228 && y<248 && xa>8){
					setcolor(DARKGRAY);
					rectangle(12,230,628,246);
					if(click==1){
						selected4=8;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>249 && y<269 && xa>9){
					setcolor(DARKGRAY);
					rectangle(12,251,628,267);
					if(click==1){
						selected4=9;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>270 && y<290 && xa>10){
					setcolor(DARKGRAY);
					rectangle(12,272,628,288);
					if(click==1){
						selected4=10;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>291 && y<311 && xa>11){
					setcolor(DARKGRAY);
					rectangle(12,293,628,309);
					if(click==1){
						selected4=11;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>312 && y<332 && xa>12){
					setcolor(DARKGRAY);
					rectangle(12,314,628,330);
					if(click==1){
						selected4=12;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>333 && y<353 && xa>13){
					setcolor(DARKGRAY);
					rectangle(12,335,628,351);
					if(click==1){
						selected4=13;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>354 && y<374 && xa>14){
					setcolor(DARKGRAY);
					rectangle(12,356,628,372);
					if(click==1){
						selected4=14;
						goto exit4;
						}
				}
				else if(x>10 && x<630 && y>375 && y<395 && xa>15){
					setcolor(DARKGRAY);
					rectangle(12,377,628,393);
					if(click==1){
						selected4=15;
						goto exit4;
						}
				}


				else if(x>240 && x<430 && y>410 && y<470){
					setcolor(DARKGRAY);
					rectangle(238,428,402,472);
					if(click==1){
							goto ended;
							}
						    }
				else{
					setcolor(LIGHTCYAN);
					rectangle(12,62,628,78);
					rectangle(12,83,628,99);
					rectangle(12,104,628,120);
					rectangle(12,125,628,141);
					rectangle(12,146,628,162);
					rectangle(12,167,628,183);
					rectangle(12,188,628,204);
					rectangle(12,209,628,225);
					rectangle(12,230,628,246);
					rectangle(12,251,628,267);
					rectangle(12,272,628,288);
					rectangle(12,293,628,309);
					rectangle(12,314,628,330);
					rectangle(12,335,628,351);
					rectangle(12,356,628,372);
					rectangle(12,377,628,393);
					rectangle(238,428,402,472);
				     }

				 }
	c=getch();
	goto again2;
	exit4:
	hide_pointer();
	des();
	goto rewind;
	ended:
	hide_pointer();
	cleardevice();
	setbkcolor(0);
	setcolor(15);
	create_pointer();

}

void des(){
		int yaxs=170;
		FILE *p;
	      cleardevice();
	      setbkcolor(LIGHTCYAN);
	      setcolor(DARKGRAY);
	      setfillstyle(SOLID_FILL,BLUE);
	      bar(520,430,590,460);
	      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	      setcolor(WHITE);
	      outtextxy(525,440,"BACK");
	      setcolor(DARKGRAY);
	      settextstyle(SMALL_FONT,HORIZ_DIR,6);
	      outtextxy(170,30,"NAME       :");
	      outtextxy(170,50,"TEMP       :");
	      outtextxy(170,70,"MOISTURE   :");
	      outtextxy(170,90,"SEASON     :");
	      outtextxy(250,140,"DESCRIPTION");
	      sprintf(str,"%s",cro[selected4].name);
	      outtextxy(310,30,str);
	      itoa(cro[selected4].starttemp,desc,10);
	      sprintf(str,"%s",desc);
	      outtextxy(310,50,str);
	      outtextxy(330,50,"-");
	      itoa(cro[selected4].endtemp,desc,10);
	      sprintf(str,"%s",desc);
	      outtextxy(350,50,str);
	      itoa(cro[selected4].starthumid,desc,10);
	      sprintf(str,"%s",desc);
	      outtextxy(310,70,str);
	      outtextxy(330,70,"-");
	      itoa(cro[selected4].endhumid,desc,10);
	      sprintf(str,"%s",desc);
	      outtextxy(350,70,str);
	      if(cro[selected4].season==1){
		outtextxy(310,90,"SUMMER");
	      }
	      if(cro[selected4].season==2){
		outtextxy(310,90,"WINTER");
		}

	      p=fopen("DESCRI.txt","rb+");
	      fwrite(&cro[selected4].description,400,1,p);
	      rewind(p);
	      for(i=0;i<5;i++){
	      fread(&str1,60,1,p);
	      sprintf(str,"%s",str1);
	      outtextxy(25,yaxs,str);
	      yaxs+=20;
	      }
	      fclose(p);
		create_pointer();
		RE:
		while(!kbhit()){
			mouse_location();
				if(x>520 && x<590 && y>430 && y<460){
					setcolor(DARKGRAY);
					rectangle(518,428,592,462);
						if(click==1){
							goto endln;
							}
						}
				else{
					setcolor(LIGHTCYAN);
					rectangle(518,428,592,462);
					}
				}
		c=getch();
		goto RE;
		endln:
		hide_pointer();
		cleardevice();

}