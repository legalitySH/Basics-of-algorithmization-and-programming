//#include <iostream>
//#include <unordered_set>
//#include <chrono>
//#include <ctime>
//
//using namespace std;
//using namespace chrono;
//
//int main() {
//    setlocale(LC_ALL, "rus");
//    srand(time(0));
//
//    vector<int> tableSizes = { 16, 32, 64, 128,256,512,1024,2048 };
//    for (int tableSize : tableSizes) {
//        unordered_set<int> hashTable(tableSize);
//
//        for (int i = 0; i < tableSize * 2; i++) {
//            int key = i * 2; 
//            hashTable.insert(key);
//        }
//
//        int keyToFind = rand() % (tableSize * 2);
//        double totalDuration = 0;
//
//        for (int i = 0; i < 100; i++) {
//            auto start = high_resolution_clock::now();
//            auto iter = hashTable.find(keyToFind);
//            auto end = high_resolution_clock::now();
//            auto duration = duration_cast<nanoseconds>(end - start);
//            totalDuration += duration.count();
//        }
//
//        double averageDuration = totalDuration / 100;
//
//        if (hashTable.find(keyToFind) != hashTable.end()) {
//            cout << "Элемент найден в хэш-таблице размером " << tableSize << "!" << endl;
//        }
//        else {
//            cout << "Элемент не найден в хэш-таблице размером " << tableSize << "!" << endl;
//        }
//
//        cout << "Среднее время поиска: " << averageDuration << " наносекунд" << endl;
//        cout << endl;
//    }
//
//    return 0;
//}
