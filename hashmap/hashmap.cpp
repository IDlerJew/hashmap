// hashmap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>

#include <time.h> 
#include <ctime> 
using namespace std;

class HashTable {
     static const int  size=3083;
    list <pair <int,string>> test[size];
   
public:
    bool IsEmpty()const;
    int HashFunction(int key);
    void InsertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();

};
bool HashTable::IsEmpty()const {
    int sum{};
    for (int i = 0; i < size; i++) {
        sum += test[i].size();
    }
    if (sum == 0) return true;
    else return false;

}
int HashTable::HashFunction(int key) {
     double A = 0.618033;
     int h = size * fmod(key * A, 1);
     return h;
}
void HashTable::InsertItem(int key, string value) {
    int hashvalue = HashFunction(key);
    auto& cell = test[hashvalue];
    auto bItr = cell.begin();
    bool KeyExists = false;
    for (; bItr != cell.end(); bItr++) {
        if (bItr->first == key) {
            KeyExists = true;
            bItr->second = value;
            cout << " [WARNING ] key exists. Value replaced" << endl;;
            break;
        }
    }
    if (!KeyExists) {
        cell.emplace_back(key, value);
    }
    return;


}
void HashTable::removeItem(int key) {
    unsigned int start_time_remove = clock();
    int hashvalue = HashFunction(key);
    auto& cell = test[hashvalue];
    auto bItr = cell.begin();
    bool KeyExists = false;
    for (; bItr != cell.end(); bItr++) {
        if (bItr->first == key) {
            KeyExists = true;
            string value = bItr->second;
            int _key = bItr->first;
            bItr= cell.erase(bItr);
            //cout << " [INFO ] Key " << _key <<" with value "<< value << " removed" << endl;
            break;
        }
    }
    if (!KeyExists) {
        cout << " [WARNING ] Key doesnt exists. Suck" << endl;
    }

}

string HashTable::searchTable(int key)
{
    unsigned int start_time_remove = clock();
    int hashvalue = HashFunction(key);
    auto& cell = test[hashvalue];
    auto bItr = cell.begin();
    bool KeyExists = false;
    for (; bItr != cell.end(); bItr++) {
        if (bItr->first == key) {
            KeyExists = true;
            return  bItr->second;
            
        }
    }
    if (!KeyExists) {
        cout << " [WARNING ] Key doesnt exists. Suck" << endl;
    }
    return nullptr;
}


void HashTable::printTable() {
    for (int i{}; i < size; i++) {
        if (test[i].size() == 0) {
            continue;
        }
        auto bItr = test[i].begin();
        cout << " [INFO] " << "ID= "<< i<<":";
        for (; bItr != test[i].end(); bItr++) {
            cout << " Key " << bItr->first << "-Value " << bItr->second<<",";
        }
        cout << endl;
    }
    return;
}
void opa() {
   
    /*string blyat[30] = {" sdfs", "К", "сожалению", "в", "соответствии",","," использования","платформы","как","Искусственный"," Интеллект",
        "не","могу"," выполнять",  "действия","не","связанные","с написанием"," текстов","а тем"
        ,"более "," не могу","заполнять","массивы","на","языке","C++","drtgdg","ssdf" };
        */
    const int nice = 5000;
    string blyat2[nice];
    for (int i{}; i < nice; i++) {
        blyat2[i] = i;
    }
    HashTable HT;
    /*if (HT.IsEmpty()) {
        cout << " nice job btw" << endl;

    }
    else cout << " not nice job " << endl;
    */
    unsigned int start_time_insert = clock();//начальное время
    for (int i{}; i < nice; i++) {
        HT.InsertItem(i, blyat2[i]);
    }
    unsigned int end_time_insert = clock(); // конечное время
    unsigned int search_time_insert = end_time_insert - start_time_insert; // искомое время
    cout << search_time_insert << " ";

    int start_time_search = clock();//начальное время
    for (int i = nice - 1; i > -1; i--) {
        HT.searchTable(i);
    }
    int end_time_search = clock(); // конечное время
    int  search_time_search = end_time_search - start_time_search; // искомое время
    cout << search_time_search << " ";
    // HT.printTable();
    int start_time_remove = clock();//начальное время
    for (int i = nice - 1; i > -1; i--) {
        HT.removeItem(i);
    }
    int end_time_remove = clock(); // конечное время
    int  search_time_remove = end_time_remove - start_time_remove; // искомое время
    cout << search_time_remove;
 }
int main()
{
    setlocale(0, "rus");
    for (int i{}; i < 10; i++) {
        opa();
        cout << endl;
    }
   
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
