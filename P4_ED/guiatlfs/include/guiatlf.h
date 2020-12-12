/**
 * @ file : guiatlf.h
 * @brief: TDA guia de telefonos
 * */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
#include <list>
#include <set>

using namespace std;
istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}	  

ostream & operator<<(ostream &os,const pair<const string,string> &d){
	  
	  os<<d.first<<'\t'<<d.second<<endl;
	  return os;
}	  


/**
  *  @brief T.D.A. Guia_Tlf
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia_Tlf es un objeto
  * formado por una colección de pares {(e11,e21),(e12,e22),(e13,e23),...,(e1n-1,e2n-1)}
  * ordenados por la el primer elemento del par denominado clave o key. No existen
  * elementos repetidos. 
  *
  *
  * Un ejemplo de su uso:
  *
  *
  * @author Rosa Rodríguez
  * @date Marzo 2012
  */

class Guia_Tlf{
  /**
  * @page repGuia_Tlf Rep del TDA Guia_Tlf
  *
  * @section invGuia_Tlf Invariante de la representación
  *
  * El invariante es \e para todo \e i y \e j tal que i<j entonces \e e1i y e1j son distintos
  *
  * @section faGuia_Tlf Función de abstracción
  *
  * Un objeto válido @e rep del TDA Guia_Tlf representa al valor
  *
  * {(rep.begin().first,rep.begin().second),(rep.begin()+1.first,rep.begin()+1.second),....,(rep.begin()+n-1.first,rep.begin()+n-1.second)}
  *
  */
	  private:
		    //multimap<string,string> datos;
		    map<string, list<string> > datos; //si admites que haya nombres repetidos tendrías que usar un
					     //multimap
					     
	  public:
		    
		    /**
		      @brief Acceso a un elemento
		      @param nombre: nombre del elemento  elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el teléfono
		    */
		    //si fuese un multimap no podriamos usar []. Ademas que deberiamos devolver p.e un vector con todos
		    // los telefonos asociados a dicho nombre
		    list<string> & operator[](const string &nombre) {
			      return datos[nombre];
		    }
		    
		    
		    list<string>  gettelefono(const string & nombre){
			      map<string,list<string> >::iterator it=datos.find(nombre);
			      if (it==datos.end()) 
					return list<string>();
			      else return it->second;
		    }
		     
		    /**
		     @brief Insert un nuevo telefono 
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
			      o false en caso contrario
		    */
		    pair<map<string, list<string> >::iterator,bool>  insert(string nombre, string tlf){

			      pair< map<string,list<string> > ::iterator,bool> ret;
			      map<string,list<string> >::iterator it=datos.find(nombre);


			      if (it==datos.end()) {
				        list <string> l;
					l.push_back(tlf);
					pair<string,list<string> > p (nombre, l);
					ret=datos.insert(p);
			      }
			      else{

				datos[nombre].push_back(tlf);
				ret.first=it;
				ret.second=true;
			      }


			      return ret;     
					
		    }
		    
		    /**
		     @brief Insert un nuevo telefono 
		     @param p: pair con el nombre y el telefono asociado
		     
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
			      o false en caso contrario
		    */
		    pair<map<string, list<string> >::iterator,bool>  insert(pair<string, list<string> > p){
			      
			      pair<map<string,list<string> > ::iterator,bool> ret;

			      ret=datos.insert(p); //datos.insert(datos.begin(),p); tambien funcionaría
			      return ret;     
					
		    }


		    /**
		     @brief Insert un nuevo telefono 
		     @param p: pair con el nombre y el telefono asociado
		     
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o 
			      o false en caso contrario
		    */
		    pair<map<string, list<string> >::iterator,bool>  insert(pair<string,string> p){
			      
			      pair< map<string,list<string> > ::iterator,bool> ret;
			      map<string,list<string> >::iterator it=datos.find(p.first);


			      if (it==datos.end()) {
				        list <string> l;
					l.push_back(p.second);
					pair<string,list<string> > paux (p.first, l);
					ret=datos.insert(paux);
			      }
			      else{

				datos[p.first].push_back(p.second);
				ret.first=it;
				ret.second=true;
			      }


			      return ret;      
					
		    }
		    
		    
		    
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar
		      @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre){
			   //OTRA ALTERNATIVA
			   pair<map<string, list<string> >::iterator,map<string,list<string>> ::iterator>ret;
			   ret = datos.equal_range(nombre);
			   datos.erase(ret.first,ret.second);  

		    }
		    
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar y telefono asociado
		      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		    */
		    //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf){
		           map<string,list<string> >::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
			   //map<string,list<string> >::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
			   list<string>::iterator it;

			   bool salir =false;

			   for (it=(*itlow).second.begin(); it!=(*itlow).second.end() && !salir;++it){
				     if (*it==tlf){
					(*itlow).second.erase(it);
					salir =true;
				     }		
			   }		
			   
		    }
		    /**
		      @brief  Numero de telefonos 
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			      return datos.size();
		    }	      
		    /**
		      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      @param nombre: nombre sobre el que queremos consultar
		      @return numero de telefonos asociados a un nombre
		      
		     */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }
		    
		    /**
		      @brief Limpia la guia
		     */
		    void clear(){
			      datos.clear();
		    }	      
		    /**
		      @brief Union de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string, list<string> >::const_iterator it;

			for (it=g.datos.begin(); it!=g.datos.end(); ++it){
			   	if(datos.find((*it).first)==datos.end())aux.insert(*it);

			   	else{
			   		list<string>::const_iterator tlfs=(*it).second.begin();

			   		for(; tlfs!=(*it).second.end(); ++tlfs){

			   			aux[(*it).first].push_back(*tlfs);


			   		}
			   	}
			}
			return aux;
			
		    }	   
		    	      
		    /**
		      @brief Diferencia de guias de telefonos
		      @param g: guia a restar
		      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g){
			Guia_Tlf aux(*this);
			map<string, list<string> >::const_iterator it;

			for (it=g.datos.begin();it!=g.datos.end();++it){

				list<string>::const_iterator tlfs=(*it).second.begin();

				for(; tlfs!=(*it).second.end(); ++tlfs){

					cerr<<" "<< *tlfs<<endl;
					aux[(*it).first].remove(*tlfs);
	 			}
	 			if(aux[(*it).first].empty())aux.borrar((*it).first);
	 		}
	
			return aux;
			
		    }
		    /**
		      @brief Intersección de guías de teléfonos
			  @param g: guia a restar
		      @return: una nueva guia resultado de la intersección del objeto al que apunta this y g
		    */
		    Guia_Tlf operator^(const Guia_Tlf & g){
			Guia_Tlf aux;
			map<string, list<string> >::const_iterator it;

			for (it=g.datos.begin();it!=g.datos.end();++it){

				if(datos.find((*it).first)!=datos.end()){
		
					list<string>::const_iterator tlfs=(*it).second.begin();
					set<string> res;
					list<string>::const_iterator mistlfs=datos[(*it).first].begin();

					for(; mistlfs!=datos[(*it).first].end(); ++mistlfs){
						for(; tlfs!=(*it).second.end(); ++tlfs){

							if(*mistlfs==*tlfs)res.insert(*tlfs);
			 			}
					}
					for(auto s=res.begin(); s!=res.end(); ++s)aux.insert((*it).first,*s);
					

				}

				
	 		}
	
			return aux;
			
		    }



		    
		    

			/**
		      @brief  Obtiene una guia con los nombre previos a uno dado
		      @param nombre: nombre delimitador
		      @return nueva guia sin nombres mayores que \a  nombre
		     */
		    Guia_Tlf previos(const string &nombre){
			map<string, list<string> >::value_compare vc=datos.value_comp(); //map<string,string>::key_compare vc=datos.key_comp()
			Guia_Tlf aux;
			pair<string,list<string> >p(nombre,datos[nombre]);
			map<string, list<string> >::iterator it=datos.begin();
			while (vc(*it,p)){
				  aux.insert(*it++);
				  
			}
			return aux;
			      
		     }		      
		    
		    
		    /**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */ 
		      
		    
		    friend ostream & operator<<(ostream & os, Guia_Tlf & g){
			      map<string, list<string> >::iterator it;

			      for (it=g.datos.begin(); it!=g.datos.end();++it){
					os<<endl<<it->first<<"\t";
					list<string>::const_iterator its;
					for(its=(*it).second.begin(); its!=(*it).second.end(); ++its)
						os<<endl<<"\t"<<*its;			
			
			      }
			      return os;
		    }
		    
		    /**
		      @brief Lectura de  la guia de telefonos
		      @param is: flujo de entrada. ES MODIFICADO
		      @param g: guia de telefonos. ES MODIFICADO
		      @return el flujo de entrada
		    */
		    
		    friend istream & operator>>(istream & is, Guia_Tlf & g){
			      pair<string,string> p;
			      Guia_Tlf aux;
			      
			      while (is>>p){
				  aux.insert(p);
			      }
			      g=aux;
			      return is;
		    }
		    
		    /**
		     * @brief clase para iterar sobre la guia
		     * */
		    class iterator{
		     private:
		      map<string,list<string> >::iterator it, final;
		     public:
		       iterator & operator++(){
			    ++it;
			    *this;		       
			}
		       iterator & operator--(){
			   --it;
			    *this;		       
		       }
		       pair<const string,list<string> > &operator *(){
			  	return *it;
		       }
		       bool operator ==(const iterator &i){
			  return i.it==it;
		       }	  
		       
		       bool operator !=(const iterator &i){
			  return i.it!=it;
		       }


			iterator& operator=(const iterator &i){
				it=i.it;
				return *this;
			}
			iterator& operator+(int a){
				for(int k=0; k<a; k++){
					++it;
				}
				return *this;
			}

		       friend class Guia_Tlf;
		    };
		    

		     class const_iterator{
		     private:
		      map<string, list<string> >::const_iterator it, final;
		     public:
		       const_iterator & operator++(){
			    ++it;
			    *this;		       
			}
		       const_iterator & operator--(){
			   --it;
			    *this;		       
		       }
		       const pair<const string, list<string> > &operator *(){
			  return *it;
		       }
		       bool operator ==(const const_iterator &i){
			  return i.it==it;
		       }	  
		       
		       bool operator !=(const const_iterator &i){
			  return i.it!=it;
		       }


			const_iterator& operator=(const const_iterator &i){
				it=i.it;
				return *this;
			}
			const_iterator& operator+(int a){
				for(int k=0; k<a; k++){
					++it;
				}
				return *this;
			}

		       friend class Guia_Tlf;
		    };
		    /**
		     * @brief Inicializa un iterator al comienzo de la guia
		     * */
		    iterator begin(){
			iterator i;
			i.it=datos.begin();
			i.final=datos.end();
			return i;
		    }	
		    /**
		     * @brief Inicializa un iterator al final de la guia
		     * */
		    iterator end(){
			iterator i;
			i.it=datos.end();
			i.final=datos.end();
			return i;
		    }  


			/**
		     * @brief Inicializa un iterator al comienzo de la guia
		     * */
		    const_iterator begin()const{
			const_iterator i;
			i.it=datos.cbegin();
			i.final=datos.cend();
			return i;
		    }	
		    /**
		     * @brief Inicializa un iterator al final de la guia
		     * */
		    const_iterator end()const{
			const_iterator i;
			i.it=datos.cend();
			i.final=datos.cend();
			return i;
		    } 
		        
					
			      
		    
};
#endif

