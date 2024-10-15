#include<iostream>
double det( const double x1, double x2, double x3, double y1, double y2, double y3){
        double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        return(D);
    }
    /*Ici, nous calculons le déterminant de trois des points entrés.*/
double alignement( const double x1,double x2,double x3, double x4,double y1,double y2,double y3,double y4){
    bool a;
    if((y2 - y1) / (x2 - x1) == (y4 - y3) / (x4 - x3)){
        a = true;
    }else{
        a = false;
    }
    return(a);
    }
    /*Ici, nous vérifions si les points entrés par l'utilisateur sont alignés,
    en calculant et comparant les pentes.*/
int main(){
    double x1, x2, x3, x4, y1, y2, y3, y4,x,y, D1, D2;
    
    /*Ici, nous récupérons les coordonnées des lieux de 04 délis.*/
    std :: cout<< "Entrez les coordonnées x et y du lieu premier crime.\n";
    std :: cin >> x1 >> y1;
    std :: cout<< "Entrez les coordonnées x et y du lieu deuxième crime.\n";
    std :: cin >> x2 >> y2;
    std :: cout<< "Entrez les coordonnées x et y du lieu troisième crime.\n";
    std :: cin>>x3 >> y3;
    std :: cout<< "Entrez les coordonnées x et y du lieu quatrième crime.\n";
    std :: cin>>x4>>y4;
    if(alignement(x1, x2, x3, x4, y1, y2, y3, y4)){
        std :: cout<< "Triangulation impossible";
    }else{
        /*Ici, nous calculons les déterminants des trois premiers et des trois derniers points.*/
        D1 = det( x1, x2, x3, y1, y2, y3);
        D2 = det( x2, x3, x4, y1, y2, y4);
        /*Ici, nous allons calculer les coordonnées
        des centres des cercles circonscrits aux triangles formés
        par les 03 premiers points et les trois derniers points.*/
        x1 = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / D1;
        y1 = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / D1;
        x2 = ((x4 * x4 + y4 * y4) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y4) + (x3 * x3 + y3 * y3) * (y4 - y2)) / D2;
        y2 = ((x4 * x4 + y4 * y4) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x4 - x3) + (x3 * x3 + y3 * y3) * (x2 - x4)) / D2;
        /*Ici, nous allons calculer les coordonnées du point moyen des deux centres de cercles,
        qui seront définis comme étant une approximation des coordonnées dele maison du brigand.*/
        x = x1 + x2 / 2;
        y = y1 + y2 / 2;
        std ::cout<< "Les coordonnées de la maison du bandit sont : x= "<<x<<"et y= "<<y;
        return 0;
    }

}