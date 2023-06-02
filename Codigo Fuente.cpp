/*
Proyecto Final Programacion Basica 81,
Cajero Electronico,
Fecha: 02 de Junio, 2023
Autor: David Alejandro Acosta Suarez
*/
	#include <iostream>
	#include <vector>
	#include <ctime>
	#include <cstdlib>								//declaracion de las librerias a usar
	
	using namespace std;
	
	struct TarjetaDebito
	{
	    string numeroTarjeta;							//struct correspondiente a una tarjeta debito
	    string PIN;
	    double saldo;
	};
	
	void interfazVisual(void);
	void realizarTransaccion(const string& numeroTarjeta, vector<TarjetaDebito>& tarjetas);
	void clearScreen();
	bool validarNumeroTarjeta(const string& numeroTarjeta, const vector<TarjetaDebito>& tarjetas);
	bool validarPIN(const string& PIN, const vector<TarjetaDebito>& tarjetas, const string& numeroTarjeta);			//prototipos de funciones
	
	int main()
	{
	    vector<TarjetaDebito> tarjetas;
	    tarjetas.push_back(TarjetaDebito{"123456789", "1234", 5000.0});
	    tarjetas.push_back(TarjetaDebito{"987654321", "4321", 5000.0});
	    tarjetas.push_back(TarjetaDebito{"147258369", "5678", 5000.0});
	    tarjetas.push_back(TarjetaDebito{"963852741", "8765", 5000.0});
	    tarjetas.push_back(TarjetaDebito{"159482637", "9870", 5000.0});							//datos de las tarjetas que reconocera el sistema, por orden: numero, pin, saldo inicial
	    
	
	    interfazVisual();																		//invocacion de la portada del proyecto
	    cout<<"\n\t\t****BIENVENIDOS****\n"<<endl;
	    cout<<"\tLe damos la bienvenida al cajero electronico del Banco Cash.inc,\n\tpor favor siga las instrucciones de uso\n"<<endl;
	    cout<<"\t-> Por favor presione 'Enter' para continuar..."<<endl;
	    cin.get();
	    system("cls");
	
	    string numeroTarjeta;
	    string PIN;
	
	
	    while (true)																	//ciclo while para que el programa persista hasta obtener una respuesta correcta
	    {
	        cout<<"\n\t-> Por favor ingrese su numero de tarjeta: ";
	        cin>>numeroTarjeta;
	
	        if (validarNumeroTarjeta(numeroTarjeta, tarjetas))
	        {
	            break;
	        }
	        else
	        {
	            clearScreen();
	            cout<<"\n\tEl numero de tarjeta ingresado no es valido, por favor intentelo nuevamente."<<endl;
	        }
	    }
	
	    clearScreen();
	
	    while (true)				//ciclo whil para que persista hasta obtener respuesta correcta
	    {
	        cout<<"\n\t-> Por favor ingrese el numero PIN de su tarjeta: ";
	        cin>>PIN;
	
	        if (validarPIN(PIN, tarjetas, numeroTarjeta))
	        {
	            clearScreen();
	            cout<<"\n\t-> Felicidades, su usuario ha sido verificado,\n\tahora tiene autorizacion para acceder al sistema."<<endl;
	            cout<<"\n\tPor favor presione 'Enter' para continuar..."<<endl;
	            cin.ignore();
	            cin.get();
	            break;
	        }
	        else
	        {
	            clearScreen();
	            cout<<"PIN invalido. Intentelo nuevamente."<<endl;
	        }
	    }
	
	    int opcion;
	    int opcionReinicio;
	    int opcionSalir;				//declaracion de las variables que manipulan los bucles del programa
	    
		do
	    {
	        clearScreen();
	
	        cout<<"\t\tCash.inc"<<endl;
	        cout<<"\n\t***MENU DE OPCIONES***"<<endl;
	        cout <<"\n\t1. Consultar disponibilidad de efectivo"<<endl;			//menu de opciones
	        cout<<"\t2. Realizar retiro de efectivo"<<endl;
	        cout<<"\t3. Salir del Programa"<<endl;
	        cout<<"\t4. Reiniciar Programa"<<endl;
	        cout<<"\n\t-> Por favor ingrese una opcion: ";
	        cin>>opcion;
	
	        switch (opcion)
	        {
	            case 1:
	                for (int i=0; i<tarjetas.size(); i++)
	                {
	                    if (tarjetas[i].numeroTarjeta==numeroTarjeta)
	                    {
	                        cout<<"\n\tSu saldo actualmente disponible es de: \n$"<<tarjetas[i].saldo<<endl;			//invocacion de la funcion correspondiente, muestra los datos unicamente de la tarjeta en cuestion
	                        cout<<"\n\t-> Por favor presione 'Enter' para continuar..."<<endl;
	                        cin.ignore();
	                        cin.get();
	                        break;
	                    }
	                }
	                break;
	            case 2:
	                realizarTransaccion(numeroTarjeta, tarjetas);
	                break;												//invocaion de la funcion principal del programa, retirar dinero
	            case 3:
	                clearScreen();
	                int opcionSalir;
	                cout<<"\n\t-> Confirma que desea cerrar el programa?\n\t(Presione 1 para Si, Presione 0 para volver al menu)"<<endl;
	                cin>>opcionSalir;
	                if (opcionSalir == 1)
	                {
	                    cout<<"\n\t-> El programa ha finalizado su ejecucion"<<endl;
	                    cout<<"\n\n\t****GRACIAS POR USAR ESTE SERVICIO****"<<endl;
	                    return 0;
	                }
	                else if (opcionSalir==0)
	                {
	                    continue;  //permite volver al menu de opciones es decir el inicio del bucle
	                }
	                else
	                {
	                    clearScreen();
	                    cout<<"\n\tOpcion no valida. Por favor ingrese 1 o 0."<<endl;
	                    cout<<"\n\t-> Presione 'Enter' para continuar..."<<endl;
	                    cin.ignore();
	                    cin.get();
	                    break;
	                }
	            case 4:
	                clearScreen();
	                int opcionReinicio;
	                cout<<"\n\t-> Confirma que desea reiniciar el programa?\n\t(Presione 1 para Si, Presione 0 para volver al menu)"<<endl;
	                cin>>opcionReinicio;
	                if (opcionReinicio==1)
	                {
	                    main();  //permite reiniciar el programa ya que se invoca el main de nuevo, como si iniciara de cero
	                    return 0;
	                }
	                else if (opcionReinicio==0)
	                {
	                    continue;  //regresar al menu de opciones
	                }
	                else
	                {
	                    clearScreen();
	                    cout<<"\n\tOpcion no valida. Por favor ingrese 1 o 0."<<endl;
	                    cout<<"\n\t-> Presione 'Enter' para continuar..."<<endl;		//validacion
	                    cin.ignore();
	                    cin.get();
	                    break;
	                }
	            default:
	                clearScreen();
	                cout<<"\n\tPor favor ingrese una opcion valida"<<endl;		//validacion del default
	                cout<<"\n\t-> Presione 'Enter' para continuar..."<<endl;
	                cin.ignore();
	                cin.get();
	                break;
	        }
	    } while (true);
	
	    return 0;
	}
	void interfazVisual(void)						//funcion de la portada del proyecto
	{
		system("color 8E");								//configura color, el 8 representa color de interfaz (gris) y E representa color del texto (amarillo)
		cout<<"\n\n\n\t\t*******PROYECTO FINAL PROGRAMACION BASICA 81*******"<<endl;
		cout<<"\n\n\t\t\t~~~David Alejandro Acosta Suarez~~~\n\n"<<endl;
		printf("\t\t\tProyecto #5 - Cajero Electronico\n\n\n");
		printf("\t\t-------------------------------------------------\n");
	    printf("\t\t|     ******      ******    *************    	|\n");
	    printf("\t\t|     ******      ******    **************    	|\n");
	    printf("\t\t|     ******      ******    ***************     |\n");
	    printf("\t\t|     ******      ******    ***       ******   	|\n");
		printf("\t\t|     ******      ******    ***        ******  	|\n");
	    printf("\t\t|     ******      ******    ***         ******  |\n");
	    printf("\t\t|     ******      ******    ***         ******  |\n");
		printf("\t\t|     ******      ******    ***         *****  	|\n");
	    printf("\t\t|     ******      ******    ***        *****   	|\n");
	    printf("\t\t|     ******      ******    ***       ******    |\n");
	    printf("\t\t|     ******************    ***************    	|\n");
	    printf("\t\t|     ****************** ** **************   **	|\n");
	    printf("\t\t|     ****************** ** *************    **	|\n");    
		printf("\t\t-------------------------------------------------\n");
		printf("\n\t\t UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS\n");
		printf("\t\t\t\tINGENIERIA DE SISTEMAS\n");
		printf("\t\t\t\t   JUNIO 02 , 2023\n");
		getchar();
		system("cls");
	}
	bool validarNumeroTarjeta(const string&numeroTarjeta, const vector<TarjetaDebito>&tarjetas)
	{
	    for (int i=0; i<tarjetas.size(); i++)
	    {
	        if (tarjetas[i].numeroTarjeta==numeroTarjeta)
	        {
	            return true;
	        }
	    }
	    return false;
	}
	
	bool validarPIN(const string& PIN, const vector<TarjetaDebito>&tarjetas, const string&numeroTarjeta)
	{
	    for (int i=0; i<tarjetas.size(); i++)
	    {
	        if (tarjetas[i].numeroTarjeta==numeroTarjeta&&tarjetas[i].PIN==PIN)
	        {
	            return true;
	        }
	    }
	    return false;
	}
	
	void realizarTransaccion(const string&numeroTarjeta, vector<TarjetaDebito>&tarjetas)
{
    time_t tiempoActual = time(NULL);
    tm* fechaHora = localtime(&tiempoActual);
    int limiteTransacciones = 3;
    double limiteRetiro = 1000.0;

    for (int i=0; i<tarjetas.size(); i++)
    {
        if (tarjetas[i].numeroTarjeta==numeroTarjeta)
        {
            if (fechaHora->tm_mday>=1 && fechaHora->tm_mday<=31)
            {
                if (tarjetas[i].saldo>0)
                {
                    int numTransacciones=0;
                    for (int j=0; j<tarjetas.size(); j++)
                    {
                        if (tarjetas[j].numeroTarjeta==numeroTarjeta)
                        {
                            ++numTransacciones;
                        }
                    }

                    if (numTransacciones<limiteTransacciones)
                    {
                        double montoRetiro;
                        cout<<"\n\tPor favor indique el monto que desea retirar: ";
                        cin>>montoRetiro;

                        if (montoRetiro>0 && montoRetiro<=limiteRetiro && montoRetiro<=tarjetas[i].saldo)
                        {
                            tarjetas[i].saldo-=montoRetiro;
                            clearScreen();
                            cout<<"Retiro exitoso."<<endl;
                            cout<<"Número de tarjeta: "<<tarjetas[i].numeroTarjeta<<endl;
                            cout<<"Monto retirado: "<<montoRetiro<<endl;
                            cout<<"Fecha y hora: "<<asctime(fechaHora)<<endl;
                            cout<<"Su saldo actual es: "<<tarjetas[i].saldo<<endl;
                            cout<<"\n->Por favor presione 'Enter' para continuar..."<<endl;
                            cin.ignore();
                            cin.get();
                        }
                        else
                        {
                            clearScreen();
                            cout<<"\n\tMonto invalido. Intentelo nuevamente."<<endl;
                            cout<<"\n\tPor favor presione 'Enter' para continuar..."<<endl;
                            cin.ignore();
                            cin.get();
                        }
                    }
                    else
                    {
                        clearScreen();
                        cout<<"\n\tLamentablemente ha excedido el limite de transacciones diarias."<<endl;
                        cout<<"\n\t-> Por favor presione 'Enter' para continuar..."<<endl;
                        cin.ignore();
                        cin.get();
                    }
                }
                else
                {
                    clearScreen();
                    cout<<"\n\tLamentablemente no posee suficiente saldo para realizar este retiro."<<endl;
                    cout<<"\n\t-> Por favor presione 'Enter' para continuar..."<<endl;
                    cin.ignore();
                    cin.get();
                }
            }
            else
            {
                clearScreen();
                cout<<"\n\tNo es posible realizar transacciones en este dia."<<endl;
                cout<<"\n\t-> Por favor presione 'Enter' para continuar..."<<endl;
                cin.ignore();
                cin.get();
            }
            break;
        }
    }
}

	
	void clearScreen()
	{
	    cout<<"\033[2J\033[1;1H";
	}

