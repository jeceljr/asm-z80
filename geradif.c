#include <stdio.h>
#include <io.h>
#include <alloc.h>

#define TRUE    1
#define FALSE   0

main (argc,argv)
int argc;
unsigned char *argv[];
{ unsigned indBuffer,tamBuffer,numBuffer,tamInsercao,baseInsercao,i,j,ok,dump;
unsigned long indBase,tamArqBase,tamArqNovo,*ptl,*pta,l,m;
unsigned char huge *arqBase,*arqNovo,iden[64],*ptc;
FILE *fbase,*fnovo,*fsaida,*fopen();

fprintf (stderr,"\n\n==================================================\n");
fprintf (stderr,"Gerador de diferencas - Edicao de 6 de Julho, 1988\n");
fprintf (stderr,"--------------------------------------------------\n");
fprintf (stderr,"Copyright Inova Tecnologia e Informatica Ltda 1988\n");
fprintf (stderr,"==================================================\n\n");

if (argc<3)
       { fprintf (stderr,"\nUso: geradif arquivoBase arquivoNovo\n");
       exit (1); }
if (argc==4 && (*argv[3]=='0' || *argv[3]=='1'))
       dump = *argv[3] - '0';
  else dump = 0;


fbase = fopen (argv[1],"rb");
if (!fbase)
       { fprintf (stderr,"\nArquivo %s nao encontrado.\n",argv[1]);
       exit (2); }
fnovo = fopen (argv[2],"rb");
if (!fnovo)
       { fprintf (stderr,"\nArquivo %s nao encontrado.\n",argv[2]);
       exit (2); }
strcpy (iden,argv[2]);
for (indBuffer=0;iden[indBuffer++];);
for (;iden[--indBuffer]!='.';);
strcpy (iden+indBuffer,".dif");
fsaida = fopen (iden,"wb");
if (!fsaida)
       { fprintf (stderr,"\nErro ao abrir arquivo de saida %s.\n",iden);
       exit (2); }


tamArqBase = filelength (fileno(fbase));
if (!(arqBase=farcalloc(tamArqBase,(long) sizeof (char))))
       { fprintf (stderr,"\nArea de memoria com tamanho %ld nao alocada.\n",
                                                                  tamArqBase);
       exit (3); }
tamArqNovo = filelength (fileno(fnovo));
numBuffer = tamBuffer = (tamArqNovo<0x8000) ? tamArqNovo : 0x8000;
if (!(arqNovo=farcalloc((long) (tamBuffer+7),(long) sizeof (char))))
       { fprintf (stderr,"\nArea de memoria com tamanho %u nao alocada.\n",
                                                                   tamBuffer);
       exit (3); }


for (indBase=0;(i=getc(fbase))!=EOF;indBase++)
  arqBase[indBase] = i;
fclose (fbase);
for (indBuffer=0;indBuffer<tamBuffer;indBuffer++,tamArqNovo--)
  arqNovo[indBuffer] = getc(fnovo);


fprintf (stderr,"\nInicio de identificacao: ");
gets (iden);
for (indBase=0l;indBase<tamArqBase;indBase++)
  for (l=indBase,i=0;l<tamArqBase;l++)
    if (arqBase[l]!=iden[i++])
           break;
      else if (!iden[i])
                  { l = indBase;
                  i = 0;
                  indBase = tamArqBase;
                  break; }
fprintf (stderr,"Final de identificacao : ");
gets (iden);
for (indBase=0l;indBase<tamArqBase;indBase++)
  for (m=indBase,j=0;m<tamArqBase;m++)
    if (arqBase[m]!=iden[j++])
           break;
      else if (!iden[j])
                  { tamInsercao = m - l + 1;
                  m = indBase;
                  j = 0;
                  indBase = tamArqBase;
                  break; }
if (i || j || l>m)
       { fprintf (stderr,"\nString de identificacao nao foi encontrada.\n");
       exit (4); }
for (ptc=&l,i=0;i<3;)
  putc (ptc[i++],fsaida);
ptc = &tamInsercao;
putc (ptc[0],fsaida);
putc (ptc[1],fsaida);
if (dump)
       printf ("%ld %d ",l,tamInsercao);
for (;l<m;l++)
  { putc (arqBase[l],fsaida);
  if (dump)
         putc (arqBase[l],stdout); }
fprintf (fsaida,"%s",iden);
if (dump)
       printf ("%s\n",iden);


baseInsercao = tamInsercao = indBuffer = 0;
ok = FALSE;


S0:
  if (dump)
         printf ("\nEstado S0 - numBuffer = %u   tamInsercao = %u\n",
                                                       numBuffer,tamInsercao);
  if (numBuffer<8)
         { tamInsercao += numBuffer;
         numBuffer = 0;
         goto S1; }
  ptl = (unsigned long *) (arqNovo + indBuffer);
  for (l=0l;l+7<tamArqBase;l++)
    { pta = (unsigned long *) (arqBase + l);
    if (ptl[0]==pta[0] && ptl[1]==pta[1])
           { indBase = l;
           ok = TRUE;
           break; } }
  if (!ok)
         { tamInsercao += 8;
         numBuffer -= 8;
         indBuffer = (indBuffer + 8) % tamBuffer;
         if (tamInsercao!=tamBuffer)
                goto S0; }
    else if (!tamInsercao)
                goto S2;


S1:
  if (dump)
         printf ("\nEstado S1 - tamInsercao = %u\n",tamInsercao);
  i = tamInsercao << 1;
  ptc = (unsigned char *) &i;
  putc (ptc[0],fsaida);
  putc (ptc[1],fsaida);
  for (;tamInsercao--;)
    { putc (arqNovo[baseInsercao],fsaida);
    if (dump)
           printf ("%02x  ",arqNovo[baseInsercao]);
    if (tamArqNovo)
           { arqNovo[baseInsercao] = getc (fnovo);
           if (baseInsercao<7)
                  arqNovo[tamBuffer+baseInsercao] = arqNovo[baseInsercao];
           tamArqNovo--;
           numBuffer++; }
    baseInsercao = ++baseInsercao % tamBuffer; }
  tamInsercao++;
  if (!numBuffer)
         goto sai;
  if (!ok)
         goto S0;


S2:
  if (dump)
         printf ("\nEstado S2\n");
  ok = FALSE;
  for (l=indBase;l+7<tamArqBase;l++)
    { pta = (unsigned long *) (arqBase + l);
    if (ptl[0]==pta[0] && ptl[1]==pta[1])
           { ptc = (unsigned char *) (pta + 2);
           i = (indBuffer + 8) % tamBuffer;
           for (j=8;j<numBuffer && arqNovo[i]==*ptc;ptc++)
             { j++;
             i = (i + 1) % tamBuffer; }
           if (tamInsercao<j)
                  { tamInsercao = j;
                  indBase = l; } } }
  numBuffer -= tamInsercao;
  if (dump)
         printf ("indBase = %ld   tamBloco = %u\n",indBase,tamInsercao);
  i = (tamInsercao << 1) + 1;
  ptc = (unsigned char *) &i;
  putc (ptc[0],fsaida);
  putc (ptc[1],fsaida);
  ptc = (unsigned char *) &indBase;
  putc (ptc[0],fsaida);
  putc (ptc[1],fsaida);
  putc (ptc[2],fsaida);
  for (;tamInsercao--;)
    if (tamArqNovo)
           { arqNovo[baseInsercao] = getc (fnovo);
           if (baseInsercao<7)
                  arqNovo[tamBuffer+baseInsercao] = arqNovo[baseInsercao];
           numBuffer++;
           tamArqNovo--;
           baseInsercao = ++baseInsercao % tamBuffer; }
      else { baseInsercao = (baseInsercao + tamInsercao + 1) % tamBuffer;
           break; }
  tamInsercao = 0;
  indBuffer = baseInsercao;
  if (numBuffer)
         goto S0;


sai:
if (dump)
       printf ("\nEstado S3 - numBuffer = %u\n",numBuffer);
fclose (fnovo);
fclose (fsaida);
exit (0); }
