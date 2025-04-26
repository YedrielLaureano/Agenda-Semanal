// Universidad Interamericana de Puerto Rico 
// Recinto de Bayamon
// Proyecto Integrador 
// Programacion Estructurada COMP 2315
// Yedriel Laureano Marrero
// Dana N. Paradis Echevarria

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;
/*****************************************************************************************/
//Dana N. Paradis Echevarria
// Funcion para entrar valores a los vectores de los dias de la semana
void entrarTareas(vector <string>& diaDeSemana, string dia) {
    string tarea;
    char otro = 'y';
    do {
        cout << "Entre la tarea a realizar para el " << dia << ":\n";
        cin.ignore();
        getline(cin, tarea);
        diaDeSemana.push_back(tarea);

        cout << "Deseas anadir otra tarea? (Y/N)";
        cin >> otro;

    } while (otro != 'n' && otro != 'N');

}

// Funcion para enviar los elementos dentro de los vectores de los dias de la semana al File
void enviarTareasAlFile(ofstream& MyFile, vector <string>& diaDeSemana, string dia) {
    if (diaDeSemana.empty()) {
        return;
    }

    MyFile << "\n     Lista de tareas del " << dia << "\n";
    for (string tareas : diaDeSemana) {
        MyFile << " [] " << tareas << "\n";
    }
    return;
}
/************************************************************************************/

/************************************************************************************/
//Yedriel Laureano Marrero
// Funcion para imprimir los elementos dentro de los vectores de los dias de la semana
void imprimirTareas(vector <string>& diaDeSemana, string dia) {
    if (diaDeSemana.empty()) {
        return;
    }

    cout << "\nLista de tareas del " << dia << "\n";
    for (string tareas : diaDeSemana) {
        cout << "[] " << tareas << "\n";
    }
    return;
}

// Funcion para eliminar un valor dentro de los vectores de  los dias de la semana
void eliminarTarea(vector <string>& diaDeSemana, string dia) {

    if (diaDeSemana.empty()) {
        cout << "No hay tarea en el " << dia << ".\n";
        return;
    }

    cout << "Lista de tareas del " << dia << ":\n";
    for (int i = 0; i < diaDeSemana.size(); i++) {
        cout << i + 1 << ". " << diaDeSemana[i] << "\n";
    }

    int r;
    cout << "Entre el numero de la tarea que deseas eliminar.\n";
    do {
        cin >> r; // r = respuesta
        if (r > 0 && r <= diaDeSemana.size()) {
            diaDeSemana.erase(diaDeSemana.begin() + (r - 1));
            cout << "Tarea eliminada.\n";
            return;
        }
        else {
            cout << "Numero incorrecto.\n";
            cout << "Vuelva a intentarlo.\n";
        }
    } while (r < 1 || r > diaDeSemana.size() - 1);
}

// Funcion para imprimir menu de dias de la semana
void imprimirMenu() {
    const int j = 10;
    cout << "  =======================" << "\n";
    cout << setw(j) << left << "  |  Dia" << setw(15) << right << "Numero |" << "\n";
    cout << "  |                     |\n";
    cout << setw(j) << left << "  |  Domingo" << setw(13) << right << "1   |" << "\n";
    cout << setw(j) << left << "  |  Lunes" << setw(15) << right << "2   |" << "\n";
    cout << setw(j) << left << "  |  Martes" << setw(14) << right << "3   |" << "\n";
    cout << setw(j) << left << "  |  Miercoles" << setw(11) << right << "4   |" << "\n";
    cout << setw(j) << left << "  |  Jueves" << setw(14) << right << "5   |" << "\n";
    cout << setw(j) << left << "  |  Viernes" << setw(13) << right << "6   |" << "\n";
    cout << setw(j) << left << "  |  Sabado" << setw(14) << right << "7   |" << "\n";
    cout << "  =======================" << "\n";
}
/***********************************************************************************************/


int main() {

    /****************************************************************************************/
    //Dana N. Paradis Echevarria
    string nombre_usuario;
    //chat gpt
    vector<vector<string>>dias(7);
    vector <string> diasSemana = { "Lunes","Martes","Miercoles", "Jueves", "Viernes", "Sabado","Domingo" };
    //
    /****************************************************************************************/

    /****************************************************************************************/
    //Yedriel Laureano Marrero
    const int tamMenu = 7;

    ofstream MyFile("Agenda semanal.txt");

    cout << "\n";
    cout << "          [][]   [][]     [][][]  []   []  [][]     [][] " << "\n";
    cout << "         []  []  []       []      [][] []  []  []  []  []" << "\n";
    cout << "         [][][]  [] [][]  [][]    [] [][]  []   [] [][][]" << "\n";
    cout << "         []  []  []  []   []      []  [[]  []  []  []  []" << "\n";
    cout << "         []  []  [][][]   [][][]  []   []  [][]    []  []" << "\n";
    cout << "\n";
    cout << "        [][]   [][][]  []    []   [][]   []   []   [][]   []    " << "\n";
    cout << "       []      []      [][] [[]  []  []  [][] []  []  []  []    " << "\n";
    cout << "       [][][]  [][]    [] [] []  [][][]  [] [][]  [][][]  []    " << "\n";
    cout << "           []  []      []    []  []  []  []  [[]  []  []  []    " << "\n";
    cout << "       [][][]  [][][]  []    []  []  []  []   []  []  []  [][][]" << "\n";

    cout << "Entre su nombre: ";
    getline(cin, nombre_usuario);

    int r; // r = respuesta

    cout << "Entre el numero del dia de la semana que quieres entrar las tareas.\n";
    imprimirMenu();

    do {

        cin >> r;

        switch (r) {
        case 1:
            entrarTareas(dias[6], diasSemana[6]);
            break;
        case 2:
            entrarTareas(dias[0], diasSemana[0]);
            break;
        case 3:
            entrarTareas(dias[1], diasSemana[1]);
            break;
        case 4:
            entrarTareas(dias[2], diasSemana[2]);
            break;
        case 5:
            entrarTareas(dias[3], diasSemana[3]);
            break;
        case 6:
            entrarTareas(dias[4], diasSemana[4]);
            break;
        case 7:
            entrarTareas(dias[5], diasSemana[5]);
            break;
        default:
            cout << "valor incorrecto.\n";
            cout << "Ingrese otro numero.\n";
            break;
        }
    } while (r < 1 || r > tamMenu);
    /****************************************************************************************/

    /****************************************************************************************/
    //Dana N. Paradis Echevarria
    int r2;

    do {
        cout << "\n   ===========> Menu de opciones <============\n";
        cout << "   | Entre 1 para anadir tareas nuevas.      |\n";
        cout << "   | Entre 2 para eliminar una tarea.        |\n";
        cout << "   | Entre 3 para imprimir todas las tareas. |\n";
        cout << "   | Entre 4 para salir del programa.        |\n";
        cout << "   ===========================================\n";

        cin >> r2;

        switch (r2) {
        case 1:

            int r3;

            cout << "Entre el numero del dia de la semana que quieres entrar las tareas.\n";
            imprimirMenu();
            do {

                cin >> r3;

                switch (r3) {
                case 1:
                    entrarTareas(dias[6], diasSemana[6]);
                    break;
                case 2:
                    entrarTareas(dias[0], diasSemana[0]);
                    break;
                case 3:
                    entrarTareas(dias[1], diasSemana[1]);
                    break;
                case 4:
                    entrarTareas(dias[2], diasSemana[2]);
                    break;
                case 5:
                    entrarTareas(dias[3], diasSemana[3]);
                    break;
                case 6:
                    entrarTareas(dias[4], diasSemana[4]);
                    break;
                case 7:
                    entrarTareas(dias[5], diasSemana[5]);
                    break;
                default:
                    cout << "valor incorrecto.\n";
                    cout << "Ingrese otro numero.\n";
                }
            } while (r3 < 1 || r3 > tamMenu);
            break;
        case 2:

            int r4;

            cout << "Entre el numero del dia de la semana que quieres eliminar una tarea.\n";
            imprimirMenu();
            do {

                cin >> r4;

                switch (r4) {
                case 1:
                    eliminarTarea(dias[6], diasSemana[6]);
                    break;
                case 2:
                    eliminarTarea(dias[0], diasSemana[0]);
                    break;
                case 3:
                    eliminarTarea(dias[1], diasSemana[1]);
                    break;
                case 4:
                    eliminarTarea(dias[2], diasSemana[2]);
                    break;
                case 5:
                    eliminarTarea(dias[3], diasSemana[3]);
                    break;
                case 6:
                    eliminarTarea(dias[4], diasSemana[4]);
                    break;
                case 7:
                    eliminarTarea(dias[5], diasSemana[5]);
                    break;
                default:
                    cout << "valor incorrecto.\n";
                    cout << "Ingrese otro numero.\n";
                }
            } while (r4 < 1 || r4 > tamMenu);
            break;
        case 3:
            imprimirTareas(dias[6], diasSemana[6]);
            imprimirTareas(dias[0], diasSemana[0]);
            imprimirTareas(dias[1], diasSemana[1]);
            imprimirTareas(dias[2], diasSemana[2]);
            imprimirTareas(dias[3], diasSemana[3]);
            imprimirTareas(dias[4], diasSemana[4]);
            imprimirTareas(dias[5], diasSemana[5]);

            break;
            /*********************************************************************************************/

            /*********************************************************************************************/
            //Yedriel Laureano Marrero
        case 4:
            cout << "Adios, espero verte pronto.\n";
            MyFile << "\n";
            MyFile << "          [][]   [][]     [][][]  []   []  [][]     [][] " << "\n";
            MyFile << "         []  []  []       []      [][] []  []  []  []  []" << "\n";
            MyFile << "         [][][]  [] [][]  [][]    [] [][]  []   [] [][][]" << "\n";
            MyFile << "         []  []  []  []   []      []  [[]  []  []  []  []" << "\n";
            MyFile << "         []  []  [][][]   [][][]  []   []  [][]    []  []" << "\n";
            MyFile << "\n";
            MyFile << "        [][]   [][][]  []    []   [][]   []   []   [][]   []    " << "\n";
            MyFile << "       []      []      [][] [[]  []  []  [][] []  []  []  []    " << "\n";
            MyFile << "       [][][]  [][]    [] [] []  [][][]  [] [][]  [][][]  []    " << "\n";
            MyFile << "           []  []      []    []  []  []  []  [[]  []  []  []    " << "\n";
            MyFile << "       [][][]  [][][]  []    []  []  []  []   []  []  []  [][][]" << "\n";

            MyFile << "\n     Agenda Semanal de " << nombre_usuario;
            enviarTareasAlFile(MyFile, dias[6], diasSemana[6]);
            enviarTareasAlFile(MyFile, dias[0], diasSemana[0]);
            enviarTareasAlFile(MyFile, dias[1], diasSemana[1]);
            enviarTareasAlFile(MyFile, dias[2], diasSemana[2]);
            enviarTareasAlFile(MyFile, dias[3], diasSemana[3]);
            enviarTareasAlFile(MyFile, dias[4], diasSemana[4]);
            enviarTareasAlFile(MyFile, dias[5], diasSemana[5]);

            break;
        default:
            cout << "valor incorrecto.\n";
            cout << "Ingrese otro numero.\n";
        }
    } while (r2 != 4);

    MyFile.close();

    /*************************************************************************************/

    return 0;
}

//ChatGPT. (2025). (ChatFPT 4o). https://chatgpt.com/c/680a77c5-e2b8-8004-a528-70eccbac37c9