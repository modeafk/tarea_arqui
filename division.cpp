
/*
    Arquitectura de computadores(CComp3-1)
    
    ALUMNO:
    Marcelo Torres Acuña

    TEMA:
    Division de enteros

*/
#include <iostream>
#include <bitset>

using namespace std;

int main(){
int const n_bits=4;//este es el tamaño de bits variara 
int q,m,A=0;


cout<<"ingrese un valor para q: ";cin>>q;
cout<<"ingrese un valor para m: ";cin>>m;

bitset<n_bits> binario_q(q), binario_A(A),binario_m(m);

for(int contador=n_bits;contador>0;contador--){
    
  
        binario_A=binario_A<<1; //a se desplaza a la izquierda

        binario_A[0]=binario_q[3];  // este variara de acuerdo el tamaño de bits que se coloque, n-1
       
        binario_q=binario_q<<1;//desplaza un espacio a la izquierda a q;
    
        binario_m=~binario_m;//hacemos el complemento inviertiendo los bits 1010→0101
    
        A=binario_A.to_ulong();
        A=A-m; //restamos 

    if(A>=0){//si A es mayor que cero este hara que el primer bit del lado izquierdo de q tenga el valor de 1 

        binario_q[0]=1;
    }
    else{
        
            A=A+m;//para regresar al anterior valor que tenia A
    }

    bitset<n_bits> temp(A);
	binario_A = temp;
    q=binario_q.to_ulong();
}
    

    cout<<"--------------------------------------"<<endl;
    cout<<"para q/cociente"<<endl; 
    cout<<"valor en bits --->"<<binario_q<<endl;
    cout<<"valor en decimal --->"<<q<<endl;
    cout<<"--------------------------------------"<<endl;
    cout<<"para A/residuo"<<endl;
    cout<<"valor en bits --->"<<binario_A<<endl;
    cout<<"valor en decimal --->"<<A<<endl;
    return 0;
}