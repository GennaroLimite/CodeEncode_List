// Limite Gennaro matricola n° 0124000891

//Elenco telefonico
//Consideriamo un elenco telefonico composto da 30 utenti. Ogni utente è identificato
//da un cognome, nome, domicilio e numero telefonico.
//Si supponga che gli utenti inizialmente sono presenti in ordine casuale.
//Permettere al programma di
//• Ordinare l’elenco in base al cognome (usare un algoritmo di ordinamento per
//inserimento).
//• Dato un cognome, un nome, visualizzare il numero corrispondente.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct domicilio {          //dichiaro la struct domicilio che mi serve per la dichiarazione
    char toponimo[40];      //della struct elenco_telefonico
    int n_civico;
};
struct elenco_telefonico {  //dichiaro la struct elenco_telefonico
    char cognome[40];
    char nome[40];
    int n_telefonico;
    struct domicilio sede;
};
typedef struct elenco_telefonico Elenco[30];
typedef struct elenco_telefonico elenco_telefonico;

void ord_ins (Elenco mio_elenco,int);   //prototipo della procedura per l'ordinamento per inserimento;
void visualizza (Elenco mio_elenco,int);//prototipo della procedura per la visualizzazione dell'elenco;
int ricerca_numero (Elenco mio_elenco); //prototipo della function per la ricerca del numero di telefono
                                        //dato un cognome e un nome;

//dichiariamo la struct per quanto riguarda l'elenco telefonico dei 30 utenti

//      MAIN
int main()
{
    int n=30,num_tel,scelta;
//riempio la struct
Elenco mio_elenco = {{"Teo","Roberta",392295773,"via fuori porta san gennaro",29},
                    {"Limite","Gennaro",334239405,"via bologna",33},
                    {"Albrizio","Salvatore",389765890,"via ponti rossi",31},
                    {"Vitale","Giovanni",336985032,"via roma",2},
                    {"Campolongo","Leopoldo",336541209,"via duomo",9},
                    {"Barbieri","Vincenzo",392489632,"via foria",229},
                    {"Di Carlucio","Giuseppe",397896321,"via giovanni de matha",119},
                    {"Marino","Carmela",398965452,"via torino",317},
                    {"Brillante","Ivan",389632556,"via benedetto cairoli",245},
                    {"Terracciano","Maria",391896556,"via genova",11},
                    {"Cerbone","Sabatino",397896324,"via ponte di casanove",1},
                    {"Nacaroma","Davide",369874563,"via nicola nicolini",33},
                    {"Mendozzi","Teresa",389632256,"via nicola rocco",49},
                    {"Franzese","Gaetano",334698745,"via arenaccia",57},
                    {"Santomartino","Anna",334236987,"via filippo maria briganti",79},
                    {"Franzese","Giuseppe",334698563,"via nazionale",48},
                    {"Morgese","Roberto",395233654,"via bari",57},
                    {"Costanzo","Alfredo",392987452,"via ferrara",13},
                    {"Russo","Carmine",392456987,"corso secondigliano",1},
                    {"Ponti","Giovanni",393698745,"via tutti i santi",19},
                    {"Cano'","Emanuele",334987456,"via benedetto cairoli",55},
                    {"Borrelli","Alessandro",336987456,"corso garibaldi",249},
                    {"Di Palma","Giuseppe",334698745,"corso meridionale",100},
                    {"Cirillo","Domenica",399874623,"piazza carlo III",14},
                    {"Loffredo","Jessica",334005987,"via pisa",69},
                    {"Caccavale","Nicola",334698765,"via calata capodichino",29},
                    {"Rea","Giuseppe",336987462,"piazza ottocalli",87},
                    {"Ruggiero","Salvatore",393698745,"via firenze",82},
                    {"Zingarini","Marco",394698745,"via milano",77},
                    {"Sorgente","Giovanni",365479851,"via torino",9}};
do
{
printf("Programma riguardante un Elenco Telefonico\n");
printf("Scegli Operazione : \n");
printf("1)Stampa dell'elenco non ordinato \n");
printf("2)Stampa dell'elenco ordinato \n");
printf("3)Ricerca di un numero telefonico\n");
printf("4)Uscita\n");
printf("scelta = ");
scanf("%1d", &scelta);
switch (scelta)
{
case 1:
    {
          printf("\nElenco non oridnato\n\n");
        visualizza(mio_elenco,n);
    }
    break;
case 2:
    {
          ord_ins(mio_elenco,n);
            printf("\nElenco oridnato\n\n");
            visualizza(mio_elenco,n);
    }
    break;
case 3:
    {
            num_tel=ricerca_numero (mio_elenco);
    printf("numero di telefono=%d\n",num_tel);
    }
    break;
default:
    break;
}
    } while(scelta < 1 || scelta > 4);
      system("PAUSE");
return EXIT_SUCCESS;
}

// PROCEDURA PER LA VISUALIZZAZIONE
void visualizza(Elenco mio_elenco,int n)
{
int i;
    for (i=0;i<n;i++)
    {
        printf("%s %s\n", mio_elenco[i].cognome,mio_elenco[i].nome);
    }
}

//PROCEDURA PER L'ORDINAMENTO PER INSERIMENTO
void ord_ins (Elenco mio_elenco,int n)
{
    elenco_telefonico temp;
    int i,j;
    for(i=1; i<n; i++)
    {
        temp=mio_elenco[i];
        j=i-1;
        while (j>=0 && (strcmp(temp.cognome,mio_elenco[j].cognome)<0))
        {
            mio_elenco[j+1]=mio_elenco[j];
            j--;
        }
        mio_elenco[j+1]=temp;
    }
}

//FUNTION PER LA RICERCA DI UN NUMERO DI TELEFONO DATO UN COGNOME E UN NOME
int ricerca_numero (Elenco mio_elenco)
{
int i=0,num_tel,trovato = 0,numero_elementi=30;
elenco_telefonico temp[100];
printf("\ninserire cognome dell'utente da cercare\n");
scanf("%s", temp[1].cognome);
printf("\ninserire nome dell'utente da cercare\n");
scanf("%s",temp[1].nome);
while(i < numero_elementi && trovato == 0)
{
if(strcmp(temp[1].cognome,mio_elenco[i].cognome)==0)
    {
        trovato = 1;
        num_tel= mio_elenco[i].n_telefonico;
    }
        else
        i++;
}
return num_tel;
}
