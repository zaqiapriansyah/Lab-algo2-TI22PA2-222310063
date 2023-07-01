//double hashing
#include <iostream>
#include <string>
#define SIZE 10

using namespace std;

class Animal{
public:
  string name;
  string species;

Animal(string name, string species){
  this->name = name;
  this->species = species;
}
};
class DoubleHash{
Animal**hashTable;
int curr_size;

public:
DoubleHash(){
  hashTable = new Animal*[SIZE];
  curr_size = 0;
  for(int i = 0 ; i<SIZE; i++)
    hashTable[i] = NULL;
}
int hash1(string key){
  int sum = 0;
  for(char ch:key)
    sum += ch;
  return sum % SIZE;
}
int hash2(string key){
  int prime = 7;
  return prime - (sumOfChars(key)%prime);  
}
int sumOfChars(string key){
  int sum = 0;
  for(char ch:key)
    sum += ch;
  return sum;
}
void insertHash(string key, Animal*animal){
  if (curr_size == SIZE){
    cout << "Hash Tabel is full" << endl;
    return;
  }
  int index = hash1(key);
  if(hashTable[index]!=NULL){
    int index2 = hash2(key);
    int i = 1;
    while(true){
      int newIndex = (index+1*index2)%SIZE;
      if(hashTable[newIndex]==NULL){
        hashTable[newIndex]=animal;
        break;
      }
      i++;
    }
  }else{
    hashTable[index]=animal;
  }
  curr_size++;
}
void displayHash(){
  for(int i=0; i<SIZE; i++){
    if(hashTable[i]!=NULL)
      cout << "Index " << i << ":" << hashTable[i]->name << "(" << hashTable[i]->species << ")" << endl;
    else
      cout << "index " << i << ":NULL" <<endl;
  }
}
};
int main(){
  DoubleHash h;
  h.insertHash("Singa", new Animal("Simba", "Singa"));
  h.insertHash("Beruang", new Animal("Baloo", "Beruang"));

  h.displayHash();
  return 0;
}