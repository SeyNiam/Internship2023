// Internship.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include <vector>


using namespace std;


class Player {
public:
    Player(){
        n = h = w = s = r = p = 0;
        cat = 3;
    }

    void Print() {
        cout << "\n " << n << "\t Рост: " << h << "\t Размах: " << w << "\t Очки: " << s << "\t Подборы: " << r << "\t Передачи: " << p << "\t Категория: " << cat << endl;
    }

    int n; // Номер
    int h; // Рост
    int w; // Размах рук
    int s; // Среднее количество очков за матч
    int r; // Среднее количество подборов за матч
    int p; // Среднее количество передач за матч
    int cat; // Категория: 0 - единорог, 1 - игрок, достойный выбора в первом раунде, 2 - во втором, 3 - не стоит выбирать
};

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
        cout << "Ошибка открытия файла!\n";
    }
    else {
        //cout << "Файл открыт!\n";
        fout.write((char*)&p, sizeof(Player));
    }
    fout.close();
}

void readDB(string path) {
    ifstream fin;
    fin.open(path, ofstream::app);

    if (!fin.is_open()) {
        cout << "Ошибка открытия файла!\n";
    }
    else {
        //cout << "Файл открыт!\n";
        Player p;
        while (fin.read((char*)&p, sizeof(Player))) {
            p = giveCat(p);
            //writeDB(path, p);
            p.Print();
        }
    }
    fin.close();
}


void taskOne() {
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

}




int taskTwo() {
    int n;
    cout << "\nВведите количество кроликов (1-200 000): ";
    cin >> n;
    while (n > 200000 || n < 1) {
        cout << "\tОШИБКА\n\tВведите количество кроликов (1-200 000): ";
        cin >> n;
    }
    cout << "\n";

    int* weights = new int[n];
    int* weights_reset = new int[n];

    for (int i = 0; i < n; i++) {
        int j = i + 1;
        cout << "Введите вес кролика " << j << " (1-109): ";
        cin >> weights[i];
        while (weights[i] > 109 || weights[i] < 1) {
            cout << "\tОШИБКА\n\tВведите вес кролика " << j << " (1-109): ";
            cin >> weights[i];
        }
        while(weights[i] < weights[i - 1] && i > 0) {
            cout << "\tОШИБКА\n\tВведите вес кролика " << j << " (1-109) и больше предыдущего: ";
            cin >> weights[i];
        }
        weights_reset[i] = weights[i];
    }

    int m;
    cout << "\nВведите количество запросов (1-200 000): ";
    cin >> m;
    while (m > 200000 || m < 1) {
        cout << "\tОШИБКА\n\tВведите количество запросов (1-200 000): ";
        cin >> m;
    }

    for (int i = 0; i < m; i++) {
        int li, ri;
        cout << "\nВведите границы шеренги (от 1 до " << n << " и нижняя граница должна быть меньше большей): ";
        cin >> li >> ri;
        while (li >= ri || li < 1 || ri > n) {
            cout << "\tОШИБКА\n\tВведите границы шеренги (от 1 до " << n << " и нижняя граница должна быть меньше большей): ";
            cin >> li >> ri;
        }

        int days = 0;
        /*
        int max_weight = 0; // Максимальный вес кролика в шеренге

        // Сортировка в шеренгу по возрастанию
        
        for (int i = li-1; i < ri-1; i++) {
            for (int j = li - 1; j < ri - i - 1; j++) {
                if (weights[j] > weights[j + 1]) {
                    // Обмен элементов
                    int temp = weights[j];
                    weights[j] = weights[j + 1];
                    weights[j + 1] = temp;
                }
            }
        }
        */

        days = weights[ri - 1] - weights[li - 1];

        // Проходим по кроликам от li до ri-1 и проверяем условие wi != wi+1 (вес текущего не равен весу следующего). 
        // Если оно выполняется, увеличиваем вес i-го кролика на 1 и обновляем значение max_weight
        /*
        for (int i = li - 1; i < ri - 1; i++) {
            if (weights[i] != weights[i + 1]) {
                //weights[i]++;
                max_weight = max(max_weight, weights[i]);
            }
        }
        cout << "max_weight " << max_weight << endl;
        
        // Повторяем, пока max_weight < wri-1 (вес последнего кролика в шеренге).
        while (max_weight < weights[ri - 1]) {
            for (int i = li - 1; i < ri - 1; i++) {
                if (weights[i] != weights[i + 1]) {
                    weights[i]++;
                    max_weight = max(max_weight, weights[i]);
                }
            }
            days++;
        }
        */



        cout << "Количество дней, после которых вес кроликов не будет меняться: " << days << endl;

        /*
        // Восстановление массива в прежнее состояние перед следующей итерацией
        for (int i = 0; i < n; i++) {
            weights[i] = weights_reset[i];
            //cout << "weights[" << i << "] " << weights[i] << endl;
        }
        */
    }

    delete[] weights; // Освобождение памяти
    delete[] weights_reset;

    return 0;
}





int main()
{
    setlocale(LC_ALL, "Russian"); // Русская локализация консоли

    int choise = 1;
    while (choise != 0) {
        cout << "\n\nМеню\n 1 - Первое задание (44)\n 2 - Второе задание (57)\n 0 - Выход\n>> ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            taskOne();
            break;
        case 2:
            taskTwo();
            break;
        case 0:
            break;
        default:
            break;
        }
    }

    /*
    string tmp;
    tmp = taskOne();
    cout << "\n" << tmp << endl;
    */

    return 0;
}

