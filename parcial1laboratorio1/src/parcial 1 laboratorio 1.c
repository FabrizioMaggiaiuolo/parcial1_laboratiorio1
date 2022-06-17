/*
Fabrizio Maggiaiuolo
1C
legajo: 112952
Instancia 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "funciones.h"
#include "validaciones.h"

#define CANTIDADMEDICOS 5
#define CANTIDADCONSULTAS 10
#define CANTIDADESPECIALIDADES 5
#define CANTIDADHOSPITALES 2


int main(void) {

	setbuf(stdout, NULL);

	int banderaPrimeraConsulta;
	banderaPrimeraConsulta = 0;

	int idsConsultas;
	idsConsultas = 0;

	int salir = 0;

	sHospital hospitales[CANTIDADHOSPITALES] = {
			{0,"Hospital Italiano",3},
			{1,"Hospital Aleman",2}
	};

	sEspecialidad especialidades[CANTIDADESPECIALIDADES] = {
			{0,"dentista"},
			{1,"cirujano"},
			{2,"medico clinico"},
			{3,"neurocirujano"},
			{4,"cardiologo"}
	};

	sMedico medicos[CANTIDADMEDICOS] = {
			{ 0, "Leandro", especialidades[0],0, 1 ,0 },
			{ 1,"Martin", especialidades[0],0, 1 ,0 },
			{ 2, "Nicolas", especialidades[2],0, 1 ,0 },
			{ 3, "Florencia", especialidades[3],0, 1 ,1 },
			{ 4, "German", especialidades[4],0, 1 ,1 }
	};

	sConsulta consultas[CANTIDADCONSULTAS];
	for (int i = 0; i < CANTIDADCONSULTAS; i++) {
		consultas[i].estado = 0;
		consultas[i].idConsulta = 1000+i;
		consultas[i].idMedico = 1000+i;
	}


	while (salir == 0) {
		int respuesta;

		printf("\n");
		printf("\n");

		printf("Ingrese una de las siguientes opciones: \n");
		printf("1. ALTA CONSULTA \n");
		printf("2. MODIFICAR CONSULTA \n");
		printf("3. CANCELAR CONSULTA \n");
		printf("4. DIAGNOSTICAR \n");
		printf("5. LISTAR \n");
		printf("6. SALIR \n");
		respuesta = GetInt("Opcion que desea ingresar:");

		printf("\n");
		printf("\n");

		switch (respuesta) {

		 case 1:
			 AltaConsulta(consultas, CANTIDADCONSULTAS,idsConsultas);
			 banderaPrimeraConsulta = 1;
			 idsConsultas++;
			 break;

		 case 2:
			 if(banderaPrimeraConsulta == 0)
			 {
				 printf("De de alta una consulta para poder continuar\n");
			 }
			 else
			 {
				 MenuModificarConsulta(consultas, CANTIDADCONSULTAS);
			 }
			 break;

		 case 3:
			 if(banderaPrimeraConsulta == 0)
			 {
				 printf("De de alta una consulta para poder continuar");
			 }
			 else
			 {
				 CancerlarConsulta(consultas, CANTIDADCONSULTAS);
			 }
			 break;

		 case 4:
		 	 if(banderaPrimeraConsulta == 0)
			 {
				 printf("De de alta una consulta para poder continuar");
			 }
			 else
			 {
				 Diagnosticar(consultas, CANTIDADCONSULTAS,medicos,CANTIDADMEDICOS);
			 }
			 break;
		 case 5:
			 if(banderaPrimeraConsulta == 0)
			 {
				 printf("De de alta una consulta para poder continuar");
			 }
			 else
			 {
				 MenuListar(consultas, CANTIDADCONSULTAS, medicos,CANTIDADMEDICOS, especialidades, CANTIDADESPECIALIDADES, hospitales, CANTIDADHOSPITALES);
			 }
			 break;
		case 6:
			salir = 1;
			break;
		}

	}

	printf("Gracias por utilizar nuestro programa");
	return 0;
}
