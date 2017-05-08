#include<iostream>
#define tam 50
 
using namespace std;


int main(){
  int v1[tam], x,n;


  cout<<"Digite o numero de vendas\n"; // pede ao menos uma vez para ter um valor como comparação
  cin>>n;


  for(int i = 0; i < n; i++){
    cout<<"Digite um numero\n";
    cin>>v1[i];
    }

  int numIguais = 0;
  for(int i = 0; i < n; i++){
    for(int j = i-1; j >=0; j--){
      if(v1[i]==v1[j]){
        numIguais++;
        break;
      }
    }
  }

  cout<< n - numIguais << " Numeros diferentes\n";
}
