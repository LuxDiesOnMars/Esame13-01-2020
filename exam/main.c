#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int voti[5]={15,15,15,15,15};
    int nuoviVoti[5]={30,30,30,30,30};
    corso nuovoCorso={"ingegneria",789,NULL,NULL,NULL};
    inserisci_coda_lista("bho","nonso",1234,voti,&nuovoCorso);
    inserisci_coda_lista("bhoo","nonsoo",12345,voti,&nuovoCorso);
    inserisci_coda_lista("bho","nonso",123456,voti,&nuovoCorso);


    modifica_voti(1234,nuoviVoti,&nuovoCorso);

    //elimina_studente(1234,&nuovoCorso);

    //stampaLista(nuovoCorso.ln);
    nuovoCorso.lt=crea_unica_lista(&nuovoCorso.lp,&nuovoCorso.ln);
    //stampaLista(nuovoCorso.ln);
    //stampaLista(nuovoCorso.lp);
    stampaLista(nuovoCorso.lt);
    puts("------------------------");
    inverti_positivi(&nuovoCorso.lt);
    stampaLista(nuovoCorso.lt);



    return 0;
}
