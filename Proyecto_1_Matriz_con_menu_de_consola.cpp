//Hecho por Carlos Alfonso Lemus Rodezno.

//Libreria obligatoria iostream 
#include <iostream>
//Libreria conio.h nos pemite usar sus funciones y elementos
#include <conio.h>
//Espacio a de nobre a usar el standar
using namespace std;

//Funciones de tipo void sin parametros para usarlas como bloques
void ingresar(int datos[2][3]); //funcion que para ingresar los datos de la matriz
void mostrar(int datos[2][3]); //funcion que muestra los datos de la matriz
void cambiar(int datos[2][3]); //funcion que modifica los datos de la matriz
void eliminar(int datos[2][3]); //funion que elimina los datos de la matriz
void buscar(int datos[2][3]); //funcion que busca un dato de una matriz
void ordenar1(int datos[2][3]); //funcion permite elejir el modo de ordenar los datos de una matriz
void ordenar2(int datos[2][3], int (*compara)(int a, int b)); //funcion que ordena los datos de la matriz
void intercambio(int *ptr1, int *ptr2); //funcion para intercambiar varibles para el ordenamiento
int ancedente(int a, int b); //funcion que necesita la funcion ordenar2 para ordenar los datos de la matriz de forma ancedente
int decendente(int a, int b); //funcion que necesita la funcion ordenar2 para ordenar los datos de la matriz de forma dencedente
void errordato(); //Funcion error dato se usara para evitar errores de datos

/*
Variable opcion que nos permitira elejir opciones.
variables filas y columnas que nos permitira almacenar el vector bidiminsional.
variables nuevaf y nuevac que nos permitira cambiar o leminar el valor de un dator del vector bidiminsional.
*/
int opcion,filas, columnas, nuevaf, nuevac;

//Bloque principal
int main(){
	
	/* Variable dato un vector bidiminsional que tiene como forma de almacenamiento static para evitar que sus valores no se pierdan al momento de 
	de salir de una funcion, por lo tanto se mantendran dichos datos en tiempo de ejecucion del programa. */
	static int datos[2][3];
		
	/*Se ingresara la opcion a elegir en caso que se ingrese un valor que nos esta en las opciones se volvera a pedir
	al usuario que ingrese nuevamente la opcion a eligir*/
	do{
		//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
		system("cls");
	
		//system que añadira color de fondo y de letra a la consola
		system("color 2E");
		
		//Se mostrara las opciones del programa.
		cout << "\n\n\n\t\t\t\t\t\t\t\tMenu\n\n\n\n" << endl;
		cout << "\t1.Ingresar";
		cout << "\t\t2.Mostrar";
		cout << "\t\t3.Cambiar";
		cout << "\t\t4.Eliminar";
		cout << "\t\t5.Buscar\n\n" << endl;
		cout << "\t\t\t\t\t6.Ordenar";
		cout << "\t\t\t\t7.Salir\n\n"<< endl;
	
		cout << "\n\t\t\t\t\t\t   Ingrese una opcion: ";	
		//Funcion que evita errores de datos
		errordato();
		cin >> opcion;
	}while(opcion < 1 || opcion > 7);
	
	/*Luego de elegir la opcion la sentencia switch lo enviare a la opcion elejida que lo trasladara a la funcion que
	contiene la opcion (execto para la opcion salir) para cumplir el proceso elejodo*/ 
	switch(opcion){
		case 1:	ingresar(datos);	break;
		case 2:	mostrar(datos);	break;
		case 3:	cambiar(datos);	break;
		case 4:	eliminar(datos);	break;
		case 5:	buscar(datos);	break;
		case 6: ordenar1(datos); break;
		case 7:	system("cls");	cout << "¡Gracias por usar el programa!";	break;
		}
}

/*Funcion sin parametros ingresar esta usara el ciclo for y las variables columnas y filas para almacenar los  
valores de los datos*/
void ingresar(int datos[2][3]){
	
	do{
	system("cls"); 	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
	
	for(filas = 0; filas < 2; filas++){
		for(columnas = 0; columnas < 3; columnas++){
			cout << "Ingrese un valor: ";
			cin >> datos[filas][columnas];
			errordato(); //Funcion que evita errores de datos
		}
	}
	
	}while(cin.fail());
	
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();
}


/*Funcion sin parametros mostrar esta usara el ciclo for y las variables columnas y filas para mostrar los  
valores de los datos y la pocision en la que se encuentra.*/
void mostrar(int datos[2][3]){
	system("cls"); 	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
	for(filas = 0; filas < 2; filas++){
		for(columnas = 0; columnas < 3; columnas++){
			cout << " Posicion del dato fila[" << filas << "] y columna [" << columnas << "].\t"; 
			cout << "Los valores ingresados son: " << datos[filas][columnas] << endl;
		}
	}
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();
}

//Funcion sin parametros cambiar le permitira al usario cambiar uno o todos los valores de los datos//
void cambiar(int datos[2][3]){
	
	int opcion_cambiar;
	
	//En caso de elejir una opcion que no se encuentre se le pedira al usario que ingrese la opcion a elejir nuevamente
	do{	
		system("cls");	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
		
		//Se imprime las opciones a elejir	
		cout << "1.Cambiar todos los valores de los datos." << endl;
		cout << "2.Cambiar solo un dato" << endl;
		cout << "3.Regresar." << endl;
	
		cout <<"\nElije una opcion: ";	
		cin >> opcion_cambiar;
		errordato(); //Funcion que evita errores de datos
		
	}while(opcion_cambiar < 1 || opcion_cambiar > 3 || cin.fail());
	
	//Si el usuario ingresa la opcion 1 volvera a ingresar todas los valores de los datos.
	if(opcion_cambiar == 1){
		system("cls"); 	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
		for(filas = 0; filas < 2; filas++){
			for(columnas = 0; columnas < 3; columnas++){
				cout << "Ingrese el nuevo valor: ";
				//Funcion que evita errores de datos
				errordato();
				cin >> datos[filas][columnas];
			}
		}
	}
	//Si el usuario ingresa la opcion 2 ingresa la oposicion en que se encuentra el dato cuyo valor quiere cambiar.
	else if(opcion_cambiar == 2){
		//En caso de que la oposicion ingresada no existe se volvera a pedir la posicion a cambiar.
		do{
			
			system("cls"); 	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
			
			cout << "Ingrese la fila y columna que desea cambiar\n";
			cout << "Ingrese la fila en la que se encuentra: ";	
			
			cin >> nuevaf;
			errordato(); //Funcion que evita errores de datos
			
			cout << "Ingrese la columna en la que se encuentra: ";	
			cin >> nuevac;
			errordato(); //Funcion que evita errores de datos
			
		}while((nuevaf > 1 || nuevaf < 0) || (nuevac > 2 || nuevac < 0 || cin.fail()));
		
		cout << "\nPosicion del dato fila[" << nuevaf << "] y columna [" << nuevac << "]."; 
		cout << "\nIngrese el nuevo valor: ";	cin >> datos[nuevaf][nuevac];	
	}
	//Si el usarion ingresa a la opcion 3 volvera al bloque principal main
	else{
		main();
	}
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();
}

void eliminar(int datos[2][3]){
	
	int opcion_cambiar;
	
	//En caso de elejir una opcion que no se encuentre se le pedira al usario que ingrese la opcion a elejir nuevamente
	do{	
		
		system("cls"); 	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
	
		//Se imprime las opciones a elejir	
		cout << "1.Eliminar todos los valores de los datos." << endl;
		cout << "2.Eliminar solo un dato" << endl;
		cout << "3.Regresar." << endl;
	
		cout <<"\nElije una opcion: ";	
		
		cin >> opcion_cambiar;
		errordato(); //Funcion que evita errores de datos

	}while(opcion_cambiar < 1 || opcion_cambiar > 3 || cin.fail());
	
	//Si el usuario ingresa la opcion 1 eliminara todos los valores de los datos.
	if(opcion_cambiar == 1){
		
		system("cls");	//Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
		
		for(filas = 0; filas < 2; filas++){
			for(columnas = 0; columnas < 3; columnas++){
				datos[filas][columnas] = 0;
			}
		}
	cout << "Se han eliminado todos los valores.";
	
	}
	//Si el usuario ingresa la opcion 2 ingresara la oposicion en que se encuentra el dato cuyo valor quiere eliminar.
	else if(opcion_cambiar == 2){
		//En caso de que la oposicion ingresada no existe se volvera a pedir la posicion a eliminar.
		do{
				system("cls"); //Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
				cout << "Ingrese la fila y columna que desea eliminar\n";
				
				cout << "Ingrese la fila en la que se encuentra: ";	
				cin >> nuevaf;
				errordato(); //Funcion que evita errores de datos
				
				cout << "Ingrese la columna en la que se encuentra: ";	
				cin >> nuevac;
				errordato(); //Funcion que evita errores de datos
				
			}while((nuevaf > 1 || nuevaf < 0) || (nuevac > 2 || nuevac < 0) || cin.fail());
			
		cout << "\nPosicion del dato fila[" << nuevaf << "] y columna [" << nuevac << "].";
		cout << "\nEl valor eliminado del dato  es: " << datos[nuevaf][nuevac] << endl;
		datos[nuevaf][nuevac] = 0; 
	}
	//Si el usarion ingresa a la opcion 3 volvera al bloque principal main
	else{
		main();
	}
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();
}

void buscar(int datos[2][3])
{
	int centralf; 
	int centralc;
	int buscar;
	
	//En caso de elejir una opcion que no se encuentre se le pedira al usario que ingrese la opcion a elejir nuevamente
	do{	
		
		system("cls"); //Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
	
		//Se imprime las opciones a elejir	
		cout << "Ingresa la posicion de el dato que buscas." << endl;
		
		cout <<"\nIngresa la fila: ";	
		cin >> centralf;
		errordato(); //Funcion que evita errores de datos
		
		cout <<"\nIngresa la columna: ";	
		cin >> centralc;
		errordato(); //Funcion que evita errores de datos

	}while(centralf < 0 || centralf > 2 || centralc < 0 || centralc > 3 || cin.fail());
		
	for(int filas = 0; filas < 2; filas++)
	{
		
		for(int columnas = 0; columnas < 3 ; columnas ++)
		{
			if(centralf == filas && centralc == columnas)
			{
				cout << "\n\nBusqueda" << endl;
				cout << "\nDato" << endl;
				cout << "\nPosicion del dato fila[" << filas << "] y columna [" << columnas << "].\t"; 
				cout << "Valor del dato " << datos[filas][columnas] << endl;
				
				/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
				ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
				getch();
				main();
			}
			
		}
	
	}
	cout << "\n\nNo existe la posicion ingresada" << endl;
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();
}

//funcion que servira para ordenar los datos de la matriz
void ordenar1(int datos[2][3]){
	
	int opcion; //variable utilizada para almacenar la opcion elejida
	
	//En caso de elejir una opcion que no se encuentre se le pedira al usario que ingrese la opcion a elejir nuevamente
	do{	
		
		system("cls"); //Funcion system("cls") para borrar lo que habia anteriormente en la pantalla.
	
		//Se imprime las opciones a elejir	
		cout << "1.Ordenar de forma ancedente." << endl;
		cout << "2.Ordenar de forma dencedente" << endl;
		cout << "3.Regresar." << endl;
	
		cout <<"\nElije una opcion: ";	
		
		cin >> opcion;
		errordato(); //Funcion que evita errores de datos

	}while(opcion < 1 || opcion > 3 || cin.fail());
	//si elije la opcion 1 uno se dirijira a este bloque if
	if(opcion == 1)
	{
	
	ordenar2(datos, ancedente); /*funcion que ordenara los datos y que lleva como parametro un puntero a una funcion que lleva la condicion que evaluara de
							   	 como se ordenaran los datos */
						
	}
	//si elije la opcion 2 uno se dirijira a este bloque else if
	else if(opcion == 2){
	
	ordenar2(datos, decendente); /*funcion que ordenara los datos y que lleva como parametro un puntero a una funcion que lleva la condicion que evaluara de
							   	 como se ordenaran los datos*/
					
	}
	//si no elije ninguna opcion de las anteriores se dirijira a este bloque else
	else{
	
		main(); //funcion que lo enviara al bloque de la funcion main
	
	}
}
//funcion que ordenara los datos de la matriz, tiene como
void ordenar2(int datos[2][3], int (*compara)(int a, int b)) 
{
	//declaracion de variables
	int filas;
	int columnas;
	int i;
	int j;	
	
	//ciclos for requeridos oara metodo de burbuja o hundimiento por el cual se ordenaran los datos
	for(int filas = 0; filas < 2; filas++)
	{
		
		for(int columnas = 0; columnas < 3; columnas++)
		{
			for(int i = 0; i < 2; i++)
			{
		
				for(int j = 0; j < 3; j++)
				{   /*condicion if que tiene como condicion el puntero a la funcion que tiene la condicion, y si dicha condicion que esta dentro de la funcion
					que tiene if como condicion if se ejecutara la funcion intercambio
					Las funciones que tienen dicha condicion para que evaluara if puede ser ancendete() o dencedente()*/
					if((*compara)(datos[filas][columnas], datos[i][j])){	
						intercambio(&datos[filas][columnas], &datos[i][j]); /*  funcion que tiene como parametros dos punteros que se encargara del proceso
																				para ordenar los datos */
					}
						
				}
		
			}
		}	
	}
	
	/*Luego de terminar el proceso la funcion getch le permite debera presionar una tecla para 
	ser enviado al bloque principal main para poder permiter al usario mirar lo que ha hecho.*/
	getch();
	main();	
}

void intercambio(int *ptr1, int *ptr2) //funcion que intercambia los datos de las varibles segun el metodo de la burbuja o hundimiento
{
	int aux; //variable auxiliar
	
	//proceso del metodo de la burbuja o hundimiento en el que se intercabian los valores de las varibles
	aux = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = aux;
}

int ancedente(int a, int b) //funcion que lleva la condicion a cumplir para ordenar los datos de la matriz
{
	return a < b; //retorna una comparacion de si a es menor que b
}

int decendente(int a, int b)  //funcion que lleva la condicion a cumplir para ordenar los datos de la matriz
{
	return a > b; //retorna una comparacion de si a es mayor que b
}

//Funcion para evitar errores de datos
void errordato()
{
	//Ciclo while para evitar ingresar datos incorrectos
	while(cin.fail()){
		
		//cin.clear limpia el bueffer de los datos ingresados				
			cin.clear();
		
		//cin.igonere ignorara los primeros 1000 caracteres o en este caso los numeros ingresados
			cin.ignore(1000,'\n');
		}
} 

