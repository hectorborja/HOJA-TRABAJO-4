#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void ingresar();
void leer ();
void menu();
int main(){
	menu();
}
void menu(){
	int op=0;
	do{
		system("CLS");
		cout<<"-------Men� principal-------"<<endl;
		cout<<"1. Ingresar datos"<<endl;
		cout<<"2. Mostrar reporte"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>op;
		if(op==1){
			system("CLS");
			int n;
			int i=0;
			cout<<"Digitar la cantidad de datos a ingresar: "<<endl;
			cin>>n;
			for(i;i<n;i++){
				ingresar();	
			}
		}
		else if(op==2){
			system("CLS");
			leer();
		}
		else if(op==3){
			break;
		}
		else{
			break;
		}
	}while(op!=3);
	
}
void ingresar(){
	int tipo;
	int area;
	float costo;
	float excedente;
	system("CLS");
	cout<<"Tipos de servicio: "<<endl;
	cout<<"1. Mala hierba  		Q 10.00"<<endl;
	cout<<"2. Langostas			Q 20.00"<<endl;
	cout<<"3. Gusanos			Q 30.00"<<endl;
	cout<<"4. Todo lo anterior 		Q 50.00"<<endl;
	cout<<"Seleccione el tipo de servicio: "<<endl;
	cin>>tipo;
	cout<<"Ingrese el �rea a fumigar"<<endl;
	cin>>area;
	if (tipo==1){
		costo = area * 10.00;
	}
	else if (tipo==2){
		costo = area * 20.00;
	}
	else if (tipo == 3){
		costo = area * 30.00;
	}
	else if (tipo == 4){
		costo = area * 50.00;
	}
	if (area>500){
		costo = costo *0.95;
	}
	if (costo>1500){
		excedente = costo - 1500;
		costo = costo - excedente;
		excedente = excedente * 0.90;
		costo = costo + excedente;	
	}
	ofstream archivo;
	archivo.open("fumigacion.txt",ios::app);
	if (archivo.fail()){
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	archivo<<tipo<<"\t"<<costo<<"\t"<<endl;
	archivo.close();
}
void leer(){
	ifstream reporte;
	float t;
	float c;
	float s1;
	float s2;
	float s3;
	float s4;
	float suma;
	int mayor=0;
	try{
		reporte.open("fumigacion.txt",ios::in);
		while(reporte>>t>>c){
			cout<<"Tipo: "<<t<<"\t"<<"Costo: "<<c<<endl;
			if(t==1){
				s1+=1;
			}
			else if(t==2){
				s2+=1;
			}
			else if(t==3){
				s3+=1;
			}
			else if(t==4){
				s4+=1;
			}
		suma+=c;
	}
	cout<<"Cantidad de servicios por cada tipo de fumigaci�n: "<<endl;
	cout<<"1. Mala hierba: "<<s1<<endl;
	cout<<"2. Langostas: "<<s2<<endl;
	cout<<"3. Gusanos: "<<s3<<endl;
	cout<<"4. Todo lo anterior: "<<s4<<endl;
	cout<<"Total pagado por los clientes: "<<suma<<endl;
	
	system("PAUSE");
	}
	catch(exception){
		cout<<"Error en la apertura del archivo"<<endl;
		exit(1);
	}
	reporte.close();
}
