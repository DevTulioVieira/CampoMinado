#include <iostream>
#include <ctime>
#include <stdio.h>

#define facil 10

using namespace std;

int Intrucoes(){
    inicio:
    cout<<"\t\tBEM VINDO AO"<<endl;
    cout<<"\t\tCAMPO MINADO"<<endl;
    cout<<"1-Jogar"<<endl;
    cout<<"2-Como Jogar"<<endl;
    cout<<"3-Sobre"<<endl;
    cout<<"4-Sair"<<endl;
    int x;
    cin>>x;
    system("cls");
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) exit(0);
    goto inicio;
}

void Sobre(){
    cout<<"Campo Minado: As regras do Campo Minado sao simples: Se voce descobrir uma mina, o jogo acaba."<<endl;
    cout<<"Se descobrir um quadrado vazio, o jogo continua."<<endl;
    cout<<"Se aparecer um numero, ele informara quantas minas estao escondidas nos oito quadrados que o cercam"<<endl<<endl;
    cout<<"Desenvolvedores: Tulio Vieira da Silva, GitHub: https://github.com/DevTulioVieira/"<<endl;
    cout<<"Disponivel em:   https://github.com/DevTulioVieira/Meus-Jogos-My-Games/tree/main/CampoMinado"<<endl;
    cout<<"Sobre:           Linguagem C++, Editor VsCode Studio, Data Inicio 27/07/2023, Idealizador Tulio Vieira da Silva"<<endl;
    system("pause");
    system("cls");
}

void ComoJogar(){
    system("pause");
    system("cls");
}

int Modo(){
    inicio:
    cout<<"Selecione a dificuldade!"<<endl;
    cout<<"1-Facil"<<endl;
    cout<<"3-Medio"<<endl;
    cout<<"3-Dificil"<<endl;
    cout<<"4-Personalizado"<<endl;
    cout<<"5-Volta"<<endl;
    int x;
    cin>>x;
    system("cls");
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 3;
    if(x==4) return 4;
    if(x==5) return 5;
    goto inicio;
}

void Jogar(int matriz[][facil], int ver[][facil], int numbombas){

}

void Mostrar(int matriz[][facil], int ver[][facil], int numbombas){
    int i, j;
    cout<<"  0 1 2 3 4 5 6 7 8 9"<<endl;
    for(i=0; i<numbombas; i++){
        cout<<i<<" ";
        for(j=0; j<numbombas; j++){
            if(ver[i][j]==0){
                cout<<"#"<<" ";
            }else{
                if (matriz[i][j]==9){
                    cout<<"@"<<" ";
                    continue;
                }else{
                    cout<<matriz[i][j]<<" ";
                }
            } 
        }
        cout<<endl;
    }
}

void GeraBombas(int matriz[][facil], int numbombas){
    int aux=0, x, y;
    srand(time(0));

    while(aux<numbombas){
        iniciobomba:
        x=rand()%10;
        y=rand()%10;
        if(matriz[x][y]==9){
            goto iniciobomba;
        }
        matriz[x][y]=9;

        aux++;
    }
}

void GeraNumeros(int matriz[][facil], int numbombas){
    int aux;
    for(int i=0; i<numbombas; i++){
        for(int j=0; j<numbombas; j++){
            aux=0;
            if(matriz[i][j]!=9){
                if((i-1)>=0 && (j-1)>=0 && matriz[(i-1)][(j-1)]==9) aux+=1;
                if((i-1)>=0 && matriz[(i-1)][j]==9) aux+=1;
                if((i-1)>=0 && (j+1)<numbombas && matriz[(i-1)][(j+1)]==9) aux+=1;
                if((j-1)>=0 && matriz[i][(j-1)]==9) aux+=1;
                if((j+1)<numbombas && matriz[i][(j+1)]==9) aux+=1;
                if((i+1)<numbombas && (j-1)>=0 && matriz[(i+1)][(j-1)]==9) aux+=1;
                if((i+1)<numbombas && matriz[(i+1)][j]==9) aux+=1;
                if((i+1)<numbombas && (j+1)<numbombas && matriz[(i+1)][(j+1)]==9) aux+=1;
                matriz[i][j]=aux;
            }
        }
    }
}

void Ocultar(int ver[][facil], int numbombas){
    int i, j;
    for(i=0; i<numbombas; i++){
        for(j=0; j<numbombas; j++){
            ver[i][j]=0;
        }
    }
}

int main(){
    int modo, intro, numbombas=0, i, j;

    for(;;){
        iniIntro:
        intro=Intrucoes();
        if(intro==2) ComoJogar();
        if(intro==3) Sobre();
        if(intro==4) exit(0);
        if(intro!=1) goto iniIntro;
        modo=Modo();
        switch(modo){
            case 1:
                numbombas=10;
                int matriz[10][10];
                int ver[10][10];
                GeraBombas(matriz, numbombas);
                GeraNumeros(matriz, numbombas);
                Ocultar(ver, numbombas);
                Mostrar(matriz, ver, numbombas);
                Jogar(matriz, ver, numbombas);
                system("cls");
            break;

            case 2:
                system("cls");
            break;

            case 3:
                system("cls");
            break;

            case 4:
                system("cls");
            break;

            case 5:
                system("cls");
                break;
            break;

            default:
                system("cls");
            break;
            cout<<"oi";
        }
    }

    return 0;
}
