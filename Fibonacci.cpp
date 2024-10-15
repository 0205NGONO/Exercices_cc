#include<iostream>
int main(){
    int a = 0, b = 1, next, i;
    unsigned int n;
    std :: cout << "Entrez le terme que vous voulez la valeur dans la suite de Fibonacci.\n";
    std :: cin >> n;
    if(n == 0){
        std :: cout << a <<"\n";
    } else if(n == 1){
            std :: cout << b <<"\n";

        }else{
    
                for(i = 2; i <= n; i++){
                    next = a + b;
                    a = b;
                    b = next;
                }
                std :: cout << next<<"\n";
            }
    
    return 0;
}