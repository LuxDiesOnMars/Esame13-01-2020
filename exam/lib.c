#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inserisci_coda_lista(char *name,char *surname,int mat,int *grades,corso *cf)
{
    listaStudente paux;
    paux=(listaStudente)malloc(sizeof(nodoStudente));
    if(!paux)
    {
        printf("non abbastanza memoria");
        exit(1);
    }
    strcpy(paux->nome,name);
    strcpy(paux->cognome,surname);
    paux->matricola=mat;
    int sum=0;
    for(int i=0;i<5;i++)
    {
        paux->voti[i]=grades[i];
        sum+=grades[i];
    }
    float med;
    med=paux->media=(float)sum/5;
    if(med>=18)
    {
        listaStudente tmp=cf->lp;
        if(tmp==NULL)
        {
            cf->lp=paux;
            paux->next=NULL;
        }
        else
        {
            while(tmp->next!=NULL);
            tmp=tmp->next;
            tmp->next=paux;
            paux->next=NULL;
        }
    }
    else if(med<18)
    {
        listaStudente tmp=cf->ln;
        if(tmp==NULL)
        {
            cf->ln=paux;
            paux->next=NULL;
        }
        else
        {
            while(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }

            tmp->next=paux;
            paux->next=NULL;
        }
    }
}

void modifica_voti(int mat,int *grades,corso *cf)
{
    listaStudente tmp=cf->lp;
    listaStudente prec=NULL;
    int flag=0;
    while(tmp!=NULL)
    {
        if(tmp->matricola==mat)
        {
            flag=1;
            break;
        }
        prec=tmp;
        tmp=tmp->next;
    }
    if(flag==0)
    {
        tmp=cf->ln;
        prec=NULL;
        while(tmp!=NULL)
        {
            if(tmp->matricola==mat)
            {
                flag=1;
                break;
            }
            prec=tmp;
            tmp=tmp->next;
        }
    }
    if(flag==0)
    {
        printf("studente non presente in corso");
        return;
    }

    int sum=0;
    for(int i=0;i<5;i++)
    {
        tmp->voti[i]=grades[i];
        sum+=grades[i];
    }
    float nuovaMedia=(float)sum/5;
    float vecchiaMedia=tmp->media;
    if((nuovaMedia<18&&vecchiaMedia<18)||(nuovaMedia>=18 && vecchiaMedia>=18))
    {
        tmp->media=nuovaMedia;
        return;
    }
    if(vecchiaMedia<18 && nuovaMedia>=18)
    {
        tmp->media=nuovaMedia;
        if(prec==NULL)
        {
            cf->ln=cf->ln->next;
            listaStudente tmp2=cf->lp;
            if(tmp2==NULL)
            {
                cf->lp=tmp;
                tmp->next=NULL;
                return;
            }
            while(tmp2->next!=NULL)
            {
                tmp2=tmp2->next;
            }
            tmp2->next=tmp;
            tmp->next=NULL;
            return;
        }
        prec->next=tmp->next;
        listaStudente tmp2=cf->lp;
        if(tmp2==NULL)
        {
            cf->lp=tmp;
            tmp->next=NULL;
            return;
        }
        while(tmp2->next!=NULL)
        {
            tmp2=tmp2->next;
        }
        tmp2->next=tmp;
        tmp->next=NULL;
    }
    else if(vecchiaMedia>=18 && nuovaMedia<18)
    {
        tmp->media=nuovaMedia;
        if(prec==NULL)
        {
            cf->ln=cf->ln->next;
            listaStudente tmp2=cf->lp;
            if(tmp2==NULL)
            {
                cf->lp=tmp;
                tmp->next=NULL;
                return;
            }
            while(tmp2->next!=NULL)
            {
                tmp2=tmp2->next;
            }
            tmp2->next=tmp;
            tmp->next=NULL;
            return;
        }
        prec->next=tmp->next;
        listaStudente tmp2=cf->ln;
        if(tmp2==NULL)
        {
            cf->ln=tmp;
            tmp->next=NULL;
            return;
        }
        while(tmp2->next!=NULL)
        {
            tmp2=tmp2->next;
        }
        tmp2->next=tmp;
        tmp->next=NULL;
    }
}

void elimina_studente(int mat,corso *cf)
{
    listaStudente tmp=cf->lp;
    listaStudente prec=NULL;
    int flag=0;
    while(tmp!=NULL)
    {
        if(tmp->matricola==mat)
        {
            flag=1;
            if(prec==NULL)
            {
                cf->lp=cf->lp->next;
                free(tmp);
                return;
            }
            else
            {
                prec->next=tmp->next;
                free(tmp);
                return;
            }
        }
        prec=tmp;
        tmp=tmp->next;
    }
    if(flag==0)
    {
        tmp=cf->ln;
        prec=NULL;
        while(tmp!=NULL)
        {
            if(tmp->matricola==mat)
            {
                flag=1;
                if(prec==NULL)
                {
                    cf->lp=cf->lp->next;
                    free(tmp);
                    return;
                }
                else
                {
                    prec->next=tmp->next;
                    free(tmp);
                    return;
                }
            }
            prec=tmp;
            tmp=tmp->next;
        }
    }
    if(flag==0)
    {
        printf("matricola non presente\n");
        return;
    }

}

void inverti_positivi(listaStudente *lis)
{
    listaStudente tmp=*lis;
    listaStudente prec=NULL;
    listaStudente mom=NULL;
    while(tmp!=NULL)
    {
        mom=tmp;
        if(tmp->next==NULL)
        {
            *lis=tmp;
        }
        tmp=tmp->next;
        mom->next=prec;
        prec=mom;
    }
}

void stampaLista(listaStudente lis)
{
    if(lis==NULL)
    {
        printf("lista vuota\n");
        return;
    }
    while(lis!=NULL)
    {
        printf("%s %s %d ",lis->nome,lis->cognome,lis->matricola);
        printf("\nvoti:\n");
        for(int i=0;i<5;i++)
        {
            printf("%d\t",lis->voti[i]);
        }
        printf("\nmedia: %.2f\n\n",lis->media);
        lis=lis->next;
    }
}

listaStudente crea_unica_lista(listaStudente *lp,listaStudente *ln)
{
    listaStudente lt;
    listaStudente tmp=*lp;
    if(tmp==NULL)
    {
        tmp=*ln;
        if(tmp==NULL)
        {
            lt=NULL;
            return lt;
        }
        else
        {
            lt=*ln;
            *ln=NULL;
            return lt;
        }

    }
    if(*ln==NULL)
    {
        lt=*lp;
        *lp=NULL;
        return lt;
    }
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=*ln;
    lt=*lp;
    *lp=*ln=NULL;
    return lt;

}
