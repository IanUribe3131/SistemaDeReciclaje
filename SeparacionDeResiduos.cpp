#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;
//Estructura de la base de datos
struct TrashItem{
    string name;
    string nameEs;
    string type;
    string bin;
};
//meter base de datos a vector
vector<TrashItem> LoadDataSet(const string& filename){
    vector<TrashItem> dataset;
    ifstream file("waste_items_dataset.csv");

    if(!file.is_open()){
        cout<< "Error: could not open data set file. \n";
        return dataset;
    }

    string line;

    while(getline(file, line)){
        stringstream ss(line);
        string name, nameEs, type, bin;

        getline(ss, name, ',');
        getline(ss, nameEs, ',');
        getline(ss, type, ',');
        getline(ss, bin, ',');

        dataset.push_back({name, nameEs, type, bin});

    }
    file.close();
    return dataset;
}
//buscar el item del usuario
string searchTrash(const vector<TrashItem>& dataset, const string& userInput){
    for(const auto& item :dataset){

        string nameLower = item.name;
        string inputLower = userInput;
        transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
        transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

        if(nameLower == inputLower){
            cout<<"Your item belongs to the "<<item.bin<< "bin\n";
        }
    }
    return "";
}



int main(){
    vector<TrashItem> dataset = LoadDataSet("waste_items_dataset.csv");

    cout<<" === Welcome to Trash Sorting Assistant ===\n";
    cout<<"Enter the name of the item you want to throw away: ";
    string userInput;
    getline(cin, userInput);

    string bin = searchTrash(dataset, userInput);

    if(bin.empty()){
        cout << "Your item was not found on the dataset.\n";
        cout << "But dont worry, we can still figure this out. \n";
    }
}