#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void limpaTela(){
    system("CLS");

}

void menuInicial(){
        int opcao = 0;

    while( opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao JOGO";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle enter: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;

            
        }
    }
}

int main(){

    menuInicial();

    return 0;


}