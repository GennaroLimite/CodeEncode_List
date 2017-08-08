// Limite Gennaro matricola n° 0124000891

//Sviluppare una coppia di algoritmi, implementati come function, per crittografare
//e decrittografare un messaggio. L’algoritmo si basa sulla cosiddetta cifratura
//polialfabetica, che consiste nel trasformare il messaggio in un testo di lunghezza
//maggiore o uguale a quella del messaggio, detto il “testo cifrato”, utilizzando una
//matrice di caratteri (prefissata), detta “matrice di sostituzione”. Il messaggio da
//crittografare viene dapprima partizionato in coppie di lettere adiacenti; se in tale
//partizionamento accade che una coppia è formata dalla stessa lettera, allora si
//inserisce una X tra le due.
//Ogni coppia di lettere viene crittografata nel seguente modo:
    //a. se le lettere sono nella stessa riga della matrice di sostituzione, le due
    //lettere da inserire nel testo cifrato saranno le lettere immediatamente a
    //destra nella stessa riga. Ogni riga è considerata circolare.
    //b. se le lettere sono nella stessa colonna della matrice di sostituzione, le due
    //lettere da inserire nel testo cifrato saranno le lettere immediatamente sotto
    //nella stessa colonna. Ogni colonna è considerata circolare.
    //c. se le lettere appaiono in differenti righe e colonne della matrice di
    //sostituzione, ognuna delle due lettere sarà crittografata con la lettera nella
    //stessa riga ma nella colonna dell’altra lettera...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAX 100

void	cerca_x(char *, int);
void	stampa_matrice(char[][9]);
void	decod(char *, char[][9], char *, int);
void	elimina_spazi(char *, char *, int);
void	cerca_lettera(char, char[][9], int *, int *);
void	separa(char *, char *, int);
void	codif(char *, char[][9], char *, int);

//      MAIN
int main()
{
int   n, i, scelta, ncr, ncc, ncr2, ncc2, combinazioni;
char  matr_di_sost[4][9] =
{
            { '8', 'J', 'E', 'Q', 'D', 'N', '5', 'O', },
            { 'P', 'U', '3', 'A', 'R', 'F', 'L', 'W', },
            { '4', 'V', 'C', '2', 'T', 'M', 'B', 'I', },
            { 'K', '7', 'Z', 'S', 'G', 'X', 'H', 'Y', },
};
//pulitura stringhe
char    mex [MAX] = {0},
        mex_cifr [MAX] = {0},
        mex_dec [MAX] = {0},
        mex_X [MAX] = {0},
        mex_senza_spazi[MAX]={0},
        temp;
do
{
printf("Programma Per Cifratura-Decifratura Messaggi\n");
printf("Scegli Operazione : \n");
printf("1)Matrice di sostituzione statica \n");
printf("2)Matrice di sostituzione Random \n");
printf("3)Uscita \n");
printf("Scelta = ");
scanf("%1d", &scelta);
switch(scelta)
{
    case 1:
            {
                fflush(stdin);          //pulitura
                printf("Inserisci il messaggio da crittografare: \n");
                gets(mex);        //input messaggio
                strupr(mex);      //conversione minuscolo maiuscolo
                n = strlen(mex);  //lunghezza messaggio
                elimina_spazi(mex, mex_senza_spazi, n);   //eliminazione spazi
                n = strlen(mex_senza_spazi);  //messaggio senza spazi
                printf("Messaggio senza spazi: %s\n", mex_senza_spazi);
                separa(mex_senza_spazi, mex_X, n);  //separazione coppie
                n = strlen(mex_X);      //dimensione stringa con X
//visualizzazione messaggio
                printf("Messaggio ottenuto inserendo le X tra le coppie adiacenti uguali : \n%s\n",mex_X);
                codif(mex_X, matr_di_sost, mex_cifr, n);   //codifica
                printf("Messaggio codificato contenente l'eventuale X tra le coppie risultate uguali : \n%s\n", mex_cifr);
                n = strlen(mex_cifr);      //dimensione
                decod(mex_cifr, matr_di_sost, mex_dec, n);  //decodifica con matrice statica
                n = strlen(mex_dec); //lunghezza messaggio
                printf("Messaggio decodificato contenente l'eventuale X tra le coppie risultate uguali : \n%s\n",mex_dec);  /* la stampo */
                cerca_x(mex_dec, n); //cerco eventuali X aggiunte tra le lettere uguali
                elimina_spazi(mex_dec, mex_senza_spazi, n);  //eliminazione spazi
                printf("Messaggio iniziale %s\n", mex_senza_spazi);         //visualizzazione messaggio
            }
break;

            case 2:
                  {
                        printf("\n Matrice di sostituzione non Permutata :\n");
                        stampa_matrice(matr_di_sost);
//generazione numeri casuali
                        srand(time(NULL));
                        do
                        {
                              printf("Quante volte vuoi mescolare la matrice di sostituzione?\n");
                              scanf("%d", &combinazioni);
                        } while(combinazioni < 0);
                        for(i = 0; i < combinazioni; i++)
                        {
                              ncr = rand() % 4;
                              ncc = rand() % 8;      // generazione numero di riga e di colonna del primo simbolo da scambiare
                              ncr2 = rand() % 4;
                              ncc2 = rand() % 8;     // genero il numero di riga di colonna del secondo simbolo da scambiare
                              temp = matr_di_sost[ncr][ncc];
                              matr_di_sost[ncr][ncc] = matr_di_sost[ncr2][ncc2];
                              matr_di_sost[ncr2][ncc2] = temp;
                        }

                        printf("\n");
                        //visualizzazione matrice Casuale
                        printf("Matrice random ottenuta :\n");
                        stampa_matrice(matr_di_sost);
                        fflush(stdin);          //pulitura buffer
                        printf("Inserisci il messaggio da crittografare: \n");
                        gets(mex);        //immissione messaggio da tastiera
                        strupr(mex);      //conversione minuscolo maiuscolo
                        n = strlen(mex);  //lunghezza messaggio
                        elimina_spazi(mex, mex_senza_spazi, n);   //ekiminazione spazi
                        n = strlen(mex_senza_spazi);  //messaggio senza spazi
                        printf("Messaggio senza spazi: %s\n", mex_senza_spazi);
                        separa(mex_senza_spazi, mex_X, n);  //separazione coppie
                        n = strlen(mex_X);      //messaggio contentente X
// visualizzazione messaggio
                        printf("Messaggio ottenuto inserendo le X tra le coppie adiacenti uguali : \n%s\n",mex_X);
                        codif(mex_X, matr_di_sost, mex_cifr, n);   //codifica
                        printf("Messaggio codificato : %s\n", mex_cifr);
                        n = strlen(mex_cifr);      //messaggio cifrato
// decodifica con matrice
                        decod(mex_cifr, matr_di_sost, mex_dec, n);
                        n = strlen(mex_dec);
                        printf("Messaggio decodificato : %s\n", mex_dec);  //visualizzazione
                        cerca_x(mex_dec, n); // X aggiunte
                        elimina_spazi(mex_dec, mex_senza_spazi, n);  // eliminazione spazi
                        printf("MESSAGGIO iniziale %s\n", mex_senza_spazi);         //visualizzazione messaggio
                  }
                  break;
            default:
                  break;
            }
    } while(scelta < 1 || scelta > 3);
      system("PAUSE");
return EXIT_SUCCESS;
}

void cerca_x(char *mex, int n)
{
int i;
for(i = 0; i < n; i++)
	{
		if(mex[i] == 'X') mex[i] = ' ';// se  lettera è una X allora sostituisco con uno spazio
	}
}

// procedura di visualizzazione della matrice
void stampa_matrice(char matrice[][9])
{
int i, j;
for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 8; j++)
		{
			printf(" %c", matrice[i][j]);
			printf(",");
		}
    printf("\n");
	}
}

// Procedura di decodifica
void decod(char *mex, char matrice[][9], char *mex_dec, int l)
{
int i, ind_rig_sec_lettera = 0, ind_col_sec_lettera = 0, ind_r_prima_lettera = 0,
		ind_c_prima_lettera = 0, s = 0;
for(i = 0; i < l; i += 2)
	{
          // controllo dell'i-esimo carattere confrontato con *
		if(mex[i] == '*')
			mex_dec[s++] = '\0';
		else
		{
            // chiamata  procedure
			cerca_lettera(mex[i], matrice, &ind_r_prima_lettera, &ind_c_prima_lettera);
			cerca_lettera(mex[i + 1], matrice, &ind_rig_sec_lettera, &ind_col_sec_lettera);

			//indice di riga colonna per posizione delle lettere
        if(ind_r_prima_lettera == ind_rig_sec_lettera)//se indice righe coppia lettere sono uguali
			{
   //se indice di colonna delle lettere = 0 si sposta l'indice all'ultima colonna(9)
				if(ind_col_sec_lettera == 0)
					ind_col_sec_lettera = 8;
				else if(ind_c_prima_lettera == 0)
					ind_c_prima_lettera = 8;
    //la prima e la seconda lettera codificata saranno = all' elemento a sinistra
				mex_dec[s++] = matrice[ind_r_prima_lettera][ind_c_prima_lettera - 1];
                mex_dec[s++] = matrice[ind_r_prima_lettera][ind_col_sec_lettera - 1];
			}
			//altrimenti confronto gli indici di colonna, se sono uguali
			else if(ind_c_prima_lettera == ind_col_sec_lettera)
			{
    //se siamo nella prima riga allora l indice si sposta sulla 3 riga ,tale da rendere la matrice CIRCOLARE
				if(ind_rig_sec_lettera == 0)
					ind_rig_sec_lettera = 4;
				else if(ind_r_prima_lettera == 0)
					ind_r_prima_lettera = 4;
    // le due lettere decodificate sn = all'elemento superiore
                mex_dec[s++] = matrice[ind_r_prima_lettera - 1][ind_c_prima_lettera];
                mex_dec[s++] = matrice[ind_rig_sec_lettera - 1][ind_c_prima_lettera];
			}
			else
			{   //avranno diversi indici di riga e col --> la lettere decodificata avrà come riga la prima lettera e colonna della seconda
               // la seconda lettera avrà riga della seconda lettera e colonna della prima
				mex_dec[s++] = matrice[ind_r_prima_lettera][ind_col_sec_lettera];
                mex_dec[s++] = matrice[ind_rig_sec_lettera][ind_c_prima_lettera];
			}
		}
	}
}

// Procedura per l'eliminazione gli spazi nella stringa
void elimina_spazi(char *mex, char *temp, int n)
{
int i, k = 0;
for(i = 0; i < n; i++)
	{
          // nella tabella ASCII  65<=MAIUSCOLO<=90
		if(mex[i] >= 65 && mex[i] <= 90)
		{
			temp[k++] = mex[i];
        }
	}

}

// Procedura di ricerca di una lettera
void cerca_lettera(char lettera, char matrice[][9], int *indice_riga, int *indice_colonna)
{
int i, j;
for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(matrice[i][j] == lettera)
			{
				*indice_riga = i;
				*indice_colonna = j;
			}
		}
	}
}

// Procedura di separazione e inserimento della X
void separa(char *mex, char *stringa, int n)
{
int		 k = 0, i;
for(i = 0; i < n; i++)
	{
		if(mex[i] != mex[i + 1])
		{
			stringa[k++] = mex[i];
			stringa[k++] = mex[i + 1];
			i++;
		}
		else
		{
			stringa[k++] = mex[i];
			stringa[k++] = 'X';
		}
	}
}

// Codifica
void codif(char *mex, char matrice[][9], char *mex_cifr, int n)
{
int i, ind_rig_sec_lettera = 0, ind_col_sec_lettera = 0, ind_r_prima_lettera = 0,
    ind_c_prima_lettera = 0, s = 0;
for(i = 0; i < n; i += 2)
	{
          //costrutto che controlla se la lettera finale nel caso in cui sia dispari non venga confrontata con una posizione non disponibile(\0)
		if(mex[i + 1] == '\0')//se si verifica sostituisce al carattere i-esimo il simbolo *
			mex_cifr[s++] = '*';
		else
		{
            //altrimenti rientra in gioco  la procedura per ricercare le lettere all interno della matrice di sostituzione
			cerca_lettera(mex[i], matrice, &ind_r_prima_lettera, &ind_c_prima_lettera);
            cerca_lettera(mex[i + 1], matrice, &ind_rig_sec_lettera, &ind_col_sec_lettera);
        if(ind_r_prima_lettera == ind_rig_sec_lettera)
            // controllo se indice prima lettera è = indice della seconda lettera
			{
            //se è vero effettuo costrutto per creare la matrice circolare
				if(ind_col_sec_lettera == 7)
					ind_col_sec_lettera = -1;
				else if(ind_c_prima_lettera == 7)
					ind_c_prima_lettera = -1;
            //i-esima lettera del mex cifrato ora = al simbolo alla destra
                mex_cifr[s++] = matrice[ind_r_prima_lettera][ind_c_prima_lettera + 1];
                mex_cifr[s++] = matrice[ind_r_prima_lettera][ind_col_sec_lettera + 1];
			}
			else if(ind_c_prima_lettera == ind_col_sec_lettera)
            //se indici di colonna delle lettere analizzate sono uguali e se vero
			{
                 //se siamo sull'ultima riga,---> matrice circolare
				if(ind_rig_sec_lettera == 3)
					ind_rig_sec_lettera = -1;
				else if(ind_r_prima_lettera == 3)
					ind_r_prima_lettera = -1;
            //l's-esima lettera del messaggio cifrato sara uguale alla lettera in BASSO
                mex_cifr[s++] = matrice[ind_r_prima_lettera + 1][ind_c_prima_lettera];
                mex_cifr[s++] = matrice[ind_rig_sec_lettera + 1][ind_c_prima_lettera];
			}
			else
			{  //se i casi precedenti risultano negativi dignifica che gli indici di riga e colonna sono diversi e quindi
			   //l's-esimo carattere cifrato sara' uguale allo stesso indice di riga ma colonna dell altra lettera
				mex_cifr[s++] = matrice[ind_r_prima_lettera][ind_col_sec_lettera];
                mex_cifr[s++] = matrice[ind_rig_sec_lettera][ind_c_prima_lettera];
			}
		}
	}
}
