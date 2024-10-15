#include<iostream>
int main(){
    int i;
    float realc, imagc, realz, imagz;
    std :: cout << "Entrez la partie réelle de votre nombre.\n";
    std :: cin >> realc;
    std :: cout << "Entrez la partie imaginaire de votre nombre.\n";
    std :: cin >> imagc;
    i = 0;
    imagz = 0;
    realz = 0;
    while(i < 1000){
        /*Si z = a + ib alors, z^2 = a^2 - b^2 + 2i*a*b
        Donc, sa partie réelle sera a^2 - b^2;
        et sa partie imaginaire, 2*a*b*/
        realz = realz * realz - imagz * imagz + realc;
        imagz = imagc + 2 * realz * imagz ;

        if((realz * realz + imagz * imagz) > 4){
            /*Ici, on vérifie si la suite (Z) définie par z = z^2 + c est convergente.*/
            std :: cout << "Ce nombre n'appartient pas à l'ensemble de Mandelbrot.\n";
            break;
        } else {
            i++;
        }
    }
    if(i == 1000){
            std :: cout << "Ce nombre fait partie de l'ensemble de Mandelbrot.\n";
        }
    return 0;
}