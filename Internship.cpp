#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

using namespace std;


class Player {
public:
    int n; // Номер
    int h; // Рост
    int w; // Размах рук
    int s; // Среднее количество очков за матч
    int r; // Среднее количество подборов за матч
    int p; // Среднее количество передач за матч
    int cat; // Категория: 0 - единорог, 1 - игрок, достойный выбора в первом раунде, 2 - во втором, 3 - не стоит выбирать
    
    Player(){
        n = h = w = s = r = p = 0;
        cat = 3;
    }

    void Print() {
        cout << "\n " << n << "\t Рост: " << h << "\t Размах: " << w << "\t Очки: " << s << "\t Подборы: " << r << "\t Передачи: " << p << "\t Категория: " << cat << endl;
    }
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

/*
void writeDB(string path, Player p) {
    // Открытие файла на запись
    //ofstream fout;
    //fout.open(path, ofstream::app);
    
    ofstream fout(path, ios::binary | ios::app);

    if (!fout.is_open()) {
        cout << "Ошибка открытия файла!\n";
    }
    else {
        //cout << "Файл открыт!\n";
        //fout.write((char*)&p, sizeof(Player));
        fout.write(reinterpret_cast<char*>(&p), sizeof(Player));
        fout.close();
    }
    

    ofstream fileOut(path, ios::binary | ios::app);
    if (fileOut.is_open()) {
        fileOut.write(reinterpret_cast<char*>(&p), sizeof(p));
        fileOut.close();
        cout << "Объект успешно записан в файл." << endl;
    }
    else {
        cout << "Ошибка при открытии файла." << endl;
    }
    
    
}
*/
/*
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


void readDB(string filePath) {
    //Player players;
    ifstream fileIn(filePath, ios::binary);
    if (fileIn.is_open()) {
        Player player;
        while (fileIn.read(reinterpret_cast<char*>(&player), sizeof(player))) {
            //players.insert(player);
            player = giveCat(player);
            player.Print();
        }
        fileIn.close();
        cout << "Объекты успешно прочитаны из файла." << endl;
    }
    else {
        cout << "Ошибка при открытии файла." << endl;
    }
    //return players;
}
*/


void writeDB(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    Player players[32];
    srand(time(NULL));
    for (int i = 0; i < 32; i++) {
        players[i].n = i;
        players[i].h = rand() % 101 + 150;
        players[i].w = rand() % 121 + 150;
        players[i].s = rand() % 31 + 5;
        players[i].r = rand() % 11;
        players[i].p = rand() % 11;
        file << players[i].h << " " << players[i].w << " " << players[i].s << " "
             << players[i].r << " " << players[i].p << endl;
    }

    file.close();
}

void readDB(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    int height, wingspan, points, rebounds, assists;
    int numPlayers = 0;
    Player players[32];

    while (file >> height >> wingspan >> points >> rebounds >> assists) {
        if (numPlayers < 32) {
            players[numPlayers].n = numPlayers + 1;
            players[numPlayers].h = height;
            players[numPlayers].w = wingspan;
            players[numPlayers].s = points;
            players[numPlayers].r = rebounds;
            players[numPlayers].p = assists;

            players[numPlayers] = giveCat(players[numPlayers]);
            players[numPlayers].Print();

            numPlayers++;
        }
        else {
            cout << "Достигнуто максимальное количество игроков." << endl;
            break;
        }
    }

    file.close();
}

void taskOne() {
    string path = "bd.txt";
    //Player player;

    // Отчистка файла перед новой записью
    fstream clear_file(path, ios::out);
    clear_file.close();

    /*
    for (int i = 0; i <= 1; i++) {
        player.n = i;
        cout << "\nPlease input parameters h, w, s, r and p of player " << i << ": " << endl;
        cin >> player.h >> player.w >> player.s >> player.r >> player.p;
        writeDB(path, player);
    }
    */

    /*
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
    */
    writeDB(path);
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
    //int* weights_reset = new int[n];

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
        //weights_reset[i] = weights[i];
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
    //delete[] weights_reset;

    return 0;
}



class Sensor {
public:
    int hi; // Высота, на которой находится датчик с номером i
    int vi; // Количество раз, которое цепь управления опрашивает этот датчик
    
    Sensor(){
        hi = vi = 0;
    }
    Sensor(int h, int v) : hi(h), vi(v) {}
};

// НЕКОРРЕКТНО РАБОТАЕТ
void taskThree() {
    int n, H, T;
    
    cout << "Введите к-во датчиков: ";
    cin >> n;
    while (n > 100000 || n < 1) {
        cout << "\tОШИБКА\n\tВведите к-во датчиков (1-100 000): ";
        cin >> n;
    }
    cout << "Введите требуемый уровень воды: ";
    cin >> H;
    while (H < 1) {
        cout << "\tОШИБКА\n\tВведите требуемый уровень воды (более 1): ";
        cin >> H;
    }
    cout << "Введите время до прихода мамы: ";
    cin >> T;
    while (T > 109) {
        cout << "\tОШИБКА\n\tВведите время до прихода мамы (менее 109): ";
        cin >> T;
    }

    Sensor* sensors = new Sensor[n];
    for (int i = 0; i < n; i++) {
        int hi, vi;
        
        cout << "\nВведите высоту, на кот. находится датчик с номером " << i << ": ";
        cin >> hi;
        while (hi > H || hi < 1) {
            cout << "\tОШИБКА\n\tВведите высоту, на кот. находится датчик с номером " << i << " (1-" << H << "): ";
            cin >> hi;
        }
        while (i > 0 && hi < sensors[i - 1].hi) {
            cout << "\tОШИБКА\n\tВведите высоту, на кот. находится датчик с номером " << i << " больше предыдущей: ";
            cin >> hi;
        }
        cout << "Введите к-во раз, кот. цепь управления опрашивает этот датчик: ";
        cin >> vi;
        while (vi > 109 || n < 1) {
            cout << "\tОШИБКА\n\tВведите к-во раз, кот.цепь управления опрашивает этот датчик (1-109): ";
            cin >> vi;
        }
        
        sensors[i] = Sensor(hi, vi);
    }

    int left = 1, right = H;
    int result = H;
    //int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2; // Высота воды в резервуаре
        long long totalTime = 0; // Общее время, необходимое для наполнения резервуара до высоты mid

        // Итерация по всем датчикам, начиная с последнего и заканчивая первым
        for (int i = n - 1; i >= 0; i--) {
            int waterLevel = mid; // Текущая высота воды в резервуаре

            if (sensors[i].hi > waterLevel) {
                // Если высота датчика больше текущей высоты воды, то время работы данного датчика добавляется к общему времени
                totalTime += sensors[i].vi; 
            }
            else {
                /* Если высота датчика меньше или равна текущей высоте воды, 
                то происходит расчет количества доливов воды, необходимых для достижения высоты датчика. 
                Затем время работы датчика умножается на количество доливов и добавляется к общему времени */
                
                //long long numRefills = (waterLevel - sensors[i].hi + mid - 1) / mid;
                long long numRefills = (waterLevel - sensors[i].hi + mid) / mid - 1;

                totalTime += numRefills * sensors[i].vi;
                waterLevel -= numRefills * mid;
                totalTime += sensors[i].vi;

                // Если после доливов остается некоторое к-во воды, то добавляется еще одна единица времени, 
                // так как требуется еще один цикл работы датчика для полного заполнения резервуара.
                if (waterLevel > 0) {
                    totalTime++;
                }
            }
        }
        /*
        if (totalTime <= T) { // Если общее время меньше или равно заданному времени,
            result = mid; // то текущее значение становится новым оптимальным значением
            right = mid - 1; // Значение right уменьшается на 1, чтобы продолжить поиск оптимального значения в левой половине диапазона
        }
        else {
            left = mid + 1; // Если общее время больше заданного времени, то значение left увеличивается на 1, чтобы продолжить поиск оптимального значения в правой половине диапазона
        }
        */
        /*
        if (totalTime <= T) {
            result = mid;
            left = mid + 1; // Изменение логики, чтобы продолжать поиск оптимального значения в правой половине диапазона
        }
        else {
            right = mid - 1;
        }
        */

        if (totalTime <= T) { // Если общее время меньше или равно заданному времени,
            result = mid; // то текущее значение становится новым оптимальным значением
            right = mid - 1; // Значение right уменьшается на 1, чтобы продолжить поиск оптимального значения в левой половине диапазона
        }
        else {
            left = mid + 1; // Если общее время больше заданного времени, то значение left увеличивается на 1, чтобы продолжить поиск оптимального значения в правой половине диапазона
        }
        
    }

    cout << "\nМин. количество сантиметров залитой воды, кот. позволит Диме завершить эксперимент за не более чем " << T << " секунд равно " << result << "." << endl;
    /*
    if(result != -1) { // Проверка, было ли найдено оптимальное значение
        cout << "\nМин. количество сантиметров залитой воды, кот. позволит Диме завершить эксперимент за не более чем " << T << " секунд равно " << result << "." << endl;
    }
    else {
        cout << "\nНет решения для заданных параметров." << endl;
    }
    */

    delete[] sensors; // освобождение памяти
}


int main()
{
    setlocale(LC_ALL, "Russian"); // Русская локализация консоли

    int choise = 1;
    while (choise != 0) {
        cout << "\n\t\tМеню\n\t 1 - Первое задание (44)\n\t 2 - Второе задание (57)\n\t 0 - Выход\n>> ";
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

    return 0;
}

