#include <SDL.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#define f first
#define s second
#define left left1
#define right right1
using namespace std;
SDL_Texture* background;
SDL_Texture* tau;
SDL_Texture* play1;
SDL_Texture* play2;
SDL_Texture* about1;
SDL_Texture* about2;
SDL_Texture* back1;
SDL_Texture* back2;
SDL_Texture* dan1;
SDL_Texture* chicken1;
SDL_Texture* chicken2;
SDL_Texture* chicken3;
SDL_Texture* egg;
SDL_Texture* trungvo;
SDL_Texture* smoke;
SDL_Texture* vuno;
SDL_Texture* upgrade1;
SDL_Texture* upgrade2;
SDL_Texture* mot;
SDL_Texture* hai;
SDL_Texture* ba;
SDL_Texture* bon;
SDL_Texture* nam;
SDL_Texture* quado1;
SDL_Texture* quado2;
SDL_Texture* quado3;
SDL_Texture* quado4;
SDL_Texture* dando;
SDL_Texture* thunder;
SDL_Texture* quatrang1;
SDL_Texture* quatrang2;
SDL_Texture* quatrang3;
SDL_Texture* quatrang4;
SDL_Texture* logo;
SDL_Texture* remuse1;
SDL_Texture* remuse2;
SDL_Texture* exit1;
SDL_Texture* exit2;
SDL_Texture* menu1;
SDL_Texture* menu2;
SDL_Texture* metalegg;
SDL_Texture* fullegg;
SDL_Texture* brokenegg;
SDL_Texture* quavang1;
SDL_Texture* quavang2;
SDL_Texture* quavang3;
SDL_Texture* quavang4;
SDL_Texture* laserboss;
SDL_Texture* end1;
SDL_Texture* end2;
SDL_Texture* backgroundend;
SDL_Texture* yes1;
SDL_Texture* yes2;
SDL_Texture* no1;
SDL_Texture* no2;
SDL_Texture* warning;
SDL_Texture* fork;
SDL_Texture* board;
SDL_Texture* heart;
SDL_Texture* phaohoa1;
SDL_Texture* phaohoa2;
SDL_Texture* phaohoa3;
SDL_Texture* phaohoa4;
SDL_Texture* phaohoa5;
SDL_Texture* thanhmau1;
SDL_Texture* thanhmau2;
SDL_Texture* aboutplay;
SDL_Texture* aboutpowerup;
SDL_Texture* aboutattack;
SDL_Texture* aboutesc;
SDL_Texture* aboutquado;
SDL_Texture* aboutquatrang;
SDL_Texture* aboutmove;
SDL_Texture* aboutquavang;
SDL_Renderer* renderer;
TTF_Font* font ;
Mix_Chunk *chickensound;
Mix_Chunk *gunsound;
Mix_Chunk *trungvosound;
Mix_Chunk *deadsound;
Mix_Chunk *blastersound;
Mix_Music *ost;
Mix_Music *musicboss;
Mix_Music *musicend;
Mix_Music *winsound;
SDL_Color textcolor ;
const double pi = M_PI;
bool quit = false ;
bool clickabout = false;
bool clickplay = false;
bool motionstart = false;
bool motionabout = false;
bool motionback = false;
bool bandan = false;
bool motionremuse = false;
bool motionexit = false;
bool motionmenu = false;
bool clickremuse = false;
bool motionremuse1 = false;
bool clickremuse1 = false;
bool clickexit= false;
bool clickmenu=false;
bool motionyes = false;
bool motionno = false;
bool clickyes = false;
bool clickno=false;

int time1 = 0 ;
int xbgr = 0 , ybgr = 0;
int sodan = 1;
int levelthunder = 70;
vector<pair<int,int>> bullet;
vector<pair<int,int>> bullettrai;
vector<pair<int,int>> bulletphai;
vector<pair<int,pair<int,int>>> info;
vector<pair<int,int>> vtlong;
vector<pair<int,int>> vtegg;
vector<pair<int,pair<int,int>>> vttrungvo;
vector<pair<int,pair<int,int>>> vtsmoke;
vector<pair<int,int>> vtupgrade;
vector<pair<int,pair<int,int>>> vtphaohoa;
pair<int,int> infoboss;
vector<pair<double,pair<double,double>>> skillboss;
int sizedanx , sizedany , sizegax , sizegay, sizetaux , sizetauy, sizeupx, sizeupy , sizequax, sizequay, sizebossx,sizebossy,sizedanbossx,sizedanbossy;
int live = 3 , disappear = 1;
int timeman3 = 0 ;
bool left = false , right = true;
SDL_Rect vtbackground;

void beforeinstart();
void instart();
void inabout();
void man1();
void man2();
void man3();
void man4();
void solvegame();
void inlive();
void inplay(int x,int y);
void gameover();
void inman();
void inscore();
void xulygachet( int i);
void resetall();
void inremuse();
void inexit();
void inmenu();
void xulyesc();
void timestop();
void xulidan();
void manboss();
void insavegame();
void savegame(fstream &inp, int issave);
void inthanhmau();
// man leveldan loaidan levelthunder live
// bug : endgame -> menu -> khong clear remuse
int sodancu=1,loaidancu=1,levelthundercu=70,livecu=3,scorecu = 0 ;
bool ktgiaonhau1(SDL_Rect rect1, double angle1, SDL_Rect rect2);
int score = 0 ;
int score1 = 0 ;
int man = 1 ;
int taux = 700, tauy=600;
int dead = 0;
int timeman = 200;
int timegame = 0;
int timegame1 = 0 ;
bool finishround[103];
int loaidan =1 ;
int hpboss = 2400;
int timeendgame = 0 ;
bool danthunder = false;
bool clickesc = false;
vector<pair<int,pair<int,int>>> skill;
vector<pair<int,pair<int,int>>> hopqua;
vector<pair<int,int>> sample;
pair<int,pair<int,int>> phaohoaboss;
int chieudai = 1920 , chieurong = 965;
int giatlen = 0 ;
int resetga = 0;
bool canremuse = true;
int beforestopx , beforestopy;
SDL_Surface* resize1(SDL_Surface* image, int w, int h) {
    SDL_Surface* sur = SDL_CreateRGBSurface(0, w, h, 32, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_BlitScaled(image, nullptr, sur, nullptr);
    return sur;
}

double tinhgoc(double x1, double y1, double x2, double y2) {
    double* dx = new double(x2 - x1);
    double* dy = new double(y2 - y1);
    double* rad = new double(atan2(*dy, *dx));
    double* res = new double(*rad * 180.0 / M_PI);
    if (*res < 0) {
        *res += 360;
    }
    *res += 90;
    if (*res >= 360) {
        *res -= 360;
    }
    delete dx;
    delete dy;
    delete rad;
    return *res;
}

bool ismanboss()
{
    for ( int i =0 ; i <= 4; i++)
        if ( finishround[i] == false ) return false;
    return true;
}

bool ktgiaonhau(int x, int y, int a,int b , int x1, int y1, int a1, int b1) {
    return !(x + a <= x1 ||x1 + a1 <= x ||y + b <= y1 || y1 + b1 <= y);
}
pair<int,pair<int,pair<int,int>>> blaster;
pair<int,pair<int,int>> ktra(int x,int y)
{
    pair<int,pair<int,int>> kq ;
    kq = {0,{x,0}};
    int *x1 = new int (x-sodan*10);
    int *x2 = new int (x+sodan*13);
    if ( sodan == 1 ) {
        *x1=(x-sodan*15);
        *x2=(x+sodan*30);
    }
    if ( sodan <= 2 ) *x1=(x-15),*x2=(x+30);
    else if ( sodan == 3 ) {
        *x1=x-20;
        *x2=x+35;
    }
    else {
        *x1=x-25;
        *x2=x+35;
    }
    int *gacon = new int(0) ;
    for ( int i = y ; i > 0 ; i--)
    {
        int *dem = new int(0) ;
        bool *checkk = new bool(false);
        for ( auto &u : info)
        {
            if ( ktgiaonhau(u.s.f,u.s.s,sizegax,sizegay,*x1-levelthunder/2+5*sodan,i,levelthunder-5*sodan,1) == true &&  ktgiaonhau(u.s.f,u.s.s,sizegax,sizegay,*x2-levelthunder/2+5*sodan,i,levelthunder-5*sodan,1) == true)
            {
                *checkk = true;
                kq = {*dem,{x,i-30}};
                *gacon = i ;
                break;
            }
            *dem=*dem+1;
        }
        delete dem;
        if ( *checkk == true ) {
            delete checkk;
            break;
        }
        delete checkk;
    }
    if ( ismanboss() == false ) {delete gacon;delete x1;delete x2;return kq;}
    for ( int i = y ; i > 0 ; i--)
    {
        if ( ktgiaonhau(infoboss.f,infoboss.s,sizebossx,sizebossy,*x1-levelthunder/2+5*sodan,i,levelthunder-5*sodan,1) == true && ktgiaonhau(infoboss.f,infoboss.s,sizebossx,sizebossy,*x2-levelthunder/2+5*sodan,i,levelthunder-5*sodan,1) == true)
        {
            if ( i > *gacon ) kq = {1000,{x,i-100}};
            break;
        }
    }
    delete gacon;delete x1,x2;
    return kq;

}
int main(int argc, char* argv[]) {


    TTF_Init();
    SDL_Init( SDL_INIT_EVERYTHING );
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    srand(time(0));
    SDL_Window* screen = NULL;
    screen = SDL_CreateWindow("Chicken Invaders",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, chieudai, chieurong, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    TTF_SetFontHinting(font, TTF_HINTING_NORMAL);

    SDL_Surface* image1 = IMG_Load("background.jpg");
    SDL_Surface* image2 = IMG_Load("tau.png");
    SDL_Surface* image3 = IMG_Load("play1.png");
    SDL_Surface* image4 = IMG_Load("play2.png");
    SDL_Surface* image5 = IMG_Load("about1.png");
    SDL_Surface* image6 = IMG_Load("about2.png");
    SDL_Surface* image7 = IMG_Load("back1.png");
    SDL_Surface* image8 = IMG_Load("back2.png");
    SDL_Surface* image9 = IMG_Load("dan.png");
    SDL_Surface* image10 = IMG_Load("chicken1.png");
    SDL_Surface* image12 = IMG_Load("egg.png");
    SDL_Surface* image13 = IMG_Load("trungvo.png");
    SDL_Surface* image14 = IMG_Load("smoke.png");
    SDL_Surface* image15 = IMG_Load("vuno.png");
    SDL_Surface* image16 = IMG_Load("chicken2.png");
    SDL_Surface* image17 = IMG_Load("chicken3.png");
    SDL_Surface* image18 = IMG_Load("upgrade1.png");
    SDL_Surface* image19 = IMG_Load("upgrade2.png");
    SDL_Surface* image20 = IMG_Load("mot.png");
    SDL_Surface* image21 = IMG_Load("hai.png");
    SDL_Surface* image22 = IMG_Load("ba.png");
    SDL_Surface* image23 = IMG_Load("bon.png");
    SDL_Surface* image24 = IMG_Load("nam.png");
    SDL_Surface* image25 = IMG_Load("quado1.png");
    SDL_Surface* image26 = IMG_Load("quado2.png");
    SDL_Surface* image27 = IMG_Load("quado3.png");
    SDL_Surface* image28 = IMG_Load("quado4.png");
    SDL_Surface* image29 = IMG_Load("dando.png");
    SDL_Surface* image30 = IMG_Load("thunder.png");
    SDL_Surface* image31 = IMG_Load("quatrang1.png");
    SDL_Surface* image32 = IMG_Load("quatrang2.png");
    SDL_Surface* image33 = IMG_Load("quatrang3.png");
    SDL_Surface* image34 = IMG_Load("quatrang4.png");
    SDL_Surface* image35 = IMG_Load("logo.png");
    SDL_Surface* image36 = IMG_Load("menu1.png");
    SDL_Surface* image37 = IMG_Load("menu2.png");
    SDL_Surface* image38 = IMG_Load("exit1.png");
    SDL_Surface* image39 = IMG_Load("exit2.png");
    SDL_Surface* image40 = IMG_Load("remuse1.png");
    SDL_Surface* image41 = IMG_Load("remuse2.png");
    SDL_Surface* image42 = IMG_Load("metalegg.png");
    SDL_Surface* image43 = IMG_Load("fullegg.png");
    SDL_Surface* image44 = IMG_Load("brokenegg.png");
    SDL_Surface* image45 = IMG_Load("quavang1.png");
    SDL_Surface* image46 = IMG_Load("quavang2.png");
    SDL_Surface* image47 = IMG_Load("quavang3.png");
    SDL_Surface* image48 = IMG_Load("quavang4.png");
    SDL_Surface* image49 = IMG_Load("laserboss.png");
    SDL_Surface* image50 = IMG_Load("end1.png");
    SDL_Surface* image51 = IMG_Load("end2.png");
    SDL_Surface* image52 = IMG_Load("backgroundend.png");
    SDL_Surface* image53 = IMG_Load("yes1.png");
    SDL_Surface* image54 = IMG_Load("yes2.png");
    SDL_Surface* image55 = IMG_Load("no1.png");
    SDL_Surface* image56 = IMG_Load("no2.png");
    SDL_Surface* image57 = IMG_Load("warning.png");
    SDL_Surface* image58 = IMG_Load("fork.png");
    SDL_Surface* image59 = IMG_Load("board.png");
    SDL_Surface* image60 = IMG_Load("heart.png");
    SDL_Surface* image61 = IMG_Load("phaohoa1.png");
    SDL_Surface* image62 = IMG_Load("phaohoa2.png");
    SDL_Surface* image63 = IMG_Load("phaohoa3.png");
    SDL_Surface* image64 = IMG_Load("phaohoa4.png");
    SDL_Surface* image65 = IMG_Load("phaohoa5.png");
    SDL_Surface* image67 = IMG_Load("thanhmau1.png");
    SDL_Surface* image68 = IMG_Load("thanhmau2.png");
    SDL_Surface* image69 = IMG_Load("aboutmove.png");
    SDL_Surface* image70 = IMG_Load("aboutattack.png");
    SDL_Surface* image71 = IMG_Load("aboutpowerup.png");
    SDL_Surface* image72 = IMG_Load("aboutplay.png");
    SDL_Surface* image73 = IMG_Load("aboutesc.png");
    SDL_Surface* image74 = IMG_Load("aboutquado.png");
    SDL_Surface* image75 = IMG_Load("aboutquavang.png");
    SDL_Surface* image76 = IMG_Load("aboutquatrang.png");
    font = TTF_OpenFont("utm.ttf", 36);

    background = SDL_CreateTextureFromSurface(renderer, image1);
    tau = SDL_CreateTextureFromSurface(renderer, image2);
    play1 = SDL_CreateTextureFromSurface(renderer, image3);
    play2 = SDL_CreateTextureFromSurface(renderer, image4);
    about1 = SDL_CreateTextureFromSurface(renderer, image5);
    about2 = SDL_CreateTextureFromSurface(renderer, image6);
    back1 = SDL_CreateTextureFromSurface(renderer, image7);
    back2 = SDL_CreateTextureFromSurface(renderer, image8);
    dan1 = SDL_CreateTextureFromSurface(renderer, image9);
    chicken1 = SDL_CreateTextureFromSurface(renderer, image10);
    egg = SDL_CreateTextureFromSurface(renderer, image12);
    trungvo = SDL_CreateTextureFromSurface(renderer, image13);
    smoke = SDL_CreateTextureFromSurface(renderer, image14);
    vuno = SDL_CreateTextureFromSurface(renderer, image15);
    chicken2 = SDL_CreateTextureFromSurface(renderer, image16);
    chicken3 = SDL_CreateTextureFromSurface(renderer, image17);
    upgrade1 = SDL_CreateTextureFromSurface(renderer, image18);
    upgrade2 = SDL_CreateTextureFromSurface(renderer, image19);
    mot = SDL_CreateTextureFromSurface(renderer, image20);
    hai = SDL_CreateTextureFromSurface(renderer, image21);
    ba = SDL_CreateTextureFromSurface(renderer, image22);
    bon = SDL_CreateTextureFromSurface(renderer, image23);
    nam = SDL_CreateTextureFromSurface(renderer, image24);
    quado1 = SDL_CreateTextureFromSurface(renderer, image25);
    quado2 = SDL_CreateTextureFromSurface(renderer, image26);
    quado3 = SDL_CreateTextureFromSurface(renderer, image27);
    quado4 = SDL_CreateTextureFromSurface(renderer, image28);
    dando = SDL_CreateTextureFromSurface(renderer, image29);
    thunder = SDL_CreateTextureFromSurface(renderer, image30);
    quatrang1 = SDL_CreateTextureFromSurface(renderer, image31);
    quatrang2 = SDL_CreateTextureFromSurface(renderer, image32);
    quatrang3 = SDL_CreateTextureFromSurface(renderer, image33);
    quatrang4 = SDL_CreateTextureFromSurface(renderer, image34);
    logo = SDL_CreateTextureFromSurface(renderer, image35);
    menu1 = SDL_CreateTextureFromSurface(renderer, image36);
    menu2 = SDL_CreateTextureFromSurface(renderer, image37);
    exit1 = SDL_CreateTextureFromSurface(renderer, image38);
    exit2 = SDL_CreateTextureFromSurface(renderer, image39);
    remuse1 = SDL_CreateTextureFromSurface(renderer, image40);
    remuse2 = SDL_CreateTextureFromSurface(renderer, image41);
    metalegg = SDL_CreateTextureFromSurface(renderer, image42);
    fullegg = SDL_CreateTextureFromSurface(renderer, image43);
    brokenegg = SDL_CreateTextureFromSurface(renderer, image44);
    quavang1 = SDL_CreateTextureFromSurface(renderer, image45);
    quavang2 = SDL_CreateTextureFromSurface(renderer, image46);
    quavang3 = SDL_CreateTextureFromSurface(renderer, image47);
    quavang4 = SDL_CreateTextureFromSurface(renderer, image48);
    laserboss = SDL_CreateTextureFromSurface(renderer, image49);
    end1 = SDL_CreateTextureFromSurface(renderer, image50);
    end2 = SDL_CreateTextureFromSurface(renderer, image51);
    backgroundend = SDL_CreateTextureFromSurface(renderer, image52);
    yes1 = SDL_CreateTextureFromSurface(renderer, image53);
    yes2 = SDL_CreateTextureFromSurface(renderer, image54);
    no1 = SDL_CreateTextureFromSurface(renderer, image55);
    no2 = SDL_CreateTextureFromSurface(renderer, image56);
    warning = SDL_CreateTextureFromSurface(renderer, image57);
    fork = SDL_CreateTextureFromSurface(renderer, image58);
    board = SDL_CreateTextureFromSurface(renderer, image59);
    heart = SDL_CreateTextureFromSurface(renderer, image60);
    phaohoa1 = SDL_CreateTextureFromSurface(renderer, image61);
    phaohoa2 = SDL_CreateTextureFromSurface(renderer, image62);
    phaohoa3 = SDL_CreateTextureFromSurface(renderer, image63);
    phaohoa4 = SDL_CreateTextureFromSurface(renderer, image64);
    phaohoa5 = SDL_CreateTextureFromSurface(renderer, image65);
    thanhmau1 = SDL_CreateTextureFromSurface(renderer, image67);
    thanhmau2 = SDL_CreateTextureFromSurface(renderer, image68);
    aboutmove = SDL_CreateTextureFromSurface(renderer, image69);
    aboutattack = SDL_CreateTextureFromSurface(renderer, image70);
    aboutpowerup = SDL_CreateTextureFromSurface(renderer, image71);
    aboutplay = SDL_CreateTextureFromSurface(renderer, image72);
    aboutesc = SDL_CreateTextureFromSurface(renderer, image73);
    aboutquado = SDL_CreateTextureFromSurface(renderer, image74);
    aboutquatrang = SDL_CreateTextureFromSurface(renderer, image75);
    aboutquavang = SDL_CreateTextureFromSurface(renderer, image76);

    SDL_Surface* controchuot = resize1(image58, 64, 64);
    SDL_Cursor* cursor = SDL_CreateColorCursor(controchuot, 0, 0);

    SDL_SetCursor(cursor);
    //SDL_FreeSurface(background);
    ost = Mix_LoadMUS("ost.mp3");
    musicboss = Mix_LoadMUS("musicboss.mp3");
    musicend = Mix_LoadMUS("musicend.mp3");
    winsound = Mix_LoadMUS("winsound.mp3");
    chickensound = Mix_LoadWAV("chickensound.mp3");

    gunsound = Mix_LoadWAV("gunsound.mp3");
    trungvosound = Mix_LoadWAV("trungvosound.mp3");
    deadsound = Mix_LoadWAV("deadsound.mp3");
    blastersound = Mix_LoadWAV("blastersound.mp3");
    Mix_VolumeChunk(gunsound, 32);
    Mix_VolumeChunk(blastersound, 32);
    Mix_PlayMusic(ost, -1);
    Mix_VolumeMusic(50);
    SDL_Event event;
    vtbackground = {0,0,chieudai,chieurong};
    textcolor =  {255, 255, 255, 255};
    sizetaux = 73 , sizetauy = 70;
    sizedanx = 19, sizedany = 60 , sizegax = 90 , sizegay = 76;
    sizeupx = sizeupy = 30;
    sizequax = 40, sizequay = 46;
    sizebossx= 270,sizebossy = 350;
    sizedanbossx = 30 , sizedanbossy = 85;
    infoboss = {chieudai/2-sizebossx/2,-sizebossy};
    for ( int i =2 ; i <= 4 ; i++)
    {
        sample.push_back({infoboss.f-330+i*30,200+(i-1)*sizebossy/4});
        sample.push_back({infoboss.f-130+i*10,200+(i-1)*sizebossy/4});
    }
    for ( int i =2 ; i <= 4 ; i++)
    {
        sample.push_back({infoboss.f+230-i*30+sizebossx,200+(i-1)*sizebossy/4});
        sample.push_back({infoboss.f+30-i*10+sizebossx,200+(i-1)*sizebossy/4});
    }
    for ( int i = 1 ; i <= 3 ; i++)
    {
        sample.push_back({10+(i-1)*270,10+i*40});
    }
    for ( int i = 1 ; i <= 3 ; i++)
    {
        sample.push_back({chieudai-sizegax-10-(i-1)*270,10+i*40});
    }
    for ( int i = 5 ; i <= 9 ; i++)
    {
        sample.push_back({infoboss.f-105+(i-5)*100,150+sizebossy+50});
    }
    fstream inp("input.txt");
    inp >> canremuse;
    inp.close();
    while ( quit == false )
    {
        timegame1++;
        if ( live > 0 && clickesc == false && clickexit == false) {
            if ( timegame1 % 7 == 0 ) {
                timegame++ ;
                if ( timegame % 4 == 1 )
                {
                    for ( auto &u : info)
                    {
                        u.s.f+=4;
                    }
                }
                else if ( timegame % 4 == 2 )
                {
                    for ( auto &u : info)
                    {
                        u.s.f-=4;
                    }
                }
            }
        }
        if ( timegame1 <= 200+254/2 )
        {
            beforeinstart();
        }
        else if ( clickabout == false && clickplay == false ) instart();
        else if ( clickabout == true ) {
            inabout();
        }
        else if ( clickplay == true && clickesc == false && clickexit == false )
        {
            inplay(taux,tauy);
            if ( live > 0  && chieurong-(timeendgame - 951-255)+500 > -500) SDL_ShowCursor(0);
            else {
                SDL_ShowCursor(1);
            }
        }
        else if ( clickesc == true  )
        {
            SDL_ShowCursor(1);
            xulyesc();
        }
        if ( clickplay == true && clickexit == true )
        {
            insavegame();
            SDL_ShowCursor(1);
        }
        if ( dead > 300 )
        {
            SDL_Rect vt = {taux-50,tauy-50,200,200};
            SDL_RenderCopy(renderer, vuno, NULL, &vt);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
            continue;
        }
        while ( SDL_PollEvent(&event) != 0 )
        {
            if ( event.type == SDL_QUIT)
            {
                if ( live > 0 && finishround[5] == false && clickplay == true  && live > 0) clickexit = true,clickesc=false;
                else if ( finishround[5] == true || live <= 0 ) {savegame(inp,0);quit = true;}
                else quit = true;
            }
            else if ( event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;
                if ( clickplay == true && clickesc == false && clickexit == false && timegame1 > 200+254/2 )
                {

                    if ( bullet.size() >= 1 && bullet.back().s >= y-90 && bullet.back().s <= y-60 ) continue;

                    if ( live > 0 ) {
                        x = min(x,chieudai-sizetaux);
                        y = min(y,chieurong-sizetauy);
                        if ( danthunder == false && dead <= 300 ) {
                            if ( timeendgame <= 800 ) Mix_PlayChannel(-1, gunsound, 0);
                            if ( sodan == 1 ) bullet.push_back({x+sizetaux/2-8,y-sizetauy+10});
                            else if ( sodan == 2 ) {
                                bullet.push_back({x+sizetaux/2-14,y-sizetauy+10});
                                bullet.push_back({x+sizetaux/2+2,y-sizetauy+10});
                            }
                            else if ( sodan == 3 )
                            {
                                bullettrai.push_back({x+sizetaux/2-50,y-sizetauy+10});
                                bulletphai.push_back({x+sizetaux/2+38,y-sizetauy+10});
                                bullet.push_back({x+sizetaux/2-6,y-sizetauy-5});
                            }
                            else if ( sodan == 4 )
                            {
                                bullettrai.push_back({x+sizetaux/2-50,y-sizetauy+10});
                                bulletphai.push_back({x+sizetaux/2+38,y-sizetauy+10});
                                bullet.push_back({x+sizetaux/2-16,y-sizetauy-5});
                                bullet.push_back({x+sizetaux/2+2,y-sizetauy-5});
                            }
                            else {
                                bullettrai.push_back({x+sizetaux/2-50,y-sizetauy+10});
                                bulletphai.push_back({x+sizetaux/2+38,y-sizetauy+10});
                                bullet.push_back({x+sizetaux/2-26,y-sizetauy-5});
                                bullet.push_back({x+sizetaux/2+14,y-sizetauy-5});
                                bullet.push_back({x+sizetaux/2-6,y-sizetauy-5});
                            }
                        }
                        else if ( blaster.f == 0 ) {
                            if ( timeendgame <= 800 ) Mix_PlayChannel(-1, blastersound, 0);
                            pair<int,pair<int,int>> x1 = ktra(x+sizetaux/2-8,y);
                            if ( x1.f == 1000 )
                            {
                                hpboss -= (6+(sodan-1)*3);
                                if ( giatlen == 0 && infoboss.s == 200) giatlen = 20;
                                vtphaohoa.push_back({25,{x1.s.f-72,x1.s.s-72}});
                            }
                            else if ( x1.s.s != 0 )
                            {
                                info[x1.f].f-=(6+(sodan-1)*3);
                                vtphaohoa.push_back({25,{info[x1.f].s.f+sizegax/2-72,info[x1.f].s.s+sizegay-72}});
                                if ( info[x1.f].f <= 0 )
                                {
                                    xulygachet(x1.f);

                                }


                            }
                            blaster.f = 12;
                            blaster.s.f = y-x1.s.s;
                            blaster.s.s.f = x+sizetaux/2-29-(sodan-1)*9;
                            blaster.s.s.s = x1.s.s;
                        }
                    }
                }
                if ( clickplay == true && (clickesc == true||live<=0||chieurong-(timeendgame - 951-255)+500 <= -500 )&& clickexit == false )
                {
                    if ( motionexit == true && finishround[5] == true )
                    {
                        quit=true;
                        continue;
                    }
                    else if ( motionexit == true && live > 0 && finishround[5] == false  )
                    {
                        clickexit = true;
                        clickesc = false;
                        //quit = true;
                        continue;
                    }
                    else if ( motionexit == true && live <= 0 )
                    {
                        quit=true;
                        continue;
                    }
                    else if ( motionmenu == true )
                    {
                        timegame1 = 401;
                        clickesc = false;
                        clickplay = false;
                        if ( finishround[5] == false && live > 0 ) {savegame(inp,1);resetall();canremuse = true;}
                        else if ( finishround[5] == false && live == 0 ) {savegame(inp,0);resetall();canremuse = false;}
                        else savegame(inp,0),resetall();

                        motionmenu = false;
                        continue;
                    }
                    else if ( motionremuse == true )
                    {
                        clickesc = false;
                        SDL_WarpMouseInWindow(screen, beforestopx, beforestopy);
                    }
                }
                if ( clickplay == true && clickexit == true && live > 0)
                {
                    if ( motionyes == true )
                    {
                        inp.close();
                        savegame(inp,1);
                        quit =true;
                    }
                    else if (motionno == true )
                    {
                        inp.close();
                        savegame(inp,0);
                        quit = true;
                    }
                }
                if ( timegame1 > 300 ) {
                    if ( motionabout == true && clickplay == false)
                    {
                        clickabout = true;
                    }
                    else if ( motionback == true && clickabout == true )
                    {
                        clickabout = false;
                    }
                    if ( motionstart == true && clickabout == false && clickplay == false )
                    {
                        clickplay = true;
                        resetall();
                        taux = x, tauy = y;
                    }
                    if ( motionremuse1 == true && clickabout == false && clickplay == false && canremuse == true)
                    {
                        clickplay = true ;

                        inp.open("input.txt");
                        inp >> man >> man >> sodan >> loaidan >> levelthunder >> live >> score;
                        inp.close();
                       // cout << man << " " << sodan << " " << loaidan << " " << levelthunder << " " << live << " " << score << endl;
                        //if ( live == 0 ) live = 3 ;
                        if ( loaidan == 3 )
                        {
                            danthunder = true ;
                            loaidan = 1;
                        }
                        if ( man > 1 )
                        {
                            if ( man == 2 ) man1();
                            else if ( man == 3 ) man2();
                            else if ( man == 4 ) timeman3 = chieudai/10,man3();
                            else if ( man == 5 ) timeman3 = chieudai/10,man4();
                            for ( int i = 0 ; i <= man-1; i++)
                            {
                                finishround[i]=true;
                            }
                        }
                        taux = x , tauy = y;
                    }
                }
            }
            else if ( event.type == SDL_MOUSEMOTION)
            {
                int x = event.motion.x;
                int y = event.motion.y;
                if ( live > 0 && clickesc == false && clickexit == false && chieurong-(timeendgame - 951-255)+500 > -500 && clickplay == true ) {
                    taux =x , tauy = y;
                    taux = min(x,chieudai-sizetaux);
                    tauy = min(y,chieurong-sizetauy);
                    continue;
                }
                else if ( clickplay == true && (clickesc == true || live <= 0 || chieurong-(timeendgame - 951-255)+500 <= -500) )
                {
                    // {chieudai/2-174/2,350,174,74};
                    if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 500 && y <= 500+74 )
                    {
                        motionmenu = true;
                    }
                    else motionmenu = false;
                    if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 650 && y <= 650+74 )
                    {
                        motionexit = true;
                    }
                    else motionexit = false;
                    if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 350 && y <= 350+74 && clickesc == true )
                    {
                        motionremuse = true;
                    }
                    else if ( clickesc == true ) motionremuse = false;
                    continue;
                }
                else if ( clickplay == true && clickexit == true )
                {
                    if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 500 && y <= 500+74)
                    {
                        motionyes= true;
                    }
                    else motionyes = false;
                    if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 600 && y <= 600+74)
                    {
                        motionno = true;
                    }
                    else motionno= false;
                    continue;
                }
                if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 650 && y <= 650+74 )
                {
                    motionstart = true;
                }
                else
                {
                    motionstart = false;
                }
                if ( x>= chieudai/2-174/2 && x<=chieudai/2-174/2+174 && y >= 750 && y <= 750+74 )
                {
                    motionabout = true;
                }
                else motionabout = false;
                if ( x >= 30 && x <= 30+174 && y >= 20 && y <= 20+74 )
                {
                    motionback = true;
                }
                else motionback = false;
                if ( x >= chieudai/2-174/2 && x <= chieudai/2-174/2+174 && y >= 550 && y <= 550+74)
                {
                    motionremuse1 = true;
                }
                else motionremuse1 = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE && clickplay == true && timeendgame == 0 && live > 0 && clickexit == false) {
                    clickesc = true;
                    beforestopx = taux , beforestopy = tauy;
                }
            }
        }
//        SDL_Rect vt = {500,500,30,85};
//        SDL_RenderCopy(renderer, laserboss, NULL, &vt);
        SDL_RenderPresent(renderer);
        SDL_Delay(10); // 100 FPS

        SDL_RenderClear(renderer);
    }
    return 0;
}
void savegame(fstream &inp, int issave)
{
    inp.open("input.txt");
    inp.seekg(0, ios::beg);
    if ( danthunder == true ) loaidancu = 3 ;
    inp << issave << endl << man << endl << sodancu << endl << loaidancu << endl << levelthundercu << endl << livecu << endl << scorecu << endl;
    inp.close();
}
void insavegame()
{
    timestop();
    SDL_Rect bigwarning = SDL_Rect{chieudai/2-679/2,250,679,174};
    SDL_RenderCopy(renderer,warning,NULL,&bigwarning);
    SDL_Rect bigyes1 = {chieudai/2-174/2,500,174,74};
    if ( motionyes == false ) SDL_RenderCopy(renderer,yes1,NULL,&bigyes1);
    else SDL_RenderCopy(renderer,yes2,NULL,&bigyes1);
    SDL_Rect bigno1 = {chieudai/2-174/2,600,174,74};
    if ( motionno == false ) SDL_RenderCopy(renderer,no1,NULL,&bigno1);
    else SDL_RenderCopy(renderer,no2,NULL,&bigno1);

}
bool ktgiaonhau1(SDL_Rect rect1, double angle1, SDL_Rect rect2) {
    double midx1 = (rect1.x + rect1.w / 2.0), midy1 = (rect1.y + rect1.h / 2.0);
    double midx2 = (rect2.x + rect2.w / 2.0), midy2 = (rect2.y + rect2.h / 2.0);
    double angleRad = angle1 * M_PI / 180.0;
    double halfw1 = (rect1.w / 2.0),halfh1 = (rect1.h / 2.0), halfw2 = (rect2.w / 2.0),halfh2 = rect2.h / 2.0;
    double cosA = cos(angleRad), sinA = sin(angleRad);
    double x1 = midx1 + halfw1 * cosA - halfh1 * sinA, y1 = midy1 + halfw1 * sinA + halfh1 * cosA;
    double x2 = midx1 - halfw1 * cosA - halfh1 * sinA, y2 = midy1 - halfw1 * sinA + halfh1 * cosA;
    double x3 = midx1 - halfw1 * cosA + halfh1 * sinA, y3 = midy1 - halfw1 * sinA - halfh1 * cosA;
    double x4 = midx1 + halfw1 * cosA + halfh1 * sinA, y4 = midy1 + halfw1 * sinA - halfh1 * cosA;
    if ( (x1 >= rect2.x && x1 <= rect2.x + rect2.w && y1 >= rect2.y && y1 <= rect2.y + rect2.h) || (x2 >= rect2.x && x2 <= rect2.x + rect2.w && y2 >= rect2.y && y2 <= rect2.y + rect2.h) || (x3 >= rect2.x && x3 <= rect2.x + rect2.w && y3 >= rect2.y && y3 <= rect2.y + rect2.h) || (x4 >= rect2.x && x4 <= rect2.x + rect2.w && y4 >= rect2.y && y4 <= rect2.y + rect2.h)) {
        return true;
    }
    double midx1Temp = midx1, midy1Temp = midy1;
    midx1 = midx2,midy1 = midy2, midx2 = midx1Temp, midy2 = midy1Temp;
    double halfw1Temp = halfw1, halfh1Temp = halfh1;
    halfw1 = halfw2,halfh1 = halfh2,halfw2 = halfw1Temp,halfh2 = halfh1Temp;
    cosA = cos(-angleRad),sinA = sin(-angleRad);
    x1 = midx1 + halfw1 * cosA - halfh1  *sinA;
    y1 = midy1 + halfw1 * sinA + halfh1  *cosA;
    x2 = midx1 - halfw1 * cosA - halfh1 *sinA;
    y2 = midy1 - halfw1 *sinA + halfh1 * cosA;
    x3 = midx1 - halfw1 * cosA + halfh1 *sinA;
    y3 = midy1 - halfw1 * sinA - halfh1 * cosA;
    x4 = midx1 + halfw1 * cosA + halfh1 * sinA;
    y4 = midy1 + halfw1 * sinA - halfh1 * cosA;
    if ((x1 >= rect1.x && x1 <= rect1.x + rect1.w && y1 >= rect1.y && y1 <= rect1.y + rect1.h) || (x2 >= rect1.x && x2 <= rect1.x + rect1.w && y2 >= rect1.y && y2 <= rect1.y + rect1.h) || (x3 >= rect1.x && x3 <= rect1.x + rect1.w && y3 >= rect1.y && y3 <= rect1.y + rect1.h) || (x4 >= rect1.x && x4 <= rect1.x + rect1.w && y4 >= rect1.y && y4 <= rect1.y + rect1.h))  {
        return true;
    }
    return false;
}
void timestop()
{
    int* x = new int(taux);
    int* y = new int(tauy);
    vtbackground = {0,ybgr,chieudai,chieurong};
    SDL_RenderCopy(renderer, background, NULL, &vtbackground);
    SDL_Rect* vt1 = new SDL_Rect{0,-chieurong+ybgr,chieudai,chieurong};
    SDL_RenderCopy(renderer, background, NULL, vt1);
    if ( blaster.f > 0 && timeendgame <=800)
    {
        SDL_Rect vt = {blaster.s.s.f,blaster.s.s.s,levelthunder,blaster.s.f};
        SDL_RenderCopy(renderer, thunder, NULL, &vt);
    }
    if ( finishround[4] == true && finishround[5] == false )
    {
        SDL_Rect vt = {infoboss.f,infoboss.s,sizebossx,sizebossy};
        if ( hpboss >= 1600 ) SDL_RenderCopy(renderer, fullegg, NULL, &vt);
        else if ( hpboss >= 800 ) SDL_RenderCopy(renderer, brokenegg, NULL, &vt);
        else if ( hpboss > 0 ) SDL_RenderCopy(renderer, metalegg, NULL, &vt);
        inthanhmau();
         for ( auto &u : skillboss)
        {
            SDL_Rect vt2 = {u.s.f,u.s.s,30,85};
            SDL_RenderCopyEx(renderer,laserboss , NULL, &vt2, u.f, NULL, SDL_FLIP_NONE);
        }
    }
    for ( auto &u : info)
    {
        sizegax = 90 , sizegay = 76;
        SDL_Rect* vtga = new SDL_Rect{u.s.f,u.s.s,sizegax,sizegay};
        SDL_RenderCopy(renderer, chicken2, NULL, vtga);
        delete vtga;
    }
    for ( auto &u : vtphaohoa)
    {

         if ( u.f > 20 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 147*100/147,141*100/147};
             SDL_RenderCopy(renderer, phaohoa1, NULL, &vt);
         }
         else if ( u.f > 15 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 178*100/147,166*100/147};
             SDL_RenderCopy(renderer, phaohoa2, NULL, &vt);
         }
         else if ( u.f > 10 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 189*100/147,212*100/147};
             SDL_RenderCopy(renderer, phaohoa3, NULL, &vt);
         }
         else if ( u.f > 5 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 212*100/147,204*100/147};
             SDL_RenderCopy(renderer, phaohoa4, NULL, &vt);
         }
         else
         {
             SDL_Rect vt = {u.s.f,u.s.s, 184*100/147,196*100/147};
             SDL_RenderCopy(renderer, phaohoa5, NULL, &vt);
         }
    }
    inlive();
    inscore();

    delete x;
    delete y;
    for ( auto &u : vtegg)
    {
        SDL_Rect* vt = new SDL_Rect{u.f,u.s, 20,29};
        SDL_RenderCopy(renderer, egg, NULL, vt);
        delete vt;
    }
    for ( auto &u : vtsmoke )
    {
        SDL_Rect* vt = new SDL_Rect{u.s.f,u.s.s, 75,75};
        SDL_RenderCopy(renderer, smoke, NULL, vt);
        delete vt;
    }
    for ( auto &u : vtupgrade)
    {
        SDL_Rect* vt = new SDL_Rect{u.f,u.s, sizeupx,sizeupy};
        SDL_RenderCopy(renderer, upgrade1, NULL, vt);
        delete vt;
    }
    for ( auto &u : hopqua)
    {
        SDL_Rect* vtkhoi = new SDL_Rect{u.s.f,u.s.s,40,46};
        if ( u.f == 1 ) SDL_RenderCopy(renderer, quavang1, NULL, vtkhoi);
        else if ( u.f== 2) SDL_RenderCopy(renderer, quado1, NULL, vtkhoi);
        else SDL_RenderCopy(renderer, quatrang1, NULL, vtkhoi);
        delete vtkhoi;
    }
    if ( (dead == 0 || disappear ==0) && (timeendgame <= 800) ) {

        SDL_Rect* vttau = new SDL_Rect{*x,*y,sizetaux,sizetauy};
        SDL_RenderCopy(renderer, tau, NULL, vttau);
        SDL_Rect vtkhoi1 = {taux+sizetaux/2-30,tauy+sizetauy-12,60,130};
        if ( dead == 0 || dead <= 300 ) {
            SDL_RenderCopy(renderer, mot, NULL, &vtkhoi1);
        }
        delete vttau;
    }

    for ( auto &u : bullet)
    {
        SDL_Rect vtdan = {u.f,u.s,sizedanx,sizedany};
        if ( loaidan == 1 ) SDL_RenderCopy(renderer, dan1, NULL, &vtdan);
        else if ( loaidan == 2 ) SDL_RenderCopy(renderer, dando, NULL, &vtdan);
    }
    for ( auto &u : bullettrai)
    {
        SDL_Rect vt = {u.f,u.s,sizedanx,sizedany};
        double angle = 360.0-14.07;
        if ( loaidan == 1 ) SDL_RenderCopyEx(renderer,dan1 , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        else if ( loaidan == 2 ) SDL_RenderCopyEx(renderer,dando , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
    }
    for ( auto &u : bulletphai)
    {
        SDL_Rect vt = {u.f,u.s,sizedanx,sizedany};
        double angle = 14.07;
        if ( loaidan == 1 ) SDL_RenderCopyEx(renderer,dan1 , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        else if ( loaidan == 2 ) SDL_RenderCopyEx(renderer,dando , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
    }
    for ( auto &u : vttrungvo )
    {
        SDL_Rect vt = {u.s.f,u.s.s, 35,18};
        SDL_RenderCopy(renderer, trungvo, NULL, &vt);
    }
    if ( live > 0 && timeman > 0 ) inman();
    inlive();
    inscore();
}
void xulyesc()
{
    timestop();
    inremuse();
    inexit();
    inmenu();

}
void resetall()
{
    canremuse = false;
    loaidan = 1 ; sodan = 1 ; score = 0 ; levelthunder = 70; xbgr = ybgr = 0 , timeman = 200 , danthunder = false, dead=0,timeman3 = 0;
    hpboss = 2400 , resetga = 0 , giatlen = 0 , timeendgame = 0 ,live = 3 ;
    loaidancu = 1 , sodancu = 1 , scorecu = 0 ,levelthundercu = 70 , man = 1 , livecu = 3;
    infoboss = {chieudai/2-sizebossx/2,-sizebossy};
    vtphaohoa.clear();
    if ( finishround[4] == true )
    {
        Mix_PlayMusic(ost, -1);
        Mix_VolumeMusic(50);
    }
    for ( int i = 0 ; i <= 10 ; i++)
    {
        finishround[i]=false;
    }
    info.clear();
    vtlong.clear();
    vtegg.clear();
    vttrungvo.clear();
    bullet.clear();
    vtupgrade.clear();
    vtsmoke.clear();
    skill.clear();
    hopqua.clear();
    skillboss.clear();
}
void inremuse()
{
    SDL_Rect* bigremuse = new SDL_Rect{chieudai/2-174/2,350,174,74};
    if ( motionremuse == false ) SDL_RenderCopy(renderer,remuse1,NULL,bigremuse);
    else SDL_RenderCopy(renderer,remuse2,NULL,bigremuse);
    delete bigremuse;
}

void inmenu()
{
    SDL_Rect* bigremuse = new SDL_Rect{chieudai/2-174/2,500,174,74};
    if ( motionmenu == false ) SDL_RenderCopy(renderer,menu1,NULL,bigremuse);
    else SDL_RenderCopy(renderer,menu2,NULL,bigremuse);
    delete bigremuse;
}

void inexit()
{
    SDL_Rect* bigremuse = new SDL_Rect{chieudai/2-174/2,650,174,74};
    if ( motionexit == false ) SDL_RenderCopy(renderer,exit1,NULL,bigremuse);
    else SDL_RenderCopy(renderer,exit2,NULL,bigremuse);
    delete bigremuse;
}
void beforeinstart()
{
    vtbackground = {0,0,chieudai,chieurong};
    SDL_RenderCopy(renderer, background, NULL, &vtbackground);
    int* x = new int(5.5*min(timegame1,200));
    int* y = new int(2.8*min(timegame1,200));
    SDL_Rect* biglogo = new SDL_Rect{chieudai/2-*x/2,100+560/2-*y/2,*x,*y};
    SDL_RenderCopy(renderer,logo,NULL,biglogo);
    delete x;
    delete y;
    if ( timegame1 > 200 ) {
        SDL_SetTextureBlendMode(play1, SDL_BLENDMODE_BLEND);
        SDL_SetTextureBlendMode(about1, SDL_BLENDMODE_BLEND);
        SDL_SetTextureBlendMode(play2, SDL_BLENDMODE_BLEND);
        SDL_SetTextureBlendMode(about2, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(play1, (timegame1-200)*2);
        SDL_SetTextureAlphaMod(about1, (timegame1-200)*2);
        SDL_SetTextureAlphaMod(play2, (timegame1-200)*2);
        SDL_SetTextureAlphaMod(about2, (timegame1-200)*2);
        SDL_Rect bigplay1 = {chieudai/2-174/2,650,174,74};
        if ( motionstart == false ) SDL_RenderCopy(renderer, play1, NULL, &bigplay1);
        else SDL_RenderCopy(renderer, play2, NULL, &bigplay1);
        SDL_Rect bigabout1 = {chieudai/2-174/2,750,174,74};
        if (motionabout == false )  SDL_RenderCopy(renderer, about1, NULL, &bigabout1);
        else SDL_RenderCopy(renderer, about2, NULL, &bigabout1);
        if ( canremuse == true )
        {
            SDL_SetTextureBlendMode(remuse1, SDL_BLENDMODE_BLEND);
            SDL_SetTextureBlendMode(remuse2, SDL_BLENDMODE_BLEND);
            SDL_SetTextureAlphaMod(remuse1, (timegame1-200)*2);
            SDL_SetTextureAlphaMod(remuse2, (timegame1-200)*2);
            SDL_Rect bigremuse1 = {chieudai/2-174/2,550,174,74};
            if ( motionremuse1 == false ) SDL_RenderCopy(renderer, remuse1, NULL, &bigremuse1);
            else SDL_RenderCopy(renderer, remuse2, NULL, &bigremuse1);
        }
    }
}
void instart()
{

    vtbackground = {0,0,chieudai,chieurong};
    SDL_RenderCopy(renderer, background, NULL, &vtbackground);
    SDL_Rect biglogo = {chieudai/2-1100/2,100,1100,560};
    SDL_RenderCopy(renderer,logo,NULL,&biglogo);
    SDL_Rect bigplay1 = {chieudai/2-174/2,650,174,74};
    if (canremuse == true )
    {
        SDL_Rect bigremuse1 = {chieudai/2-174/2,550,174,74};
        if ( motionremuse1 == false ) SDL_RenderCopy(renderer,remuse1,NULL,&bigremuse1);
        else SDL_RenderCopy(renderer,remuse2,NULL,&bigremuse1);
    }
    if ( motionstart == false ) SDL_RenderCopy(renderer,play1,NULL,&bigplay1);
    if ( motionstart == true ) {
        SDL_RenderCopy(renderer,play2,NULL,&bigplay1);
    }
    SDL_Rect bigabout1 = {chieudai/2-174/2,750,174,74};
    if ( motionabout == false )SDL_RenderCopy(renderer,about1,NULL,&bigabout1);
    else
    {
        SDL_RenderCopy(renderer,about2,NULL,&bigabout1);
    }
}
void inabout()
{
    vtbackground = {0,0,chieudai,chieurong};
    SDL_RenderCopy(renderer, background, NULL, &vtbackground);
    SDL_Rect* bigback1 = new SDL_Rect{30,20,174,74};
    if ( motionback == false ) SDL_RenderCopy(renderer,back1,NULL,bigback1);
    else SDL_RenderCopy(renderer,back2,NULL,bigback1);
    delete bigback1;
    SDL_Rect biginfoabout = {chieudai/2-325/2,10,325,83};
    SDL_RenderCopy(renderer,aboutplay,NULL,&biginfoabout);
    biginfoabout = {20,120,863,225};
    SDL_RenderCopy(renderer,aboutmove,NULL,&biginfoabout);
    biginfoabout = {30,120+225+20,753,205};
    SDL_RenderCopy(renderer,aboutesc,NULL,&biginfoabout);
    biginfoabout = {30,120+225+20+205+20+190,702,172};
    SDL_RenderCopy(renderer,aboutpowerup,NULL,&biginfoabout);
    biginfoabout = {1400,120,393,164};
    SDL_RenderCopy(renderer,aboutquatrang,NULL,&biginfoabout);
    biginfoabout = {1400,120+225+20,393,164};
    SDL_RenderCopy(renderer,aboutquado,NULL,&biginfoabout);
    biginfoabout = {1400,120+225+20+205+20,393,164};
    SDL_RenderCopy(renderer,aboutquavang,NULL,&biginfoabout);
    biginfoabout = {45,120+225+20+205+20,777,151};
    SDL_RenderCopy(renderer,aboutattack,NULL,&biginfoabout);
}

void inman()
{
    sodancu=sodan,loaidancu=loaidan,levelthundercu=levelthunder,livecu=live,scorecu = score+score1;
    int w=200;
    SDL_Surface* over;
    if ( finishround[1] == false ) over = TTF_RenderText_Blended(font, "WAVE 1", textcolor);
    else if ( finishround[2] == false ) over = TTF_RenderText_Blended(font, "WAVE 2", textcolor);
    else if ( finishround[3] == false ) over = TTF_RenderText_Blended(font, "WAVE 3", textcolor);
    else if ( finishround[4] == false ) over = TTF_RenderText_Blended(font, "WAVE 4", textcolor);
    else {
        if ( timeman == 200 ) {
            Mix_PlayMusic(musicboss, -1);
            Mix_VolumeMusic(50);
        }
        over = TTF_RenderText_Blended(font, "BOSS IS COMING !!!", textcolor);
        w=300;
    }
    SDL_Texture* gover = SDL_CreateTextureFromSurface(renderer, over);
    int* x = new int(300);
    int* y = new int(300);
    SDL_QueryTexture(gover, NULL, NULL, x, y);
    int x1 = 250;
    if ( finishround[4] ==true ) x1 = 400;
    SDL_Rect* vt = new SDL_Rect{chieudai/2-x1/2,chieurong/2-100/2,x1,100};

    SDL_RenderCopy(renderer, gover, NULL, vt);

    delete x;
    delete y;
    delete vt;

    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);
    timeman--;
    if ( (clickesc == true || clickexit == true ) && timeman > 0 ) timeman++;
}
void man1()
{
    int i = 0 ;
    for ( auto &u : info)
    {
        if ( live <= 0  ) continue;

        if ( u.s.s == 0 )
        {

            if ( u.s.f-6 >= 0 ) u.s.f-=6;
            else u.s.s+=6;
        }
        else if ( u.s.s % 150 != 0 ) (u.s.s)+=6;
        else if ( u.s.s % 300 != 0 ) {
            if ( u.s.f+6+sizegax <= chieudai ) u.s.f+=6;
            else u.s.s+=6;

            //sizegay = 76
        }
        else {
            if ( u.s.f-6 >= 0 ) u.s.f-=6;
            else u.s.s+=6;
        }
        if ( u.s.s >= chieurong ) info.erase(info.begin()+i),i--;
        i++;
    }
    if ( info.size() == 0  )
    {
        info.clear();
        finishround[1] = true;
        int x1 = 0 ;
        man = 2 ;
        for ( int i = 1 ; i <= 40 ; i++)
        {
            info.push_back({18,{chieudai+(i-1)*sizegax+x1,0}});
            x1+=40;
        }
        timeman = 200;
    }
}
void man2()
{
    int i = 0 ;
    for ( auto &u : info)
    {
        if ( live <= 0  ) continue;
        if ( u.s.s == 0 )
        {
            if ( u.s.f-10 >= 0 ) u.s.f-=10;
            else u.s.s+=10;
        }
        else if ( u.s.s % 150 != 0 ) (u.s.s)+=10;
        else if ( u.s.s % 300 != 0 ) {
            if ( u.s.f+10+sizegax <= chieudai ) u.s.f+=10;
            else u.s.s+=10;

            //sizegay = 76
        }
        else {
            if ( u.s.f-10 >= 0 ) u.s.f-=10;
            else u.s.s+=10;
        }
        if ( u.s.s >= chieurong ) info.erase(info.begin()+i),i--;
        i++;
    }
    if ( info.size() == 0  )
    {
        info.clear();
        finishround[2] = true;
        man = 3 ;
        for ( int i = 0 ; i <= 700 ; i+=100) // 700
        {
            int x1 = 0 ;
            for ( int j =1 ; j <= 14; j++) // 14
            {
                info.push_back({18,{chieudai+(j-1)*sizegax+x1+5,i+75}});
                x1+=40;
            }
        }

        timeman = 200;
    }
}
void man3()
{
    if ( timeman3 < chieudai/10 ) {
        for ( auto &u : info)
        {
            if ( live <= 0  ) continue;
            u.s.f-=10;
            if (u.s.f <= 0 )
            {
                u.s.f= 0 ;
            }
        }
        timeman3++;
        return ;
    }
    bool daochieu = false ;
    for ( auto &u : info)
    {
        if ( live <= 0  ) continue;
        if (left == true )
        {
            u.s.f--;
            if ( u.s.f <= 0 ) daochieu = true;
            if ( u.s.f <= 0 ) u.s.f = 0 ;
        }
        else {
            u.s.f++;
            if ( u.s.f+sizegax >= chieudai ) daochieu = true,u.s.f = chieudai-sizegax;
        }
    }
    if ( daochieu == true )
    {
        if ( left == true ) right=true,left=false;
        else left=true,right = false;
    }
    if ( info.size() == 0  )
    {
        info.clear();
        man = 4;
        finishround[3] = true;
        for ( int i = 0 ; i <= 500 ; i+=100)
        {
            int x1 = 0 ;
            for ( int j =1 ; j <= 14; j++)
            {
                info.push_back({18,{chieudai+(j-1)*sizegax+x1,i+75}});
                skill.push_back({i+75,{0,5}});
                x1+=40;
            }
        }

        timeman = 200;
        timeman3= 0 ;
    }
}
void man4()
{
    if ( timeman3 < chieudai/10 ) {
        for ( auto &u : info)
        {
            if ( live <= 0  ) continue;
            u.s.f-=10;
            if (u.s.f <= 0 )
            {
                u.s.f= 0 ;
            }
        }
        timeman3++;
        return ;
    }
    bool daochieu = false ;
    for ( auto &u : info)
    {
        if ( live <= 0  ) continue;
        if (left == true )
        {
            u.s.f--;
            if ( u.s.f <= 0 ) daochieu = true;
            if ( u.s.f <= 0 ) u.s.f = 0 ;
        }
        else {
            u.s.f++;
            if ( u.s.f+sizegax >= chieudai ) daochieu = true,u.s.f = chieudai-sizegax;
        }
    }
    if ( daochieu == true )
    {
        if ( left == true ) right=true,left=false;
        else left=true,right = false;
    }
    int dem = 0 ;
    for ( auto &u : skill)
    {
        if ( u.s.f > 0 ) dem++;
    }
    int m = skill.size();
    for ( int i = 1 ; i <= min(m-dem,7-dem) ; i++)
    {
        int r = rand()%m;
        while ( skill[r].s.f != 0 )
        {
            r = rand()%m;
        }
        skill[r].s.f = 1 ;
    }
    int i = -1 ;
    for ( auto &u : skill)
    {
        i++;
        if ( u.s.f == 0 ) continue;
        info[i].s.s+=u.s.s;
        if ( info[i].s.s + sizegay >= chieurong )
        {
            u.s.s = -5;
        }
        else if ( info[i].s.s <= u.f )
        {
            u.s.s = 5;
            u.s.f = 0;
            info[i].s.s = u.f;
        }
    }
    if ( info.size() <= 0 )
    {
        info.clear();
        man = 5;
        finishround[4]=true;
        timeman3 = 0 ;
        timeman = 200;

    }
}
string doubletostring(double n) {
    ostringstream stream;
    stream << fixed << setprecision(2) << n;
    return stream.str();
}
void inthanhmau()
{
    SDL_Rect vt = {660,20,652,63};
    SDL_RenderCopy(renderer, thanhmau1, NULL, &vt);
    double phantramhp = 1.0*hpboss/2400;
    SDL_Rect vt1 = {672,32,phantramhp*(640-12),51-12};
    SDL_RenderCopy(renderer, thanhmau2, NULL, &vt1);
    phantramhp*=100;
    string* s = new string(doubletostring(phantramhp));
    *s=*s+"%";
    SDL_Surface* over = TTF_RenderText_Blended(font, s->c_str(), textcolor);
    SDL_Texture* gover = SDL_CreateTextureFromSurface(renderer, over);
    int* yValue = new int(300);
    int x;
    if ( phantramhp == 100 ) x = 145;
    else if ( phantramhp >= 10 ) x = 130;
    else x= 115;
    SDL_Rect* vt2 = new SDL_Rect{920, 20, x, 53};
    int* xValue = new int;
    SDL_QueryTexture(gover, NULL, NULL, xValue, yValue);
    SDL_RenderCopy(renderer, gover, NULL, vt2);

    delete yValue;
    delete vt2;
    delete s;
    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);
}
void manboss()
{

    resetga++;
    SDL_Rect vt = {infoboss.f,infoboss.s,sizebossx,sizebossy};
    if ( infoboss.s <= 195 && giatlen == 0 )
    {
        infoboss.s += 5;

    }
    if ( giatlen > 0 ) infoboss.s = 190,giatlen-=4;
    else if ( infoboss.s == 190 ) infoboss.s = 200;

    int j = 0 ;
    for ( auto &u1 : bullet)
    {
        SDL_Rect vt1 = {u1.f,u1.s,sizedanx,sizedany};
        if ( ktgiaonhau1(vt,0,vt1) == true )
        {
            if ( giatlen == 0 && infoboss.s == 200) giatlen = 20;
            vtphaohoa.push_back({25,{u1.f-72,u1.s-72}});
            bullet.erase(bullet.begin()+j);
            if ( loaidan == 1 ) hpboss-=3;
            else hpboss-=4;
            j--;
        }
        j++;
    }
    j=0;
    for ( auto &u1 : bullettrai)
    {

        SDL_Rect vt1 = {u1.f,u1.s,sizedanx,sizedany};
        double angle = 360.0-14.07;
        if ( ktgiaonhau1(vt,angle,vt1) == true )
        {
            if ( giatlen == 0 && infoboss.s == 200) giatlen = 20;
            vtphaohoa.push_back({25,{u1.f-72,u1.s-72}});
            bullettrai.erase(bullettrai.begin()+j);
            if ( loaidan == 1 ) hpboss-=3;
            else hpboss-=4;
            j--;
        }
        j++;
    }
    j=0;
    for ( auto &u1 : bulletphai)
    {
        SDL_Rect vt1 = {u1.f,u1.s,sizedanx,sizedany};
        double angle = 14.07;
        if ( ktgiaonhau1(vt,angle,vt1) == true )
        {
            if ( giatlen == 0 && infoboss.s == 200) giatlen = 20;
            vtphaohoa.push_back({25,{u1.f-72,u1.s-72}});
            bulletphai.erase(bulletphai.begin()+j);
            if ( loaidan == 1 ) hpboss-=3;
            else hpboss-=4;
            j--;
        }
        j++;
    }
    if ( vtupgrade.size() == 0 ) {
        int r = rand()%750;
        if ( r == 1 )
        {
            int r1 = rand()%1400+100;
            vtupgrade.push_back({r1,-20});
        }
    }
    if ( infoboss.s >= 190 && hpboss < 800 ) {
        if ( right == true )
        {
            infoboss.f+=4;
            if ( infoboss.f + sizebossx >= chieudai) {
                infoboss.f=chieudai-sizebossx;
                left=true,right = false;
            }
        }
        else {
            infoboss.f-=4;
            if ( infoboss.f <= 0 )
            {
                infoboss.f=0;
                left=false,right = true;
            }
        }
    }
    if ( resetga >= 1200 && infoboss.s >= 190 && hpboss >= 800 )
    {
        info.clear();
        resetga = 0;
    }
    if ( info.size() == 0 && infoboss.s >= 190 )
    {
        resetga = 0 ;
        for ( auto &u : sample)
        {
            info.push_back({10000,{u.f,-100}});
        }
    }
    j = 0 ;
    int j1 = 0 ;
    bool ktt = true;
    if ( info.size() != sample.size() ) ktt=false;
    for ( auto &u : info)
    {
        if ( u.s.s != sample[j1].s )  ktt = false;
        j1++;
    }
    if ( ktt == true && info[0].f > 1000 )
    {
        for ( auto &u : info)
        {
            u.f=18;
        }
    }
    if ( info.size() == sample.size() && ktt == false ) {
        for ( auto &u : info)
        {
            if ( u.s.s < sample[j].s )u.s.s+=15;
            if ( u.s.s > sample[j].s) u.s.s=sample[j].s;
            j++;
        }

    }
    if ( resetga % 300 == 0 && infoboss.s >= 190  )
    {
        skillboss.push_back({0,{infoboss.f+sizebossx/2-sizedanbossx/2,infoboss.s-sizedanbossy}});
        skillboss.push_back({30,{infoboss.f+sizebossx/2+sizebossx/5+10,infoboss.s-sizedanbossy+45}});
        skillboss.push_back({60,{infoboss.f+sizebossx/2+30+sizebossx/3,infoboss.s-sizedanbossy+105}});
        skillboss.push_back({90,{infoboss.f+sizebossx+20,infoboss.s+sizebossy/2-sizedany/2}});
        skillboss.push_back({120,{infoboss.f+sizebossx/2+50+sizebossx/3,infoboss.s+sizebossy/2-sizedany/2+70}});
        skillboss.push_back({150,{infoboss.f+sizebossx/2+50+sizebossx/5+10,infoboss.s+sizebossy/2-sizedany/2+140}});
        skillboss.push_back({180,{infoboss.f+sizebossx/2-sizedanbossx/2+10,infoboss.s+sizebossy}});
        skillboss.push_back({210,{infoboss.f+sizebossx/2-sizedanbossx/2-90,infoboss.s+sizebossy-35}});
        skillboss.push_back({240,{infoboss.f+sizebossx/2-sizedanbossx/2-160,infoboss.s+sizebossy/2-sizedany/2+80}});
        skillboss.push_back({270,{infoboss.f-50,infoboss.s+sizebossy/2-sizedany/2}});
        skillboss.push_back({300,{infoboss.f-15,infoboss.s-sizedanbossy+105}});
        skillboss.push_back({330,{infoboss.f+15,infoboss.s-sizedanbossy+25}});
    }
    if ( resetga % 100 == 0 )
    {
        double p = tinhgoc(infoboss.f+sizebossx/2,infoboss.s+sizebossy/2,taux,tauy);
        skillboss.push_back({p,{infoboss.f+sizebossx/2-sizedanbossx/2,infoboss.s+sizebossy/2-sizedanbossy/2}});
    }
    if ( hpboss >= 1600 ) SDL_RenderCopy(renderer, fullegg, NULL, &vt);
    else if ( hpboss >= 800 ) SDL_RenderCopy(renderer, brokenegg, NULL, &vt);
    else if ( hpboss > 0 ) SDL_RenderCopy(renderer, metalegg, NULL, &vt);
    hpboss=max(hpboss,0);
    inthanhmau();
    if ( hpboss <= 0 )
    {

        Mix_PlayMusic(winsound, 1);
        //Mix_VolumeMusic(50);
        Mix_PlayChannel(-1, deadsound, 0);
        phaohoaboss={100,infoboss};
        finishround[5]=true;
        for ( auto &u : info)
        {
            u.f = 0 ;
            xulygachet(0);
        }
        vtegg.clear();
        skillboss.clear();
        infoboss.f=infoboss.s = -1000;
    }
}
void man6()
{

}
void gameover()
{
    SDL_Surface* over = TTF_RenderText_Blended(font, "GAME OVER", textcolor);
    SDL_Texture* gover = SDL_CreateTextureFromSurface(renderer, over);
    int* x = new int(300);
    int* y = new int(300);
    score += score1;
    SDL_QueryTexture(gover, NULL, NULL, x, y);
    SDL_Rect* vt = new SDL_Rect{chieudai / 2 - 250 / 2, chieurong / 2 - 150, 250, 75};
    SDL_RenderCopy(renderer, gover, NULL, vt);

    string* s = new string;
    *x = score;
    while (*x > 0)
    {
        int* a = new int(*x % 10);
        *x = *x / 10;
        char* b = new char(*a + '0');
        *s = *b + *s;
        delete a;
        delete b;
    }
    while (s->size() <= 5)
    {
        *s = '0' + *s;
    }
    *s = "LAST SCORE: " + *s;

    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);

    over = TTF_RenderText_Blended(font, s->c_str(), textcolor);
    gover = SDL_CreateTextureFromSurface(renderer, over);

    SDL_QueryTexture(gover, NULL, NULL, x, y);
    *vt = {chieudai / 2 - 350 / 2, chieurong / 2 - 100, 350, 75};
    SDL_RenderCopy(renderer, gover, NULL, vt);

    delete x;
    delete y;
    delete vt;
    delete s;
    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);
}
void inscoreend(int vt)
{
    string *s = new string;
    int *x1 = new int(score);
    while ( *x1 > 0)
    {
        int* a = new int(*x1 % 10);
        *x1 = *x1 / 10;
        char* b = new char(*a + '0');
        *s = *b + *s;
        delete a;
        delete b;
    }
    delete x1;
    while (s->size() <= 5)
    {
        *s = '0' + *s;
    }
    *s = "PERFECT SCORE: "+ *s;
    SDL_Surface* over = TTF_RenderText_Blended(font, s->c_str(), textcolor);
    SDL_Texture* gover = SDL_CreateTextureFromSurface(renderer, over);
    int *x= new int(300), *y= new int(300);
    SDL_QueryTexture(gover, NULL, NULL, x, y);
    SDL_Rect* vt1 = new SDL_Rect{chieudai / 2 - 380 / 2, vt, 380, 75};
    SDL_RenderCopy(renderer, gover, NULL, vt1);
    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);
    delete s;
}
void inlive()
{
    SDL_Rect vtboard = {0,0,300,75};
    SDL_RenderCopy(renderer, board, NULL, &vtboard);
    int vt = 175 ;
    for ( int i = 1 ; i <= live ;i++)
    {
        SDL_Rect vtheart = {vt,25,30,25};
        SDL_RenderCopy(renderer, heart, NULL, &vtheart);
        vt+=30;
    }
}
void inscore()
{
    if (score1 > 0)
    {
        score1 -= 5;
        score += 5;
    }

    string* s = new string;
    int* x = new int(score);

    while (*x > 0)
    {
        int* a = new int(*x % 10);
        *x = *x / 10;
        char* b = new char(*a + '0');
        *s = *b + *s;
        delete a;
        delete b;
    }

    while (s->size() <= 5)
    {
        *s = '0' + *s;
    }
    SDL_Surface* over = TTF_RenderText_Blended(font, s->c_str(), textcolor);
    SDL_Texture* gover = SDL_CreateTextureFromSurface(renderer, over);

    int* yValue = new int(300);
    SDL_Rect* vt = new SDL_Rect{0, -25, 130, 100};
    int* xValue = new int;
    SDL_QueryTexture(gover, NULL, NULL, xValue, yValue);
    SDL_RenderCopy(renderer, gover, NULL, vt);

    delete x;
    delete yValue;
    delete vt;
    delete s;
    SDL_FreeSurface(over);
    SDL_DestroyTexture(gover);
}
void xulygachet( int i)
{
    pair<int,pair<int,int>> &u = info[i];
    vtsmoke.push_back({20,{u.s.f+sizegax/2-30,u.s.s+sizegay/2-30}});
    if ( finishround[5] == false ) Mix_PlayChannel(-1, chickensound, 0);
    score1+=100;
    int r = rand()%50+1;
    if ( info.size() == 1 ) {
        if ( sodan == 1  ) r=1;
        else if ( sodan <= 2 && finishround[1] == true ) r=1;
        else if ( sodan <= 3 && finishround[2] == true ) r=1;
        else if ( sodan <= 4 && finishround[3] == true ) r=1;
    }
    if ( r == 1 ) {
        vtupgrade.push_back({u.s.f+sizegax/2-10,u.s.s+sizegay});
    }

    info.erase(info.begin()+i);
    if ( finishround[3] == true && finishround[4] == false )
    {
        skill.erase(skill.begin()+i);
    }
}
void solvegame()
{
    int i = 0 ;
    int dem = 0 ;
    for ( auto &u : info)
    {
        if (timegame % 4 == 1 ) sizegax = 80;
        else sizegax = 90 , sizegay = 76;
        SDL_Rect vtga = {u.s.f,u.s.s,sizegax,sizegay};
        if ( timegame % 2 == 0 ) SDL_RenderCopy(renderer, chicken2, NULL, &vtga);
        else if ( timegame % 4 == 1 ) {
            vtga = {u.s.f,u.s.s,sizegax,sizegay};
            SDL_RenderCopy(renderer, chicken1, NULL, &vtga);
        }
        else SDL_RenderCopy(renderer, chicken3, NULL, &vtga);

    }
    for ( auto &u : info)
    {
        int r = rand()%(info.size()*70)+1;
        if ( u.s.s > -sizegay) dem++;
        if ( dem > 0 ) {
            if ( r == 1 && u.s.f <= chieudai)
            {
                vtegg.push_back({u.s.f+sizegax/2-10,u.s.s+sizegay});
            }
            else if ( r == 1 )
            {
                int r1 = rand()%(dem);
                vtegg.push_back({info[r1].s.f+sizegax/2-10,info[r1].s.s+sizegay});
            }
        }
        bool trungdan = false;
        int j = 0 ;
        for ( auto &u1 : bullet)
        {
            if ( u1.f+sizedanx >= u.s.f && u1.f <= u.s.f+sizegax && u1.s <= u.s.s+sizegay && u1.s >= u.s.s)
            {
                bullet.erase(bullet.begin()+j);

                vtphaohoa.push_back({25,{u.s.f+sizegax/2-72,u.s.s+sizegay-72}});
                if ( loaidan == 1 ) u.f-=3;
                else u.f-=4;
                if ( u.f <= 0 )
                {
                    xulygachet(i);
                    dem--;
                    i--;
                    break;
                }
                j--;
            }
            j++;
        }
        j=0;
        for ( auto &u1 : bullettrai)
        {
            SDL_Rect vt1 = {u.s.f,u.s.s,sizegax,sizegay};
            SDL_Rect vt2 = {u1.f,u1.s,sizedanx,sizedany};
            double angle = 360.0-14.07;
            if ( ktgiaonhau1(vt1,angle,vt2) == true )
            {
                bullettrai.erase(bullettrai.begin()+j);

                vtphaohoa.push_back({25,{u.s.f+sizegax/2-72,u.s.s+sizegay-72}});
                if ( loaidan == 1 ) u.f-=3;
                else u.f-=4;
                if ( u.f <= 0 )
                {
                    xulygachet(i);
                    dem--;
                    i--;
                    break;
                }
                j--;
            }
            j++;
        }
        j=0;
        for ( auto &u1 : bulletphai)
        {
            SDL_Rect vt1 = {u.s.f,u.s.s,sizegax,sizegay};
            SDL_Rect vt2 = {u1.f,u1.s,sizedanx,sizedany};
            double angle = 14.07;
            if ( ktgiaonhau1(vt1,angle,vt2) == true )
            {
                bulletphai.erase(bulletphai.begin()+j);
                vtphaohoa.push_back({25,{u.s.f+sizegax/2-72,u.s.s+sizegay-72}});
                if ( loaidan == 1 ) u.f-=3;
                else u.f-=4;
                if ( u.f <= 0 )
                {
                    xulygachet(i);
                    dem--;
                    i--;
                    break;
                }
                j--;
            }
            j++;
        }
        i++;
    }
    i = 0 ;
    for ( auto &u : vtphaohoa)
    {

         if ( u.f > 20 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 147*100/147,141*100/147};
             SDL_RenderCopy(renderer, phaohoa1, NULL, &vt);
         }
         else if ( u.f > 15 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 178*100/147,166*100/147};
             SDL_RenderCopy(renderer, phaohoa2, NULL, &vt);
         }
         else if ( u.f > 10 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 189*100/147,212*100/147};
             SDL_RenderCopy(renderer, phaohoa3, NULL, &vt);
         }
         else if ( u.f > 5 )
         {
             SDL_Rect vt = {u.s.f,u.s.s, 212*100/147,204*100/147};
             SDL_RenderCopy(renderer, phaohoa4, NULL, &vt);
         }
         else
         {
             SDL_Rect vt = {u.s.f,u.s.s, 184*100/147,196*100/147};
             SDL_RenderCopy(renderer, phaohoa5, NULL, &vt);
         }
         u.f--;
         if ( u.f <= 0 )
         {
             vtphaohoa.erase(vtphaohoa.begin()+i);
             i--;
         }
         i++;
    }
    i=0;
    for ( auto &u : info)
    {
        if ( ktgiaonhau(u.s.f,u.s.s,sizegax,sizegay,taux,tauy,sizetaux,sizetauy) == true && dead <= 0 )
        {
            live--;
            int sodan1 = sodan;
            sodan++;
            sodan/=2;
            int change = sodan1-sodan;
            levelthunder-=(change)*20;
            Mix_PlayChannel(-1, deadsound, 0);
            if ( live == 0 ) continue ;
            dead = 400;
        }
    }
    i=0;
    for ( auto &u : vtegg)
    {
        SDL_Rect vt = {u.f,u.s, 20,29};
        SDL_RenderCopy(renderer, egg, NULL, &vt);
        u.s+=2;
        if ( u.s >= chieurong-25 ) {

            vttrungvo.push_back({300,u});
            Mix_PlayChannel(-1, trungvosound, 0);
            vtegg.erase(vtegg.begin()+i);
            i--;
        }
        i++;
    }
    i=0;
    for ( auto &u : vtegg)
    {
        if ( ktgiaonhau(u.f,u.s,20,29,taux,tauy,sizetaux,sizetauy) == true && dead <= 0 )
        {
            live--;
            int sodan1 = sodan;
            sodan++;
            sodan/=2;
            int change = sodan1-sodan;
            levelthunder-=(change)*20;
            Mix_PlayChannel(-1, deadsound, 0);
            vtegg.erase(vtegg.begin()+i);
            if ( live == 0 ) continue ;
            dead= 400;

            i--;
            SDL_Rect vt = {taux-50,tauy-50,200,200};
            SDL_RenderCopy(renderer, vuno, NULL, &vt);

        }
        i++;
    }
    if ( ktgiaonhau(infoboss.f,infoboss.s,sizebossx,sizebossy,taux,tauy,sizetaux,sizetauy) == true && dead <= 0 && finishround[4] == true )
    {
        live--;
        int sodan1 = sodan;
        sodan++;
        sodan/=2;
        int change = sodan1-sodan;
        levelthunder-=(change)*20;
        Mix_PlayChannel(-1, deadsound, 0);
        if ( live > 0 ) {
            dead= 400;
            SDL_Rect vt = {taux-50,tauy-50,200,200};
            SDL_RenderCopy(renderer, vuno, NULL, &vt);
        }
    }
    i=0;
    for ( auto &u : vttrungvo )
    {
        SDL_Rect vt = {u.s.f,u.s.s, 35,18};
        SDL_RenderCopy(renderer, trungvo, NULL, &vt);
        u.f--;
        if ( u.f <= 0 )
        {
            vttrungvo.erase(vttrungvo.begin()+i);
            i--;
        }
        i++;
    }
    i=0;
    for ( auto &u : vtsmoke )
    {
        SDL_Rect vt = {u.s.f,u.s.s, 75,75};
        SDL_RenderCopy(renderer, smoke, NULL, &vt);
        u.f--;
        if ( u.f <= 0 )
        {
            vtsmoke.erase(vtsmoke.begin()+i);
            i--;
        }
        i++;
    }
    i = 0 ;
    for ( auto &u : vtupgrade)
    {
        SDL_Rect vt = {u.f,u.s, sizeupx,sizeupy};
        if ( timegame % 2 == 0  ) SDL_RenderCopy(renderer, upgrade1, NULL, &vt);
        else SDL_RenderCopy(renderer, upgrade2, NULL, &vt);
        u.s+=2;
        if ( u.s >= chieurong )
        {
            vtupgrade.erase(vtupgrade.begin()+i);
            i--;
        }
        else {
            if ( ktgiaonhau(u.f,u.s,sizeupx,sizeupy,taux,tauy,sizetaux,sizetauy) == true )
            {
                vtupgrade.erase(vtupgrade.begin()+i);
                i--;
                sodan++;
                levelthunder+=20;
                levelthunder=min(levelthunder,150);
                sodan=min(sodan,5);
            }
        }
        i++;
    }
    int r = rand()%500;
    if ( r == 1 && hopqua.size() == 0 )
    {
        int r1 =rand()%1400+1;
        int r2 = rand()%3+1;
        hopqua.push_back({r2,{r1,-100}});
    }
    i = 0 ;
    for ( auto &u : hopqua)
    {
        u.s.s+=3;
        if (u.s.s > chieurong ) {
            hopqua.erase(hopqua.begin()+i);
            i--;
        }
        else if ( ktgiaonhau(u.s.f,u.s.s,sizequax,sizequay,taux,tauy,sizetaux,sizetauy) == true )
        {
            if (u.f != 3 ) loaidan = u.f , danthunder = false;
            else danthunder = true;
            hopqua.erase(hopqua.begin()+i);
            i--;
        }
        i++;
    }
    for ( auto &u : hopqua)
    {
        SDL_Rect vtkhoi = {u.s.f,u.s.s,40,46};
        if ( time1 % 16 <= 3 )
        {
            if ( u.f == 2 ) SDL_RenderCopy(renderer, quado1, NULL, &vtkhoi);
            else if ( u.f == 1 ) SDL_RenderCopy(renderer, quavang1, NULL, &vtkhoi);
            else SDL_RenderCopy(renderer, quatrang1, NULL, &vtkhoi);
        }
        else if ( time1 % 16 <= 7 )
        {
             if ( u.f == 2 ) SDL_RenderCopy(renderer, quado2, NULL, &vtkhoi);
             else if ( u.f == 1 ) SDL_RenderCopy(renderer, quavang2, NULL, &vtkhoi);
             else SDL_RenderCopy(renderer, quatrang2, NULL, &vtkhoi);
        }
        else if ( time1 % 16 <= 11 )
        {
            if ( u.f == 2 ) SDL_RenderCopy(renderer, quado3, NULL, &vtkhoi);
            else if ( u.f == 1 ) SDL_RenderCopy(renderer, quavang3, NULL, &vtkhoi);
            else SDL_RenderCopy(renderer, quatrang3, NULL, &vtkhoi);
        }
        else
        {
             if ( u.f == 2 ) SDL_RenderCopy(renderer, quado4, NULL, &vtkhoi);
             else if ( u.f == 1 ) SDL_RenderCopy(renderer, quavang4, NULL, &vtkhoi);
             else SDL_RenderCopy(renderer, quatrang4, NULL, &vtkhoi);
        }
    }
    int j= 0;
    for ( auto &u : skillboss)
    {
        SDL_Rect vt = {u.s.f,u.s.s,30,85};
        SDL_RenderCopyEx(renderer,laserboss , NULL, &vt, u.f, NULL, SDL_FLIP_NONE);
        double a,b;
        if ( u.f < 90 )
        {
            b = 2 ;
            if ( u.f == 30 ) b= 2.5;
            double p = sin(pi/(180.0/u.f))/sin(pi/(180.0/(90.0-u.f)));
            a = b*p;
            if (a > 5 )
            {
                double o = a/5;
                a=5;
                b=b/o;
            }
            u.s.f+=a;
            u.s.s-=b;
        }
        else if ( u.f < 180 )
        {
            b = 4 ;
            if ( u.f == 150 ) b=2;
            double o = 90-(180-u.f);
            double p = sin(pi/(180.0/o))/sin(pi/(180.0/(90.0-o)));
            a = b*p;
            if ( a > 5)
            {
                o = a/5;
                a=5;
                b=b/o;
            }
            u.s.f+=b;
            u.s.s+=a;
        }
        else if (u.f < 270)
        {
            a = 3 ;
            if ( u.f == 240 ) a=2.5;
           double alpha = 270-u.f;
           if ( u.f == 180 )
           {
               u.s.s+=3;
           }
           else {
                double p = sin(pi/(180.0/alpha))/sin(pi/(180.0/(90.0-alpha)));
                b = a/p;
                if ( b > 5 )
                {
                    double o = b/5;
                    b=5;
                    a=a/o;
                }
                u.s.f-=b;
                u.s.s+=a;
           }
        }
        else {
            b = 2 ;
            if ( u.f == 330 ) b=2.5;
            double alpha = (360-u.f);
            if ( u.f == 270 )
            {
                u.s.f-=4;
            }
            else {
                double p = sin(pi/(180.0/alpha))/sin(pi/(180.0/(90.0-alpha)));
                a = b*p;
                if ( a > 5 )
                {
                    double o = a/5;
                    a=5;
                    b=b/o;
                }
                u.s.f-=a;
                u.s.s-=b;
            }
        }
        if ( u.s.f <= -100 || u.s.f >= chieudai+100 || u.s.s <= -100 || u.s.s >= chieurong+100 )
        {
            skillboss.erase(skillboss.begin()+j);
            j--;
        }
        j++;
    }
    j = 0 ;
    for ( auto &u : skillboss)
    {
        SDL_Rect x1 = {u.s.f,u.s.s,sizedanbossx,sizedanbossy};
        SDL_Rect x2 = {taux,tauy,sizetaux,sizetauy};
        if ( ktgiaonhau1(x1,u.f,x2) == true && dead <= 0 )
        {
            live--;
            int sodan1 = sodan;
            sodan++;
            sodan/=2;
            int change = sodan1-sodan;
            levelthunder-=(change)*20;
            Mix_PlayChannel(-1, deadsound, 0);
            skillboss.erase(skillboss.begin()+j);
            if ( live == 0 ) continue ;
            dead= 400;

            j--;
            SDL_Rect vt = {taux-50,tauy-50,200,200};
            SDL_RenderCopy(renderer, vuno, NULL, &vt);

        }
        j++;
    }
}
void xulidan()
{
    for ( auto &u : bullet)
    {
        SDL_Rect vtdan = {u.f,u.s,sizedanx,sizedany};
        if ( loaidan == 1 ) SDL_RenderCopy(renderer, dan1, NULL, &vtdan);
        else if ( loaidan == 2 ) SDL_RenderCopy(renderer, dando, NULL, &vtdan);
        if ( loaidan == 1 ) (u.s)-=10;
        else if ( loaidan == 2 ) (u.s)-=5;
    }
    for ( auto &u : bullettrai)
    {
        SDL_Rect vt = {u.f,u.s,sizedanx,sizedany};
        double angle = 360.0-14.07;
        if ( loaidan == 1 ) SDL_RenderCopyEx(renderer,dan1 , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        else if ( loaidan == 2 ) SDL_RenderCopyEx(renderer,dando , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        if ( loaidan == 1 ) (u.s)-=8, u.f -=2;
        else if ( loaidan == 2 ) (u.s)-=4,u.f-=1;
    }
    for ( auto &u : bulletphai)
    {
        SDL_Rect vt = {u.f,u.s,sizedanx,sizedany};
        double angle = 14.07;
        if ( loaidan == 1 ) SDL_RenderCopyEx(renderer,dan1 , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        else if ( loaidan == 2 ) SDL_RenderCopyEx(renderer,dando , NULL, &vt, angle, NULL, SDL_FLIP_NONE);
        if ( loaidan == 1 ) (u.s)-=8, u.f +=2;
        else if ( loaidan == 2 ) (u.s)-=4,u.f+=1;
    }
    while (bullet.size() > 0 && bullet.back().s <= -60 ) bullet.pop_back();
    while (bullettrai.size() > 0 && (bullettrai.back().s <= -60||bullettrai.back().f <= -100)  ) bullettrai.pop_back();
    while (bulletphai.size() > 0 && (bulletphai.back().s <= -60||bulletphai.back().f >= chieudai +100)  ) bulletphai.pop_back();
}
void inplay(int x, int y)
 {
    if ( live <= 0 )
    {

        score+=score1;
        score1=0;

        timestop();
        dead = 0 ;
        SDL_Rect vt = {x-50,y-50,200,200};
        SDL_RenderCopy(renderer, vuno, NULL, &vt);
        gameover();
        inmenu();
        inexit();
        return ;
    }
    if ( ybgr >= chieurong ) ybgr = 0;

    time1++;
    if ( finishround[5] == false ) ybgr++;
    else if ( timeendgame <= 800 ) {
        ybgr+=15;
        timeendgame++;
        if ( timeendgame <= 666 ) score+=15;
        else if ( timeendgame == 667 ) score+=10;
    }
    if ( timeendgame> 800 && timeendgame <= 950 )
    {
        timeendgame++;
        Mix_VolumeMusic(0);
    }
    else if ( timeendgame <= 951+255 && timeendgame > 950)
    {
        SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);
        SDL_SetTextureAlphaMod(background, timeendgame-951);
        vtbackground = {0,ybgr,chieudai,chieurong};
        SDL_RenderCopy(renderer, background, NULL, &vtbackground);
        SDL_Rect vt1 = {0,-chieurong+ybgr,chieudai,chieurong};
        SDL_RenderCopy(renderer, background, NULL, &vt1);
        ybgr++;
        timeendgame+=2;
    }
    else if ( timeendgame <= 800 || timeendgame > 951+255) {
        if ( chieurong-(timeendgame - 951-255)+500 > -500 ) {
            vtbackground = {0,ybgr,chieudai,chieurong};
            SDL_RenderCopy(renderer, background, NULL, &vtbackground);
            SDL_Rect vt1 = {0,-chieurong+ybgr,chieudai,chieurong};
            SDL_RenderCopy(renderer, background, NULL, &vt1);
            ybgr++;
             vt1 = {phaohoaboss.s.f,phaohoaboss.s.s,400,400};
            if ( phaohoaboss.f > 80 ) SDL_RenderCopy(renderer, phaohoa1, NULL, &vt1);
            else if ( phaohoaboss.f > 60 ) SDL_RenderCopy(renderer, phaohoa2, NULL, &vt1);
            else if ( phaohoaboss.f > 40 ) SDL_RenderCopy(renderer, phaohoa3, NULL, &vt1);
            else if ( phaohoaboss.f > 20 ) SDL_RenderCopy(renderer, phaohoa4, NULL, &vt1);
            else if ( phaohoaboss.f > 0 ) SDL_RenderCopy(renderer, phaohoa5, NULL, &vt1);
            phaohoaboss.f--;
        }
        if ( timeendgame > 951+255 )
        {
            if ( timeendgame <= 951+257 ) {
                Mix_PlayMusic(musicend, -1);
                Mix_VolumeMusic(50);
            }
            int u = chieurong-(timeendgame - 951-255);
            SDL_Rect vt2 = {chieudai/2-875/2,u,875,285};
            int u1 = u + 500;
            SDL_Rect vt3 = {chieudai/2-875/2,u1,875,285};
            SDL_RenderCopy(renderer, end1, NULL, &vt2);
            SDL_RenderCopy(renderer, end2, NULL, &vt3);
            inscoreend(u1+300);
            if ( u1 <= -500 && u1 >= -650 )
            {
                SDL_RenderClear(renderer);
               // SDL_RenderCopy(renderer, backgroundend, NULL, NULL);
            }
            else if ( u1 < -650 && (-650-u1)*2 <= 255 )
            {
                SDL_SetTextureBlendMode(backgroundend, SDL_BLENDMODE_BLEND);
                SDL_SetTextureAlphaMod(backgroundend, (-650-u1)*2);
                SDL_RenderCopy(renderer, backgroundend, NULL, NULL);
                SDL_SetTextureBlendMode(menu1, SDL_BLENDMODE_BLEND);
                SDL_SetTextureAlphaMod(menu1, (-650-u1)*2);
                SDL_SetTextureBlendMode(exit1, SDL_BLENDMODE_BLEND);
                SDL_SetTextureAlphaMod(exit1, (-650-u1)*2);
                SDL_Rect* bigremuse = new SDL_Rect{chieudai/2-174/2,500,174,74};
                if ( motionmenu == false ) SDL_RenderCopy(renderer,menu1,NULL,bigremuse);
                else SDL_RenderCopy(renderer,menu2,NULL,bigremuse);
                delete bigremuse;
                SDL_Rect* bigremuse1 = new SDL_Rect{chieudai/2-174/2,650,174,74};
                if ( motionexit == false ) SDL_RenderCopy(renderer,exit1,NULL,bigremuse1);
                else SDL_RenderCopy(renderer,exit2,NULL,bigremuse1);
                delete bigremuse1;

            }
            else if ( (-650-u1)*2 > 255 && u1 < -650 )
            {
                SDL_RenderCopy(renderer, backgroundend, NULL, NULL);
                inmenu();
                inexit();
                SDL_ShowCursor(1);
            }
            timeendgame++;
        }

    }
    SDL_Rect vttau = {x,y,sizetaux,sizetauy};

    if ( (dead == 0 || disappear ==0) && (timeendgame <= 800) ) {

        SDL_Rect vtkhoi = {x+sizetaux/2-30,y+sizetauy-12,60,130};
        if ( dead == 0 || dead <= 300 ) {
            if ( time1 % 5 == 1 )
            {
                SDL_RenderCopy(renderer, mot, NULL, &vtkhoi);
            }
            else if ( time1 % 5 == 2 )
            {
                SDL_RenderCopy(renderer, hai, NULL, &vtkhoi);
            }
            else if ( time1 % 5 == 3 )
            {
                SDL_RenderCopy(renderer, ba, NULL, &vtkhoi);
            }
            else if ( time1 % 5 == 4 )
            {
                SDL_RenderCopy(renderer, bon, NULL, &vtkhoi);
            }
            else {
                SDL_RenderCopy(renderer, nam, NULL, &vtkhoi);
            }
        }
        SDL_RenderCopy(renderer, tau, NULL, &vttau);
    }
    if ( blaster.f > 0 && timeendgame <=800)
    {
        blaster.f--;
        SDL_Rect vt = {blaster.s.s.f,blaster.s.s.s,levelthunder,blaster.s.f};
        SDL_RenderCopy(renderer, thunder, NULL, &vt);
    }
    if ( dead > 0 ) dead--;
    if ( dead == 0 ) disappear = 1;
    if ( dead % 15 == 0 ) disappear = 1-disappear;
    if ( timeman > 0 ) inman();
    else {

        if ( finishround[0] == false )
        {
            finishround[0]=true;
            int x1 = 0 ;
            for ( int i = 1 ; i <= 40 ; i++)
            {
                info.push_back({9,{chieudai+(i-1)*sizegax+x1,0}});
                x1+=20;
            }
        }
        else if ( finishround[1] == false ) man1();
        else if (finishround[2] == false) man2();
        else if ( finishround[3] == false ) man3();
        else if ( finishround[4] == false ) man4();
        else if ( finishround[5] == false ) manboss();
        else man6();
    }
    if ( timeendgame <= 800 ) {
    solvegame();


    inlive();
    inscore();
    }
    if ( live <= 0 ) return ;
    if ( timeendgame <= 800 ) {xulidan();inlive();inscore();}
}
