#include "guiatlf.h"
#include <fstream>
int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Dime el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }
  
 Guia_Tlf g;
 
 f>>g;
 cout<<"La guia insertada "<<g<<endl;
 cin.clear();
 cout<<"Dime un nombre sobre el que quieres obtener el telefono: ";
 string n;
 while (getline(cin,n)){
	   cout<<"Buscando "<<n<<"...."<<endl;
	   list<string> tlf = g.gettelefono(n);
	   if (tlf.empty()){
		     cout<<"No existe ese nombre en la guia"<<endl;
	   }
	   else 
	    cout << "telefonos asociados a ese nombre: " << endl;
	    for(list<string>::iterator i =tlf.begin(); i!=tlf.end(); ++i) cout << *i << endl;
	   cout<<endl<<"[Pulse CTRL+D para finalizar] Dime un nombre sobre el que quieres obtener el telefono: ";
 }	
 cin.clear();
 cout<<endl<<"Dime el nombre que quieres borrar: ";
 
 while (getline(cin,n)){
	   g.borrar(n);
	   cerr<<"Ahora la guia es:"<<endl;
	   cerr<<g<<endl;
	   cout<<endl<<"[Pulse CTRL+D para finalizar] Dime el nombre que quieres borrar: ";

 }
 
 cin.clear();
 Guia_Tlf otraguia;
 string nombreguia;
 cout<<endl<<"Introduce otra guia ([Pulse CTRL+D para finalizar]): ";
 cin>>nombreguia;

 ifstream f2(nombreguia);
 if (!f2){
      cerr<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
 }
  f2>>otraguia;// cin.clear();
  cerr << "La otra guia es: "<<endl<<otraguia<<endl;
 Guia_Tlf un = g+otraguia;
 Guia_Tlf dif = g-otraguia;
 Guia_Tlf inter = g^otraguia;
 cout<<endl<<"La union de las dos guias: "<<un<<endl;
 
 cout<<endl<<"La diferencia de las dos guias:"<<dif<<endl;

 cout << endl << "La intersección de las dos guias: "<<inter<<endl;
 
 cout<<endl<<"Dime un nombre para establecer los previos"<<endl;
 cin>>n;
 list<string> tlf= g.gettelefono(n);
 Guia_Tlf p = g.previos(n);
 cout<<endl<<"Los nombre previos: "<<p<<endl;
 
 
 cout<<"Listando la guia con iteradores:"<<endl;
 Guia_Tlf::iterator it;
 list<string>::const_iterator its;

 for (it=g.begin(); it!=g.end(); ++it){
 	 cout << endl;
 	 cout << (*it).first;
    for(its=(*it).second.begin(); its!=(*it).second.end(); ++its) cout<<" "<<(*its)<<endl;
 }
}
