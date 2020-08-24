#include <iostream>
#include <fstream>
#include <jni.h>
#include <vector>
#include <Animal.h>
#include <Mammal.h>
#include <Ovi.h>
using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void AddAnimal(vector<Animal> &animalList)
{
	int idNum;
	string name;
	string type;
	string subType;
	int eon;
    cout << "Enter Tracking Number:" << endl;
    cin >> idNum;
    cout << "Enter Name" << endl;
    cin >> name;
    cout << "Enter Type:" << endl;
    cin >> type;
    cout >> "Enter SubType" << endl;
    cin >> subType;

	if (type=="Mammal" || type=="mammal"){
    	cout<< "If nursing enter 1, if not nursing enter 2:" << endl;
		cin >> eon;
    	Mammal newMammal;
    	 newMammal.setTrackNum(idNum);
    	 newMammal.setName(name);
    	 newMammal.setSubType(subType);
    	 newMammal.setNurse(eon);
    	 animalList.push_back(newMammal);
    }
     else if (type=="Oviparous"|| type == "oviparous"){
    	 cout << "Enter number of eggs:" << endl;
    	 cin >> eon;
    	 Ovi newOvi;
    	 newOvi.setTrackNum(idNum);
    	 newOvi.setName(name);
    	 newOvi.setSubType(subType);
    	 newOvi.setEggs(eon);
    	 animalList.push_back(newOvi);
      }
    }



void RemoveAnimal(vector<Animal> &animalList)
{
	int idNum;
	int choice;
	cout << "Enter Tracking number of the animal you wish to delete" << endl;
	cin >> idNum;
	int size=animalList.size();
    for (int i=0; i<size; i++){
    	if (animalList.at(i).getTrackNum()== idNum){
    		cout << "Press 1 to delete " << idNum << endl;
    		cin >>choice;
    		if (choice == 1){
    			delete animalList.at(i);
    		}
    		else{
    			cout << "Animal not deleted" << endl;
    		}
    	}
    }
}

void LoadDataFromFile(vector<Animal> &animalList)
{
	ifstream inFS;
	int idNum;
    string name;
    string type;
    string subType;
    int eggs;
    int nursing;
    Mammal newMammal;
    Ovi newOvi;

    inFS.open("zoodata.txt");
    if (!inFS.is_open()) {
          cout << "Could not open file" << endl;
          return;
       }
    while (!inFS.eof()) {
          inFS >> idNum;
		  inFS >> name;
		  inFS >> type;
		  inFS >> subType;
		  inFS >> eggs;
		  inFS >> nursing;
          if (type=="mammal" || type=="Mammal"){
        	  newMammal.setTrackNum(idNum);
        	  newMammal.setName(name);
        	  newMammal.setSubType(subType);
        	  newMammal.setNurse(nursing);
        	  animalList.push_back(newMammal);
          }
          else if (type=="Oviparous"|| type == "oviparous"){
        	  newOvi.setTrackNum(idNum);
        	  newOvi.setName(name);
        	  newOvi.setSubType(subType);
        	  newOvi.setEggs(eggs);
        	  animalList.push_back(newOvi);
          }
    }
}

void SaveDataToFile(vector<Animal> animalList)
{
	 ofstream outFS;
	outFS.open("zooData.txt");
	outFS >> animalList;
	outFS.close();
}

void DisplayMenu()
{
     cout << "*********Menu*********"<< endl;
	 cout << "1. Load Animal Data" << endl;
     cout << "2. Generate Data" << endl;
     cout << "3. Display Animal Data" << endl;
     cout << "4. Add Record" << endl;
     cout << "5. Delete Record" << endl;
     cout << "6. Save Animal Data" << endl;
     cout << "***Press 0 to Quit***" << endl;
}



int main()
{
	vector<Animal> animalList(0);
	int userInput=7;
	DisplayMenu();


	while (userInput !=0){
		cin >> userInput;
		switch(userInput){
			case 0:
				break;
			case 1:
				LoadDataFromFile(animalList);
				break;
			case 2:
				GenerateData();
				break;
			case 3:
				for (int i=0; i < animalList.size();i++){
					animalList.at(i).printAnimal();
				}
				break;
			case 4:
				AddAnimal(animalList);
				break;
			case 5:
				RemoveAnimal(animalList);
				break;
			case 6:
				SaveDataToFile(animalList);
				break;
			default:
				cout << "Not a valid option, please enter a new number" << endl;
				break;
		}

	}
	return 1;


}
