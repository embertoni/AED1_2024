#include <stdio.h>

int main() {

    int n, rd, ano, mes, dia;
    scanf("%i", &n);    
    ano = n/365;
    rd = n%365;
    mes = rd/30;
    dia = rd%30;
    printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n", ano, mes, dia);

    return 0;
}
