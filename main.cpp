#include <iostream>
#include <ostream>
#include <vector>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <direct.h>
#include <process.h>
#include <windows.h>
#include <map>
#include <utility>

using namespace std;

void diagnosis(void);
void mainScreen(void);
void addPerson();

int recordNum = 0;
const int MAX = 100;
char tempChar ;
int objNum = 0;



HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) {
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

class Disease  {
    private:
        char    name[40];
        int     age;
        float   weight;
        float   height;
        char    sex ;
        char    arrValues[100];
    public:
        void getPersonalInfo(void);
        void getSymptoms1(void);
        void getSymptoms2(void);
        void getSymptoms3(void);
        int analyseSymptoms(int);
        char showMessages(int,int);
        Disease();
        char* getName(){ return name; };
        int getAge(){ return age; };
        float getWeight(){ return weight; };
        float getHeight(){ return height; };
        char getSex(){ return sex; };

};

vector<Disease> person ;

map<string, string> level1;
map<string, string> level2;
map<string, string> level3;
map<string, string> results;


Disease::Disease(void){
    for(int i=0; i<40; i++){
        name[i] = ' ';
    }
    for(int i=0; i<100; i++){
        arrValues[i] = ' ';
    }
    age = 0.0;
    weight  = 0.0;
    height  = 0.0;
    sex = ' ';
}

int main() {
    char z;
    int num = 0;

    mainScreen();

    while(true){
        addPerson();
        system("cls");
        cout<<("\n\n\n Exit and show reports ? (y/n):  " );
        cin>>z;
        if(z == 'n' || z == 'N'){
            objNum++;
            continue;
        }else if(z == 'y' || z == 'Y'){
            cout<<"\n\n\n";
            cout<<"--------------------------- SHOW REPORTS ---------------------------" <<endl;
            for(int i=0; i < person.size(); i++){
                ++num;
                cout <<"\n\n\n  PERSON NUMBER ("<<num <<") DETAILS"<<endl;
                cout<<"-----------------------------------" <<endl;
                cout <<"Name  : " << person[i].getName()     <<endl;
                cout <<"Age   : " << person[i].getAge()      <<endl;
                cout <<"Weight: " << person[i].getWeight()   <<endl;
                cout <<"Height: " << person[i].getHeight()   <<endl;
                cout <<"Sex   : " << person[i].getSex()      <<endl;
                cout <<"\n                 THE REPORT ("<<num<<")"<<endl;
                cout<<"***********************************************" <<endl;
                SetConsoleTextAttribute(hConsole, 10);
                cout <<"\n--------------------- LEVEL (1) ------------------------"<<endl;
                SetConsoleTextAttribute(hConsole, 14);
                for( map<string,string>::iterator i=level1.begin(); i!=level1.end(); ++i){
                    cout << (*i).first << " " << (*i).second << endl;
                }
                cout <<"\n\n THE RESULTS IS : " << results["level1"] <<endl;


                if(!level2.empty()){
                    SetConsoleTextAttribute(hConsole, 10);
                    cout <<"\n--------------------- LEVEL (2) ------------------------"<<endl;
                    SetConsoleTextAttribute(hConsole, 14);
                    for( map<string,string>::iterator i=level2.begin(); i!=level2.end(); ++i){
                        cout << (*i).first << " " << (*i).second << endl;
                    }
                    cout <<"\n\n THE RESULTS IS : " << results["level2"] <<endl;
                }

                if(!level3.empty()){
                    SetConsoleTextAttribute(hConsole, 10);
                    cout <<"\n--------------------- LEVEL (3) ------------------------"<<endl;
                    SetConsoleTextAttribute(hConsole, 14);
                    for( map<string,string>::iterator i=level3.begin(); i!=level3.end(); ++i){
                        cout << (*i).first << " " << (*i).second << endl;
                    }
                    cout <<"\n\n THE RESULTS IS : " << results["level3"] <<endl;
                }

                cout <<"\n********************END REPORT ("<<num<<")"<<" *****************"<<endl;
            }

            break;
        }
        cin.clear();
        cin.ignore(10000,'\n');
    }

    return 0;
}


void addPerson(){
    char choice1,choice12;

    float analyseValue;
    int n = 1;

    Disease obj[MAX];
    obj[objNum].getPersonalInfo();
    diagnosis();
    obj[objNum].getSymptoms1();
    analyseValue = obj[objNum].analyseSymptoms(n);
    choice1=obj[objNum].showMessages(n,analyseValue);
    choice1=toupper(choice1);
    if(choice1=='Y') {
        ++n;
        obj[objNum].getSymptoms2();
        analyseValue=obj[objNum].analyseSymptoms(n);
        choice1=obj[objNum].showMessages(n,analyseValue);
        choice1=toupper(choice1);
        if(choice1=='Y') {
            ++n;
            obj[objNum].getSymptoms3();
            analyseValue=obj[objNum].analyseSymptoms(n);
            choice12=obj[objNum].showMessages(n,analyseValue);
            choice12=toupper(choice12);
            if(choice12=='Y') {
                ++n;
                obj[objNum].getSymptoms3();
                analyseValue=obj[objNum].analyseSymptoms(n);
                choice1=obj[objNum].showMessages(analyseValue,n);
            }
        }
    }

    person.push_back(obj[objNum]);

}

void mainScreen() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 14);
    cout<<endl << endl << endl;
    cout<<"                    ******************************** WELCOME ***************************************** "<<endl;
    cout<<endl << endl << endl;
    cout<<"                                  M E D I C A L   D I A G N O S I     S O F T W A R R ";
    cout<<endl << endl << endl;
    cout<<endl;
    cout<<endl;
    cout <<"                           DONE BY :\n\n"<<endl;
    SetConsoleTextAttribute(hConsole, 10);
    cout <<"                           Ahmad Hamdan            1131121467" <<endl;


    SetConsoleTextAttribute(hConsole, 14);
    cout<<endl << endl << endl << endl << endl << endl<< endl <<endl;



    cout<<"                                                PRESS ANY KEY TO CONTINUE  ";
    cout<<endl;
    cout<<"                   ************************************************************************************ ";
    getch();

    return;
}


void Disease::getPersonalInfo() {
    system("cls");

    SetConsoleTextAttribute(hConsole, 14);
     cout<<endl << endl <<endl;
     cout<< "                  ************************* P E R S O N A L   I N F O R M A T I O N ********************"<<endl;

    cout<<endl;
    cout<<"                                              N A M E        :"<<endl;

    cout<<"                                              A G E          :"<<endl;

    cout<<"                                              W E I G H T    :"<<endl;

    cout<<"                                              H E I G H T    :"<<endl;

    cout<<"                                              S E X (M/F)    :"<<endl;
    cout<<endl<<endl;
    cout<<"                    *****************************************************************************************"<<endl;
    SetConsoleTextAttribute(hConsole, 10);
    gotoxy(65,5);
    cin>>name;
    cin.clear();
    cin.ignore(10000,'\n');

    gotoxy(65,6);
    cin>>age;
    cin.clear();
    cin.ignore(10000,'\n');

    gotoxy(65,7);
    cin>>weight;
    cin.clear();
    cin.ignore(10000,'\n');

    gotoxy(65,8);
    cin>>height;
    cin.clear();
    cin.ignore(10000,'\n');

    gotoxy(65,9);
    cin>>sex;
    cin.clear();

    getch();
    return;
}


void diagnosis() {
    system("cls");
    SetConsoleTextAttribute(hConsole, 14);
    cout<<endl;
    cout<<"\n\n\n\t\t\t ";
    cout<<"****************  D I A G N O S I S   W I N D O W **************************   "<<endl;
    cout<<"\n\n\n";
    cout<<"                          Let's have a look at  symptoms........."<<endl;
    cout<<"\n\n\n";
    cout<<"                           Please enter the form in next page ."<<endl;
    cout<<"\n\n\n\n\n\n\t\t\t ";
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"*************************** PRESS ANY KEY ************************************ "<<endl;
    getch();
}

void Disease::getSymptoms1() {
    system("cls");
    int i=0;
    SetConsoleTextAttribute(hConsole, 14);
    cout<<endl;
    cout<<"\n\n\n\t\t\t ";
    cout<< "****************** MEDICAL DIAGONOSIS FORM ************************** "<<endl;
    char tempChar;
    tempChar = 'x';
    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
        cout<<endl;
        cout<<"\n\t\t\t ";
        cout<<"APPETITE ---->  (HIGH = H | LOW = L | NORMAL = N) : " ;
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
         SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
           cout<<"\n\t\t\t ";
           cout<< "------------------------------------------------------------------------- "<<endl;

            break;

        }

    }


    arrValues[i] = toupper(tempChar);
    ++i;


    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
        cout<<"\n\t\t\t ";
        cout<< "FREQUENCY OF THIRST ----> (HIGH = H | LOW = L | NORMAL = N): " ;
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["FREQUENCY OF THIRST ----> (HIGH = H | LOW = L | NORMAL = N): "] = arrValues[i];
    ++i;

    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
        cout<<"\n\t\t\t ";
        cout << "FREQUENCY OF URINATION ----> (HIGH = H | LOW = L | NORMAL = N): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
           cout<<"\n\t\t\t ";
           cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["FREQUENCY OF URINATION ----> (HIGH = H | LOW = L | NORMAL = N): "] = arrValues[i];
    ++i;

    while(tempChar != 'i' || tempChar != 'n' || tempChar != 'I' || tempChar != 'N' ){
        cout<<"\n\t\t\t ";
        cout << "VISION ----> (IMPAIRMENT = I | NORMAL = N): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'i' || tempChar == 'n' || tempChar == 'I' || tempChar == 'N' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["VISION ----> (IMPAIRMENT = I | NORMAL = N): "] = arrValues[i];
    ++i;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "URINE SUGAR ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["URINE SUGAR ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[i];
    ++i;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "KETONUREA ----> (PASSIVE = P | ACTIVE = A): ";
         SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["KETONUREA ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[i];
    ++i;

    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
        cout<<"\n\t\t\t ";
        cout << "FASTING BLOOD SUGAR ----> (HIGH = H | LOW = L | NORMAL = N): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
             cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["FASTING BLOOD SUGAR ----> (HIGH = H | LOW = L | NORMAL = N): "] = arrValues[i];
    ++i;

    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
         cout<<"\n\t\t\t ";
        cout << "Random Glucose Tests ----> (HIGH = H | LOW = L | NORMAL = N): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
         SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
             cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["Random Glucose Tests ----> (HIGH = H | LOW = L | NORMAL = N): "] = arrValues[i];
    ++i;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "FAMILY HISTORY OF Disease ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["FAMILY HISTORY OF Disease ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[i];
    ++i;

    while(tempChar != 'd' || tempChar != 'n' || tempChar != 'D' || tempChar != 'N' ){
        cout<<"\n\t\t\t ";
        cout << "Oral Glucose Tolerance Test  ---->(D/N): "; //Oral Glucose Tolerance Test
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'd' || tempChar == 'n' || tempChar == 'D' || tempChar == 'N' ){
            cout<<"\n\t\t\t ";
            cout<< "------------------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[i] = toupper(tempChar);
    level1["Oral Glucose Tolerance Test  ---->(D/N): "] = arrValues[i];
    ++i;
}

int Disease::analyseSymptoms(int n) {
    gotoxy(20,5);
    int i=0;
    int counter=0;
    int result=0;
    switch(n) {
        case 1:
            if(arrValues[9]=='D' )
                result=-1;
            else if(arrValues[5]=='P'&& arrValues[6]=='P' && arrValues[7]=='H')
                result=-1;
            else {
                for(i=0; i<10; i++) {
                    if(arrValues[i]=='H'||arrValues[i]=='P'||arrValues[i]=='D'||arrValues[i]=='I')
                        counter++;
                }
                if(counter>5)
                    result=-1;
            }
            break;

        case 2:
            if((arrValues[0]=='P')||(arrValues[1]=='P')||(arrValues[2]=='P')||(arrValues[3]=='H')||(arrValues[4]=='P')||(arrValues[5]=='P')||(arrValues[6]=='P'))
                result=-1;
            else
                result=0;
            break;
        case 3:
            if((arrValues[0]=='Y')&&(arrValues[1]=='N')&&(arrValues[2]=='W')&&(arrValues[3]=='P')&&(arrValues[4]=='P')||

                    (arrValues[0]=='Y')&&(arrValues[1]=='B')&&(arrValues[2]=='W')&&(arrValues[3]=='P')&&(arrValues[4]=='P')||

                    (arrValues[0]=='Y')&&(arrValues[1]=='N')&&(arrValues[2]=='M')&&(arrValues[3]=='P')&&(arrValues[4]=='P')||

                    (arrValues[0]=='Y')&&(arrValues[1]=='N')&&(arrValues[2]=='Y')&&(arrValues[3]=='P')&&(arrValues[4]=='P'))
                result=0;
            else
                result=-1;
            break;
        default:
            break;
    }
    return result;
}

char Disease::showMessages(int n,int m) {
    char ch;
    system("cls");
    switch(n) {
        case 1:
            switch(m) {
                case 0:
                    gotoxy(40,5);
                    cout << "********** PERSON STATUS **********" << endl << endl << endl << endl;
                    gotoxy(40,8);
                    cout << "    THE PERSON IS NOT DIABETIC " << endl << endl << endl << endl << endl;
                    gotoxy(40,10);
                    cout << "     PRESS ANY KEY TO QUIT." <<endl;
                    cout << endl;
                    getch();
                    results["level1"] = "THE PERSON IS NOT DIABETIC";
                    system("cls");
                    break;

                case -1:

                    gotoxy(40,5);
                    cout << "********** PERSON STATUS **********" << endl << endl << endl << endl;
                    gotoxy(40,8);
                    cout << "    THE PERSON IS DIABETIC " << endl << endl << endl << endl << endl;
                    gotoxy(40,10);
                    cout << "     PROCEED (Y/N)  ?.";
                    SetConsoleTextAttribute(hConsole, 10);
                    cin>>ch;
                    SetConsoleTextAttribute(hConsole, 14);
                    results["level1"] = "THE PERSON IS DIABETIC";
                    system("cls");
                    break;

            }
            break;
        case 2:
            switch(m) {
                case 0:
                    gotoxy(3,12);
                    cout << "IT IS PRIMARY Disease.\n\n\n\n" ;
                    gotoxy(3,18);
                    cout << "Proceed(Y/N)?" ;
                    gotoxy(64,18);
                    SetConsoleTextAttribute(hConsole, 10);
                    cin>>ch;
                    SetConsoleTextAttribute(hConsole, 14);
                    results["level2"] = "IT IS PRIMARY Disease";
                    system("cls");
                    break;

                case -1:
                    gotoxy(8,12);
                    cout << "IT IS SECONDARY Disease \n\n\n\n";
                    gotoxy(8,18);
                    cout << "PRESS ANY KEY TO QUIT" ;
                    results["level2"] = "IT IS SECONDARY Disease";
                    getch();
                    system("cls");
                    break;

            }
            break;

        case 3:
            switch(m) {
                case 0:
                    gotoxy(3,12);
                    cout << " IT IS INSULIN DEPENDENT Disease\n\n\n\n";
                    gotoxy(3,18);
                    cout << "press any key to quit\n";
                    results["level3"] = "IT IS INSULIN DEPENDENT Disease";

                    getch();
                    system("cls");
                    break;


                case -1:
                    gotoxy(3,12);
                    cout << "IT IS NON INSULIN DEPENDENT Disease\n\n\n\n";
                    gotoxy(3,18);
                    cout << "PRESS ANY  KEY TO QUIT .\n";
                    results["level3"] = "IT IS NON INSULIN DEPENDENT Disease";
                    getch();
                    system("cls");
                    break;
            }

            break ;
    }
    return ch;
}


void Disease::getSymptoms2() {
    system("cls");
    int j=0;
    char tempChar;
    tempChar = 'x';

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout <<"PANCREATITIS ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
           cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
        cin.clear();
        cin.ignore(10000,'\n');
    }
    arrValues[j] = toupper(tempChar);
    level2["PANCREATITIS ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;


    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "CARCINOMA ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["CARCINOMA ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "CIRHHOSIS ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["CIRHHOSIS ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;


    while(tempChar != 'h' || tempChar != 'l' || tempChar != 'n' || tempChar != 'H' || tempChar != 'L' || tempChar != 'N' ){
         cout<<"\n\t\t\t ";
        cout << "HCTS ----> (HIGH = H | LOW = L | NORMAL = N): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'h' || tempChar == 'l' || tempChar == 'n' || tempChar == 'H' || tempChar == 'L' || tempChar == 'N' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["HCTS ----> (HIGH = H | LOW = L | NORMAL = N): "] = arrValues[j];
    ++j;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "HEPATITIS ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["HEPATITIS ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "HORMONAL DISORDER ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["HORMONAL DISORDER ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "PANCREATECTOMY  ----> (PASSIVE = P | ACTIVE = A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[j] = toupper(tempChar);
    level2["PANCREATECTOMY  ----> (PASSIVE = P | ACTIVE = A): "] = arrValues[j];
    ++j;


    return;
}

void Disease::getSymptoms3() {
    int k=0;
    system("cls");
    char tempChar;
    tempChar = 'x';

    while(tempChar != 'y' || tempChar != 'm' || tempChar != 'e' || tempChar != 'Y' || tempChar != 'M' || tempChar != 'E' ){
        cout<<"\n\t\t\t ";
        cout << "AGE ====> young(Y) | Middle aged(M) | Elderly(E)): " ;
        SetConsoleTextAttribute(hConsole, 10);
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'y' || tempChar == 'm' || tempChar == 'e' || tempChar == 'Y' || tempChar == 'M' || tempChar == 'E'){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
        cin.clear();
        cin.ignore(10000,'\n');
    }
    arrValues[k] = toupper(tempChar);
    level3["AGE ====> young(Y) | Middle aged(M) | Elderly(E)): "] = arrValues[k];
    ++k;

    while(tempChar != 'n' || tempChar != 'a' || tempChar != 'b' || tempChar != 'N' || tempChar != 'A' || tempChar != 'B' ){
        cout<<"\n\t\t\t ";
        cout << "BODY WEIGHT ====> normal(N) | Above normal(A) | Below normal(B): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'n' || tempChar == 'a' || tempChar == 'b' || tempChar == 'N' || tempChar == 'A' || tempChar == 'B'){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[k] = toupper(tempChar);
    level3["BODY WEIGHT ====> normal(N) | Above normal(A) | Below normal(B): "] = arrValues[k];
    ++k;

    while(tempChar != 'w' || tempChar != 'm' || tempChar != 'y' || tempChar != 'W' || tempChar != 'M' || tempChar != 'Y' ){
        cout<<"\n\t\t\t ";
        cout << "DURATION ====> weeks(W) | Months(M) | Years(Y)):";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'w' || tempChar == 'm' || tempChar == 'y' || tempChar == 'W' || tempChar == 'M' || tempChar == 'Y' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[k] = toupper(tempChar);
    level3["DURATION ====> weeks(W) | Months(M) | Years(Y)): "] = arrValues[k];
    ++k;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
        cout<<"\n\t\t\t ";
        cout << "KETONUREA ====> Passive(P) | Active(A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A' ){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[k] = toupper(tempChar);
    level3["KETONUREA ====> Passive(P) | Active(A): "] = arrValues[k];
    ++k;

    while(tempChar != 'p' || tempChar != 'a' || tempChar != 'P' || tempChar != 'A' ){
         cout<<"\n\t\t\t ";
        cout << "AUTO ANTIBODIES ====> Passive(P) | Active(A): ";
        SetConsoleTextAttribute(hConsole, 10);
        cin.clear();
        cin.ignore(10000,'\n');
        cin>>tempChar;
        SetConsoleTextAttribute(hConsole, 14);
        if(tempChar == 'p' || tempChar == 'a' || tempChar == 'P' || tempChar == 'A'){
            cout<<"\n\t\t\t ";
            cout<< "-------------------------------------------------------------- "<<endl;
            break;
        }
    }
    arrValues[k] = toupper(tempChar);
    level3["AUTO ANTIBODIES ====> Passive(P) | Active(A): "] = arrValues[k];
    ++k;

    return;
}


