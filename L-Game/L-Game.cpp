#include <iostream>
#include "graphics.h"
#include "winbgim.h"
#include <windows.h>

using namespace std;
bool gameOver = false;

///Defineste culoarea matricei

int culoare = 15;

///Defineste dimensiunea matricei

int dimmatrice = 4;

int matrice[4][4];

void patrat(int a, int b, int x, int y, int r, int culoare)
{

    setcolor(culoare);
    rectangle(x + b, y + a, x + b + r, y + a + r);
    ///cout<<x+b<<' '<<y+a<<' '<<x+b+r<<' '<<y+a+r<<endl;

}

void moneda(int a, int b, int x, int y, int r, int c)
{
    setcolor(culoare);
    rectangle(x + b, y + a, x + b + r, y + a + r);
    setfillstyle(SOLID_FILL, c);
    circle(x + b + r / 2, y + a + r / 2, r / 2 - 10);
    floodfill(x + b + r / 2, y + a + r / 2, WHITE);
}

void patrat_fill(int a, int b, int x, int y, int r, int culoare)
{

    setfillstyle(SOLID_FILL, culoare);
    bar(x + b, y + a, x + b + r, y + a + r);
    setcolor(WHITE);
    rectangle(x + b, y + a, x + b + r, y + a + r);
    ///cout<<x+b<<' '<<y+a<<' '<<x+b+r<<' '<<y+a+r<<endl;

}

void patrat_empty(int a, int b, int x, int y, int r, int culoare)
{

    setfillstyle(SOLID_FILL, BLACK);
    bar(x + b, y + a, x + b + r, y + a + r);
    setcolor(culoare);
    rectangle(x + b, y + a, x + b + r, y + a + r);
    ///cout<<x+b<<' '<<y+a<<' '<<x+b+r<<' '<<y+a+r<<endl;

}

void fill_reset(int matrice[4][4])
{
    for (int i = 0; i <= dimmatrice; i++)
        for (int j = 0; j <= dimmatrice; j++)
            if (matrice[i + 1][j + 1] == 5)
                matrice[i + 1][j + 1] = 0;
}
void startUpBoard(int matrice[4][4])
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrice[i][j] = 0;
    matrice[1][1] = 3;
    matrice[4][4] = 3;
    matrice[2][2] = 1;
    matrice[3][2] = 1;
    matrice[4][2] = 1;
    matrice[4][3] = 1;
    matrice[1][2] = 2;
    matrice[1][3] = 2;
    matrice[2][3] = 2;
    matrice[3][3] = 2;
}
bool verificareL1(int matrice[4][4])
{
    int i = 0, j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            if (matrice[i][j] == 1)
            {
                //jos
                if (matrice[i + 1][j] == 1)
                {
                    //jos
                    if (matrice[i + 2][j] == 1)
                    {
                        //stanga
                        if (matrice[i + 2][j - 1] == 1)
                            return true;
                        else
                            //dreapta
                            if (matrice[i + 2][j + 1] == 1)
                                return true;

                    }
                }
                //sus
                if (matrice[i - 1][j] == 1)
                {

                    if (matrice[i - 2][j] == 1)
                    {
                        //stanga
                        if (matrice[i - 2][j - 1] == 1)
                            return true;
                        else
                            //dreapta
                            if (matrice[i - 2][j + 1] == 1)
                                return true;
                    }
                }
                //dreapta
                if (matrice[i][j + 1] == 1)
                {
                    //dreapta
                    if (matrice[i][j + 2] == 1)
                    {
                        //sus
                        if (matrice[i + 1][j + 2] == 1)
                            return true;
                        else
                            //jos
                            if (matrice[i - 1][j + 2] == 1)
                                return true;
                    }
                }
                //stanga
                if (matrice[i][j - 1] == 1)
                {
                    //stanga
                    if (matrice[i][j - 2] == 1)
                    {
                        //sus
                        if (matrice[i + 1][j - 2] == 1)
                            return true;
                        else
                            //jos
                            if (matrice[i - 1][j - 2] == 1)
                                return true;
                    }
                }
            }
            j++;
        }
        i++;
        j = 0;
    }
    if (matrice[3][1] == 1 && matrice[4][1] == 1 && matrice[4][2] == 1 && matrice[4][3] == 1)
        return true;
    if (matrice[3][2] == 1 && matrice[4][4] == 1 && matrice[4][2] == 1 && matrice[4][3] == 1)
        return true;
    if (matrice[3][3] == 1 && matrice[4][1] == 1 && matrice[4][2] == 1 && matrice[4][3] == 1)
        return true;
    if (matrice[3][4] == 1 && matrice[4][4] == 1 && matrice[4][2] == 1 && matrice[4][3] == 1)
        return true;
    if (matrice[3][1] == 1 && matrice[4][1] == 1 && matrice[4][2] == 1 && matrice[4][3] == 1)
        return true;
    if (matrice[2][2] == 1 && matrice[3][2] == 1 && matrice[4][2] == 1 && matrice[2][1] == 1)
        return true;
    if (matrice[2][2] == 1 && matrice[3][2] == 1 && matrice[4][2] == 1 && matrice[2][3] == 1)
        return true;
    if (matrice[2][3] == 1 && matrice[3][3] == 1 && matrice[4][3] == 1 && matrice[2][2] == 1)
        return true;
    if (matrice[2][3] == 1 && matrice[3][3] == 1 && matrice[4][3] == 1 && matrice[2][4] == 1)
        return true;
    if (matrice[2][3] == 1 && matrice[3][3] == 1 && matrice[4][3] == 1 && matrice[2][2] == 1)
        return true;
    if (matrice[1][3] == 1 && matrice[1][4] == 1 && matrice[2][4] == 1 && matrice[3][4] == 1)
        return true;
    if (matrice[3][2] == 1 && matrice[3][3] == 1 && matrice[3][4] == 1 && matrice[2][2] == 1)
        return true;
    if (matrice[4][4] == 1 && matrice[3][4] == 1 && matrice[2][4] == 1 && matrice[2][3] == 1)
        return true;
    if (matrice[2][2] == 1 && matrice[2][1] == 1 && matrice[3][1] == 1 && matrice[4][1] == 1)
        return true;
    return false;
}
bool verificareL2(int matrice[4][4])
{
    int i = 0, j = 0;
    while (i < 4)
    {
        while (j < 4)
        {
            if (matrice[i][j] == 2)
            {
                //jos
                if (matrice[i + 1][j] == 2)
                {
                    //jos
                    if (matrice[i + 2][j] == 2)
                    {
                        //stanga
                        if (matrice[i + 2][j - 1] == 2)
                            return true;
                        else
                            //dreapta
                            if (matrice[i + 2][j + 1] == 2)
                                return true;

                    }
                }
                //sus
                if (matrice[i - 1][j] == 2)
                {

                    if (matrice[i - 2][j] == 2)
                    {
                        //stanga
                        if (matrice[i - 2][j - 1] == 2)
                            return true;
                        else
                            //dreapta
                            if (matrice[i - 2][j + 1] == 2)
                                return true;
                    }
                }
                //dreapta
                if (matrice[i][j + 1] == 2)
                {
                    //dreapta
                    if (matrice[i][j + 2] == 2)
                    {
                        //sus
                        if (matrice[i + 1][j + 2] == 2)
                            return true;
                        else
                            //jos
                            if (matrice[i - 1][j + 2] == 2)
                                return true;
                    }
                }
                //stanga
                if (matrice[i][j - 1] == 2)
                {
                    //stanga
                    if (matrice[i][j - 2] == 2)
                    {
                        //sus
                        if (matrice[i + 1][j - 2] == 2)
                            return true;
                        else
                            //jos
                            if (matrice[i - 1][j - 2] == 2)
                                return true;
                    }
                }
            }
            j++;
        }
        i++;
        j = 0;
    }
    if (matrice[3][1] == 2 && matrice[4][1] == 2 && matrice[4][2] == 2 && matrice[4][3] == 2)
        return true;
    if (matrice[3][2] == 2 && matrice[4][4] == 2 && matrice[4][2] == 2 && matrice[4][3] == 2)
        return true;
    if (matrice[3][3] == 2 && matrice[4][1] == 2 && matrice[4][2] == 2 && matrice[4][3] == 2)
        return true;
    if (matrice[3][4] == 2 && matrice[4][4] == 2 && matrice[4][2] == 2 && matrice[4][3] == 2)
        return true;
    if (matrice[3][1] == 2 && matrice[4][1] == 2 && matrice[4][2] == 2 && matrice[4][3] == 2)
        return true;
    if (matrice[2][2] == 2 && matrice[3][2] == 2 && matrice[4][2] == 2 && matrice[2][1] == 2)
        return true;
    if (matrice[2][2] == 2 && matrice[3][2] == 2 && matrice[4][2] == 2 && matrice[2][3] == 2)
        return true;
    if (matrice[2][3] == 2 && matrice[3][3] == 2 && matrice[4][3] == 2 && matrice[2][2] == 2)
        return true;
    if (matrice[2][3] == 2 && matrice[3][3] == 2 && matrice[4][3] == 2 && matrice[2][4] == 2)
        return true;
    if (matrice[2][3] == 2 && matrice[3][3] == 2 && matrice[4][3] == 2 && matrice[2][2] == 2)
        return true;
    if (matrice[1][3] == 2 && matrice[1][4] == 2 && matrice[2][4] == 2 && matrice[3][4] == 2)
        return true;
    if (matrice[3][2] == 2 && matrice[3][3] == 2 && matrice[3][4] == 2 && matrice[2][2] == 2)
        return true;
    if (matrice[4][4] == 2 && matrice[3][4] == 2 && matrice[2][4] == 2 && matrice[2][3] == 2)
        return true;
    if (matrice[2][2] == 2 && matrice[2][1] == 2 && matrice[3][1] == 2 && matrice[4][1] == 2)
        return true;

    return false;
}

/*
Cand matrice[a][b]==0 afiseaza matricea propriu zisa
Cand matrice[a][b]==1 trebuie sa afiseze o casuta de o culoare
Cand matrice[a][b]==2 trebuie sa afiseze o casuta de alta culoare pentru a distinge intre jucatori
Cand matrice[a][b]==3 trebuie sa afiseze o moneda
*/

void meniu()
{
    setcolor(5);
    settextstyle(6, HORIZ_DIR, 10);
    outtextxy(100, 100, "Bonol (L-Game)");

    ///setcolor(2);
    ///bar(290,490,470,560);
    setcolor(15);
    settextstyle(10, HORIZ_DIR, 6);
    outtextxy(300, 500, "Start");

    ///setcolor(2);
    ///bar(290,590,470,660);
    setcolor(15);
    settextstyle(10, HORIZ_DIR, 6);
    outtextxy(300, 600, "Exit");

    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(1000, 700, "Creat de: Decuseara Andrei");
    outtextxy(1000, 720, "          Vasilache Tudor");
}

void end_screen()
{
    cleardevice();
    setcolor(5);
    settextstyle(6, HORIZ_DIR, 10);
    outtextxy(100, 100, "Ai castigat!");
}

void afisarematrice(int dimmatrice, int matrice[4][4], int x, int y, int r, int culoare)
{
    int a = 1, b = 1, ok;
    ///cout<<"Coordonatele patratelor: "<<endl;
    for (int i = 0; i <= dimmatrice * r; i += r)
    {
        b = 1;
        for (int j = 0; j <= dimmatrice * r; j += r)
        {
            if (matrice[a][b] == 0)
            {
                ok = 0;
                patrat(i, j, x, y, r, culoare);
            }
            else
            {
                if (matrice[a][b] == 1 || matrice[a][b] == 8)
                {
                    ok = 1;
                    patrat_fill(i, j, x, y, r, RED);
                }
                else
                {
                    if (matrice[a][b] == 2 || matrice[a][b] == 9)
                    {
                        ok = 1;
                        patrat_fill(i, j, x, y, r, BLUE);
                    }
                    else
                    {
                        if (matrice[a][b] == 5)
                        {
                            ok = 1;
                            patrat_empty(i, j, x, y, r, culoare);
                        }
                        else if (matrice[a][b] == 3)
                        {
                            ok = 1;
                            moneda(i, j, x, y, r, YELLOW);
                        }
                        else if (matrice[a][b] == 6)
                        {
                            patrat_fill(i, j, x, y, r, LIGHTRED);
                        }
                        else if (matrice[a][b] == 7)
                        {
                            patrat_fill(i, j, x, y, r, LIGHTBLUE);
                        }
                    }
                }
            }
            b++;
        }
        a++;
    }
    cout << endl;
}

struct player
{
    int x, y;
    int uid;
    char nume[20];
    int rotation;
};

struct coin
{
    int x, y;
    int uid;
};

player L1, L2;
coin C1, C2;

void backup_matrice(int matrice[4][4], int matrice1[4][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            matrice1[i][j] = matrice[i][j];
}


int main()
{
    dimmatrice = dimmatrice - 1;

    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    cout << screenWidth << " x " << screenHeight << endl;

    initwindow(screenWidth, screenHeight, "", -3, -3);

    int x = 300, y = 100, r = 150, i = 0, j = 0;

    int matrice[4][4], matrice_1[4][4];
    int a = 0, b = 0;

    ///Initializez matricea cu 0
    for (i = 0; i <= dimmatrice; i++)
        for (j = 0; j <= dimmatrice; j++)
            matrice[i][j] = 0;


    ///
    int x_coord = matrice[4][4];
    int y_coord = matrice[4][3];
    int lung = matrice[4][2];
    ///

    /*
    ///Testez daca merge sa am o anumita pozitie plina
    matrice[1][1]=1;
    matrice[1][4]=1;

    matrice[3][1]=1;
    matrice[3][4]=1;

    matrice[4][2]=1;
    matrice[4][3]=1;
    */

    POINT cursorPosition;
    long mX, mY;
    int offsetX, offsetY;
    int nrcoin = 0, casuteplayer1 = 0, casuteplayer2 = 0, el = 0;
    int meniu_var = 1;
    int ok = 0;
    int ok1 = 1;
    int nrmutari = 0, numarari1 = 0, numarari2 = 0;
    while (!gameOver)
    {
        if (ok == 0)
        {
            startUpBoard(matrice);
            ok = 1;
            casuteplayer1 = 4;
            casuteplayer2 = 4;
            nrcoin = 2;
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            gameOver = true;
        }
        GetCursorPos(&cursorPosition);
        if (GetAsyncKeyState(VK_SHIFT))
        {
            end_screen();
            delay(1000);
            closegraph();
            gameOver = true;
        }
        if (meniu_var == 1)
        {
            meniu();
            if (GetAsyncKeyState(VK_LBUTTON))
                if (cursorPosition.x >= (290) && cursorPosition.x <= (470) && cursorPosition.y >= (490) && cursorPosition.y <= (y + 560))
                {
                    meniu_var = 0;
                    cleardevice();
                }
            if (GetAsyncKeyState(VK_LBUTTON))
                if (cursorPosition.x >= (290) && cursorPosition.x <= (470) && cursorPosition.y >= (590) && cursorPosition.y <= (y + 660))
                {
                    getch();
                    closegraph();
                    return 0;
                }
        }
        else
        {
            ///Daca se apasa left click se umple casuta cu culoarea playerului 1
            if (nrcoin == 2 && nrcoin > 1)
            {
                if (nrmutari % 2 == 0)
                    if (GetAsyncKeyState(VK_LBUTTON))
                        if (cursorPosition.x >= (x - 50) && cursorPosition.x <= (x + (dimmatrice + 1) * r + 50) && cursorPosition.y >= (y - 50) && cursorPosition.y <= (y + (dimmatrice + 1) * r + 50))
                            if (matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 0 || matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 6)
                            {
                                if (casuteplayer1 < 4)

                                {
                                    matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 1;
                                    casuteplayer1++;
                                    numarari1++;
                                    if (numarari1 == 4 && verificareL1(matrice))
                                    {
                                        nrmutari += 1;
                                        numarari1 = 0;
                                    }
                                }
                            }

                ///Daca se apasa left click se umple casuta cu culoarea playerului 2
                if (nrmutari % 2 == 1)
                    if (GetAsyncKeyState(VK_LBUTTON))
                        if (cursorPosition.x >= (x - 50) && cursorPosition.x <= (x + (dimmatrice + 1) * r + 50) && cursorPosition.y >= (y - 50) && cursorPosition.y <= (y + (dimmatrice + 1) * r + 50))
                        {
                            if ((matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 0 || matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 7) && casuteplayer2 < 4)
                            {
                                matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 2;
                                casuteplayer2++;
                                numarari2++;
                                {
                                    if (numarari2 == 4 && verificareL2(matrice))
                                    {
                                        nrmutari++;
                                        numarari2 = 0;
                                    }
                                }
                            }
                        }


                ///Daca se apasa shift se sterge ce e in casuta
                if (GetAsyncKeyState(VK_RBUTTON))
                    if (cursorPosition.x >= (x - 50) && cursorPosition.x <= (x + (dimmatrice + 1) * r + 50) && cursorPosition.y >= (y - 50) && cursorPosition.y <= (y + (dimmatrice + 1) * r + 50))
                    {
                        if (matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 3)
                        {
                            nrcoin--;
                            matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 5;

                        }
                        else if (matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 1)
                        {
                            matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 5;
                            casuteplayer1--;
                        }
                        else if (matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 2)
                        {
                            matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 5;
                            casuteplayer2--;
                        }
                        else
                            matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 5;
                    }
            }
            else
            {///Daca se apasa middle click apare o moneda
                if (GetAsyncKeyState(VK_LBUTTON))
                    if (cursorPosition.x >= (x) && cursorPosition.x <= (x + (dimmatrice + 1) * r) && cursorPosition.y >= (y) && cursorPosition.y <= (y + (dimmatrice + 1) * r))
                    {
                        if (nrcoin < 2 && matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] == 0)
                        {
                            matrice[(cursorPosition.y - y) / r + 1][(cursorPosition.x - x) / r + 1] = 3;
                            nrcoin++;
                        }
                    }
            }


            ///Verificarea formei L
            if (casuteplayer1 == 4)
                if (verificareL1(matrice) == false)
                    for (int i1 = 0; i1 < 5; i1++)
                        for (int j1 = 0; j1 < 5; j1++)
                            if (matrice[i1][j1] == 1)
                            {
                                matrice[i1][j1] = 5;
                                casuteplayer1 = 0;
                                numarari1 = 0;
                            }
            if (casuteplayer2 == 4)
                if (verificareL2(matrice) == false)
                    for (int i2 = 0; i2 < 5; i2++)
                        for (int j2 = 0; j2 < 5; j2++)
                            if (matrice[i2][j2] == 2)
                            {
                                matrice[i2][j2] = 5;
                                casuteplayer2 = 0;
                                numarari2 = 0;
                            }

            if (verificareL1(matrice) == true && verificareL2(matrice) == true)
                backup_matrice(matrice, matrice_1);
            //if(casuteplayer1==0 && casuteplayer2==0)
                //backup_matrice(matrice_1,matrice);

            afisarematrice(dimmatrice, matrice, x, y, r, culoare);
            delay(100);
            ///Transforma patrat_empty in patrat
            fill_reset(matrice);
            cout << nrmutari << endl;

        }
    }

    getch();
    closegraph();
    return 0;
}