#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <conio.h>

void menuPrincipal();
void menuJogar();
void regras();
void creditos();
void ranking();
void iniciarJogo();
void menuDificuldade();
void facilTec();
void medioTec();
void dificilTec();
void acertos();
void selectionSort();

float temp, pont[10], multiplicador=0;
int x, y, ajuda, classe, entergame, escolhamenu, categorias, dificuldade, stchdificuldade, stchcateg, quantAcerto, contPont=0;
char tempChar[20], correta[10], nick[10][20], difSessao[10][20], respostaTecF;

FILE *fp;


int main(){
  setlocale(LC_ALL,"Portuguese");
  menuPrincipal();
  return 0;
}
//--------------------------------------------------
void menuPrincipal(){
  fflush(stdin);
  entergame=0;
  quantAcerto=0;
  multiplicador=0;
  while(entergame!=3){
  system("cls");
  printf("\n\n ");
  printf("                           ******************************************************\n");
  Sleep(200);
  printf("                            *                  ____        _                     *\n");
  Sleep(200);
  printf("                            *                 / __ \\      (_)                    *\n");
  Sleep(200);
  printf("                            *                | |  | |_   _ _ ____                *\n");
  Sleep(200);
  printf("                            *                | |  | | | | | |_  /                *\n");
  Sleep(200);
  printf("                            *                | |__| | |_| | |/ /                 *\n");
  Sleep(200);
  printf("                            *                 \\___\\\\_\\__,_|_/___|                *\n ");
  Sleep(200);
  printf("                           *                       DOS CRIAS                    *\n");
  Sleep(200);
  printf("                            *                                                    *\n");
  Sleep(200);
  printf("                            ******************************************************\n");
  Sleep(200);
  printf("\n\n ");
  printf("\n                                             [1] - INICIAR O JOGO ");
  printf("\n                                             [2] -    CR�DITOS ");
  printf("\n                                             [3] -    RANKING ");
  printf("\n                                             [4] -     REGRAS ");
  printf("\n                                             [5] -      SAIR ");
  printf("\n\n\n\n                                             OP��O:  ");

  scanf("%d", &entergame);
  fflush(stdin);

  switch (entergame){
    case 1:
      iniciarJogo();
        break;

    case 2:
      creditos();
        break;
        
	case 3:
	  selectionSort();
		break;
		
	case 4:
      regras();
        break;
        
    case 5:
      system("cls");
      exit(0);
   		break;	

    default:
      main();
    break;
  }
  }
}     

//------------------------------------------------------------    
void ranking(){
	do{
	system("cls");
	printf("                                             	     RANKING\n\n");
	for(x=0;x<contPont;x++){
		printf("        	 |           NICK: %s - PONTUA��O: %.0f - DIFICULDADE: %s            \n\n",nick[x],pont[x],difSessao[x]);
		Sleep(200);
	}
	printf("        	 |           ");
	printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OP��O:  ");
    scanf("%d", &escolhamenu);
    fflush(stdin);
    system("cls");
    }while(escolhamenu!=9);
	main();
}

//------------------------------------------------------------   
void selectionSort(){
	for(x=0;x<9;x++){
		for(y=x;y<10;y++){
			if(pont[y]>pont[x]){
				temp=pont[y];
				pont[y]=pont[x];
				pont[x]=temp;
				
				strcpy(tempChar,nick[y]);
				strcpy(nick[y], nick[x]);
				strcpy(nick[x], tempChar);
				
				strcpy(tempChar,difSessao[y]);
				strcpy(difSessao[y], difSessao[x]);
				strcpy(difSessao[x], tempChar);
			}	
		}
	}
	ranking();
}

//------------------------------------------------------------     
void creditos(){
 	do{
	system("cls");
  	printf("\n\n ");
 	printf("                           ********************************************************\n");
 	Sleep(250);
	printf("                            *                                                      *\n");
  	Sleep(250);
	printf("                            *        QUIZ DESENVOLVIDO PELO ALUNO DE ADS-A-S2      *\n");
 	Sleep(250);
	printf("                            *                                                      *\n");
	Sleep(250);
	printf("                            *                   ~Nathan Schiavon                   *\n");
 	Sleep(250);
	printf("                            *                                                      *\n");
 	Sleep(250);
	printf("                            ********************************************************\n");
 	printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OP��O:  ");
    scanf("%d", &escolhamenu);
    fflush(stdin);
    system("cls");
    }while(escolhamenu!=9);
    entergame=0;    
}
//------------------------------------------------------------ 
void iniciarJogo(){
  system("cls"); 
  printf("\n\n\n\n                                      *************************************\n");
  printf("                                      *           _             _         *\n");
  printf("                                      *          | |           | |        *\n");
  printf("                                      *       ___| |_ __ _ _ __| |_       *\n");
  printf("                                      *      / __| __/ _` | '__| __|      *\n");
  printf("                                      *      \\__ \\ || (_| | |  | |_       *\n");
  printf("                                      *      |___/\\__\\__,_|_|   \\__|      *\n ");
  printf("                                     *                                   *\n");
  printf("                                      *************************************\n");
  printf("\n\n\n                                             INSIRA SEU NICKNAME: ");
  gets(nick[contPont]);
  fflush(stdin);
  do{
    system("cls");
    printf("\n\n\n                                                     PLAYER - %s", nick[contPont]);
    printf("\n\n\n\n                                             [1] - DIFICULDADES");
    printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OP��O:  ");
    scanf("%d", &escolhamenu);
    fflush(stdin);
    switch(escolhamenu){
      case 9:
        system("cls");
      break;

      case 1:
      menuDificuldade();
    }
  }while (escolhamenu!=9);
  entergame=0;
}
//------------------------------------------------------------ 
void regras(){
	do{
	system("cls");
	printf("\n\n ");
 	printf("                           ********************************************************\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
  	Sleep(200);
	printf("                            *    1 - TEMOS 3 DIFICULADES COM 10 QUEST�ES CADA;     *\n");
 	printf("                            *                                                      *\n");
	Sleep(200);
	printf("                            *    2 - A CADA PERGUNTA ACERTADA VOC� ACOMULA PONTOS  *\n");
 	Sleep(200);
	printf("                            *        NO MULTIPLICADOR;                             *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            *    3 - A CADA PERGUNTA ERRADA VOC� PERDE PONTOS;     *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            ********************************************************\n");
 	Sleep(200);
	printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OP��O:  ");
    scanf("%d", &escolhamenu);
    fflush(stdin);
    system("cls");
    }while(escolhamenu!=9);
    entergame=0;
}
//---------------------------------------------------------------
void menuDificuldade(){
        system("cls");
        dificuldade=0;
		printf("\n\n\n                                                     ESCOLHA A DIFICULDADE:");
        printf("\n\n                                                     [1] - F�CIL");
        printf("\n                                                     [2] - M�DIO");
        printf("\n                                                     [3] - DIF�CIL");
        printf("\n\n                                                           OP��O:  ");
        scanf("%d", &dificuldade);
        if(dificuldade>3){
        	dificuldade=0;
        	menuDificuldade();
		}
        switch(dificuldade){
          case 1:
            strcpy(difSessao[contPont], "FACIL");
			facilTec();
            break;
          case 2:
            strcpy(difSessao[contPont], "MEDIO");
			medioTec();
            break;
          case 3:
            strcpy(difSessao[contPont], "DIFICIL");
			dificilTec();
            break;
        }
    }
//-------------------------------------------QUEST�ES-------------------------------------------
void facilTec(){	
	do{
	fflush(stdin);	
	system("cls");
	printf("QUEST�O 1\n");
	printf("Qual destes tipos de arquivo � comumente usado para armazenar m�sica digital?");
	printf("\na) .PDF");
	printf("\nb) .JPG");
	printf("\nc) .MP3");
	printf("\nd) .TXT\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 2----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 2\n");
	printf("Qual empresa � mais conhecida por produzir o sistema operacional Android?");
	printf("\na) Apple");
	printf("\nb) Microsoft");
	printf("\nc) Google");
	printf("\nd) IBM\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 3----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 3\n");
	printf("Quais desses tipos de configura��es de email possuem a caracteristica de n�o fazer c�pia dos emails enviados?");
	printf("\na) POP3 ");
	printf("\nb) IMAP ");
	printf("\nc) Exchange");
	printf("\nd) Outlook\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 4----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 4\n");
	printf("Qual destes servi�os � amplamente utilizado para armazenar e sincronizar arquivos na nuvem?");
	printf("\na) Open VPN ");
	printf("\nb) Endpoint ");
	printf("\nc) VNCServer");
	printf("\nd) NextCloud\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 5----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 5\n");
	printf("Como se chama o sistema operacional dos Macbooks da Apple?");
	printf("\na) IOS ");
	printf("\nb) MacOS  ");
	printf("\nc) Linux");
	printf("\nd) Windows\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 6----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 6\n");
	printf("Qual a principal linguagem utilizada para front-end?");
	printf("\na) Python ");
	printf("\nb) CSS  ");
	printf("\nc) JavaScript ");
	printf("\nd) HTML\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 7----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 7\n");
	printf("Qual termo descreve a pr�tica de enviar e-mails fraudulentos na tentativa de enganar as pessoas?");
	printf("\na) Phishing  ");
	printf("\nb) Spam ");
	printf("\nc) Streaming");
	printf("\nd) Firewall\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.25;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 8----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 8\n");
	printf("Qual � a principal diferen�a entre um disco r�gido (HD) e um disco de estado s�lido (SSD)?");
	printf("\na) Velocidade de leitura  ");
	printf("\nb) Capacidade de armazenamento ");
	printf("\nc) Tipo de conex�o");
	printf("\nd) M�todo de grava��o\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 9----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 9\n");
	printf("O que � a programa��o orientada a objetos?");
	printf("\na) Um tipo de linguagem de programa��o  ");
	printf("\nb) Um paradigma de programa��o ");
	printf("\nc) Um sistema operacional");
	printf("\nd) Um tipo de hardware\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 10----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 10\n");
	printf("O que significa a sigla VPN?");
	printf("\na) Virtual Private Network  ");
	printf("\nb) Very Personal Navigator ");
	printf("\nc) Video Processing Node");
	printf("\nd) Voice and Phone Network\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
	acertos();
}


void medioTec(){
//-------------------------------------------QUEST�O 1----------------------------------------
	do{
	fflush(stdin);
	system("cls");
	printf("QUEST�O 1\n");
	printf("Qual � a diferen�a entre um ataque de phishing e um ataque de ransomware?");
	printf("\na) Phishing � exclusivamente direcionado a dispositivos m�veis, enquanto ransomware atinge computadores pessoais.");
	printf("\nb) Phishing � um ataque de nega��o de servi�o, e ransomware � um ataque de intercepta��o de dados.");
	printf("\nc) Phishing envolve enganar as pessoas para obter informa��es confidenciais, enquanto ransomware criptografa dados e exige resgate.");
	printf("\nd) Phishing � um tipo de v�rus de computador, e ransomware � uma t�cnica de hacking.\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.15;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 2----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 2\n");
	printf("O que � um firewall em termos de seguran�a de rede?");
	printf("\na) Um software que protege contra v�rus de computador  ");
	printf("\nb) Um dispositivo que impede o acesso n�o autorizado � rede ");
	printf("\nc) Um protocolo de criptografia para comunica��o segura");
	printf("\nd) Uma ferramenta para monitoramento de largura de banda\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 3----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 3\n");
	printf("Em redes de computadores, qual � a fun��o do protocolo TCP?");
	printf("\na) Roteamento de pacotes  ");
	printf("\nb) Controle de congestionamento e transmiss�o confi�vel ");
	printf("\nc) Descoberta de dispositivos na rede");
	printf("\nd) Endere�amento IP\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 4----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 4\n");
	printf("Qual � o prop�sito de um servidor DNS?");
	printf("\na) Navegar na internet  ");
	printf("\nb) Converter endere�os IP em nomes de dom�nio ");
	printf("\nc) Armazenar arquivos de sistema operacional");
	printf("\nd) Proteger contra malware\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);

//-------------------------------------------QUEST�O 5----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 5\n");
	printf("O que � o termo ''cloud computing'' (computa��o em nuvem)?");
	printf("\na) Um tipo de programa antiv�rus");
	printf("\nb) Um m�todo de resfriamento de hardware");
	printf("\nc) Um modelo de entrega de servi�os pela internet");
	printf("\nd) Uma t�cnica de programa��o de jogos\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 6----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 6\n");
	printf("Qual � a fun��o principal de um firewall em um sistema de computador?");
	printf("\na) Melhorar o desempenho da CPU ");
	printf("\nb) Otimizar a velocidade da internet  ");
	printf("\nc) Ampliar a capacidade de armazenamento ");
	printf("\nd) Proteger contra amea�as de seguran�a na rede\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 7----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 7\n");
	printf("O que � um banco de dados relacional?");
	printf("\na) Um banco de dados sem tabelas");
	printf("\nb) Um banco de dados hier�rquico");
	printf("\nc) Um banco de dados com tabelas interligadas");
	printf("\nd) Um banco de dados distribu�do\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.15;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 8----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 8\n");
	printf("O que � um backup incremental em termos de seguran�a da informa��o?");
	printf("\na) Um backup que inclui apenas os arquivos alterados desde o �ltimo backup  ");
	printf("\nb) Um backup que � executado automaticamente a cada hora ");
	printf("\nc) Um backup que salva todo o sistema em intervalos regulares");
	printf("\nd) Um backup que � armazenado em uma localiza��o externa � rede\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 9----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 9\n");
	printf("O que � um ataque de for�a bruta em seguran�a de senha?");
	printf("\na) Um ataque que utiliza m�todos complexos de criptografia para quebrar senhas  ");
	printf("\nb) Uma tentativa de adivinhar uma senha testando todas as combina��es poss�veis ");
	printf("\nc) Um ataque que manipula as configura��es de firewall para obter acesso");
	printf("\nd) Uma t�cnica que explora falhas em algoritmos de criptografia\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.15;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 10----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 10\n");
	printf("Em redes de computadores, qual � a fun��o do protocolo TCP?");
	printf("\na) Controle de congestionamento e transmiss�o confi�vel  ");
	printf("\nb) Roteamento de pacotes ");
	printf("\nc) Descoberta de dispositivos na rede");
	printf("\nd) Endere�amento IP\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.15;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
	acertos();
}

void dificilTec(){
	do{
	fflush(stdin);	
	system("cls");
	printf("QUEST�O 1\n");
	printf("Quando foi lan�ado o sistema operacional Unix e qual foi o seu principal objetivo inicial?");
	printf("\na) 1970; Suporte a jogos");
	printf("\nb) 1985; Interface gr�fica de usu�rio");
	printf("\nc) 1969; Suporte a aplica��es comerciais");
	printf("\nd) 1995; Integra��o de dispositivos m�veis\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.20;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 2----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 2\n");
	printf("O que � um sistema de arquivos distribu�do e qual � sua finalidade?");
	printf("\na) Um sistema que organiza arquivos em discos locais para melhor desempenho  ");
	printf("\nb) Um sistema que permite o compartilhamento de arquivos entre diferentes computadores atrav�s de uma rede ");
	printf("\nc) Um sistema que comprime arquivos para economizar espa�o de armazenamento");
	printf("\nd) Um sistema que protege arquivos por meio de criptografia avan�ada\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.15;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 3----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 3\n");
	printf("Quando foi lan�ado o primeiro smartphone e qual empresa foi respons�vel por sua introdu��o no mercado?");
	printf("\na) 2007; Apple");
	printf("\nb) 1999; Samsung");
	printf("\nc) 2003; Google");
	printf("\nd) 2010; Microsoft\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 4----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 4\n");
	printf("Quando ocorreu o ataque de v�rus Stuxnet e qual foi seu alvo principal?");
	printf("\na) 2005; Redes sociais");
	printf("\nb) 2010; Infraestrutura nuclear iraniana");
	printf("\nc) 1998; Institui��es financeiras globais");
	printf("\nd) 2015; Sistemas de controle de tr�fego a�reo\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 5----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 5\n");
	printf("O que � a arquitetura de computa��o em nuvem e como ela difere da infraestrutura tradicional?");
	printf("\na) Uma arquitetura que utiliza servidores locais para processamento intensivo");
	printf("\nb) Uma abordagem que depende exclusivamente de dispositivos m�veis para armazenamento de dados");
	printf("\nc) Um modelo em que os recursos de computa��o s�o fornecidos pela internet, sob demanda");
	printf("\nd) Uma estrutura que utiliza apenas hardware dedicado para cada aplica��o\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 6----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 6\n");
	printf("O que � a tecnologia de cont�ineres e qual � sua principal vantagem em rela��o � virtualiza��o tradicional?");
	printf("\na) Uma tecnologia para compacta��o de arquivos ");
	printf("\nb) Um sistema para otimiza��o de consumo de energia em data centers ");
	printf("\nc) Um protocolo para transfer�ncia r�pida de dados entre servidores ");
	printf("\nd) Um m�todo para isolamento de processos em sistemas operacionais\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 7----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 7\n");
	printf("O que � a Realidade Virtual (VR) e como ela � aplicada na ind�stria de jogos");
	printf("\na) Um modelo de monetiza��o utilizado por desenvolvedores de jogos independentes");
	printf("\nb) Uma tecnologia que simula um ambiente tridimensional e � utilizada para criar experi�ncias imersivas em jogos");
	printf("\nc) Uma t�cnica de design de personagens que torna os modelos mais realistas");
	printf("\nd) Um sistema de seguran�a utilizado para proteger os servidores de jogos online\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.05;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 8----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 8\n");
	printf("Qual foi o primeiro console de videogame a ser lan�ado comercialmente e em que ano isso aconteceu?");
	printf("\na) Nintendo Entertainment System (NES) em 1985");
	printf("\nb) Atari 2600 em 1977");
	printf("\nc) Magnavox Odyssey em 1972");
	printf("\nd) Sega Master System em 1986\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 9----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 9\n");
	printf("O que � a tecnologia Li-Fi em rela��o a smartphones e redes de comunica��o?");
	printf("\na) Uma tecnologia de exibi��o hologr�fica em tempo real");
	printf("\nb) Um m�todo de recarga sem fio usando luz vis�vel ");
	printf("\nc) Um protocolo de seguran�a avan�ado para transmiss�o de dados");
	printf("\nd) Um sistema de localiza��o por GPS de alta precis�o\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'b':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUEST�O 10----------------------------------------
	do{
	system("cls");
	printf("QUEST�O 10\n");
	printf("Qual � a diferen�a fundamental entre um display AMOLED e um display LCD em smartphones?");
	printf("\na) A tecnologia de retroilumina��o");
	printf("\nb) A capacidade de reprodu��o de cores");
	printf("\nc) O consumo de energia");
	printf("\nd) A espessura do display\n");
	printf("\n\n\n\n                                             RESPOSTA:  ");
	scanf("%c", &respostaTecF);
	respostaTecF=tolower(respostaTecF);
	switch(respostaTecF){
		case 'a':
			printf("RESPOSTA CORRETA:)     \n");
			quantAcerto=quantAcerto+1;
			multiplicador=multiplicador+0.10;
			break;
		case 'b': 
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'c':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		case 'd':
			printf("RESPOSTA ERRADA:(     \n");
			break;
		default:
      		printf("                                             TECLA INV�LIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
	acertos();
}

void acertos(){
	
	fp=fopen("pont.txt","a");
	
	fflush(stdin);
	system("cls");
	pont[contPont]=1000*multiplicador;
	
	printf("VOC� ACERTOU %d QUEST�ES\n", quantAcerto);
	printf("\nPONTUA��O ALCAN�ADA: %.0f\n", pont[contPont]);
	contPont++;
	system("pause");
	menuPrincipal();
	
	fputs(fp,nick[contPont]);
	
}


