#include <process.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <alloc.h>
#include <bios.h>
#include <dos.h>
#include <dir.h>
#include <io.h>

#define TRUE       1
#define FALSE      0

#define ROT_BACKUP 0
#define ROT_WINCH  1

unsigned char *ptarq,dirCorrente[128],volumeCorrente[14];
unsigned funcao,discoCorrente,equipamento;
unsigned long end,indice;

struct FBLOCK { struct FBLOCK *prox;
              unsigned long tamanho;
              unsigned char nome[14],*ptc; } *ptf;
struct PAGINA { struct PAGINA *dprox,*eprox;
              long info; } *pag;

/* ---------------------------------------------------------------------------
    0 - apaga
    1 - razao social
    2 - pergunta
    3 - mensagens
    4 - texto
    5 - linha de selecao
    6 - tecla de selecao
    7 - erro moldura
    8 - erro texto
--------------------------------------------------------------------------- */
unsigned cor[] = { 0x07, 0x1f, 0x3f, 0x0f, 0x0e, 0x1e, 0x1b, 0x4f, 0xcf };





/* ---------------------------------------------------------------------------
LECAR        : esvazia o buffer de teclado e espera uma tecla ser apertada
                    AH - scan code         AL - caracter

CURSOR       : tipo de cursor         >> 1,linha inicial,linha final
               posicao do cursor      >> 2,x,y
               le atributos do cursor >> 3
                    CH - linha inicial     CL - linha final
                    DH - linha             DL - coluna

CLS          : modo texto 80x25 colorido

IMPCAR       : imprime caracter na posicao do cursor
                    >> num. de caracteres,caracter,atributo

REVERSO      : muda atributos dos caracteres de uma linha
                    >> x,y,comp,atrib

WRITE        : imprime string na posicao do cursor
                    >> str

PAGINA_PRINT : imprime o vetor str na tela com o atributo de cor dado
                    >> str,atrib
--------------------------------------------------------------------------- */





/* ---------------------------------------------------------------------------
INICIA  : altera vetor de interrupcao 24 - passa a dar "Fail on system call"
          para toda chamada a esta interrupcao

ACABA   : restaura vetor de interrupcao 24

RESET   : libera todos os buffers pendentes do DOS, atraves da funcao 0DH

ABRE    : abre para leitura o arquivo pedido, e devolve pointer
               >> str

CRIA    : cria para escrita o arquivo pedido, e devolve pointer
               >> str

LEIA    : le o arquivo dado armazenando os caracteres no buffer
               >> arq,buffer,num. de caracteres

ESCREVA : escreve no arquivo dado os caracteres do buffer
               >> arq,buffer,num. de caracteres

FECHA   : fecha o arquivo dado
               >> arq
--------------------------------------------------------------------------- */





MOLDURA (x,y,comp,alt,atrib)
int x,y,comp,alt,atrib;
{ int i,j;

CURSOR (2,x,y);
IMPCAR (1,218,atrib);
CURSOR (2,x+1,y);
IMPCAR (comp-1,196,atrib);
CURSOR (2,x+comp,y);
IMPCAR (1,191,atrib);

for (i=y+1;i<y+alt;i++)
  { CURSOR (2,x,i);
  IMPCAR (1,179,atrib);
  CURSOR (2,x+1,i);
  IMPCAR (comp-1,' ',atrib);
  CURSOR (2,x+comp,i);
  IMPCAR (1,179,atrib); }

CURSOR (2,x,y+alt);
IMPCAR (1,192,atrib);
CURSOR (2,x+1,y+alt);
IMPCAR (comp-1,196,atrib);
CURSOR (2,x+comp,y+alt);
IMPCAR (1,217,atrib);

return (0); }





APAGA (y,comp)
int y,comp;
{ unsigned i,x;

x = (76 - comp) / 2;
for (i=y;i<=y+2;i++)
  { CURSOR (2,x,i);
  IMPCAR (comp+4,' ',cor[0]); }
CURSOR (2,0,25);

return (0); }





QUADRO (y,str,cor1,cor2)
int y;
unsigned char *str;
unsigned cor1,cor2;
{ int x,t;

t = strlen (str);
x = (76 - t) / 2;
MOLDURA (x,y++,t+3,2,cor1);
x += 2;
CURSOR (2,x,y);
WRITE (str);
REVERSO (x,y,t,cor2);

return (0); }





ERRO (y,str)
int y;
unsigned char *str;
{ putchar ('\07');
QUADRO (y,str,cor[7],cor[8]);

return (0); }





ESPERA (y)
int y;
{ CURSOR (2,25,y);
WRITE ("Tecle algo para continuar ....");
REVERSO (25,y,30,cor[3]);
LECAR ();
CURSOR (2,25,y);
IMPCAR (30,' ',cor[0]);

return (0); }





PERGUNTA (y,str1,str2,comp)
int y,comp;
unsigned char *str1,*str2;
{ int x,t,i,c;

t = strlen (str1);
x = (76 - t - comp) / 2;
MOLDURA (x,y++,t+comp+3,2,cor[2]);
x += 2;
CURSOR (2,x,y);
WRITE (str1);
CURSOR (1,0,7);
if (comp!=1)
       { str2[0] = comp;
       cgets (str2); }
  else { LECAR ();
       * ((unsigned *) str2) = _AX;
       if (isprint(str2[0]))
              IMPCAR (1,str2[0],cor[2]); }
CURSOR (1,6,7);
CURSOR (2,0,25);

return (0); }





MSG_ABANDONO (y)
int y;
{ CURSOR (2,23,y);
WRITE ("Tecle <ESC> para abandonar funcao.");
REVERSO (23,y,34,cor[3]);

return (0); }





APAGA_MSG_ABANDONO (y)
int y;
{ CURSOR (2,0,y);
IMPCAR (80,' ',cor[0]);

return (0); }





RAZAO_SOCIAL (x,y)
int x,y;
{ MOLDURA (x,y,39,3,cor[1]);
CURSOR (2,x+2,y+1);
WRITE ("INOVA TECNOLOGIA E INFORMATICA LTDA.");
CURSOR (2,x+13,y+2);
WRITE ("Copyright 1988");

return (0); }





TELA_0 (x,y)
int x,y;
{ funcao = 0;
MOLDURA (x,y,30,7,cor[2]);
CURSOR (2,x+2,y+1);
WRITE ("F1 - Ler manual ON-LINE");
CURSOR (2,x+2,y+2);
WRITE ("F2 - Criar backup, drive B:");
CURSOR (2,x+2,y+3);
WRITE ("F3 - Instalar em Winchester");
CURSOR (2,x+2,y+4);
WRITE ("F4 - Gerar nova versao");
CURSOR (2,x+2,y+5);
WRITE ("F7 - Dos = Command.com");
CURSOR (2,x+2,y+6);
WRITE ("F9 - Exit Install");
REVERSO (x+1,y+1,29,cor[3]);

return (0); }





LE_PAGINA (pg)
struct PAGINA *pg;
{ int i,j,k;
unsigned char str[1922],*pc;

pc = str;
indice = pg->info;
for (i=0;i<24;i++)
  { for (j=0;indice<end && ptarq[indice]!=0x0a;indice++)
      switch (ptarq[indice])
        { case 0x0d:
        case 0x1a:
            break;
        case 0x09:
            for (k=0;k<8;*pc++=' ');
            j += 8;
            break;
        default:
            *pc++ = ptarq[indice];
            j++;
            break; }
  for (indice++;j<80;j++,*pc++=' '); }
PAGINA_PRINT (str,cor[4]);

return (0); }





MANUAL_ON_LINE ()
{ unsigned i,j,arq;
unsigned char *pc;
struct PAGINA *pg;

CLS ();
if ((arq=ABRE ("LEIA_ME"))<=0)
       { ERRO (15,"Arquivo LEIA_ME nao encontrado.");
       ESPERA (19);
       return (1); }
end = filelength(arq);
if (!end || end==-1l)
       { ERRO (15,"Erro no tamanho do arquivo LEIA_ME.");
       ESPERA (19);
       FECHA (arq);
       return (1); }
if (!(ptarq=farcalloc(end,(long) sizeof (unsigned char))))
       { ERRO (15,"Erro na alocacao de memoria.");
       ESPERA (19);
       FECHA (arq);
       exit (2); }
for (i=0,pc=ptarq;(j=LEIA(arq,pc,512))>0;i++,pc+=512);
if (!i || j<0)
       { ERRO (15,"Erro na leitura do arquivo LEIA_ME.");
       ESPERA (19);
       FECHA (arq);
       return (1); }
FECHA (arq);

if (!(pag=farcalloc(1l,(long) sizeof (struct PAGINA))))
       { ERRO (15,"Erro na alocacao de memoria.");
       ACABA ();
       exit (2); }
pg = pag->eprox = pag->dprox = pag;
pag->info = 0l;

CURSOR (2,0,24);
WRITE ("PG UP-pg.anterior   PG DN-pg.seguinte   HOME-primeira pg.   <ESC>-menu anterior");
REVERSO (0,24,80,cor[5]);
REVERSO (0,24,5,cor[6]);
REVERSO (20,24,5,cor[6]);
REVERSO (40,24,4,cor[6]);
REVERSO (60,24,5,cor[6]);

LE_PAGINA (pg);
if (!(pg=farcalloc(1l,(long) sizeof (struct PAGINA))))
       { CLS ();
       ERRO (15,"Erro na alocacao de memoria.");
       ACABA ();
       exit (2); }
pg->info = indice;
pag->eprox = pag->dprox = pg;
pg->eprox = pg->dprox = pag;
pag = pg;
pg = pg->eprox;

while (TRUE)
  { LECAR ();
  i = _AH;
  if (i==1)
         break;
  switch (i)
    { case 71:  /* HOME */
        if (!pg->info)
               break;
        pg = pag->dprox;
        LE_PAGINA (pg);
        break;
    case 73:   /* PG UP */
        if (pg->eprox==pag)
               break;
        pg = pg->eprox;
        LE_PAGINA (pg);
        break;
    case 81:   /* PG DN */
        if (pg->dprox->info>=end)
               break;
        pg = pg->dprox;
        LE_PAGINA (pg);
        if (pg->dprox->info!=indice)
               { if (!(pg=farcalloc(1l,(long) sizeof (struct PAGINA))))
                        { CLS ();
                        ERRO (15,"Erro na alocacao de memoria.");
                        ACABA ();
                        exit (2); }
               pg->info = indice;
               pg->dprox = pag->dprox;
               pg->eprox = pag;
               pag = pag->dprox = pag->dprox->eprox = pg;
               pg = pg->eprox; }
        break; } }

pg = pag->dprox;
pag->dprox = NULL;
do
  { pag = pg;
  pg = pg->dprox;
  farfree (pag); }
  while (pg);
pag = NULL;

farfree (ptarq);
ptarq = NULL;

return (0); }





PEDE_DISCO (string1,linha,disco,string2)
unsigned char string1[],string2[];
unsigned linha,disco;
{ unsigned i;
unsigned char str[2],buffer[512];

do
  { biosdisk (0,0,0,0,0,0,NULL);
  PERGUNTA (linha,string2,str,1);
  APAGA (15,76);
  if (str[1]==1)
         return (5);
  if (i=biosdisk(2,disco,0,0,6,1,buffer))
         { biosdisk (0,0,0,0,0,0,NULL);
         if (i=biosdisk(2,disco,0,0,6,1,buffer))
                { biosdisk (0,0,0,0,0,0,NULL);
                if (i=biosdisk(2,disco,0,0,6,1,buffer))
                       ERRO (15,string1); } } }
  while (i);

return (0); }





LIBERA ()
{ struct FBLOCK *pta;

if (ptf)
       { pta = ptf->prox;
       ptf->prox = NULL;
       do
         { ptf = pta;
         pta = pta->prox;
         farfree (ptf->ptc);
         farfree (ptf); }
         while (pta);
       ptf = NULL; }

return (0); }





LIBERA2 (pta)
struct FBLOCK *pta;
{ farfree (ptf->ptc);
farfree (ptf);
while (pta)
  { ptf = pta;
  pta = pta->prox;
  farfree (ptf->ptc);
  farfree (ptf); }
  while (pta);
ptf = NULL;

return (0); }





LEITURA (pta,pc,fblk)
struct FBLOCK *pta;
unsigned char *pc;
struct ffblk *fblk;
{ int arq,i,j;
unsigned char string[80];

sprintf (string,"Lendo arquivo %s",fblk->ff_name);
QUADRO (9,string,cor[2],cor[2]);
if (!ptf)
       pta->prox = ptf = pta;
  else { pta->prox = ptf->prox;
       ptf = ptf->prox = pta; }
pta->ptc = pc;
pta->tamanho = fblk->ff_fsize;
strcpy (pta->nome,fblk->ff_name);

if ((arq=ABRE (pta->nome))<=0)
       { APAGA_MSG_ABANDONO (13);
       ERRO (15,"Erro ao abrir arquivo para leitura.");
       ESPERA (19);
       return (1); }
for (i=0;(j=LEIA(arq,pc,512))>0;pc+=512,i++);
if (!i || j<0)
       { APAGA_MSG_ABANDONO (13);
       ERRO (15,"Erro na leitura de arquivo.");
       ESPERA (19);
       return (1); }
if (FECHA (arq))
       { APAGA_MSG_ABANDONO (13);
       ERRO (15,"Erro ao fechar arquivo lido.");
       ESPERA (19);
       return (1); }

APAGA (9,76);

return (0); }





RETORNO ()
{ struct ffblk flabel;

CLS ();
setdisk (discoCorrente);
if (discoCorrente<2)
       while (TRUE)
         { while (PEDE_DISCO("Erro ao acessar Drive CORRENTE.",5,discoCorrente,
                          "Coloque Disco CORRENTE e aperte <RETURN> ... ")==5);
         if (findfirst ("\\*.*",&flabel,FA_LABEL))
                strcpy (flabel.ff_name,"sem nome");
         if (!stricmp(flabel.ff_name,volumeCorrente))
                break;
         ERRO (15,"Nao e Disco CORRENTE."); }

CLS ();
if (chdir (dirCorrente))
       { ERRO (15,"Erro ao acessar Diretorio CORRENTE.");
       ACABA ();
       exit (6); }

return (0); }





ACESSA (string1,string2,string3,linha,disco,volume)
unsigned char *string1,*string2,*string3,*volume;
unsigned linha,disco;
{ unsigned char vol[14];
struct ffblk flabel;

setdisk (disco);
MSG_ABANDONO (13);
while (TRUE)
  { if (PEDE_DISCO(string2,linha,disco,string1)==5)
           { LIBERA ();
           RETORNO ();
           return (5); }
  if (findfirst ("\\*.*",&flabel,FA_LABEL))
         strcpy (vol,"sem nome");
    else strcpy (vol,flabel.ff_name);
  if (!stricmp(vol,volume))
         break;
  ERRO (15,string3); }
APAGA_MSG_ABANDONO (13);

return (0); }





ABANDONA (string,pta)
unsigned char *string;
struct FBLOCK *pta;
{ RESET ();
biosdisk (0,0,0,0,0,0,NULL);
APAGA_MSG_ABANDONO (13);
ERRO (15,string);
ESPERA (19);
LIBERA2 (pta);
RETORNO ();

return (0); }





COPIA (rotina,disco,str1,str2)
unsigned rotina,disco;
unsigned char *str1,*str2;
{ int c,i,arq;
unsigned char *pc,string[80];
struct ffblk fblk;
struct FBLOCK *pta;

i = TRUE;
while (TRUE)
  { if (rotina)
          { setdisk (discoCorrente);
          if (chdir(dirCorrente))
                 { CLS ();
                 ERRO (15,"Erro ao acessar diretorio corrente.");
                 ACABA ();
                 exit (6); } }
     else { APAGA (5,76);
          if ( ACESSA(
            "Coloque Disco ORIGINAL no drive A: e aperte qualquer tecla ... ",
            "Erro ao acessar drive A:","Nao e Disco ORIGINAL.",1,0,str1)==5 )
                 return (5); }

  if (!i)
         { if ( !(pta=farcalloc (1l,(long) sizeof (struct FBLOCK))) ||
                !(pc=farcalloc(fblk.ff_fsize,(long) sizeof (unsigned char))) )
                  { CLS ();
                  ERRO (15,"Erro na alocacao de memoria.");
                  ACABA ();
                  exit (2); }
         if (LEITURA (pta,pc,&fblk))
                { LIBERA ();
                RETORNO ();
                return (1); } }
  while (TRUE)
    { if (!ptf)
             i = findfirst ("*.*",&fblk,FA_ARCH);
        else i = findnext (&fblk);
    if (i || !(pta=farcalloc (1l,(long) sizeof (struct FBLOCK))))
           break;
    if (!(pc=farcalloc (fblk.ff_fsize,(long) sizeof (unsigned char))))
           { farfree (pta);
           break; }
    if (LEITURA (pta,pc,&fblk))
           { LIBERA ();
           RETORNO ();
           return (1); } }

  if (rotina)
         { setdisk (disco);
         if (chdir(str1))
                { CLS ();
                ERRO (15,"Erro ao acessar subdiretorio dado.");
                ACABA ();
                exit (6); } }
    else if (ACESSA (
             "Coloque Disco BACKUP no drive B: e aperte qualquer tecla ... ",
             "Erro ao acessar drive B:","Nao e Disco BACKUP.",
             5,disco,str2)==5)
                return (5);

  if (ptf)
         { pta = ptf->prox;
         ptf->prox = NULL;
         do
           { ptf = pta;
           pta = pta->prox;
           sprintf (string,"Gravando arquivo %s",ptf->nome);
           QUADRO (9,string,cor[2],cor[2]);
           if ((arq=CRIA (ptf->nome))<=0)
                  { ABANDONA ("Erro ao abrir arquivo para escrita.",pta);
                  return (1); }
           for (pc=ptf->ptc;ptf->tamanho;pc+=512)
             { c = (ptf->tamanho<512) ? ptf->tamanho : 512;
             if (ESCREVA (arq,pc,c)!=c)
                      { FECHA (arq);
                      ABANDONA ("Erro de escrita em arquivo.",pta);
                      return (1); }
             ptf->tamanho -= c; }
           if (FECHA (arq))
                  { ABANDONA ("Erro ao fechar arquivo gravado.",pta);
                  return (1); }
           farfree (ptf->ptc);
           farfree (ptf);
           APAGA (9,76); }
           while (pta);
         ptf = NULL; }
  if (i)
         break; }

RETORNO ();

return (0); }






BACKUP ()
{ unsigned discoBackup,tamanhoA,tamanhoB;
unsigned char volumeA[14],volumeB[14];
struct dfree dlivre;
struct ffblk flabel;

CLS ();
RAZAO_SOCIAL (20,21);
MSG_ABANDONO (13);

setdisk (0);
if (PEDE_DISCO ("Erro ao acessar drive A:",1,0,
        "Coloque Disco ORIGINAL no drive A: e aperte qualquer tecla ... ")==5)
       { RETORNO ();
       return (5); }
if (chdir ("\\"))
       { ERRO (15,"Erro no diretorio raiz.");
       ESPERA (19);
       RETORNO ();
       return (5); }
if (findfirst ("*.*",&flabel,FA_LABEL))
       strcpy (volumeA,"sem nome");
  else strcpy (volumeA,flabel.ff_name);
tamanhoA = 0;
if (findfirst ("*.*",&flabel,FA_ARCH))
       do
         tamanhoA += (flabel.ff_fsize + 511) / 512;
         while (!findnext(&flabel));

discoBackup = (equipamento) ? 1 : 0;
setdisk (discoBackup);
if (PEDE_DISCO ("Erro ao acessar drive B:",5,discoBackup,
          "Coloque Disco BACKUP no drive B: e aperte qualquer tecla ... ")==5)
       { RETORNO ();
       return (5); }
if (chdir ("\\"))
       { ERRO (15,"Erro no diretorio raiz.");
       ESPERA (19);
       RETORNO ();
       return (5); }
getdfree (discoBackup+1,&dlivre);
tamanhoB = dlivre.df_avail * dlivre.df_sclus;
if (tamanhoB<tamanhoA)
       { APAGA_MSG_ABANDONO (13);
       ERRO (15,"Espaco insuficiente no Disco BACKUP.");
       ESPERA (19);
       RETORNO ();
       return (5); }
if (findfirst ("*.*",&flabel,FA_LABEL))
       { APAGA_MSG_ABANDONO (13);
       PERGUNTA (9,"Label do Disco BACKUP: ",volumeB,12);
       if (!volumeB[1])
              strcpy (volumeB,"sem nome");
         else { strcpy (volumeB,volumeB+2);
              if (_creat(volumeB,FA_LABEL)==EOF)
                     { ERRO (15,"Erro ao acessar drive B:");
                     ESPERA (19);
                     RETORNO ();
                     return (5); } }
       APAGA (9,35); }
  else strcpy (volumeB,flabel.ff_name);

return (COPIA (ROT_BACKUP,discoBackup,volumeA,volumeB)); }





INSTALL ()
{ unsigned char *pc,*pd,str[2],drive[4],dir[68],path[76];
unsigned c,i,disco,tamanhoA,tamanhoB;
struct dfree dlivre;
struct ffblk fblk;

CLS ();
RAZAO_SOCIAL (20,21);

tamanhoA = 0;
if (findfirst ("*.*",&fblk,FA_ARCH))
       do
         tamanhoA += (fblk.ff_fsize + 511) / 512;
         while (!findnext(&fblk));

MSG_ABANDONO (13);
do
  { biosdisk (0,0,0,0,0,0,NULL);
  PERGUNTA (1,"Drive para instalar o programa: ",str,1);
  APAGA (15,35);
  if (str[1]==1)
         { RETORNO ();
         return (5); }
  if (!isalpha(*str))
         { ERRO (15,"Drive invalido.");
         *str = '\0'; }
    else { disco = toupper(*str) - 'A';
         if (disco==1 && !equipamento)
                disco = 0;
         setdisk (disco);
         if (getdisk()!=disco)
                { ERRO (15,"Drive invalido.");
                *str = '\0'; }
           else if (chdir ("\\"))
                       { ERRO (15,"Erro ao acessar drive especificado.");
                       *str = '\0'; } } }
  while (!*str);
APAGA_MSG_ABANDONO (13);

i = TRUE;
do
  { PERGUNTA (5,"Diretorio: ",path,60);
  APAGA (15,76);
  if (!path[1])
         { dir[0] = '\\';
         dir[1] = '\0';
         break; }
  if (path[path[1]+1]!='\\')
         { path[path[1]+2] = '\\';
         path[path[1]+3] = '\0'; }
  fnsplit (path+2,drive,dir+1,NULL,NULL);
  if (dir[2]=='\0' && dir[1]=='\\')
         break;
  pd = (dir[1]=='\\') ? dir + 1 : dir;
  for (pc=pd++;*pd;pc=pd++)
    { /* if (*pd=='\\' || *pd=='.')
             { ERRO (15,"String invalida de diretorio.");
             break; } */
    *pc++ = '\\';
    while (*++pd!='\\');
    *pd = '\0';
    if (chdir(pc))
           if (mkdir(pc))
                  { sprintf (path,"Erro ao criar %s.",dir+1);
                  ERRO (15,path);
                  break; }
             else chdir (pc); }
  if (!*pc)
         i = FALSE; }
  while (i);

getdfree (disco+1,&dlivre);
tamanhoB = dlivre.df_avail * dlivre.df_sclus;
if (tamanhoB<tamanhoA)
       { APAGA_MSG_ABANDONO (13);
       ERRO (15,"Espaco insuficiente no disco.");
       ESPERA (19);
       RETORNO ();
       return (5); }

pc = (dir[1]=='\\') ? dir + 1 : dir;
return (COPIA (ROT_WINCH,disco,pc,NULL)); }





NOVO_ARQUIVO ()
{ unsigned i,j;
int fbase,fcompac,fsaida;
unsigned long indBase,tamArqBase;
unsigned char huge *arqBase,*ptc,str[128],arq1[52],arq2[52],arq3[52];
unsigned char volume[16];
struct ffblk ff;

CLS ();
RAZAO_SOCIAL (20,21);

PERGUNTA (1,"Arquivo Base: ",arq1,50);
if ((fbase=ABRE (arq1+2))<=0)
       { sprintf (str,"Arquivo %s nao encontrado.",arq1+2);
       ERRO (15,str);
       ESPERA (19);
       return (1); }

PERGUNTA (5,"Arquivo de Diferencas: ",arq2,50);
if ((fcompac=ABRE (arq2+2))<=0)
       { sprintf (str,"Arquivo %s nao encontrado.",arq2+2);
       ERRO (15,str);
       ESPERA (19);
       FECHA (fbase);
       return (1); }
if (arq2[3]==':')
       { strcpy (volume,"  \\*.*");
       volume[0] = arq2[2];
       volume[1] = arq1[3]; }
  else strcpy (volume,"\\*.*");
if (!findfirst(volume,&ff,FA_LABEL))
       strcpy (volume,ff.ff_name);
  else strcpy (volume,"sem nome");
if (!stricmp(volume,"INOVA"))
       { putchar ('\07');
       PERGUNTA (9,"Deseja modificar versao original? (s/n): ",str,1);
       if (str[0]!='s' && str[0]!='S')
              { FECHA (fbase);
              FECHA (fcompac);
              return (4); }
       APAGA (9,76); }

tamArqBase = filelength (fbase);
if (!(arqBase=farcalloc(tamArqBase,(long) sizeof (char))))
       { CLS ();
       ERRO (15,"Erro na alocacao de memoria.");
       FECHA (fbase);
       FECHA (fcompac);
       ACABA ();
       exit (2); }
for (ptc=arqBase,i=0;(j=LEIA(fbase,ptc,512))>0;i++,ptc+=512);
if (!i || j>=0x8000)
       { ERRO (15,"Erro na leitura de arquivo.");
       ESPERA (19);
       FECHA (fbase);
       FECHA (fcompac);
       farfree (arqBase);
       return (1); }
FECHA (fbase);

indBase = 0l;
if (LEIA (fcompac,&indBase,3)!=3 || LEIA (fcompac,&i,2)!=2)
       { ERRO (15,"Erro na leitura de arquivo.");
       ESPERA (19);
       FECHA (fcompac);
       farfree (arqBase);
       return (1); }
for (j=0;i--;)
  { if (LEIA (fcompac,&j,1)!=1)
           { ERRO (15,"Erro na leitura de arquivo.");
           ESPERA (19);
           FECHA (fcompac);
           farfree (arqBase);
           return (1); }
  if (arqBase[indBase++]!=j)
         { ERRO (15,"String de identificacao nao foi encontrada.");
         ESPERA (19);
         FECHA (fcompac);
         farfree (arqBase);
         return (3); } }

strcpy (arq3+2,arq2+2);
for (i=2;arq3[i++];);
for (;arq3[--i]!='.';);
strcpy (arq3+i,".$$$");
arq3[0] = i;
if ((fsaida=CRIA (arq3+2))<=0)
       { sprintf (str,"Arq. de saida %s invalido.",arq3+2);
       ERRO (15,str);
       ESPERA (19);
       FECHA (fcompac);
       farfree (arqBase);
       return (1); }

while (TRUE)
  { if (!(j=LEIA (fcompac,&i,2)))
           break;
  if (j!=2)
         { ERRO (15,"Fim inesperado de arquivo.");
         ESPERA (19);
         FECHA (fcompac);
         FECHA (fsaida);
         unlink (arq3+2);
         farfree (arqBase);
         return (1); }
  if (i & 1)
         { i >>= 1;
         if (!i)
                i = 0x8000;
         indBase = 0l;
         if (LEIA(fcompac,&indBase,3)!=3)
                { ERRO (15,"Fim inesperado de arquivo.");
                ESPERA (19);
                FECHA (fcompac);
                FECHA (fsaida);
                unlink (arq3+2);
                farfree (arqBase);
                return (1); }
         if (ESCREVA (fsaida,arqBase+indBase,i)!=i)
                { ERRO (15,"Erro de escrita em arquivo.");
                ESPERA (19);
                FECHA (fcompac);
                FECHA (fsaida);
                unlink (arq3+2);
                farfree (arqBase);
                return (1); } }
    else { i >>= 1;
         if (!i)
                i = 0x8000;
         for (j=0;i--;)
           { if (LEIA (fcompac,&j,1)!=1)
                    { ERRO (15,"Fim inesperado de arquivo.");
                    ESPERA (19);
                    FECHA (fcompac);
                    FECHA (fsaida);
                    unlink (arq3+2);
                    farfree (arqBase);
                    return (1); }
           if (ESCREVA (fsaida,&j,1)!=1)
                { ERRO (15,"Erro de escrita em arquivo.");
                ESPERA (19);
                FECHA (fcompac);
                FECHA (fsaida);
                unlink (arq3+2);
                farfree (arqBase);
                return (1); } } } }

FECHA (fcompac);
FECHA (fsaida);
strcpy (arq2+arq3[0],".exe");
unlink (arq2+2);
rename (arq3+2,arq2+2);
farfree (arqBase);

return (0); }





COMANDO ()
{ CLS ();
ACABA ();
CURSOR (2,0,0);
WRITE ("Digite EXIT para retornar ao programa ...");
if (system (getenv("COMSPEC")))
       { ERRO (15,"Erro ao acessar COMMAND.COM.");
       ESPERA (19); }
INICIA ();
RETORNO ();

return (0); }





main (argc,argv)
int argc;
unsigned char *argv[];
{ unsigned i,j,x0,y0;
struct ffblk flabel;

CLS ();
INICIA ();
RAZAO_SOCIAL (20,21);
discoCorrente = getdisk ();
if (getcurdir (0,dirCorrente+1)==EOF)
       { CLS ();
       ERRO (15,"Erro ao acessar diretorio corrente.");
       CURSOR (2,0,24);
       return (6); }
dirCorrente[0] = '\\';
if (findfirst("\\*.*",&flabel,FA_LABEL))
       strcpy (volumeCorrente,"sem nome");
  else strcpy (volumeCorrente,flabel.ff_name);
ptf = NULL;
ptarq = NULL;
equipamento = (biosequip () & 0xc0) >> 6;

x0 = 24;
y0 = 5;
TELA_0 (x0,y0);
x0++;
y0++;

while (TRUE)
  { j = TRUE;
  while (j)
    { LECAR ();
    i = _AH;
    switch (i)
      { case 72:    /* up */
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = (funcao + 5) % 6;
          REVERSO (x0,y0+funcao,29,cor[3]);
          break;
      case 80:      /* down */
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = (funcao + 1) % 6;
          REVERSO (x0,y0+funcao,29,cor[3]);
          break;
      case 28:      /* return */
          j = FALSE;
          break;
      case 59:      /* F1 */
      case 38:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 0;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break;
      case 60:      /* F2 */
      case 46:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 1;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break;
      case 61:      /* F3 */
      case 23:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 2;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break;
      case 62:      /* F4 */
      case 34:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 3;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break;
      case 65:      /* F7 */
      case 32:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 4;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break;
      case 67:      /* F9 */
      case 18:
          REVERSO (x0,y0+funcao,29,cor[2]);
          funcao = 5;
          REVERSO (x0,y0+funcao,29,cor[3]);
          j = FALSE;
          break; } }

  if (funcao==5)
         break;
  switch (funcao)
    { case 0:
        MANUAL_ON_LINE ();
        CLS ();
        break;
    case 1:
        BACKUP ();
        break;
    case 2:
        INSTALL ();
        break;
    case 3:
        NOVO_ARQUIVO ();
        CLS ();
        break;
    case 4:
        COMANDO ();
        CLS ();
        break; }
  RAZAO_SOCIAL (20,21);
  TELA_0 (x0-1,y0-1); }

CLS ();
ACABA ();

return (0); }
