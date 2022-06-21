#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>


using namespace std;

void limpaTela(){
    system("CLS");

}

string retornaPalavraAleatoria(){
    string palavras [3] = {"abacaxi", "manga", "morango"};
    int indiceAleatorio = rand() % 3;
    return palavras[indiceAleatorio];

}

string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    int cont = 0;
    string palavraComMascara;
    while(cont < tamanhoDaPalavra){ //Coloca a mascara na palavra
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;

}

void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){
        cout << mensagem;
        cout << "\nPalavra: " << palavraComMascara << "(Tamanho:" << tamanhoDaPalavra << ")";
        cout << "\nTentativas restantes: " << tentativasRestantes;
        

        int cont = 0;
        cout << "\nLetras ja arriscadas: ";
        for (cont = 0; cont < letrasJaArriscadas.size(); cont++){
            cout << letrasJaArriscadas[cont] << ", ";
        }
}

int jogar(int numeroDeJogadores){
    string palavra;
    if(numeroDeJogadores == 1){
        palavra = retornaPalavraAleatoria();
    }else{
        cout << "\nDigite uma Palavra: ";
        cin >> palavra;
    }

    int tamanhoDaPalavra = palavra.size();

    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);
    
    //Variaveis Gerais
    int tentativas = 0, maximoDeTentativas = 10;
    int cont = 0;
    char letra;
    int opcao;
    string letrasJaArriscadas;
    string mensagem = "Bem vindo ao jogo!";
    string palavraArriscada;
    bool jaDigitouLetra = false, acertouLetra = false;

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0 ){
        limpaTela();
        exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);
        cout << "\nDigite uma letra: (ou digite 1 para arriscar a palavra: )";
        cin >> letra;

        if (letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                tentativas = maximoDeTentativas;
            }
        }

        for (cont = 0 ; cont < tentativas; cont++){
            
            if (letrasJaArriscadas[cont] == letra){
                mensagem = "Essa letra ja foi digitada";
                jaDigitouLetra = true;
            }
        }

        if(jaDigitouLetra == false){
            letrasJaArriscadas += tolower(letra);
            for(cont = 0; cont < tamanhoDaPalavra; cont++){ //percorre a palavra
                if(palavra[cont] == tolower(letra)){
                    palavraComMascara[cont] = palavra[cont]; //revela a letra em caso de acerto
                    acertouLetra = true;
                }
           }
        
                if(acertouLetra == false) {
                    mensagem = "Voce errou uma letra!";
                }else{
                    mensagem = "Voce acertou uma letra!";
                }

            tentativas ++;
        }
       jaDigitouLetra = false;
       acertouLetra = false;
        
    }
    if(palavra == palavraComMascara){
       
        limpaTela();
        cout << "\nParabens, voce venceu!";
        cout << "\nDeseja reiniciar? (1 - Sim / 2 - Nao)";
        cin >> opcao;
        return opcao;

    }else{
        cout << "Voce perdeu!" << palavra;
        cout << "\nDeseja reiniciar? (1 - Sim / 2 - Nao)";
        cin >> opcao;
        return opcao;
    }
}



void menuInicial(){
        int opcao = 0;

    while( opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao JOGO";
        cout << "\n1 - Jogar Sozinho";
        cout << "\n2 - Jogar em Dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha uma opcao e tecle enter: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                if(jogar(1) == 1){
                    menuInicial();
                }
                break;
            case 2:
                if(jogar(2) == 1){
                    menuInicial();
                }
                break;
            case 3:
                cout << "Informações do Jogo";
                limpaTela();
                cout << "Jogo desenvolvido por Rafael Fritsch";
                cout << "\nEstudos sobre C ++ - 2022";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair";
                cin >> opcao;
                if (opcao == 1){
                    menuInicial();
                }
                break;
            case 4:
                cout << "Obrigado por jogar!";
                break;
        }
            
        
    }

}

int main(){

    srand((unsigned)time(NULL)); // para gerar numeros aleatorios
    menuInicial();

    return 0;


}