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
};
//meter base de datos a vector
vector<TrashItem> LoadDataSet(const string& filename){
    vector<TrashItem> dataset;
    ifstream file(filename);

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

        dataset.push_back({name, nameEs, type});

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
            cout<<"Your item belongs to the '"<<item.type<< "' bin\n";
            return item.type;
        }
    }
    return "";
}


class Waste {
  public:
    virtual string getBin() = 0;
};

class organic : public Waste{
  public:
    string getBin() override { return "organic bin";}
};

class inorganicR : public Waste{
  public:
    string getBin() override {return "Recyclable inorganic bin";}
};

class inorganic : public Waste{
  public:
    string getBin() override {return "Non recyclable inorganic bin";}
};

class Glass : public Waste{
  public:
    string getBin() override {return "glass bin";}
};

class Metal : public Waste{
  public:
    string getBin() override {return "metal bin";}
};

class Cardboard: public Waste{
  public:
    string getBin() override {return "cardboard bin";}
};

class Plastic : public Waste{
  public:
    string getBin() override {return "plastic bin";}
};

class PET : public Waste{
  public:
    string getBin() override {return "PET bin";}
};

class Hazardous : public Waste{
  public:
    string getBin() override {return "battery / electronic / hazardous bin";}
};

int main(){
  vector<TrashItem> dataset = LoadDataSet("C:\\Users\\ianur\\OneDrive\\Escritorio\\VSCodeMain\\SchoolMain\\SeparacionDeBasura\\SistemaDeReciclaje\\waste_items_dataset.csv");
  
    cout<<" === Welcome to Trash Sorting Assistant ===\n";
    cout<<"Enter the name of the item you want to throw away: ";
    string userInput;
    getline(cin, userInput);

    string bin = searchTrash(dataset, userInput);

    if(bin.empty()){
      char org, recy, glass, metal, card, plastic, pet, hazard;
      cout << "Your item was not found on the dataset.\n";
      cout << "But dont worry, we can still figure this out. \n";
      cout << "Is it biodegradable? (like food, fruit, or leaves) (y/n): ";
      cin >> org;

      if(org=='y' || org =='Y'){
        organic obj;
        cout << "You should throw it in the "<< obj.getBin() << '\n';
        return 0;
      }
    
      cout << "Is it recyclable? (plastic, metal, cardboard, glass) (y/n): ";
      cin >> recy;

      if(recy=='y' || recy =='Y'){
        cout << "Is it made of glass?(y/n): ";
        cin >> glass;

        if(glass=='y'||glass=='Y'){
          Glass obj;
          cout<<"you should throw it in the "<<obj.getBin() << '\n';
          return 0;
        }

        cout<< "Is it made of metal?(y/n): ";
        cin>>metal;

        if(metal=='y'||metal=='Y'){
          Metal obj;
          cout<<"you should throw it in the "<<obj.getBin()<<'\n';
          return 0;
        }

        cout<<"Is it made of cardboard? (like pizza boxes or amazon boxes)(y/n): ";
        cin>> card;

        if(card=='y'||card=='Y'){
          Cardboard obj;
          cout<<"you should throw it in the "<<obj.getBin()<<'\n';
          return 0;
        }

        cout<<"Is it made of plastic?(y/n): ";
        cin>> plastic;
        
        if(plastic=='y'||plastic=='Y'){
          cout<<"Is it PET plastic?(y/n): ";
          cin>>pet;
          if(pet=='y'||pet=='Y'){
            PET obj;
            cout<<"you should throw it in the "<<obj.getBin()<<'\n';
            return 0;
          }

          Plastic obj;
          cout<<"you should throw it in the "<<obj.getBin()<<'\n';
          return 0;
        }

        cout<<"Is it hazardous or electronics? (like batteries, fluorescent tubes, cables, laptops)(y/n): ";
        cin>>hazard;

        if(hazard=='y'||hazard=='Y'){
          Hazardous obj;
          cout<<"you should throw it in the "<<obj.getBin()<<'\n';
          return 0;
        }
        cout<<"We dont have more categories for your type of trash. Maybe search on the internet where to put it";
      }

      inorganic obj;
      cout<<"you should throw it in the "<<obj.getBin()<<'\n';
      return 0;
    }



}