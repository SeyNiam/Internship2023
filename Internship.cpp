// Internship.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

using namespace std;


class Player {
public:
    Player(){
        h = w = s = r = p = 0;
        cat = 3;
    }
    Player(int h, int w, int s, int r, int p) {
        this->h = h;
        this->w = w;
        this->s = s;
        this->r = r;
        this->p = p;
    }

    void Print() {
        cout << "\n " << n << "\tH: " << h << "\tW: " << w << "\tS: " << s << "\tR: " << r << "\tP: " << p << "\tCategory: " << cat << endl;
    }

    int n; // Номер
    int h; // Рост
    int w; // Размах рук
    int s; // Среднее количество очков за матч
    int r; // Среднее количество подборов за матч
    int p; // Среднее количество передач за матч
    int cat; // Категория: 0 - единорог, 1 - игрок, достойный выбора в первом раунде, 2 - во втором, 3 - не стоит выбирать
};

/*
struct player
{
    int n; // Номер
    int h; // Рост
    int w; // Размах рук
    int s; // Среднее количество очков за матч
    int r; // Среднее количество подборов за матч
    int p; // Среднее количество передач за матч
    int cat; // Категория: 0 - единорог, 1 - игрок, достойный выбора в первом раунде, 2 - во втором, 3 - не стоит выбирать
};
*/


/*
// запись структуры в файл
int save(char* filename, struct player* p)
{
    FILE* fp;
    char* c;
    int size = sizeof(struct player); // количество записываемых байтов

    fp = fopen(filename, "wb"); //открываем файл для бинарной записи
    if (!fp)    // если не удалось открыть файл
    {
        printf("Error occured while opening file \n");
        return 1;
    }
    // устанавливаем указатель на начало структуры
    c = (char*)p;
    // посимвольно записываем в файл структуру
    for (int i = 0; i < size; i++)
    {
        putc(*c++, fp);
    }
    fclose(fp);
    return 0;
}

// загрузка из файла структуры
int load(char* filename)
{
    FILE* fp;
    char* c;
    int i; // для считывания одного символа
    // количество считываемых байтов
    int size = sizeof(struct player);
    // выделяем память для считываемой структуры
    struct player* ptr = (player*)malloc(size);
    fp = fopen(filename, "rb");     // открываем файл для бинарного чтения
    if (!fp)
    {
        printf("Error occured while opening file \n");
        return 1;
    }

    // устанавливаем указатель на начало блока выделенной памяти
    c = (char*)ptr;
    // считываем посимвольно из файла
    while ((i = getc(fp)) != EOF)
    {
        *c = i;
        c++;
    }

    fclose(fp);
    // вывод на консоль загруженной структуры
    printf("%5d %5d \n", ptr->n, ptr->h);
    free(ptr);
    return 0;
}
*/



Player giveCat(Player p) {
    int uni = 0; // особые параметры для единорога
    int hi = 0; // количество параметров выше ожидаемого диапазона
    int top = 0; // к-во параметров в верхней половине ожидаемого диапазона
    int mid = 0; // к-во параметров в ожидаемом диапазоне

    // h
    if (p.h > 190) {
        if (p.h >= ((220 + 190) / 2)) {
            if (p.h > 220) {
                mid++;
                top++;
                hi++; // выше ожидаемого диапазона
                uni++;
            }
            else {
                mid++;
                top++; // в верхней половине ожидаемого диапазона
            }
        }
        else
            mid++; // в ожидаемом диапазоне
    }
    // w
    if (p.w > 200) {
        if (p.w >= ((200 + 250) / 2)) {
            if (p.w > 250) {
                mid++;
                top++;
                hi++; // выше ожидаемого диапазона
                uni++;
            }
            else {
                mid++;
                top++; // в верхней половине ожидаемого диапазона
            }
        }
        else
            mid++; // в ожидаемом диапазоне
    }
    // s
    if (p.s > 10) {
        if (p.s >= ((10 + 20) / 2)) {
            if (p.s > 20) {
                mid++;
                top++;
                hi++; // выше ожидаемого диапазона
            }
            else {
                mid++;
                top++; // в верхней половине ожидаемого диапазона
            }
        }
        else
            mid++; // в ожидаемом диапазоне
    }
    // r
    if (p.r > 2) {
        if (p.r >= ((2 + 6) / 2)) {
            if (p.r > 6) {
                mid++;
                top++;
                hi++; // выше ожидаемого диапазона
            }
            else {
                mid++;
                top++; // в верхней половине ожидаемого диапазона
            }
        }
        else
            mid++; // в ожидаемом диапазоне
    }
    // p
    if (p.p > 3) {
        if (p.p >= ((3 + 7) / 2)) {
            if (p.p > 7) {
                mid++;
                top++;
                hi++; // выше ожидаемого диапазона
            }
            else {
                mid++;
                top++; // в верхней половине ожидаемого диапазона
            }
        }
        else
            mid++; // в ожидаемом диапазоне
    }

    /*
    if ((hi >= 1 && top >= hi+1) || (top >= 3)) {
        if ((hi >= 2 && top >= hi+1) || (mid >= top+5 && top >= 3)) {
            if (hi >= 3 && uni >= 1) {
                p.cat = 0;
            }
            else
                p.cat = 1;
        }
        else
            p.cat = 2;
    }
    else
        p.cat = 3;
    */



    p.cat = 3;
    if ((hi >= 1 && top >= hi + 1 || hi >= hi + 1) || (top >= 3)) {
        p.cat = 2;
    }
    if ((hi >= 2 && top >= hi + 1 || hi >= hi + 1) || (mid >= top + 5 && top >= 3)) {
        p.cat = 1;
    }
    if (hi >= 3 && uni >= 1) {
        p.cat = 0;
    }



    return p;
}





void writeDB(string path, Player p) {
    ofstream fout;
    fout.open(path, ofstream::app);

    if (!fout.is_open()) {
        cout << "File opening error!\n";
    }
    else {
        //cout << "File is open!\n";
        fout.write((char*)&p, sizeof(Player));
    }
    fout.close();
}


void readDB(string path) {
    ifstream fin;
    fin.open(path, ofstream::app);

    if (!fin.is_open()) {
        cout << "File opening error!\n";
    }
    else {
        //cout << "File is open!\n";
        Player p;
        while (fin.read((char*)&p, sizeof(Player))) {
            //p.Print();
            p = giveCat(p);
            //writeDB(path, p);
            p.Print();
        }
    }
    fin.close();
}







void taskOne() {
    /* TODO:
    - Понять что происходит
    - Сделать
    - Вывести результат на экран
    - Вывести результат на экран красиво
    */

    string path = "bd.txt";

    Player player;
    /*
    for (int i = 0; i <= 1; i++) {
        player.n = i;
        cout << "\nPlease input parameters h, w, s, r and p of player " << i << ": " << endl;
        cin >> player.h >> player.w >> player.s >> player.r >> player.p;
        writeDB(path, player);
    }
    */
    srand(time(NULL));
    for (int i = 0; i < 32; i++) {
        player.n = i;
        player.h = rand() % 101 + 150;
        player.w = rand() % 121 + 150;
        player.s = rand() % 31 + 5;
        player.r = rand() % 11;
        player.p = rand() % 11;
        writeDB(path, player);
    }
    

    readDB(path);



    /*
    player dude;

    char filename[] = "bd.txt";
    // struct player* ptr = load(filename);
    load(filename);
    

    string rez;
    rez = "yoooooooooo suck it green boooiiii";
    return rez;
    */
}



int main()
{
    taskOne();

    /*
    string tmp;
    tmp = taskOne();
    cout << "\n" << tmp << endl;
    */

    return 0;
}

