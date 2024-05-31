#include <iostream>
#include <stdlib.h>
#include <vector> //libreria para agregar vectores(arreglos)
#include <string>

using namespace std;

//funciones
void mostrarMenu1();
void mostrarMenuEstadisticas();
void mostrarArtistas();
void mostrarMenuTipoObra();
void mostrarCategoriaInicial();
void seleccionarTipoDeObra(const int tipoObra);
void mostrarArtistas(const vector<string>& artistas);
int contarArtistas(const vector<string>& artistas); // contar artistas
void limpiarPantalla();

int main(){
	
   //definicion de variables
	int opcionMenu1, menuInscripciones, menuTipoDeObra, menuCategoriaInicial, menuEstadisticas;
	float montoTotal;
	string nombreArtista;
	char continuar, continuarO, opcionCrearObra;
	
	// Estructura para almacenar los detalles de una obra de arte
    struct ObraDeArte {
    int artistaId;  // ID del artista (índice en el vector de artistas)
    string nombreObra;
    double precio;
    string tipoObra;
    string categoria;
    bool menu1;
    };
    
	
	//definicion de arrays(arreglos)
	vector<string> artistas;
	vector<ObraDeArte> obras;
	
	
	
	
	
	while(bool menu1 = true){
		
	do{
		mostrarMenu1();
		cin>> opcionMenu1;
		limpiarPantalla();
		if(opcionMenu1 <= 0 && opcionMenu1 >= 5){
			bool menu1 = true;
		}
	}while(opcionMenu1 <= 0 || opcionMenu1 >= 5);//se usa para que se seleccione una opcion corecta
		
	if(opcionMenu1 == 1){//agregar un nuevo artista o una nueva obra
	
		cout<<"INSCRIPCIONES \n 1-inscribir un nuevo artista \n 2-inscribir nueva obra de un artista"<< endl;
		cin>>menuInscripciones;
		limpiarPantalla();
		if(menuInscripciones == 1){//agregar nuevo artista
		    
			cout<<"agregar un nuevo artista"<< endl;
			cout<<"ingrese el nuevo nombre del artista: ";
			cin>>nombreArtista;
			artistas.push_back(nombreArtista);
			
			limpiarPantalla(); 
			
			
              ObraDeArte nuevaObra;
              mostrarArtistas(artistas);//llama la funcion para mostrar los artistas
              cout << "Selecciona el ID del artista (1 a " << artistas.size() << "): ";
              cin >> nuevaObra.artistaId;
              nuevaObra.artistaId--; // Ajuste para índice basado en 0
              cin.ignore(); // Limpiamos el buffer de entrada

              cout << "Ingresa el nombre de la obra: ";
              getline(cin, nuevaObra.nombreObra);

              cout << "Ingresa el precio de la obra: ";
              cin >> nuevaObra.precio;
              cin.ignore(); // Limpiamos el buffer de entrada

              do{
              	mostrarMenuTipoObra();
                cin>>menuTipoDeObra;
			  }while(menuTipoDeObra <0 || menuTipoDeObra>=10);
              
              if(menuTipoDeObra == 1){
              	nuevaObra.tipoObra="acrilico";
			  }else if(menuTipoDeObra == 2){
			  	nuevaObra.tipoObra="oleo";
			  }else if(menuTipoDeObra == 3){
			  	nuevaObra.tipoObra="mixto";
			  }else if(menuTipoDeObra == 4){
			  	nuevaObra.tipoObra="acuarela";
			  }else if(menuTipoDeObra == 5){
			  	nuevaObra.tipoObra="cuadro en cruceta";
			  }else if(menuTipoDeObra == 6){
			  	nuevaObra.tipoObra="cuadro bordado";
			  }else if(menuTipoDeObra == 7){
			  	nuevaObra.tipoObra="cuadro enrepujado";
			  }else if(menuTipoDeObra == 8){
			  	nuevaObra.tipoObra="crayola";
			  }else if(menuTipoDeObra == 9){
			  	nuevaObra.tipoObra="yeso";
			  }
              
              
              
              do{
              	mostrarCategoriaInicial();
                cin>>menuCategoriaInicial;
			  }while(menuCategoriaInicial <0 || menuCategoriaInicial>=4);

              if(menuCategoriaInicial == 1){
              	nuevaObra.categoria="inicial";
			  }else if(menuCategoriaInicial == 2){
			  	nuevaObra.categoria="intermedio";
			  }else if(menuCategoriaInicial == 3){
			  	nuevaObra.categoria="avanzado";
			  }
			  
              

        // Agregamos la nueva obra al vector de obras
        obras.push_back(nuevaObra);

        
        
        limpiarPantalla();
   
	
    
   
    
		}else if(menuInscripciones == 2){//agregar nueva obra a un artista ya existente
			
			int totalArtistas = contarArtistas(artistas);
			if(totalArtistas == 0){
				limpiarPantalla();
				cout<<"no hay ningun artista registrado en este momento"<<endl;
				
			}else{
					//agregar obra del artista
			
			do {
              ObraDeArte nuevaObra;
              mostrarArtistas(artistas);//llama la funcion para mostrar los artistas
              cout << "Selecciona el ID del artista (1 a " << artistas.size() << "): ";
              cin >> nuevaObra.artistaId;
              nuevaObra.artistaId--; // Ajuste para índice basado en 0
              cin.ignore(); // Limpiamos el buffer de entrada

              cout << "Ingresa el nombre de la obra: ";
              getline(cin, nuevaObra.nombreObra);

              cout << "Ingresa el precio de la obra: ";
              cin >> nuevaObra.precio;
              cin.ignore(); // Limpiamos el buffer de entrada

              
              

              do{
              	mostrarMenuTipoObra();
                cin>>menuTipoDeObra;
			  }while(menuTipoDeObra <0 || menuTipoDeObra>=10);
              
              if(menuTipoDeObra == 1){
              	nuevaObra.tipoObra="acrilico";
			  }else if(menuTipoDeObra == 2){
			  	nuevaObra.tipoObra="oleo";
			  }else if(menuTipoDeObra == 3){
			  	nuevaObra.tipoObra="mixto";
			  }else if(menuTipoDeObra == 4){
			  	nuevaObra.tipoObra="acuarela";
			  }else if(menuTipoDeObra == 5){
			  	nuevaObra.tipoObra="cuadro en cruceta";
			  }else if(menuTipoDeObra == 6){
			  	nuevaObra.tipoObra="cuadro bordado";
			  }else if(menuTipoDeObra == 7){
			  	nuevaObra.tipoObra="cuadro enrepujado";
			  }else if(menuTipoDeObra == 8){
			  	nuevaObra.tipoObra="crayola";
			  }else if(menuTipoDeObra == 9){
			  	nuevaObra.tipoObra="yeso";
			  }
              
              
              
              
              do{
              	mostrarCategoriaInicial();
                cin>>menuCategoriaInicial;
			  }while(menuCategoriaInicial <0 || menuCategoriaInicial>=4);

              if(menuCategoriaInicial == 1){
              	nuevaObra.categoria="inicial";
			  }else if(menuCategoriaInicial== 2){
			  	nuevaObra.categoria="intermedio";
			  }else if(menuCategoriaInicial == 3){
			  	nuevaObra.categoria="avanzado";
			  }
			  
              

        // Agregamos la nueva obra al vector de obras
        obras.push_back(nuevaObra);

        // Preguntamos si el usuario quiere agregar otra obra de arte
        cout << "¿Quieres agregar otra obra de arte? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpiamos el buffer de entrada
        
        cout << "\nLista de obras de arte:" << endl;
    for (size_t i = 0; i < obras.size(); i++) {
        cout << "Obra " << i + 1 << ":" << endl;
        cout << "  Artista: " << artistas[obras[i].artistaId] << endl;
        cout << "  Nombre de la obra: " << obras[i].nombreObra << endl;
        cout << "  Precio: $" << obras[i].precio << endl;
        cout << "  Tipo de obra: " << obras[i].tipoObra << endl;
        cout << "  Categoria: " << obras[i].categoria << endl;
    }

    } while (continuar == 's' || continuar == 'S');
    limpiarPantalla();
			}
		}

	}else if(opcionMenu1 == 2){
		limpiarPantalla();
		do{
		mostrarMenuEstadisticas();
		cin>> menuEstadisticas;
		limpiarPantalla();
	}while(menuEstadisticas <= 0 || menuEstadisticas >= 6);
	
	if(menuEstadisticas ==1){//total de participantes
		int totalArtistas = contarArtistas(artistas);
		cout<<"total de participantes: "<<totalArtistas<<endl;
	}else if(menuEstadisticas ==2){
		//El monto total en el caso que se vendieran todas las obras. Detallar el monto total por categoría y luego el monto total en general.
		cout<<""<<endl;
	}else if(menuEstadisticas ==3){
		//El detalle de las obras registras por categoría y el total de obras.
		std::cout << "\nLista de obras de arte:" << std::endl;
    for (size_t i = 0; i < obras.size(); i++) {
        cout << "Obra " << i + 1 << ":" << endl;
        cout << "  Artista: " << artistas[obras[i].artistaId] << endl;
        cout << "  Nombre de la obra: " << obras[i].nombreObra << endl;
        cout << "  Precio: $" << obras[i].precio << endl;
        cout << "  Tipo de obra: " << obras[i].tipoObra << endl;
        cout << "  Categoria: " << obras[i].categoria << endl;
    }
    
    int totalObras = obras.size();
    cout << "Número total de obras de arte: " << totalObras << endl;
	}else if(menuEstadisticas ==4){
		//Cuantos participantes se tendrán por categoría.
		cout<<""<<endl;
		int inicial = 0, intermedio = 0, avanzado = 0;
	   for (size_t i = 0; i < obras.size(); i++) {
	   	
	   
	   	
	   	 if( obras[i].categoria == "inicial"){
	   		inicial = inicial + 1;
		   }else if( obras[i].categoria == "intermedio"){
	   		intermedio = intermedio + 1;
		   }else if( obras[i].categoria == "avanzado"){
	   		avanzado = avanzado +1;
		   }      
		   i++;
    } 
    
        cout << "  Inicial: " << inicial << endl;
        cout << "  Intermedio: " << intermedio << endl;
        cout << "  avanzado: " << avanzado << endl;
        
  
    
	}else if(menuEstadisticas ==5){
		//Cuál es la obra más cara que se tendrá en la exposición y de que artista es.
		if (obras.empty()) {
        cout << "No hay obras registradas." << endl;
        return 0;
    }

    double precioMaximo = obras[0].precio;
    size_t indiceMaximo = 0;

    for (size_t i = 1; i < obras.size(); ++i) {
        if (obras[i].precio > precioMaximo) {
            precioMaximo = obras[i].precio;
            indiceMaximo = i;
        }
    }

    cout << "La obra mas cara es \"" << obras[indiceMaximo].nombreObra << "\" del artista " << artistas[obras[indiceMaximo].artistaId] << "." << endl;
    cout << "Precio: $" << obras[indiceMaximo].precio << endl;
		
	}
		
		
	
	}
		
		
	}
	
	

	
	
}

//FUNCIONES 
void mostrarMenu1(){	
   // funcion nueva
	cout<<"SELECCIONE UNA OPCION \n 1-inscripcion \n 2-estadisticas \n 3-Comprar Obras \n 4-Salir"<< endl;
	// final de la funcion
}
void mostrarMenuEstadisticas(){	
   // funcion nueva
	cout<<"SELECCIONE UNA OPCION \n 1-Total de Participantes \n 2-estadisticas \n 3-Salir"<< endl;
	cout<<"SELECCIONA UNA OPCION:"<<endl;
	cout<<"1-Total de Participantes"<<endl;
	cout<<"2-Montos totales"<<endl;
	cout<<"3-Detalles de las obras"<<endl;
	cout<<"4-Participantes por Categoria"<<endl;
	cout<<"5-Precio de la Obra Mas Cara"<<endl;
	// final de la funcion
}

void mostrarMenuTipoObra(){
	cout<<"SELECCIONA EL TIPO DE OBRA"<<endl;
	cout<<"1-acrilico"<<endl;
	cout<<"2-oleo"<<endl;
	cout<<"3-mixto"<<endl;
	cout<<"4-acuarela"<<endl;
	cout<<"5- cuadro en cruceta"<<endl;
	cout<<"6-cuadro bordado"<<endl;
	cout<<"7-cuadro enrepujado"<<endl;
	cout<<"8-crayola"<<endl;
	cout<<"9-yeso"<<endl;
}

void mostrarCategoriaInicial(){
	cout<<"SELECCIONA EL TIPO DE CATEGORIA"<<endl;
	cout<<"1-inicial"<<endl;
	cout<<"2-intermedio"<<endl;
	cout<<"3-avanzado"<<endl;
	
}

void mostrarArtistas(const vector<string>& artistas){
    cout << "\nLista de artistas:" << endl;
    for (size_t i = 0; i < artistas.size(); i++) {
        cout << i + 1 << ". " << artistas[i] << endl;
    }
}

void limpiarPantalla() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

int contarArtistas(const vector<string>& artistas) {
    return artistas.size();
}

