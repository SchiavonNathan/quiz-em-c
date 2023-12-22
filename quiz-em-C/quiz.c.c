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
  printf("\n                                             [2] -    CRÉDITOS ");
  printf("\n                                             [3] -    RANKING ");
  printf("\n                                             [4] -     REGRAS ");
  printf("\n                                             [5] -      SAIR ");
  printf("\n\n\n\n                                             OPÇÃO:  ");

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
		printf("        	 |           NICK: %s - PONTUAÇÃO: %.0f - DIFICULDADE: %s            \n\n",nick[x],pont[x],difSessao[x]);
		Sleep(200);
	}
	printf("        	 |           ");
	printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OPÇÃO:  ");
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
    printf("\n\n                                                     OPÇÃO:  ");
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
    printf("\n\n                                                     OPÇÃO:  ");
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
	printf("                            *    1 - TEMOS 3 DIFICULADES COM 10 QUESTÕES CADA;     *\n");
 	printf("                            *                                                      *\n");
	Sleep(200);
	printf("                            *    2 - A CADA PERGUNTA ACERTADA VOCÊ ACOMULA PONTOS  *\n");
 	Sleep(200);
	printf("                            *        NO MULTIPLICADOR;                             *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            *    3 - A CADA PERGUNTA ERRADA VOCÊ PERDE PONTOS;     *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            *                                                      *\n");
 	Sleep(200);
	printf("                            ********************************************************\n");
 	Sleep(200);
	printf("\n                                             [9] - RETORNAR AO MENU");
    printf("\n\n                                                     OPÇÃO:  ");
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
        printf("\n\n                                                     [1] - FÁCIL");
        printf("\n                                                     [2] - MÉDIO");
        printf("\n                                                     [3] - DIFÍCIL");
        printf("\n\n                                                           OPÇÃO:  ");
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
//-------------------------------------------QUESTÕES-------------------------------------------
void facilTec(){	
	do{
	fflush(stdin);	
	system("cls");
	printf("QUESTÃO 1\n");
	printf("Qual destes tipos de arquivo é comumente usado para armazenar música digital?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 2----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 2\n");
	printf("Qual empresa é mais conhecida por produzir o sistema operacional Android?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 3----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 3\n");
	printf("Quais desses tipos de configurações de email possuem a caracteristica de não fazer cópia dos emails enviados?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 4----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 4\n");
	printf("Qual destes serviços é amplamente utilizado para armazenar e sincronizar arquivos na nuvem?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 5----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 5\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 6----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 6\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 7----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 7\n");
	printf("Qual termo descreve a prática de enviar e-mails fraudulentos na tentativa de enganar as pessoas?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 8----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 8\n");
	printf("Qual é a principal diferença entre um disco rígido (HD) e um disco de estado sólido (SSD)?");
	printf("\na) Velocidade de leitura  ");
	printf("\nb) Capacidade de armazenamento ");
	printf("\nc) Tipo de conexão");
	printf("\nd) Método de gravação\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 9----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 9\n");
	printf("O que é a programação orientada a objetos?");
	printf("\na) Um tipo de linguagem de programação  ");
	printf("\nb) Um paradigma de programação ");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 10----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 10\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
	acertos();
}


void medioTec(){
//-------------------------------------------QUESTÃO 1----------------------------------------
	do{
	fflush(stdin);
	system("cls");
	printf("QUESTÃO 1\n");
	printf("Qual é a diferença entre um ataque de phishing e um ataque de ransomware?");
	printf("\na) Phishing é exclusivamente direcionado a dispositivos móveis, enquanto ransomware atinge computadores pessoais.");
	printf("\nb) Phishing é um ataque de negação de serviço, e ransomware é um ataque de interceptação de dados.");
	printf("\nc) Phishing envolve enganar as pessoas para obter informações confidenciais, enquanto ransomware criptografa dados e exige resgate.");
	printf("\nd) Phishing é um tipo de vírus de computador, e ransomware é uma técnica de hacking.\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 2----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 2\n");
	printf("O que é um firewall em termos de segurança de rede?");
	printf("\na) Um software que protege contra vírus de computador  ");
	printf("\nb) Um dispositivo que impede o acesso não autorizado à rede ");
	printf("\nc) Um protocolo de criptografia para comunicação segura");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 3----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 3\n");
	printf("Em redes de computadores, qual é a função do protocolo TCP?");
	printf("\na) Roteamento de pacotes  ");
	printf("\nb) Controle de congestionamento e transmissão confiável ");
	printf("\nc) Descoberta de dispositivos na rede");
	printf("\nd) Endereçamento IP\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 4----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 4\n");
	printf("Qual é o propósito de um servidor DNS?");
	printf("\na) Navegar na internet  ");
	printf("\nb) Converter endereços IP em nomes de domínio ");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);

//-------------------------------------------QUESTÃO 5----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 5\n");
	printf("O que é o termo ''cloud computing'' (computação em nuvem)?");
	printf("\na) Um tipo de programa antivírus");
	printf("\nb) Um método de resfriamento de hardware");
	printf("\nc) Um modelo de entrega de serviços pela internet");
	printf("\nd) Uma técnica de programação de jogos\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 6----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 6\n");
	printf("Qual é a função principal de um firewall em um sistema de computador?");
	printf("\na) Melhorar o desempenho da CPU ");
	printf("\nb) Otimizar a velocidade da internet  ");
	printf("\nc) Ampliar a capacidade de armazenamento ");
	printf("\nd) Proteger contra ameaças de segurança na rede\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 7----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 7\n");
	printf("O que é um banco de dados relacional?");
	printf("\na) Um banco de dados sem tabelas");
	printf("\nb) Um banco de dados hierárquico");
	printf("\nc) Um banco de dados com tabelas interligadas");
	printf("\nd) Um banco de dados distribuído\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 8----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 8\n");
	printf("O que é um backup incremental em termos de segurança da informação?");
	printf("\na) Um backup que inclui apenas os arquivos alterados desde o último backup  ");
	printf("\nb) Um backup que é executado automaticamente a cada hora ");
	printf("\nc) Um backup que salva todo o sistema em intervalos regulares");
	printf("\nd) Um backup que é armazenado em uma localização externa à rede\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 9----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 9\n");
	printf("O que é um ataque de força bruta em segurança de senha?");
	printf("\na) Um ataque que utiliza métodos complexos de criptografia para quebrar senhas  ");
	printf("\nb) Uma tentativa de adivinhar uma senha testando todas as combinações possíveis ");
	printf("\nc) Um ataque que manipula as configurações de firewall para obter acesso");
	printf("\nd) Uma técnica que explora falhas em algoritmos de criptografia\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 10----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 10\n");
	printf("Em redes de computadores, qual é a função do protocolo TCP?");
	printf("\na) Controle de congestionamento e transmissão confiável  ");
	printf("\nb) Roteamento de pacotes ");
	printf("\nc) Descoberta de dispositivos na rede");
	printf("\nd) Endereçamento IP\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
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
	printf("QUESTÃO 1\n");
	printf("Quando foi lançado o sistema operacional Unix e qual foi o seu principal objetivo inicial?");
	printf("\na) 1970; Suporte a jogos");
	printf("\nb) 1985; Interface gráfica de usuário");
	printf("\nc) 1969; Suporte a aplicações comerciais");
	printf("\nd) 1995; Integração de dispositivos móveis\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 2----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 2\n");
	printf("O que é um sistema de arquivos distribuído e qual é sua finalidade?");
	printf("\na) Um sistema que organiza arquivos em discos locais para melhor desempenho  ");
	printf("\nb) Um sistema que permite o compartilhamento de arquivos entre diferentes computadores através de uma rede ");
	printf("\nc) Um sistema que comprime arquivos para economizar espaço de armazenamento");
	printf("\nd) Um sistema que protege arquivos por meio de criptografia avançada\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 3----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 3\n");
	printf("Quando foi lançado o primeiro smartphone e qual empresa foi responsável por sua introdução no mercado?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 4----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 4\n");
	printf("Quando ocorreu o ataque de vírus Stuxnet e qual foi seu alvo principal?");
	printf("\na) 2005; Redes sociais");
	printf("\nb) 2010; Infraestrutura nuclear iraniana");
	printf("\nc) 1998; Instituições financeiras globais");
	printf("\nd) 2015; Sistemas de controle de tráfego aéreo\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 5----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 5\n");
	printf("O que é a arquitetura de computação em nuvem e como ela difere da infraestrutura tradicional?");
	printf("\na) Uma arquitetura que utiliza servidores locais para processamento intensivo");
	printf("\nb) Uma abordagem que depende exclusivamente de dispositivos móveis para armazenamento de dados");
	printf("\nc) Um modelo em que os recursos de computação são fornecidos pela internet, sob demanda");
	printf("\nd) Uma estrutura que utiliza apenas hardware dedicado para cada aplicação\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 6----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 6\n");
	printf("O que é a tecnologia de contêineres e qual é sua principal vantagem em relação à virtualização tradicional?");
	printf("\na) Uma tecnologia para compactação de arquivos ");
	printf("\nb) Um sistema para otimização de consumo de energia em data centers ");
	printf("\nc) Um protocolo para transferência rápida de dados entre servidores ");
	printf("\nd) Um método para isolamento de processos em sistemas operacionais\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 7----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 7\n");
	printf("O que é a Realidade Virtual (VR) e como ela é aplicada na indústria de jogos");
	printf("\na) Um modelo de monetização utilizado por desenvolvedores de jogos independentes");
	printf("\nb) Uma tecnologia que simula um ambiente tridimensional e é utilizada para criar experiências imersivas em jogos");
	printf("\nc) Uma técnica de design de personagens que torna os modelos mais realistas");
	printf("\nd) Um sistema de segurança utilizado para proteger os servidores de jogos online\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 8----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 8\n");
	printf("Qual foi o primeiro console de videogame a ser lançado comercialmente e em que ano isso aconteceu?");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 9----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 9\n");
	printf("O que é a tecnologia Li-Fi em relação a smartphones e redes de comunicação?");
	printf("\na) Uma tecnologia de exibição holográfica em tempo real");
	printf("\nb) Um método de recarga sem fio usando luz visível ");
	printf("\nc) Um protocolo de segurança avançado para transmissão de dados");
	printf("\nd) Um sistema de localização por GPS de alta precisão\n");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
      		Sleep(250);
	}
	}while((respostaTecF!='a') && (respostaTecF!='b') && (respostaTecF!='c') && (respostaTecF!='d'));
	system("pause");
	fflush(stdin);
//-------------------------------------------QUESTÃO 10----------------------------------------
	do{
	system("cls");
	printf("QUESTÃO 10\n");
	printf("Qual é a diferença fundamental entre um display AMOLED e um display LCD em smartphones?");
	printf("\na) A tecnologia de retroiluminação");
	printf("\nb) A capacidade de reprodução de cores");
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
      		printf("                                             TECLA INVÁLIDA, DIGITE NOVAMENTE: \n");
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
	
	printf("VOCÊ ACERTOU %d QUESTÕES\n", quantAcerto);
	printf("\nPONTUAÇÃO ALCANÇADA: %.0f\n", pont[contPont]);
	contPont++;
	system("pause");
	menuPrincipal();
	
	fputs(fp,nick[contPont]);
	
}


