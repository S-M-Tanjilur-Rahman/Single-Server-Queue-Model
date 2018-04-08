#include<graphics.h>
#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
double clck[10][2];
char dis[500];
int af=0;
double A[6];
double s[6];
double a[6];
double D[6];
double c[6];
int a1[6];
int a2[6];
queue <double> q;
queue <double> tq;
queue <double> sq;
double ghori=0;
int se=0;
double ma;
double TD=0;
double ND=1;
double aq=0;
double bq=0;
double na=0;
double da=0;
vector <double> bv;
vector <double> qv;
void sortclck()
{
    for(int i=0;i<9;i++)              /// n sonkhok element r jonno n-1 steps complete korte hobe SO 0 to n-2 = n-1
    {
        for(int j=0;j<9;j++)          /// j<n-1 or j<=n-2 CZ last index n-1 ekhon j<n nile a[n]<a[n+1] krle n-1+1=n hole n namer
                                    /// kono index nai so eta 1 ta error
        {
            if(clck[j][0]>clck[j+1][0])         /// (FOR ASCENDING ORDER)
            {
                double t1=clck[j][0];
                double t2=clck[j][1];
                clck[j][0]=clck[j+1][0];
                clck[j][1]=clck[j+1][1];
                clck[j+1][0]=t1;
                clck[j+1][1]=t2;
            }
        }
    }
}
void display(double f)
{
    int a,b,c,i,j,count=0;
    double g;
    a=(int)f;
    g=(f-a);
    g=g*100;
    g=g+.1;
    //printf("%lf\n",g);
    b=(int)g;
    //printf("%lf %d %d\n",f,a,b);
    if(a==0)
    {
        dis[0]='0';
        dis[1]='.';
        c=b;
        dis[3]=(c%10)+48;
        c=c/10;
        dis[2]=(c%10)+48;
        c=c/10;
        dis[4]='\0';
    }
    else
    {
        c=a;
        while(c!=0)
        {
            c=c/10;
            count++;
            //printf(" %d ",count);
        }
        c=a;
        for(i=count-1;i>=0;i--)
        {
            dis[i]=(c%10)+48;
            //printf("\n%c\n",dis[i]);
            c=c/10;
        }
        i=2;
        dis[count]='.';
        c=b;
        while(i!=0)
        {
            dis[count+i]=(c%10)+48;
            c=c/10;
            i--;
        }
        dis[count+3]='\0';
    }

}
void qd(int a)
{
    if(a==1)
    {
        tq=q;
        int i=125;
        while(!tq.empty())
        {
            double el=tq.front();
            display(el);
            outtextxy(388,i,dis);
            i=i+50;
            //cout<<el<<endl;
            tq.pop();
        }
    }
    else
    {
        tq=sq;
        int i=193;
        while(!tq.empty())
        {
            double el=tq.front();
            //

            display(el);
            circle(60,i,43);
            outtextxy(35,i-10,dis);
            i=i+102;
            //cout<<el<<endl;
            tq.pop();
        }
    }

}
void screen()
{

    setfillstyle(EMPTY_FILL,WHITE);
    bar3d(1,10,981,680,8,5);
    //rectangle(10,10,1330,680);
    line(120,10,120,680);
    setfillstyle(EMPTY_FILL,RED);
    setlinestyle(CENTER_LINE,1,1);
    bar3d(130,20,958,640,0,0);
    settextstyle(10,HORIZ_DIR,3);
    outtextxy(215,645,"Computer Representation");
    settextstyle(10,HORIZ_DIR,1);
    outtextxy(545,648,"(Press button 'a' for next step)");
    setlinestyle(CENTER_LINE,1,1);
    setfillstyle(DOTTED_LINE,RED);
    bar3d(570,20,570,640,0,0);
    bar3d(570,210,958,210,0,0);
    outtextxy(15,645,"System");
    settextstyle(9,HORIZ_DIR,1);
    outtextxy(290,50,"System State");
    settextstyle(9,HORIZ_DIR,1);
    outtextxy(670,230,"Statistical Counters");

    settextstyle(5,HORIZ_DIR,2);
    if(af==0)
    {
        outtextxy(2,20,"Initialization");
        outtextxy(25,40,"Time");
    }
    else if(af==1)
    {
        outtextxy(25,20,"Arrival");
        outtextxy(25,40,"Time");
    }
    else if(af==2)
    {
        outtextxy(20,20,"Departure");
        outtextxy(25,40,"Time");
    }
    setlinestyle(SOLID_LINE,1,1);
    setfillstyle(SOLID_LINE,RED);
    rectangle(7,70,107,130);
    rectangle(145,210,235,300);
    rectangle(250,210,350,300);
    rectangle(365,110,455,550);
    rectangle(470,210,560,300);
    line(365,160,455,160);
    line(365,210,455,210);
    line(365,260,455,260);
    line(365,310,455,310);
    line(365,360,455,360);
    line(365,410,455,410);
    line(365,460,455,460);
    line(365,510,455,510);
    rectangle(620,50,720,150);
    rectangle(820,50,920,170);
    line(820,110,920,110);
    rectangle(580,280,663,370);
    rectangle(673,280,758,370);
    rectangle(768,280,853,370);
    rectangle(863,280,948,370); ///END
    settextstyle(5,HORIZ_DIR,3);
    outtextxy(160,320,"Server");
    outtextxy(160,340,"Status");
    outtextxy(260,320,"Number");
    outtextxy(290,340,"in");
    outtextxy(275,360,"queue");
    outtextxy(315,570,"Times of arrival");
    outtextxy(470,320,"Time of");
    outtextxy(492,340,"last");
    outtextxy(485,360,"event");
    outtextxy(580,390,"Number");
    outtextxy(580,410,"Delayed");
    outtextxy(693,390,"Total");
    outtextxy(693,410,"Delay");
    outtextxy(788,390,"Area");
    outtextxy(788,410,"under");
    outtextxy(795,430,"q(t)");
    outtextxy(883,390,"Area");
    outtextxy(883,410,"under");
    outtextxy(890,430,"B(t)");
    outtextxy(640,170,"Clock");
    outtextxy(780,180,"Next Event List");
    outtextxy(790,70,"A");
    outtextxy(790,130,"D");
    settextstyle(8,HORIZ_DIR,1);
    display(ghori);
    outtextxy(645,90,dis);
    display(ghori);
    outtextxy(490,245,dis);
    outtextxy(32,90,dis);
    display(se);
    outtextxy(160,245,dis);
    if(af==0)
        outtextxy(600,315,dis);
    else
    {
        display(ND);
        outtextxy(600,315,dis);
    }
    display(TD);
    outtextxy(693,315,dis);
    display(aq);
    outtextxy(788,315,dis);
    display(bq);
    outtextxy(883,315,dis);
    display(q.size());
    outtextxy(270,245,dis);
    display(na);
    if(ghori>=ma)
        outtextxy(850,65,"MAX");
    else
        outtextxy(840,65,dis);
    display(da);
    if(se==0)
        outtextxy(840,125,"(1/0)");
    else
        outtextxy(840,125,dis);
    qd(1);
    qd(2);
    settextstyle(9,HORIZ_DIR,1);
    outtextxy(720,440+50,"Input Pairs:");
    settextstyle(5,HORIZ_DIR,3);
    outtextxy(590,470+70,"Ai :");
    outtextxy(590,500+70,"Si :");
    int i,j=65,k=60,l,j1=60,j2=60,k1=60;
    for(i=1;i<6;i++)
    {
        settextstyle(8,HORIZ_DIR,1);
        display(A[i]);
        outtextxy(590+j,540,dis);
        //for(l=1;l<6;l++)
            if(a1[i]==1)
            {
                line(585+j2,540,645+k1,555);
                //outtextxy(760+j,490,"X");
                j2=j2+60;
                k1=k1+60;
            }

        //for(l=1;l<6;l++)
        display(s[i]);
        outtextxy(590+j,570,dis);
            if(a2[i]==1)
            {
                line(585+j1,490+80,645+k,505+80);
                //outtextxy(760+j,520,"X");
                j1=j1+60;
                k=k+60;
            }

        j=j+60;
        //k=k+40;
    }
    /*double d=10;
    display(d);
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(805,55,dis);
    d=5.55;
    display(d);
    outtextxy(850,5,dis);*/
    //outtextxy(25,20,"Arrival");
        //outtextxy(25,40,"Time=");
    //af=1;

    //return 0;
}
int main()
{
    initwindow(1000,700,"Computer Representation");
    //screen();
    int i,j,k,w;
    printf("Press 1 for specific input\nPress 2 for random input\n");
    scanf("%d",&w);
    if(w==1)
    {
        for(i=1;i<6;i++)
        {
            printf("Enter inter arrival & Service time respectively for customer %d:\n",i);
            scanf("%lf%lf",&A[i],&s[i]);
            a1[i]=0;
            a2[i]=0;
        }
    }
    else
    {
        for(i=1;i<6;i++)
        {
            A[i]=rand()%5+(rand()%100)/100.0;
            s[i]=rand()%5+(rand()%100)/100.0;
            if(A[i]==0)
                A[i]=1;
            if(s[i]==0)
                s[i]=1;
            a1[i]=0;
            a2[i]=0;
        }
    }
    a[1]=A[1];
    D[1]=0;
    c[1]=a[1]+D[1]+s[1];
    for(i=2;i<6;i++)
    {
        a[i]=a[i-1]+A[i];
        D[i]=c[i-1]-a[i];
        if(D[i]<0)
            D[i]=0;
        c[i]=a[i]+D[i]+s[i];
    }
    for(i=0;i<5;i++)
    {
        clck[i][0]=a[i+1];
        clck[i][1]=1;
    }
    for(i=5;i<10;i++)
    {
        clck[i][0]=c[i-4];
        clck[i][1]=2;
    }
    sortclck();
    for(i=1;i<6;i++)
    {
        printf("a[%d]=%lf\n",i,a[i]);
        printf("D[%d]=%lf\n",i,D[i]);
        printf("c[%d]=%lf\n",i,c[i]);
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<2;j++)
            printf("clck[%d][%d]=%lf ",i,j,clck[i][j]);
        printf("\n");
    }
    ma=a[5];
    /*q.push(5.6);
    q.push(7.63);
    sq.push(7.63);
    sq.push(7.95);
    sq.push(7.95);
    sq.push(7.95);
    sq.push(7.95);*/
    if(clck[0][0]==0.0)
    {
        a1[0]=1;
        se=1;
        af=1;
        sq.push(0);
        for(i=0;i<10;i++)
        {
            if(clck[i][1]==1.0)
            {
                na=clck[i][0];
                break;
            }
        }
        for(i=0;i<10;i++)
        {
            if(clck[i][1]==2.0)
            {
                da=clck[i][0];
                break;
            }
        }
        bv.push_back(0.0);
        screen();
        printf("\n\n Go to the popped up GUI for checking the simulation\n\n");
    }
    else
    {
        for(i=0;i<10;i++)
        {
            if(clck[i][1]==1.0)
            {
                na=clck[i][0];
                break;
            }
        }
        screen();
        printf("\n\n Go to the popped up GUI for checking the simulation\n\n");
    }
    int a1i;
    int a2i=1;
    if(se==0)
    {
        j=0;
        a1i=1;
    }
    else
    {
        j=1;
        a1i=2;
    }
    char ch;
    //scanf("%c",&ch);
    //getchar();
    int yt=0;
    int t=10;

    while(1)
    {
        //scanf("%d",&ch);
        //getchar();
        ch=getch();
        if(ch=='a')
        {

            if(clck[j][1]==1&&j<10)
            {
                a1[a1i++]=1;
                af=1;

                if(j!=0)
                {
                    aq=aq+((clck[j][0]-clck[j-1][0])*q.size());
                }
                if(j!=0&&se==1)
                {
                    bq=bq+(clck[j][0]-clck[j-1][0]);
                }

                if(se!=0)
                    {

//                        qv.push_back(clck[j][0]);
//                        if(qv.size()==2)
//                        {
//                            aq=aq+
//                        }
                        q.push(clck[j][0]);
                    }
                if(se==0)
                {
                    se=1;
                    //ND++;
                }

                sq.push(clck[j][0]);
                ghori=clck[j][0];
                for(int i=j+1;i<10;i++)
                {
                    if(clck[i][1]==1.0)
                    {
                        na=clck[i][0];
                        break;
                    }
                }
                for(int i=j+1;i<10;i++)
                {
                    if(clck[i][1]==2.0)
                    {
                        da=clck[i][0];
                        break;
                    }
                }
                //int t=ND;
                TD=0;
                for(i=1;i<=ND;i++)
                    TD=TD+D[i];
                /*bv.push_back(ghori);
                if(bv.size==2)
                {
                    bq=bq+bv[1]-bv[0];
                    bv.erase(bv.begin());
                    //bv.erase(bv.begin()+1);
                }*/
                cleardevice();
                screen();
            }
            else if(clck[j][1]==2&&j<10)
            {
                a2[a2i++]=1;
                af=2;
                if(j!=0)
                {
                    aq=aq+((clck[j][0]-clck[j-1][0])*q.size());
                }
                if(j!=0&&se==1)
                {
                    bq=bq+(clck[j][0]-clck[j-1][0]);
                }
                sq.pop();
                if(q.size()!=0)
                    q.pop();
                if(sq.size()!=0)
                    ND++;
                ghori=clck[j][0];
                if(q.size()==0&&c[(int)ND]==ghori)
                    se=0;
                else
                    se=1;
                TD=0;
                for(int e=1;e<=ND;e++)
                    TD=TD+D[e];
                for(int e=j+1;e<10;e++)
                {
                    if(clck[e][1]==1.0)
                    {
                        na=clck[e][0];
                        break;
                    }
                }
                for(int e=j+1;e<10;e++)
                {
                    if(clck[e][1]==2.0)
                    {
                        da=clck[e][0];
                        break;
                    }
                }
                cleardevice();
                screen();
                if(sq.size()==0)
                    ND++;

            }
        //}
            //cleardevice();
            //circle(400,200+r,50);
            //screen();
            //delay(1000);
            //cleardevice();
            j++;
            if(j==11)
            {
                cleardevice();
                outtextxy(360,250,"PERFORMANCE MEASUREMENT");
                outtextxy(330,300,"Average delay in Queue = ");
                display(TD/5);
                outtextxy(598,300,dis);
                outtextxy(288,350,"Time average number in queue = ");
                display(aq/clck[9][0]);
                outtextxy(623,350,dis);
                outtextxy(350,400,"Server Utilization = ");
                display(bq/clck[9][0]);
                outtextxy(570,400,dis);
            }
            if(j==11)
                break;
        }

    }
    /*while(yt!=4)
    {
        scanf("%c",&ch);
        getchar();
        if(ch=='a')
        {
            printf("HELOO\n");
            se=20;
            cleardevice();
            delay(1000);
            screen();
        }



        yt++;
    }*/
    //screen();
    /*delay(1000);
    cleardevice();
    af++;
    screen();
    delay(1000);
    cleardevice();
    af++;
    screen();*/
    getch();
    closegraph();
    return 0;
}
